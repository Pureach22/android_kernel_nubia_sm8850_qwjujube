__int64 __fastcall cnss_pci_dump_misc_reg(
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

  if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) == 0 && (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    v8 = (_QWORD *)result;
    result = cnss_pci_check_link_status(result, a2, a3, a4, a5, a6, a7, a8);
    if ( !(_DWORD)result )
    {
      cnss_pci_misc_reg_dump(v8, v8[82], 64, "wcss");
      cnss_pci_misc_reg_dump(v8, v8[83], 45, "pcie");
      cnss_pci_misc_reg_dump(v8, v8[84], 131, "wlaon");
      return cnss_pci_misc_reg_dump(v8, v8[85], 13, "syspm");
    }
  }
  return result;
}
