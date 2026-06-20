__int64 __fastcall sde_hw_wb_setup_format(_QWORD *a1, __int64 *a2)
{
  __int64 v2; // x8
  int v4; // w10
  int v5; // w9
  int v6; // w10
  unsigned int v7; // w21
  int v8; // w13
  int v9; // w10
  unsigned int v10; // w22
  int v11; // w11
  int v12; // w27
  int v13; // w28
  int v14; // w20
  int v15; // w26
  unsigned int v16; // w23
  unsigned int v17; // w25
  __int64 v18; // x9
  int v19; // w11
  unsigned int v20; // w10
  __int64 *v21; // x24
  __int64 *v22; // x24
  unsigned int v23; // w24
  unsigned int v25; // [xsp+Ch] [xbp-4h]

  v2 = *a2;
  v4 = (*(_DWORD *)(*a2 + 4) << 19)
     | (*(_DWORD *)(*a2 + 16) << 23)
     | (*(unsigned __int8 *)(*a2 + 15) << 6)
     | (16 * *(unsigned __int8 *)(*a2 + 14))
     | (4 * *(unsigned __int8 *)(*a2 + 13))
     | *(unsigned __int8 *)(*a2 + 12);
  if ( *(_BYTE *)(*a2 + 15) )
  {
    if ( !*(_BYTE *)(*a2 + 24) )
    {
LABEL_6:
      v4 |= 0x4100u;
      goto LABEL_8;
    }
LABEL_5:
    if ( (*(_BYTE *)(a1[7] + 33LL) & 1) != 0 )
    {
      v4 |= 0x100u;
      goto LABEL_8;
    }
    goto LABEL_6;
  }
  if ( *(_BYTE *)(*a2 + 24) )
    goto LABEL_5;
LABEL_8:
  v5 = *(_DWORD *)(v2 + 28);
  v6 = v4 | ((*(_QWORD *)(v2 + 32) & 1) << 15) | ((unsigned int)*(_QWORD *)(v2 + 32) << 20) & 0x200000;
  if ( v5 == 2 && (*(_QWORD *)(v2 + 32) & 4LL) == 0 )
    v6 |= 0x80000000;
  v7 = *(_DWORD *)(v2 + 8);
  if ( *((_BYTE *)a2 + 93) )
    v6 |= 0x800u;
  v8 = v6 | (*(unsigned __int8 *)(v2 + 20) << 18) | (*(unsigned __int8 *)(v2 + 21) << 17);
  v9 = *((unsigned __int16 *)a2 + 41);
  v10 = v8 | ((*(unsigned __int8 *)(v2 + 22) << 12) - 4096) | ((*(unsigned __int8 *)(v2 + 23) << 9) - 512);
  if ( !*((_WORD *)a2 + 41) || (v11 = *((unsigned __int16 *)a2 + 40), !*((_WORD *)a2 + 40)) )
  {
    v11 = *((_DWORD *)a2 + 3);
    v9 = *((_DWORD *)a2 + 4);
  }
  v12 = *((_DWORD *)a2 + 14);
  v13 = *((_DWORD *)a2 + 15);
  v15 = *((_DWORD *)a2 + 16);
  v14 = *((_DWORD *)a2 + 17);
  v25 = v11 | (v9 << 16);
  if ( v5 == 2 && (*(_QWORD *)(v2 + 32) & 4) != 0 )
  {
    v18 = a1[5];
    v10 |= 0x80000000;
    v19 = *(_DWORD *)(v18 + 48);
    v20 = *(_DWORD *)(a1[4] + 4LL);
    if ( *(_DWORD *)v2 == 909199186 )
      v16 = (v19 << 8) | 8;
    else
      v16 = v19 << 8;
    if ( HIWORD(v20) == 0x2000 )
    {
      v21 = a2;
      sde_reg_write((__int64)a1, 0x144u, *(_DWORD *)(v18 + 56) | (16 * v19), "WB_UBWC_STATIC_CTRL");
      a2 = v21;
      v20 = *(_DWORD *)(a1[4] + 4LL);
    }
    if ( HIWORD(v20) == 4096 )
    {
      v22 = a2;
      sde_reg_write(
        (__int64)a1,
        0x144u,
        *(_DWORD *)(a1[5] + 56LL) | (16 * *(_DWORD *)(a1[5] + 48LL)) | 0x100,
        "WB_UBWC_STATIC_CTRL");
      a2 = v22;
    }
    v17 = 1;
  }
  else
  {
    v16 = 0;
    v17 = 0;
  }
  v23 = *((unsigned __int8 *)a2 + 92);
  sde_reg_write((__int64)a1, 0x78u, 0xFFu, "WB_ALPHA_X_VALUE");
  sde_reg_write((__int64)a1, 0, v10, "WB_DST_FORMAT");
  sde_reg_write((__int64)a1, 4u, v17, "WB_DST_OP_MODE");
  sde_reg_write((__int64)a1, 8u, v7, "WB_DST_PACK_PATTERN");
  sde_reg_write((__int64)a1, 0x1Cu, v12 | (v13 << 16), "WB_DST_YSTRIDE0");
  sde_reg_write((__int64)a1, 0x20u, v15 | (v14 << 16), "WB_DST_YSTRIDE1");
  sde_reg_write((__int64)a1, 0x74u, v25, "WB_OUT_SIZE");
  sde_reg_write((__int64)a1, 0x48u, v16, "WB_DST_WRITE_CONFIG");
  return sde_reg_write((__int64)a1, 0x2B0u, v23, "WB_DST_ADDR_SW_STATUS");
}
