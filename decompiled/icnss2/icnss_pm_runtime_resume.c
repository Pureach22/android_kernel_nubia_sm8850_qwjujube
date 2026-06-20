__int64 __fastcall icnss_pm_runtime_resume(_QWORD *a1)
{
  _DWORD *v1; // x19
  __int64 v2; // x8
  __int64 v3; // x9
  unsigned __int64 v4; // x9
  unsigned int v5; // w8
  unsigned int (__fastcall *v7)(_QWORD); // x8

  v1 = (_DWORD *)a1[19];
  if ( v1 )
  {
    v2 = *((_QWORD *)v1 + 38);
    if ( v2 == 43981 )
    {
      printk("%sicnss2: Ignore runtime resume\n", byte_130B32);
      ipc_log_string(icnss_ipc_log_context, "%sicnss2: Ignore runtime resume\n", (const char *)&unk_12DBF3);
      return 0;
    }
    else if ( *v1 == 1522293436 )
    {
      v3 = *((_QWORD *)v1 + 2);
      if ( v3 && *(_QWORD *)(v3 + 280) )
      {
        if ( v2 != 25680 && v2 != 26448 && v2 != 30544 && *((_BYTE *)v1 + 5968) != 1
          || (v4 = *((_QWORD *)v1 + 381), v5 = 0, v4) && v4 <= 0xFFFFFFFFFFFFF000LL )
        {
          ipc_log_string(icnss_ipc_log_long_context, "icnss2: Runtime resume, state: 0x%lx\n", *((_QWORD *)v1 + 229));
          v7 = *(unsigned int (__fastcall **)(_QWORD))(*((_QWORD *)v1 + 2) + 280LL);
          if ( *((_DWORD *)v7 - 1) != 711998475 )
            __break(0x8228u);
          return v7(a1);
        }
      }
      else
      {
        return 0;
      }
    }
    else
    {
      printk("%sicnss2: Invalid drvdata for runtime resume: dev %pK, data %pK, magic 0x%x\n", byte_130B32, a1, v1, *v1);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: Invalid drvdata for runtime resume: dev %pK, data %pK, magic 0x%x\n",
        (const char *)&unk_12DBF3,
        a1,
        v1,
        *v1);
      return (unsigned int)-22;
    }
  }
  else
  {
    printk("%sicnss2: icnss priv is NULL\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: icnss priv is NULL\n", (const char *)&unk_12DBF3);
    return (unsigned int)-12;
  }
  return v5;
}
