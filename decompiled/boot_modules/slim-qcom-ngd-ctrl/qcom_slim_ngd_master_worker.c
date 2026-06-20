void __fastcall qcom_slim_ngd_master_worker(__int64 a1)
{
  int v2; // w8
  int i; // w24
  int v4; // w0
  __int64 v5; // x1
  int v6; // w8
  int v7; // w8
  int v8; // w8
  __int64 next_child; // x0
  __int64 v10; // x21
  _QWORD v11[4]; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v12[3]; // [xsp+28h] [xbp-28h] BYREF
  _QWORD v13[2]; // [xsp+40h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 16893401;
  v12[1] = v11;
  v12[2] = 0;
  v11[3] = 0;
  v11[2] = v13;
  v11[0] = 0x40000;
  v11[1] = 0;
  v12[0] = 0xFF00000000010608LL;
  _slimbus_dbg();
  v2 = *(_DWORD *)(a1 + 532);
  if ( v2 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 544), "SLIM SAT: Rcvd master capability\n");
    v2 = *(_DWORD *)(a1 + 532);
  }
  if ( !v2 )
    ipc_log_string(*(_QWORD *)(a1 + 552), "SLIM SAT: Rcvd master capability\n");
  for ( i = 10; ; --i )
  {
    v4 = qcom_slim_ngd_xfer_msg(a1 - 4016, (unsigned __int8 *)v12);
    if ( v4 != -5 )
      break;
    _slimbus_dbg();
    v6 = *(_DWORD *)(a1 + 532);
    if ( v6 >= 2 )
    {
      printk(&unk_CF8F, v5);
      ipc_log_string(*(_QWORD *)(a1 + 544), "capability message NACKed, retrying\n");
      if ( *(_DWORD *)(a1 + 532) )
      {
LABEL_9:
        if ( !i )
          goto LABEL_32;
        goto LABEL_13;
      }
    }
    else if ( v6 )
    {
      goto LABEL_9;
    }
    ipc_log_string(*(_QWORD *)(a1 + 552), "capability message NACKed, retrying\n");
    if ( !i )
      goto LABEL_32;
LABEL_13:
    msleep(10);
  }
  if ( v4 )
  {
    dev_err(*(_QWORD *)(a1 - 2976), "SLIM: capability TX failed:%d\n", v4);
  }
  else
  {
    _slimbus_dbg();
    v7 = *(_DWORD *)(a1 + 532);
    if ( v7 >= 3 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 544), "SLIM SAT: capability exchange successful\n");
      v7 = *(_DWORD *)(a1 + 532);
    }
    if ( !v7 )
      ipc_log_string(*(_QWORD *)(a1 + 552), "SLIM SAT: capability exchange successful\n");
    if ( *(_DWORD *)(a1 + 440) >= 2u )
    {
      complete(a1 - 64);
      goto LABEL_24;
    }
    _slimbus_dbg();
    v8 = *(_DWORD *)(a1 + 532);
    if ( v8 >= 2 )
    {
      printk(&unk_C761, *(unsigned int *)(a1 + 440));
      ipc_log_string(*(_QWORD *)(a1 + 544), "capability due to noise, Unexpected state:%d\n", *(_DWORD *)(a1 + 440));
      if ( !*(_DWORD *)(a1 + 532) )
LABEL_23:
        ipc_log_string(*(_QWORD *)(a1 + 552), "capability due to noise, Unexpected state:%d\n", *(_DWORD *)(a1 + 440));
    }
    else if ( !v8 )
    {
      goto LABEL_23;
    }
LABEL_24:
    if ( *(_DWORD *)(a1 + 440) == 3 )
    {
      next_child = of_get_next_child(*(_QWORD *)(**(_QWORD **)(a1 - 2984) + 760LL), 0);
      if ( next_child )
      {
        v10 = next_child;
        do
        {
          if ( of_slim_get_device(a1 - 4016, v10) && (unsigned int)slim_get_logical_addr() )
            dev_err(*(_QWORD *)(a1 - 2976), "Failed to get logical address\n");
          v10 = of_get_next_child(*(_QWORD *)(**(_QWORD **)(a1 - 2984) + 760LL), v10);
        }
        while ( v10 );
      }
    }
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
}
