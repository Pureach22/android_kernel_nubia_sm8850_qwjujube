__int64 __fastcall iommu_debug_nr_iters_set(__int64 a1, unsigned __int64 a2)
{
  int v2; // w9
  unsigned __int64 v4; // x10
  __int64 result; // x0

  v2 = 10000;
  if ( a2 <= 1 )
    v4 = 1;
  else
    v4 = a2;
  result = 0;
  if ( v4 < 0x2710 )
    v2 = v4;
  *(_DWORD *)(a1 + 144) = v2;
  return result;
}
