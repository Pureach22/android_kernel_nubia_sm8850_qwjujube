__int64 __fastcall drm_dp_read_downstream_info(const char **a1, _BYTE *a2, _QWORD *a3)
{
  int v3; // w10
  unsigned int v5; // w10
  __int64 v8; // x20
  __int64 v9; // x0
  unsigned int v10; // w5
  const char *v11; // x9
  __int64 v12; // x1

  *a3 = 0;
  a3[1] = 0;
  if ( (a2[5] & 1) == 0 || *a2 == 16 )
    return 0;
  v3 = (a2[7] & 0xC) != 0 ? 4 : a2[7] & 0xF;
  if ( !((a2[5] & 0x10) != 0 ? v3 : a2[7] & 0xF) )
    return 0;
  v5 = 4 * v3;
  if ( (a2[5] & 0x10) != 0 )
    v8 = v5;
  else
    v8 = a2[7] & 0xF;
  v9 = drm_dp_dpcd_read(a1, 0x80u, (__int64)a3, v8);
  v10 = v9;
  if ( (v9 & 0x80000000) == 0 )
  {
    if ( v9 == (unsigned int)v8 )
    {
      v11 = a1[157];
      if ( v11 )
        v12 = *((_QWORD *)v11 + 1);
      else
        v12 = 0;
      _drm_dev_dbg(0, v12, 2, "%s: DPCD DFP: %*ph\n", *a1, v9, a3);
      return 0;
    }
    else
    {
      return (unsigned int)-5;
    }
  }
  return v10;
}
