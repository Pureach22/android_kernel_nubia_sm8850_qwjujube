__int64 __fastcall wmi_flush_endpoint(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  return htc_flush_endpoint(*(_QWORD *)(a1 + 64), *(_DWORD *)(a1 + 28), 0, a4);
}
