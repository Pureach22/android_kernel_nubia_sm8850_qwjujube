__int64 __fastcall qpnp_tm_freeze(__int64 a1)
{
  __int64 v1; // x1

  v1 = *(unsigned int *)(*(_QWORD *)(a1 + 152) + 56LL);
  if ( (int)v1 >= 1 )
    devm_free_irq(a1, v1);
  return 0;
}
