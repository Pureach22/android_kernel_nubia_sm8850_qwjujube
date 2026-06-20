__int64 __fastcall ieee80211_get_8023_tunnel_proto(__int64 a1, _WORD *a2)
{
  int v2; // w9
  int v3; // w8
  int v5; // w10

  v2 = *(unsigned __int16 *)(a1 + 4);
  v3 = *(_DWORD *)a1 ^ 0x3AAAA;
  if ( v3 | v2 || (v5 = *(unsigned __int16 *)(a1 + 6), v5 == 62336) || v5 == 14209 )
  {
    if ( v3 | v2 ^ 0xF800 )
      return 0;
    LOWORD(v5) = *(_WORD *)(a1 + 6);
  }
  *a2 = v5;
  return 1;
}
