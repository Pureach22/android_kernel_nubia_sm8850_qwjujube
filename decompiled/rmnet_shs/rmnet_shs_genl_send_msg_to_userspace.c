__int64 rmnet_shs_genl_send_msg_to_userspace()
{
  int v0; // w21
  __int64 v1; // x0
  __int64 v2; // x2
  _DWORD *v3; // x19
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 result; // x0
  __int64 v7; // x3
  __int64 v8; // x0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = rmnet_shs_genl_seqnum++;
  v1 = _alloc_skb(3732, 2080, 0, 0xFFFFFFFFLL);
  if ( !v1 )
    goto LABEL_5;
  v2 = (unsigned int)rmnet_shs_genl_seqnum;
  v3 = (_DWORD *)v1;
  ++rmnet_shs_genl_seqnum;
  v4 = genlmsg_put(v1, 0, v2, &rmnet_shs_genl_family, 0, 1);
  if ( !v4 || (v5 = v4, v9 = v0, (unsigned int)nla_put(v3, 2, 4, &v9)) )
  {
    kfree(v3);
LABEL_5:
    result = 0xFFFFFFFFLL;
    rmnet_shs_userspace_connected = 0;
    goto LABEL_6;
  }
  *(_DWORD *)(v5 - 20) = v3[54] + v3[52] - (v5 - 20);
  if ( byte_8D8 )
  {
    v7 = (unsigned int)dword_94C;
    v8 = MEMORY[0x2E268];
    v3[14] = dword_94C;
    netlink_broadcast_filtered(v8, v3, 0, v7, 2080, 0, 0);
    result = 0;
  }
  else
  {
    result = 0;
    __break(0x800u);
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
