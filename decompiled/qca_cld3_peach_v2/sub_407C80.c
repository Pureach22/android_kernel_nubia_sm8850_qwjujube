__int64 __fastcall sub_407C80(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { PRFM            #0x1C, loc_4D962C }
  return pe_find_session_by_bssid(a1, a2, a3);
}
