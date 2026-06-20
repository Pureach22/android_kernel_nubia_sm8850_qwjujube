__int64 __fastcall aw_read_msg_from_dsp_v_1_0_0_0(void *a1, unsigned int a2)
{
  unsigned __int64 v4; // x23
  unsigned __int64 v5; // x24
  unsigned __int64 v6; // x22
  unsigned int *v7; // x21
  __int64 v8; // x2
  unsigned __int64 v9; // x10
  unsigned __int64 v10; // x11
  unsigned int v11; // w12
  unsigned int v12; // w9
  int v13; // w9
  int v14; // w13
  int v15; // w10
  int v16; // w11
  unsigned int v17; // w9
  unsigned int v18; // w12
  int v19; // w13
  int v20; // w14
  int v21; // w15
  int v22; // w10
  unsigned int v23; // w19
  unsigned __int64 StatusReg; // x25
  __int64 v25; // x26

  mutex_lock(&g_aw_dsp_msg_lock);
  v4 = (unsigned __int64)&qword_0;
  if ( g_rx_topo_id )
    printk(&unk_23888, "aw_check_dsp_ready", 0);
  mutex_lock(&g_aw_dsp_lock);
  mutex_unlock(&g_aw_dsp_lock);
  v5 = a2;
  v6 = a2 + 40LL;
  v7 = (unsigned int *)_kmalloc_noprof(v6, 3520);
  if ( !v7 )
  {
LABEL_32:
    v23 = -12;
    goto LABEL_33;
  }
  while ( 1 )
  {
    if ( *(_DWORD *)(v4 + 3312) )
      printk(&unk_23888, "aw_check_dsp_ready", 0);
    mutex_lock(&g_aw_dsp_lock);
    mutex_unlock(&g_aw_dsp_lock);
    v8 = v7[2];
    if ( (_DWORD)v8 != 2 )
    {
      printk(&unk_26328, "aw_read_msg_from_dsp_v_1_0_0_0", v8);
      v23 = -22;
      goto LABEL_27;
    }
    if ( a2 + 40 >= 5 )
    {
      v9 = v6 - 4;
      v10 = a2 + 35;
      if ( v6 - 4 >= v10 )
        v11 = a2 + 35;
      else
        v11 = v6 - 4;
      v12 = v11 + 1;
      if ( v11 + 1 < 3 )
        goto LABEL_15;
      if ( v9 >= v10 )
        LODWORD(v9) = a2 + 35;
      if ( (unsigned int)v9 <= 0x7FFFFFFB )
      {
        v14 = v12 & 1;
        v15 = 0;
        if ( (v12 & 1) == 0 )
          v14 = 2;
        v16 = 0;
        v17 = v12 - v14;
        v18 = v11 - v14;
        v19 = -1;
        v13 = v17 + 4;
        do
        {
          v20 = v19 + 5;
          v21 = v19 + 6;
          v19 += 2;
          v15 += *((unsigned __int8 *)v7 + v20);
          v16 += *((unsigned __int8 *)v7 + v21);
        }
        while ( v18 != v19 );
        v4 = (unsigned int)(v16 + v15);
      }
      else
      {
LABEL_15:
        v4 = 0;
        v13 = 4;
      }
      while ( v6 > v13 )
      {
        v22 = *((unsigned __int8 *)v7 + v13++);
        v4 = (unsigned int)(v4 + v22);
        if ( a2 + 40 == v13 )
          goto LABEL_24;
      }
      __break(1u);
      goto LABEL_31;
    }
    v4 = 0;
LABEL_24:
    if ( (_DWORD)v4 != *v7 )
      break;
    if ( v5 >= a2 )
    {
      memcpy(a1, v7 + 10, a2);
      v23 = 0;
      goto LABEL_27;
    }
LABEL_31:
    _fortify_panic(16);
    v5 = a2;
    StatusReg = _ReadStatusReg(SP_EL0);
    v25 = *(_QWORD *)(StatusReg + 80);
    v6 = a2 + 40LL;
    *(_QWORD *)(StatusReg + 80) = &aw_read_msg_from_dsp_v_1_0_0_0__alloc_tag;
    v7 = (unsigned int *)_kmalloc_noprof(v6, 3520);
    *(_QWORD *)(StatusReg + 80) = v25;
    if ( !v7 )
      goto LABEL_32;
  }
  printk(&unk_22A67, "aw_read_msg_from_dsp_v_1_0_0_0", v8);
  printk(&unk_24C8A, "aw_read_msg_from_dsp_v_1_0_0_0", *v7);
  v23 = -22;
LABEL_27:
  kfree(v7);
LABEL_33:
  mutex_unlock(&g_aw_dsp_msg_lock);
  return v23;
}
