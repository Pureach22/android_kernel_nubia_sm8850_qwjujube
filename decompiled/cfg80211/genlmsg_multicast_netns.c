__int64 __fastcall genlmsg_multicast_netns(__int64 result, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 v4; // x0
  __int64 v5; // x4
  __int64 v6; // x3

  if ( (unsigned __int8)byte_BF570 <= a3 )
  {
    __break(0x800u);
  }
  else
  {
    v4 = *(_QWORD *)(result + 288);
    v5 = a4;
    v6 = dword_BF5E4 + a3;
    *(_DWORD *)(a2 + 56) = v6;
    return netlink_broadcast_filtered(v4, a2, 0, v6, v5, 0, 0);
  }
  return result;
}
