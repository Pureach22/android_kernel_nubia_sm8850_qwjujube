__int64 __fastcall cam_ife_csid_ver2_set_cesta_clk_rate(_QWORD *a1, char a2, const char *a3)
{
  __int64 v3; // x22
  __int64 v6; // x21
  unsigned __int64 v7; // x2
  __int64 v8; // x8
  __int64 v9; // x23
  int v10; // w0
  __int64 v11; // x8
  unsigned int v12; // w21
  char v13; // w23

  v3 = a1[3891];
  v6 = *(unsigned int *)(v3 + 2968);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v13 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_set_cesta_clk_rate",
      6551,
      "CSID:%d clk_rate=%llu, channel_switch=%d, identifier=%s",
      *(_DWORD *)(a1[3890] + 4LL),
      a1[4023],
      a2 & 1,
      a3);
    a2 = v13;
    v7 = a1[4023];
    if ( v7 )
      goto LABEL_4;
LABEL_10:
    if ( (a2 & 1) == 0 )
      return 0;
    goto LABEL_11;
  }
  v7 = a1[4023];
  if ( !v7 )
    goto LABEL_10;
LABEL_4:
  if ( (unsigned int)v6 >= 0xA )
    goto LABEL_15;
  v8 = *(unsigned int *)(v3 + 2892);
  if ( (unsigned int)v8 > 0x1F )
    goto LABEL_15;
  v9 = v3 + 1480 + (v6 << 7);
  v10 = cam_soc_util_set_src_clk_rate(v3 + 96, *(_DWORD *)(a1[3890] + 4LL), v7, *(int *)(v9 + 4 * v8));
  if ( !v10 )
  {
LABEL_11:
    v12 = cam_soc_util_cesta_channel_switch(*(_DWORD *)(a1[3890] + 4LL), a3);
    if ( v12 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_ife_csid_ver2_set_cesta_clk_rate",
        6573,
        "Failed to apply power states for cesta client:%d rc:%d",
        *(_DWORD *)(a1[3890] + 4LL),
        v12);
    return v12;
  }
  v11 = *(unsigned int *)(v3 + 2892);
  if ( (unsigned int)v11 <= 0x1F )
  {
    v12 = v10;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_set_cesta_clk_rate",
      6562,
      "Failed in setting cesta clk rates[high low]:[%ld %ld] client_idx:%d rc:%d",
      a1[4023],
      *(unsigned int *)(v9 + 4 * v11),
      *(_DWORD *)(a1[3890] + 4LL),
      v10);
    return v12;
  }
LABEL_15:
  __break(0x5512u);
  return cam_ife_csid_ver2_send_secure_info();
}
