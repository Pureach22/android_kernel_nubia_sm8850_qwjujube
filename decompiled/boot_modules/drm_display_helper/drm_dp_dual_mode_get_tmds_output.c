__int64 __fastcall drm_dp_dual_mode_get_tmds_output(__int64 a1, unsigned int a2, __int64 a3, bool *a4)
{
  unsigned int v4; // w19
  __int64 v7; // x0
  __int64 v8; // x1
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 > 3 )
  {
    v10[0] = 0;
    v7 = drm_dp_dual_mode_read(a3, 0x20u, v10, 1u);
    v4 = v7;
    if ( v7 )
    {
      if ( a1 )
        v8 = *(_QWORD *)(a1 + 8);
      else
        v8 = 0;
      _drm_dev_dbg(0, v8, 2, "Failed to query state of TMDS output buffers\n");
    }
    else
    {
      *a4 = (v10[0] & 1) == 0;
    }
  }
  else
  {
    v4 = 0;
    *a4 = 1;
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
