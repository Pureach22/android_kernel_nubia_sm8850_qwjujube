__int64 __fastcall thermal_pwrlevel_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x9
  unsigned int v4; // w10
  unsigned int v5; // w9
  __int64 v6; // x3

  v3 = *(_QWORD *)(a1 + 152);
  v4 = *(_DWORD *)(v3 + 10048);
  v5 = *(_DWORD *)(v3 + 10552);
  if ( v4 <= v5 )
    v6 = v5;
  else
    v6 = v4;
  return (int)scnprintf(a3, 4096, "%d\n", v6);
}
