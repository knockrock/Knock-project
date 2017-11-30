#include <stdio.h>

typedef struct to_movie{
	char * title;
	char * same_title;
	struct to_movie * next;
}to_movie;
typedef struct to_director{
	char * director;
	char * same_director;
}to_director;
typedef struct to_actor{
	char * actor;
	char * same_actor;
	struct to_actor * next;
}to_actor;
typedef struct movie_node{
	int  serial_number;
	char * title;
	char * genre;
	to_director * director;
	char * year;
	char * runtime;
	to_actor * actors;
}m_node; //영화 정보 저장 구조체
typedef struct director_node{
	int serial_number;
	char *name;
	char sex;
	char *birth;
	to_movie * best_movies;
}d_node; //감독 정보 저장 구조체
typedef struct actor_node{
	int serial_number;
	char *name;
	char sex;
	char *birth;
	to_movie *best_movies;
}a_node; //배우 정보 저장 구조체
typedef struct movie_list{
	m_node * m_data;
	struct movie_list * next;
}movie;
typedef struct director_list{
	d_node *d_data;
	struct director_list * next;
}director;
typedef struct actor_list{
	a_node *a_data;
	struct actor_list * next;
}actor;
void link_actor(); //배우 리스트 연결
void movie_log(); // movie에 add 로그 기록
m_node * input_M_node(); // movie 노드 추가
void init_M_node(); // 처음 movie 노드 리스트에 연결
void link_M_node(); // 처음이 아닌 movie 노드 리스트에 연결
void check_m_node(); // movie 연결리스트에 중복인지 아닌지 확인
void link_title(); //영화 제목 리스트 연결
void director_log(); // director에 add 로그 기록
d_node * input_D_node(); //director 노드 추가
void init_D_node(); //처음 director 노드 리스트에 연결
void link_D_node(); // 처음이 아닌 director 노드 리스트에 연결
void check_d_node(); // director 연결리스트에 중복인지 아닌지 확인
void actor_log(); //actor에 add 로그 기록
a_node * input_A_node(); // actor 노드 추가
void init_A_node(); //처음 actor 노드 리스트에 연결
void link_A_node(); // 처음이 아닌 actor 노드 리스트에 연결
void check_a_node(); // actor 연결리스트에 중복인지 아닌지 확인
void m_save(); //movie 리스트 파일에 저장
void d_save(); //director 리스트 파일에 저장
void a_save(); //actor 리스트 파일에 저장
void welcome(); // 프로그램 시작
void prompt(); // 영화 관리 프로그램 기본 프롬프트
