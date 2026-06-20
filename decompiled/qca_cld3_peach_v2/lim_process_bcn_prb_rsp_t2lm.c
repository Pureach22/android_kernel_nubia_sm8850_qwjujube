__int64 __fastcall lim_process_bcn_prb_rsp_t2lm(
        __int64 a1,
        __int64 a2,
        char *a3,
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
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  __int64 v32; // x20

  if ( !a1 || !a2 || !a3 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: invalid input parameters",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "lim_process_bcn_prb_rsp_t2lm");
  result = wlan_mlme_get_t2lm_negotiation_supported(*(_QWORD *)(a1 + 21624));
  if ( (_DWORD)result )
  {
    v22 = *(_QWORD *)(a2 + 16);
    if ( v22 )
    {
      result = wlan_vdev_mlme_is_mlo_vdev(v22, v14, v15, v16, v17, v18, v19, v20, v21);
      if ( (result & 1) != 0 )
      {
        result = wlan_cm_is_vdev_connected(v22, v23, v24, v25, v26, v27, v28, v29, v30);
        if ( (result & 1) != 0 )
        {
          result = mlo_check_if_all_links_up(v22);
          if ( (result & 1) != 0 )
          {
            v31 = *(_QWORD *)(v22 + 1360);
            qdf_mem_copy((void *)(v31 + 2592), a3, 8u);
            return wlan_update_t2lm_mapping(v22, a3 + 5792, *(_QWORD *)(v31 + 2592));
          }
        }
      }
    }
  }
  else
  {
    v32 = jiffies;
    if ( lim_process_bcn_prb_rsp_t2lm___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: T2LM negotiation not supported",
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 "lim_process_bcn_prb_rsp_t2lm");
      lim_process_bcn_prb_rsp_t2lm___last_ticks = v32;
    }
  }
  return result;
}
