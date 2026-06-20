__int64 __fastcall msm_pcie_read_devid_all(__int64 a1)
{
  __int16 v2; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = 0;
  pci_read_config_word(a1, 2, &v2);
  _ReadStatusReg(SP_EL0);
  return 0;
}
