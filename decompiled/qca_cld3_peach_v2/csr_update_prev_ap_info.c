__int64 __fastcall csr_update_prev_ap_info(
        unsigned __int8 *a1,
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
  int v12; // w21
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 cmpt_obj; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _BYTE v31[43]; // [xsp+5h] [xbp-2Bh] BYREF

  *(_QWORD *)&v31[35] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_DWORD *)(a2 + 16);
  memset(v31, 0, 32);
  result = wlan_cm_get_rso_config_fl(a2, (__int64)"csr_update_prev_ap_info", 0x1484u, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result && *(_BYTE *)(result + 678) == 1 && !v12 )
  {
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a2, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( cmpt_obj && *(_BYTE *)(cmpt_obj + 178) )
    {
      qdf_mem_copy(v31, (const void *)(cmpt_obj + 145), *(unsigned __int8 *)(cmpt_obj + 178));
      a1[53] = 1;
      result = qdf_mc_timer_get_system_time();
      *((_DWORD *)a1 + 14) = result;
    }
    else
    {
      result = qdf_trace_msg(
                 0x34u,
                 2u,
                 "%s:  failed to find SSID for vdev %d",
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 "csr_update_prev_ap_info",
                 *a1);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
