__int64 __fastcall sub_3BD3D4(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { PRFM            #0x1C, loc_48ED80 }
  return pe_find_session_by_peer_sta(a1, a2, a3);
}
