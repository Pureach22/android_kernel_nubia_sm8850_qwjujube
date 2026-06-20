__int64 __fastcall cnss_pci_fw_boot_timeout_hdlr(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  _QWORD *v8; // x19
  unsigned __int64 StatusReg; // x20
  char *v10; // x1
  __int64 v11; // x22
  __int64 v12; // x0
  unsigned int v13; // w0
  __int64 v14; // x6
  __int64 v15; // x7
  const char *v16; // x1
  char v17; // [xsp+0h] [xbp-110h]
  char v18; // [xsp+0h] [xbp-110h]
  _QWORD v19[33]; // [xsp+8h] [xbp-108h] BYREF

  v19[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v8 = (_QWORD *)result;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      v10 = "irq";
    else
      v10 = (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(StatusReg + 2320);
    result = cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v10,
               "cnss_pci_fw_boot_timeout_hdlr",
               3u,
               3u,
               "fatal: Timeout waiting for FW ready indication\n",
               a7,
               a8,
               v17);
    v11 = v8[1];
    if ( v11 )
    {
      v12 = *(_QWORD *)(v11 + 7864);
      memset(v19, 0, 256);
      v13 = stack_trace_save_tsk(v12, v19, 32, 0);
      stack_trace_print(v19, v13, 4);
      if ( (*(_QWORD *)(v11 + 552) & 8) != 0 )
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
                   "cnss_pci_fw_boot_timeout_hdlr",
                   7u,
                   7u,
                   "Ignore FW ready timeout for calibration mode\n",
                   v14,
                   v15,
                   v18);
      }
      else
      {
        result = (__int64)cnss_schedule_recovery(*v8 + 200LL, 3);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
