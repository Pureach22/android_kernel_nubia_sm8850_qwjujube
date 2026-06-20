__int64 __fastcall wlan_is_nan_allowed_on_freq(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v10; // x8
  __int64 v12; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  void *v22; // x0
  __int64 v23; // x21
  unsigned __int64 v24; // x9
  _DWORD *v25; // x8
  char v26; // w20
  bool v27; // cf
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // [xsp+0h] [xbp-10h] BYREF
  __int64 v54; // [xsp+8h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v53) = 1;
  LOBYTE(v53) = 0;
  if ( !a1 || (v10 = *(__int64 **)(a1 + 1232)) == nullptr || (v12 = *v10) == 0 )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Invalid WMI handle",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_is_nan_allowed_on_freq",
      v53,
      v54);
    goto LABEL_15;
  }
  wlan_mlme_get_support_for_nan_dfs_channel(*(_QWORD *)(a1 + 80), &v53);
  if ( !wlan_reg_is_6ghz_chan_freq(a2) )
  {
    if ( (wlan_reg_is_etsi_srd_chan_for_freq(a1, a2, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
      wlan_mlme_get_srd_master_mode_for_vdev(*(_QWORD *)(a1 + 80), 0x10u, (bool *)&v53 + 4);
    if ( (wlan_reg_is_dfs_for_freq(a1, a2, v29, v30, v31, v32, v33, v34, v35, v36) & 1) != 0 )
    {
      if ( (unsigned __int8)v53 == 1
        && (wmi_service_enabled(v12, 0x149u, v37, v38, v39, v40, v41, v42, v43, v44) & 1) != 0 )
      {
        v26 = 1;
        goto LABEL_16;
      }
      goto LABEL_15;
    }
    if ( (wlan_reg_is_freq_indoor() & 1) != 0 )
    {
      wlan_mlme_get_indoor_support_for_nan(*(_QWORD *)(a1 + 80), (_BYTE *)&v53 + 4);
    }
    else if ( (wlan_reg_is_passive_for_freq(a1, a2, v45, v46, v47, v48, v49, v50, v51, v52) & 1) != 0 )
    {
      goto LABEL_15;
    }
    v26 = BYTE4(v53);
    goto LABEL_16;
  }
  v22 = (void *)_qdf_mem_malloc(0x870u, "wlan_is_nan_allowed_on_6ghz_freq", 449);
  if ( !v22 )
  {
LABEL_15:
    v26 = 0;
    goto LABEL_16;
  }
  v23 = (__int64)v22;
  wlan_reg_get_6g_ap_master_chan_list(a1, 2u, v22);
  v24 = 0;
  v25 = (_DWORD *)(v23 + 8);
  v26 = 1;
  do
  {
    if ( *(v25 - 2) == a2 && *v25 == 3 )
      break;
    v27 = v24++ >= 0x3B;
    v25 += 9;
    v26 = !v27;
  }
  while ( v24 != 60 );
  _qdf_mem_free(v23);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v26 & 1;
}
