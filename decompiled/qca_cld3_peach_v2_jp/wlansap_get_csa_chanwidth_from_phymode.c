__int64 __fastcall wlansap_get_csa_chanwidth_from_phymode(
        __int64 a1,
        unsigned int a2,
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
  _QWORD *context; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w8
  unsigned __int16 v32; // w2
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int v41; // w8
  unsigned int v42; // w24
  unsigned int v43; // w23
  int v44; // w8
  bool is_5ghz_ch_freq; // w0
  unsigned int concurrent_bw; // w0
  unsigned int v47; // w8
  __int64 v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x8
  unsigned __int64 v58; // x9
  int v60; // [xsp+34h] [xbp-1Ch] BYREF
  __int64 v61; // [xsp+38h] [xbp-18h] BYREF
  unsigned __int64 v62; // [xsp+40h] [xbp-10h]
  __int64 v63; // [xsp+48h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61 = 0;
  v62 = 0;
  v60 = 0;
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( context )
  {
    if ( wlan_reg_is_24ghz_ch_freq(a2) )
    {
      if ( !*(_DWORD *)(a1 + 732) && wlan_reg_is_24ghz_ch_freq(a2) && *(_WORD *)(a1 + 1498) == 1 )
      {
        v31 = *(unsigned __int8 *)(a1 + 1504);
        if ( v31 == 3 )
        {
          v32 = a2 - 20;
          v31 = 1;
        }
        else if ( v31 == 1 )
        {
          v32 = a2 + 20;
        }
        else
        {
          v32 = 0;
          v31 = 1;
        }
      }
      else
      {
        v32 = 0;
        v31 = 0;
      }
      v43 = 0;
      LODWORD(v61) = v31;
      if ( !a3 )
        goto LABEL_40;
      goto LABEL_38;
    }
    wlan_mlme_get_channel_bonding_5ghz(context[2694], &v60);
    if ( !policy_mgr_is_vdev_ll_lt_sap(context[2694], *(unsigned __int8 *)(a1 + 12))
      && (!wlan_reg_is_5ghz_ch_freq(a2) || v60) )
    {
      if ( a1 )
      {
        v41 = *(_DWORD *)(a1 + 1484);
        if ( v41 <= 511 )
        {
          v42 = 1;
          if ( v41 == 16 || v41 == 64 )
            goto LABEL_24;
          if ( v41 != 256 )
            goto LABEL_23;
LABEL_46:
          if ( (unsigned int)sme_get_vht_ch_width() < 2 )
            v42 = 2;
          else
            v42 = 3;
          goto LABEL_24;
        }
        if ( v41 == 512 || v41 == 4096 || v41 == 2048 )
          goto LABEL_46;
      }
      else
      {
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: Invalid SAP pointer",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "wlansap_get_max_bw_by_phymode");
      }
    }
LABEL_23:
    v42 = 0;
LABEL_24:
    v44 = *(_DWORD *)(a1 + 732);
    if ( v44 != 2 && v44 != 4 )
    {
      is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(a2);
      if ( v42 == 3 && is_5ghz_ch_freq )
      {
        if ( *(unsigned __int16 *)(a1 + 1498) < 3u )
          v42 = 2;
        else
          v42 = 3;
      }
    }
    concurrent_bw = wlan_sap_get_concurrent_bw(context[2695], context[2694], a2, v42);
    v43 = concurrent_bw;
    v32 = 0;
    if ( v42 >= concurrent_bw )
      v47 = concurrent_bw;
    else
      v47 = v42;
    if ( !a3 )
    {
      LODWORD(v61) = v47;
LABEL_40:
      wlan_reg_set_channel_params_for_pwrmode(
        context[2695],
        a2,
        v32,
        (__int64)&v61,
        0,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30);
      LODWORD(context) = v61;
      LODWORD(v57) = 0;
      LODWORD(v58) = 0;
      goto LABEL_41;
    }
    if ( v47 >= *(_DWORD *)a3 )
      v47 = *(_DWORD *)a3;
    LODWORD(v61) = v47;
LABEL_38:
    v48 = context[2695];
    HIDWORD(v62) = *(_DWORD *)(a3 + 12);
    wlan_reg_set_channel_params_for_pwrmode(v48, a2, v32, (__int64)&v61, 0, v23, v24, v25, v26, v27, v28, v29, v30);
    v57 = v62;
    LODWORD(context) = v61;
    v58 = HIDWORD(v62);
    *(_QWORD *)a3 = v61;
    *(_QWORD *)(a3 + 8) = v57;
LABEL_41:
    qdf_trace_msg(
      0x39u,
      8u,
      "csa freq %d bw %d (phymode %d con bw %d tgt bw %d orig %d reason %d) channel bonding 5g %d ccfs0 %d ccfs1 %d",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      a2,
      (unsigned int)context,
      *(unsigned int *)(a1 + 1484),
      v43,
      *(unsigned __int16 *)(a1 + 1498),
      *(_DWORD *)(a1 + 732),
      v60,
      v57,
      v58);
    goto LABEL_42;
  }
  qdf_trace_msg(
    0x39u,
    2u,
    "%s: Invalid MAC context",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "wlansap_get_csa_chanwidth_from_phymode");
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)context;
}
