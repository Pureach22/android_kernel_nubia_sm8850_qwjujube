__int64 __fastcall sg_vma_fault(__int64 a1)
{
  unsigned __int64 *v1; // x11
  unsigned __int64 v2; // x8
  unsigned __int64 v3; // x9
  __int64 v4; // x14
  unsigned __int64 v5; // x10
  unsigned __int64 v6; // x11
  unsigned __int64 v7; // x16
  unsigned __int64 v9; // x8
  __int64 v10; // x9
  unsigned __int64 v11; // x9
  unsigned int v18; // w10

  v1 = *(unsigned __int64 **)a1;
  if ( *(_QWORD *)a1 )
  {
    v2 = v1[12];
    if ( v2 )
    {
      v3 = *(_QWORD *)(a1 + 16) << 12;
      if ( v3 < *(unsigned int *)(v2 + 120) )
      {
        if ( *(_WORD *)(v2 + 112) )
        {
          v4 = 0;
          v5 = *v1;
          v6 = v1[1];
          while ( v6 > v5 )
          {
            if ( v6 - v5 >= 1 << (*(_DWORD *)(v2 + 136) + 12) )
              v7 = 1 << (*(_DWORD *)(v2 + 136) + 12);
            else
              v7 = v6 - v5;
            if ( v3 < v7 )
            {
              v9 = *(_QWORD *)(*(_QWORD *)(v2 + 128) + v4) + (v3 >> 12 << 6);
              v10 = *(_QWORD *)(v9 + 8);
              if ( (v10 & 1) != 0 )
                v11 = v10 - 1;
              else
                v11 = v9;
              _X9 = (unsigned int *)(v11 + 52);
              __asm { PRFM            #0x11, [X9] }
              do
                v18 = __ldxr(_X9);
              while ( __stxr(v18 + 1, _X9) );
              *(_QWORD *)(a1 + 80) = v9;
              return 0;
            }
            v4 += 8;
            v5 += v7;
            v3 -= v7;
            if ( 8 * *(unsigned __int16 *)(v2 + 112) == (_DWORD)v4 )
              return 2;
          }
        }
      }
    }
  }
  return 2;
}
