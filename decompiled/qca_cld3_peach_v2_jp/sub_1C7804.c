__int64 sub_1C7804()
{
  __int64 v0; // x24

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x1CC394);
  return cm_disconnect_rsp();
}
