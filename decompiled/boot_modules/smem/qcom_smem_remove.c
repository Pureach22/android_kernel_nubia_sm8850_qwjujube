__int64 qcom_smem_remove()
{
  __int64 result; // x0

  platform_device_unregister(*(_QWORD *)(_smem + 24));
  hwspin_lock_free(*(_QWORD *)(_smem + 8));
  result = kfree(_smem);
  _smem = 0;
  return result;
}
