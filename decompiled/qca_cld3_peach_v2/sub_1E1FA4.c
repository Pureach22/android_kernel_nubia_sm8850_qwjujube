__int64 sub_1E1FA4()
{
  __int64 v0; // x24

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x1E6B34);
  return cm_disconnect_rsp();
}
