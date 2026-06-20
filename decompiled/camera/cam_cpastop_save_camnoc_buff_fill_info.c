__int64 __fastcall cam_cpastop_save_camnoc_buff_fill_info(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x22
  __int64 v4; // x27
  int v5; // w21
  __int64 v6; // x20
  __int64 v7; // x9
  int v8; // w8
  __int64 v9; // x25
  __int64 v10; // x23
  unsigned int v11; // w26
  _QWORD *v12; // x28
  __int64 v13; // x9
  __int64 v14; // [xsp+10h] [xbp-20h]
  __int64 v15; // [xsp+18h] [xbp-18h]
  __int64 v16; // [xsp+20h] [xbp-10h]
  _QWORD *v17; // [xsp+28h] [xbp-8h]

  v14 = result + 384;
  v15 = a2 + 1064;
  v3 = 0;
  v4 = a2 + 1256;
  v16 = a2 + 1048;
  v17 = *(_QWORD **)(result + 3680);
  while ( 2 )
  {
    v6 = *(_QWORD *)(*v17 + 8 * v3 + 8);
    if ( !v6 )
      goto LABEL_4;
    v7 = *(unsigned int *)(v6 + 4);
    if ( (unsigned int)v7 > 9 )
    {
LABEL_18:
      __break(0x5512u);
      return cam_cpastop_reset_irq(result, a2, a3);
    }
    v8 = *(_DWORD *)(v6 + 16);
    if ( v8 < 1 )
    {
      v5 = 0;
      goto LABEL_3;
    }
    v9 = 0;
    v5 = 0;
    v10 = 352;
    v11 = *((_DWORD *)v17 + v7 + 703);
    v12 = (_QWORD *)(v14 + 24LL * v11);
    while ( 1 )
    {
      v13 = *(_QWORD *)(v6 + 8);
      if ( *(_BYTE *)(v13 + v10 - 336) != 1 || *(_BYTE *)(v13 + v10 - 52) != 1 )
        goto LABEL_9;
      if ( v5 >= 6 )
        break;
      if ( (unsigned int)v5 > 5 )
        goto LABEL_18;
      *(_QWORD *)(v15 + 48 * v3 + 8LL * v5) = *(_QWORD *)(v13 + v10 - 344);
      if ( v11 > 7 )
        goto LABEL_18;
      *(_DWORD *)(v4 + 24 * v3 + 4LL * v5) = cam_io_r_mb(*v12 + *(unsigned int *)(*(_QWORD *)(v6 + 8) + v10 - 40));
      result = cam_io_w_mb(
                 *(unsigned int *)(*(_QWORD *)(v6 + 8) + v10),
                 *v12 + *(unsigned int *)(*(_QWORD *)(v6 + 8) + v10 - 12));
      v8 = *(_DWORD *)(v6 + 16);
      ++v5;
LABEL_9:
      ++v9;
      v10 += 416;
      if ( v9 >= v8 )
        goto LABEL_3;
    }
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               4,
               2,
               "cam_cpastop_save_camnoc_buff_fill_info",
               1169,
               "CPAS monitor reg info buffer full, max : %d",
               v5);
LABEL_3:
    *(_DWORD *)(v16 + 4 * v3) = v5;
LABEL_4:
    if ( ++v3 != 4 )
      continue;
    return result;
  }
}
