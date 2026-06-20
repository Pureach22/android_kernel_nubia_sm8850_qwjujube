__int64 __fastcall rmnet_wlan_genl_get_tuple(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  result = rmnet_wlan_get_tuples(v4, &rmnet_wlan_genl_family, a2);
  if ( !(_DWORD)result )
  {
    if ( v4[0] )
    {
      netlink_unicast(*(_QWORD *)(*(_QWORD *)(a2 + 40) + 288LL), v4[0], *(unsigned int *)(a2 + 4), 64);
      result = 0;
    }
    else
    {
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
