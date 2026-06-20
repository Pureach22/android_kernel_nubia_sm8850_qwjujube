__int64 __fastcall cluster_idle_get(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  v3 = *(unsigned int *)(a2 - 8);
  if ( (unsigned int)v3 < 4 )
    return (int)scnprintf(a3, 4096, "%d\n", *(unsigned __int8 *)(*(_QWORD *)(a2 - 24) + v3 + 376) ^ 1u);
  __break(0x5512u);
  return cluster_idle_set();
}
