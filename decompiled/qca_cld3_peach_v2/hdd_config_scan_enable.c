__int64 __fastcall hdd_config_scan_enable(__int64 a1, __int64 a2)
{
  __int64 v2; // x0

  v2 = **(_QWORD **)(*(_QWORD *)a1 + 24LL);
  if ( *(_BYTE *)(a2 + 4) )
    ucfg_scan_psoc_set_enable(v2, 4);
  else
    ucfg_scan_psoc_set_disable(v2, 4);
  return 0;
}
