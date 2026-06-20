__int64 __fastcall wlan_hdd_get_client_id_bitmap(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0

  v1 = a1 + 49152;
  if ( *(_BYTE *)(a1 + 52112) == 1 )
    result = 1LL << *(_DWORD *)(a1 + 52104);
  else
    result = 0;
  if ( *(_BYTE *)(v1 + 2976) == 1 )
    result = (unsigned int)result | (unsigned int)(1LL << *(_DWORD *)(v1 + 2968));
  if ( *(_BYTE *)(v1 + 2992) == 1 )
    result = (unsigned int)result | (unsigned int)(1LL << *(_DWORD *)(v1 + 2984));
  if ( *(_BYTE *)(v1 + 3008) == 1 )
    result = (unsigned int)result | (unsigned int)(1LL << *(_DWORD *)(v1 + 3000));
  if ( *(_BYTE *)(v1 + 3024) == 1 )
    return (unsigned int)result | (unsigned int)(1LL << *(_DWORD *)(v1 + 3016));
  return result;
}
