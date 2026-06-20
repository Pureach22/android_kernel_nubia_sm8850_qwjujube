__int64 __fastcall cam_packet_util_dump_io_bufs(__int64 result, __int64 a2, __int64 a3, __int64 *a4, char a5)
{
  unsigned int v5; // w8
  int v6; // w23
  int v8; // w9
  int v9; // w27
  unsigned __int64 v10; // x10
  unsigned __int64 v11; // x12
  int v12; // w13
  _DWORD *v13; // x20
  __int64 v14; // x8
  __int64 v15; // x28
  int *v16; // x19
  _DWORD *v17; // x26
  int v18; // w0
  int v19; // w6
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x9
  unsigned __int64 v23; // [xsp+40h] [xbp-40h]
  unsigned __int64 v24; // [xsp+48h] [xbp-38h]
  char v25; // [xsp+54h] [xbp-2Ch]
  int v26; // [xsp+58h] [xbp-28h]
  __int64 v27; // [xsp+60h] [xbp-20h]

  _ReadStatusReg(SP_EL0);
  if ( result )
  {
    v5 = *(_DWORD *)(result + 36);
    v6 = *((_DWORD *)a4 + 3);
    if ( v5 )
    {
      v8 = 0;
      v9 = *(_DWORD *)(*a4 + 40);
      v27 = result;
      v10 = result + 4 * ((unsigned __int64)*(unsigned int *)(result + 32) >> 2);
      v25 = a5;
      v11 = v10 + 56;
      v24 = v10 + 88;
      v23 = v10 + 56;
      do
      {
        v12 = v8;
        v13 = (_DWORD *)(v11 + ((__int64)v8 << 8));
        if ( (a5 & 1) == 0 || v13[47] == *((_DWORD *)a4 + 3) )
        {
          v14 = (__int64)v8 << 8;
          v15 = 0;
          v26 = v8;
          v16 = (int *)(v11 + v14);
          v17 = (_DWORD *)(v24 + v14);
          do
          {
            if ( !*v16 )
              break;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              3,
              "cam_packet_util_dump_io_bufs",
              606,
              "port: 0x%x f: %u format: %d dir %d",
              v13[47],
              v13[48],
              v13[42],
              v13[56]);
            v18 = ((__int64 (*)(void))cam_mem_get_io_buf)();
            v19 = *v16;
            if ( v18 < 0 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x20000,
                1,
                "cam_packet_util_dump_io_bufs",
                616,
                "get src buf address fail mem_handle 0x%x",
                v19);
            }
            else
            {
              if ( v9 == v19 >> 16 )
              {
                *((_DWORD *)a4 + 2) = 1;
                *((_DWORD *)a4 + 4) = *v16;
                *((_DWORD *)a4 + 5) = v16[3];
                v20 = *a4;
                v6 = v13[47];
                *((_DWORD *)a4 + 3) = v6;
                v21 = *(_QWORD *)(v20 + 16);
                if ( !v21 )
                  v21 = 0;
                a4[3] = v21;
                v22 = *(_QWORD *)(v27 + 8);
                *((_BYTE *)a4 + 48) = 1;
                a4[5] = v22;
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int, _DWORD, __int64))cam_print_log)(
                  3,
                  0x20000,
                  3,
                  "cam_packet_util_dump_io_bufs",
                  636,
                  "Found PF at port: 0x%x mem 0x%x fd: %d plane id: %d delta: %llu",
                  (unsigned int)v13[47],
                  (unsigned int)*v16,
                  v9,
                  v15,
                  v21);
                v19 = *v16;
              }
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x20000,
                3,
                "cam_packet_util_dump_io_bufs",
                646,
                "pln %d w %d h %d s %u size %zu addr 0x%llx end_addr 0x%llx offset %u memh 0x%x",
                v15,
                *(v17 - 2),
                *(v17 - 1),
                *v17,
                0,
                0,
                0,
                v16[3],
                v19);
            }
            ++v15;
            ++v16;
            v17 += 12;
          }
          while ( v15 != 3 );
          result = v27;
          a5 = v25;
          if ( (v25 & 1) != 0 )
            goto LABEL_22;
          v5 = *(_DWORD *)(v27 + 36);
          v11 = v23;
          v12 = v26;
        }
        v8 = v12 + 1;
      }
      while ( v12 + 1 < v5 );
    }
    if ( (a5 & 1) != 0 )
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 0x20000,
                 1,
                 "cam_packet_util_dump_io_bufs",
                 656,
                 "getting io port for mid resource id failed req id: %llu res id: 0x%x",
                 *(_QWORD *)(result + 8),
                 v6);
  }
  else
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               0x20000,
               1,
               "cam_packet_util_dump_io_bufs",
               582,
               "Invalid packet");
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
