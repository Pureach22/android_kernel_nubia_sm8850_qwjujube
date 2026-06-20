__int64 sub_436D60()
{
  __int64 v0; // x25

  if ( (v0 & 0x20000000000LL) != 0 )
    JUMPOUT(0x430004);
  return sme_set_wisa_params();
}
