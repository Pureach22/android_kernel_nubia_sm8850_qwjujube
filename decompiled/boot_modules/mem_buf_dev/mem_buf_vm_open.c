__int64 __fastcall mem_buf_vm_open(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 656);
  *(_QWORD *)(a2 + 32) = v2 - 16;
  return 0;
}
