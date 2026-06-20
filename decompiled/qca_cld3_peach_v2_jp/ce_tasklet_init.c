__int64 __fastcall ce_tasklet_init(__int64 result, unsigned int a2)
{
  __int64 v3; // x24
  __int64 v4; // x20
  __int64 v5; // x25
  __int64 v6; // x22
  int v7; // w23
  __int64 v8; // x26
  __int64 v9; // x27
  __int64 v10; // x28

  v3 = result + 26448;
  v4 = result;
  v5 = result + 26493;
  v6 = 0;
  v7 = 0;
  v8 = result + 26492;
  v9 = result + 26488;
  v10 = -672;
  do
  {
    if ( ((a2 >> v7) & 1) != 0 )
    {
      *(_DWORD *)(v9 + v10 + 672) = v7;
      *(_BYTE *)(v8 + v10 + 672) = 1;
      *(_QWORD *)(v4 + v10 + 27168) = v4;
      *(_BYTE *)(v5 + v10 + 672) = (*(_DWORD *)(*(_QWORD *)(v4 + 27400) + v6) & 0x80) != 0;
      result = tasklet_init(v3 + v10 + 672, ce_tasklet, v3 + v10 + 672);
    }
    v10 += 56;
    ++v7;
    v6 += 32;
  }
  while ( v10 );
  return result;
}
