size_t __fastcall dsi_ctrl_hw_cmn_set_video_timing(__int64 a1, __int64 a2)
{
  _DWORD *v4; // x11
  int *v5; // x8
  int *v6; // x9
  _DWORD *v7; // x10
  _DWORD *v8; // x11
  int v9; // w12
  int v10; // w21
  unsigned int v11; // w8
  int v12; // w9
  int v13; // w10
  int v14; // w0
  int v15; // w26
  int v16; // w25
  int v17; // w24
  int v18; // w27
  unsigned int v19; // w0
  int v20; // w10
  unsigned int v21; // w21
  int v22; // w22
  int v23; // w4
  int v24; // w7
  size_t result; // x0
  int *v26; // x11
  char v27; // [xsp+0h] [xbp+0h]

  if ( *(_BYTE *)(a2 + 224) == 1 )
  {
    v4 = *(_DWORD **)(a2 + 232);
    if ( v4 )
      goto LABEL_3;
  }
  if ( *(_BYTE *)(a2 + 225) != 1 || !*(_QWORD *)(a2 + 240) )
  {
    v10 = *(_DWORD *)(a2 + 152);
    goto LABEL_15;
  }
  if ( !*(_BYTE *)(a2 + 224) )
  {
LABEL_21:
    v26 = *(int **)(a2 + 240);
    if ( v26 )
    {
      v5 = v26 + 125;
      v6 = v26 + 123;
      v7 = v26 + 127;
      v8 = v26 + 124;
      goto LABEL_4;
    }
LABEL_23:
    v10 = 0;
    v11 = 0;
    v12 = 0;
    v13 = 2817;
    goto LABEL_5;
  }
  v4 = *(_DWORD **)(a2 + 232);
  if ( !v4 )
  {
    if ( (*(_BYTE *)(a2 + 225) & 1) == 0 )
      goto LABEL_23;
    goto LABEL_21;
  }
LABEL_3:
  v5 = v4 + 40;
  v6 = v4 + 38;
  v7 = v4 + 36;
  v8 = v4 + 39;
LABEL_4:
  v9 = *v6;
  v10 = *v5;
  v11 = (32 * *v7) & 0xFFFFF4C0;
  v12 = 16 * *v8;
  v13 = (v9 << 16) | 0xB01;
LABEL_5:
  writel_relaxed_16(v13 | v11 | v12, (unsigned int *)(*(_QWORD *)a1 + 672LL));
  if ( *(_BYTE *)(a1 + 1506) == 1 )
  {
    v14 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 16LL));
    writel_relaxed_16(v14 | 0x2000000, (unsigned int *)(*(_QWORD *)a1 + 16LL));
  }
  *(_DWORD *)(a2 + 152) = (unsigned int)(*(_DWORD *)(a2 + 252) + *(_DWORD *)(a2 + 248) * *(_DWORD *)(a2 + 152) - 1)
                        / *(_DWORD *)(a2 + 252);
LABEL_15:
  v15 = *(_DWORD *)(a2 + 160);
  v16 = *(_DWORD *)(a2 + 184);
  v17 = *(_DWORD *)(a2 + 180) + v16;
  v18 = v17 + *(_DWORD *)(a2 + 176);
  v19 = (unsigned __int16)(*(_WORD *)(a2 + 156) + v15) | ((unsigned __int16)(*(_WORD *)(a2 + 156) + v15 + v10) << 16);
  v20 = *(_DWORD *)(a2 + 164) + *(_DWORD *)(a2 + 156) + v15 + v10;
  v21 = v18 + *(_DWORD *)(a2 + 188);
  v22 = v20 - 1;
  writel_relaxed_16(v19, (unsigned int *)(*(_QWORD *)a1 + 36LL));
  writel_relaxed_16((unsigned __int16)v17 | ((unsigned __int16)v18 << 16), (unsigned int *)(*(_QWORD *)a1 + 40LL));
  writel_relaxed_16((unsigned __int16)v22 | ((unsigned __int16)(v21 - 1) << 16), (unsigned int *)(*(_QWORD *)a1 + 44LL));
  writel_relaxed_16(v15 << 16, (unsigned int *)(*(_QWORD *)a1 + 48LL));
  writel_relaxed_16(0, (unsigned int *)(*(_QWORD *)a1 + 52LL));
  writel_relaxed_16(v16 << 16, (unsigned int *)(*(_QWORD *)a1 + 56LL));
  writel_relaxed_16(0x3FD08u, (unsigned int *)(*(_QWORD *)a1 + 188LL));
  writel_relaxed_16(0x10100u, (unsigned int *)(*(_QWORD *)a1 + 164LL));
  writel_relaxed_16(1u, (unsigned int *)(*(_QWORD *)a1 + 484LL));
  if ( a1 )
    v23 = *(_DWORD *)(a1 + 56);
  else
    v23 = -1;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: ctrl video parameters updated\n", v23);
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "dsi_ctrl_hw_cmn_set_video_timing",
             531,
             -1,
             v21 - 1,
             v22,
             -1059143953,
             v24,
             v27);
  if ( *(_BYTE *)(a2 + 144) == 1 )
  {
    writel_relaxed_16(v21, (unsigned int *)(*(_QWORD *)a1 + 1236LL));
    return writel_relaxed_16(1u, (unsigned int *)(*(_QWORD *)a1 + 1232LL));
  }
  return result;
}
