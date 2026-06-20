__int64 __fastcall cam_cpas_dump_tree_vote_info(__int64 result, __int64 a2, const char *a3, int a4, int a5)
{
  __int64 v5; // x23
  __int64 v6; // x7
  int v8; // w8
  __int64 v9; // x9
  __int64 v13; // x7
  int v14; // w8
  __int64 v15; // x9
  _QWORD *v16; // x8
  _QWORD *v17; // x8
  _QWORD *v18; // x8

  if ( (cpas_dump & 1) != 0 )
  {
    v5 = *(_QWORD *)(result + 3392);
    v6 = *(_QWORD *)(a2 + 24);
    v8 = *(_DWORD *)(a2 + 4);
    v9 = *(_QWORD *)(a2 + 48);
    if ( a5 < 1 )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, __int64, int, int, _QWORD))cam_print_log)(
        3,
        0x2000000,
        3,
        "cam_cpas_dump_tree_vote_info",
        49,
        "%s node:%s lvl:%d cesta_drv_idx:%d HLOS BW camnoc[%llu]",
        a3,
        v6,
        v8,
        a5,
        *(_QWORD *)(v9 + 56LL * a5 + 24));
    else
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, __int64, int, int, _QWORD, _QWORD))cam_print_log)(
        3,
        0x2000000,
        3,
        "cam_cpas_dump_tree_vote_info",
        44,
        "%s node:%s lvl:%d cesta_drv_idx:%d DRV BW camnoc[%llu %llu]",
        a3,
        v6,
        v8,
        a5,
        *(_QWORD *)(v9 + 56LL * (unsigned int)a5 + 24),
        *(_QWORD *)(v9 + 56LL * (unsigned int)a5 + 48));
    v13 = *(_QWORD *)(a2 + 24);
    v14 = *(_DWORD *)(a2 + 4);
    v15 = *(_QWORD *)(a2 + 48);
    if ( a4 < 1 )
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, __int64, int, int, _QWORD, _QWORD))cam_print_log)(
                 3,
                 0x2000000,
                 3,
                 "cam_cpas_dump_tree_vote_info",
                 64,
                 "%s node:%s lvl:%d ddr_drv_idx:%d HLOS BW ab[%llu] ib[%llu]",
                 a3,
                 v13,
                 v14,
                 a4,
                 *(_QWORD *)(v15 + 56LL * a4 + 8),
                 *(_QWORD *)(v15 + 56LL * a4 + 16));
    else
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, __int64, int, int, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
                 3,
                 0x2000000,
                 3,
                 "cam_cpas_dump_tree_vote_info",
                 58,
                 "%s node:%s lvl:%d ddr_drv_idx:%d DRV BW ab[%llu %llu] ib[%llu %llu]",
                 a3,
                 v13,
                 v14,
                 a4,
                 *(_QWORD *)(v15 + 56LL * (unsigned int)a4 + 8),
                 *(_QWORD *)(v15 + 56LL * (unsigned int)a4 + 32),
                 *(_QWORD *)(v15 + 56LL * (unsigned int)a4 + 16),
                 *(_QWORD *)(v15 + 56LL * (unsigned int)a4 + 40));
    if ( *(_BYTE *)(v5 + 1609) == 1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x2000000,
        3,
        "cam_cpas_dump_tree_vote_info",
        72,
        "%s node:%s lvl:%d drv_idx:%d cesta_drv_idx:%d ==== printing full node state",
        a3,
        *(const char **)(a2 + 24),
        *(_DWORD *)(a2 + 4),
        a4,
        a5);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x2000000,
        3,
        "cam_cpas_dump_tree_vote_info",
        82,
        "idx[%d] HLOS camnoc[%llu], DDR ab[%llu] ib[%llu]",
        0,
        *(_QWORD *)(*(_QWORD *)(a2 + 48) + 24LL),
        *(_QWORD *)(*(_QWORD *)(a2 + 48) + 8LL),
        *(_QWORD *)(*(_QWORD *)(a2 + 48) + 16LL));
      v16 = *(_QWORD **)(a2 + 48);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x2000000,
        3,
        "cam_cpas_dump_tree_vote_info",
        92,
        "idx[%d] DRV camnoc[%llu %llu], DDR ab[%llu %llu] ib[%llu %llu]",
        1,
        v16[10],
        v16[13],
        v16[8],
        v16[11],
        v16[9],
        v16[12]);
      v17 = *(_QWORD **)(a2 + 48);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x2000000,
        3,
        "cam_cpas_dump_tree_vote_info",
        92,
        "idx[%d] DRV camnoc[%llu %llu], DDR ab[%llu %llu] ib[%llu %llu]",
        2,
        v17[17],
        v17[20],
        v17[15],
        v17[18],
        v17[16],
        v17[19]);
      v18 = *(_QWORD **)(a2 + 48);
      return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               0x2000000,
               3,
               "cam_cpas_dump_tree_vote_info",
               92,
               "idx[%d] DRV camnoc[%llu %llu], DDR ab[%llu %llu] ib[%llu %llu]",
               3,
               v18[24],
               v18[27],
               v18[22],
               v18[25],
               v18[23],
               v18[26]);
    }
  }
  return result;
}
