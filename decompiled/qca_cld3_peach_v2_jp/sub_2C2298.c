__int64 sub_2C2298()
{
  __int64 v0; // x10

  if ( (v0 & 0x2000000000000000LL) != 0 )
    JUMPOUT(0x2BB64C);
  return cm_free_join_req();
}
