__int64 __fastcall sub_408410(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { PRFM            #0x1C, loc_4D9DBC }
  return pe_find_session_by_peer_sta(a1, a2, a3);
}
