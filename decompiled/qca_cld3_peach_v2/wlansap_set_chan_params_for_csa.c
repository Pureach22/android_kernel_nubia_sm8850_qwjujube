__int64 __fastcall wlansap_set_chan_params_for_csa(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        int a4,
        unsigned int a5,
        __int16 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v20; // x0
  __int64 sap_ch_sw_info; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  _DWORD *v30; // x22
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  int v39; // w8
  unsigned int v40; // w8
  int v41; // w8
  __int64 result; // x0
  unsigned int v43; // [xsp+0h] [xbp-20h] BYREF
  __int64 v44; // [xsp+4h] [xbp-1Ch]
  __int64 v45; // [xsp+Ch] [xbp-14h]
  int v46; // [xsp+14h] [xbp-Ch]
  __int64 v47; // [xsp+18h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = *(_QWORD *)(a2 + 16);
  v46 = 0;
  v45 = 0;
  v44 = 0;
  sap_ch_sw_info = wlan_get_sap_ch_sw_info(v20, a7, a8, a9, a10, a11, a12, a13, a14);
  if ( sap_ch_sw_info )
  {
    v30 = (_DWORD *)sap_ch_sw_info;
    v43 = a5;
    LODWORD(v45) = a4;
    *(_DWORD *)(sap_ch_sw_info + 16) = wlansap_get_csa_chanwidth_from_phymode(
                                         a2,
                                         a3,
                                         (__int64)&v43,
                                         v22,
                                         v23,
                                         v24,
                                         v25,
                                         v26,
                                         v27,
                                         v28,
                                         v29);
    qdf_mem_set(v30 + 5, 0x18u, 0);
    *v30 = a3;
    v39 = v45;
    v30[5] = v30[4];
    v30[8] = v39;
    if ( a5 != 9 )
    {
      qdf_trace_msg(0x39u, 8u, "SAP CSA: target bw:%d new width:%d", v31, v32, v33, v34, v35, v36, v37, v38, a5);
      v40 = v30[5];
      if ( v40 >= a5 )
        v40 = a5;
      v30[4] = v40;
      v30[5] = v40;
    }
    v41 = *(_DWORD *)(a2 + 1484);
    if ( v41 == 0x4000 || v41 == 0x2000 )
      wlan_reg_set_create_punc_bitmap(a2 + 1500, 1);
    wlan_reg_set_channel_params_for_pwrmode(
      *(_QWORD *)(a1 + 21632),
      a3,
      0,
      (__int64)(v30 + 5),
      0,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38);
    wlan_reg_set_input_punc_bitmap((__int64)(v30 + 5), a6);
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid channel info",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wlansap_set_chan_params_for_csa");
    result = 5;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
