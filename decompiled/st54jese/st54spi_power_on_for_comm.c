__int64 __fastcall st54spi_power_on_for_comm(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 8);
  if ( !v2 )
    v2 = *(_QWORD *)(a1 + 16);
  result = dev_info(v2, "%s\n", "st54spi_power_on_for_comm");
  if ( !*(_DWORD *)(a1 + 124) && *(_QWORD *)(a1 + 16) )
  {
    raw_spin_lock_irq(a1 + 4);
    *(_QWORD *)(a1 + 8) = *(_QWORD *)(a1 + 16);
    *(_QWORD *)(a1 + 16) = 0;
    result = raw_spin_unlock_irq(a1 + 4);
  }
  *(_DWORD *)(a1 + 148) = 1;
  return result;
}
