__int64 __fastcall ieee80211_get_vif_queues(__int64 a1, unsigned __int8 *a2)
{
  int v3; // w9
  int v4; // w11
  int v5; // w13
  int v6; // w14
  int v7; // w8
  __int64 v8; // x12
  bool v9; // zf
  __int64 v10; // x9
  __int64 v11; // x11
  __int64 v12; // x13
  __int64 v13; // x10
  unsigned int v14; // w8
  int v15; // w9

  if ( !a2 || (*(_QWORD *)(a1 + 96) & 0x40000) == 0 )
    return (unsigned int)~(-1 << *(_WORD *)(a1 + 128));
  v3 = a2[5850];
  v4 = a2[5851];
  v5 = a2[5852];
  v6 = a2[5853];
  v7 = a2[5849];
  v8 = 1LL << v3;
  v9 = v3 == 255;
  v10 = 1LL << v4;
  if ( v9 )
    LODWORD(v8) = 0;
  v9 = v4 == 255;
  v11 = 1LL << v5;
  if ( v9 )
    LODWORD(v10) = 0;
  v9 = v5 == 255;
  v12 = 1LL << v6;
  if ( v9 )
    LODWORD(v11) = 0;
  v13 = 1LL << v7;
  if ( v6 == 255 )
    LODWORD(v12) = 0;
  v9 = v7 == 255;
  v14 = v12 | v11 | v10 | v8;
  if ( v9 )
    v15 = 0;
  else
    v15 = v13;
  return v15 | v14;
}
