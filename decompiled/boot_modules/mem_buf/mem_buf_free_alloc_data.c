__int64 __fastcall mem_buf_free_alloc_data(__int64 a1)
{
  if ( *(_DWORD *)(a1 + 64) == 1 )
    kfree(*(_QWORD *)(a1 + 72));
  if ( *(_DWORD *)(a1 + 48) == 1 )
    kfree(*(_QWORD *)(a1 + 56));
  kfree(*(_QWORD *)(a1 + 16));
  return kfree(*(_QWORD *)(a1 + 24));
}
