__int64 __fastcall dsi_conn_mode_valid(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // w10
  unsigned int v6; // w8
  int v7; // w11
  unsigned int v8; // w9
  int v9; // w12
  int v10; // w9
  int v11; // w10
  unsigned int v13; // w9
  unsigned int v14; // w10
  int v15; // w8
  int v16; // w9
  int v17; // w0
  unsigned int v18; // w8
  char v19; // w9
  int v20; // w10
  __int64 v21; // x8
  __int64 v22; // x9
  __int16 v23; // w10
  __int64 v24; // x11
  __int64 v25; // x9
  int v26; // w8
  int v27; // w9
  __int64 result; // x0
  __int64 v29; // [xsp+0h] [xbp-D0h] BYREF
  unsigned __int64 v30; // [xsp+8h] [xbp-C8h] BYREF
  __int128 v31; // [xsp+10h] [xbp-C0h]
  unsigned __int64 v32; // [xsp+20h] [xbp-B0h]
  __int128 v33; // [xsp+28h] [xbp-A8h]
  __int64 v34; // [xsp+38h] [xbp-98h]
  __int64 v35; // [xsp+40h] [xbp-90h]
  __int64 v36; // [xsp+48h] [xbp-88h]
  __int64 v37; // [xsp+50h] [xbp-80h]
  __int64 v38; // [xsp+58h] [xbp-78h]
  __int64 v39; // [xsp+60h] [xbp-70h]
  __int64 v40; // [xsp+68h] [xbp-68h]
  __int64 v41; // [xsp+70h] [xbp-60h]
  __int64 v42; // [xsp+78h] [xbp-58h]
  __int64 v43; // [xsp+80h] [xbp-50h]
  __int64 v44; // [xsp+88h] [xbp-48h]
  __int64 v45; // [xsp+90h] [xbp-40h]
  __int64 v46; // [xsp+98h] [xbp-38h]
  __int64 v47; // [xsp+A0h] [xbp-30h]
  __int64 v48; // [xsp+A8h] [xbp-28h]
  __int64 v49; // [xsp+B0h] [xbp-20h]
  __int64 v50; // [xsp+B8h] [xbp-18h]
  __int64 v51; // [xsp+C0h] [xbp-10h]
  __int64 v52; // [xsp+C8h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v33 = 0u;
  v32 = 0;
  v30 = 0;
  v31 = 0u;
  v29 = 0;
  if ( !a1 || !a2 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    result = 0xFFFFFFFFLL;
    goto LABEL_23;
  }
  v4 = *(unsigned __int16 *)(a2 + 8);
  v6 = *(unsigned __int16 *)(a2 + 4);
  v7 = *(unsigned __int16 *)(a2 + 6);
  v8 = *(unsigned __int16 *)(a2 + 10) - v4;
  v9 = *(unsigned __int16 *)(a2 + 18);
  *((_QWORD *)&v31 + 1) = 0;
  v32 = 0;
  v30 = __PAIR64__(v8, v6);
  v10 = v4 - v7;
  v11 = *(unsigned __int16 *)(a2 + 20);
  v50 = 0;
  v51 = 0;
  LODWORD(v31) = v10;
  *(_QWORD *)((char *)&v31 + 4) = v7 - v6;
  v13 = v11 - v9;
  v14 = *(unsigned __int16 *)(a2 + 14);
  v15 = *(unsigned __int16 *)(a2 + 12);
  v48 = 0;
  v49 = 0;
  v32 = __PAIR64__(v13, v14);
  v16 = *(unsigned __int16 *)(a2 + 16);
  DWORD2(v31) = v15;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  HIDWORD(v33) = 0;
  LODWORD(v33) = v9 - v16;
  *(_QWORD *)((char *)&v33 + 4) = v16 - v14;
  v17 = drm_mode_vrefresh(a2);
  v18 = *(unsigned __int8 *)(a2 + 24);
  HIDWORD(v33) = v17;
  v19 = v18 & 1;
  v20 = (v18 >> 2) & 1;
  v21 = *(_QWORD *)(a1 + 2512);
  BYTE12(v31) = v19;
  BYTE8(v33) = v20;
  if ( !v21 )
    goto LABEL_19;
  v22 = *(_QWORD *)(v21 + 3248);
  v51 = v22;
  if ( v22 )
  {
    v23 = *(_WORD *)(v22 + 3400);
    v38 = v22 + 2496;
    v39 = v22 + 2712;
    v24 = *(_QWORD *)(v22 + 3404);
    v25 = *(_QWORD *)(v22 + 2408);
    LOWORD(v37) = v23;
    v40 = v24;
    v34 = v25;
  }
  v26 = *(_DWORD *)(v21 + 3240);
  if ( (v26 & 0x20) != 0 )
  {
    v27 = 1;
    HIDWORD(v47) = 1;
  }
  else
  {
    v27 = 0;
  }
  if ( (~v26 & 0x21) != 0 )
  {
    if ( (v26 & 2) == 0 )
      goto LABEL_12;
  }
  else
  {
    v27 |= 2u;
    HIDWORD(v47) = v27;
    if ( (v26 & 2) == 0 )
    {
LABEL_12:
      if ( (v26 & 4) == 0 )
        goto LABEL_13;
      goto LABEL_26;
    }
  }
  v27 |= 4u;
  HIDWORD(v47) = v27;
  if ( (v26 & 4) == 0 )
  {
LABEL_13:
    if ( (v26 & 8) == 0 )
      goto LABEL_14;
    goto LABEL_27;
  }
LABEL_26:
  v27 |= 8u;
  HIDWORD(v47) = v27;
  if ( (v26 & 8) == 0 )
  {
LABEL_14:
    if ( (v26 & 0x40) == 0 )
      goto LABEL_15;
    goto LABEL_28;
  }
LABEL_27:
  v27 |= 0x10u;
  HIDWORD(v47) = v27;
  if ( (v26 & 0x40) == 0 )
  {
LABEL_15:
    if ( (v26 & 0x80) == 0 )
      goto LABEL_16;
LABEL_29:
    v27 |= 0x100u;
    HIDWORD(v47) = v27;
    if ( (v26 & 0x10) == 0 )
    {
LABEL_17:
      if ( (v26 & 0x100) == 0 )
        goto LABEL_19;
      goto LABEL_18;
    }
    goto LABEL_30;
  }
LABEL_28:
  v27 |= 0x80u;
  HIDWORD(v47) = v27;
  if ( (v26 & 0x80) != 0 )
    goto LABEL_29;
LABEL_16:
  if ( (v26 & 0x10) == 0 )
    goto LABEL_17;
LABEL_30:
  v27 |= 0x20u;
  HIDWORD(v47) = v27;
  if ( (v26 & 0x100) != 0 )
LABEL_18:
    HIDWORD(v47) = v27 | 0x200;
LABEL_19:
  if ( (unsigned int)dsi_display_find_mode(a3, &v30, 0, &v29) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: could not find mode %s\n", (const char *)(a2 + 80));
    result = 0xFFFFFFFFLL;
  }
  else
  {
    result = dsi_display_validate_mode(a3, v29, 1);
    if ( (_DWORD)result )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: mode not supported, rc=%d\n", result);
      result = 4294967294LL;
    }
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
