unsigned __int64 __fastcall sde_hw_intf_get_vsync_timestamp(__int64 a1, unsigned __int8 a2)
{
  bool v3; // zf
  __int64 v4; // x1
  unsigned int v5; // w20
  __int64 v6; // x21

  v3 = (((*(_QWORD *)(*(_QWORD *)(a1 + 40) + 32LL) & 0x400LL) != 0) & a2) == 0;
  if ( (((*(_QWORD *)(*(_QWORD *)(a1 + 40) + 32LL) & 0x400LL) != 0) & a2) != 0 )
    v4 = 544;
  else
    v4 = 536;
  if ( v3 )
    v5 = 532;
  else
    v5 = 540;
  v6 = (unsigned int)sde_reg_read(a1, v4);
  return (unsigned int)sde_reg_read(a1, v5) | (unsigned __int64)(v6 << 32);
}
