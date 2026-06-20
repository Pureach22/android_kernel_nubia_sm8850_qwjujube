__int64 __fastcall traceid_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%#lx\n", *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + 44LL));
}
