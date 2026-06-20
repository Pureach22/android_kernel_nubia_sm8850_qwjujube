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
  unsigned int v31; // w8
  unsigned int v32; // w23
  unsigned int v33; // w24
  unsigned int max_bw_by_phymode; // w24
  int v35; // w8
  bool is_5ghz_ch_freq; // w0
  unsigned int concurrent_bw; // w0
  int ap_oper_ch_width; // w24
  __int64 v39; // x24
  unsigned __int8 v40; // w1
  unsigned int scc_vdev_id; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w25
  int v51; // w8
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x7
  unsigned __int64 v61; // x8
  unsigned __int64 v62; // x9
  int v64; // [xsp+34h] [xbp-4Ch] BYREF
  __int64 v65; // [xsp+38h] [xbp-48h] BYREF
  unsigned __int64 v66; // [xsp+40h] [xbp-40h]
  __int64 v67; // [xsp+48h] [xbp-38h]
  _QWORD v68[2]; // [xsp+50h] [xbp-30h] BYREF
  __int64 v69; // [xsp+60h] [xbp-20h]
  __int64 v70; // [xsp+68h] [xbp-18h]
  __int64 v71; // [xsp+70h] [xbp-10h]
  __int64 v72; // [xsp+78h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v66 = 0;
  v67 = 0;
  v65 = 0;
  v64 = 0;
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
  {
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
    goto LABEL_50;
  }
  if ( wlan_reg_is_24ghz_ch_freq(a2) )
  {
    if ( !*(_DWORD *)(a1 + 732) && wlan_reg_is_24ghz_ch_freq(a2) && *(_WORD *)(a1 + 1498) == 1 )
    {
      v31 = *(unsigned __int8 *)(a1 + 1504);
      if ( v31 == 3 )
      {
        v32 = 0;
        v33 = a2 - 20;
        v31 = 1;
      }
      else if ( v31 == 1 )
      {
        v32 = 0;
        v33 = a2 + 20;
      }
      else
      {
        v33 = 0;
        v32 = 0;
        v31 = 1;
      }
    }
    else
    {
      v33 = 0;
      v31 = 0;
      v32 = 0;
    }
LABEL_39:
    LODWORD(v65) = v31;
    if ( a3 )
      goto LABEL_40;
    goto LABEL_42;
  }
  wlan_mlme_get_channel_bonding_5ghz(context[2703], &v64);
  if ( policy_mgr_is_vdev_ll_lt_sap(context[2703], *(unsigned __int8 *)(a1 + 12))
    || wlan_reg_is_5ghz_ch_freq(a2) && !v64 )
  {
    max_bw_by_phymode = 0;
  }
  else
  {
    max_bw_by_phymode = wlansap_get_max_bw_by_phymode(a1);
  }
  v35 = *(_DWORD *)(a1 + 732);
  if ( v35 != 2 && v35 != 4 )
  {
    is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(a2);
    if ( max_bw_by_phymode >= 3 && is_5ghz_ch_freq && *(unsigned __int16 *)(a1 + 1498) < 3u )
      max_bw_by_phymode = 2;
  }
  concurrent_bw = wlan_sap_get_concurrent_bw(context[2704], context[2703], a2, max_bw_by_phymode);
  v32 = concurrent_bw;
  if ( max_bw_by_phymode >= concurrent_bw )
    v31 = concurrent_bw;
  else
    v31 = max_bw_by_phymode;
  if ( a3 && v31 >= *(_DWORD *)a3 )
    v31 = *(_DWORD *)a3;
  if ( v31 != 7 )
  {
    v33 = 0;
    goto LABEL_39;
  }
  ap_oper_ch_width = 7;
  if ( policy_mgr_is_conn_lead_to_bw_downgrade(context[2703], *(_BYTE *)(a1 + 12), a2, 7u) )
    ap_oper_ch_width = wlan_mlme_get_ap_oper_ch_width(*(_QWORD *)(a1 + 16), v23, v24, v25, v26, v27, v28, v29, v30);
  if ( a3 && ap_oper_ch_width == 7 )
  {
    v39 = context[2703];
    v40 = *(_BYTE *)(a1 + 12);
    v70 = 0;
    v71 = 0;
    v68[1] = 0;
    v69 = 0;
    v68[0] = 0;
    scc_vdev_id = policy_mgr_fetch_scc_vdev_id(v39, v40, a2);
    if ( !(unsigned int)wlan_get_chan_by_vdev_id(v39, scc_vdev_id, v68, v42, v43, v44, v45, v46, v47, v48, v49)
      && (_DWORD)v70 == 7
      && *(_DWORD *)(a3 + 12) != HIDWORD(v69) )
    {
      *(_DWORD *)(a3 + 12) = HIDWORD(v69);
    }
    v33 = 0;
    LODWORD(v65) = 7;
    goto LABEL_40;
  }
  LODWORD(v65) = ap_oper_ch_width;
  v33 = 0;
  if ( a3 )
  {
LABEL_40:
    v50 = 1;
    HIDWORD(v66) = *(_DWORD *)(a3 + 12);
    goto LABEL_43;
  }
LABEL_42:
  v50 = 0;
LABEL_43:
  v51 = *(_DWORD *)(a1 + 1484);
  if ( v51 == 0x4000 || v51 == 0x2000 )
    wlan_reg_set_create_punc_bitmap((__int64)&v65, 1);
  wlan_reg_set_channel_params_for_pwrmode(
    context[2704],
    a2,
    v33,
    (__int64)&v65,
    0,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30);
  LODWORD(context) = v65;
  if ( v50 )
  {
    v60 = v65;
    v61 = v66;
    *(_QWORD *)(a3 + 16) = v67;
    v62 = HIDWORD(v61);
    *(_QWORD *)a3 = v60;
    *(_QWORD *)(a3 + 8) = v61;
  }
  else
  {
    LODWORD(v61) = 0;
    LODWORD(v62) = 0;
    v60 = 9;
  }
  qdf_trace_msg(
    0x39u,
    8u,
    "csa freq %d bw %d (phymode %d con bw %d tgt bw %d orig %d reason %d) channel bonding 5g %d ccfs0 %d ccfs1 %d",
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    a2,
    (unsigned int)context,
    *(unsigned int *)(a1 + 1484),
    v32,
    v60,
    *(unsigned __int16 *)(a1 + 1498),
    *(_DWORD *)(a1 + 732),
    v64,
    v61,
    v62);
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)context;
}
