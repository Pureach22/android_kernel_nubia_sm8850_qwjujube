unsigned int *__fastcall sde_kms_rect_merge_rectangles(unsigned int *result, __int64 a2)
{
  unsigned int *v3; // x20
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x21
  int v6; // w25
  int v7; // w23
  unsigned __int16 *v8; // x24
  int v9; // w26
  int v10; // w28
  unsigned int v11; // w5
  unsigned int v12; // w6
  unsigned int v13; // w7
  unsigned int v14; // w9

  if ( result )
  {
    if ( a2 )
    {
      *(_QWORD *)a2 = 0;
      v3 = result;
      v4 = *result;
      if ( (_DWORD)v4 )
      {
        v5 = 0;
        LOWORD(v6) = 0;
        LOWORD(v7) = 0;
        v8 = (unsigned __int16 *)result + 3;
        LOWORD(v9) = -1;
        LOWORD(v10) = -1;
        do
        {
          if ( v5 == 5 )
          {
            __break(0x5512u);
            return (unsigned int *)_traceiter_sde_perf_set_qos_luts();
          }
          v11 = *(v8 - 1);
          v12 = *v8;
          v13 = v8[1];
          if ( (unsigned __int16)v9 >= v11 )
            v9 = *(v8 - 1);
          else
            v9 = (unsigned __int16)v9;
          v14 = v8[2];
          if ( (unsigned __int16)v10 >= v12 )
            v10 = *v8;
          else
            v10 = (unsigned __int16)v10;
          if ( (unsigned __int16)v6 <= v13 )
            v6 = v8[1];
          else
            v6 = (unsigned __int16)v6;
          if ( (unsigned __int16)v7 <= v14 )
            v7 = v8[2];
          else
            v7 = (unsigned __int16)v7;
          if ( (_drm_debug & 4) != 0 )
          {
            result = (unsigned int *)_drm_dev_dbg(
                                       0,
                                       0,
                                       0,
                                       "roi%d (%d,%d),(%d,%d) -> crtc (%d,%d),(%d,%d)\n",
                                       v5,
                                       v11,
                                       v12,
                                       v13,
                                       v14,
                                       v9,
                                       v10,
                                       v6,
                                       v7);
            v4 = *v3;
          }
          ++v5;
          v8 += 4;
        }
        while ( v5 < v4 );
        if ( v6 )
        {
          if ( v7 )
          {
            *(_WORD *)a2 = v9;
            *(_WORD *)(a2 + 4) = v6 - v9;
            *(_WORD *)(a2 + 2) = v10;
            *(_WORD *)(a2 + 6) = v7 - v10;
          }
        }
      }
    }
  }
  return result;
}
