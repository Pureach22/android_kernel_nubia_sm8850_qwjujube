__int64 __fastcall freq_req_val_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%x\n", *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + 40LL));
}
