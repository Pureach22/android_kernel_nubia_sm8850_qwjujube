void __fastcall i3c_setup_go_tre(__int64 a1, __int64 a2, int a3, char a4, char a5)
{
  unsigned int v5; // w9
  int v9; // w10
  int *v10; // x11
  int v11; // w23
  int v12; // w27
  int v13; // w28
  int v14; // w24
  int v15; // w25
  int v16; // w26
  int v17; // w14
  int v18; // w10
  int v19; // w11
  int v20; // w13
  int v21; // w9
  int v22; // w8
  int v23; // w8

  v5 = *(_DWORD *)(a2 + 8);
  if ( *(int *)(a1 + 21544) >= 4 )
    v9 = (v5 << 24) & 0x4000000;
  else
    v9 = 0x4000000;
  if ( (a5 & 1) != 0 )
  {
    if ( (unsigned int)(a3 % 448) >= 0x1C0 )
    {
      __break(0x5512u);
      geni_i3c_err(a1, a2);
      return;
    }
    v10 = (int *)(a1 + 4LL * (unsigned int)(a3 % 448) + 10152);
  }
  else
  {
    v10 = (int *)(a1 + 21276);
  }
  v11 = (v5 >> 8) & 1;
  v12 = BYTE2(v5);
  v13 = (unsigned __int16)v5 >> 9;
  v14 = (v5 >> 26) & 1;
  v15 = (v5 >> 25) & 1;
  v16 = HIBYTE(v5) & 1;
  v17 = v9 | (v5 >> 26 << 31) | (BYTE2(v5) << 16) | (v13 << 8);
  v18 = *v10;
  v19 = *(_DWORD *)(a1 + 21272);
  v20 = *(_DWORD *)(a2 + 4) | v17;
  v21 = 2099456;
  *(_DWORD *)(a1 + 2868) = (4 * v11) | (2 * v16) | v15;
  *(_DWORD *)(a1 + 2864) = v20;
  *(_DWORD *)(a1 + 2872) = v18;
  if ( v19 == 1 )
  {
    if ( *(_BYTE *)(a1 + 21640) == 1 )
    {
      if ( *(_DWORD *)(a1 + 21284) - 1 == a3 )
        v21 = 2099200;
      else
        v21 = 2099456;
    }
  }
  else
  {
    if ( (a4 & 1) != 0 )
      v22 = -1279;
    else
      v22 = -2303;
    v23 = v22 + 2099456;
    v21 = 2097664;
    if ( v18 )
      v21 = v23;
  }
  *(_DWORD *)(a1 + 2876) = v21;
  ipc_log_string(
    *(_QWORD *)(a1 + 2528),
    "%s cmd:0x%x param0x%x ccc:0x%x addr:0x%x\n",
    "i3c_setup_go_tre",
    *(_DWORD *)(a2 + 4),
    *(_DWORD *)(a2 + 8),
    v12,
    v13);
  if ( *(_QWORD *)(a1 + 8) )
    i3c_trace_log();
  ipc_log_string(
    *(_QWORD *)(a1 + 2528),
    "%s:use_7e:%d nack_ibi:%d cont_mod:%d, bypass addrspace:%d idx:%d gsi_bei:%d\n",
    "i3c_setup_go_tre",
    v15,
    v16,
    v11,
    v14,
    a3,
    a4 & 1);
  if ( *(_QWORD *)(a1 + 8) )
    i3c_trace_log();
  ipc_log_string(
    *(_QWORD *)(a1 + 2528),
    "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
    "i3c_setup_go_tre",
    *(_DWORD *)(a1 + 2864),
    *(_DWORD *)(a1 + 2868),
    *(_DWORD *)(a1 + 2872),
    *(_DWORD *)(a1 + 2876));
  if ( *(_QWORD *)(a1 + 8) )
    i3c_trace_log();
}
