void __fastcall i3c_setup_cfg0_tre(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x21
  unsigned int *v7; // x8
  unsigned int v8; // w20
  __int64 v9; // x3
  int v10; // w8
  __int64 v11; // x0
  int v12; // w8

  v5 = *(_QWORD *)(a1 + 21304);
  if ( (a4 & 1) != 0 )
  {
    if ( (unsigned int)((int)a2 % 448) >= 0x1C0 )
    {
      __break(0x5512u);
      i3c_setup_go_tre(a1, a2, a3, a4, a5);
      return;
    }
    v7 = (unsigned int *)(a1 + 4LL * (unsigned int)((int)a2 % 448) + 10152);
  }
  else
  {
    v7 = (unsigned int *)(a1 + 21276);
  }
  v8 = *v7;
  v9 = *(unsigned int *)(a1 + 21252);
  if ( *(_BYTE *)(a1 + 21652) == 1 )
  {
    *(_QWORD *)(a1 + 2880) = 51511816;
    v10 = 1;
  }
  else
  {
    *(_DWORD *)(a1 + 2880) = (*(unsigned __int8 *)(v5 + 9) << 8)
                           | (*(_DWORD *)(v5 + 16) << 16)
                           | *(unsigned __int8 *)(v5 + 10)
                           | 0x3000000;
    *(_DWORD *)(a1 + 2884) = *(unsigned __int16 *)(v5 + 11);
    v10 = *(unsigned __int8 *)(v5 + 8) | ((_DWORD)v9 << 16);
  }
  *(_DWORD *)(a1 + 2888) = v10;
  v11 = *(_QWORD *)(a1 + 2528);
  if ( (a3 & 1) != 0 )
    v12 = 2229249;
  else
    v12 = 2228225;
  *(_DWORD *)(a1 + 2892) = v12;
  ipc_log_string(v11, "%s: dfs:%d div:%d len:%d\n", "i3c_setup_cfg0_tre", v9, *(unsigned __int8 *)(v5 + 8), v8);
  if ( *(_QWORD *)(a1 + 8) )
    i3c_trace_log();
  ipc_log_string(
    *(_QWORD *)(a1 + 2528),
    "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
    "i3c_setup_cfg0_tre",
    *(_DWORD *)(a1 + 2880),
    *(_DWORD *)(a1 + 2884),
    *(_DWORD *)(a1 + 2888),
    *(_DWORD *)(a1 + 2892));
  if ( *(_QWORD *)(a1 + 8) )
    i3c_trace_log();
}
