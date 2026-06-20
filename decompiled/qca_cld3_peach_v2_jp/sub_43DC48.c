__int64 sub_43DC48()
{
  __int64 v0; // x24

  if ( (v0 & 0x40000000000000LL) != 0 )
    JUMPOUT(0x443EE8);
  return sme_test_config_twt_terminate();
}
