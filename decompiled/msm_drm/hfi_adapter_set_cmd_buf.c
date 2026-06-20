__int64 __fastcall hfi_adapter_set_cmd_buf(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x21
  _QWORD *v3; // x8
  __int64 v4; // x2
  _QWORD *v5; // x9
  _QWORD *v6; // x9
  unsigned __int64 v7; // x10
  unsigned int v9; // w19
  _QWORD v11[11]; // [xsp+8h] [xbp-58h] BYREF

  v11[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 136);
  memset(&v11[1], 0, 72);
  if ( !v1 )
  {
    printk(&unk_21CFDB, "hfi_adapter_set_cmd_buf");
    goto LABEL_16;
  }
  v2 = *(_QWORD *)(v1 + 120);
  if ( !v2 )
  {
LABEL_16:
    v9 = -22;
    goto LABEL_17;
  }
  v3 = (_QWORD *)(a1 + 120);
  LODWORD(v4) = 0;
  v5 = (_QWORD *)(a1 + 120);
  do
  {
    v5 = (_QWORD *)*v5;
    v4 = (unsigned int)(v4 + 1);
  }
  while ( v5 != v3 );
  v6 = *(_QWORD **)(a1 + 120);
  v11[0] = a1 + 64;
  if ( v6 != v3 )
  {
    v7 = 1;
    do
    {
      if ( v6 != (_QWORD *)&unk_68 )
      {
        if ( v7 > 9 )
        {
          __break(0x5512u);
          break;
        }
        v11[v7++] = v6 - 5;
      }
      v6 = (_QWORD *)*v6;
    }
    while ( v6 != v3 );
  }
  v9 = hfi_core_cmds_tx_buf_send(*(_QWORD *)(v2 + 32), v11, v4, 1);
  if ( v9 )
    printk(&unk_2204E4, "hfi_adapter_set_cmd_buf");
  mutex_lock(v2 + 368);
  release_tx_buffers(a1);
  mutex_unlock(v2 + 368);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v9;
}
