__int64 __fastcall cam_cpas_dump_full_tree_state(__int64 result, const char *a2)
{
  __int64 v3; // x25
  __int64 i; // x26
  int *v5; // x28
  int *v6; // x11
  int v7; // w8
  int v8; // w9
  int v9; // w10
  _QWORD *v10; // x8
  _QWORD *v11; // x8
  _QWORD *v12; // x8

  if ( (cpas_dump & 2) != 0 )
  {
    v3 = *(_QWORD *)(result + 3392);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      3,
      "cam_cpas_dump_full_tree_state",
      108,
      "Dumping cpas tree full state start ============== %s",
      a2);
    for ( i = 0; i != 504; i += 8 )
    {
      v5 = *(int **)(v3 + 360 + i);
      if ( v5 )
      {
        v6 = *((int **)v5 + 1);
        v7 = *v5;
        v8 = v5[1];
        v9 = *v6;
        if ( *(_BYTE *)(v3 + 1609) == 1 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000000,
            3,
            "cam_cpas_dump_full_tree_state",
            131,
            "Identifier[%s] node:[%s] cell:%d lvl:%d PortIdx mnoc[%d %d %d %d] camnoc[%d] camnoc_max %d, bus_width:%d, drv_idx:%d",
            a2,
            *((const char **)v5 + 3),
            v7,
            v8,
            v9,
            v6[1],
            v6[2],
            v6[3],
            v5[5],
            *((unsigned __int8 *)v5 + 57),
            v5[11],
            v5[4]);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000000,
            3,
            "cam_cpas_dump_full_tree_state",
            140,
            "    idx[%d] HLOS camnoc[%llu], DDR ab[%llu] ib[%llu]",
            0,
            *(_QWORD *)(*((_QWORD *)v5 + 6) + 24LL),
            *(_QWORD *)(*((_QWORD *)v5 + 6) + 8LL),
            *(_QWORD *)(*((_QWORD *)v5 + 6) + 16LL));
          v10 = *((_QWORD **)v5 + 6);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000000,
            3,
            "cam_cpas_dump_full_tree_state",
            150,
            "    idx[%d] DRV camnoc[%llu %llu], DDR ab[%llu %llu] ib[%llu %llu]",
            1,
            v10[10],
            v10[13],
            v10[8],
            v10[11],
            v10[9],
            v10[12]);
          v11 = *((_QWORD **)v5 + 6);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000000,
            3,
            "cam_cpas_dump_full_tree_state",
            150,
            "    idx[%d] DRV camnoc[%llu %llu], DDR ab[%llu %llu] ib[%llu %llu]",
            2,
            v11[17],
            v11[20],
            v11[15],
            v11[18],
            v11[16],
            v11[19]);
          v12 = *((_QWORD **)v5 + 6);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000000,
            3,
            "cam_cpas_dump_full_tree_state",
            150,
            "    idx[%d] DRV camnoc[%llu %llu], DDR ab[%llu %llu] ib[%llu %llu]",
            3,
            v12[24],
            v12[27],
            v12[22],
            v12[25],
            v12[23],
            v12[26]);
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            3,
            "cam_cpas_dump_full_tree_state",
            165,
            "[%s] Cell[%d] level[%d] PortIdx[%d][%d] camnoc_bw[%d %d %lld %lld] mnoc_bw[%lld %lld]",
            *((const char **)v5 + 3),
            v7,
            v8,
            v9,
            v5[5],
            *((unsigned __int8 *)v5 + 57),
            v5[11],
            *(_QWORD *)(*((_QWORD *)v5 + 6) + 24LL),
            *(_QWORD *)(*((_QWORD *)v5 + 6) + 24LL) * (unsigned int)v5[11],
            *(_QWORD *)(*((_QWORD *)v5 + 6) + 8LL),
            *(_QWORD *)(*((_QWORD *)v5 + 6) + 16LL));
        }
      }
    }
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             4,
             3,
             "cam_cpas_dump_full_tree_state",
             169,
             "Dumping cpas tree full state end ============== %s",
             a2);
  }
  return result;
}
