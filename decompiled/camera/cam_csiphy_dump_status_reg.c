__int64 __fastcall cam_csiphy_dump_status_reg(__int64 a1)
{
  unsigned int v1; // w6
  char *v3; // x8
  __int64 v4; // x24
  __int64 *v5; // x9
  __int64 v6; // x21
  unsigned int *v7; // x23
  __int64 v8; // x28
  unsigned __int64 v9; // x20
  __int64 v10; // x22
  int v11; // w24
  int v12; // w25
  int v13; // w26
  int v14; // w0
  const char *v15; // x5
  __int64 v16; // x4
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x20
  __int64 v20; // x21
  __int64 v21; // x22
  int v22; // w24
  int v23; // w25
  int v24; // w26
  int v25; // w27
  int v26; // w28
  int v27; // w0
  __int64 v28; // [xsp+28h] [xbp-18h]
  __int64 v29; // [xsp+30h] [xbp-10h]
  unsigned __int64 v30; // [xsp+38h] [xbp-8h]

  if ( !a1 )
  {
    v15 = "Null csiphy_dev";
    v16 = 666;
LABEL_13:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_dump_status_reg",
      v16,
      v15);
    return 4294967274LL;
  }
  v1 = *(_DWORD *)(a1 + 932);
  if ( v1 >= 8 )
  {
    __break(0x5512u);
    return cam_csiphy_reset(a1);
  }
  v3 = (char *)&g_phy_data + 56 * v1;
  v4 = *(_QWORD *)v3;
  if ( !*(_QWORD *)v3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_dump_status_reg",
      677,
      "Invalid cphy_idx: %d",
      v1);
    return 4294967274LL;
  }
  v5 = *(__int64 **)(a1 + 112);
  v6 = *v5;
  v7 = *(unsigned int **)(*v5 + 16);
  if ( !v7 )
  {
    v15 = "2ph/3ph status offset not set";
    v16 = 686;
    goto LABEL_13;
  }
  if ( v3[8] )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      3,
      "cam_csiphy_dump_status_reg",
      691,
      "Dumping 3ph status regs");
    if ( *((_WORD *)v7 + 12) )
    {
      v8 = *(unsigned int *)(v6 + 24);
      v9 = 0;
      v10 = v4 + *v7;
      do
      {
        v11 = *(_DWORD *)(a1 + 932);
        v12 = cam_io_r(v10);
        v13 = cam_io_r(v10 + v8);
        v14 = cam_io_r(v10 + 2 * v8);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          3,
          "cam_csiphy_dump_status_reg",
          704,
          "PHY: %d, Status%u. Ln0: 0x%x, Ln1: 0x%x, Ln2: 0x%x",
          v11,
          v9++,
          v12,
          v13,
          v14);
        v10 += 4;
      }
      while ( v9 < *((unsigned __int16 *)v7 + 12) );
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      3,
      "cam_csiphy_dump_status_reg",
      707,
      "Dumping 2ph status regs");
    if ( *((_WORD *)v7 + 13) )
    {
      v18 = *(unsigned int *)(v6 + 24);
      v19 = 0;
      v20 = v4 + v7[1];
      v29 = 2 * v18;
      v30 = v18;
      v21 = 3 * v18;
      v28 = (v18 >> 1) + 3 * v18;
      do
      {
        v22 = *(_DWORD *)(a1 + 932);
        v23 = cam_io_r(v20 + v28);
        v24 = cam_io_r(v20);
        v25 = cam_io_r(v20 + v30);
        v26 = cam_io_r(v20 + v29);
        v27 = cam_io_r(v20 + v21);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          3,
          "cam_csiphy_dump_status_reg",
          727,
          "PHY: %d, Status%u. CLK_LN: 0x%x Ln0: 0x%x, Ln1: 0x%x, Ln2: 0x%x, Ln3: 0x%x",
          v22,
          v19++,
          v23,
          v24,
          v25,
          v26,
          v27);
        v20 += 4;
      }
      while ( v19 < *((unsigned __int16 *)v7 + 13) );
    }
  }
  return 0;
}
