__int64 __fastcall mem_prot_debuginfo_open(__int64 a1, __int64 a2)
{
  return single_open(a2, mem_prot_debuginfo_show, *(_QWORD *)(a1 + 696));
}
