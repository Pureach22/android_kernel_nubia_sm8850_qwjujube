__int64 __fastcall hal_srng_access_end(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x8

  if ( !a2 )
    return qdf_trace_msg(
             0x38u,
             2u,
             "%s: Error: Invalid hal_ring\n",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "hal_srng_access_end");
  if ( (*(_DWORD *)(a2 + 76) & 0x80000000) != 0 )
  {
    **(_DWORD **)(a2 + 144) = *(_DWORD *)(a2 + 120);
    v11 = *(_QWORD *)(a2 + 88);
    if ( (v11 & 1) == 0 )
      return raw_spin_unlock(a2 + 80);
LABEL_7:
    *(_QWORD *)(a2 + 88) = v11 & 0xFFFFFFFFFFFFFFFELL;
    return raw_spin_unlock_bh(a2 + 80);
  }
  hal_delayed_reg_write(a1, a2, *(_QWORD *)(a2 + 144), *(unsigned int *)(a2 + 120));
  v11 = *(_QWORD *)(a2 + 88);
  if ( (v11 & 1) != 0 )
    goto LABEL_7;
  return raw_spin_unlock(a2 + 80);
}
