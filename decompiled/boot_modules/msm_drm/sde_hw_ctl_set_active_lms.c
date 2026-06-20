__int64 __fastcall sde_hw_ctl_set_active_lms(__int64 a1, _QWORD *a2)
{
  unsigned int v2; // w8
  __int64 v3; // x2

  if ( a2 )
  {
    v2 = *a2 & 1 | ((*a2 & 2) != 0);
    if ( (*a2 & 4LL) != 0 )
      v2 = *a2 & 1 | ((*a2 & 2) != 0) | 2;
    if ( (*a2 & 8LL) != 0 )
      v2 |= 4u;
    if ( (*a2 & 0x10LL) != 0 )
      v2 |= 8u;
    if ( (*a2 & 0x20LL) != 0 )
      v2 |= 0x10u;
    if ( (*a2 & 0x40LL) != 0 )
      v2 |= 0x20u;
    if ( (*a2 & 0x80LL) != 0 )
      v2 |= 0x40u;
    if ( (*a2 & 0x100LL) != 0 )
      v2 |= 0x80u;
    if ( (*a2 & 0x200LL) != 0 )
      v2 |= 1u;
    if ( (*a2 & 0x400LL) != 0 )
      v2 |= 1u;
    if ( (*a2 & 0x800LL) != 0 )
      v2 |= 1u;
    if ( (*a2 & 0x1000LL) != 0 )
      v3 = v2 | 1;
    else
      v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  return sde_reg_write(a1, 304, v3, "CTL_LAYER_ACTIVE");
}
