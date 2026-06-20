__int64 __fastcall dsi_ctrl_setup_avr(__int64 a1, char a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  _DWORD *v6; // x8

  if ( !a1 )
    return 4294967274LL;
  if ( *(_DWORD *)(a1 + 2440) != 1 )
    return 0;
  v4 = mutex_lock(a1 + 32);
  v5 = *(unsigned int *)(a1 + 1608);
  if ( (unsigned int)v5 < 3 )
  {
    v6 = *(_DWORD **)(a1 + 8 * v5 + 216);
    if ( v6 )
    {
      if ( *(v6 - 1) != 1642962683 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v6)(a1 + 96, a2 & 1);
    }
    mutex_unlock(a1 + 32);
    return 0;
  }
  __break(0x5512u);
  return dsi_ctrl_host_deinit(v4);
}
