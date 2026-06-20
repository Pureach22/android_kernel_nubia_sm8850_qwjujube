__int64 __fastcall st54spi_power_off_for_comm(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0

  v2 = *(_QWORD *)(a1 + 8);
  if ( !v2 )
    v2 = *(_QWORD *)(a1 + 16);
  result = dev_info(v2, "%s\n", "st54spi_power_off_for_comm");
  if ( *(_DWORD *)(a1 + 148) )
  {
    if ( !*(_DWORD *)(a1 + 124) )
    {
      if ( *(_QWORD *)(a1 + 8) )
      {
        raw_spin_lock_irq(a1 + 4);
        v4 = *(_QWORD *)(a1 + 8);
        *(_QWORD *)(a1 + 8) = 0;
        *(_QWORD *)(a1 + 16) = v4;
        raw_spin_unlock_irq(a1 + 4);
      }
      result = usleep_range_state(2000, 4500, 2);
    }
    *(_DWORD *)(a1 + 148) = 0;
  }
  else
  {
    v5 = *(_QWORD *)(a1 + 8);
    if ( !v5 )
      v5 = *(_QWORD *)(a1 + 16);
    return dev_info(v5, "%s - nothing to do\n", "st54spi_power_off_for_comm");
  }
  return result;
}
