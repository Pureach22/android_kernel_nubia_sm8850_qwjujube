__int64 __fastcall mem_entry_max_show(__int64 a1, unsigned int a2, __int64 a3)
{
  if ( a2 < 8 )
    return (int)scnprintf(a3, 4096, "%llu\n", *(_QWORD *)(a1 + 16LL * a2 + 216));
  __break(0x5512u);
  return imported_mem_show();
}
