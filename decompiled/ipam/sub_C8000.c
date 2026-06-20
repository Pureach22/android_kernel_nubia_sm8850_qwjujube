__int64 sub_C8000()
{
  __int64 v0; // x10

  if ( (v0 & 0x400000000000000LL) != 0 )
    JUMPOUT(0xCD1E4);
  return ipa3_del_hdr_by_user();
}
