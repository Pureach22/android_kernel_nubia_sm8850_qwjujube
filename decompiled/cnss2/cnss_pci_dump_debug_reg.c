__int64 __fastcall cnss_pci_dump_debug_reg(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 result; // x0
  __int64 v10; // x6
  __int64 v11; // x7
  unsigned __int64 StatusReg; // x8
  const char *v13; // x1
  __int16 v14; // w9
  const char *v15; // x8
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  __int64 v30; // x1
  __int64 v31; // x2
  __int64 v32; // x3
  __int64 v33; // x4
  __int64 v34; // x5
  __int64 v35; // x6
  __int64 v36; // x7
  char v37; // [xsp+0h] [xbp+0h]

  result = cnss_pci_check_link_status(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !(_DWORD)result )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else
    {
      v14 = *(_DWORD *)(StatusReg + 16);
      v15 = (const char *)(StatusReg + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v15;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v13,
      "cnss_pci_dump_debug_reg",
      7u,
      7u,
      "Start to dump debug registers\n",
      v10,
      v11,
      v37);
    if ( !(unsigned int)cnss_pci_check_link_status(a1, v16, v17, v18, v19, v20, v21, v22) )
      mhi_debug_reg_dump(*(_QWORD *)(a1 + 344));
    cnss_pci_bhi_debug_reg_dump(a1, v23, v24, v25, v26, v27, v28, v29);
    cnss_pci_soc_scratch_reg_dump(a1, v30, v31, v32, v33, v34, v35, v36);
    cnss_pci_dump_ce_reg(a1, 12);
    cnss_pci_dump_ce_reg(a1, 9);
    return cnss_pci_dump_ce_reg(a1, 10);
  }
  return result;
}
