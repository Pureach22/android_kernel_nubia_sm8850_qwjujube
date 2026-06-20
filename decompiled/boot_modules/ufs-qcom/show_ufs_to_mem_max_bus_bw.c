__int64 __fastcall show_ufs_to_mem_max_bus_bw(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v5; // x0

  v3 = *(_QWORD *)(a1 + 152);
  if ( v3 )
    return (int)scnprintf(a3, 4096, "%u\n", *(unsigned __int8 *)(*(_QWORD *)(v3 + 184) + 24LL));
  __break(0x800u);
  v5 = MEMORY[0x711BDB8]();
  return store_ufs_to_mem_max_bus_bw(v5);
}
