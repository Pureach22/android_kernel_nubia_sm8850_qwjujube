__int64 __fastcall rpmh_stress_trig1_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  unsigned __int64 v5; // x8

  v3 = *(_QWORD *)(a1 + 96);
  result = -22;
  v5 = *(_QWORD *)(v3 + 152);
  if ( v5 && v5 <= 0xFFFFFFFFFFFFF000LL && *(_BYTE *)(v5 + 160) == 1 )
    return (int)scnprintf(a3, 4096, "%#x\n", *(_DWORD *)(v5 + 108));
  return result;
}
