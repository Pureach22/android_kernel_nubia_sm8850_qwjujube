__int64 sub_2F7F5C()
{
  __int64 v0; // x24

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x2FCAEC);
  return cm_disconnect_complete_ind();
}
