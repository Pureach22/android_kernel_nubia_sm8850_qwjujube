__int64 spss_get_fw_calc_cmac()
{
  unsigned int *v0; // x19
  __int64 result; // x0

  v0 = (unsigned int *)cmac_mem;
  if ( !cmac_mem )
    return printk(&unk_866E, "spss_get_fw_calc_cmac");
  calc_fw_cmac = 0;
  qword_9820 = 0;
  LODWORD(calc_fw_cmac) = readl_relaxed((unsigned int *)(cmac_mem + 16));
  HIDWORD(calc_fw_cmac) = readl_relaxed(v0 + 5);
  LODWORD(qword_9820) = readl_relaxed(v0 + 6);
  result = readl_relaxed(v0 + 7);
  HIDWORD(qword_9820) = result;
  return result;
}
