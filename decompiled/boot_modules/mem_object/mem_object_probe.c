__int64 __fastcall mem_object_probe(__int64 a1)
{
  __int64 result; // x0

  result = dma_set_mask(a1 + 16, -1);
  if ( !(_DWORD)result )
  {
    dma_set_coherent_mask(a1 + 16, -1);
    mem_ops = (__int64)mo_shm_bridge_release;
    qword_A0 = (__int64)mo_shm_bridge_prepare;
    init_si_object_user(&primordial_object, 8, &shm_bridge__po_ops, "po_in_mem_object");
    mem_object_pdev = a1;
    return 0;
  }
  return result;
}
