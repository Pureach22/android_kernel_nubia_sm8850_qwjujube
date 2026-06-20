__int64 __fastcall lim_assoc_failure_timer_handler(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  __int64 v11; // x21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w10
  __int64 result; // x0
  __int64 v22; // [xsp+8h] [xbp-38h] BYREF
  __int64 v23; // [xsp+10h] [xbp-30h]
  __int64 v24; // [xsp+18h] [xbp-28h]
  __int64 v25; // [xsp+20h] [xbp-20h]
  __int64 v26; // [xsp+28h] [xbp-18h]
  __int64 v27; // [xsp+30h] [xbp-10h]
  __int64 v28; // [xsp+38h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  if ( a2 != 1 || (v10 = *(_QWORD *)(a1 + 12376)) == 0 || *(_DWORD *)(v10 + 72) != 28 )
  {
LABEL_8:
    HIDWORD(v22) = a2;
    LOWORD(v22) = 5077;
    v23 = 0;
    result = lim_post_msg_api(a1, (unsigned __int16 *)&v22);
    goto LABEL_9;
  }
  v11 = a1;
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Reassoc timeout happened",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_assoc_failure_timer_handler");
  v20 = *(unsigned __int8 *)(v11 + 12384);
  if ( v20 > 1 )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Reassoc request retry MAX: %d reached",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "lim_assoc_failure_timer_handler",
      2);
    a1 = v11;
    a2 = 1;
    if ( *(_QWORD *)(v10 + 136) )
    {
      _qdf_mem_free(*(_QWORD *)(v10 + 136));
      a2 = 1;
      a1 = v11;
      *(_QWORD *)(v10 + 136) = 0;
    }
    goto LABEL_8;
  }
  *(_BYTE *)(v11 + 12384) = v20 + 1;
  result = qdf_trace_msg(
             0x35u,
             3u,
             "%s: Reassoc request retry is sent %d times",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "lim_assoc_failure_timer_handler");
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
