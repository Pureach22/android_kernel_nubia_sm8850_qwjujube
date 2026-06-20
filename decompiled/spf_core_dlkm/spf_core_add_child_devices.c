__int64 spf_core_add_child_devices()
{
  bool is_apm_ready; // w8
  __int64 v1; // x0
  __int64 result; // x0

  printk(&unk_713A, "spf_core_add_child_devices");
  is_apm_ready = spf_core_is_apm_ready(0x493E0u);
  v1 = *(_QWORD *)spf_core_priv;
  if ( !is_apm_ready )
    return dev_err(v1, "%s: apm is not up\n", "spf_core_add_child_devices");
  dev_err(v1, "%s: apm is up\n", "spf_core_add_child_devices");
  result = of_platform_populate(*(_QWORD *)(*(_QWORD *)spf_core_priv + 744LL), 0, 0);
  if ( (_DWORD)result )
    result = dev_err(
               *(_QWORD *)spf_core_priv,
               "%s: failed to add child nodes, ret=%d\n",
               "spf_core_add_child_devices",
               result);
  *(_BYTE *)(spf_core_priv + 64) = 0;
  return result;
}
