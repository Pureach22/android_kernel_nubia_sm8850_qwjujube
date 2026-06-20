__int64 __fastcall qcom_llcc_edac_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  edac_device_del_device(*(_QWORD *)(v1 + 192));
  return edac_device_free_ctl_info(v1);
}
