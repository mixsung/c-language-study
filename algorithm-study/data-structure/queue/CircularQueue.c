#include "CircularQueue.h"

void CQ_CreateQueue(CircularQueue **Queue, int Capacity) {
  (*Queue) = (CircularQueue *)malloc(sizeof(CircularQueue));

  // 입력된 Capacity + 1 만큼의 노드를 자유저장소에 생성
  (*Queue)->Nodes = (Node *)malloc(sizeof(Node) * (Capacity + 1));

  (*Queue)->Capacity = Capacity;
  (*Queue)->Front = 0;
  (*Queue)->Rear = 0;
}

void CQ_DestroyQueue(CircularQueue *Queue) {
  free(Queue->Nodes);
  free(Queue);
}

// 노드 삽입 연산
void CQ_Enqueue(CircularQueue *Queue, ElementType Data) {
  int Position = 0;

  if (Queue->Rear ==
      Queue->Capacity) // Queue->Capacity => dummy => 배열의 끝에 도달했다는 뜻
  {
    Position = Queue->Rear;
    Queue->Rear = 0;
  } else {
    Position = Queue->Rear++;
  }
  Queue->Nodes[Position].Data = Data;
}

// 노드 제거 연산
ElementType CQ_Dequeue(CircularQueue *Queue) {
  int Position = Queue->Front; // queue는 앞에서부터 제거하니까

  if (Queue->Front == Queue->Capacity) // 전단이 배열의 끝에 도달했을 때
    Queue->Front = 0;                  // Front를 인덱스 맨 앞으로
  else
    Queue->Front++;

  return (Queue->Nodes[Position].Data);
}

// 공백 상태 확인
int CQ_IsEmpty(CircularQueue *Queue)
{
  return (Queue->Front == Queue->Rear);
}

// 포화 상태 확인
int CQ_IsFull(CircularQueue *Queue) {
  // 1. 전단이 후단 앞에 있을 때, 후단과 전단의 차가 큐의 용량과 동일할 때
  if (Queue->Front < Queue->Rear)
    return ((Queue->Rear - Queue->Front) == Queue->Capacity);
  else // 2. 전단이 후단과 같은 위치 또는 뒤에 있고 후단에 1을 더한 값이 전단과
       // 동일
    return ((Queue->Rear + 1) == Queue->Front);
}

// 큐의 모든 요소 출력
// void  display(CircularQueue *Queue)
// {
  
// }

// 큐가 비어있지 않으면 맨 앞 요소를 삭제하지 않고 반환
ElementType peek(CircularQueue *Queue)
{
  if (!CQ_IsEmpty(Queue))
    return (Queue->Nodes[Queue->Front].Data);
  else
    return (NULL); // 앞단에서 이거 받아서 에러 처리 필요 (ex. if (!peek(Queue)))
}

int CQ_GetSize(CircularQueue *Queue) {
  if (Queue->Front <= Queue->Rear)
    return (Queue->Rear - Queue->Front);
  else
    return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
}

/*
      CQ_GetSize의 else return 시각 설명

[0][1][2][3][4][5][6][7][8]
| |  |  |  |10|20|30|40|  | -> 후단
            전단       |->실제후단

[0][1][2][3][4][5][6][7][8]       // '50' 삽입
| |  |  |  |10|20|30|40|50|
후단         전단          |-> 실제후단

* 실제후단이 배열 끝에 도달하면, Queue->Rear는 0이 된다.
* else에서 후단 뒤에 전단이 있다는 것은, 전단부터 배열 끝(Capacity값)까지부터
사이즈를 측정해야하는 것

*/
