__int64 __fastcall wlan_get_ll_lt_sap_restart_freq(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        int *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x22
  unsigned int v16; // w19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  int opmode_from_vdev_id; // w0
  unsigned int valid_freq; // w0
  __int64 v28; // x7
  unsigned int v29; // w21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  v12 = *(_QWORD *)(a1 + 80);
  v16 = a2;
  if ( wlan_reg_is_disable_in_secondary_list_for_freq(a1, a2, a5, a6, a7, a8, a9, a10, a11, a12)
    && (utils_dfs_is_freq_in_nol(a1, v16) & 1) == 0 )
  {
    v25 = 11;
    goto LABEL_10;
  }
  if ( (wlan_reg_is_passive_for_freq(a1, v16, v17, v18, v19, v20, v21, v22, v23, v24) & 1) != 0 )
  {
    v25 = 12;
LABEL_10:
    *a4 = v25;
    valid_freq = ll_lt_sap_get_valid_freq(v12, a3, 0, 0);
    v28 = (unsigned int)*a4;
    v29 = valid_freq;
    qdf_trace_msg(
      0xA1u,
      8u,
      "%s: vdev %d old freq %d restart freq %d CSA reason %d ",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_get_ll_lt_sap_restart_freq",
      (unsigned __int8)a3,
      v16,
      valid_freq,
      v28);
    return v29;
  }
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(a1, a3);
  if ( (policy_mgr_is_sap_freq_allowed(v12, opmode_from_vdev_id, v16) & 1) == 0 )
  {
    v25 = 6;
    goto LABEL_10;
  }
  if ( (_policy_mgr_is_ll_lt_sap_restart_required(v12, "wlan_get_ll_lt_sap_restart_freq") & 1) != 0 )
  {
    v25 = 5;
    goto LABEL_10;
  }
  return v16;
}
