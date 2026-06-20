__int64 __fastcall msm_pcie_debugfs_rc_select(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  int v4; // w0
  unsigned int v6; // w8
  void *v7; // x0
  char v8; // w8
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v4 = msm_pcie_debugfs_parse_input(a2, a3, &v9);
  if ( !v4 )
  {
    if ( v9 && (!rc_sel_max ? (v6 = 0) : (v6 = 31), v9 <= v6) )
    {
      v7 = &unk_22EE4;
      rc_sel = v9;
    }
    else
    {
      printk(&unk_2C298);
      v7 = &unk_2F075;
    }
    printk(v7);
    printk(&unk_2D975);
    v8 = rc_sel;
    if ( (rc_sel & 1) != 0 )
    {
      printk(&unk_2364E);
      v8 = rc_sel;
      if ( (rc_sel & 2) == 0 )
      {
LABEL_13:
        if ( (v8 & 4) == 0 )
          goto LABEL_14;
        goto LABEL_19;
      }
    }
    else if ( (rc_sel & 2) == 0 )
    {
      goto LABEL_13;
    }
    printk(&unk_2364E);
    v8 = rc_sel;
    if ( (rc_sel & 4) == 0 )
    {
LABEL_14:
      if ( (v8 & 8) == 0 )
        goto LABEL_15;
      goto LABEL_20;
    }
LABEL_19:
    printk(&unk_2364E);
    v8 = rc_sel;
    if ( (rc_sel & 8) == 0 )
    {
LABEL_15:
      if ( (v8 & 0x10) == 0 )
        goto LABEL_3;
LABEL_16:
      printk(&unk_2364E);
      goto LABEL_3;
    }
LABEL_20:
    printk(&unk_2364E);
    if ( (rc_sel & 0x10) == 0 )
      goto LABEL_3;
    goto LABEL_16;
  }
  v3 = v4;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return v3;
}
