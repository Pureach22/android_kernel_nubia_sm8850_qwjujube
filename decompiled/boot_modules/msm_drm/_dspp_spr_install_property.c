__int64 __fastcall dspp_spr_install_property(__int64 *a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x8
  int v5; // w1
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x8
  unsigned int v9; // w20
  char s[8]; // [xsp+8h] [xbp-208h] BYREF
  __int64 v11; // [xsp+10h] [xbp-200h]
  __int64 v12; // [xsp+18h] [xbp-1F8h]
  __int64 v13; // [xsp+20h] [xbp-1F0h]
  __int64 v14; // [xsp+28h] [xbp-1E8h]
  __int64 v15; // [xsp+30h] [xbp-1E0h]
  __int64 v16; // [xsp+38h] [xbp-1D8h]
  __int64 v17; // [xsp+40h] [xbp-1D0h]
  __int64 v18; // [xsp+48h] [xbp-1C8h]
  __int64 v19; // [xsp+50h] [xbp-1C0h]
  __int64 v20; // [xsp+58h] [xbp-1B8h]
  __int64 v21; // [xsp+60h] [xbp-1B0h]
  __int64 v22; // [xsp+68h] [xbp-1A8h]
  __int64 v23; // [xsp+70h] [xbp-1A0h]
  __int64 v24; // [xsp+78h] [xbp-198h]
  __int64 v25; // [xsp+80h] [xbp-190h]
  __int64 v26; // [xsp+88h] [xbp-188h]
  __int64 v27; // [xsp+90h] [xbp-180h]
  __int64 v28; // [xsp+98h] [xbp-178h]
  __int64 v29; // [xsp+A0h] [xbp-170h]
  __int64 v30; // [xsp+A8h] [xbp-168h]
  __int64 v31; // [xsp+B0h] [xbp-160h]
  __int64 v32; // [xsp+B8h] [xbp-158h]
  __int64 v33; // [xsp+C0h] [xbp-150h]
  __int64 v34; // [xsp+C8h] [xbp-148h]
  __int64 v35; // [xsp+D0h] [xbp-140h]
  __int64 v36; // [xsp+D8h] [xbp-138h]
  __int64 v37; // [xsp+E0h] [xbp-130h]
  __int64 v38; // [xsp+E8h] [xbp-128h]
  __int64 v39; // [xsp+F0h] [xbp-120h]
  __int64 v40; // [xsp+F8h] [xbp-118h]
  __int64 v41; // [xsp+100h] [xbp-110h]
  char v42[8]; // [xsp+108h] [xbp-108h] BYREF
  __int64 v43; // [xsp+110h] [xbp-100h]
  __int64 v44; // [xsp+118h] [xbp-F8h]
  __int64 v45; // [xsp+120h] [xbp-F0h]
  __int64 v46; // [xsp+128h] [xbp-E8h]
  __int64 v47; // [xsp+130h] [xbp-E0h]
  __int64 v48; // [xsp+138h] [xbp-D8h]
  __int64 v49; // [xsp+140h] [xbp-D0h]
  __int64 v50; // [xsp+148h] [xbp-C8h]
  __int64 v51; // [xsp+150h] [xbp-C0h]
  __int64 v52; // [xsp+158h] [xbp-B8h]
  __int64 v53; // [xsp+160h] [xbp-B0h]
  __int64 v54; // [xsp+168h] [xbp-A8h]
  __int64 v55; // [xsp+170h] [xbp-A0h]
  __int64 v56; // [xsp+178h] [xbp-98h]
  __int64 v57; // [xsp+180h] [xbp-90h]
  __int64 v58; // [xsp+188h] [xbp-88h]
  __int64 v59; // [xsp+190h] [xbp-80h]
  __int64 v60; // [xsp+198h] [xbp-78h]
  __int64 v61; // [xsp+1A0h] [xbp-70h]
  __int64 v62; // [xsp+1A8h] [xbp-68h]
  __int64 v63; // [xsp+1B0h] [xbp-60h]
  __int64 v64; // [xsp+1B8h] [xbp-58h]
  __int64 v65; // [xsp+1C0h] [xbp-50h]
  __int64 v66; // [xsp+1C8h] [xbp-48h]
  __int64 v67; // [xsp+1D0h] [xbp-40h]
  __int64 v68; // [xsp+1D8h] [xbp-38h]
  __int64 v69; // [xsp+1E0h] [xbp-30h]
  __int64 v70; // [xsp+1E8h] [xbp-28h]
  __int64 v71; // [xsp+1F0h] [xbp-20h]
  __int64 v72; // [xsp+1F8h] [xbp-18h]
  __int64 v73; // [xsp+200h] [xbp-10h]
  __int64 v74; // [xsp+208h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *a1;
  v40 = 0;
  v41 = 0;
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
  v2 = *(_QWORD *)(v1 + 56);
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  *(_QWORD *)s = 0;
  v11 = 0;
  v3 = *(_QWORD *)(v2 + 8);
  if ( !v3 )
  {
    result = _drm_err("!kms = %d\n ", 1);
    goto LABEL_12;
  }
  v5 = HIWORD(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 152) + 8216LL) + 428LL));
  if ( v5 == 1 )
  {
    snprintf(s, 0x100u, "%s%d", "SDE_SPR_INIT_CFG_V", 1);
    goto LABEL_7;
  }
  if ( v5 == 2 )
  {
    snprintf(s, 0x100u, "%s%d", "SDE_SPR_UDC_CFG_V", 2);
    sde_cp_crtc_install_blob_property(a1, s, 36, 3144);
    snprintf(s, 0x100u, "%s%d", "SDE_SPR_INIT_CFG_V", 2);
LABEL_7:
    sde_cp_crtc_install_blob_property(a1, s, 35, 304);
    goto LABEL_9;
  }
  _drm_err("version %d not supported\n", v5);
LABEL_9:
  v7 = *a1;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v8 = *(_QWORD *)(v7 + 56);
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  *(_QWORD *)v42 = 0;
  v43 = 0;
  v9 = HIWORD(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 8) + 152LL) + 8216LL) + 464LL));
  snprintf(v42, 0x100u, "%s%d", "SDE_DSPP_SPR_DITHER_V", v9);
  if ( v9 - 1 > 1 )
    result = _drm_err("version %d not supported\n", v9);
  else
    result = sde_cp_crtc_install_blob_property(a1, v42, 37, 1120);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
