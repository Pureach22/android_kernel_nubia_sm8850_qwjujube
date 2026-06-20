__int64 __fastcall drm_dp_128b132b_read_aux_rd_interval(__int64 a1)
{
  unsigned int v2; // w8
  __int64 v4; // x8
  __int64 v5; // x0
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  if ( drm_dp_dpcd_read(a1, 8726, v6, 1) == 1 )
  {
    v2 = v6[0];
  }
  else
  {
    v4 = *(_QWORD *)(a1 + 1256);
    if ( v4 )
      v5 = *(_QWORD *)(v4 + 8);
    else
      v5 = 0;
    dev_err(v5, "[drm] *ERROR* %s: failed rd interval read\n", *(const char **)a1);
    v2 = 127;
  }
  _ReadStatusReg(SP_EL0);
  return 1000 * (((v2 & 0x7F) + 1) << ((v2 >> 7) ^ 1));
}
