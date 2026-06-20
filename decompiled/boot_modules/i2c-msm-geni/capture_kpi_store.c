__int64 __fastcall capture_kpi_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  const char *v7; // x3
  __int64 v8; // x0
  _QWORD v10[4]; // [xsp+0h] [xbp-30h] BYREF
  int v11; // [xsp+20h] [xbp-10h]
  __int64 v12; // [xsp+28h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  if ( v4 )
  {
    if ( (unsigned int)kstrtoint(a3, 0, v4 + 5112) )
    {
      a4 = -22;
      dev_err(a1, "Invalid input\n");
    }
    else if ( *(_DWORD *)(v4 + 5112) && !*(_QWORD *)(v4 + 5104) )
    {
      v11 = 0;
      memset(v10, 0, sizeof(v10));
      v7 = *(const char **)(*(_QWORD *)v4 + 112LL);
      if ( !v7 )
        v7 = **(const char ***)v4;
      scnprintf(v10, 36, "%s%s", v7, "_kpi");
      v8 = ipc_log_context_create(4, v10, 0);
      *(_QWORD *)(v4 + 5104) = v8;
      if ( !v8 )
        dev_err(a1, "Error creating kpi IPC logs\n");
    }
  }
  else
  {
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
