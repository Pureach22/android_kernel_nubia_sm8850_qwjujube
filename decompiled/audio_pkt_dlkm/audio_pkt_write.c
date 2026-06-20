unsigned __int64 __fastcall audio_pkt_write(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x23
  __int64 v4; // x22
  int v7; // w21
  unsigned __int64 result; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  int v11; // w21
  int v12; // w9
  unsigned __int64 v13; // x20
  void *v14; // x0
  int v15; // w0
  void *v16; // x0
  int updated; // w0
  int v18; // w21

  if ( !a1 || !a2 || (v3 = *(_QWORD *)(a1 + 32)) == 0 )
  {
    if ( (unsigned int)__ratelimit(&audio_pkt_write__rs, "audio_pkt_write") )
      printk(&unk_84F9, "audio_pkt_write");
    ipc_log_string(0, "[%s]: invalid parameters\n", "audio_pkt_write");
    return -22;
  }
  v4 = *(_QWORD *)(v3 + 16);
  if ( !v4 )
  {
    if ( (unsigned int)__ratelimit(&audio_pkt_write__rs_26, "audio_pkt_write") )
      printk(&unk_8597, "audio_pkt_write");
    ipc_log_string(0, "[%s]: invalid device handle\n", "audio_pkt_write");
    return -22;
  }
  mutex_lock(v3 + 24);
  v7 = *(_DWORD *)(v3 + 72);
  mutex_unlock(v3 + 24);
  if ( v7 == 1 )
  {
    if ( a3 <= 0x17 )
    {
      if ( (unsigned int)__ratelimit(&audio_pkt_write__rs_28, "audio_pkt_write") )
        printk(&unk_7E10, "audio_pkt_write");
      ipc_log_string(0, "[%s]: Invalid count %zu\n", "audio_pkt_write", a3);
      return -22;
    }
    result = memdup_user(a2, a3);
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      if ( a3 > 0x1000 || a3 < (unsigned __int64)*(unsigned int *)result >> 8 )
      {
        v11 = -22;
LABEL_53:
        kfree(result);
        return v11;
      }
      if ( (a3 & 0x1FFC) == 0x14 )
      {
        __break(1u);
        return inline_copy_to_user(result, v9, v10);
      }
      v12 = *(_DWORD *)(result + 20);
      if ( v12 == 16781350 )
      {
        if ( a3 <= 0x33 )
        {
          v13 = result;
          v14 = &audio_pkt_write__rs_35;
          goto LABEL_32;
        }
        v13 = result;
        updated = audpkt_chk_and_update_satellite_physical_addr(result);
        if ( updated < 0 )
        {
          v11 = updated;
          v16 = &audio_pkt_write__rs_36;
          goto LABEL_49;
        }
      }
      else
      {
        v13 = result;
        if ( v12 == 16781324 )
        {
          if ( a3 <= 0x2B )
          {
            v14 = &audio_pkt_write__rs_31;
LABEL_32:
            if ( (unsigned int)__ratelimit(v14, "audio_pkt_write") )
              printk(&unk_7E10, "audio_pkt_write");
            ipc_log_string(0, "[%s]: Invalid count %zu\n", "audio_pkt_write", a3);
            v11 = -22;
            goto LABEL_52;
          }
          v15 = audpkt_chk_and_update_physical_addr(result);
          if ( v15 < 0 )
          {
            v11 = v15;
            v16 = &audio_pkt_write__rs_32;
LABEL_49:
            if ( (unsigned int)__ratelimit(v16, "audio_pkt_write") )
              printk(&unk_7FF7, "audio_pkt_write");
            ipc_log_string(0, "[%s]: Update Physical Address Failed -%d\n", "audio_pkt_write", v11);
            goto LABEL_52;
          }
        }
      }
      if ( (unsigned int)mutex_lock_interruptible(v4 + 144) )
      {
        v11 = -512;
LABEL_52:
        result = v13;
        goto LABEL_53;
      }
      v18 = gpr_send_pkt(*(_QWORD *)v3, v13);
      if ( v18 < 0 )
      {
        if ( (unsigned int)__ratelimit(&audio_pkt_write__rs_38, "audio_pkt_write") )
          printk(&unk_849F, "audio_pkt_write");
        ipc_log_string(0, "[%s]: APR Send Packet Failed ret -%d\n", "audio_pkt_write", v18);
        if ( v18 == -104 )
          v18 = -102;
      }
      mutex_unlock(v4 + 144);
      kfree(v13);
      if ( v18 >= 0 )
        return a3;
      else
        return v18;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&audio_pkt_write__rs_27, "audio_pkt_write") )
      printk(&unk_83C5, "audio_pkt_write");
    ipc_log_string(0, "[%s]: dev is in reset\n", "audio_pkt_write");
    return -102;
  }
  return result;
}
