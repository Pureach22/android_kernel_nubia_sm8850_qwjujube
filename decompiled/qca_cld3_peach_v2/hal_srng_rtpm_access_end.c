__int64 __fastcall hal_srng_rtpm_access_end(
        __int64 *a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x8
  __int64 result; // x0
  __int64 v16; // x8
  __int64 v17; // x8
  unsigned __int64 v24; // x9
  unsigned __int64 v27; // x9

  if ( !a2 )
    return qdf_trace_msg(
             0x38u,
             2u,
             "%s: Error: Invalid hal_ring\n",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "hal_srng_rtpm_access_end");
  if ( !(unsigned int)hif_rtpm_get(0, a3) )
  {
    if ( (unsigned int)hif_system_pm_state_check(*a1) )
    {
      v16 = *(_QWORD *)(a2 + 88);
      if ( (v16 & 1) != 0 )
      {
        *(_QWORD *)(a2 + 88) = v16 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a2 + 80);
      }
      else
      {
        raw_spin_unlock(a2 + 80);
      }
      _X8 = (unsigned __int64 *)(a2 + 176);
      __asm { PRFM            #0x11, [X8] }
      do
        v27 = __ldxr(_X8);
      while ( __stxr(v27 | 2, _X8) );
      ++*(_DWORD *)(a2 + 168);
      return hif_rtpm_put(4, a3);
    }
    if ( (*(_DWORD *)(a2 + 76) & 0x80000000) != 0 )
    {
      **(_DWORD **)(a2 + 144) = *(_DWORD *)(a2 + 120);
      v17 = *(_QWORD *)(a2 + 88);
      if ( (v17 & 1) == 0 )
        goto LABEL_10;
    }
    else
    {
      hal_delayed_reg_write((__int64)a1, (unsigned __int8 *)a2, *(_QWORD *)(a2 + 144), *(_DWORD *)(a2 + 120));
      v17 = *(_QWORD *)(a2 + 88);
      if ( (v17 & 1) == 0 )
      {
LABEL_10:
        raw_spin_unlock(a2 + 80);
        return hif_rtpm_put(4, a3);
      }
    }
    *(_QWORD *)(a2 + 88) = v17 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a2 + 80);
    return hif_rtpm_put(4, a3);
  }
  v14 = *(_QWORD *)(a2 + 88);
  if ( (v14 & 1) != 0 )
  {
    *(_QWORD *)(a2 + 88) = v14 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a2 + 80);
  }
  else
  {
    result = raw_spin_unlock(a2 + 80);
  }
  _X8 = (unsigned __int64 *)(a2 + 176);
  __asm { PRFM            #0x11, [X8] }
  do
    v24 = __ldxr(_X8);
  while ( __stxr(v24 | 2, _X8) );
  ++*(_DWORD *)(a2 + 168);
  return result;
}
