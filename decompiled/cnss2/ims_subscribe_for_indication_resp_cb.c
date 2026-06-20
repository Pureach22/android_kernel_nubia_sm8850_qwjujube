__int64 __fastcall ims_subscribe_for_indication_resp_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int16 *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x21
  const char *v11; // x1
  __int64 result; // x0
  __int64 v13; // x6
  __int64 v14; // x7
  const char *v15; // x1
  const char *v16; // x1
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
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
  result = cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v11,
             "ims_subscribe_for_indication_resp_cb",
             7u,
             7u,
             "Received IMS subscribe indication response\n",
             a7,
             a8,
             vars0);
  if ( a3 )
  {
    if ( *a4 )
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
                 "ims_subscribe_for_indication_resp_cb",
                 3u,
                 3u,
                 "IMS subscribe for indication request rejected, result:%d error:%d\n",
                 *a4,
                 a4[1],
                 vars0a);
      *(_DWORD *)(a3 + 48) = -*a4;
    }
  }
  else
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
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v16,
             "ims_subscribe_for_indication_resp_cb",
             3u,
             3u,
             "spurious response\n",
             v13,
             v14,
             vars0a);
  }
  return result;
}
