__int64 __fastcall lpi_pinctrl_suspend(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x20

  if ( (*(_WORD *)(a1 + 488) & 7) != 0 || *(_DWORD *)(a1 + 500) != 2 )
  {
    v2 = *(_QWORD *)(a1 + 152);
    v3 = *(_QWORD *)(v2 + 648);
    if ( v3 || (v3 = *(_QWORD *)(v2 + 656)) != 0 )
    {
      mutex_lock(v2 + 720);
      if ( *(_BYTE *)(v2 + 712) == 1 )
      {
        digital_cdc_rsc_mgr_hw_vote_disable(v3, a1);
        *(_BYTE *)(v2 + 712) = 0;
      }
      mutex_unlock(v2 + 720);
    }
    _pm_runtime_disable(a1, 1);
    _pm_runtime_set_status(a1, 2);
    pm_runtime_enable(a1);
  }
  return 0;
}
