__int64 sub_8F24()
{
  __int64 v0; // x10

  if ( (v0 & 0x20000000000LL) == 0 )
    JUMPOUT(0xAD18);
  return swr_driver_register();
}
