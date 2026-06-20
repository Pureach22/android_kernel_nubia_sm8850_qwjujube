__int64 sub_64D438()
{
  __asm { PRFM            #0x12, unk_706E40 }
  return extract_twt_session_stats_event_tlv();
}
