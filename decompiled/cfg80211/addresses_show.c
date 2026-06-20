__int64 __fastcall addresses_show(__int64 a1, int a2, char *s)
{
  _QWORD *v3; // x22
  unsigned __int16 *v5; // x23
  char *v6; // x20
  __int64 v7; // x24
  unsigned __int64 v8; // x25

  v3 = (_QWORD *)(a1 - 328);
  if ( !*(_QWORD *)(a1 - 328) )
    return sprintf(s, "%pM\n", (const void *)(a1 - 344));
  v5 = (unsigned __int16 *)(a1 - 298);
  v6 = s;
  if ( *(_WORD *)(a1 - 298) )
  {
    v7 = 0;
    v8 = 0;
    v6 = s;
    do
    {
      ++v8;
      v6 += sprintf(v6, "%pM\n", (const void *)(*v3 + v7));
      v7 += 6;
    }
    while ( v8 < *v5 );
  }
  return v6 - s;
}
