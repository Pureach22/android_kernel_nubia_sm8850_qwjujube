__int64 __fastcall cnss_boot_debug_timeout_hdlr(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x20
  __int64 v9; // x19
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  __int64 v15; // x6
  __int64 v16; // x7
  __int64 v17; // x7
  unsigned __int64 StatusReg; // x8
  const char *v19; // x1
  __int16 v20; // w9
  const char *v21; // x8
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // x3
  __int64 v25; // x4
  __int64 v26; // x5
  __int64 v27; // x6
  __int64 v28; // x7
  __int64 v29; // x1
  __int64 v30; // x2
  __int64 v31; // x3
  __int64 v32; // x4
  __int64 v33; // x5
  __int64 v34; // x6
  __int64 v35; // x7
  __int64 v36; // x1
  __int64 v37; // x2
  __int64 v38; // x3
  __int64 v39; // x4
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 v42; // x7
  __int64 v43; // x1
  __int64 v44; // x2
  __int64 v45; // x3
  __int64 v46; // x4
  __int64 v47; // x5
  __int64 v48; // x6
  __int64 v49; // x7
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = result - 448;
  if ( result != 448 )
  {
    v9 = result;
    result = cnss_pci_check_link_status(result - 448, a2, a3, a4, a5, a6, a7, a8);
    if ( !(_DWORD)result )
    {
      result = cnss_pcie_is_device_down(*(_QWORD *)(*(_QWORD *)v8 + 352LL), v10, v11, v12, v13, v14, v15, v16);
      if ( !(_DWORD)result && (*(_QWORD *)(v9 - 96) & 4) == 0 )
      {
        result = mhi_scan_rddm_cookie(*(_QWORD *)(v9 - 104), 3405695694LL);
        if ( (result & 1) == 0 )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v19 = "irq";
          }
          else
          {
            v20 = *(_DWORD *)(StatusReg + 16);
            v21 = (const char *)(StatusReg + 2320);
            if ( (v20 & 0xFF00) != 0 )
              v19 = "soft_irq";
            else
              v19 = v21;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v19,
            "cnss_boot_debug_timeout_hdlr",
            7u,
            7u,
            "Dump MHI/PBL/SBL debug data every %ds during MHI power on\n",
            7,
            v17,
            vars0);
          if ( !(unsigned int)cnss_pci_check_link_status(v8, v22, v23, v24, v25, v26, v27, v28) )
            mhi_debug_reg_dump(*(_QWORD *)(v9 - 104));
          cnss_pci_bhi_debug_reg_dump(v8, v29, v30, v31, v32, v33, v34, v35);
          cnss_pci_soc_scratch_reg_dump(v8, v36, v37, v38, v39, v40, v41, v42);
          cnss_pci_dump_bl_sram_mem(v8, v43, v44, v45, v46, v47, v48, v49);
          return mod_timer(v9, jiffies + 1750LL);
        }
      }
    }
  }
  return result;
}
