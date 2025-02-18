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
// TH1
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
//     vTaskDelay( 100 / portTICK_PERIOD_MS );
//     vTaskDelete(TaskHandle_2);     //Delete own task by passing NULL(TaskHandle_2 can also be used)
// }

// //TH2
// volatile int count = 0; // Biến đếm cho Task1
// volatile bool task1Suspended = false; // Trạng thái Task1
// void setup() {
//     Serial.begin(9600);

//     // Tạo Task1 với độ ưu tiên 1
//     xTaskCreate(Task1, "Task 1", 128, NULL, 1, &TaskHandle_1);
//     // Tạo Task2 với độ ưu tiên 1
//     xTaskCreate(Task2, "Task 2", 128, NULL, 1, &TaskHandle_2);

//     // Bắt đầu scheduler
//     vTaskStartScheduler();
// }
// // Task1: Chạy 10 lần rồi suspend
// void Task1(void *pvParameters) {
//     while (1) {
//         Serial.print("Task 1 Running... ");
//         Serial.println(count + 1);
//         count++;

//         // Nếu chạy đủ 10 lần thì suspend Task1
//         if (count == 10) {
//             Serial.println("Task 1 Suspended...");
//             task1Suspended = true; // Đánh dấu Task1 bị suspend
//             vTaskSuspend(NULL); // Suspend chính nó
//         }

//         vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay 1 giây
//     }
// }
// // Task2: Resume Task1 sau khi bị suspend
// void Task2(void *pvParameters) {
//     while (1) {
//         if (task1Suspended) { // Chỉ resume nếu Task1 đang bị suspend
//             Serial.println("Task 2 Running...");
//             vTaskDelay(5000 / portTICK_PERIOD_MS); // Chờ 5 giây trước khi resume

//             Serial.println("Task 1 Resumed...");
//             task1Suspended = false; // Reset trạng thái
//             count = 0; // Reset biến đếm của Task1
//             vTaskResume(TaskHandle_1); // Resume Task1
//         }
//         vTaskDelay(500 / portTICK_PERIOD_MS); // Kiểm tra trạng thái Task1 mỗi 500ms
//     }
// }

// TH3
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

void Task1(void* pvParameters)
{
    while(1)
    {
        Serial.println("Task1 is running");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
// Hàm Idle Hook
void vApplicationIdleHook(void)
{
    Serial.println("Idle Task is running");
}

void setup() 
{
    Serial.begin(9600);

    xTaskCreate(Task1, "Task1", 100, NULL, 3, &TaskHandle_1);

    vTaskStartScheduler(); // Bắt đầu FreeRTOS
}