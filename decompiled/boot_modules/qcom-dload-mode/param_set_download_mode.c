__int64 __fastcall param_set_download_mode(char *s1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v5; // w19
  __int64 v6; // x1
  __int64 v7; // x0

  if ( s1 )
  {
    if ( !strncmp(s1, "nullcrash", 9u) )
    {
      printk(&unk_6E43, "param_set_download_mode");
      printk(&unk_7008, 27524);
    }
    else
    {
      if ( !strncmp(s1, "bugoncrash", 0xAu) )
      {
        v7 = printk(&unk_6FE5, "param_set_download_mode");
        __break(0x800u);
        return msm_enable_dump_mode(v7);
      }
      if ( strncmp(s1, "wdtbark", 7u) )
      {
        if ( !strncmp(s1, "panicfmt1", 9u) )
          panic("ztedbg %s: panic format1\n", "abcdefg");
        if ( !strncmp(s1, "panicfmt2", 9u) )
          panic("ztedbg %d %s: panic format2\n", 2, "a1b2c3d4");
        if ( !strncmp(s1, "panicfmt3", 9u) )
          panic("ztedbg %d 0x%u %s: panic format3\n", 3, 3, "ABCDEFGHI");
        if ( !strncmp(s1, "panicfmt4", 9u) )
          panic("ztedbg %ld %d %u %s: panic format4\n", 4, 4, 4, "fmt4");
        if ( !strncmp(s1, "panicfmt5", 9u) )
          panic("ztedbg panic format5 %% no arg\n");
        if ( !strncmp(s1, "panicfmt6", 9u) )
          panic((const char *)&unk_6F00);
        if ( !strncmp(s1, "panicfmt7", 9u) )
          panic("zte\n");
        if ( !strncmp(s1, "panicfmt8", 9u) )
          panic("ztedbg panic format6 %-*s no arg\n", 20, "fmtfmt8\nfmtfmtfmt8");
        if ( !strncmp(s1, "panicinpanic", 0xCu) )
          panic("ztedbg %s %d %d %d\n", "panicinpanic", 1, 2, 3);
        goto LABEL_2;
      }
      zte_set_wdt_trigger_flag();
      printk(&unk_7067, "param_set_download_mode");
    }
    return 0xFFFFFFFFLL;
  }
LABEL_2:
  printk(&unk_6F73, s1);
  result = param_set_int(s1, a2);
  if ( !(_DWORD)result )
  {
    v5 = dump_mode;
    if ( (dump_mode & 0x20) == 0 || (msm_minidump_enabled() & 1) != 0 || (v5 &= ~0x20u, printk(&unk_71F8, v6), v5) )
    {
      current_download_mode = v5;
      qcom_scm_set_download_mode(v5);
    }
    return 0;
  }
  return result;
}
