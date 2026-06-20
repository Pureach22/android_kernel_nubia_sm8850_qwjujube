__int64 __fastcall dspp_ltm_install_property(__int64 *a1)
{
  __int64 v2; // x8
  __int64 v3; // x8
  int v4; // w9
  unsigned int v5; // w8
  unsigned int v6; // w20
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v9; // [xsp+10h] [xbp-100h]
  __int64 v10; // [xsp+18h] [xbp-F8h]
  __int64 v11; // [xsp+20h] [xbp-F0h]
  __int64 v12; // [xsp+28h] [xbp-E8h]
  __int64 v13; // [xsp+30h] [xbp-E0h]
  __int64 v14; // [xsp+38h] [xbp-D8h]
  __int64 v15; // [xsp+40h] [xbp-D0h]
  __int64 v16; // [xsp+48h] [xbp-C8h]
  __int64 v17; // [xsp+50h] [xbp-C0h]
  __int64 v18; // [xsp+58h] [xbp-B8h]
  __int64 v19; // [xsp+60h] [xbp-B0h]
  __int64 v20; // [xsp+68h] [xbp-A8h]
  __int64 v21; // [xsp+70h] [xbp-A0h]
  __int64 v22; // [xsp+78h] [xbp-98h]
  __int64 v23; // [xsp+80h] [xbp-90h]
  __int64 v24; // [xsp+88h] [xbp-88h]
  __int64 v25; // [xsp+90h] [xbp-80h]
  __int64 v26; // [xsp+98h] [xbp-78h]
  __int64 v27; // [xsp+A0h] [xbp-70h]
  __int64 v28; // [xsp+A8h] [xbp-68h]
  __int64 v29; // [xsp+B0h] [xbp-60h]
  __int64 v30; // [xsp+B8h] [xbp-58h]
  __int64 v31; // [xsp+C0h] [xbp-50h]
  __int64 v32; // [xsp+C8h] [xbp-48h]
  __int64 v33; // [xsp+D0h] [xbp-40h]
  __int64 v34; // [xsp+D8h] [xbp-38h]
  __int64 v35; // [xsp+E0h] [xbp-30h]
  __int64 v36; // [xsp+E8h] [xbp-28h]
  __int64 v37; // [xsp+F0h] [xbp-20h]
  __int64 v38; // [xsp+F8h] [xbp-18h]
  __int64 v39; // [xsp+100h] [xbp-10h]
  __int64 v40; // [xsp+108h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v3 = *(_QWORD *)(v2 + 56);
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  *(_QWORD *)s = 0;
  v9 = 0;
  LODWORD(v3) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 8) + 152LL) + 8216LL) + 392LL);
  v4 = v3 - 0x10000;
  v5 = WORD1(v3);
  if ( (unsigned int)(v4 - 3) >= 2 )
    v6 = v5;
  else
    v6 = 2;
  snprintf(s, 0x100u, "%s%d", "SDE_DSPP_LTM_V", v6);
  if ( v6 - 1 > 1 )
  {
    result = _drm_err("version %d not supported\n", v6);
  }
  else
  {
    sde_cp_crtc_install_immutable_property(a1, s, 23);
    sde_cp_crtc_install_range_property(a1, "SDE_DSPP_LTM_INIT_V1", 24, 0, -1, 0);
    sde_cp_create_local_blob(a1, 24, 16);
    sde_cp_crtc_install_range_property(a1, "SDE_DSPP_LTM_ROI_V1", 25, 0, -1, 0);
    sde_cp_create_local_blob(a1, 25, 24);
    sde_cp_crtc_install_enum_property(a1, 26, &sde_ltm_hist_modes, 2, "SDE_DSPP_LTM_HIST_CTRL_V1");
    sde_cp_crtc_install_range_property(a1, "SDE_DSPP_LTM_HIST_THRESH_V1", 27, 0, 1023, 0);
    sde_cp_crtc_install_range_property(a1, "SDE_DSPP_LTM_SET_BUF_V1", 28, 0, -1, 0);
    sde_cp_create_local_blob(a1, 28, 24);
    sde_cp_crtc_install_range_property(a1, "SDE_DSPP_LTM_QUEUE_BUF_V1", 29, 0, -1, 0);
    sde_cp_crtc_install_range_property(a1, "SDE_DSPP_LTM_QUEUE_BUF2_V1", 30, 0, -1, 0);
    sde_cp_crtc_install_range_property(a1, "SDE_DSPP_LTM_QUEUE_BUF3_V1", 31, 0, -1, 0);
    sde_cp_crtc_install_range_property(a1, "SDE_DSPP_LTM_VLUT_V1", 32, 0, -1, 0);
    result = sde_cp_create_local_blob(a1, 32, 4224);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
