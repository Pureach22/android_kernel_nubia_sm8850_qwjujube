__int64 __fastcall cam_isp_copy_fcg_config(__int64 result, __int64 a2)
{
  int v2; // w8
  unsigned int v3; // w26
  int v4; // w13
  int v5; // w19
  __int64 v6; // x15
  const char *v7; // x14
  unsigned int *v8; // x20
  __int64 v9; // x28
  unsigned int v10; // w8
  unsigned int v11; // w23
  _DWORD *v12; // x8
  int *v13; // x11
  int v14; // w10
  int v15; // w9
  int v16; // w8
  unsigned int v17; // w23
  __int64 v18; // x21
  _DWORD *v19; // x8
  _DWORD *v20; // x11
  int v21; // w10
  int v22; // w9
  int v23; // w8
  const char *v24; // x28
  char v25; // w8
  __int64 v26; // [xsp+20h] [xbp-20h]
  __int64 v27; // [xsp+20h] [xbp-20h]
  int v28; // [xsp+2Ch] [xbp-14h]
  int v29; // [xsp+2Ch] [xbp-14h]
  __int64 v30; // [xsp+30h] [xbp-10h]
  __int64 v31; // [xsp+30h] [xbp-10h]
  __int64 v32; // [xsp+38h] [xbp-8h]
  __int64 v33; // [xsp+38h] [xbp-8h]

  *(_DWORD *)result = *(_DWORD *)(a2 + 8);
  v2 = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(result + 4) = v2;
  if ( *(_DWORD *)(a2 + 8) )
  {
    v3 = 0;
    v4 = 56 * v2 + 40;
    v5 = 0;
    v6 = a2 + 40;
    v7 = "Copy FCG STATS config on ch 0x%x, prediction idx %d, stats_index_g: %u, stats_index_r: %u, stats_index_b: %u";
    do
    {
      v8 = (unsigned int *)(*(_QWORD *)(result + 16) + 16LL * (int)v3);
      v9 = v6 + v3 * v4;
      *v8 = *(_DWORD *)(v9 + 4);
      v10 = *(_DWORD *)(v9 + 8);
      v8[1] = v10;
      if ( (v10 & 1) != 0 )
      {
        if ( *(_DWORD *)(a2 + 12) )
        {
          v11 = 0;
          do
          {
            v12 = (_DWORD *)(v9 + 40 + 56LL * (int)v11);
            v13 = (int *)(*((_QWORD *)v8 + 1) + 24LL * (int)v11);
            v14 = v12[3];
            v13[2] = v14;
            v15 = v12[2];
            v13[1] = v15;
            v16 = v12[1];
            *v13 = v16;
            if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              v32 = a2;
              v30 = result;
              v28 = v4;
              v26 = v6;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_isp_copy_fcg_config",
                12570,
                "Copy FCG PHASE config on ch 0x%x, prediction idx %d, phase_index_g: %u, phase_index_r: %u, phase_index_b: %u",
                *v8,
                v11,
                v16,
                v15,
                v14);
              result = v30;
              a2 = v32;
              v7 = "Copy FCG STATS config on ch 0x%x, prediction idx %d, stats_index_g: %u, stats_index_r: %u, stats_index_b: %u";
              v6 = v26;
              v4 = v28;
            }
            ++v11;
          }
          while ( v11 < *(_DWORD *)(a2 + 12) );
          v10 = *(_DWORD *)(v9 + 8);
        }
        ++v5;
      }
      if ( (v10 & 2) != 0 )
      {
        if ( *(_DWORD *)(a2 + 12) )
        {
          v17 = 0;
          v18 = v9 + 40;
          do
          {
            v19 = (_DWORD *)(v18 + 56LL * (int)v17);
            v20 = (_DWORD *)(*((_QWORD *)v8 + 1) + 24LL * (int)v17);
            v21 = v19[6];
            v20[5] = v21;
            v22 = v19[5];
            v20[4] = v22;
            v23 = v19[4];
            v20[3] = v23;
            if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              v33 = a2;
              v31 = result;
              v24 = v7;
              v29 = v4;
              v27 = v6;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int, int, int))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_isp_copy_fcg_config",
                12592,
                v7,
                *v8,
                v17,
                v23,
                v22,
                v21);
              result = v31;
              a2 = v33;
              v7 = v24;
              v6 = v27;
              v4 = v29;
            }
            ++v17;
          }
          while ( v17 < *(_DWORD *)(a2 + 12) );
        }
        ++v5;
      }
      ++v3;
    }
    while ( v3 < *(_DWORD *)(a2 + 8) );
  }
  else
  {
    v5 = 0;
  }
  v25 = debug_mdl;
  *(_DWORD *)(result + 8) = v5;
  if ( (v25 & 8) != 0 && !debug_priority )
    return ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             v25 & 8,
             4,
             "cam_isp_copy_fcg_config",
             12601,
             "Inspect on copied FCG config, num_types: %u, num_ch_ctx: %u, num_predictions: %u",
             v5,
             *(_DWORD *)result,
             *(_DWORD *)(result + 4));
  return result;
}
