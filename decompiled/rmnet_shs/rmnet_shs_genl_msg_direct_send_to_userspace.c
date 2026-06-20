__int64 __fastcall rmnet_shs_genl_msg_direct_send_to_userspace(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x2
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x21

  if ( msg_last_net )
  {
    v2 = _alloc_skb(3732, 2080, 0, 0xFFFFFFFFLL);
    if ( v2 )
    {
      v3 = (unsigned int)rmnet_shs_genl_msg_seqnum;
      v4 = v2;
      ++rmnet_shs_genl_msg_seqnum;
      v5 = genlmsg_put(v2, 0, v3, &rmnet_shs_genl_msg_family, 0, 1);
      if ( v5 && (v6 = v5, !(unsigned int)nla_put(v4, 2, 120, a1)) )
      {
        *(_DWORD *)(v6 - 20) = *(_DWORD *)(v4 + 216) + *(_DWORD *)(v4 + 208) - (v6 - 20);
        if ( (netlink_unicast(*(_QWORD *)(msg_last_net + 288), v4, (unsigned int)msg_last_snd_portid, 64) & 0x80000000) == 0 )
          return 0;
      }
      else
      {
        kfree(v4);
      }
    }
  }
  return 0xFFFFFFFFLL;
}
