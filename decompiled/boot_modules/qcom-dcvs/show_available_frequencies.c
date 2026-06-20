__int64 __fastcall show_available_frequencies(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w22
  unsigned int v6; // w23
  int v7; // w0
  int v8; // w20

  if ( *(_DWORD *)(a1 + 112) )
  {
    v5 = 0;
    v6 = 0;
    do
    {
      v7 = scnprintf(a3 + v5, 4096LL - v5, "%d ", *(_DWORD *)(*(_QWORD *)(a1 + 104) + 4LL * (int)v6++));
      v5 += v7;
    }
    while ( v6 < *(_DWORD *)(a1 + 112) );
  }
  else
  {
    v5 = 0;
  }
  if ( v5 )
    v8 = v5 - 1;
  else
    v8 = 0;
  return (int)(scnprintf(a3 + v8, 4096LL - v8, "\n") + v8);
}
