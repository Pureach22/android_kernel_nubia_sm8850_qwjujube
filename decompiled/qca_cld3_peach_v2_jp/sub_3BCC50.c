__int64 __fastcall sub_3BCC50(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { PRFM            #0x1C, loc_48E5F8+4 }
  return pe_find_session_by_bssid(a1, a2, a3);
}
