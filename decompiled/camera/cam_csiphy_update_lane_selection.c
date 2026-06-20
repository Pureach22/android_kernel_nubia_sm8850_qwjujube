__int64 __fastcall cam_csiphy_update_lane_selection(__int64 a1, unsigned int a2, char a3)
{
  __int64 v3; // x24
  int *v7; // x8
  __int64 v8; // x20
  __int64 v9; // x19
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  int v13; // w9
  int v14; // w10
  unsigned int v15; // w8
  unsigned int v16; // w22
  int v17; // w9
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 1200);
  v7 = *(int **)(*(_QWORD *)(a1 + 112) + 40LL);
  v8 = *v7;
  v9 = v7[2];
  v10 = cam_io_r(v3 + v8);
  if ( (a3 & 1) != 0 )
  {
    if ( a2 <= 2 )
    {
      v13 = *(_DWORD *)(a1 + 104LL * a2 + 604);
      v14 = *(_DWORD *)(a1 + 92) | v13;
      v15 = a2;
      v16 = v13 | v10;
      goto LABEL_6;
    }
LABEL_9:
    __break(0x5512u);
    return cam_csiphy_get_settle_count(v10, v11, v12);
  }
  if ( a2 > 2 )
    goto LABEL_9;
  v17 = *(_DWORD *)(a1 + 104LL * a2 + 604);
  v14 = *(_DWORD *)(a1 + 92) ^ v17;
  v15 = a2;
  v16 = v10 & ~v17;
LABEL_6:
  *(_DWORD *)(a1 + 92) = v14;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x8000,
    3,
    "cam_csiphy_update_lane_selection",
    2034,
    "lane_reg_addr: 0x%x, lane_assign: 0x%x, lane_enable: 0x%x, delay: %d",
    v8,
    *(unsigned __int16 *)(a1 + 104LL * v15 + 600),
    v16,
    v9);
  result = cam_io_w_mb(v16, v3 + v8);
  if ( (_DWORD)v9 )
    return usleep_range_state(v9, (int)v9 + 5, 2);
  return result;
}
