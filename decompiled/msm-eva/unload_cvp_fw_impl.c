__int64 __fastcall unload_cvp_fw_impl(__int64 a1)
{
  qcom_scm_pas_shutdown(*(unsigned int *)(a1 + 2200));
  *(_DWORD *)(a1 + 2200) = 0;
  return 0;
}
