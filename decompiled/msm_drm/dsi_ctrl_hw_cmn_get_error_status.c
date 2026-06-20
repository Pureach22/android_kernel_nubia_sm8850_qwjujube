__int64 __fastcall dsi_ctrl_hw_cmn_get_error_status(_DWORD *a1)
{
  unsigned int v2; // w19
  unsigned int v3; // w21
  unsigned __int64 v4; // x9
  unsigned int v5; // w0
  unsigned __int64 v6; // x26
  unsigned __int64 v7; // x27
  unsigned __int64 v8; // x28
  unsigned __int64 v9; // x22
  unsigned int v10; // w23
  unsigned int v11; // w0
  unsigned __int64 v12; // x8
  int v13; // w27
  unsigned __int64 v14; // x22
  int v15; // w25
  __int64 v16; // x26
  int v17; // w19
  int v18; // w6
  unsigned __int64 v20; // [xsp+10h] [xbp-10h]
  int v21; // [xsp+1Ch] [xbp-4h]

  v2 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 180LL));
  v3 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 12LL));
  v4 = (v2 << 6) & 0x400LL
     | ((v2 & 1) << 9) & 0x37FF
     | ((((unsigned __int64)v2 >> 8) & 1) << 11) & 0xFFFFFFFFFFFF3FFFLL
     | (v2 << 12) & 0x11000000
     | ((((unsigned __int64)v3 >> 7) & 1) << 15)
     | ((((unsigned __int64)v3 >> 10) & 1) << 14)
     | ((unsigned __int64)v3 >> 2) & 0x10000
     | (2 * v3) & 0x100000
     | ((unsigned __int64)v3 >> 5) & 0x20000
     | ((unsigned __int64)v3 >> 2) & 0x200000
     | ((unsigned __int64)v3 >> 8) & 0x40000
     | ((unsigned __int64)v3 >> 5) & 0x400000
     | ((unsigned __int64)v3 >> 11) & 0x80000;
  if ( (v3 & 0x80000000) != 0 )
    v4 |= 0x800000u;
  v20 = v4;
  v5 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 104LL));
  v6 = v5;
  v21 = v5;
  v7 = (unsigned __int64)v5 >> 20;
  v8 = ((unsigned __int64)v5 >> 18) & 4;
  v9 = ((unsigned __int64)v5 >> 3) & 0x1000;
  v10 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 192LL));
  v11 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 288LL));
  v12 = v7 & 0x18 | v9;
  v13 = v11;
  v14 = v8 & 0xFFFFFFFFFFFFFF9CLL
      | (v6 >> 16) & 3
      | v12 & 0xFFFFFFFFFFFFFF9FLL
      | ((unsigned __int64)(v10 & 1) << 6)
      | (32 * (((unsigned __int64)v10 >> 4) & 1))
      | (v10 >> 1) & 0x80LL
      | (v11 >> 8) & 0x100
      | v20;
  v15 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 8LL));
  if ( v15 >= 0 )
    v16 = v14;
  else
    v16 = v14 | 0x2000;
  if ( a1 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Error status = 0x%llx, phy=0x%x, fifo=0x%x\n", a1[14], v16, v2, v3);
    v17 = a1[14];
  }
  else
  {
    v18 = v2;
    v17 = -1;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Error status = 0x%llx, phy=0x%x, fifo=0x%x\n", -1, v16, v18, v3);
  }
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: DSI_%d: ack=0x%x, timeout=0x%x, clk=0x%x, dsi=0x%x\n",
    v17,
    v21,
    v10,
    v13,
    v15);
  return v16;
}
