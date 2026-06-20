__int64 __fastcall lim_handle_csa_offload_msg(
        _QWORD *a1,
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
  unsigned __int8 *v10; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  _BYTE v21[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int8 **)(a2 + 8);
  v21[0] = 0;
  if ( v10 )
  {
    if ( pe_find_session_by_bssid(a1, v10 + 24, v21) )
    {
      result = lim_handle_sta_csa_param(a1, v10, 1, v12, v13, v14, v15, v16, v17, v18, v19);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Session does not exists for %02x:%02x:%02x:**:**:%02x",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "lim_handle_csa_offload_msg",
        v10[24],
        v10[25],
        v10[26],
        v10[29]);
      result = _qdf_mem_free((__int64)v10);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: limMsgQ body ptr is NULL",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_handle_csa_offload_msg");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
