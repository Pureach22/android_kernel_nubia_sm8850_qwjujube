__int64 __fastcall cnss_rddm_trigger_debug(
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
  __int64 v9; // x6
  __int64 v10; // x7
  unsigned __int64 StatusReg; // x20
  const char *v12; // x1
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  __int64 v23; // x7
  const char *v24; // x1
  __int64 v25; // x3
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  __int64 v30; // x7
  const char *v31; // x1
  char v32; // [xsp+0h] [xbp-10h]
  char v33; // [xsp+0h] [xbp-10h]
  char v34; // [xsp+0h] [xbp-10h]
  unsigned int v35; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v8 = (_QWORD *)result;
    if ( *(_DWORD *)(result + 24) == 4355 )
    {
      result = cnss_pci_check_link_status(result, a2, a3, a4, a5, a6, a7, a8);
      if ( !(_DWORD)result )
      {
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
          cnss_ipc_log_context,
          v12,
          "cnss_rddm_trigger_debug",
          3u,
          3u,
          "Write GCC Spare with ACE55 Pattern",
          v9,
          v10,
          v32);
        cnss_pci_reg_write(v8, 31720208, 708181, v13, v14, v15, v16, v17);
        v23 = (unsigned int)cnss_pci_reg_read(v8, 31720208, &v35, v18, v19, v20, v21, v22);
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v24 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v24 = "soft_irq";
        }
        else
        {
          v24 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v24,
          "cnss_rddm_trigger_debug",
          3u,
          3u,
          "Read back GCC Spare: 0x%x, ret: %d",
          v35,
          v23,
          v33);
        v30 = (unsigned int)cnss_pci_reg_read(v8, 31720048, &v35, v25, v26, v27, v28, v29);
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v31 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v31 = "soft_irq";
        }
        else
        {
          v31 = (const char *)(StatusReg + 2320);
        }
        result = cnss_debug_ipc_log_print(
                   cnss_ipc_log_context,
                   v31,
                   "cnss_rddm_trigger_debug",
                   3u,
                   3u,
                   "Warm reset allowed check: 0x%x, ret: %d",
                   v35,
                   v30,
                   v34);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
