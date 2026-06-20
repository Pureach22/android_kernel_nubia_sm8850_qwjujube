__int64 __fastcall gen7_hwsched_preempt_count_get(__int64 a1)
{
  if ( *(_DWORD *)(a1 + 11120) == 2 )
    return gen7_hwsched_hfi_get_value((_QWORD *)a1, 120);
  else
    return 0;
}
