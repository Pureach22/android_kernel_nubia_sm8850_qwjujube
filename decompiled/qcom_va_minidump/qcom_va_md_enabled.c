__int64 qcom_va_md_enabled()
{
  unsigned __int8 v0; // w8

  if ( (msm_minidump_enabled() & 1) != 0 )
    v0 = atomic_load((unsigned __int8 *)&byte_77FA);
  else
    v0 = 0;
  return v0 & 1;
}
