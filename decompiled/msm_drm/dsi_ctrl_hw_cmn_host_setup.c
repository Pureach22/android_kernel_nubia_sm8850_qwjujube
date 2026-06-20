void __fastcall dsi_ctrl_hw_cmn_host_setup(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  int v6; // w8
  int v7; // w9
  int v8; // w8
  int v9; // w8
  int v10; // w0
  int v11; // w9
  int v12; // w10
  int v13; // w4

  v4 = readl_relaxed_19(*(_QWORD *)a1 + 132LL);
  v5 = *(unsigned int *)(a2 + 20);
  if ( (unsigned int)v5 >= 6 )
  {
    __break(0x5512u);
    writel_relaxed_16(v4);
  }
  else
  {
    writel_relaxed_16(v4 & 0x7FFFFF8F | ((unsigned __int8)(*(_DWORD *)(a2 + 16) == 1) << 31) | (16
                                                                                              * (byte_28FF88[v5] & 7u)));
    if ( *(_BYTE *)(a2 + 56) == 1 )
    {
      v6 = readl_relaxed_19(*(_QWORD *)a1 + 816LL) & 0xFF8F8FFF;
      if ( *(_BYTE *)(a2 + 57) == 1 )
      {
        if ( *(_DWORD *)(a2 + 72) == 2 )
          v7 = 5255424;
        else
          v7 = 5255184;
        v8 = v6 | v7;
      }
      else
      {
        v8 = v6 | 0x503000;
      }
      writel_relaxed_16(v8 | 1u);
      __dsb(0xEu);
    }
    writel_relaxed_16(*(_DWORD *)(a2 + 44) & 0x3F | ((*(_DWORD *)(a2 + 40) & 0x3Fu) << 8));
    if ( *(_BYTE *)(a2 + 48) )
      v9 = 16;
    else
      v9 = 0;
    writel_relaxed_16(v9 | (unsigned int)*(unsigned __int8 *)(a2 + 49));
    writel_relaxed_16(575);
    v10 = readl_relaxed_19(*(_QWORD *)a1 + 4LL);
    if ( *(_BYTE *)(a2 + 11) )
      v11 = 0x1000000;
    else
      v11 = 0;
    if ( *(_BYTE *)(a2 + 12) )
      v12 = 0x100000;
    else
      v12 = 0;
    writel_relaxed_16(v10 | v11 | v12 | (16 * (*(_DWORD *)(a2 + 4) & 0xF)) | 0x100u);
    if ( *(_DWORD *)(a2 + 52) == 1 )
      writel_relaxed_16(1);
    if ( *(_BYTE *)(a1 + 1504) == 1 )
      writel_relaxed_16(0x10000000);
    if ( a1 )
      v13 = *(_DWORD *)(a1 + 56);
    else
      v13 = -1;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Host configuration complete\n", v13);
  }
}
