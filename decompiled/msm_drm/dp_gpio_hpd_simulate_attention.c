__int64 __fastcall dp_gpio_hpd_simulate_attention(__int64 a1)
{
  __int64 v1; // x9
  void (__fastcall *v2)(_QWORD); // x9
  __int64 v3; // x0
  __int64 v5; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    if ( a1 == 8 )
    {
      ipc_log_context = get_ipc_log_context(8);
      ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_275B6D, "dp_gpio_hpd_attention");
    }
    else
    {
      v1 = *(_QWORD *)(a1 + 216);
      *(_BYTE *)(a1 + 9) = 1;
      if ( v1 )
      {
        v2 = *(void (__fastcall **)(_QWORD))(v1 + 16);
        if ( v2 )
        {
          v3 = *(_QWORD *)(a1 - 8);
          if ( *((_DWORD *)v2 - 1) != 711998475 )
            __break(0x8229u);
          v2(v3);
        }
      }
    }
    return 0;
  }
  else
  {
    v5 = get_ipc_log_context(0);
    ipc_log_string(v5, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_gpio_hpd_simulate_attention");
    return 4294967274LL;
  }
}
