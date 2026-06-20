double __fastcall dsi_ctrl_hw_cmn_enable_status_interrupts(_DWORD *a1, unsigned int a2)
{
  unsigned int v4; // w21
  unsigned int v5; // w22
  unsigned int v6; // w23
  unsigned int v7; // w24
  unsigned int v8; // w25
  unsigned int v9; // w26
  int v10; // w0
  unsigned int v11; // w8
  int v12; // w22
  int v13; // w21
  int v14; // w4

  v4 = a2 >> 8;
  v5 = a2 >> 5;
  v6 = a2 >> 4;
  v7 = a2 >> 3;
  v8 = a2 >> 2;
  v9 = a2 >> 1;
  v10 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 272LL));
  v11 = (8 * a2) & 0x200
      | (unsigned __int8)(2 * (a2 & 1))
      | ((v9 & 1) << 11) & 0x5FFF
      | ((v8 & 1) << 13) & 0x7FFF
      | ((v7 & 1) << 15)
      | ((v6 & 1) << 17) & 0xFFDFFFFF
      | ((v5 & 1) << 21);
  v12 = v10 & 0x2000000;
  v13 = v11 | (a2 << 22) & 0x20000000 | (v4 << 31);
  writel_relaxed_16(v13 | v10 & 0x2000000, (unsigned int *)(*(_QWORD *)a1 + 272LL));
  if ( a1 )
    v14 = a1[14];
  else
    v14 = -1;
  return _drm_dev_dbg(
           0,
           0,
           0,
           "[msm-dsi-debug]: DSI_%d: Enable interrupts 0x%x, INT_CTRL=0x%x\n",
           v14,
           a2,
           v13 | (unsigned int)v12);
}
