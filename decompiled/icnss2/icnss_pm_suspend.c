__int64 __fastcall icnss_pm_suspend(_QWORD *a1)
{
  _DWORD *v1; // x19
  __int64 v3; // x8
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x9
  unsigned __int64 v6; // x9
  __int64 result; // x0
  __int64 v8; // x8
  unsigned __int64 v15; // x9

  v1 = (_DWORD *)a1[19];
  if ( !v1 )
  {
    printk("%sicnss2: icnss priv is NULL\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: icnss priv is NULL\n", (const char *)&unk_12DBF3);
    return 4294967284LL;
  }
  if ( *v1 != 1522293436 )
  {
    printk("%sicnss2: Invalid drvdata for pm suspend: dev %pK, data %pK, magic 0x%x\n", byte_130B32, a1, v1, *v1);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: Invalid drvdata for pm suspend: dev %pK, data %pK, magic 0x%x\n",
      (const char *)&unk_12DBF3,
      a1,
      v1,
      *v1);
    return 4294967274LL;
  }
  ipc_log_string(icnss_ipc_log_long_context, "icnss2: PM Suspend, state: 0x%lx\n", *((_QWORD *)v1 + 229));
  v3 = *((_QWORD *)v1 + 2);
  if ( !v3 )
    return 0;
  v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 240);
  if ( !v4 )
    return 0;
  v5 = *((_QWORD *)v1 + 38);
  if ( v5 != 25680 && v5 != 26448 && v5 != 30544 && *((_BYTE *)v1 + 5968) != 1
    || (v6 = *((_QWORD *)v1 + 381), result = 0, v6) && v6 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( (*((_QWORD *)v1 + 229) & 8) == 0 )
      return 0;
    if ( *((_DWORD *)v4 - 1) != 711998475 )
      __break(0x8228u);
    result = v4(a1);
    if ( (_DWORD)result )
    {
      ++v1[632];
      return result;
    }
    v8 = *((_QWORD *)v1 + 38);
    if ( v8 == 25680 || v8 == 30544 || v8 == 26448 )
    {
      if ( (*((_QWORD *)v1 + 229) & 0x200) != 0 || (*((_QWORD *)v1 + 229) & 0x10000) == 0 )
        return 0;
      result = icnss_send_smp2p((__int64)v1, 1, 0);
    }
    else
    {
      result = 0;
    }
    ++v1[631];
    _X8 = (unsigned __int64 *)(v1 + 458);
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 | 0x20, _X8) );
  }
  return result;
}
