__int64 __fastcall cnss_genl_send_xdump_bt_over_wl_resp(unsigned int a1)
{
  __int64 v2; // x0
  _DWORD *v3; // x20
  __int64 v4; // x0
  __int64 v5; // x22
  unsigned int v6; // w0
  __int64 v7; // x3
  __int64 v8; // x0
  int v9; // w0
  unsigned int v10; // w21
  unsigned __int64 StatusReg; // x8
  const char *v12; // x1
  __int16 v13; // w9
  const char *v14; // x8
  char v16[4]; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = _alloc_skb(52, 3264, 0, 0xFFFFFFFFLL);
  if ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = genlmsg_put(v2, 0, 0, &cnss_genl_family, 0, 2);
    if ( v4 )
    {
      v5 = v4;
      v16[0] = 3;
      v6 = nla_put(v3, 1, 1, v16);
      if ( (v6 & 0x80000000) == 0 )
      {
        v17 = a1;
        v6 = nla_put(v3, 2, 4, &v17);
        if ( (v6 & 0x80000000) == 0 )
        {
          *(_DWORD *)(v5 - 20) = v3[54] + v3[52] - (v5 - 20);
          if ( byte_1388 )
          {
            v7 = (unsigned int)dword_13FC;
            v8 = wait_for_completion_killable;
            v3[14] = dword_13FC;
            v9 = netlink_broadcast_filtered(v8, v3, 0, v7, 3264, 0, 0);
            v10 = v9 & (v9 >> 31);
          }
          else
          {
            __break(0x800u);
            v10 = -22;
          }
          goto LABEL_11;
        }
      }
      v10 = v6;
    }
    else
    {
      v10 = -12;
    }
    sk_skb_reason_drop(0, v3, 2);
  }
  else
  {
    v10 = -12;
  }
LABEL_11:
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v12 = "irq";
  }
  else
  {
    v13 = *(_DWORD *)(StatusReg + 16);
    v14 = (const char *)(StatusReg + 2320);
    if ( (v13 & 0xFF00) != 0 )
      v12 = "soft_irq";
    else
      v12 = v14;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v12,
    "cnss_genl_send_xdump_bt_over_wl_resp",
    6u,
    6u,
    "Send XDUMP_SUBCMD_BT_OVER_WL_RESP(%d): %d\n",
    a1,
    v10,
    v16[0]);
  _ReadStatusReg(SP_EL0);
  return v10;
}
