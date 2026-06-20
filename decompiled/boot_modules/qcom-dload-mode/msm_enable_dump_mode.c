__int64 __fastcall msm_enable_dump_mode(char a1)
{
  __int64 result; // x0
  unsigned int v2; // w19
  __int64 v3; // x1
  char v4; // w8
  unsigned int v5; // w19

  if ( (a1 & 1) == 0 )
  {
    result = 0;
LABEL_7:
    current_download_mode = result;
    return qcom_scm_set_download_mode(result);
  }
  result = (unsigned int)dump_mode;
  if ( (dump_mode & 0x20) == 0 )
    goto LABEL_7;
  v2 = dump_mode;
  v4 = msm_minidump_enabled();
  result = v2;
  if ( (v4 & 1) != 0 )
    goto LABEL_7;
  v5 = v2 & 0xFFFFFFDF;
  printk(&unk_71F8, v3);
  result = v5;
  if ( v5 )
    goto LABEL_7;
  return result;
}
