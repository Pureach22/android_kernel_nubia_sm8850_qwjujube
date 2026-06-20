__int64 __fastcall flag_type_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%x\n", *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + 52LL));
}
