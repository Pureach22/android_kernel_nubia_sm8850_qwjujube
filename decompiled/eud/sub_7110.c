__int64 sub_7110()
{
  __int64 v0; // x10

  if ( (v0 & 0x800000000000LL) == 0 )
    JUMPOUT(0xAE0C);
  return eud_config_port();
}
