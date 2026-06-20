__int64 __fastcall wlan_pkt_stats_to_logger_thread(
        unsigned __int16 *a1,
        _BYTE *a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v12; // w24
  __int64 v15; // x0
  __int64 v16; // x19
  _DWORD *v17; // x23
  int v18; // w24
  __int64 result; // x0
  void *v20; // x0
  void *v21; // x0
  void *v22; // x0
  void *v23; // x0
  unsigned __int64 v30; // x9

  if ( !a1 )
    return qdf_trace_msg(
             0x38u,
             2u,
             "%s: Invalid pkt_stats_header",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wlan_pkt_stats_to_logger_thread");
  v12 = a1[3];
  v15 = raw_spin_lock_irqsave(&dword_826CB4);
  v16 = v15;
  if ( !qword_826CA8 )
    return raw_spin_unlock_irqrestore(&dword_826CB4, v15);
  v17 = *(_DWORD **)(qword_826CA8 + 16);
  if ( v17[29] || v12 + 64 >= v17[53] - v17[52] )
  {
    ((void (*)(void))wlan_get_pkt_stats_free_node)();
    v18 = 1;
    v17 = *(_DWORD **)(qword_826CA8 + 16);
  }
  else
  {
    v18 = 0;
  }
  v20 = (void *)skb_put(v17, 16);
  v21 = qdf_mem_copy(v20, a1, 0x10u);
  if ( a2 )
  {
    v22 = (void *)skb_put(v17, 8);
    v21 = qdf_mem_copy(v22, a2, 8u);
    a1[3] -= 8;
  }
  if ( a3 )
  {
    v23 = (void *)skb_put(v17, a1[3]);
    v21 = qdf_mem_copy(v23, a3, a1[3]);
  }
  if ( a2 && a2[1] == 2 )
  {
    wlan_get_pkt_stats_free_node(v21);
    raw_spin_unlock_irqrestore(&dword_826CB4, v16);
  }
  else
  {
    result = raw_spin_unlock_irqrestore(&dword_826CB4, v16);
    if ( !v18 )
      return result;
  }
  _X8 = &qword_826C78;
  __asm { PRFM            #0x11, [X8] }
  do
    v30 = __ldxr((unsigned __int64 *)&qword_826C78);
  while ( __stxr(v30 | 4, (unsigned __int64 *)&qword_826C78) );
  return _wake_up(&unk_826C28, 1, 1, 0);
}
