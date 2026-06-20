__int64 __fastcall cnss_wlfw_respond_get_info_ind_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x22
  const char *v12; // x1
  __int64 v13; // x6
  __int64 v14; // x7
  const char *v15; // x1
  const char *v16; // x1
  __int64 result; // x0
  __int64 (*v18)(void); // x8
  char v19; // [xsp+0h] [xbp-10h]
  char v20; // [xsp+0h] [xbp-10h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
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
  cnss_debug_ipc_log_print(
    cnss_ipc_log_long_context,
    v12,
    "cnss_wlfw_respond_get_info_ind_cb",
    8u,
    7u,
    "Received QMI WLFW respond get info indication\n",
    a7,
    a8,
    v19);
  if ( a3 )
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
    cnss_debug_ipc_log_print(
      cnss_ipc_log_long_context,
      v15,
      "cnss_wlfw_respond_get_info_ind_cb",
      8u,
      7u,
      "Extract message with event length: %d, type: %d, is last: %d, seq no: %d\n",
      *a4,
      *((unsigned __int8 *)a4 + 6149),
      *((_BYTE *)a4 + 6151));
    result = *(_QWORD *)(a1 + 6600);
    if ( result )
    {
      v18 = *(__int64 (**)(void))(a1 + 6608);
      if ( v18 )
      {
        if ( *((_DWORD *)v18 - 1) != 1142088401 )
          __break(0x8228u);
        return v18();
      }
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
             "cnss_wlfw_respond_get_info_ind_cb",
             3u,
             3u,
             "Spurious indication\n",
             v13,
             v14,
             v20);
  }
  return result;
}
