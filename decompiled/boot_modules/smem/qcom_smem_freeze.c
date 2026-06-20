__int64 qcom_smem_freeze()
{
  platform_device_unregister(*(_QWORD *)(_smem + 24));
  hwspin_lock_free(*(_QWORD *)(_smem + 8));
  kfree(_smem);
  _smem = 0;
  return 0;
}
