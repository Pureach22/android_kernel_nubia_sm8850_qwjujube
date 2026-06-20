__int64 __fastcall mlo_link_recfg_defer_rsp_handler(
        __int64 a1,
        _DWORD *a2,
        __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  __int64 v13; // x8
  unsigned __int64 v14; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int link_status; // w0
  unsigned int v25; // w8
  int v26; // w0
  unsigned int v27; // w8
  int v28; // w0
  unsigned int v29; // w8

  result = 4;
  if ( !a1 || !a2 || !a3 )
    return result;
  if ( (unsigned int)*(char *)(a1 + 3024) >= 7 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: unexpected curr_state_idx %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "mlo_link_recfg_get_curr_tran_req");
    goto LABEL_10;
  }
  v13 = a1 + 312LL * *(char *)(a1 + 3024);
  v14 = v13 + 840;
  if ( v13 == -840 )
  {
LABEL_10:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: curr tran ctx null",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "mlo_link_recfg_defer_rsp_handler");
    return 4;
  }
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 3288) == 21 && (unsigned int)qdf_mc_timer_stop(a1 + 3288) )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Failed to stop the Link Recfg rsp timer",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "mlo_link_recfg_defer_rsp_handler");
    return 16;
  }
  if ( *a2 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: RX response failure %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "mlo_link_recfg_defer_rsp_handler");
    return 4;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: RX response success, to defer proc it",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "mlo_link_recfg_defer_rsp_handler");
  if ( a1 + 3024 > v14 )
  {
    while ( *(_DWORD *)v14 != 5 )
    {
      if ( *(_BYTE *)(v14 + 128) )
      {
        link_status = mlo_link_recfg_find_link_status(*(unsigned __int8 *)(v14 + 9), a1 + 576);
        v25 = *(unsigned __int8 *)(v14 + 128);
        *(_DWORD *)(v14 + 28) = link_status;
        if ( v25 >= 2 )
        {
          v26 = mlo_link_recfg_find_link_status(*(unsigned __int8 *)(v14 + 49), a1 + 576);
          v27 = *(unsigned __int8 *)(v14 + 128);
          *(_DWORD *)(v14 + 68) = v26;
          if ( v27 >= 3 )
          {
            v28 = mlo_link_recfg_find_link_status(*(unsigned __int8 *)(v14 + 89), a1 + 576);
            v29 = *(unsigned __int8 *)(v14 + 128);
            *(_DWORD *)(v14 + 108) = v28;
            if ( v29 > 3 )
            {
              __break(0x5512u);
              return mlo_link_recfg_proc_defer_rsp_handler();
            }
          }
        }
      }
      v14 += 312LL;
      if ( v14 >= a1 + 3024 )
        break;
    }
  }
  mlo_link_recfg_tranistion_to_next_state(a1);
  return 6;
}
