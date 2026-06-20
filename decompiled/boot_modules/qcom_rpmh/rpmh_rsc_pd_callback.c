__int64 __fastcall rpmh_rsc_pd_callback(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  int v5; // w21

  if ( *(_DWORD *)(a1 - 36) == 1 )
  {
    v4 = 0;
    if ( a2 )
      return 1;
  }
  else
  {
    do
      v5 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 - 64) + *(unsigned int *)(*(_QWORD *)(a1 + 1576) + 80LL)));
    while ( (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 - 64)
                                                       + *(unsigned int *)(*(_QWORD *)(a1 + 1576) + 84LL))) != v5 );
    if ( (v5 & 1) != 0 )
    {
      v4 = 1;
      if ( a2 )
        return 1;
    }
    else
    {
      if ( (v5 & 2) != 0 )
        v4 = 0;
      else
        v4 = -16;
      if ( a2 )
        return 1;
    }
  }
  if ( (v4 & 0x80000000) != 0 || rpmh_rsc_ctrlr_is_busy(a1 - 88) || (unsigned int)rpmh_flush(a1 + 1064, v4) )
    return 32770;
  return 1;
}
