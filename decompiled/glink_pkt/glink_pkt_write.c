unsigned __int64 __fastcall glink_pkt_write(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x22
  unsigned __int64 result; // x0
  unsigned __int64 v8; // x20
  int v9; // w21
  __int64 v10; // x8
  __int64 v11; // x0
  int v12; // w0

  v3 = *(_QWORD *)(a1 + 32);
  if ( v3 && *(_DWORD *)(v3 + 1128) != 1 )
  {
    ipc_log_string(
      glink_pkt_ilctxt,
      "[%s]: begin to %s buffer_size %zu\n",
      "glink_pkt_write",
      *(const char **)(v3 + 1512),
      a3);
    result = vmemdup_user(a2, a3);
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      v8 = result;
      if ( (unsigned int)mutex_lock_interruptible(v3 + 1048) )
      {
        v9 = -512;
      }
      else
      {
        if ( (completion_done(v3 + 1096) & 1) != 0 && (v10 = *(_QWORD *)(v3 + 1136)) != 0 )
        {
          v11 = *(_QWORD *)(v10 + 968);
          if ( (*(_BYTE *)(a1 + 49) & 8) != 0 )
            v12 = rpmsg_trysend(v11, v8, (unsigned int)a3);
          else
            v12 = rpmsg_send(v11, v8, (unsigned int)a3);
          v9 = v12;
        }
        else
        {
          if ( (unsigned int)__ratelimit(&glink_pkt_write__rs_46, "glink_pkt_write") )
            printk("%s[%s]: %s channel in reset\n", byte_9300, "glink_pkt_write", *(const char **)(v3 + 1512));
          ipc_log_string(
            glink_pkt_ilctxt,
            "%s[%s]: %s channel in reset\n",
            (const char *)&unk_90F5,
            "glink_pkt_write",
            *(const char **)(v3 + 1512));
          v9 = -102;
        }
        mutex_unlock(v3 + 1048);
      }
      kvfree(v8);
      ipc_log_string(
        glink_pkt_ilctxt,
        "[%s]: finish to %s ret %d\n",
        "glink_pkt_write",
        *(const char **)(v3 + 1512),
        v9);
      if ( v9 >= 0 )
        return a3;
      else
        return v9;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&glink_pkt_write__rs, "glink_pkt_write") )
      printk("%s[%s]: invalid device handle\n", byte_9300, "glink_pkt_write");
    ipc_log_string(glink_pkt_ilctxt, "%s[%s]: invalid device handle\n", (const char *)&unk_90F5, "glink_pkt_write");
    return -22;
  }
  return result;
}
