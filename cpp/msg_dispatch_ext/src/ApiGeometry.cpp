#include "ApiGeometry.h"

ApiErrCode ApiGeometry::curveGetEdges(const curveGetEdgesReq req, curveGetEdgesRsp* rsp)
{
    //mock data
    rsp->numEdges = 3;
    rsp->edges =  new int[3];
    rsp->edges[0] = 1001;
    rsp->edges[1] = 1002;
    rsp->edges[2] = 1003;

    return 0;
}
