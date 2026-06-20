__int64 __fastcall htc_can_suspend_link(__int64 *a1)
{
  __int64 v1; // x0

  v1 = *a1;
  if ( v1 )
    LOBYTE(v1) = hif_can_suspend_link(v1);
  return v1 & 1;
}
