unsigned __int64 __fastcall ocp_notifier_log_event(_QWORD *a1, __int64 a2, unsigned __int16 *a3, const char *a4)
{
  unsigned int v4; // w22
  __int64 v7; // x1
  __int64 v10; // x0
  const char **v11; // x8
  const char *v12; // x22
  unsigned __int64 result; // x0
  __int64 v14; // x24
  _QWORD v15[3]; // [xsp+8h] [xbp-18h] BYREF

  v15[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a3;
  if ( *a3 )
  {
    v7 = *a3;
    v15[0] = 0;
    v15[1] = 0;
    v10 = idr_find(a1 + 1, v7);
    if ( v10 )
    {
LABEL_3:
      v11 = *(const char ***)(v10 + 1144);
      if ( !v11 || (v12 = *v11) == nullptr )
      {
        if ( **(_QWORD **)v10 )
          v12 = **(const char ***)v10;
        else
          v12 = (const char *)&unk_6C1E;
      }
      if ( (unsigned int)__ratelimit(&ocp_notifier_log_event__rs, "ocp_notifier_log_event") )
        printk(&unk_6D75, a4, v12, *a3);
      ipc_log_string(
        *(_QWORD *)(a2 + 16),
        "%s name=%s, ppid=0x%03X, mode=%u\n",
        a4,
        v12,
        *a3,
        *((unsigned __int8 *)a3 + 2));
      goto LABEL_11;
    }
    LOBYTE(v15[0]) = 0;
    scnprintf(v15, 16, "periph-%03x", v4);
    result = regulator_get_optional(*a1, v15);
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      v14 = *(_QWORD *)(result + 120);
      regulator_put();
      result = idr_alloc(a1 + 1, v14, v4, v4 + 1, 3264);
      if ( (result & 0x80000000) != 0 )
        goto LABEL_12;
      if ( (_DWORD)result != v4 )
      {
        result = 4294967274LL;
        goto LABEL_12;
      }
      v10 = v14;
      if ( v14 )
        goto LABEL_3;
    }
    else if ( (_DWORD)result == -517 )
    {
      goto LABEL_12;
    }
    if ( (unsigned int)__ratelimit(&ocp_notifier_log_event__rs_14, "ocp_notifier_log_event") )
      printk(&unk_6D99, a4, *a3, *((unsigned __int8 *)a3 + 2));
    ipc_log_string(*(_QWORD *)(a2 + 16), "%s ppid=0x%03X, mode=%u\n", a4, *a3, *((unsigned __int8 *)a3 + 2));
  }
LABEL_11:
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
