#ifndef __ADS1292_H
#define __ADS1292_H
#include "sys.h"


////////////////////////////////////////////////////////////////////////////////
//���ź궨��
#define ADS_DRDY		PBin(5)
#define ADS_CS			PBout(6)
//	#define ADS_RESET 	PAout(0)
//	#define ADS_START	PAout(2)
//	#define ADS_CLKSEL	PAout(3)

/////////////////////////////////////////////////////////////////////////////////////////////
//��������
extern	volatile u8 ads1292_Cache[9];		//ads1292���ݻ���
extern  volatile u8 ads1292_recive_flag;	//���ݶ�ȡ��ɱ�־



/////////////////////////////////////////////////////////////////////////////////////////////
//ADS1292R ���к����͵���������Ĺ���
//ID
#define	ADS1292_DEVICE	DEVICE_ID_ADS1292R		//ע��1292оƬ����ʹ�ú�����صĹ��ܣ��ᵼ�����ݲ�����
//1		CONFIG1
#define DATA_RATE  				DATA_RATE_500SPS		//����ʱ��ԭ�򣬲����ʻ������
//2		CONFIG2
#define	PDB_LOFF_COMP 		PDB_LOFF_COMP_OFF		//��������Ƚ���
#define	PDB_REFBUF				PDB_REFBUF_ON				//��׼��ѹ������
#define	VREF							VREF_242V						//�����ڲ��ο���ѹ
#define	CLK_EN						CLK_EN_OFF					//ʹ���ڲ�ʱ��ʱ��CLK�����Ƿ����ʱ���ź�
#define	INT_TEST					INT_TEST_OFF				//�Ƿ���ڲ������ź�
//4	5		CHSET
#define	CNNNLE1_POWER			PD_ON								//ͨ����Դ
#define	CNNNLE1_GAIN			GAIN_2							//����
#define	CNNNLE1_MUX				MUX_Normal_input		//���뷽ʽ
#define	CNNNLE2_POWER			PD_ON
#define	CNNNLE2_GAIN			GAIN_6
#define	CNNNLE2_MUX				MUX_Normal_input
//6		RLD_SENS
#define	PDB_RLD						PDB_RLD_ON					//RLD�����Դ		
#define	RLD_LOFF_SENSE		RLD_LOFF_SENSE_OFF	//RLD�������书�ܣ����Ե�ʱ�������ȵ���������������������������ͬʱ������
#define	RLD2N							RLD_CANNLE_ON				//ͨ���������������
#define	RLD2P							RLD_CANNLE_ON
#define	RLD1N							RLD_CANNLE_OFF			//����ͨ������Ҫ��������
#define	RLD1P							RLD_CANNLE_OFF
//7		LOFF_SENS
#define	FLIP2							FLIP2_OFF						//���λ���ڿ��Ƶ���������ͨ��1�ĵ����ķ���
#define	FLIP1							FLIP1_OFF						//���λ���ڿ��Ƶ���������ͨ��2�ĵ����ķ���
#define	LOFF2N						RLD_CANNLE_ON			//ͨ�����������⹦��
#define	LOFF2P						RLD_CANNLE_ON
#define	LOFF1N						RLD_CANNLE_OFF			//����ͨ������Ҫ����������
#define	LOFF1P						RLD_CANNLE_OFF
//9		RSP1
#define	RESP_DEMOD_EN1		RESP_DEMOD_ON		//����ͨ��1�����·
#define	RESP_MOD_EN				RESP_MOD_ON			//����ͨ��1���Ƶ�·
#define	RESP_PH						0X0D					//���ƽ���źŵ���λ	135																					
#define	RESP_CTRL					RESP_CTRL_CLOCK_INTERNAL//�ڲ������ڲ�ʱ��
//10		RSP2
#define	CALIB							CALIB_OFF								//ͨ��ƫ��У�� //���й���������ı�������Ҫ��ͨ��ƫ��У������ִ�� OFFSETCAL ָ��
#define	FREQ							FREQ_32K								//��������Ƶ��	64K/32K
#define	RLDREF_INT				RLDREF_INT_INTERNALLY		//RLD�ο� �ڲ�����  ���������Ĳο���ѹ����ѡ���ڲ�����(AVDD + AVSS) / 2��Ҳ����ѡ���ⲿ�ṩ




//ADS1292R�����
//ϵͳ����
#define WAKEUP	0X02	//�Ӵ���ģʽ����
#define STANDBY	0X04	//�������ģʽ
#define RESET	0X06	//��λADS1292R
#define START	0X08	//������ת��
#define STOP	0X0A	//ֹͣת��
#define OFFSETCAL	0X1A	//ͨ��ƫ��У׼

//���ݶ�ȡ����
#define RDATAC	0X10	//�������������ݶ�ȡģʽ,Ĭ��ʹ�ô�ģʽ
#define SDATAC	0X11	//ֹͣ���������ݶ�ȡģʽ
#define RDATA		0X12	//ͨ�������ȡ����;֧�ֶ��ֶ��ء�
//�Ĵ�����ȡ����
//r rrrr=Ҫ����д�ļĴ����׵�ַ	 //	n nnnn=Ҫ��д�ļĴ�������
#define RREG	0X20	//��ȡ  001r rrrr(���ֽ�) 000n nnnn(2�ֽ�) 
#define WREG	0X40	//д��  010r rrrr(���ֽ�) 000n nnnn(2�ֽ�)

//ADS1292R�ڲ��Ĵ�����ַ����
#define ID					0	//ID���ƼĴ���
#define CONFIG1			1	//���üĴ���1
#define CONFIG2			2	//���üĴ���2
#define LOFF				3	//����������ƼĴ���
#define CH1SET			4	//ͨ��1���üĴ���
#define CH2SET			5	//ͨ��2���üĴ���
#define RLD_SENS		6	//��������ѡ��Ĵ���
#define LOFF_SENS		7	//����������ѡ��Ĵ���
#define LOFF_STAT		8	//����������״̬�Ĵ���
#define	RESP1				9	//���������ƼĴ���1
#define	RESP2				10//���������ƼĴ���2
#define	GPIO				11//GPIO���ƼĴ���


/////////////////////////////////////////////////////////////////////////////////////////////
//�Ĵ�������
//ID
#define	DEVICE_ID_ADS1292		0X53
#define	DEVICE_ID_ADS1292R	0X73
//CONFIG1
#define	DATA_RATE_125SPS	0X00	//������
#define	DATA_RATE_250SPS	0X01
#define	DATA_RATE_500SPS	0X02
#define	DATA_RATE_1kSPS		0X03
#define	DATA_RATE_2kSPS		0X04
#define	DATA_RATE_4kSPS		0X05
#define	DATA_RATE_8kSPS		0X06
//CONFIG2
#define	PDB_LOFF_COMP_OFF	0	//��������Ƚ������磨Ĭ�ϣ�
#define	PDB_LOFF_COMP_ON	1
#define	PDB_REFBUF_OFF	0		//��׼��ѹ���������磨Ĭ�ϣ�
#define	PDB_REFBUF_ON		1
#define	VREF_242V		0	//�ڲ��ο���ѹ2.42V��Ĭ�ϣ�
#define	VREF_4V			1	//�ڲ��ο���ѹ4.033V
#define	CLK_EN_OFF	0	//����ʱ��������ã�Ĭ�ϣ�
#define	CLK_EN_ON		1
#define	INT_TEST_OFF	0	//�ر��ڲ������źţ�Ĭ�ϣ�
#define	INT_TEST_ON		1
//CHSET
#define	PD_ON			0	//ͨ���������У�Ĭ�ϣ�	
#define	PD_OFF		1
#define	GAIN_6		0//����6��Ĭ�ϣ�
#define	GAIN_1		1
#define	GAIN_2		2
#define	GAIN_3		3
#define	GAIN_4		4
#define	GAIN_8		5
#define	GAIN_12		6
#define	MUX_Normal_input 	0		//��ͨ�缫���루Ĭ�ϣ�
#define	MUX_input_shorted 1		//�����·
#define	MUX_Test_signal 	5		//�����ź�����
#define	MUX_RLD_DRP				6
#define	MUX_RLD_DRM				7
#define	MUX_RLD_DRPM			8
#define	MUX_RSP_IN3P			9		//������ͨ��1
//RLD_SENS
#define	PDB_RLD_OFF					0//��Ĭ�ϣ�
#define	PDB_RLD_ON					1
#define	RLD_LOFF_SENSE_OFF	0//��Ĭ�ϣ�
#define	RLD_LOFF_SENSE_ON		1
#define	RLD_CANNLE_OFF			0//��Ĭ�ϣ�
#define	RLD_CANNLE_ON				1
//LOFF_SENS
#define	FLIP2_OFF			0//��Ĭ�ϣ�
#define	FLIP2_ON			1
#define	FLIP1_OFF			0//��Ĭ�ϣ�
#define	FLIP1_ON			1
#define	LOFF_CANNLE_OFF		0//��Ĭ�ϣ�
#define	LOFF_CANNLE_ON		1
//RSP1
#define	RESP_DEMOD_OFF	0	//��Ĭ�ϣ�
#define	RESP_DEMOD_ON		1
#define	RESP_MOD_OFF 		0	//��Ĭ�ϣ�
#define	RESP_MOD_ON			1
#define	RESP_CTRL_CLOCK_INTERNAL	0
#define	RESP_CTRL_CLOCK_EXTERNAL	1
//RSP2
#define	CALIB_OFF		0//��Ĭ�ϣ�
#define	CALIB_ON		1
#define	FREQ_32K		0	//��Ĭ�ϣ�
#define	FREQ_64K		1
#define	RLDREF_INT_EXTERN				0//�ⲿ����RLDREF
#define	RLDREF_INT_INTERNALLY		1//�ڲ�




typedef struct
{
    u8 Data_Rate; //ADCͨ��������
} ADS1292_CONFIG1;
typedef struct
{
    u8	Pdb_Loff_Comp; 	//��������Ƚ����Ƿ����
    u8	Pdb_Refbuf;			//�ڲ��ο��������Ƿ����
    u8	Vref;				//�ڲ��ο���ѹ����
    u8	Clk_EN;					//����ʱ���������
    u8	Int_Test;				//�ڲ������ź�ʹ��λ
} ADS1292_CONFIG2;
typedef struct
{
    u8  PD;			//ͨ���ϵ磿
    u8	GAIN;		//����PGA����
    u8	MUX;		//����ͨ�����뷽ʽ
} ADS1292_CHSET;
typedef struct
{
    u8	Pdb_Rld;				//��λ����RLD�����Դ״̬
    u8	Rld_Loff_Sense;	//��λʹ��RLD���������⹦��
    u8	Rld2N;					//���λ����ͨ��2������ �����������������
    u8	Rld2P;					//��λ����ͨ��2������ �����������������
    u8	Rld1N;					//���λ����ͨ��1������ �����������������
    u8	Rld1P;					//��λ����ͨ��1������ �����������������
} ADS1292_RLD_SENS;
typedef struct
{
    u8	Flip2;//���λ���ڿ��Ƶ���������ͨ��2�ĵ����ķ���
    u8	Flip1;//���λ�������ڵ���������ͨ��1�ĵ����ķ���
    u8	Loff2N;//��λ����ͨ��2������˵ĵ���������
    u8	Loff2P;//��λ����ͨ��2������˵ĵ���������
    u8	Loff1N;//��λ����ͨ��1������˵ĵ���������
    u8	Loff1P;//��λ����ͨ��1������˵ĵ���������
} ADS1292_LOFF_SENS;
typedef struct
{
    u8	RESP_DemodEN;		//ͨ��ƫ��У׼
    u8	RESP_modEN;	//RLDREF�ź�Դ
    u8	RESP_ph;
    u8	RESP_Ctrl;
} ADS1292_RESP1;
typedef struct
{
    u8	Calib;		//ͨ��ƫ��У׼
    u8	freq;			//Ƶ�� 32k 64k
    u8	Rldref_Int;	//RLDREF�ź�Դ
} ADS1292_RESP2;





void ADS1292_Init(void); //��ʼ��ADS1292����
void ADS1292_PowerOnInit(void);//�ϵ��ʼ��
u8 ADS1292_SPI(u8 com);

void ADS1292_Send_CMD(u8 data);//��������
void ADS1292_WR_REGS(u8 reg,u8 len,u8 *data);//��д����Ĵ���
u8 ADS1292_Read_Data(u8 *data);//��9�ֽ�����

void ADS1292_SET_REGBUFF(void);//���üĴ�������
u8 ADS1292_WRITE_REGBUFF(void);//���Ĵ�������д��Ĵ���

u8 ADS1292_Noise_Test(void);
u8 ADS1292_Single_Test(void);//����ͨ��1�ڲ�1mV�����ź�
u8 ADS1292_Single_Read(void);//���������źŲɼ�ģʽ
u8 Set_ADS1292_Collect(u8 mode);//�������ݲɼ���ʽ

#endif


//�ֲἰ��̳���ϣ�
//����CLK����ʹ���ڲ�ʱ�ӻ���ʹ���ⲿʱ�ӣ����ʹ���ڲ�ʱ�ӣ����Խ���ӵء����ʹ���ⲿʱ�ӣ����Խ���Դ�������MCU��ʱ��������Ÿ�ADS1292 �ṩʱ�ӡ�
//ʹ���ڲ�����Ļ����Ĵ���CONFIG2��bit3 �������Ϊ1�Ļ�����ôCLK�������Ƶ�ʼ�Ϊ�ڲ�ʱ�Ӳ�����Ƶ�ʣ��������Ϊ0�Ļ�����ôCLK���disable
//SCLK ��ΪSPI��Ƶ�ʣ����Ĵ�Сdatasheet�Ѿ���������2.7 V �� DVDD �� 3.6 V������tSCLK��min��=50ns�� ��1.7 V �� DVDD �� 2 Vʱ��tSCLK��min��=66.6ns

//1. ��������ģʽ�£����ܶ�д�Ĵ�������������ģʽ�£�����Ҫ������ֹͣ SDATAC ��Ȼ����ܷ����������
//2. �ֲ���������������1292 ���ն��ֽ�����ʱ������һ���ֽ���Ҫ 7.2us������㷢�Ͷ��ֽ�����ʱ�������ֽ�֮��ļ������Ҫ��8us
//��������
//	���� CLKSEL =1 	ʹ���ڲ�ʱ�ӣ�
//	���� PWDN/RESET = 1  �ȴ�1�� ������λ�͵ȴ�����
//	����SDATAC����  ���üĴ���
//	����WREG CONFIG2 A0h	ʹ���ڲ��ο���ѹ��
//	����START = 1		����ת��
//	����RDATAC����	���豸�ָ���RDATACģʽ
//	�������ݲ��������
//	�������ݲ������ź�