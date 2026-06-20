__int64 __fastcall aw882xx_dsp_write_dsp_msg(__int64 a1, int a2, const void *a3, unsigned int a4)
{
  unsigned __int64 v6; // x20
  unsigned int v7; // w23
  _DWORD *v8; // x19
  unsigned int v10; // w3
  unsigned __int64 StatusReg; // x24
  __int64 v12; // x25

  if ( *(_DWORD *)(a1 + 52) > 3u )
    return aw_write_msg_to_dsp_v_1_0_0_0();
  v6 = a4;
  v7 = a4;
  v8 = (_DWORD *)_kmalloc_noprof(a4 + 24LL, 3520);
  if ( !v8 )
    return 4294967284LL;
  while ( 1 )
  {
    *v8 = 0;
    v8[1] = a2;
    v8[2] = 1;
    if ( v6 >= v7 )
      break;
    _fortify_panic(17);
    v6 = v10;
    StatusReg = _ReadStatusReg(SP_EL0);
    v12 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &aw_write_msg_to_dsp__alloc_tag;
    v7 = v10;
    v8 = (_DWORD *)_kmalloc_noprof(v10 + 24LL, 3520);
    *(_QWORD *)(StatusReg + 80) = v12;
    if ( !v8 )
      return 4294967284LL;
  }
  memcpy(v8 + 6, a3, v7);
  if ( g_rx_topo_id )
    printk(&unk_23888, "aw_check_dsp_ready", 0);
  mutex_lock(&g_aw_dsp_lock);
  mutex_unlock(&g_aw_dsp_lock);
  kfree(v8);
  return 0;
}
