__int64 __fastcall msm_pcie_debugfs_rc_select_show(__int64 a1)
{
  char v2; // w8

  seq_printf(a1, "Current rc_sel: %d which selects:\n", rc_sel);
  v2 = rc_sel;
  if ( (rc_sel & 1) != 0 )
  {
    seq_printf(a1, "\tPCIe%d\n", 0);
    v2 = rc_sel;
    if ( (rc_sel & 2) == 0 )
    {
LABEL_3:
      if ( (v2 & 4) == 0 )
        goto LABEL_4;
      goto LABEL_10;
    }
  }
  else if ( (rc_sel & 2) == 0 )
  {
    goto LABEL_3;
  }
  seq_printf(a1, "\tPCIe%d\n", 1);
  v2 = rc_sel;
  if ( (rc_sel & 4) == 0 )
  {
LABEL_4:
    if ( (v2 & 8) == 0 )
      goto LABEL_5;
LABEL_11:
    seq_printf(a1, "\tPCIe%d\n", 3);
    if ( (rc_sel & 0x10) == 0 )
      return 0;
    goto LABEL_6;
  }
LABEL_10:
  seq_printf(a1, "\tPCIe%d\n", 2);
  v2 = rc_sel;
  if ( (rc_sel & 8) != 0 )
    goto LABEL_11;
LABEL_5:
  if ( (v2 & 0x10) != 0 )
LABEL_6:
    seq_printf(a1, "\tPCIe%d\n", 4);
  return 0;
}
