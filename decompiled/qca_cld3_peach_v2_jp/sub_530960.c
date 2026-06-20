__int64 __fastcall sub_530960(__int64 a1, __int64 a2)
{
  __int64 v2; // x30

  if ( !v2 )
    JUMPOUT(0x4D7754);
  return ucfg_mc_cp_stats_get_channel_status(a1, a2);
}
