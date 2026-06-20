__int64 __fastcall wlan_peer_find_mld_peer_n_get_mac_info(__int64 a1, __int64 a2, __int64 a3)
{
  int *v3; // x20
  __int64 result; // x0
  int v7; // w9
  int v8; // w9

  v3 = (int *)(a2 + 792);
  result = qdf_mem_cmp((const void *)(a2 + 792), (const void *)a3, 6u);
  if ( !(_DWORD)result )
  {
    v7 = *(_DWORD *)(a2 + 48);
    *(_WORD *)(a3 + 10) = *(_WORD *)(a2 + 52);
    *(_DWORD *)(a3 + 6) = v7;
    v8 = *v3;
    *(_WORD *)(a3 + 16) = *((_WORD *)v3 + 2);
    *(_DWORD *)(a3 + 12) = v8;
  }
  return result;
}
