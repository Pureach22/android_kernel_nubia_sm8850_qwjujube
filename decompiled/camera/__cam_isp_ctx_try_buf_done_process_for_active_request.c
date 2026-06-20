__int64 __fastcall _cam_isp_ctx_try_buf_done_process_for_active_request(__int64 result, _QWORD *a2, __int64 a3)
{
  __int64 v3; // x26
  __int64 v4; // x27
  __int64 v5; // x28
  unsigned int v7; // w21
  unsigned int v8; // w8
  __int64 v9; // x24
  int v11; // w10
  __int64 v12; // x11
  int v13; // w9
  int v14; // w12
  __int64 v15; // x23
  __int64 v16; // x11
  int v17; // w10
  int v18; // w11
  const char *v19; // x7
  int v20; // w0

  v3 = *a2;
  v4 = *(_QWORD *)(*a2 + 128LL);
  if ( v4 != *a2 + 128LL )
  {
    v5 = *(_QWORD *)(a3 + 32);
    v7 = result;
    v8 = *(_DWORD *)(v5 + 56);
    if ( v8 > (unsigned int)result )
    {
      v9 = *(_QWORD *)(v4 + 32);
      do
      {
        v11 = *(_DWORD *)(v9 + 32);
        if ( v11 )
        {
          v12 = *(_QWORD *)(v9 + 24);
          v13 = *(_DWORD *)(*(_QWORD *)(v5 + 24) + ((__int64)*(int *)(*(_QWORD *)(v5 + 64) + 4LL * (int)v7) << 6));
          v14 = 0;
          while ( 1 )
          {
            v15 = v14;
            if ( *(_DWORD *)(v12 + ((__int64)v14 << 6)) == v13 )
              break;
            ++v14;
            if ( v11 == (_DWORD)v15 + 1 )
              goto LABEL_6;
          }
          v16 = v12 + ((__int64)v14 << 6);
          v17 = *(_DWORD *)(v16 + 16);
          if ( v17 != -1 )
          {
            v18 = *(_DWORD *)(v16 + 20);
            if ( *(_BYTE *)(v9 + 4504) )
              v19 = "Y";
            else
              v19 = "N";
            result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       8,
                       2,
                       "__cam_isp_ctx_try_buf_done_process_for_active_request",
                       3175,
                       "Processing delayed buf done req: %llu bubble_detected: %s res: 0x%x fd: 0x%x early_fd: 0x%x, ctx:"
                       " %u link: 0x%x [deferred req: %llu last applied: %llu]",
                       *(_QWORD *)(v4 + 24),
                       v19,
                       v13,
                       v17,
                       v18,
                       *(_DWORD *)(v3 + 32),
                       *(_DWORD *)(v3 + 64),
                       *(_QWORD *)(a3 + 24),
                       a2[4669]);
            if ( (*(_BYTE *)(v9 + 4504) & 1) == 0 )
            {
              v20 = cam_sync_signal(*(_DWORD *)(*(_QWORD *)(v9 + 24) + (v15 << 6) + 16), 2u, 1u);
              if ( v20 )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "__cam_isp_ctx_try_buf_done_process_for_active_request",
                  3187,
                  "Sync: %d for req: %llu failed with rc: %d, ctx: %u link: 0x%x",
                  *(_DWORD *)(*(_QWORD *)(v9 + 24) + (v15 << 6) + 16),
                  *(_QWORD *)(v4 + 24),
                  v20,
                  *(_DWORD *)(v3 + 32),
                  *(_DWORD *)(v3 + 64));
              *(_DWORD *)(*(_QWORD *)(v9 + 24) + (v15 << 6) + 16) = -1;
              result = *(unsigned int *)(*(_QWORD *)(v9 + 24) + (v15 << 6) + 20);
              if ( (int)result >= 1 )
              {
                result = cam_sync_signal(result, 2u, 1u);
                if ( (_DWORD)result )
                  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                             3,
                             8,
                             1,
                             "__cam_isp_ctx_try_buf_done_process_for_active_request",
                             3201,
                             "Early sync=%d for req=%llu failed with rc=%d ctx:%u link[0x%x]",
                             *(_DWORD *)(*(_QWORD *)(v9 + 24) + (v15 << 6) + 20),
                             *(_QWORD *)(v4 + 24),
                             result,
                             *(_DWORD *)(v3 + 32),
                             *(_DWORD *)(v3 + 64));
                *(_DWORD *)(*(_QWORD *)(v9 + 24) + (v15 << 6) + 20) = -1;
              }
            }
            ++*(_DWORD *)(v9 + 52);
            v8 = *(_DWORD *)(v5 + 56);
          }
        }
LABEL_6:
        ++v7;
      }
      while ( v7 < v8 );
    }
  }
  return result;
}
