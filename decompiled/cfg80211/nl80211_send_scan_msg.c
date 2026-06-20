__int64 __fastcall nl80211_send_scan_msg(__int64 result, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x3

  if ( a2 )
  {
    if ( (unsigned __int8)byte_BF570 <= 1u )
    {
      __break(0x800u);
    }
    else
    {
      v2 = *(_QWORD *)(*(_QWORD *)(result + 2344) + 288LL);
      v3 = (unsigned int)(dword_BF5E4 + 1);
      *(_DWORD *)(a2 + 56) = v3;
      return netlink_broadcast_filtered(v2, a2, 0, v3, 3264, 0, 0);
    }
  }
  return result;
}
