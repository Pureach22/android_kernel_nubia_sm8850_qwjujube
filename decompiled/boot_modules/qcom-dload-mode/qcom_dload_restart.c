__int64 __fastcall qcom_dload_restart(__int64 a1)
{
  if ( (*(_BYTE *)(a1 + 120) & 1) == 0 && (*(_BYTE *)(a1 + 121) & 1) == 0 )
  {
    qcom_scm_disable_sdi(a1);
    current_download_mode = 0;
    qcom_scm_set_download_mode(0);
  }
  return 1;
}
