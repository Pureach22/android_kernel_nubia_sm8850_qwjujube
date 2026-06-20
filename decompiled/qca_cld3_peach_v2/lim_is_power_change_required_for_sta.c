__int64 __fastcall lim_is_power_change_required_for_sta(
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
  __int64 v14; // x0
  unsigned int v15; // w1
  char channel_state_for_pwrmode; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 result; // x0
  unsigned int v50; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+8h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 21632);
  v15 = *(_DWORD *)(a3 + 284);
  v50 = 0;
  channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(v14, v15, 3u, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a3 + 16), v17, v18, v19, v20, v21, v22, v23, v24) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: vdev component object is NULL",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_is_power_change_required_for_sta");
LABEL_9:
    result = 0;
    goto LABEL_10;
  }
  if ( (wlan_is_scc_tpc_power_supp_enabled(*(_QWORD *)(a3 + 16), v25, v26, v27, v28, v29, v30, v31, v32) & 1) != 0 )
    goto LABEL_9;
  if ( *(_DWORD *)(a2 + 284) != *(_DWORD *)(a3 + 284) )
    goto LABEL_9;
  wlan_reg_get_cur_6g_ap_pwr_type(*(_QWORD *)(a1 + 21632), &v50, v33, v34, v35, v36, v37, v38, v39, v40);
  if ( *(_BYTE *)(a2 + 10069) )
    goto LABEL_9;
  result = 0;
  if ( (channel_state_for_pwrmode & 3) != 0 && v50 == 2 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Change the power type of STA from LPI to VLP",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "lim_is_power_change_required_for_sta");
    result = 1;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
