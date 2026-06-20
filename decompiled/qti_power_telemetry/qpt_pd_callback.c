__int64 __fastcall qpt_pd_callback(__int64 a1, __int64 a2)
{
  _QWORD *i; // x10

  if ( !*(_DWORD *)(a1 - 160) )
  {
    if ( a2 == 3 )
    {
      if ( (*(_BYTE *)(a1 - 162) & 1) == 0 )
      {
        if ( (ktime_get() - *(_QWORD *)(a1 - 104)) / 1000000 > qpt_update_interval_ms )
        {
          for ( i = *(_QWORD **)(a1 - 64); i != (_QWORD *)(a1 - 64); i = (_QWORD *)*i )
            i[9] = 0;
        }
        enable_irq(*(unsigned int *)(a1 - 232));
        *(_BYTE *)(a1 - 162) = 1;
      }
    }
    else if ( a2 == 1 && *(_BYTE *)(a1 - 162) == 1 )
    {
      disable_irq_nosync(*(unsigned int *)(a1 - 232));
      *(_BYTE *)(a1 - 162) = 0;
    }
  }
  return 1;
}
