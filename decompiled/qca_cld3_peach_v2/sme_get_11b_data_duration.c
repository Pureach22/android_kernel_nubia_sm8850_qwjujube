__int64 __fastcall sme_get_11b_data_duration(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = ucfg_mc_cp_stats_get_channel_status(*(_QWORD *)(a1 + 21632), a2);
  if ( result )
    return *(unsigned int *)(result + 32);
  return result;
}
