__int64 __fastcall acd_calibrate_set(__int64 a1, unsigned int a2)
{
  __int64 v4; // x21
  unsigned int v5; // w22

  v4 = to_gen7_gmu();
  rt_mutex_lock(a1 + 11088);
  v5 = adreno_active_count_get(a1);
  if ( !v5 )
  {
    v5 = gen7_hfi_send_set_value(a1, 116, 78, a2);
    if ( !v5 )
      *(_DWORD *)(v4 + 1228) = a2;
    adreno_active_count_put(a1);
  }
  rt_mutex_unlock(a1 + 11088);
  return v5;
}
