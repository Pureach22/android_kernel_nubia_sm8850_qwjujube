__int64 __fastcall drm_dp_read_dpcd_caps(const char **a1, _BYTE *a2)
{
  __int64 result; // x0
  const char *v5; // x8
  __int64 v6; // x1
  unsigned int v7; // w5
  const char *v8; // x8
  __int64 v9; // x1
  const char *v11; // x8
  __int64 v12; // x1
  __int64 v13; // x9
  _QWORD v14[3]; // [xsp+8h] [xbp-18h] BYREF

  v14[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = drm_dp_dpcd_read(a1, 0, (__int64)a2, 15);
  if ( (result & 0x80000000) != 0 )
    goto LABEL_15;
  if ( (_DWORD)result != 15 || !*a2 )
    goto LABEL_12;
  if ( (char)a2[14] < 0 )
  {
    *(_QWORD *)((char *)v14 + 7) = 0;
    v14[0] = 0;
    result = drm_dp_dpcd_read(a1, 0x2200u, (__int64)v14, 15);
    if ( (result & 0x80000000) != 0 )
      goto LABEL_15;
    if ( (result & 0x7FFFFFFF) == 0xF )
    {
      v7 = (unsigned __int8)*a2;
      if ( v7 <= LOBYTE(v14[0]) )
      {
        if ( *(_QWORD *)a2 != v14[0] || *(_QWORD *)(a2 + 7) != *(_QWORD *)((char *)v14 + 7) )
        {
          v11 = a1[157];
          if ( v11 )
            v12 = *((_QWORD *)v11 + 1);
          else
            v12 = 0;
          _drm_dev_dbg(0, v12, 2, "%s: Base DPCD: %*ph\n", *a1, 15, a2);
          v13 = *(_QWORD *)((char *)v14 + 7);
          *(_QWORD *)a2 = v14[0];
          *(_QWORD *)(a2 + 7) = v13;
        }
      }
      else
      {
        v8 = a1[157];
        if ( v8 )
          v9 = *((_QWORD *)v8 + 1);
        else
          v9 = 0;
        _drm_dev_dbg(0, v9, 2, "%s: Extended DPCD rev less than base DPCD rev (%d > %d)\n", *a1, v7, LOBYTE(v14[0]));
      }
      goto LABEL_5;
    }
LABEL_12:
    result = 4294967291LL;
    goto LABEL_15;
  }
LABEL_5:
  v5 = a1[157];
  if ( v5 )
    v6 = *((_QWORD *)v5 + 1);
  else
    v6 = 0;
  _drm_dev_dbg(0, v6, 2, "%s: DPCD: %*ph\n", *a1, 15, a2);
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
