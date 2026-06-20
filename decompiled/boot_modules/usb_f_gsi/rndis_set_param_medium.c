__int64 __fastcall rndis_set_param_medium(__int64 a1, int a2, int a3)
{
  if ( !a1 )
    return 0xFFFFFFFFLL;
  *(_DWORD *)(a1 + 12) = a2;
  *(_DWORD *)(a1 + 16) = a3;
  return 0;
}
