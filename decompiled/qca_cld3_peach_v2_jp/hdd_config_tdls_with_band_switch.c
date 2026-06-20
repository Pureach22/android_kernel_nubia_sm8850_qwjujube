__int64 __fastcall hdd_config_tdls_with_band_switch(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *v10; // x2
  unsigned int v11; // w1
  __int64 result; // x0
  __int64 v13; // x0
  char v14; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // [xsp+0h] [xbp-10h] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  HIDWORD(v33) = 0;
  LOBYTE(v33) = 0;
  if ( !a1 )
  {
    v10 = "%s: Invalid hdd_ctx";
    goto LABEL_5;
  }
  if ( (unsigned int)ucfg_reg_get_band(a1[1], (_DWORD *)&v33 + 1, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    v10 = "%s: Failed to get current band config";
LABEL_5:
    v11 = 2;
LABEL_6:
    result = qdf_trace_msg(
               0x33u,
               v11,
               v10,
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "hdd_config_tdls_with_band_switch",
               v33,
               v34);
    goto LABEL_7;
  }
  v13 = *a1;
  if ( (~HIDWORD(v33) & 3) == 0 )
  {
    if ( (unsigned int)cfg_tdls_get_off_channel_enable_orig(v13, &v33, a2, a3, a4, a5, a6, a7, a8, a9) )
    {
      v10 = "%s: cfg get tdls off ch orig failed";
      goto LABEL_5;
    }
    if ( (v33 & 1) != 0 )
    {
      cfg_tdls_restore_off_channel_enable(*a1, a2, a3, a4, a5, a6, a7, a8, a9);
      v14 = 1;
      goto LABEL_17;
    }
    v10 = "%s: tdls off ch orig is false, do nothing";
LABEL_21:
    v11 = 8;
    goto LABEL_6;
  }
  if ( (unsigned int)cfg_tdls_get_off_channel_enable(v13, &v33, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    v10 = "%s: cfg get tdls off ch failed";
    goto LABEL_5;
  }
  if ( (v33 & 1) == 0 )
  {
    v10 = "%s: tdls off ch is false, do nothing";
    goto LABEL_21;
  }
  cfg_tdls_store_off_channel_enable(*a1, a2, a3, a4, a5, a6, a7, a8, a9);
  cfg_tdls_set_off_channel_enable(*a1, 0, v15, v16, v17, v18, v19, v20, v21, v22);
  v14 = 2;
LABEL_17:
  result = ucfg_get_tdls_vdev(*a1, 0x11u);
  if ( result )
  {
    v23 = result;
    ucfg_set_tdls_offchan_mode(result, v14);
    result = wlan_objmgr_vdev_release_ref(v23, 0x11u, v24, v25, v26, v27, v28, v29, v30, v31, v32);
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
