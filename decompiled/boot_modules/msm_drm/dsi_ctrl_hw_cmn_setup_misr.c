__int64 __fastcall dsi_ctrl_hw_cmn_setup_misr(__int64 a1, int a2, char a3, unsigned int a4)
{
  int v4; // w8
  int v5; // w9
  int v6; // w8
  int v7; // w10
  __int64 v9; // x21
  unsigned int v10; // w20
  int v11; // w4
  __int64 result; // x0

  if ( (a3 & 1) != 0 )
    v4 = 0x10000;
  else
    v4 = 0;
  if ( a4 >= 0xFF )
    v5 = 255;
  else
    v5 = a4;
  v6 = v4 | (v5 << 8);
  if ( (a3 & 1) != 0 )
    v7 = 0x10000000;
  else
    v7 = 0;
  if ( a2 == 2 )
    v9 = 160;
  else
    v9 = 164;
  if ( a2 == 2 )
    v10 = v7;
  else
    v10 = v6;
  if ( a1 )
    v11 = *(_DWORD *)(a1 + 56);
  else
    v11 = -1;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: MISR ctrl: 0x%x\n", v11, v10);
  result = writel_relaxed_16(v10, (unsigned int *)(*(_QWORD *)a1 + v9));
  __dsb(0xEu);
  return result;
}
