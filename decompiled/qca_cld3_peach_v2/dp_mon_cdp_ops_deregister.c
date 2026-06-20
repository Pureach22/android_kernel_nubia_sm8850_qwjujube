_QWORD **__fastcall dp_mon_cdp_ops_deregister(
        _QWORD **result,
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
  _QWORD *v11; // x8
  __int64 v12; // x9

  v11 = *result;
  if ( !*result )
    return (_QWORD **)qdf_trace_msg(
                        0x92u,
                        2u,
                        "%s: cdp_ops is NULL",
                        a2,
                        a3,
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        "dp_mon_cdp_ops_deregister",
                        v9,
                        v10);
  v12 = *v11;
  v11[3] = 0;
  *(_QWORD *)(v12 + 168) = 0;
  *(_QWORD *)(*v11 + 376LL) = 0;
  *(_QWORD *)(v11[8] + 152LL) = 0;
  *(_QWORD *)(v11[8] + 160LL) = 0;
  *(_QWORD *)(v11[8] + 168LL) = 0;
  *(_QWORD *)(v11[1] + 160LL) = 0;
  *(_QWORD *)(v11[1] + 128LL) = 0;
  return result;
}
