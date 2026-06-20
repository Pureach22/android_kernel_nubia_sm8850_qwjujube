__int64 sub_5437F0()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x54A7C4);
  return ucfg_coex_send_logging_config();
}
