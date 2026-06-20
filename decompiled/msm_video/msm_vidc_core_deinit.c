__int64 __fastcall msm_vidc_core_deinit(__int64 a1, char a2)
{
  unsigned int v4; // w19

  if ( a1 )
  {
    mutex_lock(a1 + 3856);
    v4 = msm_vidc_core_deinit_locked(a1, a2 & 1);
    mutex_unlock(a1 + 3856);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v4;
}
