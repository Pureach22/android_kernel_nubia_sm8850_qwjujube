__int64 __fastcall dp_tx_ring_access_end(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  __int64 v12; // x8

  if ( !a3 )
  {
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
               "hal_srng_access_end");
    if ( (*(_DWORD *)(a2 + 76) & 0x80000000) != 0 )
    {
      **(_DWORD **)(a2 + 144) = *(_DWORD *)(a2 + 120);
      v12 = *(_QWORD *)(a2 + 88);
      if ( (v12 & 1) == 0 )
        return raw_spin_unlock(a2 + 80);
LABEL_9:
      *(_QWORD *)(a2 + 88) = v12 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(a2 + 80);
    }
    v11 = a2;
    hal_delayed_reg_write(*(_QWORD *)(a1 + 1128), a2, *(_QWORD *)(a2 + 144), *(unsigned int *)(a2 + 120));
    a2 = v11;
  }
  v12 = *(_QWORD *)(a2 + 88);
  if ( (v12 & 1) != 0 )
    goto LABEL_9;
  return raw_spin_unlock(a2 + 80);
}
