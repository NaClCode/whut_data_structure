#include "../../include/graph/cGraph.hpp"
#include <QDebug>
CGraph::CGraph(){
    init();
}

void CGraph::init(){
    for(int i = 0;i < N;i ++){
        for(int j = 0;j < N;j ++){
            this->adj_matrix[i][j] = -1;
        }
    }

    for(int i = 0;i < N;i++){
        this->vex_matrix[i].setVex(-1, "", "");
    }

    this->vex_num = 0;
}

bool CGraph::insertVex(Vex vex){
    if(this->vex_num >= N){
        return false;
    }else{
        this->vex_matrix[this->vex_num ++] = vex;
        return true;
    }
};
bool CGraph::insertEdge(Edge edge){
    if(edge.getVex1() < 0 || edge.getVex1() >= this->vex_num || edge.getVex2() < 0 || edge.getVex2() >= this->vex_num){
        return false;
    }else{
        this->adj_matrix[edge.getVex1()][edge.getVex2()] = edge.getWeight();
        this->adj_matrix[edge.getVex2()][edge.getVex1()] = edge.getWeight();
        return true;
    }

};

bool CGraph::getVex(int v, Vex& vew){
    if(v >= this->vex_num) return false;
    else{
        vew = this->vex_matrix[v];
        return true;
    }
};

int CGraph::findEdge(int v, Edge edges[]){
    int num = 0;
    for(int i = 0;i < this->vex_num;i ++){
        if(this->adj_matrix[v][i] != -1){
            edges[num++].setEdge(v, i, this->adj_matrix[v][i]);
        }
    }
    return num;
};

int CGraph::getVexNum(){
    return this->vex_num;
};

void CGraph::DFS(int nVex, bool Visited[], int& nIndex, vector<Path>& list, int path[]){
    Visited[nVex] = true;

    path[nIndex++] = nVex;

    if(nIndex == this->vex_num){
        Path p;

        for(int i = 0;i < nIndex;i ++){
            p.vexs[i] = path[i];
        }

        list.push_back(p);

        return ;


    }else{
        for(int i = 0;i < this->vex_num;i ++){
            if(this->adj_matrix[nVex][i] != -1 && !Visited[i]){
                DFS(i, Visited, nIndex, list, path);
                Visited[i] = false;
                nIndex--;
            }
        }
    }

};

void CGraph::DFSTraverse(int nVex,  vector<Path>& list){
    int nIndex = 0;
    bool bVisited[N] = {false};
    int path[N];
    DFS(nVex, bVisited, nIndex, list, path);
};

int CGraph::findShortPath(int start, int end, int path[]) {

    // 初始化
    const int MAX = 1e8;
    int visited[N];
    int dist[N];
    int parent[N];

    memset(dist, MAX, sizeof(dist));
    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    for(int i = 0; i < N; i++) {
        if(adj_matrix[start][i] != -1) dist[i] = adj_matrix[start][i];
        else dist[i] = MAX;
    }

    dist[start] = 0;
    visited[start] = true;

    for(int i = 0; i < N - 1; i++) {

        int indexMin = -1, min = MAX;
        for(int j = 0; j < N; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                indexMin = j;
            }
        }

        if(indexMin == -1) break; // 没有找到未访问的最小节点，结束循环

        visited[indexMin] = true;

        //更新节点
        for(int j = 0; j < N; j++) {
            if(!visited[j] && adj_matrix[indexMin][j] != -1 && dist[indexMin] + adj_matrix[indexMin][j] < dist[j]) {
                dist[j] = dist[indexMin] + adj_matrix[indexMin][j];
                parent[j] = indexMin; // 更新父节点
            }
        }
    }

    //父节点推算
    int j = 0;
    for(int i = end; i != -1;i = parent[i]){
        path[j ++] = i;
    }

    //反过来
    int temp = 0;
    path[j ++] = start;
    for(int i = 0;i < j / 2;i ++){
        temp = path[i];
        path[i] = path[j - i - 1];
        path[j - i - 1] = temp;
    }

    return dist[end]; // 返回最短路径长度
}


bool CGraph::findMinTree(Edge aPath[]) {
    int adjvex[N];
    int lowcost[N];
    const int MAX = 1e8;

    lowcost[0] = 0;
    adjvex[0] = 0;

    for (int i = 1; i < vex_num; i++) {
        if(adj_matrix[0][i] != -1){
            lowcost[i] = adj_matrix[0][i];
        }else{
            lowcost[i] = MAX;
        }

        adjvex[i] = 0;
    }

    for (int i = 1; i < vex_num; i++) {
        int minCost = MAX, minIndex = -1;

        for (int j = 0; j < vex_num; j++) {
            if (lowcost[j] < minCost && lowcost[j] != 0) {
                minCost = lowcost[j];
                minIndex = j;
            }
        }

        if(minIndex != -1){
            aPath[i - 1].setEdge(adjvex[minIndex], minIndex, minCost);
            lowcost[minIndex] = 0;
            for (int j = 0; j < vex_num; j++) {
                if (lowcost[j] != 0 && adj_matrix[minIndex][j] != -1 && adj_matrix[minIndex][j] < lowcost[j]) {
                    lowcost[j] = adj_matrix[minIndex][j];
                    adjvex[j] = minIndex;
                }
            }
        } else {
            return false;
        }
    }
    return true;
}


