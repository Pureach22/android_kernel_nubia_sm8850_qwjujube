__int64 __fastcall qcom_smd_remove_device(__int64 a1)
{
  device_unregister(a1);
  return 0;
}
