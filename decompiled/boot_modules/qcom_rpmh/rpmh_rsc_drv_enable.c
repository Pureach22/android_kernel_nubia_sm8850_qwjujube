__int64 __fastcall rpmh_rsc_drv_enable(__int64 a1, char a2)
{
  unsigned int v4; // w20
  unsigned int v5; // w22
  unsigned int v6; // w23
  int v7; // w22
  char v8; // w8

  raw_spin_lock(a1 + 1120);
  v4 = a2 & 1;
  if ( (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24)
                                                  + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 88LL))) == v4 )
  {
    v5 = -22;
  }
  else if ( (a2 & 1) != 0 )
  {
    v5 = rpmh_flush(a1 + 1152, 0);
    if ( !v5 )
    {
      writel_relaxed(v4, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 88LL)));
      writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 80LL)));
      rpmh_rsc_is_tcs_completed((_QWORD *)a1, 0);
    }
  }
  else
  {
    if ( *(_DWORD *)(a1 + 52) == 1 )
    {
      v6 = 0;
    }
    else
    {
      do
        v7 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 80LL)));
      while ( (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24)
                                                         + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 84LL))) != v7 );
      v8 = v7;
      if ( (v7 & 1) != 0 )
      {
        v6 = 1;
      }
      else
      {
        v6 = 0;
        v5 = 0;
        if ( (v8 & 2) == 0 )
          goto LABEL_15;
      }
    }
    v5 = rpmh_flush(a1 + 1152, v6);
    if ( !v5 )
    {
      writel_relaxed(1 << v6, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 80LL)));
      rpmh_rsc_is_tcs_completed((_QWORD *)a1, v6);
      writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 80LL)));
      writel_relaxed(v4, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 88LL)));
    }
  }
LABEL_15:
  raw_spin_unlock(a1 + 1120);
  ipc_log_string(*(_QWORD *)(a1 + 1672), "drv enable: %d ret: %d", v4, v5);
  return v5;
}
