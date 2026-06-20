__int64 __fastcall qcom_dload_panic(__int64 a1)
{
  int v1; // w8
  unsigned int v2; // w19
  __int64 v3; // x1

  v1 = enable_dump;
  *(_BYTE *)(a1 + 168) = 1;
  if ( v1 )
  {
    v2 = dump_mode;
    if ( (dump_mode & 0x20) == 0 || (msm_minidump_enabled() & 1) != 0 || (v2 &= ~0x20u, printk(&unk_71F8, v3), v2) )
    {
      current_download_mode = v2;
      qcom_scm_set_download_mode(v2);
    }
  }
  return 1;
}
