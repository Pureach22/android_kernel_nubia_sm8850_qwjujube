__int64 __fastcall htc_ce_tasklet_debug_dump(__int64 *a1)
{
  __int64 result; // x0

  result = *a1;
  if ( result )
    return hif_display_stats(result);
  return result;
}
