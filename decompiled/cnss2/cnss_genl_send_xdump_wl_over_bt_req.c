__int64 cnss_genl_send_xdump_wl_over_bt_req()
{
  __int64 v0; // x0
  __int64 v1; // x7
  _DWORD *v2; // x20
  __int64 v3; // x0
  __int64 v4; // x21
  unsigned int v5; // w0
  __int64 v6; // x3
  __int64 v7; // x0
  int v8; // w0
  unsigned int v9; // w19
  unsigned __int64 StatusReg; // x8
  const char *v11; // x1
  __int16 v12; // w9
  const char *v13; // x8
  char v15; // [xsp+0h] [xbp-10h]
  char v16[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = _alloc_skb(44, 3264, 0, 0xFFFFFFFFLL);
  if ( v0 )
  {
    v2 = (_DWORD *)v0;
    v3 = genlmsg_put(v0, 0, 0, &cnss_genl_family, 0, 2);
    if ( v3 )
    {
      v4 = v3;
      v16[0] = 5;
      v5 = nla_put(v2, 1, 1, v16);
      if ( (v5 & 0x80000000) == 0 )
      {
        *(_DWORD *)(v4 - 20) = v2[54] + v2[52] - (v4 - 20);
        if ( byte_1388 )
        {
          v6 = (unsigned int)dword_13FC;
          v7 = wait_for_completion_killable;
          v2[14] = dword_13FC;
          v8 = netlink_broadcast_filtered(v7, v2, 0, v6, 3264, 0, 0);
          v9 = v8 & (v8 >> 31);
        }
        else
        {
          __break(0x800u);
          v9 = -22;
        }
        goto LABEL_10;
      }
      v9 = v5;
    }
    else
    {
      v9 = -12;
    }
    sk_skb_reason_drop(0, v2, 2);
  }
  else
  {
    v9 = -12;
  }
LABEL_10:
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v11 = "irq";
  }
  else
  {
    v12 = *(_DWORD *)(StatusReg + 16);
    v13 = (const char *)(StatusReg + 2320);
    if ( (v12 & 0xFF00) != 0 )
      v11 = "soft_irq";
    else
      v11 = v13;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v11,
    "cnss_genl_send_xdump_wl_over_bt_req",
    6u,
    6u,
    "Send XDUMP_SUBCMD_WL_OVER_BT_REQ: %d\n",
    v9,
    v1,
    v15);
  _ReadStatusReg(SP_EL0);
  return v9;
}
