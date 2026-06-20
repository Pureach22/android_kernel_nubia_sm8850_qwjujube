__int64 __fastcall qrtr_endpoint_post(__int64 a1, unsigned __int8 *a2, unsigned __int64 a3)
{
  __int64 result; // x0
  __int64 v6; // x19
  __int64 v8; // x4
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x7
  __int64 v15; // x20
  __int64 *v16; // x0
  __int64 v17; // x0
  int v18; // w9
  __int64 v19; // x1
  int v20; // w8
  __int64 v21; // x11
  __int64 v22; // x9
  int v23; // w10
  __int64 v24; // x9
  int v25; // w12
  __int64 v26; // x3
  unsigned __int8 *v27; // x21
  __int64 v28; // x22
  __int64 v29; // x23
  int v30; // w8
  int v31; // w8
  unsigned int v32; // w19
  unsigned int v33; // w20
  unsigned int v34; // w22
  unsigned int v35; // w23
  unsigned int v36; // w2
  __int64 v37; // x4
  __int64 v38; // x5
  __int64 v39; // x6
  __int64 v40; // x7
  unsigned int service_id; // w0
  __int64 v42; // x7
  __int64 v43; // x6
  __int64 v44; // x7
  __int64 v45; // x3
  __int64 v46; // x4
  __int64 v47; // x5
  __int64 v48; // x6
  __int64 v49; // x7
  int v50; // w0
  int v51; // w22
  __int64 v52; // x0
  __int64 v53; // x21
  int v54; // [xsp+14h] [xbp-2Ch] BYREF
  __int64 v55; // [xsp+18h] [xbp-28h] BYREF
  __int64 v56; // [xsp+20h] [xbp-20h] BYREF
  __int64 v57; // [xsp+28h] [xbp-18h]
  unsigned int v58; // [xsp+30h] [xbp-10h]
  __int64 v59; // [xsp+38h] [xbp-8h]

  result = 4294967274LL;
  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 || (a3 & 3) != 0 )
    goto LABEL_60;
  v6 = *(_QWORD *)(a1 + 8);
  if ( *(_BYTE *)(a1 + 16) )
    v8 = 11456;
  else
    v8 = 10272;
  v54 = 0;
  v15 = alloc_skb_with_frags(32, a3, 0, &v54, v8);
  if ( !v15 )
  {
    if ( a3 >= 0x400 )
    {
      if ( a3 >> 14 )
        goto LABEL_47;
      v16 = &qrtr_backup_hi;
    }
    else
    {
      v16 = &qrtr_backup_lo;
    }
    v17 = skb_dequeue(v16);
    if ( v17 )
    {
      v15 = v17;
      queue_work_on(32, system_unbound_wq, &qrtr_backup_work);
      goto LABEL_13;
    }
LABEL_47:
    v31 = *a2;
    if ( v31 == 3 )
    {
      v32 = *((unsigned __int16 *)a2 + 4);
      v35 = *((unsigned __int16 *)a2 + 6);
      if ( *((unsigned __int16 *)a2 + 5) == 65534 )
        v33 = -2;
      else
        v33 = *((unsigned __int16 *)a2 + 5);
      if ( *((unsigned __int16 *)a2 + 7) == 65534 )
        v34 = -2;
      else
        v34 = *((unsigned __int16 *)a2 + 7);
    }
    else if ( v31 == 1 )
    {
      v32 = *((_DWORD *)a2 + 2);
      v33 = *((_DWORD *)a2 + 3);
      v35 = *((_DWORD *)a2 + 6);
      v34 = *((_DWORD *)a2 + 7);
    }
    else
    {
      v33 = 0;
      v35 = 0;
      v34 = 0;
      v32 = 0;
    }
    service_id = qrtr_get_service_id(v32, v33);
    v42 = service_id;
    if ( (service_id & 0x80000000) != 0 )
      v42 = (unsigned int)qrtr_get_service_id(v35, v34);
    printk(&unk_DDAB, "qrtr_print_skb_failure_reason", a3, v32, v33, v35, v34, v42);
    result = 4294967284LL;
    goto LABEL_60;
  }
LABEL_13:
  v18 = *(_DWORD *)(v15 + 208) + 32;
  *(_QWORD *)(v15 + 224) += 32LL;
  *(_DWORD *)(v15 + 208) = v18;
  v19 = *a2;
  if ( (_DWORD)v19 != 3 )
  {
    if ( (_DWORD)v19 == 1 )
    {
      if ( a3 >= 0x20 )
      {
        v20 = a2[4];
        v21 = 20;
        *(_BYTE *)(v15 + 56) = v20;
        *(_DWORD *)(v15 + 40) = *((_DWORD *)a2 + 2);
        *(_DWORD *)(v15 + 44) = *((_DWORD *)a2 + 3);
        *(_BYTE *)(v15 + 57) = *((_DWORD *)a2 + 4) != 0;
        *(_DWORD *)(v15 + 48) = *((_DWORD *)a2 + 6);
        v22 = 32;
        v23 = *((_DWORD *)a2 + 7);
        *(_DWORD *)(v15 + 52) = v23;
        goto LABEL_23;
      }
    }
    else
    {
      printk(&unk_DD6F, v19, v9, v10, v11, v12, v13, v14);
    }
LABEL_59:
    sk_skb_reason_drop(0, v15, 2);
    result = 4294967274LL;
    goto LABEL_60;
  }
  if ( a3 < 0x10 )
    goto LABEL_59;
  v20 = a2[1];
  v24 = a2[3];
  *(_BYTE *)(v15 + 56) = v20;
  v22 = v24 + 16;
  *(_BYTE *)(v15 + 57) = a2[2] & 1;
  *(_DWORD *)(v15 + 40) = *((unsigned __int16 *)a2 + 4);
  v25 = *((unsigned __int16 *)a2 + 5);
  *(_DWORD *)(v15 + 44) = v25;
  *(_DWORD *)(v15 + 48) = *((unsigned __int16 *)a2 + 6);
  v23 = *((unsigned __int16 *)a2 + 7);
  *(_DWORD *)(v15 + 52) = v23;
  if ( v25 == 65534 )
    *(_DWORD *)(v15 + 44) = -2;
  if ( v23 == 65534 )
  {
    v23 = -2;
    *(_DWORD *)(v15 + 52) = -2;
  }
  v21 = 4;
LABEL_23:
  v26 = *(unsigned int *)&a2[v21];
  if ( v23 == 0xFFFF )
  {
    v23 = -2;
    *(_DWORD *)(v15 + 52) = -2;
  }
  if ( !(_DWORD)v26
    || ((v26 + 3) & 0x1FFFFFFFCLL) + v22 != a3
    || (v20 == 4 || v20 == 7) && (unsigned int)v26 < 0x14
    || v23 != -2 && v20 != 7 && v20 != 1 )
  {
    goto LABEL_59;
  }
  v27 = &a2[v22];
  *(_DWORD *)(v15 + 112) = v26;
  *(_DWORD *)(v15 + 116) = v26;
  skb_store_bits(v15, 0, &a2[v22]);
  v28 = *(unsigned int *)(v15 + 40);
  if ( (_DWORD)v28 != -1 && *(_DWORD *)(v6 + 60) != (_DWORD)v28 )
  {
    v29 = raw_spin_lock_irqsave(&qrtr_nodes_lock);
    if ( !radix_tree_lookup(&qrtr_nodes, v28) )
      radix_tree_insert(&qrtr_nodes, v28, v6);
    if ( *(_DWORD *)(v6 + 60) == -1 )
      *(_DWORD *)(v6 + 60) = v28;
    raw_spin_unlock_irqrestore(&qrtr_nodes_lock, v29);
  }
  v30 = *(unsigned __int8 *)(v15 + 56);
  if ( v30 == 4 )
  {
    qrtr_node_assign(v6, *((unsigned int *)v27 + 3));
    v30 = *(unsigned __int8 *)(v15 + 56);
  }
  v58 = 0;
  v56 = 0;
  v57 = 0;
  v55 = 0;
  if ( v30 == 1 )
  {
    skb_copy_bits(v15, 0, &v55, 8);
    ipc_log_string(
      *(_QWORD *)(v6 + 352),
      "RX DATA: Len:0x%x CF:0x%x src[0x%x:0x%x] dst[0x%x:0x%x] [%08x %08x]\n",
      *(_DWORD *)(v15 + 112),
      *(unsigned __int8 *)(v15 + 57),
      *(_DWORD *)(v15 + 40),
      *(_DWORD *)(v15 + 44),
      *(_DWORD *)(v15 + 48),
      *(_DWORD *)(v15 + 52),
      v55,
      HIDWORD(v55));
    if ( msm_pm_debug_mask != 1 )
    {
      if ( qrtr_count < 1 )
        goto LABEL_77;
      --qrtr_count;
    }
    printk(
      &unk_E108,
      *(unsigned int *)(v15 + 112),
      *(unsigned __int8 *)(v15 + 57),
      *(unsigned int *)(v15 + 40),
      *(unsigned int *)(v15 + 44),
      *(unsigned int *)(v15 + 48),
      *(unsigned int *)(v15 + 52),
      v55);
  }
  else
  {
    skb_copy_bits(v15, 0, &v56, 20);
    v36 = *(unsigned __int8 *)(v15 + 56);
    if ( v36 > 7 )
      goto LABEL_77;
    if ( ((1 << v36) & 0xC) != 0 )
    {
      ipc_log_string(*(_QWORD *)(v6 + 352), "RX CTRL: cmd:0x%x node[0x%x]\n", v36, *(_DWORD *)(v15 + 40));
      if ( msm_pm_debug_mask != 1 )
      {
        if ( qrtr_count < 1 )
          goto LABEL_77;
        --qrtr_count;
      }
      printk(&unk_DC55, *(unsigned __int8 *)(v15 + 56), *(unsigned int *)(v15 + 40), v45, v46, v47, v48, v49);
    }
    else if ( ((1 << v36) & 0x30) != 0 )
    {
      ipc_log_string(
        *(_QWORD *)(v6 + 352),
        "RX CTRL: cmd:0x%x SVC[0x%x:0x%x] addr[0x%x:0x%x]\n",
        v36,
        HIDWORD(v56),
        v57,
        HIDWORD(v57),
        v58);
      if ( msm_pm_debug_mask != 1 )
      {
        if ( qrtr_count < 1 )
          goto LABEL_77;
        --qrtr_count;
      }
      printk(&unk_E44E, *(unsigned __int8 *)(v15 + 56), HIDWORD(v56), (unsigned int)v57, HIDWORD(v57), v58, v43, v44);
    }
    else
    {
      if ( ((1 << v36) & 0xC0) == 0 )
        goto LABEL_77;
      ipc_log_string(*(_QWORD *)(v6 + 352), "RX CTRL: cmd:0x%x addr[0x%x:0x%x]\n", v36, HIDWORD(v56), v57);
      if ( msm_pm_debug_mask != 1 )
      {
        if ( qrtr_count < 1 )
          goto LABEL_77;
        --qrtr_count;
      }
      printk(&unk_E32C, *(unsigned __int8 *)(v15 + 56), HIDWORD(v56), (unsigned int)v57, v37, v38, v39, v40);
    }
  }
LABEL_77:
  v50 = qrtr_get_service_id(*(unsigned int *)(v15 + 40), *(unsigned int *)(v15 + 44));
  if ( *(_BYTE *)(v15 + 56) != 1 || *(_DWORD *)(v15 + 48) != qrtr_local_nid )
  {
    skb_queue_tail(v6 + 144, v15);
    kthread_queue_work(v6 + 184, v6 + 248);
    pm_wakeup_ws_event(*(_QWORD *)(v6 + 328), 0, 1);
    result = 0;
    goto LABEL_60;
  }
  v51 = v50;
  v52 = qrtr_port_lookup(*(unsigned int *)(v15 + 52));
  if ( !v52 )
  {
    sk_skb_reason_drop(0, v15, 2);
    result = 4294967277LL;
    goto LABEL_60;
  }
  v53 = v52;
  if ( (unsigned int)sock_queue_rcv_skb_reason(v52, v15, 0) )
  {
    sock_put(v53);
    goto LABEL_59;
  }
  if ( !xa_load(v6 + 336, v51) )
    pm_wakeup_ws_event(*(_QWORD *)(v6 + 328), 0, 1);
  sock_put(v53);
  result = 0;
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
