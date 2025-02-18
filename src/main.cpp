#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "task.h"

TaskHandle_t TaskHandle_2; // handler for Task2
TaskHandle_t TaskHandle_1; // handler for Task1

void Task1(void* pvParameters); // Task1 function prototype
void Task2(void* pvParameters); // Task2 function prototype

void loop() 
{
// Do nothing as schduler will allocated CPU to Task1 and Task2 automatically
}

//TH1

// void setup() 
// {
//   Serial.begin(9600); 
//   pinMode(4, OUTPUT);  
//   pinMode(5, OUTPUT); 

 
//   xTaskCreate(Task1, "LED1", 100, NULL, 1, NULL);
//   vTaskStartScheduler();
// }


// /* Task1 with priority 1 */
// void Task1(void* pvParameters)
// {

//   while(1)
//   {
//     Serial.println("Task1 Running"); // print "Task1 Running" on Arduino Serial Monitor
//     digitalWrite(4, HIGH); // sets the digital pin 4 on
//     digitalWrite(5, LOW); // sets the digital pin 5 off
//     xTaskCreate(Task2, "LED2", 100, NULL, 2, &TaskHandle_2); // create task2 with priority 2
//     vTaskDelay( 100 / portTICK_PERIOD_MS ); // wait for one second
//   }
// }


// /* Task2 with priority 2 */
// void Task2(void* pvParameters)
// { 
//     digitalWrite(5, HIGH); // sets the digital pin 5 high
//     digitalWrite(4, LOW); // sets the digital pin 4 low
//     Serial.println("Task2 is runnig and about to delete itself");
//     delay(1000); // wait for one second
//     vTaskDelete(TaskHandle_2);     //Delete own task by passing NULL(TaskHandle_2 can also be used)
// }

//TH2

void setup() 
{
  Serial.begin(9600); 
  xTaskCreate(Task1, "task1", 100, NULL, 1, &TaskHandle_1);
  xTaskCreate(Task2, "task2", 100, NULL, 2, &TaskHandle_2);
  vTaskStartScheduler();
}

void Task1(void* pvParameters)
{
  while(1)
  {
    Serial.println("Task1 is running on core ");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void Task2(void* pvParameters)
{
  while(1)
  {
    Serial.println("Task2 is running on core ");
    vTaskSuspend(TaskHandle_1);
    Serial.println("Task1 is suspended");
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    vTaskResume(TaskHandle_1);
    Serial.println("Task1 is resumed");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

//TH3
// void setup() 
// {
//   Serial.begin(9600); // Enable serial communication library.

//    xTaskCreate(Task1, "LED1", 100, NULL, 3, &TaskHandle_1);
//    xTaskCreate(Task2, "LED2", 100, NULL, 2, &TaskHandle_2);
//    vTaskStartScheduler();
// }


// //definition of Task1
// void Task1(void* pvParameters)
// {
//     UBaseType_t uxPriority = uxTaskPriorityGet( NULL );
//     UBaseType_t uxPriority2 = uxTaskPriorityGet( TaskHandle_2 );
//     while(1)
//     {
//     Serial.print("Task1 is running, Task2 Priority = ");
//     Serial.println(uxPriority2);
//     vTaskPrioritySet( TaskHandle_2, ( uxPriority + 2 ) );  
//     delay(1000);
//     }
// }
// void Task2(void* pvParameters)
// {
//     UBaseType_t   uxPriority = uxTaskPriorityGet( TaskHandle_1 );
//     UBaseType_t   uxPriority2 = uxTaskPriorityGet( NULL );
//     while(1)
//     {
//     Serial.print("Task2 is running, Task2 Priority = ");
//     Serial.println(uxPriority2);
//     vTaskPrioritySet( TaskHandle_2, ( uxPriority - 2 ) );
//     delay(1000);
//     }
  
// }

//TH4

// void Task1(void* pvParameters)
// {
//     while(1)
//     {
//         Serial.println("Task1 is running");
//         vTaskDelay(pdMS_TO_TICKS(1000));
//     }
// }

// // Hàm Idle Hook
// void vApplicationIdleHook(void)
// {
//     Serial.println("Idle Task is running");
// }

// void setup() 
// {
//     Serial.begin(9600);

//     xTaskCreate(Task1, "Task1", 100, NULL, 3, &TaskHandle_1);

//     vTaskStartScheduler(); // Bắt đầu FreeRTOS
// }