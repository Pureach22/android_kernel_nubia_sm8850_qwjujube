__int64 __fastcall drm_lspcon_get_mode(__int64 a1, __int64 a2, int *a3)
{
  __int64 v6; // x1
  __int64 result; // x0
  int v8; // w8
  __int64 v9; // x0
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  if ( a3 )
  {
    if ( (unsigned int)drm_dp_dual_mode_read(a2, 0x41u, v10, 1u)
      && (usleep_range_state(500, 1000, 2), (unsigned int)drm_dp_dual_mode_read(a2, 0x41u, v10, 1u))
      && (usleep_range_state(500, 1000, 2), (unsigned int)drm_dp_dual_mode_read(a2, 0x41u, v10, 1u))
      && (usleep_range_state(500, 1000, 2), (unsigned int)drm_dp_dual_mode_read(a2, 0x41u, v10, 1u))
      && (usleep_range_state(500, 1000, 2), (unsigned int)drm_dp_dual_mode_read(a2, 0x41u, v10, 1u))
      && (usleep_range_state(500, 1000, 2), (unsigned int)drm_dp_dual_mode_read(a2, 0x41u, v10, 1u)) )
    {
      if ( a1 )
        v6 = *(_QWORD *)(a1 + 8);
      else
        v6 = 0;
      _drm_dev_dbg(0, v6, 2, "LSPCON read(0x80, 0x41) failed\n");
      result = 4294967282LL;
    }
    else
    {
      result = 0;
      if ( (v10[0] & 1) != 0 )
        v8 = 2;
      else
        v8 = 1;
      *a3 = v8;
    }
  }
  else
  {
    if ( a1 )
      v9 = *(_QWORD *)(a1 + 8);
    else
      v9 = 0;
    dev_err(v9, "[drm] *ERROR* NULL input\n");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
