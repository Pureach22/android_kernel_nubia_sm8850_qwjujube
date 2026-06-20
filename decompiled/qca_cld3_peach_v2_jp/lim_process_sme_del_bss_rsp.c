__int64 __fastcall lim_process_sme_del_bss_rsp(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x21
  int v13; // w8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  _QWORD v23[7]; // [xsp+8h] [xbp-38h] BYREF

  v12 = a1 + 0x2000;
  v23[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a1 + 8888) = "lim_process_sme_del_bss_rsp";
  *(_BYTE *)(a1 + 8885) = 1;
  qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", a3, a4, a5, a6, a7, a8, a9, a10);
  v13 = *(unsigned __int8 *)(v12 + 693);
  memset(v23, 0, 48);
  if ( v13 )
  {
    if ( *(_WORD *)(v12 + 496) )
    {
      LOWORD(v23[0]) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)v23) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to post lim msg:0x%x",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "lim_post_msg_to_process_deferred_queue",
          LOWORD(v23[0]));
    }
  }
  dph_hash_table_init(a1, a2 + 360);
  lim_delete_pre_auth_list(a1);
  result = lim_send_stop_bss_response(a1, *(unsigned __int8 *)(a2 + 10), 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
