__int64 __fastcall dp_mon_feature_ops_deregister(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  __int64 v11; // x8
  _QWORD *v12; // x8

  if ( !result )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: mon_ops is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_mon_feature_ops_deregister",
             v9,
             v10);
  v11 = *(_QWORD *)(result + 20112);
  if ( !v11 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: mon_ops is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_mon_feature_ops_deregister",
             v9,
             v10);
  v12 = *(_QWORD **)(v11 + 416);
  if ( !v12 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: mon_ops is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_mon_feature_ops_deregister",
             v9,
             v10);
  v12[24] = 0;
  v12[36] = 0;
  v12[37] = 0;
  v12[47] = 0;
  v12[48] = 0;
  v12[49] = 0;
  v12[53] = 0;
  v12[54] = 0;
  v12[55] = 0;
  v12[56] = 0;
  v12[57] = 0;
  v12[58] = 0;
  v12[59] = 0;
  v12[60] = 0;
  v12[69] = 0;
  v12[70] = 0;
  v12[80] = 0;
  v12[79] = 0;
  v12[78] = 0;
  v12[77] = 0;
  v12[76] = 0;
  v12[75] = 0;
  v12[111] = 0;
  v12[110] = 0;
  v12[109] = 0;
  v12[108] = 0;
  v12[107] = 0;
  v12[106] = 0;
  v12[105] = 0;
  return result;
}
