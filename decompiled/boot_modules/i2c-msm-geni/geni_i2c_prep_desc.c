__int64 __fastcall geni_i2c_prep_desc(_QWORD *a1, __int64 a2, char a3)
{
  __int64 v4; // x0
  __int64 (*v5)(void); // x9
  __int64 result; // x0
  __int64 (__fastcall *v7)(); // x8
  __int64 v8; // x9
  __int64 v9; // x0
  __int64 (*v10)(void); // x8
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x1
  __int64 v14; // x2

  if ( (a3 & 1) != 0 )
  {
    v4 = a1[640];
    if ( v4 )
    {
      if ( *(_QWORD *)v4 )
      {
        v5 = *(__int64 (**)(void))(*(_QWORD *)v4 + 272LL);
        if ( v5 )
        {
          if ( *((_DWORD *)v5 - 1) != -1221891457 )
            __break(0x8229u);
          result = v5();
          if ( result )
          {
            v7 = gi2c_gsi_tx_cb;
            v8 = 1123;
LABEL_16:
            *(_QWORD *)(result + 40) = v7;
            *(_QWORD *)(result + 56) = &a1[v8];
            return result;
          }
        }
      }
    }
    ipc_log_string(a1[637], "prep_slave_sg for tx failed\n");
    if ( !*a1 )
    {
      printk(&unk_F6A4, v11, v12);
      if ( !*a1 )
        goto LABEL_27;
      goto LABEL_26;
    }
    dev_err(*a1, "prep_slave_sg for tx failed\n");
    if ( *a1 )
      goto LABEL_26;
  }
  else
  {
    v9 = a1[641];
    if ( v9 )
    {
      if ( *(_QWORD *)v9 )
      {
        v10 = *(__int64 (**)(void))(*(_QWORD *)v9 + 272LL);
        if ( v10 )
        {
          if ( *((_DWORD *)v10 - 1) != -1221891457 )
            __break(0x8228u);
          result = v10();
          if ( result )
          {
            v7 = gi2c_gsi_rx_cb;
            v8 = 1129;
            goto LABEL_16;
          }
        }
      }
    }
    ipc_log_string(a1[637], "prep_slave_sg for rx failed\n");
    if ( !*a1 )
    {
      printk(&unk_FF7E, v13, v14);
      if ( !*a1 )
        goto LABEL_27;
      goto LABEL_26;
    }
    dev_err(*a1, "prep_slave_sg for rx failed\n");
    if ( *a1 )
LABEL_26:
      i2c_trace_log();
  }
LABEL_27:
  *((_DWORD *)a1 + 6) = -12;
  return 0;
}
