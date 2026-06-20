__int64 __fastcall lim_process_mlm_del_bss_rsp(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x22
  int v15; // w8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  _QWORD v25[7]; // [xsp+8h] [xbp-38h] BYREF

  v14 = a1 + 0x2000;
  v25[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a1 + 8888) = "lim_process_mlm_del_bss_rsp";
  *(_BYTE *)(a1 + 8885) = 1;
  qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", a4, a5, a6, a7, a8, a9, a10, a11);
  v15 = *(unsigned __int8 *)(v14 + 693);
  memset(v25, 0, 48);
  if ( v15 )
  {
    if ( *(_WORD *)(v14 + 496) )
    {
      LOWORD(v25[0]) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)v25) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to post lim msg:0x%x",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "lim_post_msg_to_process_deferred_queue",
          LOWORD(v25[0]));
    }
  }
  *(_DWORD *)(a1 + 12512) = 0;
  if ( *(_DWORD *)(a3 + 88) == 1 && !*(_WORD *)(a3 + 248) )
    result = lim_process_ap_mlm_del_bss_rsp(a1, a2, a3);
  else
    result = lim_process_sta_mlm_del_bss_rsp(a1, a2, a3);
  _ReadStatusReg(SP_EL0);
  return result;
}
