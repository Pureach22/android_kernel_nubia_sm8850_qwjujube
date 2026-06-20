__int64 __fastcall sub_370A8(__int64 a1, __int64 a2, __int64 a3)
{
  if ( (a3 & 0x1000000000000LL) != 0 )
    JUMPOUT(0x302B0);
  return cvp_create_pkt_cmd_session_send();
}
