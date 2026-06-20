bool __fastcall _qdf_nbuf_is_mcast_replay(__int64 a1)
{
  int *v2; // x8
  __int64 v3; // x9
  int v4; // w10
  int v5; // w9
  int v6; // w11
  int v7; // w8

  if ( (*(_BYTE *)(a1 + 128) & 7) != 2 )
    return 0;
  v2 = *(int **)(*(_QWORD *)(a1 + 16) + 1008LL);
  v3 = *(_QWORD *)(a1 + 216) + *(unsigned __int16 *)(a1 + 186);
  v4 = *(_DWORD *)(v3 + 6);
  v5 = *(unsigned __int16 *)(v3 + 10);
  v6 = *v2;
  v7 = *((unsigned __int16 *)v2 + 2);
  return v6 == v4 && v7 == v5;
}
