__int64 __fastcall sde_hw_intf_setup_timing_engine(__int64 a1, __int64 a2, __int64 a3, char a4, char a5)
{
  int v9; // w0
  int v10; // w9
  int v11; // w14
  __int64 v12; // x10
  unsigned int v13; // w0
  int v14; // w15
  int v15; // w17
  unsigned int v16; // w4
  int v17; // w8
  int v18; // w16
  int v19; // w11
  unsigned int v20; // w3
  int v21; // w27
  int v22; // w0
  int v23; // w12
  int v24; // w13
  int v25; // w7
  int v26; // w0
  int v27; // w1
  int v28; // w5
  int v29; // w2
  int v30; // w14
  int v31; // w3
  int v32; // w6
  unsigned int v33; // w17
  unsigned int v34; // w15
  unsigned int v35; // w20
  int v36; // w16
  int v37; // w17
  int v38; // w2
  unsigned int v39; // w24
  int v40; // w28
  int v41; // w9
  int v42; // w21
  unsigned int v43; // w26
  int v44; // w11
  int v45; // w23
  int v46; // w25
  int v49; // w2
  unsigned int v51; // [xsp+8h] [xbp-38h]
  unsigned int v52; // [xsp+Ch] [xbp-34h]
  unsigned int v53; // [xsp+10h] [xbp-30h]
  unsigned int v54; // [xsp+14h] [xbp-2Ch]
  __int64 v55; // [xsp+18h] [xbp-28h]
  unsigned int v56; // [xsp+24h] [xbp-1Ch]
  unsigned int v57; // [xsp+28h] [xbp-18h]
  unsigned int v58; // [xsp+2Ch] [xbp-14h]
  int v59; // [xsp+30h] [xbp-10h]
  unsigned int v60; // [xsp+34h] [xbp-Ch]
  int v61; // [xsp+38h] [xbp-8h]

  v9 = sde_reg_read(a1, 4);
  v10 = *(_DWORD *)(a2 + 32);
  v11 = *(_DWORD *)(a2 + 20);
  v12 = *(_QWORD *)(a1 + 40);
  v59 = v9;
  v13 = *(_DWORD *)a2;
  v14 = *(unsigned __int8 *)(a2 + 69);
  v15 = *(_DWORD *)(a2 + 16) + v10;
  v16 = *(_DWORD *)(v12 + 48);
  v17 = *(_DWORD *)(a2 + 56);
  v18 = v15 + *(_DWORD *)a2;
  v19 = *(_DWORD *)(a2 + 24) + *(_DWORD *)(a2 + 36);
  v20 = v16 - 9;
  v21 = v18 + v11;
  if ( v14 == 1 )
  {
    v22 = *(_DWORD *)(a2 + 80);
    if ( (*(_BYTE *)(a2 + 68) & 1) != 0 )
    {
      v13 = (v22 + 5) / 6u;
LABEL_6:
      v23 = 17;
      v24 = 1;
      goto LABEL_9;
    }
    v24 = 0;
    v23 = 0;
    v13 = (v22 + 2) / 3u;
  }
  else
  {
    if ( (*(_BYTE *)(a2 + 68) & 1) != 0 )
    {
      v13 >>= v20 > 1;
      goto LABEL_6;
    }
    v24 = 0;
    v23 = 16;
  }
LABEL_9:
  v60 = v16 - 9;
  v25 = ((v18 << 16) - 0x10000) | v15;
  v26 = ((v13 + v15) << 16) - 0x10000;
  if ( v20 >= 2 )
    v27 = 0;
  else
    v27 = *(_DWORD *)(a2 + 16) + v10;
  v28 = 0;
  v29 = ((*(_DWORD *)(a2 + 8) + v15) << 16) - 0x10000;
  if ( v20 < 2 )
    v30 = ~v11;
  else
    v30 = -1;
  v31 = v26 | v15;
  v32 = v29 | v15;
  if ( v16 <= 0xA && ((1 << v16) & 0x608) != 0 )
  {
    if ( !*(_BYTE *)(a2 + 69) )
    {
      v28 = 0;
      if ( **(_DWORD **)(a1 + 48) >> 28 != 6 || (v25 = v29 | v15, (*(_BYTE *)(a2 + 76) & 1) == 0) )
      {
        v25 = v29 | v15;
        goto LABEL_28;
      }
LABEL_26:
      v23 |= 0x1000u;
      goto LABEL_28;
    }
    v25 = v29 | v15;
    v31 = v15 + ((*(_DWORD *)(a2 + 72) + v15) << 16);
    v28 = v31;
  }
  v33 = **(_DWORD **)(a1 + 48) >> 28;
  if ( v33 >= 7 && (v14 & 1) != 0 || v33 == 6 && (*(_BYTE *)(a2 + 76) & 1) != 0 )
    goto LABEL_26;
LABEL_28:
  v34 = *(_DWORD *)(a2 + 12);
  v35 = v19 * v21 + v27 + v17;
  if ( v16 == 3 )
  {
    v36 = v34 < 0x2D0;
    v37 = v36;
  }
  else if ( v16 == 10 )
  {
    v36 = *(_DWORD *)(a2 + 40);
    v37 = *(_DWORD *)(a2 + 44);
  }
  else
  {
    v36 = 0;
    v37 = 0;
  }
  v61 = *(_DWORD *)(v12 + 48);
  v57 = v31;
  if ( (*(_QWORD *)(a3 + 32) & 1) != 0 )
    v38 = 8511;
  else
    v38 = *(unsigned __int8 *)(a3 + 12)
        | (4 * *(unsigned __int8 *)(a3 + 13))
        | (16 * *(unsigned __int8 *)(a3 + 14))
        | 0x2100;
  v39 = v10 | (v21 << 16);
  v40 = v23 | v24;
  v53 = v36 | (2 * v37);
  v54 = v38;
  v41 = v19 + *(_DWORD *)(a2 + 4);
  v52 = v35 + v34 * v21 - 1;
  v55 = *(_QWORD *)(v12 + 32);
  if ( (v55 & 8) != 0 && *(_BYTE *)(a2 + 77) )
    v40 |= 0x10000u;
  v42 = v41 * v21;
  v43 = v25;
  if ( (a5 & 1) != 0 )
    v44 = 70;
  else
    v44 = 1105;
  v45 = v41 + *(_DWORD *)(a2 + 28);
  v46 = v17 + v30;
  v56 = v32;
  v58 = v28;
  v51 = v44;
  if ( *(_BYTE *)(a1 + 77) == 1 )
    sde_reg_write(a1, 128, 3, "INTF_REG_SPLIT_LINK");
  sde_reg_write(a1, 8, v39, "INTF_HSYNC_CTL");
  sde_reg_write(a1, 12, (unsigned int)(v45 * v21), "INTF_VSYNC_PERIOD_F0");
  sde_reg_write(a1, 20, (unsigned int)(*(_DWORD *)(a2 + 36) * v21), "INTF_VSYNC_PULSE_WIDTH_F0");
  sde_reg_write(a1, 60, v43, "INTF_DISPLAY_HCTL");
  sde_reg_write(a1, 28, v35, "INTF_DISPLAY_V_START_F0");
  sde_reg_write(a1, 36, (unsigned int)(v46 + v42), "INTF_DISPLAY_V_END_F0");
  sde_reg_write(a1, 64, v56, "INTF_ACTIVE_HCTL");
  sde_reg_write(a1, 44, v35, "INTF_ACTIVE_V_START_F0");
  sde_reg_write(a1, 52, v52, "INTF_ACTIVE_V_END_F0");
  sde_reg_write(a1, 68, *(unsigned int *)(a2 + 48), "INTF_BORDER_COLOR");
  sde_reg_write(a1, 72, *(unsigned int *)(a2 + 52), "INTF_UNDERFLOW_COLOR");
  sde_reg_write(a1, 76, *(unsigned int *)(a2 + 56), "INTF_HSYNC_SKEW");
  sde_reg_write(a1, 80, v53, "INTF_POLARITY_CTL");
  sde_reg_write(a1, 168, 3, "INTF_FRAME_LINE_COUNT_EN");
  sde_reg_write(a1, 4, v59 | 0x60000000u, "INTF_CONFIG");
  sde_reg_write(a1, 144, v54, "INTF_PANEL_FORMAT");
  sde_reg_write(a1, 100, v57, "INTF_DISPLAY_DATA_HCTL");
  sde_reg_write(a1, 104, v58, "INTF_ACTIVE_DATA_HCTL");
  if ( (a4 & 1) != 0 )
  {
    v40 |= 0x800000u;
    sde_reg_write(a1, 108, v51, "INTF_TIMING_ENGINE_ALIGN_CTRL");
  }
  if ( (v55 & 0x400000) != 0 && v61 != 3 && v60 >= 2 )
    v49 = v40 | 0x1000000;
  else
    v49 = v40;
  return sde_reg_write(a1, 96, v49 & 0xEFFFFFFF | ((((unsigned int)v55 >> 23) & 1) << 28), "INTF_CONFIG2");
}
