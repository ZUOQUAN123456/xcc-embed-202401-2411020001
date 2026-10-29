#define RCC_AHB1ENR   (*(volatile unsigned int *)0x40023830)
#define GPIOF_MODER   (*(volatile unsigned int *)0x40021400)
#define GPIOF_ODR     (*(volatile unsigned int *)0x40021414)

void SoftDelay(unsigned int t)
{
	while(t--);
}

void LED_Init(void)
{
	RCC_AHB1ENR |= (1 << 5);    // ??GPIOF??
	GPIOF_MODER &= 0xFFFF0000;
	GPIOF_MODER |= 0x00005555;  // PF0~PF7 ?????
	GPIOF_ODR |= 0x00FF;        // ??????(?????)
}

int main(void)
{
	unsigned int dat = 0x0001;
	LED_Init();
	while(1)
	{
		GPIOF_ODR = ~dat;
		SoftDelay(800000);
		dat <<= 1;
		if(dat >= 0x0100)
		{
			dat = 0x0001;
		}
	}
}

