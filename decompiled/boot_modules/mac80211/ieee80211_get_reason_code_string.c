const char *__fastcall ieee80211_get_reason_code_string(__int16 a1)
{
  if ( (unsigned __int16)(a1 - 1) > 0x41u )
    return "<unknown>";
  else
    return off_C0608[(unsigned __int16)(a1 - 1)];
}
