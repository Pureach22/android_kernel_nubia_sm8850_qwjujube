__int64 __fastcall dspp_aiqe_install_property(__int64 *a1)
{
  __int64 v2; // x21
  __int64 v3; // x8
  unsigned int v4; // w20
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v7; // [xsp+10h] [xbp-100h]
  __int64 v8; // [xsp+18h] [xbp-F8h]
  __int64 v9; // [xsp+20h] [xbp-F0h]
  __int64 v10; // [xsp+28h] [xbp-E8h]
  __int64 v11; // [xsp+30h] [xbp-E0h]
  __int64 v12; // [xsp+38h] [xbp-D8h]
  __int64 v13; // [xsp+40h] [xbp-D0h]
  __int64 v14; // [xsp+48h] [xbp-C8h]
  __int64 v15; // [xsp+50h] [xbp-C0h]
  __int64 v16; // [xsp+58h] [xbp-B8h]
  __int64 v17; // [xsp+60h] [xbp-B0h]
  __int64 v18; // [xsp+68h] [xbp-A8h]
  __int64 v19; // [xsp+70h] [xbp-A0h]
  __int64 v20; // [xsp+78h] [xbp-98h]
  __int64 v21; // [xsp+80h] [xbp-90h]
  __int64 v22; // [xsp+88h] [xbp-88h]
  __int64 v23; // [xsp+90h] [xbp-80h]
  __int64 v24; // [xsp+98h] [xbp-78h]
  __int64 v25; // [xsp+A0h] [xbp-70h]
  __int64 v26; // [xsp+A8h] [xbp-68h]
  __int64 v27; // [xsp+B0h] [xbp-60h]
  __int64 v28; // [xsp+B8h] [xbp-58h]
  __int64 v29; // [xsp+C0h] [xbp-50h]
  __int64 v30; // [xsp+C8h] [xbp-48h]
  __int64 v31; // [xsp+D0h] [xbp-40h]
  __int64 v32; // [xsp+D8h] [xbp-38h]
  __int64 v33; // [xsp+E0h] [xbp-30h]
  __int64 v34; // [xsp+E8h] [xbp-28h]
  __int64 v35; // [xsp+F0h] [xbp-20h]
  __int64 v36; // [xsp+F8h] [xbp-18h]
  __int64 v37; // [xsp+100h] [xbp-10h]
  __int64 v38; // [xsp+108h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  v8 = 0;
  v9 = 0;
  *(_QWORD *)s = 0;
  v7 = 0;
  v2 = *(_QWORD *)(get_kms((__int64)a1) + 152);
  if ( (*(_BYTE *)(v2 + 20112) & 1) == 0 )
  {
    result = printk(&unk_269B57, 0);
    goto LABEL_15;
  }
  v3 = *(_QWORD *)(v2 + 8216);
  v4 = *(_DWORD *)(v3 + 612);
  if ( HIWORD(v4) - 1 <= 1u )
  {
    if ( *(_BYTE *)(v3 + 616) == 1 )
    {
      snprintf(s, 0x100u, "%s%d", "SDE_DSPP_AIQE_MDNIE_V", HIWORD(v4));
      sde_cp_crtc_install_range_property(a1, s, 0x2Au, 0, -1, 0);
      sde_cp_create_local_blob(a1, 42, 568);
      sde_cp_crtc_install_range_property(a1, "SDE_DSPP_AIQE_MDNIE_ART_V1", 0x2Bu, 0, -1, 0);
      sde_cp_create_local_blob(a1, 43, 16);
      sde_cp_crtc_install_range_property(a1, "SDE_DSPP_AIQE_MDNIE_IPC_V1", 0x2Cu, 0, 0xFFFFFFFFLL, 0);
      v3 = *(_QWORD *)(v2 + 8216);
    }
    if ( *(_BYTE *)(v3 + 618) == 1 )
    {
      sde_cp_crtc_install_blob_property(a1, "SDE_DSPP_AIQE_SSRC_CONFIG_V1", 0x2Du, 68);
      sde_cp_crtc_install_blob_property(a1, "SDE_DSPP_AIQE_SSRC_DATA_V1", 0x2Eu, 20516);
      v3 = *(_QWORD *)(v2 + 8216);
    }
    if ( *(_BYTE *)(v3 + 619) == 1 )
    {
      sde_cp_crtc_install_range_property(a1, "SDE_DSPP_AIQE_COPR_V1", 0x2Fu, 0, -1, 0);
      sde_cp_create_local_blob(a1, 47, 80);
      v3 = *(_QWORD *)(v2 + 8216);
    }
    if ( *(_BYTE *)(v3 + 617) == 1 )
    {
      sde_cp_crtc_install_range_property(a1, "SDE_DSPP_AIQE_ABC_V1", 0x31u, 0, -1, 0);
      sde_cp_create_local_blob(a1, 49, 192);
    }
    if ( a1 )
      goto LABEL_12;
LABEL_14:
    result = _drm_err("invalid sde_crtc %pK\n", nullptr);
    goto LABEL_15;
  }
  _drm_err("version %d not supported\n", v4);
  if ( !a1 )
    goto LABEL_14;
LABEL_12:
  result = aiqe_init(v4, a1 + 994);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
