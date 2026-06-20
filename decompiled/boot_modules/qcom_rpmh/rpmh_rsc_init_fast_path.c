__int64 __fastcall rpmh_rsc_init_fast_path(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x8
  int v5; // w20
  __int64 v7; // x22
  int v8; // w0

  if ( a3 >= 2 )
  {
    __break(0x5512u);
    JUMPOUT(0xA3EC);
  }
  v3 = a1 + 336LL * a3;
  if ( !*(_DWORD *)(v3 + 716) )
    return 4294967277LL;
  v5 = *(_DWORD *)(v3 + 712);
  v7 = *(unsigned int *)(*(_QWORD *)(a1 + 1664) + 16LL);
  v8 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 32) + v7));
  writel_relaxed(v8 & ~(unsigned int)(1LL << v5), (unsigned int *)(*(_QWORD *)(a1 + 32) + v7));
  _tcs_buffer_write(a1, v5, 0, a2);
  return 0;
}
