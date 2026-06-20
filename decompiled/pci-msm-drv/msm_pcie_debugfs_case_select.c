size_t __fastcall msm_pcie_debugfs_case_select(__int64 a1, unsigned __int64 a2, size_t a3)
{
  size_t v3; // x19
  int v4; // w0
  char v6; // w8
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  v4 = msm_pcie_debugfs_parse_input(a2, a3, (__int64)&v7);
  if ( !v4 )
  {
    printk(&unk_25FED);
    v6 = rc_sel;
    if ( (rc_sel & 1) != 0 )
    {
      ((void (__fastcall *)(__int64, _QWORD))msm_pcie_sel_debug_testcase)(msm_pcie_dev[0], v7);
      v6 = rc_sel;
      if ( (rc_sel & 2) == 0 )
      {
LABEL_6:
        if ( (v6 & 4) == 0 )
          goto LABEL_7;
        goto LABEL_12;
      }
    }
    else if ( (rc_sel & 2) == 0 )
    {
      goto LABEL_6;
    }
    ((void (__fastcall *)(__int64, _QWORD))msm_pcie_sel_debug_testcase)(qword_30B50, v7);
    v6 = rc_sel;
    if ( (rc_sel & 4) == 0 )
    {
LABEL_7:
      if ( (v6 & 8) == 0 )
        goto LABEL_8;
      goto LABEL_13;
    }
LABEL_12:
    ((void (__fastcall *)(__int64, _QWORD))msm_pcie_sel_debug_testcase)(qword_30B58, v7);
    v6 = rc_sel;
    if ( (rc_sel & 8) == 0 )
    {
LABEL_8:
      if ( (v6 & 0x10) == 0 )
        goto LABEL_3;
LABEL_14:
      ((void (__fastcall *)(__int64, _QWORD))msm_pcie_sel_debug_testcase)(qword_30B68, v7);
      goto LABEL_3;
    }
LABEL_13:
    ((void (__fastcall *)(__int64, _QWORD))msm_pcie_sel_debug_testcase)(qword_30B60, v7);
    if ( (rc_sel & 0x10) == 0 )
      goto LABEL_3;
    goto LABEL_14;
  }
  v3 = v4;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return v3;
}
