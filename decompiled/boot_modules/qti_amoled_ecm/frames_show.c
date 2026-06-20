__int64 __fastcall frames_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%u\n", *(unsigned __int16 *)(*(_QWORD *)(a1 + 152) + 32LL));
}
