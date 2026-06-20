__int64 __fastcall stm_disable(__int64 result)
{
  __int64 *v1; // x20
  __int64 v2; // x19
  __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x9

  v1 = *(__int64 **)(*(_QWORD *)(result + 152) + 152LL);
  if ( (unsigned int)*(_QWORD *)(result + 968) == 1 )
  {
    v2 = result;
    raw_spin_lock(v1 + 4);
    *(_DWORD *)(*v1 + 4016) = -978530731;
    __dsb(0xFu);
    *(_DWORD *)(*v1 + 3712) &= ~1u;
    v3 = *v1;
    __dsb(0xFu);
    *(_DWORD *)(v3 + 4016) = 0;
    *(_DWORD *)(*v1 + 4016) = -978530731;
    __dsb(0xFu);
    *(_DWORD *)(*v1 + 3584) = 0;
    *(_DWORD *)(*v1 + 3696) = 0;
    v4 = *v1;
    __dsb(0xFu);
    *(_DWORD *)(v4 + 4016) = 0;
    if ( *((_DWORD *)v1 + 41) )
    {
      *(_DWORD *)(*v1 + 4016) = -978530731;
      __dsb(0xFu);
      *(_DWORD *)(*v1 + 3428) = 0;
      *(_DWORD *)(*v1 + 3328) = 0;
      *(_DWORD *)(*v1 + 3360) = 0;
      v5 = *v1;
      __dsb(0xFu);
      *(_DWORD *)(v5 + 4016) = 0;
    }
    raw_spin_unlock(v1 + 4);
    coresight_timeout(v2 + 32, 3712, 23, 0);
    _pm_runtime_idle(*(_QWORD *)(v2 + 152), 4);
    result = coresight_csr_set_etr_atid(v2, *((unsigned __int8 *)v1 + 144), 0, 0);
    if ( *((_BYTE *)v1 + 176) == 1 )
      result = coresight_trace_id_free_reserved_id(*((unsigned __int8 *)v1 + 144));
    *(_QWORD *)(v2 + 968) = 0;
  }
  return result;
}
