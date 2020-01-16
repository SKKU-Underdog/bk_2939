# 택배 배달
   
시간 제한 |	메모리 제한
---|---
2초 |	256MB
  
## 문제
상근이는 데이트 비용을 마련하기 위해 빠름택배에서 택배를 배달하는 직업을 가졌다.  
매일 빠름택배에 출근하면, 상근이는 그날 배달해야 하는 위치가 적힌 종이를 받는다. 또, 이 위치에 적혀져있는 순서대로 배달해야 한다.  
도시는 R*C칸으로 나누어져 있다. 각 행은 1번부터 R번까지 번호가 매겨져 있고, 열도 1번부터 C번까지 번호가 매겨져 있다.  
상근이는 각 칸에서, 왼쪽 또는 오른쪽으로 이동할 수 있다. 하지만, 위나 아래로 이동하려면 꼭 첫 번째나 마지막 열(1과 C)로 가야 한다.  
빠름택배는 가장 왼쪽 위 칸인 (1,1)에 있다. 이곳이 상근이가 배달을 시작하는 곳이다. 상근이는 출발할 때 모든 물품을 들고 출발하고, 자신의 오토바이를 이용하여 배달하기 때문에, 배달하는 중 또는 배달을 마치고 다시 빠름택배로 돌아오지 않는다.  
각 칸을 통과하는데 드는 시간이 주어진다. 이때, 모든 택배를 배달하는데 걸리는 최소 시간을 계산하는 프로그램을성하시오.  
  
## 입력
첫째 줄에 도시의 크기 R과 C가 주어진다. (1 ≤ R ≤ 2000, 1 ≤ C ≤ 200)  
다음 R개 줄에는, 각 칸을 통과하는데 드는 시간이 주어진다. 이 시간은 0보다 크거나 같고, 5000보다 작거나 같은 자연수이다.  
다음 줄에는 배달해야 하는 물품의 수 D (1 ≤ D ≤ 200000)가 주어진다. 다음 D개 줄에는 물품을 배달해야 하는 곳의 위치의 좌표가 배달해야 하는 순서대로 주어진다. 같은 곳이 여러 번 주어질 수는 있다. 하지만, 연속해서 같은 곳을 배달해야 하는 경우는 없다.   
  
## 출력
모든 택배를 배달하는데 가장 빠른 시간을 출력한다.

## Input
3 3  
1 8 2  
2 3 2  
1 0 1  
3  
1 3  
3 3  
2 2  
  
## Output
17  
