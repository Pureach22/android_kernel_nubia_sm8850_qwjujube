__int64 __fastcall htc_destroy(_QWORD *a1)
{
  __int64 v2; // x0
  unsigned int v9; // w8
  unsigned int v10; // w8
  unsigned int v13; // w8
  unsigned int v14; // w8
  __int64 htc_packet_container; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v17; // x8
  _QWORD *v18; // x20
  __int64 v20; // x0
  _QWORD *v21; // x22
  __int64 v22; // x0

  if ( (dword_B0B4 & 8) != 0 )
    qdf_trace_msg(56, 2, "%s: +htc_destroy ..  Destroying :0x%pK\n", "htc_destroy", a1);
  v2 = htc_hang_event_notifier_unregister();
  if ( a1 )
  {
    hif_stop(*a1);
    _X20 = (unsigned int *)a1 + 891;
    while ( 1 )
    {
      __asm { PRFM            #0x11, [X20] }
      do
      {
        v9 = __ldxr(_X20);
        v10 = v9 - 1;
      }
      while ( __stlxr(v10, _X20) );
      __dmb(0xBu);
      if ( (v10 & 0x80000000) != 0 )
        break;
      hif_rtpm_put(4, 3u);
    }
    while ( 1 )
    {
      _X9 = (unsigned int *)(a1 + 446);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v13 = __ldxr(_X9);
        v14 = v13 - 1;
      }
      while ( __stlxr(v14, _X9) );
      __dmb(0xBu);
      if ( (v14 & 0x80000000) != 0 )
        break;
      hif_rtpm_put(4, 2u);
    }
    if ( *a1 )
    {
      hif_detach_htc(*a1);
      hif_mask_interrupt_call(*a1);
      *a1 = 0;
    }
    while ( 1 )
    {
      htc_packet_container = allocate_htc_packet_container(a1);
      if ( !htc_packet_container )
        break;
      _qdf_mem_free(htc_packet_container);
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 374);
      v17 = a1[375];
    }
    else
    {
      raw_spin_lock_bh(a1 + 374);
      v17 = a1[375] | 1LL;
      a1[375] = v17;
    }
    v18 = (_QWORD *)a1[435];
    a1[435] = 0;
    if ( (v17 & 1) != 0 )
    {
      a1[375] = v17 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 374);
      if ( !v18 )
        goto LABEL_24;
    }
    else
    {
      raw_spin_unlock(a1 + 374);
      if ( !v18 )
      {
LABEL_24:
        qdf_trace_msg(
          62,
          4,
          "%s: Non flow ctrl enabled endpoints nbuf map: %d, unamp: %d",
          "htc_cleanup",
          *((_DWORD *)a1 + 893),
          *((_DWORD *)a1 + 894));
        htc_flush_endpoint_txlookupQ(a1, 0, 1);
        _qdf_mem_free(a1);
        ((void (__fastcall *)(__int64))hif_rtpm_deregister)(3);
        v2 = ((__int64 (__fastcall *)(__int64))hif_rtpm_deregister)(2);
        goto LABEL_25;
      }
    }
    do
    {
      v20 = v18[12];
      v21 = (_QWORD *)v18[1];
      if ( v20 )
        _qdf_nbuf_free(v20);
      v22 = v18[11];
      if ( v22 )
        _qdf_mem_free(v22);
      _qdf_mem_free(v18);
      v18 = v21;
    }
    while ( v21 );
    goto LABEL_24;
  }
LABEL_25:
  if ( (dword_B0B4 & 8) != 0 )
    v2 = qdf_trace_msg(56, 2, "%s: -htc_destroy\n", "htc_destroy");
  return htc_credit_history_deinit(v2);
}
