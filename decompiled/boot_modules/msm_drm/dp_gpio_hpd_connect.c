__int64 __fastcall dp_gpio_hpd_connect(__int64 *a1, char a2)
{
  __int64 v2; // x9
  __int64 (__fastcall *v3)(_QWORD); // x8
  __int64 (__fastcall *v4)(_QWORD); // x9
  __int64 v5; // x0
  __int64 v7; // x0
  void *v8; // x0
  __int64 ipc_log_context; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v8 = &unk_275B6D;
    return printk(v8, "dp_gpio_hpd_connect");
  }
  v2 = a1[28];
  *((_WORD *)a1 + 8) = a2 & 1;
  *((_BYTE *)a1 + 18) = a2 & 1;
  if ( !v2
    || (v3 = *(__int64 (__fastcall **)(_QWORD))v2) == nullptr
    || (v4 = *(__int64 (__fastcall **)(_QWORD))(v2 + 8)) == nullptr )
  {
    v7 = get_ipc_log_context(a1);
    ipc_log_string(v7, "[e][%-4d]invalid cb\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v8 = &unk_229F4E;
    return printk(v8, "dp_gpio_hpd_connect");
  }
  v5 = *a1;
  if ( (a2 & 1) != 0 )
  {
    if ( *((_DWORD *)v3 - 1) != 711998475 )
      __break(0x8228u);
    return v3(v5);
  }
  else
  {
    if ( *((_DWORD *)v4 - 1) != 711998475 )
      __break(0x8229u);
    return v4(v5);
  }
}
