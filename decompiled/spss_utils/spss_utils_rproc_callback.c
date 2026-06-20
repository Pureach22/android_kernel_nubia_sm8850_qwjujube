__int64 __fastcall spss_utils_rproc_callback(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x2
  __int64 v4; // x2
  __int64 v5; // x2
  __int64 v6; // x0
  __int64 v8; // x0
  __int64 v9; // x2
  __int64 fw_calc_cmac; // x0

  if ( a2 > 1 )
  {
    if ( a2 == 3 )
    {
      mutex_lock(&event_lock);
      complete_all(&dword_96E8);
      dword_9708 = 0;
      word_972E = 1;
      goto LABEL_12;
    }
    if ( a2 == 2 )
    {
      mutex_lock(&event_lock);
      word_9729 = 0;
      dword_9648 = 0;
      dword_9668 = 0;
LABEL_12:
      mutex_unlock(&event_lock);
      return 1;
    }
LABEL_21:
    printk(&unk_892C, "spss_utils_rproc_callback");
    return 1;
  }
  if ( !a2 )
  {
    if ( is_iar_active == 1 )
    {
      if ( is_ssr_disabled == 1 )
      {
        printk(&unk_8B41, "spss_utils_rproc_callback");
        kernel_restart("SPSS SSR disabled, requesting reboot");
      }
      else
      {
        v2 = cmac_mem;
        if ( cmac_mem )
        {
          writel_relaxed((unsigned int)saved_fw_cmac, cmac_mem, 0);
          writel_relaxed(HIDWORD(saved_fw_cmac), v2 + 4, v3);
          writel_relaxed((unsigned int)qword_9798, v2 + 8, v4);
          v6 = writel_relaxed(HIDWORD(qword_9798), v2 + 12, v5);
        }
        else
        {
          v6 = printk(&unk_866E, "spss_set_saved_fw_cmac");
        }
        spss_set_saved_uefi_apps_cmac(v6);
      }
    }
    return 1;
  }
  if ( a2 != 1 )
    goto LABEL_21;
  printk(&unk_89E7, "spss_utils_rproc_callback");
  mutex_lock(&event_lock);
  complete_all(&dword_9708);
  dword_96E8 = 0;
  word_972E = 256;
  v8 = mutex_unlock(&event_lock);
  if ( cmac_mem
    || (!arm64_use_ng_mappings ? (v9 = 0x68000000000713LL) : (v9 = 0x68000000000F13LL),
        v8 = ioremap_prot(cmac_mem_addr, 4096, v9),
        (cmac_mem = v8) != 0) )
  {
    fw_calc_cmac = spss_get_fw_calc_cmac(v8);
    spss_get_apps_calc_cmac(fw_calc_cmac);
    return 1;
  }
  printk(&unk_8719, "spss_utils_rproc_callback");
  return 4294967282LL;
}
