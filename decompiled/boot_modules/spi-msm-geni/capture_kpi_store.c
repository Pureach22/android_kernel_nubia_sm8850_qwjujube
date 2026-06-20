__int64 __fastcall capture_kpi_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x22
  const char **v7; // x8
  const char *v8; // x3
  __int64 v9; // x0
  _QWORD v11[4]; // [xsp+0h] [xbp-30h] BYREF
  int v12; // [xsp+20h] [xbp-10h]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  if ( v4 )
  {
    if ( (unsigned int)kstrtoint(a3, 0, v4 + 496) )
    {
      a4 = -22;
      dev_err(a1, "Invalid input\n");
    }
    else if ( *(_DWORD *)(v4 + 496) && !*(_QWORD *)(v4 + 488) )
    {
      v7 = *(const char ***)(v4 + 200);
      v12 = 0;
      v8 = v7[14];
      memset(v11, 0, sizeof(v11));
      if ( !v8 )
        v8 = *v7;
      scnprintf(v11, 36, "%s%s", v8, "_kpi");
      v9 = ipc_log_context_create(4, v11, 0);
      *(_QWORD *)(v4 + 488) = v9;
      if ( !v9 )
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
