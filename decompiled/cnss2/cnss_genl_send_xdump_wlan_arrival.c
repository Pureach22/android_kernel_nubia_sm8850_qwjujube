__int64 __fastcall cnss_genl_send_xdump_wlan_arrival(unsigned __int8 a1, unsigned __int8 a2, int a3, int a4)
{
  __int64 v8; // x0
  _DWORD *v9; // x23
  __int64 v10; // x0
  __int64 v11; // x25
  unsigned int v12; // w0
  __int64 v13; // x3
  __int64 v14; // x0
  int v15; // w0
  unsigned int v16; // w24
  unsigned __int64 StatusReg; // x8
  const char *v18; // x1
  __int16 v19; // w9
  const char *v20; // x8
  int v22; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+28h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = _alloc_skb(76, 3264, 0, 0xFFFFFFFFLL);
  if ( v8 )
  {
    v9 = (_DWORD *)v8;
    v10 = genlmsg_put(v8, 0, 0, &cnss_genl_family, 0, 2);
    if ( v10 )
    {
      v11 = v10;
      LOBYTE(v22) = 4;
      v12 = nla_put(v9, 1, 1, &v22);
      if ( (v12 & 0x80000000) == 0 )
      {
        if ( !a1 || (v12 = nla_put(v9, 5, 0, 0), (v12 & 0x80000000) == 0) )
        {
          if ( !a2 || (v12 = nla_put(v9, 6, 0, 0), (v12 & 0x80000000) == 0) )
          {
            v22 = a3;
            v12 = nla_put(v9, 3, 4, &v22);
            if ( (v12 & 0x80000000) == 0 )
            {
              v22 = a4;
              v12 = nla_put(v9, 4, 4, &v22);
              if ( (v12 & 0x80000000) == 0 )
              {
                *(_DWORD *)(v11 - 20) = v9[54] + v9[52] - (v11 - 20);
                if ( byte_1388 )
                {
                  v13 = (unsigned int)dword_13FC;
                  v14 = wait_for_completion_killable;
                  v9[14] = dword_13FC;
                  v15 = netlink_broadcast_filtered(v14, v9, 0, v13, 3264, 0, 0);
                  v16 = v15 & (v15 >> 31);
                }
                else
                {
                  __break(0x800u);
                  v16 = -22;
                }
                goto LABEL_16;
              }
            }
          }
        }
      }
      v16 = v12;
    }
    else
    {
      v16 = -12;
    }
    sk_skb_reason_drop(0, v9, 2);
  }
  else
  {
    v16 = -12;
  }
LABEL_16:
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v18 = "irq";
  }
  else
  {
    v19 = *(_DWORD *)(StatusReg + 16);
    v20 = (const char *)(StatusReg + 2320);
    if ( (v19 & 0xFF00) != 0 )
      v18 = "soft_irq";
    else
      v18 = v20;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v18,
    "cnss_genl_send_xdump_wlan_arrival",
    6u,
    6u,
    "Send XDUMP_SUBCMD_WL_ARRIVAL(wl_over_bt: %d, bt_over_wl: %d, sram_addr: 0x%x, sram_size: 0x%x): %d\n",
    a1,
    a2,
    a3);
  _ReadStatusReg(SP_EL0);
  return v16;
}
