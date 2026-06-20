__int64 __fastcall mon_set_throttle_adj(__int64 a1, unsigned int a2)
{
  if ( a2 > 0x1F )
    return 4294967274LL;
  *(_DWORD *)(a1 + 260) = a2 << 16;
  return 0;
}
