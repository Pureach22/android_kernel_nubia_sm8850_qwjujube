__int64 sub_219EFC()
{
  __int64 v0; // x24

  if ( (v0 & 0x400000000LL) != 0 )
    JUMPOUT(0x21D1A8);
  return wmi_unified_update_edca_pifs_param();
}
