__int64 __fastcall dspp_demura_install_property(__int64 *a1)
{
  __int64 v2; // x8
  __int64 v3; // x8
  int v4; // w20
  char *v5; // x1
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v8; // [xsp+10h] [xbp-100h]
  __int64 v9; // [xsp+18h] [xbp-F8h]
  __int64 v10; // [xsp+20h] [xbp-F0h]
  __int64 v11; // [xsp+28h] [xbp-E8h]
  __int64 v12; // [xsp+30h] [xbp-E0h]
  __int64 v13; // [xsp+38h] [xbp-D8h]
  __int64 v14; // [xsp+40h] [xbp-D0h]
  __int64 v15; // [xsp+48h] [xbp-C8h]
  __int64 v16; // [xsp+50h] [xbp-C0h]
  __int64 v17; // [xsp+58h] [xbp-B8h]
  __int64 v18; // [xsp+60h] [xbp-B0h]
  __int64 v19; // [xsp+68h] [xbp-A8h]
  __int64 v20; // [xsp+70h] [xbp-A0h]
  __int64 v21; // [xsp+78h] [xbp-98h]
  __int64 v22; // [xsp+80h] [xbp-90h]
  __int64 v23; // [xsp+88h] [xbp-88h]
  __int64 v24; // [xsp+90h] [xbp-80h]
  __int64 v25; // [xsp+98h] [xbp-78h]
  __int64 v26; // [xsp+A0h] [xbp-70h]
  __int64 v27; // [xsp+A8h] [xbp-68h]
  __int64 v28; // [xsp+B0h] [xbp-60h]
  __int64 v29; // [xsp+B8h] [xbp-58h]
  __int64 v30; // [xsp+C0h] [xbp-50h]
  __int64 v31; // [xsp+C8h] [xbp-48h]
  __int64 v32; // [xsp+D0h] [xbp-40h]
  __int64 v33; // [xsp+D8h] [xbp-38h]
  __int64 v34; // [xsp+E0h] [xbp-30h]
  __int64 v35; // [xsp+E8h] [xbp-28h]
  __int64 v36; // [xsp+F0h] [xbp-20h]
  __int64 v37; // [xsp+F8h] [xbp-18h]
  __int64 v38; // [xsp+100h] [xbp-10h]
  __int64 v39; // [xsp+108h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v3 = *(_QWORD *)(v2 + 56);
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  *(_QWORD *)s = 0;
  v8 = 0;
  v4 = HIWORD(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 8) + 152LL) + 8216LL) + 580LL));
  snprintf(s, 0x100u, "%s%d", "SDE_DEMURA_INIT_CFG_V", v4);
  if ( (unsigned int)(v4 - 3) < 2 )
  {
    v5 = s;
  }
  else
  {
    if ( (unsigned int)(v4 - 1) > 1 )
    {
      result = _drm_err("version %d not supported\n", v4);
      goto LABEL_6;
    }
    v5 = "SDE_DEMURA_INIT_CFG_V1";
  }
  sde_cp_crtc_install_blob_property(a1, v5, 38, 8568);
  sde_cp_crtc_install_range_property(a1, "SDE_DEMURA_BACKLIGHT_V1", 39, 0, 0xFFFFFFFFLL, 0);
  sde_cp_crtc_install_bitmask_property(a1, "SDE_DEMURA_BOOT_PLANE_V1", 40, 1, &sde_demura_fetch_planes, 4, 15);
  result = sde_cp_crtc_install_blob_property(a1, "SDE_DEMURA_CFG0_PARAM2", 41, 6152);
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
