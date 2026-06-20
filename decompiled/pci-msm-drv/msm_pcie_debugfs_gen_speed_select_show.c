__int64 __fastcall msm_pcie_debugfs_gen_speed_select_show(__int64 a1)
{
  seq_write(a1, "Options:\n", 9);
  seq_printf(a1, "\t%d:\t %s\n", 1, "SET MAXIMUM LINK SPEED TO GEN 1");
  seq_printf(a1, "\t%d:\t %s\n", 2, "SET MAXIMUM LINK SPEED TO GEN 2");
  seq_printf(a1, "\t%d:\t %s\n", 3, "SET MAXIMUM LINK SPEED TO GEN 3");
  seq_printf(a1, "\t%d:\t %s\n", 4, "SET MAXIMUM LINK SPEED TO GEN 4");
  return 0;
}
