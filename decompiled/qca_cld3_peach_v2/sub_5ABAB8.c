__int64 sub_5ABAB8()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x5B2A8C);
  return ucfg_coex_send_logging_config();
}
