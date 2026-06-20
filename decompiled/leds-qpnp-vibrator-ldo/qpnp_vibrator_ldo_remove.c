__int64 __fastcall qpnp_vibrator_ldo_remove(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19

  v1 = *(_QWORD *)(result + 168);
  v2 = result;
  if ( (*(_BYTE *)(v1 + 633) & 1) == 0 )
  {
    hrtimer_cancel(v1 + 504);
    result = cancel_work_sync(v1 + 568);
  }
  *(_QWORD *)(v2 + 168) = 0;
  return result;
}
