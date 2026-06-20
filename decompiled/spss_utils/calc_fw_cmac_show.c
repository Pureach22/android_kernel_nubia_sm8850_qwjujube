__int64 __fastcall calc_fw_cmac_show(__int64 a1, __int64 a2, _QWORD *a3)
{
  unsigned int *v4; // x21
  __int64 v5; // x8
  __int64 result; // x0

  if ( a1 && a2 && a3 )
  {
    v4 = (unsigned int *)cmac_mem;
    if ( cmac_mem )
    {
      calc_fw_cmac = 0;
      qword_9820 = 0;
      LODWORD(calc_fw_cmac) = readl_relaxed((unsigned int *)(cmac_mem + 16));
      HIDWORD(calc_fw_cmac) = readl_relaxed(v4 + 5);
      LODWORD(qword_9820) = readl_relaxed(v4 + 6);
      HIDWORD(qword_9820) = readl_relaxed(v4 + 7);
    }
    else
    {
      printk(&unk_866E, "spss_get_fw_calc_cmac");
    }
    v5 = qword_9820;
    result = 16;
    *a3 = calc_fw_cmac;
    a3[1] = v5;
  }
  else
  {
    printk(&unk_8619, "calc_fw_cmac_show");
    return -22;
  }
  return result;
}
