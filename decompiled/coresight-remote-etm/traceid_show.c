__int64 __fastcall traceid_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  int v4; // w9
  unsigned __int8 *v5; // x8
  int v6; // w3
  __int64 result; // x0

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  v4 = *(_DWORD *)(v3 + 80);
  v5 = *(unsigned __int8 **)(v3 + 72);
  v6 = *v5;
  if ( v4 == 1 )
    LODWORD(result) = scnprintf(a3, 4096, "%#x\n", v6);
  else
    LODWORD(result) = scnprintf(a3, 4096, "%#x %#x\n", v6, v5[1]);
  return (int)result;
}
