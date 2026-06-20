__int64 __fastcall kgsl_hwlock(_DWORD *a1)
{
  __int64 v1; // x10

  v1 = jiffies;
  a1[1] = 1;
  __dsb(0xEu);
  a1[2] = 0;
  __dsb(0xFu);
  do
  {
    if ( !*a1 || a1[2] )
      return 0;
    __yield();
    __dsb(0xDu);
  }
  while ( v1 + 250 - jiffies >= 0 );
  if ( !*a1 || a1[2] )
    return 0;
  return 4294967280LL;
}
