__int64 __fastcall sample_interval_ms_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%u\n", 100 * (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 + 152) + 16LL));
}
