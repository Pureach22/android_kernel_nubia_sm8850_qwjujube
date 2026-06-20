__int64 __fastcall drm_dp_as_sdp_supported(_QWORD *a1, unsigned __int8 *a2)
{
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x1
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *a2 < 0x13u )
  {
LABEL_8:
    result = 0;
    goto LABEL_9;
  }
  v6[0] = 0;
  if ( drm_dp_dpcd_read(a1, 0x2214u, (__int64)v6, 1) != 1 )
  {
    v4 = a1[157];
    if ( v4 )
      v5 = *(_QWORD *)(v4 + 8);
    else
      v5 = 0;
    _drm_dev_dbg(0, v5, 8, "Failed to read DP_DPRX_FEATURE_ENUMERATION_LIST_CONT_1\n");
    goto LABEL_8;
  }
  result = v6[0] & 1;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
