__int64 __fastcall cnss_vreg_unvote_type(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x6
  const char *v10; // x1
  __int64 v11; // x24
  __int64 v12; // x25
  unsigned __int64 v13; // x23
  unsigned __int64 v14; // x8
  const char *v15; // x1
  int v16; // w8
  unsigned int v17; // w0
  const char *v18; // x1
  unsigned int v19; // w0
  const char *v20; // x1
  __int16 v22; // w9
  const char *v23; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a2 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v9 = a2;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v10 = "irq";
    }
    else
    {
      v22 = *(_DWORD *)(StatusReg + 16);
      v23 = (const char *)(StatusReg + 2320);
      if ( (v22 & 0xFF00) != 0 )
        v10 = "soft_irq";
      else
        v10 = v23;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v10,
      "cnss_vreg_unvote_type",
      3u,
      3u,
      "Unsupported vreg type 0x%x\n",
      v9,
      a8,
      vars0);
    return 4294967274LL;
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 7880) & 1) == 0 )
    {
      v11 = *(_QWORD *)(a1 + 32);
      v12 = a1 + 24;
      if ( v11 != a1 + 24 )
      {
        v13 = _ReadStatusReg(SP_EL0);
        do
        {
          v14 = *(_QWORD *)(v11 + 16);
          if ( v14 && v14 <= 0xFFFFFFFFFFFFF000LL && *(_DWORD *)(v11 + 48) )
          {
            v15 = "irq";
            v16 = *(_DWORD *)(v13 + 16) & 0xF0000;
            if ( *(_DWORD *)(v11 + 56) )
            {
              if ( !v16 )
              {
                if ( (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
                  v15 = "soft_irq";
                else
                  v15 = (const char *)(v13 + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v15,
                "cnss_vreg_unvote_single",
                7u,
                7u,
                "Removing vote for Regulator %s\n",
                *(_QWORD *)(v11 + 24),
                a8,
                vars0);
              if ( *(_DWORD *)(v11 + 40) )
              {
                v17 = regulator_set_load(*(_QWORD *)(v11 + 16));
                if ( (v17 & 0x80000000) != 0 )
                {
                  v18 = "irq";
                  if ( (*(_DWORD *)(v13 + 16) & 0xF0000) == 0 )
                  {
                    if ( (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
                      v18 = "soft_irq";
                    else
                      v18 = (const char *)(v13 + 2320);
                  }
                  cnss_debug_ipc_log_print(
                    cnss_ipc_log_context,
                    v18,
                    "cnss_vreg_unvote_single",
                    3u,
                    3u,
                    "Failed to set load for regulator %s, err = %d\n",
                    *(_QWORD *)(v11 + 24),
                    v17,
                    vars0);
                }
              }
              if ( *(_DWORD *)(v11 + 32) )
              {
                if ( *(_DWORD *)(v11 + 36) )
                {
                  v19 = regulator_set_voltage(*(_QWORD *)(v11 + 16));
                  if ( v19 )
                  {
                    v20 = "irq";
                    if ( (*(_DWORD *)(v13 + 16) & 0xF0000) == 0 )
                    {
                      if ( (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
                        v20 = "soft_irq";
                      else
                        v20 = (const char *)(v13 + 2320);
                    }
                    cnss_debug_ipc_log_print(
                      cnss_ipc_log_context,
                      v20,
                      "cnss_vreg_unvote_single",
                      3u,
                      3u,
                      "Failed to set voltage for regulator %s, err = %d\n",
                      *(_QWORD *)(v11 + 24),
                      v19,
                      vars0);
                  }
                }
              }
            }
            else
            {
              if ( !v16 )
              {
                if ( (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
                  v15 = "soft_irq";
                else
                  v15 = (const char *)(v13 + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v15,
                "cnss_vreg_unvote_single",
                7u,
                7u,
                "Regulator %s is already disabled\n",
                *(_QWORD *)(v11 + 24),
                a8,
                vars0);
            }
          }
          v11 = *(_QWORD *)(v11 + 8);
        }
        while ( v11 != v12 );
      }
    }
    return 0;
  }
}
