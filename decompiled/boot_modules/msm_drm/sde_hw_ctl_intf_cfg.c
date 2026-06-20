__int64 __fastcall sde_hw_ctl_intf_cfg(__int64 a1, _DWORD *a2)
{
  int v2; // w8
  int v3; // w3
  int v4; // w9
  unsigned int v5; // w8
  __int64 v6; // x2

  if ( !a1 )
    return 4294967274LL;
  if ( a2[1] )
    v2 = (a2[1] & 3) + 2;
  else
    v2 = 0;
  v4 = a2[2];
  v3 = a2[3];
  v5 = v2 & 0xFFFFFF0F | (16 * (*a2 & 0xF));
  if ( v4 )
    v5 = (v5 | (v4 << 20)) - 0x80000;
  if ( v3 == 1 )
  {
    v6 = v5 | ((a2[4] & 3) << 15) | 0x20000;
    goto LABEL_12;
  }
  if ( !v3 )
  {
    v6 = v5 & 0xFFFC7FFF;
LABEL_12:
    sde_reg_write(a1, 20, v6, "CTL_TOP");
    return 0;
  }
  printk(&unk_274824, "sde_hw_ctl_intf_cfg");
  return 4294967274LL;
}
