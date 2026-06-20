__int64 __fastcall tme_opt_file_download_store(__int64 a1, int a2, char *s, unsigned __int64 a4)
{
  __int64 v4; // x19
  __int64 v5; // x20
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  __int64 v8; // x6
  __int64 v9; // x7
  unsigned __int64 v10; // x8
  const char *v11; // x1
  __int16 v12; // w9
  const char *v13; // x8
  unsigned __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x1
  __int16 v18; // w9
  const char *v19; // x8
  unsigned __int64 v20; // x8
  const char *v21; // x1
  __int16 v22; // w9
  const char *v23; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v31; // x9
  int v32; // [xsp+0h] [xbp-10h] BYREF
  char v33; // [xsp+4h] [xbp-Ch]
  __int64 v34; // [xsp+8h] [xbp-8h]

  v4 = a4;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v33 = 0;
  v32 = 0;
  if ( a4 >= 6 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v7 = "irq";
    }
    else
    {
      v12 = *(_DWORD *)(StatusReg + 16);
      v13 = (const char *)(StatusReg + 2320);
      if ( (v12 & 0xFF00) != 0 )
        v7 = "soft_irq";
      else
        v7 = v13;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v7,
      "tme_opt_file_download_store",
      3u,
      3u,
      "Cmd length is larger than %zu bytes, count: %zu ",
      5,
      a4,
      v32);
    goto LABEL_12;
  }
  if ( sscanf(s, "%s", &v32) != 1 )
  {
LABEL_12:
    v4 = -22;
    goto LABEL_13;
  }
  if ( (*(_QWORD *)(v5 + 552) & 4) == 0 )
  {
    v10 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else
    {
      v18 = *(_DWORD *)(v10 + 16);
      v19 = (const char *)(v10 + 2320);
      if ( (v18 & 0xFF00) != 0 )
        v11 = "soft_irq";
      else
        v11 = v19;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v11,
      "tme_opt_file_download_store",
      3u,
      3u,
      "Firmware is not ready yet\n",
      v8,
      v9,
      v32);
    goto LABEL_13;
  }
  v15 = *(_QWORD *)(v5 + 528) - 4366LL;
  if ( v15 > 4 || ((1LL << v15) & 0x19) == 0 || (cnss_bus_runtime_pm_get_sync(v5) & 0x80000000) == 0 )
  {
    switch ( v32 )
    {
      case 6514035:
        _X8 = (unsigned __int64 *)(v5 + 552);
        __asm { PRFM            #0x11, [X8] }
        do
          v31 = __ldxr(_X8);
        while ( __stxr(v31 | 0x80000000, _X8) );
        break;
      case 7499890:
        cnss_bus_load_tme_opt_file(v5);
        v16 = v5;
        v17 = 2;
        goto LABEL_27;
      case 7499876:
        cnss_bus_load_tme_opt_file(v5);
        v16 = v5;
        v17 = 3;
LABEL_27:
        cnss_wlfw_tme_opt_file_dnld_send_sync(v16, v17);
        break;
    }
    v20 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v20 + 16) & 0xF0000) != 0 )
    {
      v21 = "irq";
    }
    else
    {
      v22 = *(_DWORD *)(v20 + 16);
      v23 = (const char *)(v20 + 2320);
      if ( (v22 & 0xFF00) != 0 )
        v21 = "soft_irq";
      else
        v21 = v23;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v21,
      "tme_opt_file_download_store",
      7u,
      7u,
      "Received tme_opt_file_download indication cmd: %s\n",
      (__int64)&v32,
      v9,
      v32);
  }
  v24 = *(_QWORD *)(v5 + 528) - 4366LL;
  if ( v24 <= 4 && ((1LL << v24) & 0x19) != 0 )
    cnss_bus_runtime_pm_put(v5);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v4;
}
