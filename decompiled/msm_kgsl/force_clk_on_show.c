__int64 __fastcall force_clk_on_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%d\n", ((unsigned int)*(_QWORD *)(*(_QWORD *)(a1 + 152) + 9136LL) >> 1) & 1);
}
