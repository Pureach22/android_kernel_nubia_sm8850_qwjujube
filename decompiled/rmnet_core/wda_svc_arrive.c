__int64 __fastcall wda_svc_arrive(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v3; // x1

  *(_WORD *)(a1 + 304) = 42;
  *(_DWORD *)(a1 + 308) = *(_DWORD *)(a2 + 12);
  v2 = *(_DWORD *)(a2 + 16);
  v3 = *(_QWORD *)(a1 - 40);
  *(_DWORD *)(a1 + 312) = v2;
  queue_work_on(32, v3, a1 - 32);
  return 0;
}
