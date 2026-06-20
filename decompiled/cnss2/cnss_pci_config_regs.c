__int64 __fastcall cnss_pci_config_regs(
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

  v8 = *(_DWORD *)(result + 24);
  if ( v8 == 4355 )
  {
    *(_QWORD *)(result + 688) = 1;
    *(_QWORD *)(result + 672) = &wlaon_reg_access_seq;
  }
  else if ( v8 == 4353 )
  {
    *(_QWORD *)(result + 656) = &wcss_reg_access_seq;
    *(_QWORD *)(result + 664) = &pcie_reg_access_seq;
    *(_QWORD *)(result + 672) = &wlaon_reg_access_seq;
    *(_QWORD *)(result + 688) = 0;
    *(_QWORD *)(result + 680) = &syspm_reg_access_seq;
    return cnss_pci_reg_write((_QWORD *)result, 31474228, 3735884340LL, a4, a5, a6, a7, a8);
  }
  return result;
}
