__int64 __fastcall hdd_reg_set_band(
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
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v46; // w0
  __int64 v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  const char *v64; // x2
  unsigned int v65; // w1
  int v66; // w0
  __int64 v67; // x8
  int v68; // w20
  int v69; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v70; // [xsp+8h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v69 = 0;
  if ( !a2 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: Can't disable all bands", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_reg_set_band");
    result = 4294967274LL;
    goto LABEL_17;
  }
  v12 = *(_QWORD *)(a1 + 2712);
  qdf_trace_msg(0x33u, 8u, "%s: change band to %u", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_reg_set_band", a2);
  if ( !(unsigned int)ucfg_reg_get_band(*(_QWORD *)(v12 + 8), &v69, v13, v14, v15, v16, v17, v18, v19, v20) )
  {
    if ( v69 == a2
      && (ucfg_reg_get_keep_6ghz_sta_cli_connection(*(_QWORD *)(v12 + 8), v21, v22, v23, v24, v25, v26, v27, v28) & 1) == 0 )
    {
      v64 = "%s: band is the same so not updating";
      v65 = 8;
    }
    else
    {
      if ( (hdd_is_chan_switch_in_progress(v21, v22, v23, v24, v25, v26, v27, v28) & 1) != 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: channel switch is in progress",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "hdd_reg_set_band");
        if ( (unsigned int)policy_mgr_wait_chan_switch_complete_evt(*(_QWORD *)v12) )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: qdf wait for csa event failed",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "hdd_reg_set_band");
          result = 16;
          goto LABEL_17;
        }
      }
      v46 = wlan_reg_band_bitmap_to_band_info(a2);
      v47 = *(_QWORD *)(v12 + 8);
      *(_DWORD *)(v12 + 3252) = v46;
      if ( (unsigned int)ucfg_reg_set_band(v47, a2, v48, v49, v50, v51, v52, v53, v54, v55) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to set the band bitmap value to %u",
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          "hdd_reg_set_band",
          a2);
        result = 4294967274LL;
        goto LABEL_17;
      }
      v66 = wlan_cm_set_roam_band_update(*(_QWORD *)v12, *(unsigned __int8 *)(*(_QWORD *)(a1 + 55520) + 8LL));
      v67 = *(_QWORD *)v12;
      v68 = v66;
      wlan_cm_set_roam_band_bitmask(v67, *(unsigned __int8 *)(*(_QWORD *)(a1 + 55520) + 8LL), a2);
      if ( !v68 )
      {
LABEL_16:
        result = 0;
        goto LABEL_17;
      }
      v64 = "%s: Failed to send RSO update to fw on set band";
      v65 = 2;
    }
    qdf_trace_msg(0x33u, v65, v64, v21, v22, v23, v24, v25, v26, v27, v28, "hdd_reg_set_band");
    goto LABEL_16;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Failed to get current band config",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "hdd_reg_set_band");
  result = 4294967291LL;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
