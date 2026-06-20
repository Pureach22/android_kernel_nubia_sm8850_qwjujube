void *__fastcall cam_ife_csid_ver2_read_debug_err_vectors(__int64 a1)
{
  void *result; // x0
  __int64 *v3; // x8
  __int64 v4; // x26
  __int64 v5; // x25
  int v6; // w27
  int v7; // w28
  int v8; // w19
  __int64 v9; // x8
  __int64 v10; // x20
  __int64 v11; // x21
  unsigned int v12; // w23
  unsigned __int64 v13; // x23
  __int64 v14; // x8
  __int64 v15; // x7
  int v16; // w24
  unsigned int v17; // w21
  unsigned __int64 v18; // x20
  bool v19; // cc
  __int64 v20; // x8
  __int64 v21; // x7
  int v22; // w24
  unsigned int v23; // w21
  unsigned __int64 v24; // x20
  __int64 v25; // x8
  int v26; // w0
  __int64 v27; // x7
  unsigned int v28; // w21
  unsigned __int64 v29; // x20
  char v30; // [xsp+0h] [xbp-430h]
  int v31; // [xsp+14h] [xbp-41Ch]
  unsigned __int64 v32; // [xsp+18h] [xbp-418h] BYREF
  char s[1024]; // [xsp+20h] [xbp-410h] BYREF
  __int64 v34; // [xsp+420h] [xbp-10h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = memset(s, 0, sizeof(s));
  v3 = *(__int64 **)(a1 + 31136);
  v32 = 0;
  v4 = *v3;
  if ( (*(_BYTE *)(*(_QWORD *)(*v3 + 120) + 829LL) & 1) != 0 )
  {
    v5 = *(_QWORD *)(a1 + 31128);
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v31 = 0;
    while ( 1 )
    {
      cam_io_w_mb((unsigned int)(2 * v8), *(_QWORD *)(v5 + 384) + *(unsigned int *)(*(_QWORD *)(v4 + 120) + 152LL));
      v9 = *(_QWORD *)(v4 + 120);
      v10 = *(_QWORD *)(v5 + 384);
      v11 = *(unsigned int *)(v9 + 156);
      v12 = cam_io_r_mb(v10 + *(unsigned int *)(v9 + 160));
      result = (void *)cam_io_r_mb(v10 + v11);
      v13 = (((((10000 * (unsigned __int64)(unsigned int)result) >> 32) + 10000LL * v12) / 0xC0) << 32)
          | (unsigned int)((unsigned __int64)((((10000LL * (unsigned int)result) & 0xFFFFFFC0LL
                                              | (((((10000 * (unsigned __int64)(unsigned int)result) >> 32)
                                                 + 10000LL * v12)
                                                % 0xC0) << 32))
                                             * (unsigned __int128)0x2AAAAAAAAAAAAAABuLL) >> 64) >> 5);
      if ( !v13 )
        break;
      v14 = *(unsigned int *)(*(_QWORD *)(v4 + 120) + 140LL);
      if ( (_DWORD)v14 )
      {
        v16 = cam_io_r_mb(*(_QWORD *)(v5 + 384) + v14);
        v17 = v6 ^ v16;
        if ( v6 != v16 )
        {
          v18 = 0;
          do
          {
            if ( (v17 & 1) != 0 )
            {
              if ( v18 > 0x1F )
LABEL_34:
                __break(0x5512u);
              cam_print_to_buffer(
                (__int64)s,
                0x400u,
                &v32,
                3u,
                8u,
                "%s ",
                *(_QWORD *)(*(_QWORD *)(v4 + 576) + 8 * v18),
                v15,
                v30);
            }
            v19 = v17 > 1;
            ++v18;
            v17 >>= 1;
          }
          while ( v19 );
        }
        v6 |= v16;
        v20 = *(unsigned int *)(*(_QWORD *)(v4 + 120) + 144LL);
        if ( (_DWORD)v20 )
        {
          v22 = cam_io_r_mb(*(_QWORD *)(v5 + 384) + v20);
          v23 = v7 ^ v22;
          if ( v7 != v22 )
          {
            v24 = 0;
            do
            {
              if ( (v23 & 1) != 0 )
              {
                if ( v24 > 0x1F )
                  goto LABEL_34;
                cam_print_to_buffer(
                  (__int64)s,
                  0x400u,
                  &v32,
                  3u,
                  8u,
                  "%s ",
                  *(_QWORD *)(*(_QWORD *)(v4 + 576) + 8 * v24 + 256),
                  v21,
                  v30);
              }
              v19 = v23 > 1;
              ++v24;
              v23 >>= 1;
            }
            while ( v19 );
          }
          v7 |= v22;
          v25 = *(unsigned int *)(*(_QWORD *)(v4 + 120) + 148LL);
          if ( (_DWORD)v25 )
          {
            v26 = cam_io_r_mb(*(_QWORD *)(v5 + 384) + v25);
            v28 = v31 ^ v26;
            v31 |= v26;
            if ( v28 )
            {
              v29 = 0;
              do
              {
                if ( (v28 & 1) != 0 )
                {
                  if ( v29 > 0x1F )
                    goto LABEL_34;
                  cam_print_to_buffer(
                    (__int64)s,
                    0x400u,
                    &v32,
                    3u,
                    8u,
                    "%s ",
                    *(_QWORD *)(*(_QWORD *)(v4 + 576) + 8 * v29 + 512),
                    v27,
                    v30);
                }
                v19 = v28 > 1;
                ++v29;
                v28 >>= 1;
              }
              while ( v19 );
            }
          }
        }
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_ife_csid_ver2_read_debug_err_vectors",
        2008,
        "Error(s) that occurred in time order %d at timestamp %llu: %s",
        v8,
        v13,
        s);
      memset(s, 0, sizeof(s));
      if ( ++v8 == 4 )
      {
        result = (void *)cam_io_w_mb(1, *(_QWORD *)(v5 + 384) + *(unsigned int *)(*(_QWORD *)(v4 + 120) + 152LL));
        goto LABEL_33;
      }
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      result = (void *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                         3,
                         debug_mdl & 8,
                         4,
                         "cam_ife_csid_ver2_read_debug_err_vectors",
                         1984,
                         "Debug IRQ vectors already read, skip");
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
