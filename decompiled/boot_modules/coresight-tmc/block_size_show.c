__int64 __fastcall block_size_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  int v4; // w3

  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + 304LL);
  if ( v3 )
    v4 = *(_DWORD *)(v3 + 152);
  else
    v4 = 0;
  return (int)scnprintf(a3, 4096, "%d\n", v4);
}
