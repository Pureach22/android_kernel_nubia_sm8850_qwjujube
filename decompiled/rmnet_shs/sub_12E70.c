__int64 __fastcall sub_12E70(__int64 a1)
{
  __int64 v1; // x24

  if ( (v1 & 0x8000000000LL) != 0 )
    JUMPOUT(0x11E1C);
  return rmnet_shs_genl_msg_direct_send_to_userspace(a1);
}
