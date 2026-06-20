bool __fastcall csr_peer_mac_match_cmd(__int64 a1, char a2, __int64 a3, __int64 a4)
{
  int v4; // w8
  char v6; // w21
  __int64 v7; // x22
  __int64 v8; // x23
  int v9; // w8
  char v10; // w20
  __int64 v11; // x21
  __int64 v12; // x22

  v4 = *(_DWORD *)(a1 + 16);
  if ( v4 == 65537 )
  {
    if ( (unsigned int)(*(_DWORD *)(a1 + 32) - 1) > 1 )
      return 0;
    v6 = a2;
    v7 = a3;
    v8 = a4;
    if ( (csr_peer_match_ser_peer(65537, a2 & 1, a3, a4, a1 + 36, a1 + 42) & 1) != 0 )
      return 1;
    v4 = *(_DWORD *)(a1 + 16);
    a4 = v8;
    a3 = v7;
    a2 = v6;
  }
  if ( v4 == 65538 )
  {
    v9 = *(_DWORD *)(a1 + 32);
    if ( v9 )
    {
      if ( v9 == 1 )
        return (csr_peer_match_ser_peer(*(unsigned int *)(a1 + 16), a2 & 1, a3, a4, a1 + 54, a1 + 60) & 1) != 0;
    }
    else
    {
      v10 = a2;
      v11 = a3;
      v12 = a4;
      if ( (csr_peer_match_ser_peer(65538, a2 & 1, a3, a4, a1 + 54, a1 + 60) & 1) != 0 )
        return 1;
      a4 = v12;
      a3 = v11;
      a2 = v10;
      if ( *(_DWORD *)(a1 + 32) == 1 )
        return (csr_peer_match_ser_peer(*(unsigned int *)(a1 + 16), a2 & 1, a3, a4, a1 + 54, a1 + 60) & 1) != 0;
    }
  }
  return 0;
}
