/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
void disp_select(uint8_t display)
{
	switch(display) {
	case 1:
		HAL_GPIO_WritePin(GPIOC, S7Com1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, S7Com2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, S7Com3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, S7Com4_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOC, S7Com1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, S7Com2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, S7Com3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, S7Com4_Pin, GPIO_PIN_SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOC, S7Com1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, S7Com2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, S7Com3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, S7Com4_Pin, GPIO_PIN_SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOC, S7Com1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, S7Com2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, S7Com3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, S7Com4_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOC, S7Com1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, S7Com2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, S7Com3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, S7Com4_Pin, GPIO_PIN_SET);
		break;
	default:
		break;
	}

}

void number_select(uint8_t number)
{
	switch(number) {
	case 0:
			HAL_GPIO_WritePin(GPIOC, S7A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7G_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7Dp_Pin, GPIO_PIN_RESET);
			break;
	case 1:
			HAL_GPIO_WritePin(GPIOC, S7A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7D_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7E_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7G_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7Dp_Pin, GPIO_PIN_RESET);
			break;
	case 2:
			HAL_GPIO_WritePin(GPIOC, S7A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7C_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7G_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7Dp_Pin, GPIO_PIN_RESET);
			break;
	case 3:
			HAL_GPIO_WritePin(GPIOC, S7A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7E_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7G_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7Dp_Pin, GPIO_PIN_RESET);
			break;
	case 4:
			HAL_GPIO_WritePin(GPIOC, S7A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7D_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7E_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7G_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7Dp_Pin, GPIO_PIN_RESET);
			break;
	case 5:
			HAL_GPIO_WritePin(GPIOC, S7A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7B_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7E_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7G_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7Dp_Pin, GPIO_PIN_RESET);
			break;
	case 6:
			HAL_GPIO_WritePin(GPIOC, S7A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7B_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7G_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7Dp_Pin, GPIO_PIN_RESET);
			break;
	case 7:
			HAL_GPIO_WritePin(GPIOC, S7A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7D_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7E_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7G_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7Dp_Pin, GPIO_PIN_RESET);
			break;
	case 8:
			HAL_GPIO_WritePin(GPIOC, S7A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7G_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7Dp_Pin, GPIO_PIN_RESET);
			break;
	case 9:
			HAL_GPIO_WritePin(GPIOC, S7A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7E_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, S7F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7G_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOC, S7Dp_Pin, GPIO_PIN_RESET);
			break;
	default:
			break;
	}
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  	int counter = 0;
    int sg1_numb = 0;
    int sg2_numb = 0;
    int sg3_numb = 0;
    int sg4_numb = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  sg1_numb = counter/1000;
	  sg2_numb = (counter/100)%10;
	  sg3_numb = (counter/10)%10;
	  sg4_numb = counter%10;
	  for (int i=0; i<10; i++){
	  	  disp_select(1);
	  	  number_select(sg1_numb);
	  	  HAL_Delay(4);
	  	  disp_select(2);
	  	  number_select(sg2_numb);
	  	  HAL_Delay(4);
	  	  disp_select(3);
	  	  number_select(sg3_numb);
	  	  HAL_Delay(4);
	  	  disp_select(4);
	  	  number_select(sg4_numb);
	  	  HAL_Delay(4);
	  }
	  counter++;
	  if (counter > 9999)
	  	counter = 0;
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, S7G_Pin|S7D_Pin|S7E_Pin|S7C_Pin
                          |S7B_Pin|S7F_Pin|S7A_Pin|S7Dp_Pin
                          |S7Com4_Pin|S7Com3_Pin|S7Com2_Pin|S7Com1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : S7G_Pin S7D_Pin S7E_Pin S7C_Pin
                           S7B_Pin S7F_Pin S7A_Pin S7Dp_Pin
                           S7Com4_Pin S7Com3_Pin S7Com2_Pin S7Com1_Pin */
  GPIO_InitStruct.Pin = S7G_Pin|S7D_Pin|S7E_Pin|S7C_Pin
                          |S7B_Pin|S7F_Pin|S7A_Pin|S7Dp_Pin
                          |S7Com4_Pin|S7Com3_Pin|S7Com2_Pin|S7Com1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
