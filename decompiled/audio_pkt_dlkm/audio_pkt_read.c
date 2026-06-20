__int64 __fastcall audio_pkt_read(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x23
  int v8; // w22
  __int64 v9; // x22
  _QWORD *v10; // x19
  __int64 v11; // x0
  __int64 v12; // x19
  _DWORD *v13; // x22
  void *v14; // x0
  __int64 v15; // x20
  __int64 result; // x0
  unsigned int updated; // w0
  unsigned int v18; // w22
  _QWORD v19[6]; // [xsp+0h] [xbp-30h] BYREF

  v19[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  v4 = *(_QWORD *)(v3 + 16);
  if ( v4 )
  {
    mutex_lock(v3 + 24);
    v8 = *(_DWORD *)(v3 + 72);
    mutex_unlock(v3 + 24);
    if ( v8 == 1 )
    {
      v9 = raw_spin_lock_irqsave(v4 + 192);
      v10 = (_QWORD *)(v4 + 200);
      if ( *(_QWORD *)(v4 + 200) == v4 + 200 )
      {
        raw_spin_unlock_irqrestore(v4 + 192, v9);
        if ( (*(_BYTE *)(a1 + 49) & 8) != 0 )
        {
          result = -11;
          goto LABEL_45;
        }
        if ( (_QWORD *)*v10 == v10 )
        {
          memset(v19, 0, 40);
          init_wait_entry(v19, 0);
          v11 = prepare_to_wait_event(v4 + 224, v19, 1);
          if ( *(_QWORD **)(v4 + 200) == v10 )
          {
            while ( !v11 )
            {
              schedule();
              v11 = prepare_to_wait_event(v4 + 224, v19, 1);
              if ( (_QWORD *)*v10 != v10 )
                goto LABEL_9;
            }
            if ( (_DWORD)v11 )
            {
              result = -512;
              goto LABEL_45;
            }
          }
          else
          {
LABEL_9:
            finish_wait(v4 + 224, v19);
          }
        }
        v9 = raw_spin_lock_irqsave(v4 + 192);
      }
      v12 = skb_dequeue(v4 + 200);
      raw_spin_unlock_irqrestore(v4 + 192, v9);
      if ( v12 )
      {
        v13 = *(_DWORD **)(v12 + 224);
        if ( *(unsigned int *)(v12 + 112) < a3 )
          a3 = *(unsigned int *)(v12 + 112);
        if ( !v13 )
        {
          if ( (unsigned int)__ratelimit(&audio_pkt_read__rs_11, "audio_pkt_read") )
            printk(&unk_8184, "audio_pkt_read");
          ipc_log_string(0, "[%s]: Invalid audpkt_hdr\n", "audio_pkt_read");
          v15 = -14;
          goto LABEL_44;
        }
        if ( (int)a3 > 4096 || (unsigned int)a3 < *v13 >> 8 )
        {
          v14 = &audio_pkt_read__rs_14;
LABEL_18:
          if ( (unsigned int)__ratelimit(v14, "audio_pkt_read") )
            printk(&unk_8656, "audio_pkt_read");
          ipc_log_string(0, "[%s]: Invalid count %d\n", "audio_pkt_read", (unsigned int)a3);
LABEL_21:
          v15 = -22;
LABEL_44:
          sk_skb_reason_drop(0, v12, 2);
          result = v15;
          goto LABEL_45;
        }
        if ( v13[5] == 16781324 )
        {
          if ( a3 <= 0x2B )
          {
            v14 = &audio_pkt_read__rs_17;
            goto LABEL_18;
          }
          updated = audpkt_chk_and_update_handle(*(_QWORD *)(v12 + 224));
          if ( (updated & 0x80000000) != 0 )
          {
            v18 = updated;
            if ( (unsigned int)__ratelimit(&audio_pkt_read__rs_18, "audio_pkt_read") )
              printk(&unk_7F1C, "audio_pkt_read");
            ipc_log_string(0, "[%s]: Update from physical address to file handle failed -%d\n", "audio_pkt_read", v18);
            goto LABEL_21;
          }
          v13 = *(_DWORD **)(v12 + 224);
        }
        if ( (unsigned __int64)(int)a3 >> 31 )
        {
          __break(0x800u);
          v15 = -14;
        }
        else
        {
          _check_object_size(v13, (int)a3, 1);
          if ( inline_copy_to_user(a2, v13, (int)a3) )
            v15 = -14;
          else
            v15 = (int)a3;
        }
        goto LABEL_44;
      }
      if ( (unsigned int)__ratelimit(&audio_pkt_read__rs_8, "audio_pkt_read") )
        printk(&unk_84E4, "audio_pkt_read");
      ipc_log_string(0, "[%s]: Invalid skb\n", "audio_pkt_read");
      result = -14;
    }
    else
    {
      if ( (unsigned int)__ratelimit(&audio_pkt_read__rs_5, "audio_pkt_read") )
        printk(&unk_83C5, "audio_pkt_read");
      ipc_log_string(0, "[%s]: dev is in reset\n", "audio_pkt_read");
      result = -102;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&audio_pkt_read__rs, "audio_pkt_read") )
      printk(&unk_8597, "audio_pkt_read");
    ipc_log_string(0, "[%s]: invalid device handle\n", "audio_pkt_read");
    result = -22;
  }
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
