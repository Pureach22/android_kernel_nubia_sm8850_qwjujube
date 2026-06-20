__int64 sub_6676F0()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return wifi_pos_get_rsta_sec_ltf_cap();
}
