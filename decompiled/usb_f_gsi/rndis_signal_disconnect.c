__int64 __fastcall rndis_signal_disconnect(__int64 a1)
{
  int v1; // w8
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  void (__fastcall *v6)(_QWORD); // x8

  v1 = *(_DWORD *)(a1 + 8);
  *(_DWORD *)(a1 + 20) = 1;
  if ( !v1 )
    return 4294966772LL;
  v3 = rndis_add_response();
  if ( !v3 )
    return 4294967284LL;
  v4 = *(_QWORD *)(v3 + 16);
  *(_QWORD *)v4 = 0x1400000007LL;
  *(_QWORD *)(v4 + 8) = 1073807372;
  *(_DWORD *)(v4 + 16) = 0;
  v6 = *(void (__fastcall **)(_QWORD))(a1 + 64);
  v5 = *(_QWORD *)(a1 + 72);
  if ( *((_DWORD *)v6 - 1) != 251140989 )
    __break(0x8228u);
  v6(v5);
  return 0;
}
