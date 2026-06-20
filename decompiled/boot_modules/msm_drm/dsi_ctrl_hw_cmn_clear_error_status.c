double __fastcall dsi_ctrl_hw_cmn_clear_error_status(_DWORD *a1, __int64 a2)
{
  unsigned int v4; // w20
  int v5; // w24
  unsigned int v6; // w26
  unsigned int v7; // w25
  unsigned int v8; // w28
  unsigned int v9; // w21
  int v10; // w27
  unsigned int v11; // w23
  int v12; // w19
  __int64 v13; // x5

  v4 = ((_DWORD)a2 << 18) & 0x100000
     | ((a2 & 3) << 16) & 0xFE7F7FFF
     | ((((unsigned int)a2 >> 3) & 3) << 23)
     | ((((unsigned int)a2 >> 12) & 1) << 15);
  v5 = (_DWORD)a2 << 8;
  v6 = ((unsigned int)a2 >> 12) & 0x11000 | ((unsigned int)a2 >> 9) & 1;
  v7 = ((unsigned int)a2 >> 4) & 0x400
     | ((unsigned int)a2 >> 8) & 0x80
     | ((WORD1(a2) & 1) << 18) & 0xBBBFFFFF
     | ((((unsigned int)a2 >> 17) & 1) << 22) & 0xBBFFFFFF
     | ((((unsigned int)a2 >> 18) & 1) << 26) & 0xBFFFFFFF
     | ((((unsigned int)a2 >> 19) & 1) << 30);
  v8 = ((unsigned int)a2 >> 6) & 0x10 | ((unsigned int)a2 >> 3) & 0x100;
  v9 = ((unsigned int)a2 >> 1) & 0x10 | ((unsigned int)a2 >> 6) & 1 | ((((unsigned int)a2 >> 7) & 1) << 8);
  v10 = ((unsigned int)a2 >> 1) & 0x80000 | (4 * a2) & 0x800000 | (32 * a2) & 0x8000000 | ((_DWORD)a2 << 8) & 0x80000000;
  v11 = ((_DWORD)a2 << 18) & 0x80000000;
  writel_relaxed_16(v6 | v8, (unsigned int *)(*(_QWORD *)a1 + 180LL));
  writel_relaxed_16(v7 | v10, (unsigned int *)(*(_QWORD *)a1 + 12LL));
  writel_relaxed_16(v4, (unsigned int *)(*(_QWORD *)a1 + 104LL));
  __dsb(0xEu);
  writel_relaxed_16(0, (unsigned int *)(*(_QWORD *)a1 + 104LL));
  writel_relaxed_16(v9, (unsigned int *)(*(_QWORD *)a1 + 192LL));
  writel_relaxed_16(v5 & 0x10000, (unsigned int *)(*(_QWORD *)a1 + 288LL));
  writel_relaxed_16(v11, (unsigned int *)(*(_QWORD *)a1 + 8LL));
  if ( a1 )
  {
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: DSI_%d: clear errors = 0x%llx, phy=0x%x, fifo=0x%x\n",
      a1[14],
      a2,
      v6 | v8,
      v7 | v10);
    v12 = a1[14];
  }
  else
  {
    v13 = a2;
    v12 = -1;
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: DSI_%d: clear errors = 0x%llx, phy=0x%x, fifo=0x%x\n",
      -1,
      v13,
      v6 | v8,
      v7 | v10);
  }
  return _drm_dev_dbg(
           0,
           0,
           0,
           "[msm-dsi-debug]: DSI_%d: ack=0x%x, timeout=0x%x, clk=0x%x, dsi=0x%x\n",
           v12,
           v4,
           v9,
           v5 & 0x10000,
           v11);
}
