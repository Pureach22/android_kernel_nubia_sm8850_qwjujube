__int64 ufs_qcom_cpu_online()
{
  ufs_qcom_set_esi_affinity_hint(*(_QWORD *)(ufs_qcom_hosts[0] + 16));
  return 0;
}
