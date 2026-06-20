__int64 __fastcall dp_pll_driver_remove(__int64 a1)
{
  int *v1; // x20
  int v3; // w8
  __int64 result; // x0

  v1 = *(int **)(a1 + 168);
  v3 = *v1;
  if ( (unsigned int)*v1 <= 7 )
  {
    if ( ((1 << v3) & 0x38) != 0 )
    {
      dp_pll_clock_unregister_4nm(*(_QWORD *)(a1 + 168));
    }
    else if ( ((1 << v3) & 0x46) != 0 )
    {
      dp_pll_clock_unregister_5nm(*(_QWORD *)(a1 + 168));
    }
    else if ( v3 == 7 )
    {
      dp_pll_clock_unregister_3nm(*(_QWORD *)(a1 + 168));
    }
  }
  result = kfree(v1);
  *(_QWORD *)(a1 + 168) = 0;
  return result;
}
