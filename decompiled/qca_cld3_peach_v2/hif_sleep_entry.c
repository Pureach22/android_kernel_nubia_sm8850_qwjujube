__int64 __fastcall hif_sleep_entry(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  int v3; // w8
  unsigned int v4; // w0
  __int64 v5; // x22
  unsigned int multiplier; // w0

  if ( (*(_BYTE *)(result + 648) & 1) == 0 )
  {
    v1 = result;
    result = hif_is_driver_unloading(result);
    if ( (result & 1) == 0 )
    {
      v2 = raw_spin_lock_irqsave(v1 + 27272);
      v3 = *(unsigned __int8 *)(v1 + 27309);
      *(_QWORD *)(v1 + 27280) = v2;
      if ( v3 == 1 )
      {
        v4 = jiffies_to_msecs(jiffies - *(_QWORD *)(v1 + 27376));
        if ( (*(_BYTE *)(v1 + 27308) & 1) != 0 || v4 < 0x32 )
        {
          timer_delete((timer_t)(v1 + 27312));
          v5 = jiffies;
          multiplier = qdf_timer_get_multiplier();
          *(_QWORD *)(v1 + 27328) = v5 - multiplier + 16LL * multiplier;
          add_timer(v1 + 27312);
        }
        else if ( !*(_DWORD *)(v1 + 684) )
        {
          hif_write32_mb_reg_window(
            v1,
            *(_QWORD *)(v1 + 40)
          + *(_DWORD *)(*(_QWORD *)(v1 + 632) + 160LL)
          + *(_DWORD *)(*(_QWORD *)(v1 + 632) + 168LL),
            *(_DWORD *)(*(_QWORD *)(v1 + 632) + 164LL));
          *(_BYTE *)(v1 + 27309) = 0;
        }
      }
      return raw_spin_unlock_irqrestore(v1 + 27272, *(_QWORD *)(v1 + 27280));
    }
  }
  return result;
}
