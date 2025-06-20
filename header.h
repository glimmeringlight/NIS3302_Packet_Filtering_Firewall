#define CMD_MIN		0x6000//十进制：24576
 
#define CMD_GET_DEBUG_STATE	    CMD_MIN+1
#define CMD_SET_DEBUG_STATE     CMD_MIN+2
#define CMD_GET_RULES           CMD_MIN+3
#define CMD_ADD_RULE            CMD_MIN+4
#define CMD_DEL_RULE            CMD_MIN+5
#define CMD_ALT_RULE            CMD_MIN+6
#define CMD_RULE_STATE          CMD_MIN+7
 
#define CMD_MAX		0x6100//十进制：24832
 
#define MYFW_ICMP   1  //IPPROTO_ICMP
#define MYFW_TCP    6  //IPPROTO_TCP
#define MYFW_UDP    17 //IPPROTO_UDP

#define MATCH 1
#define NMATCH 0

typedef struct{
    int wday;   //0-6

    int s_hour;
    int s_min;
    int e_hour;
    int e_min;

    int date;    //1-31

}Control_Time;
 
typedef struct{
    int id;
    int block;
    unsigned int sip;//信息来源ip地址
    unsigned int dip;//信息目的ip地址
    unsigned short sport;//信息的发出端口
    unsigned short dport;//发送信息的目的端口
    unsigned short protocol;//使用的协议
    Control_Time controlled_time;
}Rule;

typedef struct{
    unsigned int sip;
    unsigned int dip;
    unsigned int sport;
    unsigned int dport;
    unsigned int protocol;
    unsigned int ct_date;
    unsigned int ct_wday;
    unsigned int ct_stime;
    unsigned int ct_etime;
}Rule_Mark_Bit;

typedef struct{
    int id;
    Rule rule;
    Rule_Mark_Bit mark_bit;
}Rule_with_tag;

typedef struct
{
    int rule_id;
    int blocked;
}RuleStat;

 
typedef struct{
    unsigned int count;//表示规则的个数
    Rule rule;//保存规则
}RuleTable;