__int64 __fastcall glink_pkt_read(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x19
  __int64 result; // x0
  const char *v8; // x3
  unsigned __int64 StatusReg; // x23
  _QWORD *v10; // x21
  __int64 *v11; // x26
  __int64 v12; // x0
  __int64 v13; // x22
  int v14; // w20
  __int64 v15; // x8
  int v16; // w10
  __int64 v17; // x0
  __int64 v18; // x21
  __int64 v19; // x22
  __int64 v20; // x0
  __int64 v21; // x0
  _QWORD v22[6]; // [xsp+10h] [xbp-30h] BYREF

  v22[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  if ( !v3 || *(_DWORD *)(v3 + 1128) == 1 )
  {
    if ( (unsigned int)__ratelimit(&glink_pkt_read__rs, "glink_pkt_read") )
      printk("%s[%s]: invalid device handle\n", byte_9300, "glink_pkt_read");
    ipc_log_string(glink_pkt_ilctxt, "%s[%s]: invalid device handle\n", (const char *)&unk_90F5, "glink_pkt_read");
    result = -22;
    goto LABEL_39;
  }
  if ( (unsigned int)mutex_lock_interruptible(v3 + 1048) )
  {
LABEL_7:
    result = -512;
    goto LABEL_39;
  }
  if ( (completion_done(v3 + 1096) & 1) != 0 )
  {
    v8 = *(const char **)(v3 + 1512);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      glink_pkt_ilctxt,
      "[%s]: begin for %s by %s:%d ref_cnt[%d], remaining[%lu], count[%lu]\n",
      "glink_pkt_read",
      v8,
      (const char *)(StatusReg + 2320),
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(v3 + 1128),
      *(_QWORD *)(v3 + 1600),
      a3);
    mutex_unlock(v3 + 1048);
    raw_spin_lock_irq(v3 + 1148);
    v10 = (_QWORD *)(v3 + 1152);
    if ( *(_QWORD *)(v3 + 1152) == v3 + 1152 && !*(_QWORD *)(v3 + 1584) )
    {
      if ( (*(_BYTE *)(a1 + 49) & 8) != 0 )
      {
        raw_spin_unlock_irq(v3 + 1148);
        mutex_unlock(v3 + 1048);
        result = -11;
        goto LABEL_39;
      }
      if ( (completion_done(v3 + 1096) & 1) != 0 )
      {
        memset(v22, 0, 40);
        init_wait_entry(v22, 0);
        v17 = prepare_to_wait_event(v3 + 1200, v22, 1);
        if ( *(_QWORD **)(v3 + 1152) == v10 )
        {
          v19 = v17;
          while ( (completion_done(v3 + 1096) & 1) != 0 )
          {
            v20 = v3 + 1148;
            if ( v19 )
            {
              raw_spin_unlock_irq(v20);
              if ( (_DWORD)v19 )
                goto LABEL_7;
              goto LABEL_12;
            }
            v21 = raw_spin_unlock_irq(v20);
            schedule(v21);
            raw_spin_lock_irq(v3 + 1148);
            v19 = prepare_to_wait_event(v3 + 1200, v22, 1);
            if ( (_QWORD *)*v10 != v10 )
              break;
          }
        }
        finish_wait(v3 + 1200, v22);
      }
    }
    raw_spin_unlock_irq(v3 + 1148);
LABEL_12:
    if ( (completion_done(v3 + 1096) & 1) == 0 )
    {
      result = -102;
      goto LABEL_39;
    }
    if ( (unsigned int)mutex_lock_interruptible(v3 + 1048) )
      goto LABEL_7;
    mutex_lock(v3 + 1536);
    raw_spin_lock_irq(v3 + 1148);
    v11 = (__int64 *)(v3 + 1584);
    if ( !*(_QWORD *)(v3 + 1584) )
    {
      v12 = skb_dequeue(v3 + 1152);
      *v11 = v12;
      if ( !v12 )
      {
        raw_spin_unlock_irq(v3 + 1148);
        mutex_unlock(v3 + 1536);
        mutex_unlock(v3 + 1048);
        result = 0;
        goto LABEL_39;
      }
      *(_QWORD *)(v3 + 1592) = *(_QWORD *)(v12 + 224);
      *(_QWORD *)(v3 + 1600) = *(unsigned int *)(v12 + 112);
    }
    raw_spin_unlock_irq(v3 + 1148);
    if ( *(_QWORD *)(v3 + 1600) < a3 )
      a3 = *(_QWORD *)(v3 + 1600);
    if ( (unsigned __int64)(int)a3 >> 31 )
    {
      __break(0x800u);
      v14 = -14;
    }
    else
    {
      v13 = *(_QWORD *)(v3 + 1592);
      _check_object_size(v13, (int)a3, 1);
      if ( inline_copy_to_user(a2, v13, (int)a3) )
        v14 = -14;
      else
        v14 = a3;
    }
    raw_spin_lock_irq(v3 + 1148);
    v15 = *(_QWORD *)(v3 + 1600);
    v16 = *(unsigned __int8 *)(v3 + 1228);
    *(_QWORD *)(v3 + 1592) += (int)a3;
    *(_QWORD *)(v3 + 1600) = v15 - (int)a3;
    if ( v16 != 1 || v15 == (int)a3 )
    {
      v18 = *v11;
      *(_QWORD *)(v3 + 1592) = 0;
      *(_QWORD *)(v3 + 1600) = 0;
      *v11 = 0;
      raw_spin_unlock_irq(v3 + 1148);
      if ( v18 )
        glink_pkt_kfree_skb(v3, v18);
    }
    else
    {
      raw_spin_unlock_irq(v3 + 1148);
    }
    mutex_unlock(v3 + 1536);
    ipc_log_string(
      glink_pkt_ilctxt,
      "[%s]: end for %s by %s:%d ret[%d], remaining[%lu]\n",
      "glink_pkt_read",
      *(const char **)(v3 + 1512),
      (const char *)(StatusReg + 2320),
      *(_DWORD *)(StatusReg + 1800),
      v14,
      *(_QWORD *)(v3 + 1600));
    mutex_unlock(v3 + 1048);
    result = v14;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&glink_pkt_read__rs_39, "glink_pkt_read") )
      printk("%s[%s]: %s channel in reset\n", byte_9300, "glink_pkt_read", *(const char **)(v3 + 1512));
    ipc_log_string(
      glink_pkt_ilctxt,
      "%s[%s]: %s channel in reset\n",
      (const char *)&unk_90F5,
      "glink_pkt_read",
      *(const char **)(v3 + 1512));
    mutex_unlock(v3 + 1048);
    result = -102;
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
