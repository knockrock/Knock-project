#ifndef movie_manage_program_h
#define movie_manage_program_h

#include <stdio.h>

typedef struct movie_node m_node; //영화 정보 저장 구조체
typedef struct director_node d_node; //감독 정보 저장 구조체
typedef struct actor_node a_node; //배우 정보 저장 구조체

typedef struct to_movie{
	char * title;
	m_node * same_title;
	struct to_movie * next;
}to_movie;
typedef struct to_director{
	char * director;
	d_node * same_director;
	struct to_director * next;
}to_director;
typedef struct to_actor{
	char * actor;
	a_node * same_actor;
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
	m_node m_data;
	struct movie_list * next;
}movie;
typedef struct director_list{
	d_node d_data;
	struct director_list * next;
}director;
typedef struct actor_list{
	a_node a_data;
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
int m_t_compare();//title로 정렬
int m_g_compare();//genre로 정렬
int m_d_compare();//director로 정렬
int m_y_compare();//year로 정렬
int m_r_compare();//runtime으로 정렬
int m_a_compare();//actor로 정렬
void m_sort(); // movie 정렬
int d_n_compare();//name으로 정렬
int d_s_compare();//sex로 정렬
int d_b_compare();//birth로 정렬
int d_m_compare();//best_movies로 정렬
void d_sort(); //director 정렬
int a_n_compare();//name으로 정렬
int a_s_compare();//sex로 정렬
int a_b_compare();//birth로 정렬
int a_m_compare();//best_movies로 정렬
void a_sort(); // actor 정렬
movie * read_m_log(); // movie_log 읽어 링크드 리스트 생성
director * read_d_log(); //director_log 읽어 링크드 리스트 생성
actor * read_a_log(); // actor_log 읽어 링크드 리스트 생성
void prompt(); // 영화 관리 프로그램 기본 프롬프트
void m_update(); //movie 노드 업데이트
void d_update(); //director 노드 업데이트
void a_update(); //actor 노드 업데이트
void delete_m(); // movie 노드 삭제
void delete_d(); // director 노드 삭제
void delete_a(); // actor 노드 삭제
void print_d();  // director 노드 출력
void delete_log_d(); // director log파일 읽을 때 삭제
void delete_log_a(); // actor log파일 읽을 때 삭제
void delete_log_m(); // movie log파일 읽을 때 삭제
void cntrl_signal(); // 신호 처리 함수
void d_link();
void m_link();
void a_link();
void m_update_log();
void d_update_log();
void a_update_log();
#endif
