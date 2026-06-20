__int64 __fastcall rmnet_ll_buffer_pool_alloc(__int64 a1)
{
  *(_DWORD *)(a1 + 16) = 0;
  *(_QWORD *)a1 = a1;
  *(_QWORD *)(a1 + 8) = a1;
  *(_QWORD *)(a1 + 24) = a1;
  *(_DWORD *)(a1 + 32) = 0;
  return 0;
}
