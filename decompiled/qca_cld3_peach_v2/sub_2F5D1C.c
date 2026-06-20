__int64 sub_2F5D1C()
{
  __int64 v0; // x10

  if ( (v0 & 0x2000000000000000LL) != 0 )
    JUMPOUT(0x2EF0D0);
  return cm_free_join_req();
}
