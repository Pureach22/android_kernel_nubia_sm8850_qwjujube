__int64 __fastcall dp_parser_put(__int64 a1)
{
  __int64 i; // x24
  __int64 v3; // x26
  __int64 v4; // x26
  __int64 v5; // x1
  __int64 v6; // x1
  __int64 v7; // x1
  int v8; // w8
  unsigned int v9; // w20
  __int64 v10; // x21
  _QWORD *v11; // x21
  __int64 v12; // t1
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    for ( i = 0; i != 336; i += 48 )
    {
      v3 = a1 + i;
      if ( a1 + i == -16 )
      {
        printk(&unk_23A915, "dp_parser_put_clk_data");
        printk(&unk_275CE5, v7);
        printk(&unk_23A915, "dp_parser_put_gpio_data");
      }
      else
      {
        if ( *(_QWORD *)(v3 + 56) )
        {
          devm_kfree(*(_QWORD *)a1 + 16LL);
          *(_QWORD *)(v3 + 56) = 0;
        }
        v4 = a1 + i;
        v5 = *(_QWORD *)(a1 + i + 24);
        *(_DWORD *)(a1 + i + 48) = 0;
        if ( v5 )
        {
          devm_kfree(*(_QWORD *)a1 + 16LL);
          *(_QWORD *)(v4 + 24) = 0;
        }
        v6 = *(_QWORD *)(v4 + 40);
        *(_DWORD *)(a1 + i + 16) = 0;
        if ( v6 )
        {
          devm_kfree(*(_QWORD *)a1 + 16LL);
          *(_QWORD *)(v4 + 40) = 0;
        }
        *(_DWORD *)(a1 + i + 32) = 0;
      }
    }
    devm_kfree(*(_QWORD *)a1 + 16LL);
    devm_kfree(*(_QWORD *)a1 + 16LL);
    devm_kfree(*(_QWORD *)a1 + 16LL);
    devm_kfree(*(_QWORD *)a1 + 16LL);
    v8 = *(_DWORD *)(a1 + 400);
    *(_BYTE *)(a1 + 832) = 0;
    *(_QWORD *)(a1 + 824) = 0;
    *(_QWORD *)(a1 + 816) = 0;
    *(_QWORD *)(a1 + 808) = 0;
    *(_QWORD *)(a1 + 800) = 0;
    if ( v8 )
    {
      v9 = 0;
      do
      {
        v10 = *(_QWORD *)(a1 + 408) + 32LL * (int)v9;
        v12 = *(_QWORD *)(v10 + 8);
        v11 = (_QWORD *)(v10 + 8);
        if ( v12 )
          devm_kfree(*(_QWORD *)a1 + 16LL);
        *v11 = 0;
        ++v9;
      }
      while ( v9 < *(_DWORD *)(a1 + 400) );
    }
    devm_kfree(*(_QWORD *)a1 + 16LL);
    return devm_kfree(*(_QWORD *)a1 + 16LL);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid parser module\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275CA4, "dp_parser_put");
  }
}
