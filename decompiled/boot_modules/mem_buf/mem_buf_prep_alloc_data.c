__int64 __fastcall mem_buf_prep_alloc_data(__int64 a1, __int64 a2)
{
  unsigned int v3; // w0
  unsigned int v5; // w20
  unsigned __int64 mem_type_data_user; // x0
  unsigned __int64 v7; // x0

  v3 = *(_DWORD *)(a2 + 16);
  *(_QWORD *)a1 = *(_QWORD *)a2;
  *(_DWORD *)(a1 + 8) = v3;
  v5 = mem_buf_acl_to_vmid_perms_list(v3, *(_QWORD *)(a2 + 8), (__int64 *)(a1 + 16), a1 + 24);
  if ( !v5 )
  {
    *(_QWORD *)(a1 + 40) = 0;
    *(_DWORD *)(a1 + 48) = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(a1 + 64) = *(_DWORD *)(a2 + 32);
    mem_type_data_user = mem_buf_retrieve_mem_type_data_user(*(unsigned int *)(a2 + 20), *(_QWORD *)(a2 + 24));
    v5 = mem_type_data_user;
    *(_QWORD *)(a1 + 56) = mem_type_data_user;
    if ( mem_type_data_user <= 0xFFFFFFFFFFFFF000LL )
    {
      v7 = mem_buf_retrieve_mem_type_data_user(*(unsigned int *)(a2 + 32), *(_QWORD *)(a2 + 40));
      *(_QWORD *)(a1 + 72) = v7;
      if ( v7 < 0xFFFFFFFFFFFFF001LL )
        return 0;
      v5 = v7;
      if ( *(_DWORD *)(a1 + 48) == 1 )
        kfree(*(_QWORD *)(a1 + 56));
    }
    kfree(*(_QWORD *)(a1 + 16));
    kfree(*(_QWORD *)(a1 + 24));
  }
  return v5;
}
