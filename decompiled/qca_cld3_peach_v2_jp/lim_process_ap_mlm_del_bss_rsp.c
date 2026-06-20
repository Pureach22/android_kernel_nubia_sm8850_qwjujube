__int64 __fastcall lim_process_ap_mlm_del_bss_rsp(
        __int64 a1,
        _DWORD *a2,
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
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x2
  __int64 result; // x0

  if ( a3 )
  {
    if ( a2 )
    {
      *(_DWORD *)(a1 + 4020) = 1;
      qdf_trace(53, 0, 255, 1);
      if ( *(_DWORD *)(a3 + 72) == 17 )
      {
        if ( *a2 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: BSS: DEL_BSS_RSP error (%x)",
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            "lim_process_ap_mlm_del_bss_rsp");
          v22 = 533;
        }
        else
        {
          dph_hash_table_init(a1, a3 + 360);
          lim_delete_pre_auth_list(a1);
          v22 = 0;
          *(_WORD *)(a3 + 7250) = 0;
        }
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Received unexpected WMA_DEL_BSS_RSP in state %X",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "lim_process_ap_mlm_del_bss_rsp");
        v22 = 506;
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: BSS: DEL_BSS_RSP with no body!",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "lim_process_ap_mlm_del_bss_rsp");
      v22 = 506;
    }
    lim_send_stop_bss_response(a1, *(unsigned __int8 *)(a3 + 10), v22);
    return pe_delete_session(a1);
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Session entry passed is NULL",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_process_ap_mlm_del_bss_rsp");
    if ( a2 )
      return _qdf_mem_free((__int64)a2);
  }
  return result;
}
