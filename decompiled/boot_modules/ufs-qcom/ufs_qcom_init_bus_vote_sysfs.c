__int64 __fastcall ufs_qcom_init_bus_vote_sysfs(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 64LL);
  *(_QWORD *)(a1 + 32) = "max_bus_bw";
  *(_QWORD *)(a1 + 48) = show_ufs_to_mem_max_bus_bw;
  *(_QWORD *)(a1 + 56) = store_ufs_to_mem_max_bus_bw;
  *(_WORD *)(a1 + 40) = 420;
  result = device_create_file(v1);
  if ( (_DWORD)result )
    return dev_err(v1, "%s: (%d) Failed to create sysfs entries\n", "ufs_qcom_init_bus_vote_sysfs", result);
  return result;
}
