__int64 __fastcall sde_hw_ctl_hw_fence_ctrl(__int64 a1, char a2, char a3, int a4, char a5, char a6)
{
  int v12; // w0
  int v13; // w8
  int v14; // w9
  int v15; // w8
  int v16; // w9
  int v17; // w8
  unsigned int v18; // w9
  int v19; // w10
  unsigned int v20; // w8
  __int64 v21; // x2

  v12 = sde_reg_read(a1, 592);
  if ( (a2 & 1) != 0 )
    v13 = 32;
  else
    v13 = 0;
  if ( (a3 & 1) != 0 )
    v14 = 16;
  else
    v14 = 0;
  v15 = v14 | v13;
  if ( (a5 & 1) != 0 )
    v16 = 257;
  else
    v16 = 1;
  v17 = v15 | v12;
  v18 = v17 | v16;
  if ( (a6 & 1) != 0 )
    v18 |= 0x200u;
  if ( (a5 & 1) != 0 )
    v19 = -2;
  else
    v19 = -258;
  v20 = v17 & v19;
  if ( (a6 & 1) == 0 )
    v20 &= ~0x200u;
  if ( a4 )
    v21 = v18;
  else
    v21 = v20;
  return sde_reg_write(a1, 592, v21, "CTL_HW_FENCE_CTRL");
}
