__int64 __fastcall qrtr_node_rx_work(__int64 a1)
{
  __int64 v1; // x25
  __int64 v2; // x8
  __int64 v3; // x27
  __int64 result; // x0
  __int64 v5; // x26
  _UNKNOWN **v6; // x24
  int v7; // w8
  _UNKNOWN **i; // x20
  __int64 v9; // x0
  int v10; // w9
  __int64 v11; // x2
  int v12; // w8
  int v13; // w8
  int v14; // w0
  unsigned __int64 v15; // x23
  __int64 v16; // x25
  _QWORD *v17; // x20
  int v18; // w8
  int v19; // w9
  int v20; // w8
  __int64 v21; // x0
  __int64 v22; // x23
  _QWORD *v23; // x23
  _QWORD *v24; // x8
  _QWORD *v25; // t2
  __int64 v26; // x0
  __int64 v27; // x8
  int v34; // w9
  __int64 v35; // x0
  __int64 v36; // x27
  __int64 v37; // x3
  __int64 v38; // x4
  __int64 v39; // x5
  __int64 v40; // x6
  __int64 v41; // x7
  __int64 v42; // x0
  unsigned int v43; // w0
  int v46; // w8
  unsigned int v49; // w8
  unsigned int *v50; // [xsp+8h] [xbp-78h]
  __int64 v51; // [xsp+10h] [xbp-70h]
  __int64 v52; // [xsp+18h] [xbp-68h]
  __int64 v53; // [xsp+20h] [xbp-60h]
  __int64 v54; // [xsp+28h] [xbp-58h]
  __int64 v55; // [xsp+30h] [xbp-50h]
  __int64 v56; // [xsp+38h] [xbp-48h] BYREF
  __int64 v57; // [xsp+40h] [xbp-40h]
  int v58; // [xsp+48h] [xbp-38h]
  int v59; // [xsp+4Ch] [xbp-34h] BYREF
  int v60; // [xsp+50h] [xbp-30h]
  int v61; // [xsp+54h] [xbp-2Ch]
  char s[8]; // [xsp+58h] [xbp-28h] BYREF
  __int64 v63; // [xsp+60h] [xbp-20h]
  __int64 v64; // [xsp+68h] [xbp-18h]
  __int64 v65; // [xsp+70h] [xbp-10h]
  __int64 v66; // [xsp+78h] [xbp-8h]

  v1 = a1;
  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 104);
  v64 = 0;
  v65 = 0;
  *(_QWORD *)s = 0;
  v63 = 0;
  if ( !v2 )
  {
    snprintf(s, 0x20u, "qrtr_%d", *(_DWORD *)(a1 - 188));
    *(_QWORD *)(v1 + 104) = ipc_log_context_create(4, s, 0);
  }
  v3 = v1 - 104;
  result = skb_dequeue(v1 - 104);
  if ( result )
  {
    v5 = result;
    v6 = (_UNKNOWN **)(v1 - 248);
    v52 = v1 - 168;
    v53 = v1 - 152;
    v50 = (unsigned int *)(v1 - 176);
    v54 = v1;
    v55 = v1 - 104;
    while ( 1 )
    {
      v7 = *(unsigned __int8 *)(v5 + 56);
      if ( v7 != 1 )
      {
        down_read(&qrtr_epts_lock);
        for ( i = (_UNKNOWN **)qrtr_all_epts; i != &qrtr_all_epts; i = (_UNKNOWN **)*i )
        {
          LODWORD(v56) = 42;
          v59 = 42;
          if ( !v6 )
            goto LABEL_9;
          if ( i != (_UNKNOWN **)&unk_A8 )
          {
            v12 = *(unsigned __int8 *)(v5 + 56);
            if ( v12 != 2 && v12 != 7 && i - 21 != v6 && *((_DWORD *)i - 27) != -1 )
            {
              v13 = *((_DWORD *)i - 26) - *(_DWORD *)(v1 - 184);
              if ( v13 < 0 )
                v13 = *(_DWORD *)(v1 - 184) - *((_DWORD *)i - 26);
              if ( v13 >= 2 )
              {
LABEL_9:
                v9 = skb_clone(v5, 3264);
                if ( !v9 )
                  break;
                v10 = *(_DWORD *)(v5 + 44);
                v11 = *(unsigned __int8 *)(v5 + 56);
                HIDWORD(v56) = *(_DWORD *)(v5 + 40);
                LODWORD(v57) = v10;
                v60 = *((_DWORD *)i - 27);
                v61 = -2;
                qrtr_node_enqueue(i - 21, v9, v11, &v56, &v59, 0);
              }
            }
          }
        }
        up_read(&qrtr_epts_lock);
        v7 = *(unsigned __int8 *)(v5 + 56);
        if ( v7 == 7 )
        {
          v14 = *(_DWORD *)(v5 + 48);
          if ( v14 == qrtr_local_nid )
          {
            v58 = 0;
            v56 = 0;
            v57 = 0;
            skb_copy_bits(v5, 0, &v56, 20);
            if ( (_DWORD)v56 == 7 )
            {
              v59 = 42;
              v60 = HIDWORD(v56);
              v15 = (unsigned int)v57 | ((unsigned __int64)HIDWORD(v56) << 32);
              v61 = v57;
              mutex_lock(v53);
              v16 = radix_tree_lookup(v52, v15);
              mutex_unlock(v53);
              if ( v16 )
              {
                v51 = raw_spin_lock_irqsave(v16 + 48);
                *(_DWORD *)(v16 + 24) = 0;
                _wake_up(v16, 1, 0, 0);
                v17 = *(_QWORD **)(v16 + 32);
                while ( v17 != (_QWORD *)(v16 + 32) )
                {
                  v23 = v17;
                  v25 = v17;
                  v17 = (_QWORD *)*v17;
                  v24 = (_QWORD *)v25[1];
                  if ( (_QWORD *)*v24 == v23 && (_QWORD *)v17[1] == v23 )
                  {
                    v17[1] = v24;
                    *v24 = v17;
                  }
                  else
                  {
                    _list_del_entry_valid_or_report(v23);
                  }
                  *v23 = 0xDEAD000000000100LL;
                  v23[1] = 0xDEAD000000000122LL;
                  v26 = _alloc_skb(0, 2080, 0, 0xFFFFFFFFLL);
                  if ( v26 )
                    qrtr_local_enqueue(v26, v26, 7, &v59, v23[2] + 840LL);
                  v27 = v23[2];
                  _X0 = (unsigned int *)(v27 + 128);
                  __asm { PRFM            #0x11, [X0] }
                  do
                    v34 = __ldxr(_X0);
                  while ( __stlxr(v34 - 1, _X0) );
                  if ( v34 == 1 )
                  {
                    __dmb(9u);
                    sk_free(v27);
                  }
                  else if ( v34 <= 0 )
                  {
                    refcount_warn_saturate();
                  }
                  kfree(v23);
                }
                raw_spin_unlock_irqrestore(v16 + 48, v51);
                consume_skb(v5);
                v3 = v55;
              }
            }
            v1 = v54;
            goto LABEL_6;
          }
LABEL_30:
          v18 = *(_DWORD *)(v5 + 40);
          v19 = *(_DWORD *)(v5 + 44);
          v59 = 42;
          v60 = v14;
          LODWORD(v56) = 42;
          HIDWORD(v56) = v18;
          v20 = *(_DWORD *)(v5 + 52);
          LODWORD(v57) = v19;
          v61 = v20;
          v21 = qrtr_node_lookup();
          if ( v21 )
          {
            v22 = v21;
            qrtr_node_enqueue(v21, v5, *(unsigned __int8 *)(v5 + 56), &v56, &v59, 0);
            qrtr_node_release(v22);
          }
          else
          {
            sk_skb_reason_drop(0, v5, 2);
          }
          goto LABEL_6;
        }
      }
      if ( v7 == 1 )
      {
        v14 = *(_DWORD *)(v5 + 48);
        if ( v14 != qrtr_local_nid )
          goto LABEL_30;
      }
      v35 = qrtr_port_lookup(*(_DWORD *)(v5 + 52));
      if ( v35 )
        break;
      sk_skb_reason_drop(0, v5, 2);
LABEL_61:
      v3 = v55;
LABEL_6:
      result = skb_dequeue(v3);
      v5 = result;
      if ( !result )
        goto LABEL_71;
    }
    v36 = v35;
    if ( *(_BYTE *)(v5 + 56) == 2 )
    {
      if ( *(_DWORD *)(v1 - 176) )
        goto LABEL_50;
      _X10 = v50;
      __asm { PRFM            #0x11, [X10] }
      do
        v49 = __ldxr(v50);
      while ( __stxr(v49 + 1, v50) );
    }
    if ( *(_DWORD *)(v35 + 848) == -2 )
    {
      while ( 1 )
      {
        v43 = sock_queue_rcv_skb_reason(v36, v5, 0);
        if ( v43 != -12 )
        {
          v37 = v43;
          if ( v43 != -105 )
            break;
        }
        v42 = raw_spin_lock_irqsave(v36 + 908);
        *(_DWORD *)(v36 + 872) = 0;
        *(_BYTE *)(v36 + 904) = 1;
        raw_spin_unlock_irqrestore(v36 + 908, v42);
        wait_for_completion(v36 + 872);
      }
    }
    else
    {
      v37 = (unsigned int)sock_queue_rcv_skb_reason(v35, v5, 0);
    }
    if ( !(_DWORD)v37 )
      goto LABEL_59;
    printk(&unk_DECD, "qrtr_sock_queue_skb", *(unsigned __int8 *)(v5 + 57), v37, v38, v39, v40, v41);
LABEL_50:
    sk_skb_reason_drop(0, v5, 2);
LABEL_59:
    _X0 = (unsigned int *)(v36 + 128);
    __asm { PRFM            #0x11, [X0] }
    do
      v46 = __ldxr(_X0);
    while ( __stlxr(v46 - 1, _X0) );
    if ( v46 != 1 )
    {
      v3 = v55;
      if ( v46 <= 0 )
        refcount_warn_saturate();
      goto LABEL_6;
    }
    __dmb(9u);
    sk_free(v36);
    goto LABEL_61;
  }
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return result;
}
