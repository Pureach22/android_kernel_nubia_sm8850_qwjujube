__int64 __fastcall ipa_send_msg(unsigned __int8 *a1, _WORD *a2, _DWORD *a3)
{
  char *v3; // x23
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 result; // x0
  unsigned int v11; // w8
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x2
  _DWORD *v20; // x0
  _QWORD *v21; // x22
  unsigned int v22; // w8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x2
  __int64 *v26; // x1
  int v27; // w8
  unsigned __int64 v28; // x24
  unsigned __int8 *v29; // x25
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  _DWORD *v33; // x0
  _QWORD *v34; // x22
  unsigned int v35; // w8
  char *v36; // x0
  size_t v37; // x2
  __int64 v38; // x8
  _QWORD *v39; // x0
  __int64 v40; // x2
  _QWORD *v41; // x1
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x8
  _QWORD *v46; // x25
  int v47; // w22
  __int64 v48; // x10
  _QWORD *v49; // x24
  __int64 v50; // x9
  __int64 v51; // x10
  __int64 v53; // x0
  __int64 v54; // x0
  _QWORD *v55; // x8
  _QWORD *v56; // x9
  __int64 v57; // x8
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x8
  __int64 v61; // x0
  __int64 v62; // x0
  unsigned __int64 v63; // x8
  int v64; // [xsp+18h] [xbp-18h]
  __int16 v65; // [xsp+1Ch] [xbp-14h]

  _ReadStatusReg(SP_EL0);
  if ( !a1 || !a2 && a3 || a2 && !a3 )
  {
    if ( (unsigned int)__ratelimit(&ipa_send_msg__rs, "ipa_send_msg") )
      printk(&unk_3D8823, "ipa_send_msg");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d invalid param meta=%pK buff=%pK, callback=%pK\n", "ipa_send_msg", 511, a1, a2, a3);
        v7 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v7 + 34160);
      if ( v9 )
        ipc_log_string(v9, "ipa %s:%d invalid param meta=%pK buff=%pK, callback=%pK\n", "ipa_send_msg", 511, a1, a2, a3);
    }
    goto LABEL_13;
  }
  v11 = *a1;
  if ( v11 >= 0x3A )
  {
    if ( (unsigned int)__ratelimit(&ipa_send_msg__rs_45, "ipa_send_msg") )
    {
      printk(&unk_3FE156, "ipa_send_msg");
      v12 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_18:
        v13 = *(_QWORD *)(v12 + 34152);
        if ( v13 )
        {
          ipc_log_string(v13, "ipa %s:%d unsupported message type %d\n", "ipa_send_msg", 516, *a1);
          v12 = ipa3_ctx;
        }
        v14 = *(_QWORD *)(v12 + 34160);
        if ( v14 )
        {
          ipc_log_string(v14, "ipa %s:%d unsupported message type %d\n", "ipa_send_msg", 516, *a1);
          result = 4294967274LL;
          goto LABEL_14;
        }
      }
    }
    else
    {
      v12 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_18;
    }
LABEL_13:
    result = 4294967274LL;
    goto LABEL_14;
  }
  if ( *(_BYTE *)(ipa3_ctx + 32267) != 1 || v11 > 0xA || ((1 << v11) & 0x7C3) == 0 )
  {
    v20 = (_DWORD *)_kmalloc_cache_noprof(ipc_log_string, 3520, 40);
    v21 = v20;
    if ( v20 )
    {
      v22 = *(_DWORD *)a1;
      *v20 = *(_DWORD *)a1;
      if ( !a2 || v22 < 0x10000 )
        goto LABEL_41;
      v23 = kmemdup_noprof(a2, *((unsigned __int16 *)a1 + 1), 3264);
      if ( v23 )
      {
        v21[1] = ipa_send_msg_free;
        v21[2] = v23;
LABEL_41:
        mutex_lock(ipa3_ctx + 32104);
        v24 = (__int64)(v21 + 3);
        v25 = ipa3_ctx + 32072;
        v26 = *(__int64 **)(ipa3_ctx + 32080);
        if ( v21 + 3 == (_QWORD *)(ipa3_ctx + 32072) || v26 == (__int64 *)v24 || *v26 != v25 )
          goto LABEL_117;
        *(_QWORD *)(ipa3_ctx + 32080) = v24;
        v21[3] = v25;
        v21[4] = v26;
        *v26 = v24;
        if ( !a2 )
          goto LABEL_104;
LABEL_45:
        v27 = *a1;
        if ( v27 != 10 )
        {
LABEL_64:
          if ( v27 != 1 )
            goto LABEL_110;
          v42 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v43 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v43 )
            {
              ipc_log_string(v43, "ipa %s:%d Mac %pM, msg %d\n", "wlan_msg_process", 451, a2 + 16, 1);
              v42 = ipa3_ctx;
            }
            v44 = *(_QWORD *)(v42 + 34160);
            if ( v44 )
              ipc_log_string(v44, "ipa %s:%d Mac %pM, msg %d\n", "wlan_msg_process", 451, a2 + 16, *a1);
          }
          v64 = *((_DWORD *)a2 + 8);
          v65 = a2[18];
          mutex_lock(ipa3_ctx + 32168);
          v45 = ipa3_ctx;
          v46 = *(_QWORD **)(ipa3_ctx + 32152);
          if ( v46 != (_QWORD *)(ipa3_ctx + 32152) )
          {
            v47 = 0;
            v3 = (_BYTE *)&unk_7D98;
            do
            {
              v48 = *(v46 - 1);
              v49 = (_QWORD *)*v46;
              v50 = *(unsigned __int8 *)(v48 + 32);
              if ( *(_BYTE *)(v48 + 32) )
              {
                v51 = v48 + 36;
                while ( *(_DWORD *)v51 || v64 != *(_DWORD *)(v51 + 5) || v65 != *(_WORD *)(v51 + 9) )
                {
                  --v50;
                  v51 += 12;
                  if ( !v50 )
                    goto LABEL_78;
                }
                if ( v45 )
                {
                  v53 = *(_QWORD *)(v45 + 34152);
                  if ( v53 )
                  {
                    ipc_log_string(v53, "ipa %s:%d clean %d\n", "wlan_msg_process", 473, v47);
                    v45 = ipa3_ctx;
                  }
                  v54 = *(_QWORD *)(v45 + 34160);
                  if ( v54 )
                    ipc_log_string(v54, "ipa %s:%d clean %d\n", "wlan_msg_process", 473, v47);
                }
                v55 = (_QWORD *)v46[1];
                if ( (_QWORD *)*v55 == v46 && (v56 = (_QWORD *)*v46, *(_QWORD **)(*v46 + 8LL) == v46) )
                {
                  v56[1] = v55;
                  *v55 = v56;
                }
                else
                {
                  _list_del_entry_valid_or_report(v46);
                }
                *v46 = 0xDEAD000000000100LL;
                v46[1] = 0xDEAD000000000122LL;
                kfree(v46 - 3);
                v45 = ipa3_ctx;
              }
LABEL_78:
              ++v47;
              v46 = v49;
            }
            while ( v49 != (_QWORD *)(v45 + 32152) );
          }
          mutex_unlock(v45 + 32168);
          goto LABEL_110;
        }
        if ( *((_BYTE *)a2 + 32) )
        {
          v28 = 0;
          v29 = (unsigned __int8 *)(a2 + 23);
          v3 = "wlan_msg_process";
          do
          {
            if ( !*(_DWORD *)(v29 - 10) )
            {
              v30 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v31 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v31 )
                {
                  ipc_log_string(
                    v31,
                    "ipa %s:%d %02x:%02x:%02x:%02x:%02x:%02x,(%d)\n",
                    "wlan_msg_process",
                    414,
                    *(v29 - 5),
                    *(v29 - 4),
                    *(v29 - 3),
                    *(v29 - 2),
                    *(v29 - 1),
                    *v29,
                    *a1);
                  v30 = ipa3_ctx;
                }
                v32 = *(_QWORD *)(v30 + 34160);
                if ( v32 )
                  ipc_log_string(
                    v32,
                    "ipa %s:%d %02x:%02x:%02x:%02x:%02x:%02x,(%d)\n",
                    "wlan_msg_process",
                    414,
                    *(v29 - 5),
                    *(v29 - 4),
                    *(v29 - 3),
                    *(v29 - 2),
                    *(v29 - 1),
                    *v29,
                    *a1);
              }
            }
            ++v28;
            v29 += 12;
          }
          while ( v28 < *((unsigned __int8 *)a2 + 32) );
        }
        mutex_lock(ipa3_ctx + 32168);
        v33 = (_DWORD *)_kmalloc_cache_noprof(ipc_log_string, 3520, 40);
        v34 = v33;
        if ( v33 )
        {
          v35 = *(_DWORD *)a1;
          *v33 = *(_DWORD *)a1;
          if ( v35 < 0x10000 )
          {
            printk(&unk_3C705A, "wlan_msg_process");
            v57 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v58 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v58 )
              {
                ipc_log_string(v58, "ipa %s:%d msg_len %d\n", "wlan_msg_process", 436, *((unsigned __int16 *)a1 + 1));
                v57 = ipa3_ctx;
              }
              v59 = *(_QWORD *)(v57 + 34160);
              if ( v59 )
                ipc_log_string(v59, "ipa %s:%d msg_len %d\n", "wlan_msg_process", 436, *((unsigned __int16 *)a1 + 1));
            }
          }
          else
          {
            v3 = (char *)*((unsigned __int16 *)a1 + 1);
            v36 = (char *)kmemdup_noprof(a2, v3, 3264);
            if ( v36 )
            {
              v37 = *((unsigned __int16 *)a1 + 1);
              if ( (unsigned __int64)v3 < v37 )
                goto LABEL_116;
              v3 = v36;
              memcpy(v36, a2, v37);
              v38 = ipa3_ctx;
              v34[1] = ipa_send_msg_free;
              v34[2] = v3;
              v39 = v34 + 3;
              v40 = v38 + 32152;
              v41 = *(_QWORD **)(v38 + 32160);
              if ( v34 + 3 == (_QWORD *)(v38 + 32152) || v41 == v39 || *v41 != v40 )
              {
                _list_add_valid_or_report(v39, v41);
              }
              else
              {
                *(_QWORD *)(v38 + 32160) = v39;
                v34[3] = v40;
                v34[4] = v41;
                *v41 = v39;
              }
              mutex_unlock(ipa3_ctx + 32168);
              v27 = *a1;
              goto LABEL_64;
            }
          }
          kfree(v34);
        }
        mutex_unlock(ipa3_ctx + 32168);
        while ( 1 )
        {
LABEL_104:
          if ( (unsigned int)__ratelimit(&ipa_send_msg__rs_53, "ipa_send_msg") )
          {
            printk(&unk_3F54B6, "ipa_send_msg");
            v60 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_110;
          }
          else
          {
            v60 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_110;
          }
          v61 = *(_QWORD *)(v60 + 34152);
          if ( v61 )
          {
            ipc_log_string(v61, "ipa %s:%d wlan_msg_process failed\n", "ipa_send_msg", 547);
            v60 = ipa3_ctx;
          }
          v62 = *(_QWORD *)(v60 + 34160);
          if ( v62 )
            ipc_log_string(v62, "ipa %s:%d wlan_msg_process failed\n", "ipa_send_msg", 547);
LABEL_110:
          mutex_unlock(ipa3_ctx + 32104);
          v63 = *a1;
          if ( v63 < 0x3B )
          {
            ++*(_DWORD *)(ipa3_ctx + 4 * v63 + 32364);
            _wake_up(ipa3_ctx + 32216, 3, 1, 0);
            if ( !a2 )
              goto LABEL_35;
            goto LABEL_32;
          }
          __break(0x5512u);
LABEL_116:
          v24 = _fortify_panic(17, v3, v37);
LABEL_117:
          _list_add_valid_or_report(v24, v26);
          if ( a2 )
            goto LABEL_45;
        }
      }
      kfree(v21);
    }
    result = 4294967284LL;
    goto LABEL_14;
  }
  if ( (unsigned int)__ratelimit(&ipa_send_msg__rs_48, "ipa_send_msg") )
  {
    printk(&unk_3FE17F, "ipa_send_msg");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
      goto LABEL_27;
  }
  else
  {
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
LABEL_27:
      v16 = *(_QWORD *)(v15 + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d Opt data path enabled, ignore message type %d\n", "ipa_send_msg", 522, *a1);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(v17, "ipa %s:%d Opt data path enabled, ignore message type %d\n", "ipa_send_msg", 522, *a1);
    }
  }
  if ( !a2 )
    goto LABEL_35;
LABEL_32:
  v18 = *((unsigned __int16 *)a1 + 1);
  v19 = *a1;
  if ( *(a3 - 1) != -1844471269 )
    __break(0x8234u);
  ((void (__fastcall *)(_WORD *, __int64, __int64))a3)(a2, v18, v19);
LABEL_35:
  result = 0;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
