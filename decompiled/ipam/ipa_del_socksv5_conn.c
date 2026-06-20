__int64 __fastcall ipa_del_socksv5_conn(unsigned int a1)
{
  __int64 v2; // x20
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w9
  __int64 v10; // x8
  int v11; // w6
  __int64 v12; // x0
  __int64 v13; // x0
  _WORD *v14; // x20
  unsigned int v15; // w19
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  int v38; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v39; // [xsp+8h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x10u )
  {
    printk(&unk_3A7A91, "ipa_del_socksv5_conn");
    v20 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_61;
    v21 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v21 )
    {
      ipc_log_string(v21, "ipa %s:%d Not support !\n", "ipa_del_socksv5_conn", 14753);
      v20 = ipa3_ctx;
    }
    v22 = *(_QWORD *)(v20 + 34160);
    if ( v22 )
    {
      ipc_log_string(v22, "ipa %s:%d Not support !\n", "ipa_del_socksv5_conn", 14753);
      v15 = -1;
    }
    else
    {
LABEL_61:
      v15 = -1;
    }
  }
  else
  {
    if ( (*(_BYTE *)(ipa3_ctx + 51328) & 1) != 0 )
    {
      if ( a1 >= 0x3E9 )
      {
        printk(&unk_3EA4D0, "ipa_del_socksv5_conn");
        v26 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_60;
        v27 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v27 )
        {
          ipc_log_string(v27, "ipa %s:%d invalid handle!\n", "ipa_del_socksv5_conn", 14763);
          v26 = ipa3_ctx;
        }
        v28 = *(_QWORD *)(v26 + 34160);
        if ( !v28 )
          goto LABEL_60;
        ipc_log_string(v28, "ipa %s:%d invalid handle!\n", "ipa_del_socksv5_conn", 14763);
      }
      else
      {
        if ( (a1 & 1) == 0 )
        {
          if ( *(int *)(ipa3_ctx + 51384) > 1 )
          {
            v2 = *(_QWORD *)(ipa3_ctx + 51304) + (a1 << 7);
            mutex_lock(ipa3_ctx + 51336);
            if ( (*(_BYTE *)(v2 + 60) & 1) == 0 )
            {
              v3 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v4 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v4 )
                {
                  ipc_log_string(v4, "ipa %s:%d  entry %d already free\n", "ipa_del_socksv5_conn", 14784, a1);
                  v3 = ipa3_ctx;
                }
                v5 = *(_QWORD *)(v3 + 34160);
                if ( v5 )
                  ipc_log_string(v5, "ipa %s:%d  entry %d already free\n", "ipa_del_socksv5_conn", 14784, a1);
              }
            }
            if ( (*(_BYTE *)(v2 + 188) & 1) == 0 )
            {
              v6 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v7 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v7 )
                {
                  ipc_log_string(v7, "ipa %s:%d  entry %d already free\n", "ipa_del_socksv5_conn", 14790, a1);
                  v6 = ipa3_ctx;
                }
                v8 = *(_QWORD *)(v6 + 34160);
                if ( v8 )
                  ipc_log_string(v8, "ipa %s:%d  entry %d already free\n", "ipa_del_socksv5_conn", 14790, a1);
              }
            }
            v9 = *(_DWORD *)(v2 + 188) & 0xFFFFFFFE;
            *(_DWORD *)(v2 + 60) &= ~1u;
            *(_DWORD *)(v2 + 188) = v9;
            v10 = ipa3_ctx;
            v11 = *(_DWORD *)(ipa3_ctx + 51384) - 2;
            *(_DWORD *)(ipa3_ctx + 51384) = v11;
            if ( v10 )
            {
              v12 = *(_QWORD *)(v10 + 34152);
              if ( v12 )
              {
                ipc_log_string(
                  v12,
                  "ipa %s:%d free entry %d and %d, left total %d\n",
                  "ipa_del_socksv5_conn",
                  14803,
                  a1,
                  a1 | 1,
                  v11);
                v10 = ipa3_ctx;
              }
              v13 = *(_QWORD *)(v10 + 34160);
              if ( v13 )
                ipc_log_string(
                  v13,
                  "ipa %s:%d free entry %d and %d, left total %d\n",
                  "ipa_del_socksv5_conn",
                  14803,
                  a1,
                  a1 | 1,
                  *(_DWORD *)(v10 + 51384));
            }
            v14 = (_WORD *)_kmalloc_cache_noprof(sg_next, 3520, 4);
            if ( !v14 )
            {
              printk(&unk_3B3190, "ipa_del_socksv5_conn");
              v35 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v36 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v36 )
                {
                  ipc_log_string(
                    v36,
                    "ipa %s:%d socksv5_handle memory allocation failed!\n",
                    "ipa_del_socksv5_conn",
                    14808);
                  v35 = ipa3_ctx;
                }
                v37 = *(_QWORD *)(v35 + 34160);
                if ( v37 )
                  ipc_log_string(
                    v37,
                    "ipa %s:%d socksv5_handle memory allocation failed!\n",
                    "ipa_del_socksv5_conn",
                    14808);
              }
              v15 = -12;
              goto LABEL_32;
            }
            *(_DWORD *)v14 = a1;
            LOBYTE(v38) = 47;
            HIWORD(v38) = 4;
            v15 = ipa_send_msg((unsigned __int8 *)&v38, v14, ipa3_socksv5_msg_free_cb);
            if ( !v15 )
            {
LABEL_32:
              mutex_unlock(ipa3_ctx + 51336);
              goto LABEL_33;
            }
            if ( (unsigned int)__ratelimit(&ipa_del_socksv5_conn__rs, "ipa_del_socksv5_conn") )
            {
              printk(&unk_3A28DF, "ipa_del_socksv5_conn");
              v16 = ipa3_ctx;
              if ( ipa3_ctx )
                goto LABEL_27;
            }
            else
            {
              v16 = ipa3_ctx;
              if ( ipa3_ctx )
              {
LABEL_27:
                v17 = *(_QWORD *)(v16 + 34152);
                if ( v17 )
                {
                  ipc_log_string(v17, "ipa %s:%d ipa_send_msg failed: %d\n", "ipa_del_socksv5_conn", 14818, v15);
                  v16 = ipa3_ctx;
                }
                v18 = *(_QWORD *)(v16 + 34160);
                if ( v18 )
                  ipc_log_string(v18, "ipa %s:%d ipa_send_msg failed: %d\n", "ipa_del_socksv5_conn", 14818, v15);
              }
            }
            kfree(v14);
            goto LABEL_32;
          }
          printk(&unk_3D3B1E, "ipa_del_socksv5_conn");
          v32 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v33 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v33 )
            {
              ipc_log_string(v33, "ipa %s:%d invalid handle, all tbl is empty!\n", "ipa_del_socksv5_conn", 14773);
              v32 = ipa3_ctx;
            }
            v34 = *(_QWORD *)(v32 + 34160);
            if ( v34 )
            {
              ipc_log_string(v34, "ipa %s:%d invalid handle, all tbl is empty!\n", "ipa_del_socksv5_conn", 14773);
              goto LABEL_59;
            }
          }
LABEL_60:
          v15 = -22;
          goto LABEL_33;
        }
        printk(&unk_3EA4D0, "ipa_del_socksv5_conn");
        v29 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_60;
        v30 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v30 )
        {
          ipc_log_string(v30, "ipa %s:%d invalid handle!\n", "ipa_del_socksv5_conn", 14768);
          v29 = ipa3_ctx;
        }
        v31 = *(_QWORD *)(v29 + 34160);
        if ( !v31 )
          goto LABEL_60;
        ipc_log_string(v31, "ipa %s:%d invalid handle!\n", "ipa_del_socksv5_conn", 14768);
      }
LABEL_59:
      v15 = -22;
      goto LABEL_33;
    }
    printk(&unk_3F8EB2, "ipa_del_socksv5_conn");
    v23 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_62;
    v24 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v24 )
    {
      ipc_log_string(v24, "ipa %s:%d uC act tbl haven't allocated\n", "ipa_del_socksv5_conn", 14758);
      v23 = ipa3_ctx;
    }
    v25 = *(_QWORD *)(v23 + 34160);
    if ( v25 )
    {
      ipc_log_string(v25, "ipa %s:%d uC act tbl haven't allocated\n", "ipa_del_socksv5_conn", 14758);
      v15 = -2;
    }
    else
    {
LABEL_62:
      v15 = -2;
    }
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return v15;
}
