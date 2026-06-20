__int64 __fastcall dsi_bridge_mode_fixup(__int64 a1, __int64 *a2, _QWORD *a3)
{
  _QWORD *v3; // x19
  __int64 v4; // x8
  __int64 v5; // x9
  int v6; // w8
  __int64 v7; // x22
  __int64 v8; // x8
  int v9; // w10
  unsigned int v11; // w8
  int v12; // w11
  unsigned int v13; // w9
  int v14; // w12
  int v15; // w9
  int v16; // w10
  unsigned int v18; // w9
  unsigned int v19; // w10
  int v20; // w8
  int v22; // w9
  int v23; // w0
  unsigned int v24; // w8
  char v25; // w9
  int v26; // w10
  __int64 v27; // x8
  __int16 v28; // w9
  __int64 v29; // x10
  __int64 v30; // x8
  int v31; // w8
  int v32; // w9
  __int64 result; // x0
  int v34; // w11
  unsigned int v35; // w12
  unsigned int v36; // w8
  __int64 v37; // x8
  __int64 v38; // x10
  __int64 v39; // x8
  __int64 v40; // x10
  __int64 v41; // x11
  __int64 v42; // x8
  __int64 v43; // x10
  __int64 v44; // x11
  __int64 v45; // x8
  __int64 v46; // x10
  __int64 v47; // x11
  unsigned int v48; // w0
  __int64 v49; // [xsp+8h] [xbp-D8h] BYREF
  __int64 v50; // [xsp+10h] [xbp-D0h] BYREF
  unsigned __int64 v51; // [xsp+18h] [xbp-C8h] BYREF
  __int128 v52; // [xsp+20h] [xbp-C0h]
  unsigned __int64 v53; // [xsp+30h] [xbp-B0h]
  __int128 v54; // [xsp+38h] [xbp-A8h]
  __int64 v55; // [xsp+48h] [xbp-98h]
  __int64 v56; // [xsp+50h] [xbp-90h]
  __int64 v57; // [xsp+58h] [xbp-88h]
  __int64 v58; // [xsp+60h] [xbp-80h]
  __int64 v59; // [xsp+68h] [xbp-78h]
  __int64 v60; // [xsp+70h] [xbp-70h]
  __int64 v61; // [xsp+78h] [xbp-68h]
  __int64 v62; // [xsp+80h] [xbp-60h]
  __int64 v63; // [xsp+88h] [xbp-58h]
  __int64 v64; // [xsp+90h] [xbp-50h]
  __int64 v65; // [xsp+98h] [xbp-48h]
  __int64 v66; // [xsp+A0h] [xbp-40h]
  __int64 v67; // [xsp+A8h] [xbp-38h]
  __int64 v68; // [xsp+B0h] [xbp-30h]
  unsigned __int64 v69; // [xsp+B8h] [xbp-28h]
  __int64 v70; // [xsp+C0h] [xbp-20h]
  __int64 v71; // [xsp+C8h] [xbp-18h]
  __int64 v72; // [xsp+D0h] [xbp-10h]
  __int64 v73; // [xsp+D8h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
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
  v54 = 0u;
  v53 = 0;
  v51 = 0;
  v52 = 0u;
  v49 = 0;
  v50 = 0;
  if ( !a1
    || !a2
    || !a3
    || (v3 = *(_QWORD **)(a1 + 304)) == nullptr
    || (v4 = v3[2]) == 0
    || !*(_QWORD *)(v4 + 2512)
    || (v5 = a2[23], v6 = *(_DWORD *)(v4 + 152), v6 >= *(_DWORD *)(v5 + 40))
    || (v7 = *(_QWORD *)(*(_QWORD *)(v5 + 48) + 40LL * v6 + 24)) == 0 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    goto LABEL_16;
  }
  v8 = v3[33];
  if ( v8 && !*(_DWORD *)(v8 + 1432) )
  {
    v37 = a2[2];
    result = 1;
    v38 = *a2;
    a3[1] = a2[1];
    a3[2] = v37;
    *a3 = v38;
    v39 = a2[6];
    v40 = a2[3];
    v41 = a2[4];
    a3[5] = a2[5];
    a3[6] = v39;
    a3[3] = v40;
    a3[4] = v41;
    v42 = a2[10];
    v43 = a2[7];
    v44 = a2[8];
    a3[9] = a2[9];
    a3[10] = v42;
    a3[7] = v43;
    a3[8] = v44;
    v45 = a2[14];
    v46 = a2[11];
    v47 = a2[12];
    a3[13] = a2[13];
    a3[14] = v45;
    a3[11] = v46;
    a3[12] = v47;
    *(_QWORD *)(v7 + 3232) = a3;
    *(_QWORD *)(v7 + 3248) = &default_priv_info;
    *(_DWORD *)(v7 + 3240) = 0;
    goto LABEL_17;
  }
  v9 = *((unsigned __int16 *)a2 + 4);
  v11 = *((unsigned __int16 *)a2 + 2);
  v12 = *((unsigned __int16 *)a2 + 3);
  v13 = *((unsigned __int16 *)a2 + 5) - v9;
  v14 = *((unsigned __int16 *)a2 + 9);
  v53 = 0;
  *(_QWORD *)&v54 = 0;
  v51 = __PAIR64__(v13, v11);
  v15 = v9 - v12;
  v16 = *((unsigned __int16 *)a2 + 10);
  HIDWORD(v52) = 0;
  LODWORD(v52) = v15;
  *(_QWORD *)((char *)&v52 + 4) = v12 - v11;
  v18 = v16 - v14;
  v19 = *((unsigned __int16 *)a2 + 7);
  v20 = *((unsigned __int16 *)a2 + 6);
  v70 = 0;
  v71 = 0;
  v53 = __PAIR64__(v18, v19);
  v22 = *((unsigned __int16 *)a2 + 8);
  DWORD2(v52) = v20;
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
  HIDWORD(v54) = 0;
  v55 = 0;
  LODWORD(v54) = v14 - v22;
  *(_QWORD *)((char *)&v54 + 4) = v22 - v19;
  v23 = drm_mode_vrefresh(a2);
  v24 = *((unsigned __int8 *)a2 + 24);
  HIDWORD(v54) = v23;
  v25 = v24 & 1;
  v26 = (v24 >> 2) & 1;
  v27 = *(_QWORD *)(v7 + 3248);
  BYTE12(v52) = v25;
  BYTE8(v54) = v26;
  v72 = v27;
  if ( v27 )
  {
    v28 = *(_WORD *)(v27 + 3400);
    v59 = v27 + 2496;
    v60 = v27 + 2712;
    v29 = *(_QWORD *)(v27 + 3404);
    v30 = *(_QWORD *)(v27 + 2408);
    LOWORD(v58) = v28;
    v61 = v29;
    v55 = v30;
  }
  v31 = *(_DWORD *)(v7 + 3240);
  if ( (v31 & 0x20) != 0 )
  {
    v32 = 1;
    HIDWORD(v68) = 1;
  }
  else
  {
    v32 = 0;
  }
  if ( (~v31 & 0x21) != 0 )
  {
    if ( (v31 & 2) != 0 )
    {
LABEL_21:
      v32 |= 4u;
      HIDWORD(v68) = v32;
      if ( (v31 & 4) != 0 )
        goto LABEL_22;
      goto LABEL_30;
    }
  }
  else
  {
    v32 |= 2u;
    HIDWORD(v68) = v32;
    if ( (v31 & 2) != 0 )
      goto LABEL_21;
  }
  if ( (v31 & 4) != 0 )
  {
LABEL_22:
    v32 |= 8u;
    HIDWORD(v68) = v32;
    if ( (v31 & 8) != 0 )
      goto LABEL_23;
    goto LABEL_31;
  }
LABEL_30:
  if ( (v31 & 8) != 0 )
  {
LABEL_23:
    v32 |= 0x10u;
    HIDWORD(v68) = v32;
    if ( (v31 & 0x40) != 0 )
      goto LABEL_24;
    goto LABEL_32;
  }
LABEL_31:
  if ( (v31 & 0x40) != 0 )
  {
LABEL_24:
    v32 |= 0x80u;
    HIDWORD(v68) = v32;
    if ( (v31 & 0x80) != 0 )
      goto LABEL_25;
    goto LABEL_33;
  }
LABEL_32:
  if ( (v31 & 0x80) != 0 )
  {
LABEL_25:
    v32 |= 0x100u;
    HIDWORD(v68) = v32;
    if ( (v31 & 0x10) != 0 )
      goto LABEL_26;
    goto LABEL_34;
  }
LABEL_33:
  if ( (v31 & 0x10) != 0 )
  {
LABEL_26:
    v32 |= 0x20u;
    HIDWORD(v68) = v32;
    if ( (v31 & 0x100) == 0 )
      goto LABEL_36;
    goto LABEL_35;
  }
LABEL_34:
  if ( (v31 & 0x100) != 0 )
LABEL_35:
    HIDWORD(v68) = v32 | 0x200;
LABEL_36:
  LODWORD(v49) = *(_QWORD *)(v7 + 1824);
  HIDWORD(v49) = *(_QWORD *)(v7 + 1952);
  if ( (unsigned int)dsi_display_find_mode(v3, &v51, &v49, &v50) )
  {
LABEL_37:
    result = 1;
    goto LABEL_17;
  }
  v72 = *(_QWORD *)(v50 + 184);
  v34 = *(_DWORD *)(v50 + 156);
  v35 = *(_DWORD *)(v50 + 160);
  v36 = *(_DWORD *)(v50 + 164);
  LOBYTE(v58) = *(_BYTE *)(v72 + 3400);
  v59 = v72 + 2496;
  HIDWORD(v68) = v34;
  v69 = __PAIR64__(v36, v35);
  if ( (unsigned int)dsi_display_restore_bit_clk(v3, &v51) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] bit clk rate cannot be restored\n", v3[4]);
  }
  else if ( (unsigned int)dsi_display_update_dyn_bit_clk(v3, &v51) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to update bit clock\n", v3[4]);
  }
  else
  {
    v48 = dsi_display_validate_mode(*(_QWORD *)(a1 + 304), &v51, 1);
    if ( v48 )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%d] mode is not valid, rc=%d\n",
        *(unsigned int *)(a1 + 296),
        v48);
    }
    else if ( (dsi_bridge_mode_validate_and_fixup(a1, a2 - 18, v3, &v51) & 1) != 0 )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to validate dsi bridge mode.\n", v3[4]);
    }
    else
    {
      if ( (*((_BYTE *)a2 - 134) & 4) == 0 || (v68 & 0x1B000000000LL) == 0 )
      {
        dsi_convert_to_drm_mode((int *)&v51, (__int64)a3);
        dsi_convert_to_msm_mode(&v51, v7 + 3232);
        goto LABEL_37;
      }
      drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: seamless upon active changed 0x%x %d\n", HIDWORD(v68), 1);
    }
  }
LABEL_16:
  result = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
