__int64 __fastcall rmnet_vnd_change_mtu(__int64 a1, unsigned int a2)
{
  if ( a2 > 0x4000 )
    return 4294967274LL;
  *(_DWORD *)(a1 + 56) = a2;
  return 0;
}
