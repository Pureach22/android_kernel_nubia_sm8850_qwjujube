const char *__fastcall ieee80211_conn_mode_str(unsigned int a1)
{
  if ( a1 < 6 )
    return ieee80211_conn_mode_str_modes[a1];
  __break(0x800u);
  return "<out of range>";
}
