__int64 __fastcall dsi_ctrl_reset(__int64 a1, unsigned int a2)
{
  __int64 v4; // x8
  _DWORD *v5; // x8
  unsigned int v6; // w20

  if ( a1 )
  {
    mutex_lock(a1 + 32);
    v4 = *(unsigned int *)(a1 + 1608);
    if ( (unsigned int)v4 >= 3 )
    {
      __break(0x5512u);
      JUMPOUT(0x1D3264);
    }
    v5 = *(_DWORD **)(a1 + 8 * v4 + 1224);
    if ( v5 )
    {
      if ( *(v5 - 1) != 717022289 )
        __break(0x8228u);
      v6 = ((__int64 (__fastcall *)(__int64, _QWORD))v5)(a1 + 96, a2);
    }
    else
    {
      v6 = 0;
    }
    mutex_unlock(a1 + 32);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v6;
}
