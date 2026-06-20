__int64 sub_48FC14()
{
  __int64 v0; // x25

  if ( (v0 & 0x20000000000LL) != 0 )
    JUMPOUT(0x488EB8);
  return sme_set_wisa_params();
}
