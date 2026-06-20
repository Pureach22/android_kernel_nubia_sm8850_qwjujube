__int64 __fastcall tmc_etr_byte_cntr_stop(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    mutex_lock(result + 312);
    *(_QWORD *)(v1 + 408) = tmc_get_rwp_offset(*(_QWORD *)(v1 + 368));
    *(_WORD *)(v1 + 144) = 0;
    *(_DWORD *)(v1 + 160) = 0;
    _wake_up(v1 + 168, 3, 1, 0);
    coresight_csr_set_byte_cntr(*(_QWORD *)(v1 + 360), *(unsigned int *)(v1 + 392), 0);
    return mutex_unlock(v1 + 312);
  }
  return result;
}
