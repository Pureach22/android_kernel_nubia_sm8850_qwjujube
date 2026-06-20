__int64 __fastcall wma_vdev_set_bss_params(
        __int64 *a1,
        unsigned int a2,
        unsigned __int16 a3,
        unsigned __int8 a4,
        char a5,
        char a6,
        char a7)
{
  __int64 v13; // x25
  __int64 v14; // x0
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w8
  _DWORD *v34; // x9
  int v35; // w10
  unsigned int v36; // w19
  __int64 result; // x0
  __int64 v38; // x0
  unsigned int v39; // [xsp+8h] [xbp-38h] BYREF
  unsigned int v40; // [xsp+Ch] [xbp-34h] BYREF
  _DWORD v41[4]; // [xsp+10h] [xbp-30h] BYREF
  __int64 v42; // [xsp+20h] [xbp-20h]
  __int64 v43; // [xsp+28h] [xbp-18h]
  __int64 v44; // [xsp+30h] [xbp-10h]
  __int64 v45; // [xsp+38h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = a1[65] + 488LL * a2;
  v14 = *a1;
  v43 = 0;
  v44 = 0;
  v42 = 0;
  v40 = 0;
  v41[0] = 3;
  v41[1] = a3;
  v15 = wmi_unified_vdev_set_gtx_cfg_send(v14);
  if ( v15 )
  {
    v24 = "%s: failed to set vdev gtx cfg";
  }
  else
  {
    v41[2] = 13;
    v41[3] = a4;
    *(_BYTE *)(v13 + 178) = a4;
    if ( (wlan_reg_is_ext_tpc_supported(a1[3], v16, v17, v18, v19, v20, v21, v22, v23) & 1) != 0 )
    {
      v33 = 2;
    }
    else
    {
      if ( !a7 )
        qdf_trace_msg(
          0x36u,
          3u,
          "%s: Setting Tx power limit to 0",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "wma_vdev_set_bss_params");
      qdf_trace_msg(0x36u, 8u, "TXP[W][set_bss_params]: %d", v25, v26, v27, v28, v29, v30, v31, v32, (unsigned int)a7);
      LODWORD(v42) = 56;
      HIDWORD(v42) = a7;
      v33 = 3;
    }
    v34 = &v41[2 * v33];
    if ( a5 )
      v35 = 2;
    else
      v35 = 1;
    *v34 = 7;
    v34[1] = v35;
    v34[2] = 26;
    v34[3] = a6 != 0;
    v15 = wma_send_multi_pdev_vdev_set_params(1, a2, v41, (unsigned int)(v33 + 2));
    if ( !v15 )
    {
      v38 = *(_QWORD *)v13;
      v39 = 0;
      mlme_set_max_reg_power(v38, a7, v16, v17, v18, v19, v20, v21, v22, v23);
      wlan_mlme_get_sta_keep_alive_period(a1[3], (int *)&v40);
      wma_get_keep_sta_alive_method(a1[3], (int *)&v39);
      wma_set_sta_keep_alive(a1, a2, v39, v40, 0, 0, 0);
      result = 0;
      goto LABEL_14;
    }
    v24 = "%s: Failed to set BEACON/DTIM_PERIOD/PWRLIMIT/SLOTTIME/PROTECTION params";
  }
  v36 = v15;
  qdf_trace_msg(0x36u, 2u, v24, v16, v17, v18, v19, v20, v21, v22, v23, "wma_vdev_set_bss_params");
  result = v36;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
