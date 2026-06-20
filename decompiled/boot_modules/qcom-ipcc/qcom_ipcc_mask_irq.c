__int64 __fastcall qcom_ipcc_mask_irq(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x9
  unsigned __int16 **v4; // x12
  unsigned __int16 *v5; // x13

  v1 = *(_QWORD *)(a1 + 48);
  v2 = *(_QWORD *)(a1 + 8);
  v3 = *(unsigned int *)(v1 + 176);
  if ( (int)v3 >= 1 )
  {
    v4 = (unsigned __int16 **)(*(_QWORD *)(v1 + 24) + 240LL);
    do
    {
      v5 = *v4;
      if ( !*v4 )
        break;
      if ( __PAIR64__(v5[1], *v5) == __PAIR64__((unsigned __int16)v2, WORD1(v2)) )
      {
        v5[2] = 0;
        return writel(v2, (unsigned int *)(*(_QWORD *)(v1 + 8) + 24LL));
      }
      --v3;
      v4 += 31;
    }
    while ( v3 );
  }
  return writel(v2, (unsigned int *)(*(_QWORD *)(v1 + 8) + 24LL));
}
