__int64 __fastcall msm_pcie_debugfs_base_select(__int64 a1, unsigned __int64 a2, size_t a3)
{
  size_t v3; // x19
  int v4; // w0
  __int64 v6; // x0
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  v4 = msm_pcie_debugfs_parse_input(a2, a3, (__int64)&v7);
  if ( v4 )
  {
    v3 = v4;
LABEL_3:
    _ReadStatusReg(SP_EL0);
    return v3;
  }
  if ( (unsigned int)(v7 - 10) <= 0xFFFFFFF6 )
  {
    printk(&unk_299E4);
    printk(&unk_2B5F0);
    goto LABEL_3;
  }
  base_sel = v7;
  v6 = printk(&unk_2C9F5);
  if ( (unsigned int)(base_sel - 1) < 9 )
  {
    printk(&unk_25193);
    goto LABEL_3;
  }
  __break(0x5512u);
  return msm_pcie_debugfs_base_select_open(v6);
}
