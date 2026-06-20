void *__fastcall cam_vfe_top_ver4_print_diag_sensor_frame_count_info(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        int a4,
        char a5)
{
  void *result; // x0
  __int64 v10; // x27
  __int64 v11; // x8
  __int64 v12; // x19
  __int64 v13; // x24
  __int64 v14; // x20
  __int64 v15; // x22
  int v16; // w19
  __int64 v17; // x8
  __int64 v18; // x8
  unsigned int v19; // w9
  _BOOL4 v20; // w10
  _BOOL4 v21; // w9
  _BOOL4 v22; // w8
  __int64 v23; // x21
  __int64 v24; // x8
  unsigned int v25; // w0
  __int64 v26; // x8
  unsigned int v27; // w26
  unsigned int v28; // w28
  __int64 v29; // x8
  char v30; // w10
  __int64 v31; // x8
  unsigned int v32; // w0
  __int64 v33; // x8
  unsigned int v34; // w20
  unsigned int v35; // w19
  __int64 v36; // x8
  char v37; // w10
  __int64 v38; // x8
  __int64 v39; // x8
  unsigned int v40; // w0
  __int64 v41; // x8
  unsigned int v42; // w20
  unsigned int v43; // w19
  __int64 v44; // x8
  char v45; // w10
  __int64 v46; // x8
  __int64 v47; // x8
  unsigned int v48; // w0
  __int64 v49; // x8
  unsigned int v50; // w20
  unsigned int v51; // w19
  __int64 v52; // x8
  char v53; // w10
  char v54; // [xsp+0h] [xbp-450h]
  char v55; // [xsp+0h] [xbp-450h]
  char v56; // [xsp+0h] [xbp-450h]
  int v57; // [xsp+18h] [xbp-438h]
  __int64 v59; // [xsp+30h] [xbp-420h]
  unsigned __int64 v60; // [xsp+38h] [xbp-418h] BYREF
  char s[1024]; // [xsp+40h] [xbp-410h] BYREF
  __int64 v62; // [xsp+440h] [xbp-10h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = memset(s, 0, sizeof(s));
  v10 = *(_QWORD *)(a1 + 72);
  v11 = *(_QWORD *)(v10 + 16);
  v12 = *(_QWORD *)(*(_QWORD *)(v10 + 10432) + 288LL);
  v13 = *(_QWORD *)(v11 + 256);
  v59 = *(_QWORD *)(v10 + 10432);
  v60 = 0;
  if ( (a5 & 1) != 0 )
  {
    v14 = 32LL * a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_print_diag_sensor_frame_count_info",
      819,
      "VFE[%u] %s occurred at [%llu: %09llu]",
      *(_DWORD *)(v59 + 20),
      *(const char **)(*(_QWORD *)(v11 + 176) + v14 + 8),
      *(_QWORD *)(a2 + 40),
      *(_QWORD *)(a2 + 48));
    result = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       8,
                       1,
                       "cam_vfe_top_ver4_print_diag_sensor_frame_count_info",
                       820,
                       "%s",
                       *(const char **)(*(_QWORD *)(*(_QWORD *)(v10 + 16) + 176LL) + v14 + 16));
  }
  if ( (*(_BYTE *)(v10 + 10928) & 1) != 0 )
  {
    v15 = v12 + v13;
    result = (void *)cam_io_r_mb(v12 + v13 + *(unsigned int *)(*(_QWORD *)(v10 + 8) + 132LL));
    v16 = (int)result;
    v17 = *(unsigned int *)(*(_QWORD *)(v10 + 8) + 136LL);
    if ( (_DWORD)v17 )
    {
      result = (void *)cam_io_r_mb(v15 + v17);
      v57 = (int)result;
    }
    else
    {
      v57 = 0;
    }
    v18 = *(_QWORD *)(a1 + 64);
    v19 = *(_DWORD *)(v18 + 52) & v16;
    v20 = v19 != 0;
    v21 = v19 < 4;
    if ( *(_BYTE *)(v18 + 64) )
      v22 = v21;
    else
      v22 = v20;
    if ( v22 )
    {
      v23 = 0;
      do
      {
        v24 = *(unsigned int *)(*(_QWORD *)(v10 + 8) + 4 * v23 + 140);
        if ( !(_DWORD)v24 )
          break;
        v25 = cam_io_r_mb(v15 + v24);
        v26 = *(_QWORD *)(*(_QWORD *)(v10 + 16) + 224LL);
        if ( *(_DWORD *)(v26 + 16 * v23) )
        {
          v27 = v25;
          v28 = 0;
          do
          {
            v29 = *(_QWORD *)(v26 + 16 * v23 + 8) + 16LL * (int)v28;
            v30 = __clz(__rbit32(*(_DWORD *)v29));
            if ( !*(_DWORD *)v29 )
              v30 = -1;
            cam_print_to_buffer(
              (__int64)s,
              0x400u,
              &v60,
              3u,
              8u,
              "%s: 0x%x, ",
              *(_QWORD *)(v29 + 8),
              (*(_DWORD *)v29 & v27) >> v30,
              v54);
            ++v28;
            v26 = *(_QWORD *)(*(_QWORD *)(v10 + 16) + 224LL);
          }
          while ( v28 < *(_DWORD *)(v26 + 16 * v23) );
        }
        result = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                           3,
                           8,
                           3,
                           "cam_vfe_top_ver4_print_diag_sensor_frame_count_info",
                           848,
                           "VFE[%u] res_id: %d diag_sensor_status_%d: %s",
                           *(_DWORD *)(v59 + 20),
                           a4,
                           v23++,
                           s);
        v60 = 0;
      }
      while ( v23 != 4 );
    }
    if ( v16 && *(_DWORD *)(*(_QWORD *)(a1 + 64) + 56LL) || v57 && (*(_DWORD *)(*(_QWORD *)(a1 + 64) + 60LL) & v57) != 0 )
    {
      v31 = *(unsigned int *)(*(_QWORD *)(v10 + 8) + 156LL);
      if ( (_DWORD)v31 )
      {
        v32 = cam_io_r_mb(v15 + v31);
        v33 = *(_QWORD *)(*(_QWORD *)(v10 + 16) + 232LL);
        if ( *(_DWORD *)v33 )
        {
          v34 = v32;
          v35 = 0;
          do
          {
            v36 = *(_QWORD *)(v33 + 8) + 16LL * (int)v35;
            v37 = __clz(__rbit32(*(_DWORD *)v36));
            if ( !*(_DWORD *)v36 )
              v37 = -1;
            cam_print_to_buffer(
              (__int64)s,
              0x400u,
              &v60,
              3u,
              8u,
              "%s: 0x%x, ",
              *(_QWORD *)(v36 + 8),
              (*(_DWORD *)v36 & v34) >> v37,
              v54);
            ++v35;
            v33 = *(_QWORD *)(*(_QWORD *)(v10 + 16) + 232LL);
          }
          while ( v35 < *(_DWORD *)v33 );
        }
        result = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                           3,
                           8,
                           3,
                           "cam_vfe_top_ver4_print_diag_sensor_frame_count_info",
                           873,
                           "VFE[%u] res_id: %d diag_frame_count_status_%d: %s",
                           *(_DWORD *)(v59 + 20),
                           a4,
                           0,
                           s);
        v38 = *(_QWORD *)(v10 + 8);
        v60 = 0;
        v39 = *(unsigned int *)(v38 + 160);
        if ( (_DWORD)v39 )
        {
          v40 = cam_io_r_mb(v15 + v39);
          v41 = *(_QWORD *)(*(_QWORD *)(v10 + 16) + 232LL);
          if ( *(_DWORD *)(v41 + 16) )
          {
            v42 = v40;
            v43 = 0;
            do
            {
              v44 = *(_QWORD *)(v41 + 24) + 16LL * (int)v43;
              v45 = __clz(__rbit32(*(_DWORD *)v44));
              if ( !*(_DWORD *)v44 )
                v45 = -1;
              cam_print_to_buffer(
                (__int64)s,
                0x400u,
                &v60,
                3u,
                8u,
                "%s: 0x%x, ",
                *(_QWORD *)(v44 + 8),
                (*(_DWORD *)v44 & v42) >> v45,
                v55);
              ++v43;
              v41 = *(_QWORD *)(*(_QWORD *)(v10 + 16) + 232LL);
            }
            while ( v43 < *(_DWORD *)(v41 + 16) );
          }
          result = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                             3,
                             8,
                             3,
                             "cam_vfe_top_ver4_print_diag_sensor_frame_count_info",
                             873,
                             "VFE[%u] res_id: %d diag_frame_count_status_%d: %s",
                             *(_DWORD *)(v59 + 20),
                             a4,
                             1,
                             s);
          v46 = *(_QWORD *)(v10 + 8);
          v60 = 0;
          v47 = *(unsigned int *)(v46 + 164);
          if ( (_DWORD)v47 )
          {
            v48 = cam_io_r_mb(v15 + v47);
            v49 = *(_QWORD *)(*(_QWORD *)(v10 + 16) + 232LL);
            if ( *(_DWORD *)(v49 + 32) )
            {
              v50 = v48;
              v51 = 0;
              do
              {
                v52 = *(_QWORD *)(v49 + 40) + 16LL * (int)v51;
                v53 = __clz(__rbit32(*(_DWORD *)v52));
                if ( !*(_DWORD *)v52 )
                  v53 = -1;
                cam_print_to_buffer(
                  (__int64)s,
                  0x400u,
                  &v60,
                  3u,
                  8u,
                  "%s: 0x%x, ",
                  *(_QWORD *)(v52 + 8),
                  (*(_DWORD *)v52 & v50) >> v53,
                  v56);
                ++v51;
                v49 = *(_QWORD *)(*(_QWORD *)(v10 + 16) + 232LL);
              }
              while ( v51 < *(_DWORD *)(v49 + 32) );
            }
            result = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                               3,
                               8,
                               3,
                               "cam_vfe_top_ver4_print_diag_sensor_frame_count_info",
                               873,
                               "VFE[%u] res_id: %d diag_frame_count_status_%d: %s",
                               *(_DWORD *)(v59 + 20),
                               a4,
                               2,
                               s);
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
