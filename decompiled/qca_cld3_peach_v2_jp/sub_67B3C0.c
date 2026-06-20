__int64 __fastcall sub_67B3C0(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int128 *v3; // x18

  __ldaxp(v3);
  return wmi_unified_set_mcc_channel_time_latency_cmd(a1, a2, a3);
}
