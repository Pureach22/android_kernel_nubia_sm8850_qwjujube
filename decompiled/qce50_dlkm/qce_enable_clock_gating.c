__int64 __fastcall qce_enable_clock_gating(__int64 result, __int64 a2, __int64 a3)
{
  unsigned int v3; // w8

  if ( *(_BYTE *)(result + 70252) == 1 )
    return printk(&unk_15E51, "qce_enable_clock_gating", a3);
  v3 = *(_DWORD *)(result + 408);
  if ( v3 == 5 )
  {
    if ( *(_DWORD *)(result + 404) <= 8u )
      return result;
  }
  else if ( v3 < 6 )
  {
    return result;
  }
  return writel();
}
