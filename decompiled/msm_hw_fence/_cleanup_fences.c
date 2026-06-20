__int64 __fastcall cleanup_fences(unsigned int a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x21

  if ( (a1 & 0x80000000) == 0 )
  {
    v5 = 8LL * a1;
    do
    {
      kfree(*(_QWORD *)(a3 + v5));
      kfree(*(_QWORD *)(a2 + v5));
      v5 -= 8;
    }
    while ( v5 != -8 );
  }
  kfree(a3);
  return kfree(a2);
}
