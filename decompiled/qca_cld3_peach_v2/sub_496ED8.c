__int64 sub_496ED8()
{
  __int64 v0; // x24

  if ( (v0 & 0x40000000000000LL) != 0 )
    JUMPOUT(0x49D178);
  return sme_test_config_twt_terminate();
}
