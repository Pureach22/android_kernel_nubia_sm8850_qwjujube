__int64 __fastcall pld_pcie_schedule_recovery_work(__int64 a1, int a2)
{
  __int64 v2; // x1

  if ( a2 == 1 )
    v2 = 1;
  else
    v2 = 4 * (unsigned int)(a2 == 2);
  return cnss_schedule_recovery(a1, v2);
}
