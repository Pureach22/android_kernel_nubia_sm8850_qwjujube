__int64 sub_9F18()
{
  __int64 v0; // x10

  if ( (v0 & 0x800000000000LL) == 0 )
    JUMPOUT(0xDC14);
  return msm_geni_serial_config_port();
}
