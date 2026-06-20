__int64 __fastcall adc5_gen3_freeze(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v3; // w21

  v1 = *(_QWORD *)(a1 + 152);
  mutex_lock(v1 + 96);
  if ( *(_DWORD *)(v1 + 36) )
  {
    v3 = 0;
    do
      devm_free_irq(a1, *(unsigned int *)(*(_QWORD *)(v1 + 24) + 24LL * (int)v3++ + 16), v1);
    while ( v3 < *(_DWORD *)(v1 + 36) );
  }
  mutex_unlock(v1 + 96);
  return 0;
}
