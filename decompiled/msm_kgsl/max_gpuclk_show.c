__int64 __fastcall max_gpuclk_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  unsigned int v4; // w9
  __int64 v6; // x0

  v3 = *(_QWORD *)(a1 + 152);
  v4 = *(_DWORD *)(v3 + 10048);
  if ( v4 <= *(_DWORD *)(v3 + 10552) )
    v4 = *(_DWORD *)(v3 + 10552);
  if ( v4 < 0x20 )
    return (int)scnprintf(a3, 4096, "%d\n", *(_DWORD *)(v3 + 28LL * v4 + 9144));
  __break(0x5512u);
  v6 = MEMORY[0x7214528]();
  return max_gpuclk_store(v6);
}
