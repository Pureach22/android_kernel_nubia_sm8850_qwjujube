__int64 __fastcall sub_605DC8(__int64 a1, __int64 a2)
{
  __int64 v2; // x30

  if ( (v2 & 0x2000000000000LL) != 0 )
    JUMPOUT(0x6063FC);
  return wmi_unified_send_peer_cfr_capture_cmd(a1, a2);
}
