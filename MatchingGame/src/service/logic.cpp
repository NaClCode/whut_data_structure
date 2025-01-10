#include "../../include/service/logic.h"
#include "../../include/model/cGraph.h"
#include "../../include/exception/gameException.h"
#include "QDebug"

GameLogic::GameLogic(CGraph* cgraph):cgraph(cgraph){
    avPath = new Point[MAXNUM];
    anPath = new int[MAXNUM];
    nVexNum = nCorner = 0;
};

void GameLogic::initMap(){

    int anTemp[MAXNUM];

    for (int i = 0; i < MAX_PIC_NUM; i++)
    {

        for (int j = 0; j < REPEAT_NUM; j++)
        {
            anTemp[i * REPEAT_NUM + j] = i;
        }
    }


    srand((int)time(NULL));

    for (int i = 0; i < 300; i++)
    {
        int nIndex1 = rand() % MAXNUM;
        int nIndex2 = rand() % MAXNUM;

        int nTemp = anTemp[nIndex1];
        anTemp[nIndex1] = anTemp[nIndex2];
        anTemp[nIndex2] = nTemp;
    }

    for (int i = 0; i < MAXNUM; i++)
    {
        cgraph->addVex(anTemp[i]);
    }

    for (int i = 0; i < MAX_ROW; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            updateArc(i, j);
        }
    }

};


void GameLogic::updateArc(int row, int col){
    int nV1Index = row * MAX_COL + col;
    if (col > 0) // 左边相邻
    {
        int nV2Index = nV1Index - 1;
        int nV1Info = cgraph->getVex(nV1Index);
        int nV2Info = cgraph->getVex(nV2Index);

        // 判断与左边相邻的是否有关系
        if (nV1Info == nV2Info || nV1Info == BLANK || nV2Info == BLANK)
        {
            cgraph->addArc(nV1Index, nV2Index);
        }
    }
    if (col < MAX_COL - 1) // 右边相邻
    {
        int nV2Index = nV1Index + 1;
        int nV1Info = cgraph->getVex(nV1Index);
        int nV2Info = cgraph->addVex(nV2Index);

        // 判断与右边相邻的是否有关系
        if (nV1Info == nV2Info || nV1Info == BLANK || nV2Info == BLANK)
        {
            cgraph->addArc(nV1Index, nV2Index);
        }
    }
    if (row > 0) // 正上方相邻
    {
        int nV2Index = nV1Index - MAX_COL;
        int nV1Info = cgraph->getVex(nV1Index);
        int nV2Info = cgraph->getVex(nV2Index);

        // 判断与正上方的是否有关系
        if (nV1Info == nV2Info || nV1Info == BLANK || nV2Info == BLANK)
        {
            cgraph->addArc(nV1Index, nV2Index);
        }
    }
    if (row < MAX_ROW - 1) // 正下方相邻
    {
        int nV2Index = nV1Index + MAX_COL;
        int nV1Info = cgraph->getVex(nV1Index);
        int nV2Info = cgraph->getVex(nV2Index);

        // 判断与正下方的是否有关系
        if (nV1Info == nV2Info || nV1Info == BLANK || nV2Info == BLANK)
        {
            cgraph->addArc(nV1Index, nV2Index);
        }
    }
}

bool GameLogic::isLink(Point p1, Point p2){
    int v1Index = p1.getX() * MAX_COL + p1.getY();
    int v2Index = p2.getX() * MAX_COL + p2.getY();

    pushVex(v1Index);
    //qDebug() << searchPath(v1Index, v2Index);
    if(searchPath(v1Index, v2Index)){
        return true;
    }

    popVex();
    return false;
};

void GameLogic::clear(Point p1, Point p2){
    int v1Index = p1.getX() * MAX_COL + p1.getY();
    int v2Index = p2.getX() * MAX_COL + p2.getY();

    this->cgraph->updateVex(v1Index, BLANK);
    this->cgraph->updateVex(v2Index, BLANK);

    updateArc(p1.getX(), p1.getY());
    updateArc(p2.getX(), p2.getY());

};

bool GameLogic::searchPath(int v1Index, int v2Index){

    for(int i = 0;i < cgraph->getVexnum();i ++){

        if(cgraph->getArc(v1Index, i) && !isExist(i)){
            pushVex(i);

            if(nCorner > 2) {
                popVex();
                continue;
            }

            if(i != v2Index){
                if(cgraph->getVex(i) != BLANK){
                    popVex();
                    continue;
                }

                if(searchPath(i, v2Index)){
                    return true;
                }
            }else return true;
            popVex();
        }
    }
    return false;
};

bool GameLogic::isExist(int viIndex){
    for(int i = 0;i < nVexNum;i ++){
        if(anPath[i] == viIndex) return true;
    }
    return false;
};

bool GameLogic::isCornor(){

    if (nVexNum >= 3)
    {
        if ((anPath[nVexNum - 1] + anPath[nVexNum - 3]) / 2 != anPath[nVexNum - 2])
        {
            return true;
        }
    }
    return false;
};

int GameLogic::getVexPath(QVector<Point>& avPath){

    for(int k = 0;k < nVexNum;k ++){
        for(int i = 0;i < MAX_COL;i ++){
            for (int j = 0;j < MAX_ROW;j++){
                if(j * MAX_COL + i == anPath[k]){
                    Point p(i, j, -1);
                    avPath.append(p);
                }
            }
        }
    }

    return nVexNum;
};

bool GameLogic::isBlank(){
    for(int i = 0;i < cgraph->getVexnum();i ++){
        if(cgraph->getVex(i) != BLANK) return false;
    }
    return true;
};

bool GameLogic::searchValidPath(){
    for(int i = 0;i < cgraph->getVexnum();i ++){
        if(cgraph->getVex(i) == BLANK) continue;

        for(int j = 0;j < cgraph->getVexnum();j ++){
            if(i != j){
                if(cgraph->getVex(i) == cgraph->getVex(j)){
                    pushVex(i);
                    if(searchPath(i, j) == true){
                        qDebug() << i << j;
                        return true;
                    }
                    popVex();
                }
            }
        }
    }
    return false;

};

void GameLogic::resetGraph(){

    for (int i = 0; i < MAX_PIC_NUM; i++)
    {

        for (int j = 0; j < REPEAT_NUM; j++)
        {
            this->cgraph->updateVex(i * REPEAT_NUM + j , i);
        }
    }

    for(int i = 0;i < 200;i++){
        int nIndex1 = rand() % MAXNUM;
        int nIndex2 = rand() % MAXNUM;
        //交换两个数值
        cgraph->changeVex(nIndex1, nIndex2);
    }
    //更新弧信息
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            updateArc(i, j);
        }
    }

};

CGraph* GameLogic::getMap(){
    return this->cgraph;
};

// 添加一个路径顶点
void GameLogic::pushVex(int nV)
{
    // 将顶点压栈
    anPath[nVexNum] = nV;
    nVexNum++;

    // 判断是否形成新的拐点
    if (isCornor())
    {
        nCorner++;
    }
}

// 取出一个路径顶点
void GameLogic::popVex()
{
    // 判断是否形成拐点，如果存在拐点，在取出之前减少拐点数
    if (isCornor())
    {
        nCorner--;
    }
    nVexNum--;
}

void GameLogic::clearStack(){
    nCorner = nVexNum = 0;
}

// //row -> x
// //col -> y
// GameLogic::GameLogic(CGraph* cgraph):cgraph(cGraph){
//     this->vexnum = 0;
// };

// bool GameLogic::isLink(Point p1, Point p2){
//     pushVex(p1);

//     if(p1.getX() == p2.getX() && p1.getY() == p2.getY()) return false;
//     if(p1.getValue() != p2.getValue()) return false;
//     if(p1.getX() == p2.getX()){
//         return linkInRow(p1, p2);
//     }

//     if(p1.getY() == p2.getY()){
//         return linkInCol(p1, p2);
//     }

//     if(oneCornerLink(p1, p2)) return true;
//     if(twoCornerLink(p1, p2)) return true;
//     popVex();
//     return false;
// };

// void GameLogic::clear(Point p1, Point p2){
//     map->setBlank(p1.getX(), p1.getY());
//     map->setBlank(p2.getX(), p2.getY());
//     clearStack();
// };

// int GameLogic::getVexPath(Point* avPath){
//     for(int i = 0;i < vexnum;i ++){
//         avPath[i] = this->avPath[i];
//     }
//     return vexnum;
// };

// bool GameLogic::linkInRow(Point p1, Point p2){
//     int col1 = p1.getY();
//     int col2 = p2.getY();
//     int row  = p1.getX();

//     return LineX(row, col1, col2);
// };

// bool GameLogic::linkInCol(Point p1, Point p2){
//     int row1 = p1.getX();
//     int row2 = p2.getX();
//     int col = p1.getY();

//     return LineY(row1, row2, col);
// };

// //row -> x
// //col -> y
// bool GameLogic::oneCornerLink(Point p1, Point p2){
//     if(map->getNum(p1.getX(), p2.getY()) == BLANK){
//         if(LineY(p1.getX(), p2.getX(), p2.getY()) && LineX(p1.getX(), p1.getY(), p2.getY())){
//             Point p = {p1.getX(), p2.getY(), -1};
//             pushVex(p);
//             return true;
//         }
//     }

//     if(map->getNum(p2.getX(), p1.getY()) == BLANK){
//         if(LineY(p1.getX(), p2.getX(), p2.getY()) && LineX(p2.getX(), p1.getY(), p2.getY())){
//             Point p = {p2.getX(), p1.getY(), -1};
//             pushVex(p);
//             return true;
//         }
//     }
//     return false;
// };

// bool GameLogic::LineY(int row1, int row2, int col){
//     if(row1 > row2){
//         int temp = row1;
//         row1 = row2;
//         row2 = temp;
//     }

//     for(int i = row1 + 1;i <= row2;i ++){
//         if(i == row2) return true;
//         if(this->map->getNum(i, col) != BLANK) break;
//     }

//     return false;
// };

// bool GameLogic::LineX(int row, int col1, int col2){
//     if(col1 > col2){
//         int temp = col1;
//         col1 = col2;
//         col2 = temp;
//     }

//     for(int i = col1 + 1;i <= col2;i ++){
//         if(i == col2) return true;
//         if(this->map->getNum(row, i) != BLANK) break;
//     }
//     return false;
// };

// //row -> x
// //col -> y
// bool GameLogic::twoCornerLink(Point p1, Point p2){
//     for(int col = 0;col < map->getCol();col++){
//         if(map->getNum(p1.getX(), col) == BLANK && map->getNum(p2.getX(), col) == BLANK){
//             if(LineY(p1.getX(), p2.getX(), col)){
//                 if(LineX(p1.getX(), p1.getY(), col) && LineX(p2.getX(), p2.getY(), col)){
//                     Point v1 = {p1.getX(), col, BLANK};
//                     Point v2 = {p2.getX(), col, BLANK};
//                     pushVex(v1);
//                     pushVex(v2);
//                     return true;
//                 }
//             }
//         }
//     }

//     for(int row = 0;row < map->getRow();row++){
//         if(map->getNum(row, p1.getY()) == BLANK && map->getNum(row, p2.getY()) == BLANK){
//             if(LineX(row, p1.getY(), p2.getY())){
//                 if(LineY(row, p1.getX(), p1.getY()) && LineY(row, p2.getX(), p2.getY())){
//                     Point v1 = {row, p1.getY(), BLANK};
//                     Point v2 = {row, p2.getY(), BLANK};
//                     pushVex(v1);
//                     pushVex(v2);
//                     return true;
//                 }
//             }
//         }
//     }

//     return false;
// };

// void GameLogic::pushVex(Point p){
//     this->avPath[this->vexnum++] = p;
// };

// void GameLogic::popVex(){
//     this->vexnum--;
// };

// void GameLogic::clearStack(){
//     this->vexNum = 0;
// };

// int GameLogic::getMapRow(){
//     return map->getRow();
// };

// int GameLogic::getMapCol(){
//     return map->getCol();
// };

// int GameLogic::getMapnPic(){
//     return map->getnPic();
// };

// int GameLogic::getMapNum(int row, int col){
//     if(row >= 0 && row < map->getRow() && col >= 0 && col < map->getCol())
//         return map->getNum(row, col);
//     else return -1;
// }

// int GameLogic::getVex(){
//     return vexnum;
// }

// int GameLogic::initMap(int row, int col , int nPic){
//     map->initMap(row, col , nPic);
// }
