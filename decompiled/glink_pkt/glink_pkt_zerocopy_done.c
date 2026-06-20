__int64 __fastcall glink_pkt_zerocopy_done(__int64 a1, __int64 *a2)
{
  __int64 v2; // x20
  unsigned __int64 StatusReg; // x25
  __int64 v5; // x0
  __int64 v7; // x21
  __int64 v8; // x0
  _QWORD *v9; // x9
  __int64 v10; // x22
  __int64 v11; // x8
  _QWORD *v12; // x23
  _QWORD *v13; // x19
  _QWORD *v14; // x26
  __int64 v15; // x0
  int v16; // w0

  v2 = *a2;
  if ( (*a2 & 0xFFF) != 0 || *(_BYTE *)(a1 + 1144) != 1 )
    return 4294967274LL;
  StatusReg = _ReadStatusReg(SP_EL0);
  down_read(*(_QWORD *)(StatusReg + 1672) + 136LL);
  v5 = mtree_load(*(_QWORD *)(StatusReg + 1672) + 64LL, v2);
  if ( !v5 || *(_UNKNOWN **)(v5 + 72) != &glink_pkt_vm_ops )
  {
    up_read(*(_QWORD *)(StatusReg + 1672) + 136LL);
    return 4294967274LL;
  }
  v7 = v5;
  v8 = raw_spin_lock_irqsave(a1 + 1148);
  v9 = *(_QWORD **)(a1 + 1176);
  v10 = v8;
  if ( v9 == (_QWORD *)(a1 + 1176) || !v9 )
  {
    raw_spin_unlock_irqrestore(a1 + 1148, v8);
    v13 = nullptr;
    v14 = nullptr;
  }
  else
  {
    v11 = a1;
    while ( 1 )
    {
      v12 = v9;
      if ( v2 == v9[7] )
        break;
      v9 = (_QWORD *)*v9;
      v13 = nullptr;
      if ( *v12 == a1 + 1176 || !v9 )
        goto LABEL_16;
    }
    skb_unlink(v9);
    v11 = a1;
    v13 = v12;
LABEL_16:
    v14 = v12 + 5;
    raw_spin_unlock_irqrestore(v11 + 1148, v10);
    if ( v12 != (_QWORD *)-40LL && v12[7] == v2 )
      zap_vma_ptes(v7, v2, v12[8]);
  }
  up_read(*(_QWORD *)(StatusReg + 1672) + 136LL);
  if ( !v13 )
    return 4294967274LL;
  v15 = v14[1];
  if ( v15 )
    free_pages(v15, 0);
  if ( *v14 )
    free_pages(*v14, 0);
  if ( *(_BYTE *)(a1 + 1144) == 1 )
  {
    ipc_log_string(glink_pkt_ilctxt, "[%s]: channel:%s\n", "glink_pkt_kfree_skb", *(const char **)(a1 + 1512));
    v16 = qcom_glink_rx_done(*(_QWORD *)(*(_QWORD *)(a1 + 1136) + 968LL), v13[28]);
    if ( v16 < 0 )
      ipc_log_string(
        glink_pkt_ilctxt,
        "[%s]: Failed channel:%s ret:%d\n",
        "glink_pkt_kfree_skb",
        *(const char **)(a1 + 1512),
        v16);
    v13[28] = v13[27];
  }
  sk_skb_reason_drop(0, v13, 2);
  return 0;
}
