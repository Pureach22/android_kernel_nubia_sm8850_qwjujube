__int64 __fastcall msm_pcie_debugfs_case_show(__int64 a1)
{
  seq_printf(a1, "\t%d:\t %s\n", 0, "OUTPUT PCIE INFO");
  seq_printf(a1, "\t%d:\t %s\n", 1, "DISABLE LINK");
  seq_printf(a1, "\t%d:\t %s\n", 2, "ENABLE LINK");
  seq_printf(a1, "\t%d:\t %s\n", 3, "DISABLE AND ENABLE LINK");
  seq_printf(a1, "\t%d:\t %s\n", 4, "DISABLE L0S");
  seq_printf(a1, "\t%d:\t %s\n", 5, "ENABLE L0S");
  seq_printf(a1, "\t%d:\t %s\n", 6, "DISABLE L1");
  seq_printf(a1, "\t%d:\t %s\n", 7, "ENABLE L1");
  seq_printf(a1, "\t%d:\t %s\n", 8, "DISABLE L1SS");
  seq_printf(a1, "\t%d:\t %s\n", 9, "ENABLE L1SS");
  seq_printf(a1, "\t%d:\t %s\n", 10, "ENUMERATE");
  seq_printf(a1, "\t%d:\t %s\n", 11, "READ A PCIE REGISTER");
  seq_printf(a1, "\t%d:\t %s\n", 12, "WRITE TO PCIE REGISTER");
  seq_printf(a1, "\t%d:\t %s\n", 13, "DUMP PCIE REGISTER SPACE");
  seq_printf(a1, "\t%d:\t %s\n", 14, "SET AER ENABLE FLAG");
  seq_printf(a1, "\t%d:\t %s\n", 15, "CLEAR AER ENABLE FLAG");
  seq_printf(a1, "\t%d:\t %s\n", 16, "OUTPUT PERST AND WAKE GPIO STATUS");
  seq_printf(a1, "\t%d:\t %s\n", 17, "ASSERT PERST");
  seq_printf(a1, "\t%d:\t %s\n", 18, "DE-ASSERT PERST");
  seq_printf(a1, "\t%d:\t %s\n", 19, "SET KEEP_RESOURCES_ON FLAG");
  seq_printf(a1, "\t%d:\t %s\n", 20, "Trigger SBR");
  seq_printf(a1, "\t%d:\t %s\n", 21, "PCIE REMOTE LOOPBACK");
  seq_printf(a1, "\t%d:\t %s\n", 22, "PCIE LOCAL LOOPBACK");
  return 0;
}
