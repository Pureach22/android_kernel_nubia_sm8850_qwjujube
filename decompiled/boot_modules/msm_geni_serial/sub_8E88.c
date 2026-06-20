__int64 sub_8E88()
{
  __int64 v0; // x10

  if ( (v0 & 0x800000000000LL) == 0 )
    JUMPOUT(0xCB84);
  return msm_geni_serial_break_ctl();
}
