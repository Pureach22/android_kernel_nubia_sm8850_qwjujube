__int64 __fastcall drm_dp_dpcd_access(__int64 a1, unsigned __int8 a2, int a3, __int64 a4, __int64 a5)
{
  int v7; // w0
  int v8; // w20
  int v9; // w22
  __int64 (__fastcall *v10)(__int64, int *); // x8
  __int64 v11; // x8
  __int64 v12; // x1
  unsigned int v13; // w20
  int v15; // [xsp+0h] [xbp-20h] BYREF
  int v16; // [xsp+4h] [xbp-1Ch]
  __int64 v17; // [xsp+8h] [xbp-18h]
  __int64 v18; // [xsp+10h] [xbp-10h]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = a4;
  v15 = a3;
  v16 = a2;
  v18 = a5;
  mutex_lock(a1 + 1272);
  if ( (*(_BYTE *)(a1 + 1553) & 1) != 0 )
  {
    v7 = -16;
  }
  else
  {
    v7 = 0;
    v8 = 0;
    v9 = 32;
    do
    {
      if ( v7 != -110 && v7 )
        usleep_range_state(500, 600, 2);
      v10 = *(__int64 (__fastcall **)(__int64, int *))(a1 + 1360);
      if ( *((_DWORD *)v10 - 1) != -929194565 )
        __break(0x8228u);
      v7 = v10(a1, &v15);
      if ( (v7 & 0x80000000) == 0 )
      {
        if ( (v16 & 0x300) != 0 )
        {
          v7 = -5;
        }
        else
        {
          if ( (v7 & 0x7FFFFFFF) == a5 )
            goto LABEL_21;
          v7 = -71;
        }
      }
      if ( !v8 )
        v8 = v7;
      --v9;
    }
    while ( v9 );
    v11 = *(_QWORD *)(a1 + 1256);
    if ( v11 )
      v12 = *(_QWORD *)(v11 + 8);
    else
      v12 = 0;
    _drm_dev_dbg(0, v12, 2, "%s: Too many retries, giving up. First error: %d\n", *(const char **)a1, v8);
    v7 = v8;
  }
LABEL_21:
  v13 = v7;
  mutex_unlock(a1 + 1272);
  _ReadStatusReg(SP_EL0);
  return v13;
}
