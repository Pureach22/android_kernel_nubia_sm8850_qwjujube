__int64 __fastcall qce_sps_add_data(__int64 a1, unsigned __int64 a2, unsigned int a3, __int64 a4, char a5, char a6)
{
  __int64 v6; // x12
  _DWORD *v7; // x8
  unsigned int v9; // w13

  if ( !a3 )
    return 0;
  v6 = *(unsigned int *)(a4 + 16);
  v7 = (_DWORD *)(*(_QWORD *)(a4 + 8) + 8 * v6);
  while ( (_DWORD)v6 != 512 )
  {
    v9 = 32704;
    if ( a3 <= 0x7FC0 )
    {
      v9 = a3;
      if ( *(_DWORD *)(a1 + 408) == 6 )
      {
        v9 = a3;
        if ( !*(_DWORD *)(a1 + 404) )
        {
          v9 = a3;
          if ( !*(_DWORD *)(a1 + 412) )
          {
            v9 = a3;
            if ( (a5 & 1) != 0 )
            {
              v9 = a3;
              if ( *(_BYTE *)(a1 + 70304) == 1 )
              {
                if ( (v6 & 1) != 0 )
                  v9 = a3 >> (a6 & 1);
                else
                  v9 = a3 >> ((a6 & 1) == 0);
              }
            }
          }
        }
      }
    }
    a3 -= v9;
    *v7 = a2;
    v7[1] = v9 | (a2 >> 16) & 0xF0000;
    v7 += 2;
    a2 += v9;
    LODWORD(v6) = *(_DWORD *)(a4 + 16) + 1;
    *(_DWORD *)(a4 + 16) = v6;
    if ( !a3 )
      return 0;
  }
  printk(&unk_15B74, "_qce_sps_add_data", 512);
  return 4294967284LL;
}
