__int64 __fastcall lpi_pinctrl_runtime_suspend(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x20

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v1 + 648);
  if ( v3 || (v3 = *(_QWORD *)(v1 + 656)) != 0 )
  {
    mutex_lock(v1 + 720);
    if ( *(_BYTE *)(v1 + 712) == 1 )
    {
      digital_cdc_rsc_mgr_hw_vote_disable(v3, a1);
      *(_BYTE *)(v1 + 712) = 0;
    }
    mutex_unlock(v1 + 720);
  }
  return 0;
}
