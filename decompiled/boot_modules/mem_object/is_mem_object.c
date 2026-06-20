bool __fastcall is_mem_object(unsigned __int64 a1)
{
  return a1 >= 2 && *(_DWORD *)(a1 + 12) == 2 && *(_QWORD *)(a1 + 24) == (_QWORD)&mem_ops;
}
