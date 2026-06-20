__int64 __fastcall drm_dp_i2c_do_msg(const char **a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x10
  int v6; // w23
  unsigned int v7; // w24
  unsigned __int64 v8; // x9
  int v9; // w10
  int v10; // w8
  int v11; // w8
  int v12; // w25
  const char *v13; // x8
  __int64 result; // x0
  int v15; // w3
  int v16; // w8
  const char *v17; // x8
  __int64 v18; // x1
  const char *v19; // x8
  __int64 v20; // x1
  int v21; // w8
  const char *v22; // x8
  __int64 v23; // x1
  const char *v24; // x20
  __int64 v25; // x0
  int v26; // w8
  const char *v27; // x9
  __int64 v28; // x1
  __int64 v29; // x8
  const char *v30; // x8
  __int64 v31; // x1
  int v32; // w5
  const char *v33; // x8
  __int64 v34; // x1
  int v35; // w5
  const char *v36; // x4
  __int64 v37; // x19
  const char *v38; // x8
  __int64 v39; // x0
  const char *v40; // x8
  __int64 v41; // x0

  v2 = *(_QWORD *)(a2 + 16);
  v3 = dp_aux_i2c_speed_khz + 9000 * v2;
  LODWORD(v2) = 8 * v2;
  v6 = 0;
  v7 = 0;
  v8 = (v3 + 10999) / (unsigned __int64)dp_aux_i2c_speed_khz;
  v9 = v2 + 42;
  v10 = v2 + 566;
  if ( (*(_BYTE *)(a2 + 4) & 1) != 0 )
    v10 = 566;
  else
    v9 = 42;
  v11 = ((int)v8 + v10 + v9 - 1) / (v10 + v9);
  if ( v11 <= 7 )
    v12 = 7;
  else
    v12 = v11;
  while ( 1 )
  {
    v13 = a1[170];
    if ( *((_DWORD *)v13 - 1) != -929194565 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(const char **, __int64))v13)(a1, a2);
    if ( (result & 0x80000000) != 0 )
    {
      if ( (_DWORD)result != -16 )
      {
        if ( (_DWORD)result == -110 )
        {
          if ( (_drm_debug & 4) != 0
            && (v24 = a1[157], (unsigned int)__ratelimit(&drm_dp_i2c_do_msg_rs_, "drm_dp_i2c_do_msg")) )
          {
            if ( v24 )
              v25 = *((_QWORD *)v24 + 1);
            else
              v25 = 0;
            drm_dev_printk(v25, &unk_1C719, "%s: transaction timed out\n", *a1);
            return 4294967186LL;
          }
          else
          {
            return 4294967186LL;
          }
        }
        else
        {
          v27 = a1[157];
          if ( v27 )
          {
            v28 = *((_QWORD *)v27 + 1);
            v29 = result;
          }
          else
          {
            v29 = result;
            v28 = 0;
          }
          v36 = *a1;
          v37 = v29;
          _drm_dev_dbg(0, v28, 2, "%s: transaction failed: %d\n", v36, v29);
          return v37;
        }
      }
      goto LABEL_8;
    }
    v15 = *(unsigned __int8 *)(a2 + 5);
    v16 = v15 & 3;
    if ( (v15 & 3) == 0 )
      break;
    if ( v16 != 2 )
    {
      if ( v16 == 1 )
      {
        v30 = a1[157];
        if ( v30 )
        {
          v31 = *((_QWORD *)v30 + 1);
          v32 = result;
        }
        else
        {
          v32 = result;
          v31 = 0;
        }
        _drm_dev_dbg(0, v31, 2, "%s: native nack (result=%d, size=%zu)\n", *a1, v32, *(_QWORD *)(a2 + 16));
      }
      else
      {
        v38 = a1[157];
        if ( v38 )
          v39 = *((_QWORD *)v38 + 1);
        else
          v39 = 0;
        dev_err(v39, "[drm] *ERROR* %s: invalid native reply %#04x\n", *a1, v15);
      }
      return 4294967175LL;
    }
    v17 = a1[157];
    if ( v17 )
      v18 = *((_QWORD *)v17 + 1);
    else
      v18 = 0;
    _drm_dev_dbg(0, v18, 2, "%s: native defer\n", *a1);
    usleep_range_state(500, 600, 2);
LABEL_8:
    if ( ++v6 >= v7 + v12 )
    {
      v22 = a1[157];
      if ( v22 )
        v23 = *((_QWORD *)v22 + 1);
      else
        v23 = 0;
      _drm_dev_dbg(0, v23, 2, "%s: Too many retries, giving up\n", *a1);
      return 4294967175LL;
    }
  }
  if ( (v15 & 0xC) == 8 )
  {
    v19 = a1[157];
    if ( v19 )
      v20 = *((_QWORD *)v19 + 1);
    else
      v20 = 0;
    _drm_dev_dbg(0, v20, 2, "%s: I2C defer\n", *a1);
    if ( v7 < 7 )
      ++v7;
    ++*((_DWORD *)a1 + 345);
    usleep_range_state(500, 600, 2);
    v21 = *(unsigned __int8 *)(a2 + 4);
    if ( (v21 & 0xFFFFFFFB) == 0 )
      *(_BYTE *)(a2 + 4) = v21 | 2;
    goto LABEL_8;
  }
  if ( (v15 & 0xC) == 4 )
  {
    v33 = a1[157];
    if ( v33 )
    {
      v34 = *((_QWORD *)v33 + 1);
      v35 = result;
    }
    else
    {
      v35 = result;
      v34 = 0;
    }
    _drm_dev_dbg(0, v34, 2, "%s: I2C nack (result=%d, size=%zu)\n", *a1, v35, *(_QWORD *)(a2 + 16));
    ++*((_DWORD *)a1 + 344);
    return 4294967175LL;
  }
  if ( (v15 & 0xC) != 0 )
  {
    v40 = a1[157];
    if ( v40 )
      v41 = *((_QWORD *)v40 + 1);
    else
      v41 = 0;
    dev_err(v41, "[drm] *ERROR* %s: invalid I2C reply %#04x\n", *a1, v15);
    return 4294967175LL;
  }
  if ( (result & 0x7FFFFFFF) != *(_QWORD *)(a2 + 16) )
  {
    v26 = *(unsigned __int8 *)(a2 + 4);
    if ( (v26 & 0xFFFFFFFB) == 0 )
      *(_BYTE *)(a2 + 4) = v26 | 2;
  }
  return result;
}
