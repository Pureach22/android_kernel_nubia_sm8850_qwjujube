__int64 __fastcall mode_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  const char *v5; // x2

  v3 = *(_QWORD *)(a1 + 152);
  if ( (*(_BYTE *)(v3 + 746) & 1) != 0 )
  {
    v5 = "peripheral\n";
  }
  else if ( *(_DWORD *)(v3 + 752) )
  {
    v5 = "none\n";
  }
  else
  {
    v5 = "host\n";
  }
  return (int)scnprintf(a3, 4096, v5);
}
