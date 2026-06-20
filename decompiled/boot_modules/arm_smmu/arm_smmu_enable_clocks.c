__int64 __fastcall arm_smmu_enable_clocks(__int64 a1)
{
  __int64 v2; // x20
  __int64 i; // x21
  unsigned int v4; // w0
  unsigned int v6; // w22
  __int64 v7; // x20

  if ( *(int *)(a1 + 16) < 1 )
    return 0;
  v2 = 0;
  for ( i = 8; ; i -= 8 )
  {
    v4 = clk_enable(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8 * v2));
    if ( v4 )
      break;
    if ( ++v2 >= *(int *)(a1 + 16) )
      return 0;
  }
  v6 = v4;
  dev_err(*(_QWORD *)a1, "Couldn't enable clock #%d\n", v2);
  if ( (_DWORD)v2 )
  {
    v7 = -i;
    do
    {
      clk_disable(*(_QWORD *)(*(_QWORD *)(a1 + 8) + v7));
      v7 -= 8;
    }
    while ( v7 != -8 );
  }
  return v6;
}
