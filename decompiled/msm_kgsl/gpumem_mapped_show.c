__int64 __fastcall gpumem_mapped_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%lld\n", *(_QWORD *)(a1 + 336));
}
