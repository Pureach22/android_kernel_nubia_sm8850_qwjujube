__int64 __fastcall policy_mgr_is_chan_eligible_for_sap(__int64 *a1, __int64 a2, unsigned int a3)
{
  __int64 v5; // x0
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  int channel_state_for_pwrmode; // w22
  double best_6g_power_type; // d0
  __int64 v18; // x8
  unsigned int v19; // w0
  unsigned int v20; // w21
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  char is_6ghz_psc_chan_freq; // w0
  unsigned int *v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v47; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v48; // [xsp+8h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a1;
  v47 = 0;
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v5, a2, 24);
  if ( v6 )
  {
    v15 = v6;
    channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                  a1[1],
                                  a3,
                                  0,
                                  v7,
                                  v8,
                                  v9,
                                  v10,
                                  v11,
                                  v12,
                                  v13,
                                  v14);
    best_6g_power_type = mlme_get_best_6g_power_type(v15);
    v18 = a1[1];
    v20 = v19;
    wlan_reg_get_cur_6g_ap_pwr_type(v18, &v47, best_6g_power_type, v21, v22, v23, v24, v25, v26, v27);
    is_6ghz_psc_chan_freq = wlan_reg_is_6ghz_psc_chan_freq(a3, v28, v29, v30, v31, v32, v33, v34, v35);
    LOBYTE(a3) = 0;
    if ( (is_6ghz_psc_chan_freq & 1) != 0 )
    {
      LOBYTE(a3) = 0;
      v37 = (unsigned int *)(v47 & 0xFFFFFFFE);
      if ( (_DWORD)v37 == 2 && channel_state_for_pwrmode == 3 && v20 <= 3 )
      {
        v37 = (unsigned int *)(v20 & 0xF);
        a3 = 0xDu >> (v20 & 0xF);
      }
    }
    wlan_objmgr_vdev_release_ref(v15, 0x18u, v37, v38, v39, v40, v41, v42, v43, v44, v45);
  }
  else
  {
    LOBYTE(a3) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return a3 & 1;
}
