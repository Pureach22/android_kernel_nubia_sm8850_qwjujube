__int64 __fastcall glink_pkt_poll(__int64 a1, _DWORD **a2)
{
  __int64 v2; // x21
  _DWORD *v6; // x8
  __int64 v7; // x1
  __int64 v8; // x8
  int v9; // w23
  unsigned int v10; // w19

  v2 = *(_QWORD *)(a1 + 32);
  if ( v2 && *(_DWORD *)(v2 + 1128) != 1 )
  {
    if ( (completion_done(v2 + 1096) & 1) != 0 )
    {
      ipc_log_string(
        glink_pkt_ilctxt,
        "[%s]: Wait for pkt on channel:%s\n",
        "glink_pkt_poll",
        *(const char **)(v2 + 1512));
      if ( a2 )
      {
        v6 = *a2;
        if ( *a2 )
        {
          if ( *(v6 - 1) != -442429149 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _DWORD **))v6)(a1, v2 + 1200, a2);
          __dmb(0xBu);
        }
      }
      mutex_lock(v2 + 1048);
      if ( (completion_done(v2 + 1096) & 1) != 0 && *(_QWORD *)(v2 + 1136) )
      {
        v7 = raw_spin_lock_irqsave(v2 + 1148);
        if ( *(_QWORD *)(v2 + 1152) != v2 + 1152 || (v8 = *(_QWORD *)(v2 + 1584)) != 0 )
          LODWORD(v8) = 65;
        if ( *(_DWORD *)(v2 + 1224) )
          v9 = v8 | 2;
        else
          v9 = v8;
        raw_spin_unlock_irqrestore(v2 + 1148, v7);
        v10 = rpmsg_poll(*(_QWORD *)(*(_QWORD *)(v2 + 1136) + 968LL), a1, a2) | v9;
        mutex_unlock(v2 + 1048);
        ipc_log_string(glink_pkt_ilctxt, "[%s]: Exit channel:%s\n", "glink_pkt_poll", *(const char **)(v2 + 1512));
        return v10;
      }
      else
      {
        if ( (unsigned int)__ratelimit(&glink_pkt_poll__rs_50, "glink_pkt_poll") )
          printk("%s[%s]: %s channel reset after wait\n", byte_9300, "glink_pkt_poll", *(const char **)(v2 + 1512));
        ipc_log_string(
          glink_pkt_ilctxt,
          "%s[%s]: %s channel reset after wait\n",
          (const char *)&unk_90F5,
          "glink_pkt_poll",
          *(const char **)(v2 + 1512));
        mutex_unlock(v2 + 1048);
        return 16;
      }
    }
    else
    {
      if ( (unsigned int)__ratelimit(&glink_pkt_poll__rs_48, "glink_pkt_poll") )
        printk("%s[%s]: %s channel in reset\n", byte_9300, "glink_pkt_poll", *(const char **)(v2 + 1512));
      ipc_log_string(
        glink_pkt_ilctxt,
        "%s[%s]: %s channel in reset\n",
        (const char *)&unk_90F5,
        "glink_pkt_poll",
        *(const char **)(v2 + 1512));
      return 18;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&glink_pkt_poll__rs, "glink_pkt_poll") )
      printk("%s[%s]: invalid device handle\n", byte_9300, "glink_pkt_poll");
    ipc_log_string(glink_pkt_ilctxt, "%s[%s]: invalid device handle\n", (const char *)&unk_90F5, "glink_pkt_poll");
    return 8;
  }
}
