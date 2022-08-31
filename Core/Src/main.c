/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <string.h>
#include <stdio.h>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
char ATcommand[100];
   uint8_t buffer[100] = {0};
   uint8_t ATisOK = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int _write(int file, char *ptr, int len)
{
	int i=0;
	for(i=0 ; i<len ; i++)
		ITM_SendChar((*ptr++));
	return len;
}

uint8_t count = 0;

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

    while(!ATisOK){
    		sprintf(ATcommand,"AT\r\n");
    		HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
    		HAL_UART_Receive (&huart1, buffer, 30, 100);
    		HAL_Delay(1000);
    		if(strstr((char *)buffer,"OK")){
    			ATisOK = 1;
    		}
    		HAL_Delay(1000);
    		memset(buffer,0,sizeof(buffer));
    }

            //*GPRS ACTIVE CODE START*//

    sprintf(ATcommand,"AT+CMGF=1\r\n");
    HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
    HAL_UART_Receive (&huart1, buffer, 30, 100);
    HAL_Delay(100);
    count++;
    printf ("Check point count = %d,\n ", count);
    HAL_Delay(100);

    memset(buffer,0,sizeof(buffer));
    sprintf(ATcommand,"AT+CHIPSHUT\r\n");
    HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
    HAL_Delay(100);
    count++;
    printf ("Check point count = %d,\n ", count);
    HAL_Delay(100);

    memset(buffer,0,sizeof(buffer));
        sprintf(ATcommand,"AT+CGATT=1\r\n");
        HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
        HAL_Delay(100);
	count++;
	   printf ("Check point count = %d,\n ", count);
	   HAL_Delay(100);

    memset(buffer,0,sizeof(buffer));
	    sprintf(ATcommand,"AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"\r\n");
		HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
		HAL_Delay(100);
	 count++;
		printf ("Check point count = %d,\n ", count);
		HAL_Delay(100);

    memset(buffer,0,sizeof(buffer));
		sprintf(ATcommand,"AT+SAPBR=3,1,\"APN\",\"CMNET\"\r\n");
		HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
		HAL_Delay(100);
		 count++;
		    printf ("Check point count = %d,\n ", count);
		    HAL_Delay(100);

    memset(buffer,0,sizeof(buffer));
		sprintf(ATcommand,"AT+CSTT=Tespack\r\n");
		HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
		HAL_Delay(100);
		 count++;
		    printf ("Check point count = %d,\n ", count);
		    HAL_Delay(100);

    memset(buffer,0,sizeof(buffer));
 		sprintf(ATcommand,"AT+SAPBR=1,1\r\n");
		HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
		HAL_Delay(100);
		 count++;
		    printf ("Check point count = %d,\n ", count);
		    HAL_Delay(100);

    memset(buffer,0,sizeof(buffer));
		sprintf(ATcommand,"AT+SAPBR=2,1\r\n");
		HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
		HAL_Delay(100);
		 count++;
		    printf ("Check point count = %d,\n ", count);
		    HAL_Delay(100);

    memset(buffer,0,sizeof(buffer));
		sprintf(ATcommand,"AT+CIICR\r\n");
		HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
		HAL_Delay(100);
		 count++;
		    printf ("Check point count = %d,\n ", count);
		    HAL_Delay(100);

		//*GPRS ACTIVE CODE END*//


		//DEMO START//
//
//		 memset(buffer,0,sizeof(buffer));
//				sprintf(ATcommand,"AT+CIFSR\r\n");
//				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
//				HAL_Delay(100);
//		 memset(buffer,0,sizeof(buffer));
//				sprintf(ATcommand,"AT+CIPSPRT=0\r\n");
//				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
//				HAL_Delay(100);
//		 memset(buffer,0,sizeof(buffer));
//				sprintf(ATcommand,"AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"\r\n");
//				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
//				HAL_Delay(100);
//		 memset(buffer,0,sizeof(buffer));
//				sprintf(ATcommand,"AT+CIPSEND\r\n");
//				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
//				HAL_Delay(100);
//		 memset(buffer,0,sizeof(buffer));
//				sprintf(ATcommand,"AT+HTTPPARA=\"URL\",api.thingspeak.com/update?api_key=PM6D6N0YMZVV9COX&field1=0\r\n");
//				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),sizeof(buffer));
//				HAL_Delay(100);


		//Demo END//






		//*Data sending CODE START*//

		 memset(buffer,0,sizeof(buffer));
				sprintf(ATcommand,"AT+HTTPINIT\r\n");
				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),sizeof(buffer));
				HAL_Delay(100);
				 count++;
				    printf ("Check point count = %d,\n ", count);
				    HAL_Delay(100);

		  memset(buffer,0,sizeof(buffer));
				sprintf(ATcommand,"AT+HTTPPARA=\"CID\",1\r\n");
				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),sizeof(buffer));
				HAL_Delay(100);
				 count++;
				    printf ("Check point count = %d,\n ", count);
				    HAL_Delay(100);

		  memset(buffer,0,sizeof(buffer));
				sprintf(ATcommand,"AT+HTTPPARA=\"URL\",api.thingspeak.com/update?api_key=PM6D6N0YMZVV9COX&field1=0\r\n");
				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),sizeof(buffer));
				HAL_Delay(100);
				 count++;
				    printf ("Check point count = %d,\n ", count);
				    HAL_Delay(100);

		  memset(buffer,0,sizeof(buffer));
		        sprintf(ATcommand,"AT+HTTPPARA=\"REDIR\",1\r\n");
				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),sizeof(buffer));
				HAL_Delay(100);
				 count++;
				    printf ("Check point count = %d,\n ", count);
				    HAL_Delay(100);

		  memset(buffer,0,sizeof(buffer));
				sprintf(ATcommand,"AT+HTTPSSL=1\r\n");
				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),sizeof(buffer));
				HAL_Delay(100);
				 count++;
				    printf ("Check point count = %d,\n ", count);
				    HAL_Delay(100);

		  memset(buffer,0,sizeof(buffer));
				sprintf(ATcommand,"AT+HTTPACTION=0\r\n");
				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),sizeof(buffer));
				HAL_Delay(100);
				 count++;
				    printf ("Check point count = %d,\n ", count);
				    HAL_Delay(100);

		  memset(buffer,0,sizeof(buffer));
				sprintf(ATcommand,"AT+HTTPREAD\r\n");
				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),sizeof(buffer));
				HAL_Delay(100);
				 count++;
				    printf ("Check point count = %d,\n ", count);
				    HAL_Delay(100);

		  memset(buffer,0,sizeof(buffer));
				sprintf(ATcommand,"AT+HTTPTERM\r\n");
				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),sizeof(buffer));
				HAL_Delay(100);
				 count++;
				    printf ("Check point count = %d,\n ", count);
				    HAL_Delay(100);


		//*Data sending CODE END*//

		//*GPS deactivation CODE START*//

//		memset(buffer,0,sizeof(buffer));
//				sprintf(ATcommand,"AT+SAPBR=0,1\r\n");
//				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),sizeof(buffer));
//				HAL_Delay(100);
//		memset(buffer,0,sizeof(buffer));
//				sprintf(ATcommand,"AT+CGNSPWR=0\r\n"); //#########   GPS Shut Down     ##########//
//				HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),sizeof(buffer));
//				HAL_Delay(3000);

		//*GPS deactivation CODE END*//


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
