__int64 __fastcall _mem_sort_cmp(__int64 a1, __int64 a2, __int64 a3)
{
  return (unsigned int)(*(_DWORD *)(a2 - 16) - *(_DWORD *)(a3 - 16));
}
