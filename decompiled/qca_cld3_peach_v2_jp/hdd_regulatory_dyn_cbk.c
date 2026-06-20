__int64 __fastcall hdd_regulatory_dyn_cbk(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        _WORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 *v12; // x8
  __int64 v13; // x19
  char coex_unsafe_chan_nb_user_prefer_for_sap; // w22
  char coex_unsafe_chan_reg_disable; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  __int16 v35; // [xsp+4h] [xbp-Ch] BYREF
  char v36; // [xsp+6h] [xbp-Ah]
  __int64 v37; // [xsp+8h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(__int64 **)(a2 + 24);
  v36 = 0;
  v35 = 0;
  if ( !v12 )
  {
    result = qdf_trace_msg(0x33u, 2u, "%s: pdev_priv null", a5, a6, a7, a8, a9, a10, a11, a12, "hdd_regulatory_dyn_cbk");
    goto LABEL_12;
  }
  v13 = *v12;
  if ( *v12 )
  {
    coex_unsafe_chan_nb_user_prefer_for_sap = ucfg_mlme_get_coex_unsafe_chan_nb_user_prefer_for_sap(*(_QWORD *)(v13 + 1536));
    coex_unsafe_chan_reg_disable = ucfg_mlme_get_coex_unsafe_chan_reg_disable(*(_QWORD *)(v13 + 1536));
    if ( a4 && (coex_unsafe_chan_nb_user_prefer_for_sap & 1) != 0 )
    {
      if ( (coex_unsafe_chan_reg_disable & 1) != 0 )
      {
LABEL_6:
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: process channel list update from regulatory",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "hdd_regulatory_dyn_cbk");
        hdd_regulatory_chanlist_dump(a3);
        fill_wiphy_band_channels(v13, a3, 0);
        fill_wiphy_band_channels(v13, a3, 1);
        v26 = fill_wiphy_band_channels(v13, a3, 3);
        ucfg_reg_get_cc_and_src(*(_QWORD *)(v13 + 1536), &v35, v26, v27, v28, v29, v30, v31, v32, v33);
        qdf_mem_copy((void *)(v13 + 2154), &v35, 3u);
        if ( *(_BYTE *)(v13 + 1304) == 1 )
          hdd_send_wiphy_regd_sync_event(v13 + 1536, 0);
        hdd_config_tdls_with_band_switch(v13 + 1536);
        result = queue_work_on(32, system_wq, v13 + 8320);
        goto LABEL_12;
      }
    }
    else if ( !a4 )
    {
      goto LABEL_6;
    }
    result = hdd_ch_avoid_ind(v13 + 1536, a4 + 340, a4, v18, v19, v20, v21, v22, v23, v24, v25);
LABEL_12:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x800u);
  return hdd_regulatory_chanlist_dump(a1);
}
