__int64 __fastcall ufs_qcom_init_sysfs(__int64 a1)
{
  __int64 result; // x0

  result = sysfs_create_group(*(_QWORD *)(a1 + 64), &ufs_qcom_sysfs_group);
  if ( (_DWORD)result )
    return dev_err(
             *(_QWORD *)(a1 + 64),
             "%s: Failed to create qcom sysfs group (err = %d)\n",
             "ufs_qcom_init_sysfs",
             result);
  return result;
}
