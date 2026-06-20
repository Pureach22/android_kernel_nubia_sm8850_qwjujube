__int64 __fastcall qcom_dload_reboot(__int64 a1, __int64 a2, const char *a3)
{
  unsigned int v4; // w19
  __int64 v5; // x1
  __int64 v6; // x0

  *(_BYTE *)(a1 + 145) = 1;
  current_download_mode = 0;
  qcom_scm_set_download_mode(0);
  if ( a3 )
  {
    if ( !strcmp(a3, "edl") )
    {
      current_download_mode = 1;
      v6 = qcom_scm_set_download_mode(1);
      qcom_scm_disable_sdi(v6);
    }
    else if ( !strcmp(a3, "qcom_dload") )
    {
      v4 = dump_mode;
      if ( (dump_mode & 0x20) == 0 || (msm_minidump_enabled() & 1) != 0 || (v4 &= ~0x20u, printk(&unk_71F8, v5), v4) )
      {
        current_download_mode = v4;
        qcom_scm_set_download_mode(v4);
      }
    }
  }
  if ( current_download_mode )
    reboot_mode = 1;
  return 1;
}
