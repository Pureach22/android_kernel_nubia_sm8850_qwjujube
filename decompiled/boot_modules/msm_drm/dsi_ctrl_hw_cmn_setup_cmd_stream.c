void __fastcall dsi_ctrl_hw_cmn_setup_cmd_stream(__int64 a1, __int64 a2, unsigned int *a3, int a4, __int64 a5)
{
  __int64 v7; // x8
  int v8; // w9
  signed int v9; // w22
  __int64 v10; // x21
  __int64 v11; // x28
  signed int v12; // w22
  int v13; // w22
  int v14; // w26
  unsigned int v15; // w23
  int v16; // w25
  unsigned int v17; // w24
  int v18; // w27
  unsigned int v19; // w21
  unsigned int v20; // w22
  int v21; // w0
  int v22; // w21
  int v23; // w0
  char v24; // w9
  int v25; // w10
  unsigned int v26; // w8
  int v27; // w9
  int v28; // w4
  int v29; // w24
  unsigned int v30; // w21
  int v31; // w4
  _DWORD dest[166]; // [xsp+8h] [xbp-2A8h] BYREF
  __int64 v33; // [xsp+2A0h] [xbp-10h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a5 && (!*(_WORD *)(a5 + 4) || !*(_WORD *)(a5 + 6)) )
    goto LABEL_45;
  v7 = *a3;
  if ( (unsigned int)v7 > 7 )
    v8 = 24;
  else
    v8 = bits_per_pixel[v7];
  if ( *(_BYTE *)(a2 + 72) == 1 && *(_QWORD *)(a2 + 80) )
  {
    if ( a5 )
    {
      v9 = *(unsigned __int16 *)(a5 + 4);
      v10 = a2;
      v11 = a5;
    }
    else
    {
      v9 = *(_DWORD *)a2;
      v11 = 0;
      v10 = a2;
    }
    memcpy(dest, *(const void **)(a2 + 80), 0xD4u);
    sde_dsc_populate_dsc_private_params((__int64)dest, v9 / LOWORD(dest[1]) * LOWORD(dest[1]), *(_BYTE *)(a1 + 1506));
    v18 = dest[36];
    v13 = dest[37];
    v17 = dest[38];
    v14 = dest[39];
  }
  else
  {
    if ( *(_BYTE *)(a2 + 73) != 1 || !*(_QWORD *)(a2 + 88) )
    {
      v13 = 0;
      v14 = 0;
      if ( a5 )
      {
        v15 = *(unsigned __int16 *)(a5 + 4);
        v16 = *(unsigned __int16 *)(a5 + 6);
      }
      else
      {
        v15 = *(_DWORD *)a2;
        v16 = *(_DWORD *)(a2 + 24);
      }
      v17 = (v8 * v15 + 7) >> 3;
      v18 = 0;
      goto LABEL_24;
    }
    if ( a5 )
    {
      v12 = *(unsigned __int16 *)(a5 + 4);
      v10 = a2;
      v11 = a5;
    }
    else
    {
      v12 = *(_DWORD *)a2;
      v11 = 0;
      v10 = a2;
    }
    memcpy(dest, *(const void **)(a2 + 88), sizeof(dest));
    sde_vdc_intf_prog_params((__int64)dest, v12 / dest[119] * dest[119]);
    v17 = dest[123];
    v18 = dest[127];
    v14 = dest[124];
    v13 = dest[122];
  }
  v15 = v18 * v17;
  v16 = 0;
  a5 = v11;
  a2 = v10;
LABEL_24:
  if ( *(_BYTE *)(a2 + 72) == 1 && *(_QWORD *)(a2 + 80) || *(_BYTE *)(a2 + 73) == 1 && *(_QWORD *)(a2 + 88) )
  {
    if ( a5 )
      v16 = *(unsigned __int16 *)(a5 + 6);
    else
      v16 = *(_DWORD *)(a2 + 24);
    if ( *(_BYTE *)(a1 + 1506) == 1 )
    {
      v15 = (v15 + 5) / 6;
      v21 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 440LL));
      writel_relaxed_16(v21 | 0x100000, (unsigned int *)(*(_QWORD *)a1 + 440LL));
    }
    else
    {
      v15 = (v15 + 2) / 3;
    }
    v22 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 680LL));
    v23 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 684LL));
    v24 = 16 * (a4 != 0);
    v25 = 0xFFFF << v24;
    v26 = ((32 * v18) & 0xFFFFFFDF | (16 * v14) | 0x3901) << v24;
    v27 = v13 << v24;
    v20 = v22 & ~v25 | v26;
    v19 = v23 & ~v25 | v27;
    if ( a1 )
      v28 = *(_DWORD *)(a1 + 56);
    else
      v28 = -1;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: reg_ctrl 0x%x reg_ctrl2 0x%x\n", v28, v20, v19);
  }
  else
  {
    v19 = 0;
    v20 = 0;
  }
  writel_relaxed_16(0x49C3Cu, (unsigned int *)(*(_QWORD *)a1 + 188LL));
  v29 = ((a4 & 3) << 8) | (v17 << 16);
  writel_relaxed_16(v20, (unsigned int *)(*(_QWORD *)a1 + 680LL));
  writel_relaxed_16(v19, (unsigned int *)(*(_QWORD *)a1 + 684LL));
  writel_relaxed_16(v29 + 65593, (unsigned int *)(*(_QWORD *)a1 + 88LL));
  writel_relaxed_16(v29 + 65593, (unsigned int *)(*(_QWORD *)a1 + 96LL));
  v30 = v15 | (v16 << 16);
  writel_relaxed_16(v30, (unsigned int *)(*(_QWORD *)a1 + 92LL));
  writel_relaxed_16(v30, (unsigned int *)(*(_QWORD *)a1 + 100LL));
  if ( *(_BYTE *)(a1 + 1505) == 1 )
    writel_relaxed_16((2 * a4) | 1, (unsigned int *)(*(_QWORD *)a1 + 692LL));
  if ( a1 )
    v31 = *(_DWORD *)(a1 + 56);
  else
    v31 = -1;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: stream_ctrl 0x%x stream_total 0x%x\n", v31, v29 + 65593, v30);
LABEL_45:
  _ReadStatusReg(SP_EL0);
}
