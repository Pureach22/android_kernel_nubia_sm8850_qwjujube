__int64 __fastcall cnss_rddm_trigger_check(
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
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v11; // x5
  __int64 v12; // x6
  __int64 v13; // x7
  unsigned int v14; // w0
  unsigned __int64 StatusReg; // x20
  const char *v16; // x1
  __int64 v17; // x3
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x7
  __int64 v22; // x3
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  __int64 v26; // x7
  __int64 v27; // x3
  __int64 v28; // x4
  __int64 v29; // x5
  __int64 v30; // x6
  __int64 v31; // x7
  __int64 v32; // x3
  __int64 v33; // x4
  __int64 v34; // x5
  __int64 v35; // x6
  __int64 v36; // x7
  const char *v37; // x1
  __int64 v38; // x7
  const char *v39; // x1
  char v40; // [xsp+0h] [xbp-30h]
  char v41; // [xsp+0h] [xbp-30h]
  unsigned int v42; // [xsp+14h] [xbp-1Ch] BYREF
  int v43; // [xsp+18h] [xbp-18h] BYREF
  __int64 v44; // [xsp+1Ch] [xbp-14h] BYREF
  unsigned int v45; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+28h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v8 = (_QWORD *)result;
    if ( *(_DWORD *)(result + 24) == 4355 )
    {
      result = cnss_pci_check_link_status(result, a2, a3, a4, a5, a6, a7, a8);
      if ( !(_DWORD)result )
      {
        v45 = 0;
        v14 = cnss_pci_reg_read(v8, 31720208, &v45, v9, v10, v11, v12, v13);
        StatusReg = _ReadStatusReg(SP_EL0);
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
        v44 = 0;
        v42 = 0;
        v43 = 0;
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v16,
          "cnss_rddm_trigger_check",
          3u,
          3u,
          "Read GCC spare to check reset status: 0x%x, ret: %d",
          v45,
          v14,
          v40);
        cnss_pci_reg_read(v8, 28311800, (_DWORD *)&v44 + 1, v17, v18, v19, v20, v21);
        cnss_pci_reg_read(v8, 31515192, &v44, v22, v23, v24, v25, v26);
        cnss_pci_reg_read(v8, 31515196, &v43, v27, v28, v29, v30, v31);
        cnss_pci_reg_read(v8, 31599412, &v42, v32, v33, v34, v35, v36);
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v37 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v37 = "soft_irq";
        }
        else
        {
          v37 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v37,
          "cnss_rddm_trigger_check",
          7u,
          7u,
          "TCSR_PBL_LOGGING: 0x%08x PCIE_BHI_ERRDBG: Start: 0x%08x Size:0x%08x \n",
          HIDWORD(v44),
          (unsigned int)v44,
          v43);
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v39 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v39 = "soft_irq";
        }
        else
        {
          v39 = (const char *)(StatusReg + 2320);
        }
        result = cnss_debug_ipc_log_print(
                   cnss_ipc_log_context,
                   v39,
                   "cnss_rddm_trigger_check",
                   7u,
                   7u,
                   "PBL_WLAN_BOOT_CFG: 0x%08x\n",
                   v42,
                   v38,
                   v41);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
