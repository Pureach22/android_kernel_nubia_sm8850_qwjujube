__int64 __fastcall _print_clock_residency_stats(unsigned __int64 a1)
{
  __int64 v1; // x8
  unsigned __int64 v2; // x20
  unsigned __int64 v3; // x19
  _QWORD *v4; // x8
  __int64 v5; // x10
  _QWORD *v6; // x21
  _QWORD *v7; // x27
  __int64 v8; // x8
  _QWORD *v9; // x9
  __int64 v10; // x10
  char v11; // w8

  v1 = *(_QWORD *)(a1 + 3904);
  v2 = *(_QWORD *)(v1 + 64);
  if ( v2 < v2 + 72LL * *(unsigned int *)(v1 + 72) )
  {
    v3 = a1;
    do
    {
      if ( *(_BYTE *)(v2 + 20) == 1 )
      {
        if ( (msm_vidc_debug & 0x42) != 0 && *(_QWORD *)(v2 + 24) )
        {
          a1 = ktime_get(a1);
          if ( v2 )
          {
            v4 = (_QWORD *)(v2 + 40);
            while ( 1 )
            {
              v4 = (_QWORD *)*v4;
              if ( v4 == (_QWORD *)(v2 + 40) )
                break;
              if ( v4[2] == *(_QWORD *)(v2 + 24) )
              {
                if ( v4 )
                {
                  v5 = v4[3];
                  if ( v5 )
                    v4[4] += a1 / 0x3E8 - v5;
                  v4[3] = 0;
                }
                break;
              }
            }
          }
          else if ( (msm_vidc_debug & 1) != 0 )
          {
            a1 = printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "get_residency_stats");
          }
        }
        if ( *(_BYTE *)(v2 + 20) == 1 )
        {
          v7 = (_QWORD *)(v2 + 40);
          v6 = *(_QWORD **)(v2 + 40);
          if ( v6 != (_QWORD *)(v2 + 40) )
          {
            v8 = 0;
            v9 = *(_QWORD **)(v2 + 40);
            do
            {
              v10 = v9[4];
              v9 = (_QWORD *)*v9;
              v8 += v10;
            }
            while ( v9 != v7 );
            v11 = msm_vidc_debug;
            do
            {
              if ( (v11 & 0x42) != 0 )
              {
                a1 = printk(&unk_83AC1, "high", 0xFFFFFFFFLL, "codec", "print_residency_stats");
                v11 = msm_vidc_debug;
              }
              v6 = (_QWORD *)*v6;
            }
            while ( v6 != v7 );
          }
        }
      }
      v2 += 72LL;
    }
    while ( v2 < *(_QWORD *)(*(_QWORD *)(v3 + 3904) + 64LL)
               + 72 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(v3 + 3904) + 72LL) );
  }
  return 0;
}
