__int64 __fastcall qcom_socinfo_remove(__int64 a1)
{
  _QWORD *v1; // x19

  v1 = *(_QWORD **)(a1 + 168);
  soc_device_unregister(*v1);
  return debugfs_remove(v1[8]);
}
