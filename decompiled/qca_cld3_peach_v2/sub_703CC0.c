__int64 sub_703CC0()
{
  __asm { PRFM            #0x12, unk_7BD6C8 }
  return extract_twt_session_stats_event_tlv();
}
