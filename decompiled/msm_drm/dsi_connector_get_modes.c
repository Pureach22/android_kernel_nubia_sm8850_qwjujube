__int64 __fastcall dsi_connector_get_modes(__int64 a1, __int64 a2)
{
  int v4; // w21
  int v5; // w22
  int mode_count; // w0
  int modes; // w0
  int v9; // w25
  unsigned int v10; // w24
  __int64 v11; // x0
  unsigned int *v12; // x8
  const char *v13; // x20
  unsigned int v14; // w0
  size_t v15; // x2
  unsigned int v16; // w10
  unsigned int v17; // w9
  __int64 v18; // x8
  __int64 v19; // x9
  unsigned int *v20; // x10
  unsigned int v21; // w1
  unsigned int v22; // w14
  unsigned int v23; // w15
  char *v24; // x12
  unsigned int v25; // w0
  unsigned int v26; // w17
  int v27; // w16
  unsigned int v28; // w13
  unsigned int v29; // w4
  unsigned int v30; // w1
  __int64 v31; // x10
  char v32; // w8
  char v33; // w9
  char *v34; // x11
  unsigned int *v35; // [xsp+0h] [xbp-110h] BYREF
  unsigned int v36; // [xsp+Ch] [xbp-104h] BYREF
  _QWORD v37[2]; // [xsp+10h] [xbp-100h] BYREF
  __int64 v38; // [xsp+20h] [xbp-F0h]
  __int64 v39; // [xsp+28h] [xbp-E8h]
  __int64 v40; // [xsp+30h] [xbp-E0h]
  __int64 v41; // [xsp+38h] [xbp-D8h]
  __int64 v42; // [xsp+40h] [xbp-D0h]
  __int64 v43; // [xsp+48h] [xbp-C8h]
  __int64 v44; // [xsp+50h] [xbp-C0h]
  __int64 v45; // [xsp+58h] [xbp-B8h]
  __int64 v46; // [xsp+60h] [xbp-B0h]
  __int64 v47; // [xsp+68h] [xbp-A8h]
  __int64 v48; // [xsp+70h] [xbp-A0h]
  __int64 v49; // [xsp+78h] [xbp-98h]
  __int64 v50; // [xsp+80h] [xbp-90h] BYREF
  __int64 v51; // [xsp+88h] [xbp-88h]
  __int64 v52; // [xsp+90h] [xbp-80h] BYREF
  __int64 v53; // [xsp+98h] [xbp-78h]
  __int64 v54; // [xsp+A0h] [xbp-70h]
  __int64 v55; // [xsp+A8h] [xbp-68h]
  __int64 v56; // [xsp+B0h] [xbp-60h]
  __int64 v57; // [xsp+B8h] [xbp-58h]
  __int64 v58; // [xsp+C0h] [xbp-50h]
  __int64 v59; // [xsp+C8h] [xbp-48h]
  __int64 v60; // [xsp+D0h] [xbp-40h]
  __int64 v61; // [xsp+D8h] [xbp-38h]
  __int64 v62; // [xsp+E0h] [xbp-30h]
  __int64 v63; // [xsp+E8h] [xbp-28h]
  __int64 v64; // [xsp+F0h] [xbp-20h]
  __int64 v65; // [xsp+F8h] [xbp-18h]
  __int64 v66; // [xsp+100h] [xbp-10h]
  __int64 v67; // [xsp+108h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37[0] = 0xFFFFFFFFFFFF00LL;
  v37[1] = 0x100016D44LL;
  v36 = 0;
  v42 = 0x10101010101LL;
  v43 = 0;
  v4 = *(_DWORD *)(a1 + 216);
  v5 = *(_DWORD *)(a1 + 220);
  v35 = nullptr;
  v38 = 0x780000800301101BLL;
  v39 = 0x27984757A0C90D0ALL;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v52 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v47 = 0;
  v48 = 0;
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v40 = 0x1010000004C4812LL;
  v41 = 0x101010101010101LL;
  mode_count = dsi_display_get_mode_count(a2, &v36);
  if ( mode_count )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get num of modes, rc=%d\n", mode_count);
    goto LABEL_6;
  }
  modes = dsi_display_get_modes(a2, &v35);
  if ( modes )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get modes, rc=%d\n", modes);
LABEL_5:
    v36 = 0;
    goto LABEL_6;
  }
  if ( v36 )
  {
    v9 = 0;
    while ( 1 )
    {
      v65 = 0;
      v66 = 0;
      v63 = 0;
      v64 = 0;
      v61 = 0;
      v62 = 0;
      v59 = 0;
      v60 = 0;
      v57 = 0;
      v58 = 0;
      v55 = 0;
      v56 = 0;
      v53 = 0;
      v54 = 0;
      v52 = 0;
      dsi_convert_to_drm_mode((int *)&v35[48 * v9], (__int64)&v52);
      v11 = drm_mode_duplicate(*(_QWORD *)a1, &v52);
      if ( !v11 )
      {
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to add mode %ux%u\n", WORD2(v52), HIWORD(v53));
        v36 = -12;
        goto LABEL_6;
      }
      *(_WORD *)(v11 + 58) = *(_DWORD *)(a1 + 216);
      *(_WORD *)(v11 + 60) = *(_DWORD *)(a1 + 220);
      v12 = &v35[48 * v9];
      if ( *(_DWORD *)(a2 + 1212) == -1 )
      {
        if ( v12[44] )
          goto LABEL_10;
      }
      else if ( (v12[43] & 1) == 0 )
      {
        goto LABEL_10;
      }
      *(_BYTE *)(v11 + 62) |= 8u;
LABEL_10:
      drm_mode_probed_add(a1, v11);
      v10 = v36;
      if ( ++v9 >= v36 )
        goto LABEL_18;
    }
  }
  v10 = 0;
LABEL_18:
  v13 = **(const char ***)(a2 + 264);
  if ( !v13 )
    goto LABEL_5;
  LOBYTE(v50) = 0;
  HIDWORD(v49) = -33554432;
  v14 = strlen(v13);
  if ( v14 >= 0xD )
    v15 = 13;
  else
    v15 = v14;
  memcpy((char *)&v50 + 1, v13, v15);
  v16 = *(_DWORD *)(a1 + 220);
  BYTE5(v38) = *(_DWORD *)(a1 + 216) / 0xAu;
  BYTE6(v38) = v16 / 0xA;
  if ( v10 )
  {
    if ( v10 >= 3 )
      v17 = 3;
    else
      v17 = v10;
    v18 = 0;
    v19 = 18LL * v17;
    v20 = v35;
    do
    {
      v21 = v20[7];
      v23 = v20[2];
      v22 = v20[3];
      v24 = (char *)v37 + v18;
      v18 += 18;
      v25 = v20[8];
      v26 = v20[9];
      v27 = v23 + v22 + v20[1];
      *((_WORD *)v24 + 27) = v20[38] / 0xA;
      v28 = *v20;
      v24[57] = v27;
      v29 = v28 >> 4;
      v24[56] = v28;
      LOWORD(v28) = v25 + v26 + v21;
      v24[58] = v29 & 0xF0 | BYTE1(v27) & 0xF;
      v30 = v20[6];
      v24[62] = v22;
      v20 += 48;
      v24[60] = v28;
      v24[63] = v23;
      v24[64] = v25 & 0xF | (16 * v26);
      v24[65] = (v22 >> 2) & 0xC0 | (v23 >> 4) & 0x30 | (v26 >> 2) & 0xC | (v25 >> 4) & 3;
      *(_DWORD *)(v24 + 66) = 0;
      v24[59] = v30;
      v24[61] = (v30 >> 4) & 0xF0 | BYTE1(v28) & 0xF;
      *((_WORD *)v24 + 35) = 0;
    }
    while ( v19 != v18 );
  }
  v31 = 0;
  v32 = 0;
  v33 = 0;
  do
  {
    v34 = (char *)v37 + v31;
    v31 += 2;
    v32 += *v34;
    v33 += v34[1];
  }
  while ( v31 != 126 );
  HIBYTE(v51) = -BYTE6(v51) - (v33 + v32);
  if ( (unsigned int)drm_connector_update_edid_property(a1) )
    v36 = 0;
  *(_DWORD *)(a1 + 216) = v4;
  *(_DWORD *)(a1 + 220) = v5;
LABEL_6:
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: MODE COUNT =%d\n\n", v36);
  _ReadStatusReg(SP_EL0);
  return v36;
}
