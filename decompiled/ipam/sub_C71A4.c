__int64 sub_C71A4()
{
  __int64 v0; // x10

  if ( (v0 & 0x400000000000000LL) != 0 )
    JUMPOUT(0xCC388);
  return ipa3_del_hdr_hpc_usr();
}
