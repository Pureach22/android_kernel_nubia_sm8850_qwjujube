__int64 __fastcall dp_power_pinctrl_set(__int64 *a1, char a2)
{
  __int64 v2; // x9
  unsigned int v3; // w8
  unsigned __int64 v4; // x0
  __int64 v5; // x8
  unsigned __int64 v7; // x1
  __int64 v8; // x0
  __int64 v10; // x0
  int v11; // w2
  const char *v12; // x19
  unsigned int v13; // w20
  __int64 ipc_log_context; // x0
  int v15; // w2
  const char *v16; // x19

  v2 = *a1;
  v3 = 0;
  v4 = *(_QWORD *)(*a1 + 352);
  if ( v4 && v4 <= 0xFFFFFFFFFFFFF000LL )
  {
    v5 = 392;
    if ( (a2 & 1) != 0 )
      v5 = 360;
    v7 = *(_QWORD *)(v2 + v5);
    if ( v7 && v7 <= 0xFFFFFFFFFFFFF000LL )
    {
      v8 = pinctrl_select_state();
      if ( (_DWORD)v8 )
      {
        v13 = v8;
        ipc_log_context = get_ipc_log_context(v8);
        v15 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
        if ( (a2 & 1) != 0 )
          v16 = "dp_active";
        else
          v16 = "dp_sleep";
        ipc_log_string(ipc_log_context, "[e][%-4d]can not set %s pins\n", v15, v16);
        printk(&unk_23E221, "dp_power_pinctrl_set");
        return v13;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      v10 = get_ipc_log_context(v4);
      v11 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
      if ( (a2 & 1) != 0 )
        v12 = "dp_active";
      else
        v12 = "dp_sleep";
      ipc_log_string(v10, "[e][%-4d]invalid '%s' pinstate\n", v11, v12);
      printk(&unk_244CFC, "dp_power_pinctrl_set");
      return (unsigned int)-14;
    }
  }
  return v3;
}
