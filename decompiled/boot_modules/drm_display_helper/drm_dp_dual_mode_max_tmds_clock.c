__int64 __fastcall drm_dp_dual_mode_max_tmds_clock(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v6; // x1
  _BYTE v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    result = 165000;
    if ( a2 >= 4 )
    {
      v5 = a1;
      v7[0] = 0;
      if ( drm_dp_dual_mode_read(a3, 0x1Du, v7, 1u) || (unsigned int)v7[0] - 255 <= 0xFFFFFF01 )
      {
        if ( v5 )
          v6 = *(_QWORD *)(v5 + 8);
        else
          v6 = 0;
        _drm_dev_dbg(0, v6, 2, "Failed to query max TMDS clock\n");
        result = 165000;
      }
      else
      {
        result = 2500 * (unsigned int)v7[0];
      }
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
