__int64 __fastcall icnss_pm_resume(_QWORD *a1)
{
  _DWORD *v1; // x19
  __int64 v3; // x8
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x9
  unsigned __int64 v6; // x9
  __int64 result; // x0
  unsigned __int64 v14; // x10

  v1 = (_DWORD *)a1[19];
  if ( v1 )
  {
    if ( *v1 == 1522293436 )
    {
      ipc_log_string(icnss_ipc_log_long_context, "icnss2: PM resume, state: 0x%lx\n", *((_QWORD *)v1 + 229));
      v3 = *((_QWORD *)v1 + 2);
      if ( !v3 )
        goto LABEL_16;
      v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 248);
      if ( !v4 )
        goto LABEL_16;
      v5 = *((_QWORD *)v1 + 38);
      if ( v5 == 25680 || v5 == 26448 || v5 == 30544 || *((_BYTE *)v1 + 5968) == 1 )
      {
        v6 = *((_QWORD *)v1 + 381);
        if ( !v6 || v6 > 0xFFFFFFFFFFFFF000LL )
          goto LABEL_16;
      }
      if ( (*((_QWORD *)v1 + 229) & 8) == 0 )
        goto LABEL_16;
      if ( *((_DWORD *)v4 - 1) != 711998475 )
        __break(0x8228u);
      result = v4(a1);
      if ( (_DWORD)result )
      {
        ++v1[634];
      }
      else
      {
LABEL_16:
        ++v1[633];
        _X8 = (unsigned __int64 *)(v1 + 458);
        __asm { PRFM            #0x11, [X8] }
        do
          v14 = __ldxr(_X8);
        while ( __stxr(v14 & 0xFFFFFFFFFFFFFFDFLL, _X8) );
        return 0;
      }
    }
    else
    {
      printk("%sicnss2: Invalid drvdata for pm resume: dev %pK, data %pK, magic 0x%x\n", byte_130B32, a1, v1, *v1);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: Invalid drvdata for pm resume: dev %pK, data %pK, magic 0x%x\n",
        (const char *)&unk_12DBF3,
        a1,
        v1,
        *v1);
      return 4294967274LL;
    }
  }
  else
  {
    printk("%sicnss2: icnss priv is NULL\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: icnss priv is NULL\n", (const char *)&unk_12DBF3);
    return 4294967284LL;
  }
  return result;
}
