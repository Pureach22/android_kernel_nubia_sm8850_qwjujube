__int64 __fastcall qrtr_node_enqueue(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5, char a6)
{
  int v12; // w27
  unsigned int v13; // w20
  __int64 v15; // x28
  unsigned __int64 v16; // x23
  unsigned __int64 v17; // x26
  __int64 v18; // x23
  int *v19; // x25
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  int v23; // w8
  int *v24; // x8
  int v25; // w8
  _DWORD *v26; // x0
  _DWORD *v27; // x25
  int v28; // w8
  unsigned int v29; // w24
  unsigned int v30; // w8
  int v31; // w9
  unsigned int v32; // w8
  unsigned int v33; // w25
  unsigned int v34; // w26
  __int64 v35; // x11
  __int64 v36; // x27
  __int64 v37; // x28
  unsigned int v38; // w9
  unsigned int v39; // w23
  __int64 v40; // x12
  int v41; // w11
  unsigned __int64 v42; // x10
  __int64 v43; // x12
  unsigned int v44; // w8
  int v45; // w24
  unsigned int v46; // w9
  unsigned int v47; // w9
  unsigned int v48; // w8
  unsigned int v49; // w24
  __int64 v50; // x0
  __int64 v51; // x1
  __int64 v52; // x5
  __int64 v53; // x6
  __int64 v54; // x7
  unsigned int v55; // w9
  __int64 (**v56)(void); // x0
  __int64 (*v57)(void); // x8
  unsigned __int64 v58; // x21
  __int64 v59; // x21
  unsigned __int64 v60; // x11
  unsigned int v61; // w10
  unsigned int v62; // w8
  __int64 v63; // x8
  __int64 v64; // x0
  __int64 v65; // x23
  int v66; // w4
  int v67; // w5
  __int64 v68; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v70; // x2
  unsigned int v73; // w9
  unsigned int v80; // w10
  int v81; // [xsp+20h] [xbp-40h]
  __int64 v82; // [xsp+28h] [xbp-38h] BYREF
  __int64 v83; // [xsp+30h] [xbp-30h]
  __int64 v84; // [xsp+38h] [xbp-28h]
  __int64 v85; // [xsp+40h] [xbp-20h]
  __int64 v86; // [xsp+48h] [xbp-18h]
  _QWORD v87[2]; // [xsp+50h] [xbp-10h] BYREF

  v87[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_DWORD *)(a2 + 112);
  mutex_lock(a1);
  if ( a3 != 2 && !*(_DWORD *)(a1 + 68) || a3 == 2 && *(_DWORD *)(a1 + 68) )
  {
    sk_skb_reason_drop(0, a2, 2);
    mutex_unlock(a1);
    v13 = 0;
    goto LABEL_6;
  }
  if ( a3 == 2 && !*(_DWORD *)(a1 + 68) )
  {
    _X8 = (unsigned int *)(a1 + 68);
    __asm { PRFM            #0x11, [X8] }
    do
      v73 = __ldxr(_X8);
    while ( __stxr(v73 + 1, _X8) );
  }
  mutex_unlock(a1);
  v15 = *(_QWORD *)(a2 + 24);
  if ( v15 )
  {
    if ( a3 == 1 )
    {
      v16 = *(unsigned int *)(a5 + 8) | ((unsigned __int64)*(unsigned int *)(a5 + 4) << 32);
      if ( (a6 & 0x40) != 0 )
        v17 = 0;
      else
        v17 = *(_QWORD *)(v15 + 512);
      mutex_lock(a1 + 96);
      v19 = (int *)radix_tree_lookup(a1 + 80, v16);
      if ( v19 )
      {
LABEL_17:
        mutex_unlock(a1 + 96);
        raw_spin_lock_irq(v19 + 12);
        if ( v19[6] < 10 || v19[7] )
        {
          v18 = v17;
          if ( !v17 )
          {
            v18 = 1;
            goto LABEL_28;
          }
        }
        else
        {
          v21 = *(_QWORD *)(a1 + 48);
          if ( v21 | v17 )
            v18 = v17;
          else
            v18 = 1;
          if ( v21 && v18 )
          {
            v85 = 0;
            v86 = 0;
            v83 = 0;
            v84 = 0;
            v82 = 0;
            init_wait_entry(&v82, 0);
            v22 = prepare_to_wait_event(v19, &v82, 1);
            if ( v19[6] >= 10 )
            {
              v18 = v22;
              do
              {
                if ( v19[7] )
                  break;
                v63 = *(_QWORD *)(a1 + 48);
                if ( !(v63 | v17) )
                  v17 = 1;
                if ( !v63 || !v17 )
                  goto LABEL_40;
                if ( v18 )
                  goto LABEL_20;
                raw_spin_unlock_irq(v19 + 12);
                v17 = schedule_timeout(v17);
                raw_spin_lock_irq(v19 + 12);
                v18 = prepare_to_wait_event(v19, &v82, 1);
              }
              while ( v19[6] >= 10 );
            }
            if ( v17 <= 1 )
              v17 = 1;
LABEL_40:
            finish_wait(v19, &v82);
            v18 = v17;
          }
        }
LABEL_20:
        if ( v18 < 0 )
        {
          raw_spin_unlock_irq(v19 + 12);
          if ( (v18 & 0x80000000) != 0 )
            goto LABEL_113;
          goto LABEL_49;
        }
LABEL_28:
        if ( *(_QWORD *)(a1 + 48) )
        {
          if ( v19[7] )
          {
            v19[7] = 0;
            LODWORD(v18) = 1;
LABEL_48:
            raw_spin_unlock_irq(v19 + 12);
            goto LABEL_49;
          }
          v23 = v19[6];
          if ( v18 || v23 < 10 )
          {
            v25 = v23 + 1;
            v19[6] = v25;
            LODWORD(v18) = v25 == 5;
            goto LABEL_48;
          }
          v24 = v19 + 8;
          while ( 1 )
          {
            v24 = *(int **)v24;
            if ( v24 == v19 + 8 )
              break;
            if ( *((_QWORD *)v24 + 2) == v15 )
              goto LABEL_111;
          }
          v64 = _kmalloc_cache_noprof(kthread_create_on_node, 2336, 24);
          if ( v64 )
          {
            *(_QWORD *)(v64 + 16) = v15;
            v65 = v64;
            refcount_inc(v15 + 128);
            list_add_tail(v65, v19 + 8);
            v66 = *(_DWORD *)(a5 + 4);
            v67 = *(_DWORD *)(a5 + 8);
            v68 = *(_QWORD *)(a1 + 352);
            StatusReg = _ReadStatusReg(SP_EL0);
            ipc_log_string(
              v68,
              "new waiter %s[%d] for [0x%x:0x%x]\n",
              (const char *)(StatusReg + 2320),
              *(_DWORD *)(StatusReg + 1800),
              v66,
              v67);
LABEL_111:
            LODWORD(v18) = -11;
          }
          else
          {
            LODWORD(v18) = -12;
          }
        }
        else
        {
          LODWORD(v18) = -32;
        }
        raw_spin_unlock_irq(v19 + 12);
LABEL_113:
        sk_skb_reason_drop(0, a2, 2);
        v13 = v18;
        goto LABEL_6;
      }
      v20 = _kmalloc_cache_noprof(kfree, 3520, 56);
      v19 = (int *)v20;
      if ( v20 )
      {
        *(_QWORD *)(v20 + 32) = v20 + 32;
        *(_QWORD *)(v20 + 40) = v20 + 32;
        _init_waitqueue_head(v20, "&flow->resume_tx", &qrtr_tx_wait___key);
        v19[12] = 0;
        if ( !(unsigned int)radix_tree_insert(a1 + 80, v16, v19) )
          goto LABEL_17;
        kfree(v19);
      }
      mutex_unlock(a1 + 96);
      LODWORD(v18) = 1;
    }
    else
    {
      LODWORD(v18) = 0;
    }
  }
  else
  {
    LODWORD(v18) = *(unsigned __int8 *)(a2 + 57);
  }
LABEL_49:
  v26 = (_DWORD *)skb_push(a2, 32);
  v27 = v26;
  *v26 = 1;
  v26[1] = a3;
  v26[2] = *(_DWORD *)(a4 + 4);
  v26[3] = *(_DWORD *)(a4 + 8);
  if ( *(_DWORD *)(a5 + 8) == -2 )
  {
    v26[6] = *(_DWORD *)(a1 + 60);
    v28 = -2;
  }
  else
  {
    v26[6] = *(_DWORD *)(a5 + 4);
    v28 = *(_DWORD *)(a5 + 8);
  }
  v26[7] = v28;
  v82 = 0;
  v83 = 0;
  v26[4] = v18 != 0;
  v26[5] = v12;
  LODWORD(v84) = 0;
  v87[0] = 0;
  if ( a2 && v26 )
  {
    v29 = v26[1];
    if ( v29 == 1 )
    {
      skb_copy_bits(a2, 32, v87, 8);
      ipc_log_string(
        *(_QWORD *)(a1 + 352),
        "TX DATA: Len:0x%x CF:0x%x src[0x%x:0x%x] dst[0x%x:0x%x] [%08x %08x] [%s]\n",
        v27[5],
        v27[4],
        v27[2],
        v27[3],
        v27[6],
        v27[7],
        LODWORD(v87[0]),
        HIDWORD(v87[0]),
        (const char *)(_ReadStatusReg(SP_EL0) + 2320));
    }
    else
    {
      skb_copy_bits(a2, 32, &v82, 20);
      v30 = v29 & 0xFFFFFFFE;
      if ( (v29 & 0xFFFFFFFE) == 2 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 352), "TX CTRL: cmd:0x%x node[0x%x]\n", v29, (unsigned int)v27[2]);
      }
      else if ( v30 == 6 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 352), "TX CTRL: cmd:0x%x addr[0x%x:0x%x]\n", v29, HIDWORD(v82), v83);
      }
      else if ( v30 == 4 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 352),
          "TX CTRL: cmd:0x%x SVC[0x%x:0x%x] addr[0x%x:0x%x]\n",
          v29,
          HIDWORD(v82),
          v83,
          HIDWORD(v83),
          v84);
      }
      else if ( v29 == 13 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 352), "TX CTRL: cmd:0x%x node[0x%x]\n", 13, (unsigned int)v83);
      }
    }
  }
  v31 = *(_DWORD *)(a2 + 116);
  v81 = v18;
  if ( !v31 )
  {
    v47 = *(_DWORD *)(a2 + 112);
    v48 = ((v12 + 3) & 0xFFFFFFFC) + 32;
    v49 = v48 - v47;
    if ( v48 <= v47 )
      goto LABEL_85;
    v50 = _skb_pad(a2, v49, 1);
    if ( (_DWORD)v50 )
    {
      v70 = *(unsigned int *)(a2 + 112);
      v13 = -12;
      printk(&unk_E0AA, "qrtr_node_enqueue", v70, ((_DWORD)v70 + 3) & 0xFFFFFFFC, 4294967284LL, v52, v53, v54);
      goto LABEL_91;
    }
    if ( !*(_DWORD *)(a2 + 116) )
    {
      v55 = *(_DWORD *)(a2 + 112) + v49;
      *(_DWORD *)(a2 + 208) += v49;
      *(_DWORD *)(a2 + 112) = v55;
      goto LABEL_85;
    }
    __break(0x800u);
    return list_add_tail(v50, v51);
  }
  v32 = *(_DWORD *)(a2 + 112);
  v33 = (v32 + 3) & 0xFFFFFFFC;
  v34 = v33 - v32;
  if ( v33 == v32 )
    goto LABEL_85;
  v35 = *(unsigned int *)(a2 + 212);
  if ( !*(_BYTE *)(*(_QWORD *)(a2 + 216) + v35 + 2) )
  {
LABEL_83:
    if ( v32 != v33 )
      __break(0x800u);
    goto LABEL_85;
  }
  v36 = 16LL * *(unsigned __int8 *)(*(_QWORD *)(a2 + 216) + v35 + 2);
  v37 = 0;
  v38 = v32 - v31;
  while ( 1 )
  {
    if ( v37 == 288 )
      __break(0x5512u);
    v40 = *(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + v37;
    v41 = *(_DWORD *)(v40 + 96);
    v39 = v41 + v38;
    if ( v41 + v38 < v32 )
      goto LABEL_70;
    v42 = *(unsigned int *)(v40 + 100);
    v43 = *(_QWORD *)(v40 + 88);
    if ( v39 >= v33 )
      break;
    if ( (v43 & 1) != 0 )
      v43 = 0;
    if ( !v41 )
      goto LABEL_69;
    v44 = v32 - v38;
    v45 = v41 - v44;
    memset(
      (void *)(((((v43 + ((v42 >> 6) & 0x3FFFFC0)) << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL
              | 0xFF00000000000000LL)
             + (v42 & 0xFFF)
             + v44),
      0,
      v41 - v44);
    v34 -= v45;
    v32 = *(_DWORD *)(a2 + 112) + v45;
    v46 = *(_DWORD *)(a2 + 116) + v34;
    *(_DWORD *)(a2 + 112) = v32;
    *(_DWORD *)(a2 + 116) = v46;
    if ( v32 == v33 )
      goto LABEL_85;
LABEL_70:
    v37 += 16;
    v38 = v39;
    if ( v36 == v37 )
      goto LABEL_83;
  }
  if ( !v41 )
  {
LABEL_69:
    v39 = v38;
    if ( v32 == v33 )
      goto LABEL_85;
    goto LABEL_70;
  }
  v60 = v42 >> 6;
  v61 = v42 & 0xFFF;
  if ( (v43 & 1) != 0 )
    v43 = 0;
  memset(
    (void *)(((((v43 + (v60 & 0x3FFFFC0)) << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
           + v61
           + v32
           - v38),
    0,
    v34);
  v62 = *(_DWORD *)(a2 + 116) + v34;
  *(_DWORD *)(a2 + 112) = v33;
  *(_DWORD *)(a2 + 116) = v62;
LABEL_85:
  mutex_lock(a1);
  v56 = *(__int64 (***)(void))(a1 + 48);
  if ( v56 )
  {
    v57 = *v56;
    if ( *((_DWORD *)*v56 - 1) != -1070807168 )
      __break(0x8228u);
    v13 = v57();
  }
  else
  {
    sk_skb_reason_drop(0, a2, 2);
    v13 = -19;
  }
  LODWORD(v18) = v81;
  mutex_unlock(a1);
  if ( v13 )
  {
LABEL_91:
    if ( (_DWORD)v18 )
    {
      v58 = *(int *)(a5 + 8) | ((unsigned __int64)*(unsigned int *)(a5 + 4) << 32);
      mutex_lock(a1 + 96);
      v59 = radix_tree_lookup(a1 + 80, v58);
      mutex_unlock(a1 + 96);
      if ( v59 )
      {
        raw_spin_lock_irq(v59 + 48);
        *(_DWORD *)(v59 + 28) = 1;
        raw_spin_unlock_irq(v59 + 48);
      }
    }
  }
  if ( a3 == 2 && v13 )
  {
    _X8 = (unsigned int *)(a1 + 68);
    __asm { PRFM            #0x11, [X8] }
    do
      v80 = __ldxr(_X8);
    while ( __stxr(v80 - 1, _X8) );
    kthread_queue_work(a1 + 184, a1 + 288);
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return v13;
}
