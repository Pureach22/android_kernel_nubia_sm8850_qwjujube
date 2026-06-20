__int64 __fastcall gmu_core_trace_header_init(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x9

  v1 = *(_QWORD *)(*(_QWORD *)result + 8LL);
  *(_DWORD *)(v1 + 40) = 5;
  *(_QWORD *)(v1 + 4) = 0x5040000001LL;
  *(_QWORD *)(v1 + 32) = *(unsigned int *)(*(_QWORD *)result + 184LL);
  v2 = *(_QWORD *)(*(_QWORD *)result + 40LL);
  *(_DWORD *)(v1 + 44) = 1;
  *(_DWORD *)(v1 + 12) = v2;
  return result;
}
