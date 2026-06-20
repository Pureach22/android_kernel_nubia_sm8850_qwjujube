__int64 __fastcall hdd_is_legacy_connection(__int64 a1)
{
  char v2; // w8
  unsigned int v3; // w8

  if ( (unsigned __int16)hdd_get_tdls_connected_peer_count() )
  {
    v2 = 0;
  }
  else
  {
    v3 = *(_DWORD *)(a1 + 680);
    if ( v3 <= 0xD )
      v2 = 0x4Eu >> v3;
    else
      v2 = 0;
  }
  return v2 & 1;
}
