__int64 __fastcall csr_get_modify_profile_fields(__int64 a1, unsigned int a2, void *a3)
{
  if ( !a3 )
    return 16;
  qdf_mem_copy(a3, (const void *)(*(_QWORD *)(a1 + 17296) + 96LL * a2 + 40), 1u);
  return 0;
}
