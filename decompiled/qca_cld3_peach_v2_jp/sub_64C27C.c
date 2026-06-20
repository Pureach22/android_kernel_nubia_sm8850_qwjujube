__int64 __fastcall sub_64C27C(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { PRFM            #0x12, unk_705C84 }
  return wmi_extract_twt_session_stats_event(a1, a2, a3);
}
