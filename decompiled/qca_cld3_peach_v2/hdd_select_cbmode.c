__int64 __fastcall hdd_select_cbmode(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 *v12; // x22
  unsigned int v17; // w2
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  __int64 v27; // x22
  unsigned __int8 *v28; // x8
  int v29; // w21
  __int64 v30; // x0
  unsigned int v31; // w0
  __int64 v32; // x4
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  v12 = *(__int64 **)(a1 + 24);
  if ( *a4 == 1 && wlan_reg_is_24ghz_ch_freq(a2) )
  {
    v17 = a3;
    if ( !a3 )
    {
      if ( a2 - 2412 > 0x14 )
      {
        if ( a2 - 2437 >= 0x24 )
          v17 = 0;
        else
          v17 = a2 - 20;
      }
      else
      {
        v17 = a2 + 20;
      }
    }
  }
  else
  {
    v17 = 0;
  }
  wlan_reg_set_channel_params_for_pwrmode(v12[1], a2, v17, (__int64)a4, 0, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( (unsigned int)cds_get_conparam() == 4 || (result = policy_mgr_is_sta_mon_concurrency(*v12), (result & 1) != 0) )
  {
    v27 = *(_QWORD *)(a1 + 52832);
    v28 = *(unsigned __int8 **)(*(_QWORD *)(a1 + 24) + 104LL);
    v29 = *v28;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Dot11Mode is %u",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "hdd_mon_select_cbmode",
      *v28);
    if ( v29 <= 7 )
    {
      if ( v29 )
      {
        v30 = 4;
        if ( v29 == 4 || v29 == 6 )
          goto LABEL_26;
        goto LABEL_18;
      }
    }
    else
    {
      if ( (unsigned int)v29 > 0xE )
      {
LABEL_18:
        v30 = (unsigned int)v29;
LABEL_26:
        *(_DWORD *)(v27 + 84) = *a4;
        v31 = hdd_cfg_xlate_to_csr_phy_mode(v30);
        *(_DWORD *)(v27 + 80) = a2;
        v32 = *(unsigned int *)(v27 + 84);
        *(_DWORD *)(v27 + 92) = v31;
        *(_BYTE *)(v27 + 88) = *a4;
        return qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: ch_info width %d, phymode %d channel freq %d",
                 v33,
                 v34,
                 v35,
                 v36,
                 v37,
                 v38,
                 v39,
                 v40,
                 "hdd_mon_select_cbmode",
                 v32,
                 v31,
                 a2);
      }
      if ( ((1 << v29) & 0x300) != 0 )
      {
LABEL_23:
        if ( (sme_is_feature_supported_by_fw(2) & 1) != 0 )
          v30 = 9;
        else
          v30 = 4;
        goto LABEL_26;
      }
      if ( ((1 << v29) & 0x1800) != 0 )
      {
LABEL_21:
        if ( (sme_is_feature_supported_by_fw(13) & 1) != 0 )
        {
          v30 = 12;
          goto LABEL_26;
        }
        goto LABEL_23;
      }
      if ( ((1 << v29) & 0x6000) == 0 )
        goto LABEL_18;
    }
    if ( (sme_is_feature_supported_by_fw(14) & 1) != 0 )
    {
      v30 = 13;
      goto LABEL_26;
    }
    goto LABEL_21;
  }
  return result;
}
