__int64 __fastcall capture_kpi_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x22
  const char **v7; // x8
  const char *v8; // x3
  __int64 v9; // x0
  _QWORD v11[6]; // [xsp+0h] [xbp-30h] BYREF

  v11[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  if ( (unsigned int)kstrtoint(a3, 0, v6 + 916) )
  {
    dev_err(a1, "Invalid input\n");
    a4 = -22;
  }
  else if ( *(_DWORD *)(v6 + 916) && !*(_QWORD *)(v6 + 968) )
  {
    v7 = *(const char ***)(v6 + 344);
    v8 = v7[14];
    memset(v11, 0, 35);
    if ( !v8 )
      v8 = *v7;
    scnprintf(v11, 35, "%s%s", v8, "_kpi");
    v9 = ipc_log_context_create(4, v11, 0);
    *(_QWORD *)(v6 + 968) = v9;
    if ( !v9 )
      dev_info(*(_QWORD *)(v6 + 344), "Err in KPI IPC Log\n");
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
