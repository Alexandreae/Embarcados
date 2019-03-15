/** 
 ** Entrega realizada por:
 **  - WARLEN CÉSAR RODRIGUES FILHO
 **  - ALEXANDRE ALMEIDA EDINGTON
 **
 **  - VÍDEO NO REPOSITÓRIO
 **  - https://youtu.be/aRU4Zoluhlc
 **/

/************************************************************************/
/* includes                                                             */
/************************************************************************/

#include "asf.h"

/************************************************************************/
/* defines                                                              */
/************************************************************************/

// BUZZER

#define BUZZER_PIO           PIOA			// DEFININDO O PIO DO BUZZER 
#define BUZZER_PIO_ID        ID_PIOA            // ID DO PIO
#define BUZZER_PIO_IDX      4u             // ID DO PINO QUE ALIMENTARÁO BUZZER NO PIO
#define BUZZER_PIO_IDX_MASK  (1u << BUZZER_PIO_IDX)   // MASCARA PARA MUDAR A TABELA DO PIO COM A INFO QUE QUEREMOS NA LINHA E COLUNA DO PINO

// LEDS

#define LED1_OLED_PIO           PIOA
#define LED1_OLED_PIO_ID        10
#define LED1_OLED_PIO_IDX		0u
#define LED1_OLED_PIO_IDX_MASK  (1u << LED1_OLED_PIO_IDX)

#define LED2_OLED_PIO           PIOC
#define LED2_OLED_PIO_ID        12  
#define LED2_OLED_PIO_IDX		30u 
#define LED2_OLED_PIO_IDX_MASK  (1u << LED2_OLED_PIO_IDX)

#define LED3_OLED_PIO           PIOB                // periferico que controla o LED
#define LED3_OLED_PIO_ID        11                  // ID do periférico PIOC (controla LED)
#define LED3_OLED_PIO_IDX		2u                    // ID do LED no PIO
#define LED3_OLED_PIO_IDX_MASK  (1u << LED3_OLED_PIO_IDX)   // Mascara para CONTROLARMOS o LED ;;6 PB2

// BUTTONS

#define BUTTON_SAME_PIO PIOA	// BOTÃO DA PLACA (NÃO O RESET, O OUTRO)
#define BUTTON_SAME_PIO_ID 10
#define BUTTON_SAME_PIO_IDX 11
#define BUTTON_SAME_PIO_IDX_MASK (1u << BUTTON_SAME_PIO_IDX)

#define BUTTON1_OLED_PIO PIOD   // PLAY - EXIT1 9 PD28
#define BUTTON1_OLED_PIO_ID 16
#define BUTTON1_OLED_PIO_IDX 28
#define BUTTON1_OLED_PIO_IDX_MASK (1u << BUTTON1_OLED_PIO_IDX)

#define BUTTON2_OLED_PIO PIOA  // STOP - EXIT1 4 PA19
#define BUTTON2_OLED_PIO_ID 10
#define BUTTON2_OLED_PIO_IDX 19
#define BUTTON2_OLED_PIO_IDX_MASK (1u << BUTTON2_OLED_PIO_IDX)

#define BUTTON3_OLED_PIO PIOC // NEXT - EXIT1 3 PC31
#define BUTTON3_OLED_PIO_ID 12
#define BUTTON3_OLED_PIO_IDX 31
#define BUTTON3_OLED_PIO_IDX_MASK (1u << BUTTON3_OLED_PIO_IDX)

// NOTES
 
 //		NAME	FREQ
 
#define NOTE_C4  262 
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5 988
#define c  261
#define d  294
#define e  329
#define f  349
#define g  391
#define gS  415
#define a  440
#define aS  455
#define b  466
#define cH  523
#define cSH  554
#define dH  587
#define dSH  622
#define eH  659
#define fH  698
#define fSH  740
#define gH  784
#define gSH  830
#define aH  880
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define NOTE_B4b 466

/*MUSICAS*/

//Piratas do Caribe
int pirate_notes[] = {
	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
	NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
	NOTE_A4, NOTE_G4, NOTE_A4, 0,
	
	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
	NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
	NOTE_A4, NOTE_G4, NOTE_A4, 0,
	
	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
	NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
	NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
	NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
	
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
	NOTE_D5, NOTE_E5, NOTE_A4, 0,
	NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
	NOTE_C5, NOTE_A4, NOTE_B4, 0,

	NOTE_A4, NOTE_A4,
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
	NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
	NOTE_A4, NOTE_G4, NOTE_A4, 0,

	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
	NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
	NOTE_A4, NOTE_G4, NOTE_A4, 0,
	
	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
	NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
	NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
	NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
	
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
	NOTE_D5, NOTE_E5, NOTE_A4, 0,
	NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
	NOTE_C5, NOTE_A4, NOTE_B4, 0,

	NOTE_E5, 0, 0, NOTE_F5, 0, 0,
	NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
	NOTE_D5, 0, 0, NOTE_C5, 0, 0,
	NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

	NOTE_E5, 0, 0, NOTE_F5, 0, 0,
	NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
	NOTE_D5, 0, 0, NOTE_C5, 0, 0,
	NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4
};

int pirate_tempo[] = {
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 375, 125,
	
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 375, 125,
	
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 125, 250, 125,

	125, 125, 250, 125, 125,
	250, 125, 250, 125,
	125, 125, 250, 125, 125,
	125, 125, 375, 375,

	250, 125,
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 375, 125,
	
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 375, 125,
	
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 125, 250, 125,

	125, 125, 250, 125, 125,
	250, 125, 250, 125,
	125, 125, 250, 125, 125,
	125, 125, 375, 375,
	
	250, 125, 375, 250, 125, 375,
	125, 125, 125, 125, 125, 125, 125, 125, 375,
	250, 125, 375, 250, 125, 375,
	125, 125, 125, 125, 125, 500,

	250, 125, 375, 250, 125, 375,
	125, 125, 125, 125, 125, 125, 125, 125, 375,
	250, 125, 375, 250, 125, 375,
	125, 125, 125, 125, 125, 500
};

int tetrisNotes[] = { 
	NOTE_E6, NOTE_B5, NOTE_C6, NOTE_D6,
	NOTE_C6, NOTE_B5, NOTE_A5, NOTE_A5,
	NOTE_C6, NOTE_E6, NOTE_D6, NOTE_C6, 
	NOTE_B5, NOTE_C6, NOTE_D6, NOTE_E6, 
	NOTE_C6, NOTE_A5, NOTE_A5, NOTE_A5, 
	NOTE_B5, NOTE_C6, NOTE_D6, NOTE_F6, 
	NOTE_A6, NOTE_G6, NOTE_F6, NOTE_E6, 
	NOTE_C6, NOTE_E6, NOTE_D6, NOTE_C6, 
	NOTE_B5, NOTE_B5, NOTE_C6, NOTE_D6,
	NOTE_E6, NOTE_C6, NOTE_A5, NOTE_A5
};

int tetrisDurations[] = {
	200, 100, 100, 200, 
	100, 100, 200, 100, 
	100, 200, 100, 100, 
	300, 100, 200, 200, 
	200, 200, 100, 100, 
	100, 100, 300, 100, 
	200, 100, 100, 300, 
	100, 200, 100, 100, 
	200, 100, 100, 200, 
	200, 200, 200, 200
};

int happyBirthdayNotes[] = {
	NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4,
	NOTE_F4, NOTE_E4, NOTE_C4, NOTE_C4, 
	NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4, 
	NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, 
	NOTE_F4, NOTE_E4, NOTE_D4, NOTE_B4b, 
	NOTE_B4b, NOTE_A4,NOTE_F4, NOTE_G4, NOTE_F4};

int happyBirthdayDuration [] = {
	100, 100, 200, 200, 
	200, 250, 100, 100, 
	200, 200, 200, 250, 
	100, 100, 200, 200, 
	200, 200, 200, 100, 
	100, 200, 200, 200, 300};

/************************************************************************/
/* constants                                                            */
/************************************************************************/

/************************************************************************/
/* variaveis globais                                                    */
/************************************************************************/

/************************************************************************/
/* prototypes                                                           */
/************************************************************************/

/************************************************************************/
/* interrupcoes                                                         */
/************************************************************************/

/************************************************************************/
/* funcoes                                                              */
/************************************************************************/

// Função de inicialização do uC
void init(void)
{
	/* INICIALIZAR CLOCK*/
	sysclk_init();
	
	/* DESABILITANDO WATCHDOG TIMER*/
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	/* INICIALIZAR PMC*/
	// Ativa os PIOs nos quais os Componentes estão conectados
	
	// BUTTON_SAME NA
	// BUTTON1 PLAY
	// BUTTON2 STOP
	// BUTTON3 NEXT
	
	pmc_enable_periph_clk(BUZZER_PIO_ID);
	pmc_enable_periph_clk(LED1_OLED_PIO_ID);
	pmc_enable_periph_clk(LED2_OLED_PIO_ID);
	pmc_enable_periph_clk(LED3_OLED_PIO_ID);
	pmc_enable_periph_clk(BUTTON_SAME_PIO_ID);
	pmc_enable_periph_clk(BUTTON1_OLED_PIO_ID);
	pmc_enable_periph_clk(BUTTON2_OLED_PIO_ID);
	pmc_enable_periph_clk(BUTTON3_OLED_PIO_ID);
			
	
	/* INICIALIZAR PIO*/
	
	/*Inicializando default de início das saídas LED e BUZZER*/
	
	pio_set_output(BUZZER_PIO, BUZZER_PIO_IDX_MASK, 0, 0, 0);
	pio_set_output(LED1_OLED_PIO, LED1_OLED_PIO_IDX_MASK, 0, 0, 0);
	pio_set_output(LED2_OLED_PIO, LED2_OLED_PIO_IDX_MASK, 0, 0, 0);
	pio_set_output(LED3_OLED_PIO, LED3_OLED_PIO_IDX_MASK, 0, 0, 0);
		
	/*Inicializando o default das entradas de Buttons*/
	pio_set_input(BUTTON_SAME_PIO, BUTTON_SAME_PIO_IDX_MASK, PIO_DEFAULT);
	pio_set_input(BUTTON1_OLED_PIO, BUTTON1_OLED_PIO_IDX_MASK, PIO_DEFAULT);
	pio_set_input(BUTTON2_OLED_PIO, BUTTON2_OLED_PIO_IDX_MASK, PIO_DEFAULT);
	pio_set_input(BUTTON3_OLED_PIO, BUTTON3_OLED_PIO_IDX_MASK, PIO_DEFAULT);	
	
	pio_pull_up(BUTTON_SAME_PIO, BUTTON_SAME_PIO_IDX_MASK, PIO_PULLUP);
	pio_pull_up(BUTTON1_OLED_PIO, BUTTON1_OLED_PIO_IDX_MASK, PIO_PULLUP);
	pio_pull_up(BUTTON2_OLED_PIO, BUTTON2_OLED_PIO_IDX_MASK, PIO_PULLUP);
	pio_pull_up(BUTTON3_OLED_PIO, BUTTON3_OLED_PIO_IDX_MASK, PIO_PULLUP);
	
}

void playNote(int note, int duration){
	for (int i = 0; i < duration; i++){
		pio_set(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
		delay_us((1000000/note)/2);
		pio_clear(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
		delay_us((1000000/note)/2);		
	}		
}

void playSong(int notes[], int sizeOne, int times[], int sizeTwo){
	for (int i = 0; i < sizeOne; i++){
		if(!pio_get(BUTTON1_OLED_PIO, PIO_INPUT, BUTTON1_OLED_PIO_IDX_MASK) || !pio_get(BUTTON2_OLED_PIO, PIO_INPUT, BUTTON2_OLED_PIO_IDX_MASK) ||
		 !pio_get(BUTTON3_OLED_PIO, PIO_INPUT, BUTTON3_OLED_PIO_IDX_MASK) || !pio_get(BUTTON_SAME_PIO, PIO_INPUT, BUTTON_SAME_PIO_IDX_MASK)){
			 break;
		 }
		playNote(notes[i], times[i]);
		delay_ms(times[i]/6);
	}
}

/************************************************************************/
/* Main                                                                 */
/************************************************************************/

// Funcao principal chamada na inicalizacao do uC.
int main(void) {
	// inicializa sistema e IOs
	init();

	pio_set(LED1_OLED_PIO, LED1_OLED_PIO_IDX_MASK);
	pio_set(LED2_OLED_PIO, LED2_OLED_PIO_IDX_MASK);
	pio_set(LED3_OLED_PIO, LED3_OLED_PIO_IDX_MASK);

	
	// super loop
	while (1)
	{
		if (!pio_get(BUTTON1_OLED_PIO, PIO_INPUT, BUTTON1_OLED_PIO_IDX_MASK)){
			pio_clear(LED1_OLED_PIO, LED1_OLED_PIO_IDX_MASK);
			pio_set(LED2_OLED_PIO, LED2_OLED_PIO_IDX_MASK);
			pio_set(LED3_OLED_PIO, LED3_OLED_PIO_IDX_MASK);
			playSong(pirate_notes, sizeof(pirate_notes)/sizeof(int), pirate_tempo, sizeof(pirate_tempo)/sizeof(int));
			}
			
		if (!pio_get(BUTTON3_OLED_PIO, PIO_INPUT, BUTTON3_OLED_PIO_IDX_MASK)){
			pio_set(LED1_OLED_PIO, LED1_OLED_PIO_IDX_MASK);
			pio_clear(LED2_OLED_PIO, LED2_OLED_PIO_IDX_MASK);
			pio_set(LED3_OLED_PIO, LED3_OLED_PIO_IDX_MASK);			
			playSong(tetrisNotes, sizeof(tetrisNotes)/sizeof(int), tetrisDurations, sizeof(tetrisDurations)/sizeof(int));
		}
		
		if (!pio_get(BUTTON2_OLED_PIO, PIO_INPUT, BUTTON2_OLED_PIO_IDX_MASK)){
			pio_set(LED1_OLED_PIO, LED1_OLED_PIO_IDX_MASK);
			pio_set(LED2_OLED_PIO, LED2_OLED_PIO_IDX_MASK);
			pio_clear(LED3_OLED_PIO, LED3_OLED_PIO_IDX_MASK);
			playSong(happyBirthdayNotes, sizeof(happyBirthdayNotes)/sizeof(int), happyBirthdayDuration, sizeof(happyBirthdayDuration)/sizeof(int));
		}
	}	
	
	return 0;
}