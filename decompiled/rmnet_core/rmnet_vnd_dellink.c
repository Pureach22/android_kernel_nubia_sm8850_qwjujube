__int64 __fastcall rmnet_vnd_dellink(char a1, __int64 a2, __int64 a3)
{
  if ( a1 == -1 || !*(_QWORD *)(a3 + 8) )
    return 4294967274LL;
  *(_QWORD *)(a3 + 8) = 0;
  --*(_BYTE *)(a2 + 12);
  return 0;
}
