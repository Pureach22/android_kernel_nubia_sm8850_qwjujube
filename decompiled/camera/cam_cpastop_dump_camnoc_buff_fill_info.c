__int64 __fastcall cam_cpastop_dump_camnoc_buff_fill_info(__int64 a1)
{
  _QWORD *v2; // x21
  __int64 result; // x0
  __int64 v4; // x25
  __int64 v5; // x8
  __int64 v6; // x27
  __int64 v7; // x9
  int v8; // w8
  __int64 v9; // x20
  unsigned __int64 v10; // x21
  __int64 v11; // x22
  unsigned int v12; // w26
  _QWORD *v13; // x28
  __int64 v14; // x9
  __int64 v15; // [xsp+8h] [xbp-228h]
  char *v16; // [xsp+10h] [xbp-220h]
  _QWORD *v17; // [xsp+18h] [xbp-218h]
  char s[512]; // [xsp+20h] [xbp-210h] BYREF
  __int64 v19; // [xsp+220h] [xbp-10h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 3680);
  result = (__int64)memset(s, 0, sizeof(s));
  v4 = 0;
  v16 = (char *)v2 + 2812;
  v17 = v2;
  v15 = a1 + 384;
  while ( 1 )
  {
    v5 = *v17 + 8LL;
    if ( *(_QWORD *)(v5 + 8 * v4) )
      break;
LABEL_3:
    if ( ++v4 == 4 )
      goto LABEL_15;
  }
  s[0] = 0;
  v6 = *(_QWORD *)(v5 + 8 * v4);
  v7 = *(unsigned int *)(v6 + 4);
  if ( (unsigned int)v7 <= 9 )
  {
    v8 = *(_DWORD *)(v6 + 16);
    if ( v8 >= 1 )
    {
      v9 = 0;
      v10 = 0;
      v11 = 352;
      v12 = *(_DWORD *)&v16[4 * v7];
      v13 = (_QWORD *)(v15 + 24LL * v12);
      do
      {
        v14 = *(_QWORD *)(v6 + 8);
        if ( *(_BYTE *)(v14 + v11 - 336) == 1 && *(_BYTE *)(v14 + v11 - 52) == 1 )
        {
          if ( v12 > 7 )
            goto LABEL_14;
          result = cam_io_r_mb(*v13 + *(unsigned int *)(v14 + v11 - 40));
          if ( v10 > 0x200 )
            goto LABEL_14;
          v10 += (int)scnprintf(
                        &s[v10],
                        512 - v10,
                        " %s:[%d %d]",
                        *(const char **)(*(_QWORD *)(v6 + 8) + v11 - 344),
                        result & 0x7FF,
                        WORD1(result) & 0x7F);
          result = cam_io_w_mb(
                     *(unsigned int *)(*(_QWORD *)(v6 + 8) + v11),
                     *v13 + *(unsigned int *)(*(_QWORD *)(v6 + 8) + v11 - 12));
          v8 = *(_DWORD *)(v6 + 16);
        }
        ++v9;
        v11 += 416;
      }
      while ( v9 < v8 );
    }
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               4,
               3,
               "cam_cpastop_dump_camnoc_buff_fill_info",
               1141,
               "%s Fill level [Queued Pending] %s",
               g_camnoc_names[v4],
               s);
    goto LABEL_3;
  }
LABEL_14:
  __break(0x5512u);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
