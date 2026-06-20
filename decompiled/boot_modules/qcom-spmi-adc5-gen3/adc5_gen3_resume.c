__int64 __fastcall adc5_gen3_resume(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v3; // w22
  __int64 v4; // x8
  __int64 result; // x0

  if ( pm_suspend_target_state != 3 )
    return 0;
  v1 = *(_QWORD *)(a1 + 152);
  if ( !*(_DWORD *)(v1 + 36) )
    return 0;
  v3 = 0;
  do
  {
    v4 = *(_QWORD *)(v1 + 24) + 24LL * (int)v3;
    result = devm_request_threaded_irq(a1, *(unsigned int *)(v4 + 16), adc5_gen3_isr, 0, 0, *(_QWORD *)(v4 + 8), v1);
    if ( (result & 0x80000000) != 0 )
      break;
    ++v3;
  }
  while ( v3 < *(_DWORD *)(v1 + 36) );
  return result;
}
