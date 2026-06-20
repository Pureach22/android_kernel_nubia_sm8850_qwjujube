__int64 __fastcall gpuclk_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  unsigned int v4; // w9
  __int64 v6; // x0

  v3 = *(_QWORD *)(a1 + 152);
  v4 = *(_DWORD *)(v3 + 10040);
  if ( v4 < 0x20 )
    return (int)scnprintf(a3, 4096, "%ld\n", *(unsigned int *)(v3 + 28LL * v4 + 9144));
  __break(0x5512u);
  v6 = MEMORY[0x7214394]();
  return gpuclk_store(v6);
}
