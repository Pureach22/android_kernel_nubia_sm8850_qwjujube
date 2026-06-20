__int64 __fastcall orientation_show(__int64 a1, __int64 a2, __int64 a3)
{
  const char *v3; // x10
  int v4; // w9
  __int64 result; // x0

  v3 = "none\n";
  v4 = *(_DWORD *)(*(_QWORD *)(a1 + 152) + 1236LL);
  if ( v4 == 8 )
    v3 = "B\n";
  if ( v4 == 4 )
    LODWORD(result) = scnprintf(a3, 4096, "A\n");
  else
    LODWORD(result) = scnprintf(a3, 4096, v3);
  return (int)result;
}
