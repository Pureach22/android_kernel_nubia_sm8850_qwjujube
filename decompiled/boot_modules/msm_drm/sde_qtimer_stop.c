size_t __fastcall sde_qtimer_stop(__int64 a1)
{
  int v1; // w6
  int v2; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  writel_relaxed_8(2u, (unsigned int *)(*(_QWORD *)(a1 + 8) + 44LL));
  return sde_evtlog_log(sde_dbg_base_evtlog, "sde_qtimer_stop", 180, -1, 0, -1059143953, v1, v2, vars0);
}
