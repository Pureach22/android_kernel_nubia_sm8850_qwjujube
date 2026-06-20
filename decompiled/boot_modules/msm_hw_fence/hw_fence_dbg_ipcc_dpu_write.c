__int64 __fastcall hw_fence_dbg_ipcc_dpu_write(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v6; // w21
  unsigned int client_virt_id; // w0

  v6 = *(_DWORD *)(*(_QWORD *)(a1 + 32) + 632LL);
  client_virt_id = hw_fence_ipcc_get_client_virt_id();
  return (int)debugfs_ipcc_trigger(a1, a2, a3, v6, client_virt_id);
}
