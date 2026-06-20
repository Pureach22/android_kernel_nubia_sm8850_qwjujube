__int64 __fastcall aw_write_msg_to_dsp_v_1_0_0_0(__int64 a1, int a2, const void *a3, unsigned int a4)
{
  unsigned __int64 v8; // x23
  unsigned __int64 v9; // x20
  __int64 v10; // x2
  __int64 v11; // x19
  int v12; // w9
  unsigned __int64 v13; // x10
  unsigned __int64 v14; // x11
  unsigned int v15; // w12
  unsigned int v16; // w9
  int v17; // w10
  int v18; // w9
  int v19; // w13
  int v20; // w10
  int v21; // w11
  unsigned int v22; // w9
  unsigned int v23; // w12
  int v24; // w13
  int v25; // w14
  int v26; // w15
  int v27; // w11
  unsigned int v28; // w19
  unsigned __int64 StatusReg; // x26
  __int64 v31; // x27

  mutex_lock(&g_aw_dsp_msg_lock);
  v8 = a4;
  v9 = a4 + 40LL;
  v11 = _kmalloc_noprof(v9, 3520);
  if ( !v11 )
  {
LABEL_26:
    printk(&unk_238AA, "aw_write_msg_to_dsp_v_1_0_0_0", v10);
    v28 = -12;
    goto LABEL_23;
  }
  while ( 1 )
  {
    v12 = *(_DWORD *)(a1 + 52);
    *(_QWORD *)(v11 + 4) = 0x110000000LL;
    *(_DWORD *)(v11 + 12) = a2;
    *(_DWORD *)(v11 + 16) = v12;
    *(_DWORD *)(v11 + 20) = 1;
    *(_DWORD *)(v11 + 24) = a4;
    if ( v8 >= a4 )
      break;
LABEL_25:
    _fortify_panic(17);
    v8 = a4;
    StatusReg = _ReadStatusReg(SP_EL0);
    v31 = *(_QWORD *)(StatusReg + 80);
    v9 = a4 + 40LL;
    *(_QWORD *)(StatusReg + 80) = &aw_write_msg_to_dsp_v_1_0_0_0__alloc_tag;
    v11 = _kmalloc_noprof(v9, 3520);
    *(_QWORD *)(StatusReg + 80) = v31;
    if ( !v11 )
      goto LABEL_26;
  }
  memcpy((void *)(v11 + 40), a3, a4);
  if ( a4 + 40 >= 5 )
  {
    v13 = v9 - 4;
    v14 = a4 + 35;
    if ( v9 - 4 >= v14 )
      v15 = a4 + 35;
    else
      v15 = v9 - 4;
    v16 = v15 + 1;
    if ( v15 + 1 < 3 )
      goto LABEL_11;
    if ( v13 >= v14 )
      LODWORD(v13) = a4 + 35;
    if ( (unsigned int)v13 <= 0x7FFFFFFB )
    {
      v19 = v16 & 1;
      v20 = 0;
      if ( (v16 & 1) == 0 )
        v19 = 2;
      v21 = 0;
      v22 = v16 - v19;
      v23 = v15 - v19;
      v24 = -1;
      v18 = v22 + 4;
      do
      {
        v25 = v24 + 5;
        v26 = v24 + 6;
        v24 += 2;
        v20 += *(unsigned __int8 *)(v11 + v25);
        v21 += *(unsigned __int8 *)(v11 + v26);
      }
      while ( v23 != v24 );
      v17 = v21 + v20;
    }
    else
    {
LABEL_11:
      v17 = 0;
      v18 = 4;
    }
    while ( v9 > v18 )
    {
      v27 = *(unsigned __int8 *)(v11 + v18++);
      v17 += v27;
      if ( a4 + 40 == v18 )
        goto LABEL_20;
    }
    __break(1u);
    goto LABEL_25;
  }
  v17 = 0;
LABEL_20:
  *(_DWORD *)v11 = v17;
  if ( g_rx_topo_id )
    printk(&unk_23888, "aw_check_dsp_ready", 0);
  mutex_lock(&g_aw_dsp_lock);
  mutex_unlock(&g_aw_dsp_lock);
  kfree(v11);
  v28 = 0;
LABEL_23:
  mutex_unlock(&g_aw_dsp_msg_lock);
  return v28;
}
