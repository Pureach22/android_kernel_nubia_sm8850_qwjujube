__int64 __fastcall cnss_vreg_off_single(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x20
  int v10; // w8
  const char *v11; // x1
  const char *v12; // x1
  __int64 result; // x0
  const char *v14; // x1
  const char *v15; // x1
  const char *v16; // x1
  char v17; // [xsp+0h] [xbp+0h]
  char v18; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v10 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( *(_DWORD *)(a1 + 56) )
  {
    if ( v10 )
    {
      v11 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v11 = "soft_irq";
    }
    else
    {
      v11 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v11,
      "cnss_vreg_off_single",
      7u,
      7u,
      "Regulator %s is being disabled\n",
      *(_QWORD *)(a1 + 24),
      a8,
      v17);
    result = regulator_disable(*(_QWORD *)(a1 + 16));
    if ( (_DWORD)result )
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v14 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v14 = "soft_irq";
      }
      else
      {
        v14 = (const char *)(StatusReg + 2320);
      }
      result = cnss_debug_ipc_log_print(
                 cnss_ipc_log_context,
                 v14,
                 "cnss_vreg_off_single",
                 3u,
                 3u,
                 "Failed to disable regulator %s, err = %d\n",
                 *(_QWORD *)(a1 + 24),
                 (unsigned int)result,
                 v18);
    }
    if ( *(_DWORD *)(a1 + 40) )
    {
      result = regulator_set_load(*(_QWORD *)(a1 + 16));
      if ( (result & 0x80000000) != 0 )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v15 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v15 = "soft_irq";
        }
        else
        {
          v15 = (const char *)(StatusReg + 2320);
        }
        result = cnss_debug_ipc_log_print(
                   cnss_ipc_log_context,
                   v15,
                   "cnss_vreg_off_single",
                   3u,
                   3u,
                   "Failed to set load for regulator %s, err = %d\n",
                   *(_QWORD *)(a1 + 24),
                   (unsigned int)result,
                   v18);
      }
    }
    if ( *(_DWORD *)(a1 + 32) )
    {
      if ( *(_DWORD *)(a1 + 36) )
      {
        result = regulator_set_voltage(*(_QWORD *)(a1 + 16));
        if ( (_DWORD)result )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v16 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v16 = "soft_irq";
          }
          else
          {
            v16 = (const char *)(StatusReg + 2320);
          }
          result = cnss_debug_ipc_log_print(
                     cnss_ipc_log_context,
                     v16,
                     "cnss_vreg_off_single",
                     3u,
                     3u,
                     "Failed to set voltage for regulator %s, err = %d\n",
                     *(_QWORD *)(a1 + 24),
                     (unsigned int)result,
                     v18);
        }
      }
    }
    *(_DWORD *)(a1 + 56) = 0;
  }
  else
  {
    if ( v10 )
    {
      v12 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v12 = "soft_irq";
    }
    else
    {
      v12 = (const char *)(StatusReg + 2320);
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v12,
             "cnss_vreg_off_single",
             7u,
             7u,
             "Regulator %s is already disabled\n",
             *(_QWORD *)(a1 + 24),
             a8,
             v17);
  }
  return result;
}
