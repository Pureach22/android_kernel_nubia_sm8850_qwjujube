__int64 __fastcall wlansap_set_chan_params_for_csa(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        int a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v18; // x0
  __int64 sap_ch_sw_info; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _DWORD *v28; // x21
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int v37; // w8
  unsigned int v38; // w8
  __int64 result; // x0
  unsigned int v40; // [xsp+8h] [xbp-18h] BYREF
  __int64 v41; // [xsp+Ch] [xbp-14h]
  int v42; // [xsp+14h] [xbp-Ch]
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = *(_QWORD *)(a2 + 16);
  v41 = 0;
  sap_ch_sw_info = wlan_get_sap_ch_sw_info(v18, a6, a7, a8, a9, a10, a11, a12, a13);
  if ( sap_ch_sw_info )
  {
    v28 = (_DWORD *)sap_ch_sw_info;
    v40 = a5;
    v42 = a4;
    *(_DWORD *)(sap_ch_sw_info + 16) = wlansap_get_csa_chanwidth_from_phymode(
                                         a2,
                                         a3,
                                         (__int64)&v40,
                                         v20,
                                         v21,
                                         v22,
                                         v23,
                                         v24,
                                         v25,
                                         v26,
                                         v27);
    qdf_mem_set(v28 + 5, 0x10u, 0);
    *v28 = a3;
    v37 = v42;
    v28[5] = v28[4];
    v28[8] = v37;
    if ( a5 != 9 )
    {
      qdf_trace_msg(0x39u, 8u, "SAP CSA: target bw:%d new width:%d", v29, v30, v31, v32, v33, v34, v35, v36, a5);
      v38 = v28[5];
      if ( v38 >= a5 )
        v38 = a5;
      v28[4] = v38;
      v28[5] = v38;
    }
    wlan_reg_set_channel_params_for_pwrmode(
      *(_QWORD *)(a1 + 21560),
      a3,
      0,
      (__int64)(v28 + 5),
      0,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36);
    wlan_reg_set_input_punc_bitmap();
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid channel info",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlansap_set_chan_params_for_csa");
    result = 5;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
