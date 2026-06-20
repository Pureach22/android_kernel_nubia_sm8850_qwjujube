__int64 __fastcall sdhci_msm_setup_pm(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v11; // w9

  _X8 = (unsigned int *)(a1 + 496);
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 + 1, _X8) );
  _pm_runtime_set_status(a1 + 16, 0);
  result = pm_runtime_enable(a1 + 16);
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 128) + 998LL) & 0x20) == 0 )
  {
    pm_runtime_set_autosuspend_delay(a1 + 16, 10);
    return _pm_runtime_use_autosuspend(a1 + 16, 1);
  }
  return result;
}
