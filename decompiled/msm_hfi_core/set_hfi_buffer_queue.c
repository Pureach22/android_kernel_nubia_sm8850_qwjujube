__int64 __fastcall set_hfi_buffer_queue(__int64 a1, int *a2, int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  __int64 v8; // x8
  _QWORD *v9; // x9
  _QWORD *v11; // x8
  __int64 v12; // x10
  _QWORD *v13; // x22
  _QWORD *v14; // x8
  __int64 v15; // x9
  __int64 v16; // x10
  int v17; // w9
  __int64 v18; // x0
  __int64 result; // x0
  _QWORD *v20; // x8
  unsigned int v21; // w19
  _QWORD v22[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v23; // [xsp+18h] [xbp-18h]
  __int64 v24; // [xsp+20h] [xbp-10h]
  __int64 v25; // [xsp+28h] [xbp-8h]

  v6 = v5;
  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  v22[0] = 0;
  v22[1] = 0;
  if ( !a2
    || a3 != 16
    || (v8 = *((_QWORD *)a2 + 1)) == 0
    || !*(_QWORD *)v8
    || !*(_QWORD *)(v8 + 8)
    || !*(_DWORD *)(v8 + 16) )
  {
    printk(&unk_1AD82, "set_hfi_buffer_queue", 350, v5, a2);
    result = 4294967274LL;
    goto LABEL_22;
  }
  v9 = *(_QWORD **)(a1 + 1000);
  if ( v9 != (_QWORD *)(a1 + 1000) )
  {
    v11 = (_QWORD *)v9[1];
    if ( (_QWORD *)*v11 == v9 && (v12 = *v9, *(_QWORD **)(*v9 + 8LL) == v9) )
    {
      *(_QWORD *)(v12 + 8) = v11;
      *v11 = v12;
    }
    else
    {
      _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 1000));
    }
    *v9 = v9;
    v9[1] = v9;
  }
  v13 = v9 - 3;
  if ( v9 == &_ksymtab_hfi_core_cmds_rx_buf_get )
  {
    printk(&unk_1A06A, "set_hfi_buffer_queue", 356, v6, a5);
    result = 4294967284LL;
    goto LABEL_22;
  }
  v14 = *((_QWORD **)a2 + 1);
  v16 = v14[1];
  v15 = v14[2];
  *v13 = *v14;
  v13[1] = v16;
  v13[2] = v15;
  sg_init_one(v22, *(_QWORD *)(*((_QWORD *)a2 + 1) + 8LL), *(unsigned int *)(*((_QWORD *)a2 + 1) + 16LL));
  v17 = *a2;
  v18 = *(_QWORD *)(a1 + 1080);
  v23 = *(_QWORD *)(*((_QWORD *)a2 + 1) + 8LL);
  if ( v17 == 1 )
  {
    result = virtqueue_add_inbuf(v18, v22, 1, v13, 3264);
    if ( (_DWORD)result )
      goto LABEL_17;
  }
  else
  {
    result = virtqueue_add_outbuf(v18, v22, 1, v13, 3264);
    if ( (_DWORD)result )
    {
LABEL_17:
      v20 = *((_QWORD **)a2 + 1);
      v21 = result;
      printk(&unk_1958B, "set_hfi_buffer_queue", 380, v6, *v20);
      result = v21;
    }
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
