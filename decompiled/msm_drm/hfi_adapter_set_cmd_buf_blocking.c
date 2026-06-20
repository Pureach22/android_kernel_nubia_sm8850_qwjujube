__int64 __fastcall hfi_adapter_set_cmd_buf_blocking(__int64 a1)
{
  __int64 v1; // x22
  _QWORD *v2; // x8
  __int64 v4; // x2
  _QWORD *v5; // x9
  _QWORD *v6; // x9
  unsigned __int64 v7; // x10
  unsigned int v8; // w0
  int v9; // w23
  int v10; // w24
  unsigned int v11; // w20
  _QWORD v13[11]; // [xsp+8h] [xbp-58h] BYREF

  v13[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 120LL);
  if ( !v1 )
  {
    v11 = -22;
    goto LABEL_18;
  }
  v2 = (_QWORD *)(a1 + 120);
  LODWORD(v4) = 0;
  v5 = (_QWORD *)(a1 + 120);
  memset(&v13[1], 0, 72);
  do
  {
    v5 = (_QWORD *)*v5;
    v4 = (unsigned int)(v4 + 1);
  }
  while ( v5 != v2 );
  v6 = *(_QWORD **)(a1 + 120);
  v13[0] = a1 + 64;
  if ( v6 == v2 )
    goto LABEL_11;
  v7 = 1;
  while ( 1 )
  {
    if ( v6 == (_QWORD *)&unk_68 )
      goto LABEL_7;
    if ( v7 > 9 )
      break;
    v13[v7++] = v6 - 5;
LABEL_7:
    v6 = (_QWORD *)*v6;
    if ( v6 == v2 )
      goto LABEL_11;
  }
  __break(0x5512u);
LABEL_11:
  v8 = hfi_core_cmds_tx_buf_send(*(_QWORD *)(v1 + 32), v13, v4, 1);
  if ( v8 )
  {
    v11 = v8;
    printk(&unk_2204E4, "hfi_adapter_set_cmd_buf_blocking");
  }
  else
  {
    v9 = 202;
    while ( 1 )
    {
      usleep_range_state(10000, 10010, 2);
      if ( !--v9 )
        break;
      v10 = *(_DWORD *)(a1 + 152);
      printk(&unk_279B63, "hfi_adapter_set_cmd_buf_blocking");
      if ( v10 )
      {
        v11 = 0;
        goto LABEL_16;
      }
    }
    printk(&unk_237D6C, "hfi_adapter_set_cmd_buf_blocking");
    printk(&unk_26FB80, "hfi_adapter_set_cmd_buf_blocking");
    v11 = -110;
LABEL_16:
    mutex_lock(v1 + 368);
    release_tx_buffers(a1);
    mutex_unlock(v1 + 368);
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v11;
}
