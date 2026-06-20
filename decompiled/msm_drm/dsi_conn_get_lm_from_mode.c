__int64 __fastcall dsi_conn_get_lm_from_mode(__int64 a1, __int64 a2)
{
  int v3; // w10
  unsigned int v5; // w8
  int v6; // w11
  unsigned int v7; // w9
  int v8; // w12
  int v9; // w9
  int v10; // w10
  unsigned int v11; // w9
  unsigned int v12; // w10
  int v13; // w8
  int v14; // w9
  int v15; // w0
  char v16; // w8
  unsigned int mode; // w0
  unsigned int v18; // w20
  __int64 v20; // [xsp+0h] [xbp-D0h] BYREF
  unsigned __int64 v21; // [xsp+8h] [xbp-C8h] BYREF
  __int128 v22; // [xsp+10h] [xbp-C0h]
  unsigned __int64 v23; // [xsp+20h] [xbp-B0h]
  __int128 v24; // [xsp+28h] [xbp-A8h]
  __int64 v25; // [xsp+38h] [xbp-98h]
  __int64 v26; // [xsp+40h] [xbp-90h]
  __int64 v27; // [xsp+48h] [xbp-88h]
  __int64 v28; // [xsp+50h] [xbp-80h]
  __int64 v29; // [xsp+58h] [xbp-78h]
  __int64 v30; // [xsp+60h] [xbp-70h]
  __int64 v31; // [xsp+68h] [xbp-68h]
  __int64 v32; // [xsp+70h] [xbp-60h]
  __int64 v33; // [xsp+78h] [xbp-58h]
  __int64 v34; // [xsp+80h] [xbp-50h]
  __int64 v35; // [xsp+88h] [xbp-48h]
  __int64 v36; // [xsp+90h] [xbp-40h]
  __int64 v37; // [xsp+98h] [xbp-38h]
  __int64 v38; // [xsp+A0h] [xbp-30h]
  __int64 v39; // [xsp+A8h] [xbp-28h]
  __int64 v40; // [xsp+B0h] [xbp-20h]
  __int64 v41; // [xsp+B8h] [xbp-18h]
  __int64 v42; // [xsp+C0h] [xbp-10h]
  __int64 v43; // [xsp+C8h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
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
  v24 = 0u;
  v23 = 0;
  v21 = 0;
  v22 = 0u;
  v20 = 0;
  if ( a1 && a2 )
  {
    v3 = *(unsigned __int16 *)(a2 + 8);
    v5 = *(unsigned __int16 *)(a2 + 4);
    v6 = *(unsigned __int16 *)(a2 + 6);
    v7 = *(unsigned __int16 *)(a2 + 10) - v3;
    v8 = *(unsigned __int16 *)(a2 + 18);
    *((_QWORD *)&v22 + 1) = 0;
    v23 = 0;
    v21 = __PAIR64__(v7, v5);
    v9 = v3 - v6;
    v10 = *(unsigned __int16 *)(a2 + 20);
    v41 = 0;
    v42 = 0;
    LODWORD(v22) = v9;
    *(_QWORD *)((char *)&v22 + 4) = v6 - v5;
    v11 = v10 - v8;
    v12 = *(unsigned __int16 *)(a2 + 14);
    v13 = *(unsigned __int16 *)(a2 + 12);
    v39 = 0;
    v40 = 0;
    v23 = __PAIR64__(v11, v12);
    v14 = *(unsigned __int16 *)(a2 + 16);
    DWORD2(v22) = v13;
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
    HIDWORD(v24) = 0;
    LODWORD(v24) = v8 - v14;
    *(_QWORD *)((char *)&v24 + 4) = v14 - v12;
    v15 = drm_mode_vrefresh(a2);
    v16 = *(_BYTE *)(a2 + 24);
    HIDWORD(v24) = v15;
    HIDWORD(v22) = v16 & 1;
    DWORD2(v24) = (v16 & 4) != 0;
    mode = dsi_display_find_mode(a1, &v21, 0, &v20);
    if ( mode )
    {
      v18 = mode;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: mode not found %d\n", mode);
      drm_mode_debug_printmodeline(a2);
    }
    else
    {
      v18 = *(_DWORD *)(*(_QWORD *)(v20 + 184) + 2480LL);
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params %d %d\n", a1 == 0, a2 == 0);
    v18 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v18;
}
