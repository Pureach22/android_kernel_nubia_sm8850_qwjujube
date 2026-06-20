__int64 __fastcall dsi_bridge_mode_validate_and_fixup(__int64 a1, _BYTE *a2, __int64 a3, int *a4)
{
  __int64 v4; // x8
  __int64 v5; // x24
  int v10; // w9
  int v11; // w10
  int v12; // w8
  int v13; // w11
  int v14; // w12
  int v15; // w9
  int v16; // w10
  int v17; // w8
  __int64 v18; // x11
  unsigned int v19; // w9
  unsigned int v20; // w10
  int v21; // w8
  __int64 v22; // x23
  int v23; // w9
  int v24; // w0
  unsigned int v25; // w8
  char v26; // w9
  int v27; // w10
  __int64 v28; // x8
  __int16 v29; // w9
  __int64 v30; // x10
  __int64 v31; // x11
  int v32; // w9
  int v33; // w10
  __int64 v34; // x1
  int v35; // w0
  __int64 result; // x0
  int v37; // w8
  int v38; // w8
  int v39; // w5
  int v40; // w6
  size_t v41; // x0
  int v42; // w7
  int v43; // w9
  int v44; // w8
  _DWORD v45[4]; // [xsp+18h] [xbp-C8h] BYREF
  __int64 v46; // [xsp+28h] [xbp-B8h]
  unsigned __int64 v47; // [xsp+30h] [xbp-B0h]
  __int128 v48; // [xsp+38h] [xbp-A8h]
  __int64 v49; // [xsp+48h] [xbp-98h]
  __int64 v50; // [xsp+50h] [xbp-90h]
  __int64 v51; // [xsp+58h] [xbp-88h]
  __int64 v52; // [xsp+60h] [xbp-80h]
  __int64 v53; // [xsp+68h] [xbp-78h]
  __int64 v54; // [xsp+70h] [xbp-70h]
  __int64 v55; // [xsp+78h] [xbp-68h]
  __int64 v56; // [xsp+80h] [xbp-60h]
  __int64 v57; // [xsp+88h] [xbp-58h]
  __int64 v58; // [xsp+90h] [xbp-50h]
  __int64 v59; // [xsp+98h] [xbp-48h]
  __int64 v60; // [xsp+A0h] [xbp-40h]
  __int64 v61; // [xsp+A8h] [xbp-38h]
  __int64 v62; // [xsp+B0h] [xbp-30h]
  __int64 v63; // [xsp+B8h] [xbp-28h]
  __int64 v64; // [xsp+C0h] [xbp-20h]
  __int64 v65; // [xsp+C8h] [xbp-18h]
  __int64 v66; // [xsp+D0h] [xbp-10h]
  __int64 v67; // [xsp+D8h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 112);
  if ( !v4 || !*(_QWORD *)(v4 + 80) || !*(_QWORD *)a2 )
  {
LABEL_37:
    result = 0;
    goto LABEL_38;
  }
  v5 = *(_QWORD *)(*(_QWORD *)a2 + 2008LL);
  v61 = 0;
  v62 = 0;
  v63 = 0;
  v64 = 0;
  v65 = 0;
  v10 = *(unsigned __int16 *)(v5 + 154);
  v11 = *(unsigned __int16 *)(v5 + 152);
  v12 = *(unsigned __int16 *)(v5 + 148);
  v13 = *(unsigned __int16 *)(v5 + 150);
  v14 = *(unsigned __int16 *)(v5 + 162);
  v46 = 0;
  v47 = 0;
  v48 = 0u;
  v45[0] = v12;
  v45[1] = v10 - v11;
  v15 = v11 - v13;
  v16 = *(unsigned __int16 *)(v5 + 164);
  v17 = v13 - v12;
  v18 = *(_QWORD *)(a3 + 16);
  v49 = 0;
  v50 = 0;
  v45[2] = v15;
  v45[3] = v17;
  v19 = v16 - v14;
  v20 = *(unsigned __int16 *)(v5 + 158);
  v21 = *(unsigned __int16 *)(v5 + 156);
  v22 = *(_QWORD *)(v18 + 2512);
  v51 = 0;
  v52 = 0;
  v47 = __PAIR64__(v19, v20);
  v23 = *(unsigned __int16 *)(v5 + 160);
  LODWORD(v46) = v21;
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = 0;
  v58 = 0;
  v59 = 0;
  v60 = 0;
  LODWORD(v48) = v14 - v23;
  *(_QWORD *)((char *)&v48 + 4) = v23 - v20;
  v24 = drm_mode_vrefresh(v5 + 144);
  v25 = *(unsigned __int8 *)(v5 + 168);
  HIDWORD(v48) = v24;
  v26 = v25 & 1;
  v27 = (v25 >> 2) & 1;
  v28 = *(_QWORD *)(v22 + 3248);
  BYTE4(v46) = v26;
  BYTE8(v48) = v27;
  v66 = v28;
  if ( v28 )
  {
    v29 = *(_WORD *)(v28 + 3400);
    v53 = v28 + 2496;
    v54 = v28 + 2712;
    v30 = *(_QWORD *)(v28 + 3404);
    v31 = *(_QWORD *)(v28 + 2408);
    LOWORD(v52) = v29;
    v55 = v30;
    v49 = v31;
  }
  v32 = *(_DWORD *)(v22 + 3240);
  if ( (v32 & 0x20) != 0 )
  {
    v33 = 1;
    HIDWORD(v62) = 1;
  }
  else
  {
    v33 = 0;
  }
  if ( (~v32 & 0x21) != 0 )
  {
    if ( (v32 & 2) == 0 )
      goto LABEL_11;
  }
  else
  {
    v33 |= 2u;
    HIDWORD(v62) = v33;
    if ( (v32 & 2) == 0 )
    {
LABEL_11:
      if ( v22 == -3232 )
        goto LABEL_22;
      goto LABEL_15;
    }
  }
  v33 |= 4u;
  HIDWORD(v62) = v33;
  if ( v22 == -3232 )
    goto LABEL_22;
LABEL_15:
  if ( (v32 & 4) != 0 )
  {
    v33 |= 8u;
    HIDWORD(v62) = v33;
    if ( (v32 & 8) == 0 )
    {
LABEL_17:
      if ( (v32 & 0x40) == 0 )
        goto LABEL_18;
      goto LABEL_41;
    }
  }
  else if ( (v32 & 8) == 0 )
  {
    goto LABEL_17;
  }
  v33 |= 0x10u;
  HIDWORD(v62) = v33;
  if ( (v32 & 0x40) == 0 )
  {
LABEL_18:
    if ( (v32 & 0x80) == 0 )
      goto LABEL_19;
    goto LABEL_42;
  }
LABEL_41:
  v33 |= 0x80u;
  HIDWORD(v62) = v33;
  if ( (v32 & 0x80) == 0 )
  {
LABEL_19:
    if ( (v32 & 0x10) == 0 )
      goto LABEL_20;
LABEL_43:
    v33 |= 0x20u;
    HIDWORD(v62) = v33;
    if ( (v32 & 0x100) == 0 )
      goto LABEL_22;
    goto LABEL_21;
  }
LABEL_42:
  v33 |= 0x100u;
  HIDWORD(v62) = v33;
  if ( (v32 & 0x10) != 0 )
    goto LABEL_43;
LABEL_20:
  if ( (v32 & 0x100) != 0 )
LABEL_21:
    HIDWORD(v62) = v33 | 0x200;
LABEL_22:
  HIDWORD(v63) = *(_DWORD *)(*(_QWORD *)(a3 + 264) + 1224LL);
  if ( v28 && (unsigned int)dsi_display_restore_bit_clk(a3, v45) )
  {
    printk(&unk_23D3E3, v34);
    result = 1;
    goto LABEL_38;
  }
  v35 = dsi_display_validate_mode_change(*(_QWORD *)(a1 + 304), v45, a4);
  if ( !v35 )
  {
    v37 = a4[39];
    if ( (v37 & 8) != 0 && (a2[10] & 4) != 0 )
      a4[39] = v37 & 0xFFFFFFF7;
    if ( (dsi_display_mode_match(v45, a4, 3) & 1) == 0 )
    {
      v38 = a4[39];
      if ( (v38 & 0x1B0) == 0 && ((a2[10] & 4) == 0 || *(_BYTE *)(a3 + 64) == 1) )
      {
        v39 = *a4;
        v40 = a4[6];
        v41 = sde_dbg_base_evtlog;
        v42 = a4[11];
        v43 = a4[38];
        a4[39] = v38 | 8;
        sde_evtlog_log(v41, "_dsi_bridge_mode_validate_and_fixup", 465, -1, 17476, v39, v40, v42, v43);
      }
    }
    if ( (dsi_display_mode_match(v45, a4, 1) & 1) == 0 )
    {
      v44 = a4[39];
      if ( (v44 & 0x20) != 0 )
      {
        a4[39] = v44 & 0xFFFFFFDF;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DMS and dyn clk not supported in same commit\n");
      }
    }
    goto LABEL_37;
  }
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: [%s] seamless mode mismatch failure rc=%d\n",
    *(const char **)(*(_QWORD *)(a1 + 304) + 32LL),
    v35);
  result = 1;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
