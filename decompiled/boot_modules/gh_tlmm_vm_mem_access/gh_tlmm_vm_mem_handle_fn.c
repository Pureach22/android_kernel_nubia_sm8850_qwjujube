__int64 __fastcall gh_tlmm_vm_mem_handle_fn(__int64 a1)
{
  __int64 v2; // x0

  wait_for_completion(&mem_handle_obtained);
  v2 = *(_QWORD *)(a1 - 152);
  *(_DWORD *)(a1 - 88) = 0;
  return dev_err(v2, "Invalid memory handle\n");
}
