__int64 __fastcall adreno_hwsched_parse_payload_rb(__int64 a1, _QWORD *a2)
{
  unsigned int *v2; // x9
  unsigned int v3; // w8
  int v4; // w8
  unsigned int v5; // w22
  unsigned int v8; // w24
  _DWORD *v9; // x23
  _WORD *v10; // x21

  v2 = *(unsigned int **)(a1 + 22792);
  v3 = *v2;
  if ( *v2 )
  {
    v4 = (v3 >> 6) & 0x3FC;
    v5 = v4 - 36;
    if ( v4 == 36 )
    {
      LOBYTE(v3) = 0;
    }
    else
    {
      LOBYTE(v3) = 0;
      v8 = 0;
      v9 = v2 + 9;
      do
      {
        v10 = (_WORD *)((char *)v9 + v8);
        if ( *v10 == 2 )
        {
          adreno_hwsched_snapshot_rb_payload(a1, a2, (__int64)v9 + v8);
          LOBYTE(v3) = 1;
        }
        v8 += 4 * (unsigned __int16)v10[1] + 4;
      }
      while ( v8 < v5 );
    }
  }
  return v3 & 1;
}
