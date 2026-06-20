__int64 __fastcall wcd9378_enable_clsh(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x8
  __int64 v5; // x20
  unsigned int v6; // w9
  bool v7; // cc
  int v8; // w9

  v3 = *(_QWORD *)(a1 + 40);
  v5 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  v6 = *(_DWORD *)(v5 + 360);
  v7 = v6 > 5;
  v8 = (1 << v6) & 0x36;
  if ( !v7 && v8 != 0 )
    wcd9378_rx_connect_port(v3 - 208, 18, a3 & 3);
  if ( (a3 & 0xC) != 0 )
    return swr_slvdev_datapath_control(*(_QWORD *)(v5 + 56), *(unsigned __int8 *)(*(_QWORD *)(v5 + 56) + 64LL), 0);
  else
    return 0;
}
