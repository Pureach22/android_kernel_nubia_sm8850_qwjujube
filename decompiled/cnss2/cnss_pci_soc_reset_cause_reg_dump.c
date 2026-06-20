__int64 __fastcall cnss_pci_soc_reset_cause_reg_dump(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  int v8; // w8
  unsigned __int64 StatusReg; // x20
  _QWORD *v10; // x19
  __int64 v11; // x6
  __int64 v12; // x7
  char *v13; // x1
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  __int64 v19; // x7
  const char *v20; // x1
  char v21; // [xsp+0h] [xbp-10h]
  char v22; // [xsp+0h] [xbp-10h]
  unsigned int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_DWORD *)(result + 24);
  if ( v8 == 4369 || v8 == 4366 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) == 0 && (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
      v10 = (_QWORD *)result;
      result = cnss_pci_check_link_status(result, a2, a3, a4, a5, a6, a7, a8);
      if ( !(_DWORD)result )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          v13 = "irq";
        else
          v13 = (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(StatusReg + 2320);
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v13,
          "cnss_pci_soc_reset_cause_reg_dump",
          7u,
          7u,
          "Start to dump SOC Reset Cause registers\n",
          v11,
          v12,
          v21);
        result = cnss_pci_reg_read(v10, 33031688, &v23, v14, v15, v16, v17, v18);
        if ( !(_DWORD)result )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v20 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v20 = "soft_irq";
          }
          else
          {
            v20 = (const char *)(StatusReg + 2320);
          }
          result = cnss_debug_ipc_log_print(
                     cnss_ipc_log_context,
                     v20,
                     "cnss_pci_soc_reset_cause_reg_dump",
                     7u,
                     7u,
                     "WLAON_SOC_RESET_CAUSE_SHADOW_REG = 0x%x\n",
                     v23,
                     v19,
                     v22);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
