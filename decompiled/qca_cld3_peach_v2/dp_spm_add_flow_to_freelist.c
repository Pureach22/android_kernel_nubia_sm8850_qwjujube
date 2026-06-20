__int64 __fastcall dp_spm_add_flow_to_freelist(__int64 a1)
{
  __int64 result; // x0
  __int16 v3; // w21
  __int64 v4; // x22

  result = dp_get_context();
  if ( result )
  {
    v3 = *(_WORD *)(a1 + 16);
    v4 = result;
    qdf_spinlock_acquire(result + 2984);
    qdf_mem_set((void *)(a1 - 32), 0xC0u, 0);
    *(_WORD *)(a1 + 16) = v3;
    qdf_list_insert_back((_QWORD *)(v4 + 2960), (_QWORD *)(a1 - 32));
    return qdf_spinlock_release(v4 + 2984);
  }
  return result;
}
