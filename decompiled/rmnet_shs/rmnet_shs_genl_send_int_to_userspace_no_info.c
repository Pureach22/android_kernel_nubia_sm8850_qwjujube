__int64 __fastcall rmnet_shs_genl_send_int_to_userspace_no_info(int a1)
{
  __int64 v2; // x0
  __int64 v3; // x2
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 result; // x0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( last_net )
  {
    v2 = _alloc_skb(3732, 2080, 0, 0xFFFFFFFFLL);
    if ( v2 )
    {
      v3 = (unsigned int)rmnet_shs_genl_seqnum;
      v4 = v2;
      ++rmnet_shs_genl_seqnum;
      v5 = genlmsg_put(v2, 0, v3, &rmnet_shs_genl_family, 0, 1);
      if ( v5 && (v6 = v5, v8 = a1, !(unsigned int)nla_put(v4, 2, 4, &v8)) )
      {
        *(_DWORD *)(v6 - 20) = *(_DWORD *)(v4 + 216) + *(_DWORD *)(v4 + 208) - (v6 - 20);
        if ( (netlink_unicast(*(_QWORD *)(last_net + 288), v4, (unsigned int)last_snd_portid, 64) & 0x80000000) == 0 )
        {
          result = 0;
          goto LABEL_8;
        }
      }
      else
      {
        kfree(v4);
      }
    }
    rmnet_shs_userspace_connected = 0;
  }
  result = 0xFFFFFFFFLL;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
