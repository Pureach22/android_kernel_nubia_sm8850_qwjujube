__int64 __fastcall drm_edp_backlight_init(
        const char **a1,
        __int64 a2,
        unsigned __int16 a3,
        __int64 a4,
        unsigned __int16 *a5,
        unsigned __int8 *a6)
{
  char v11; // w8
  char v12; // w9
  const char *v13; // x8
  __int64 v14; // x1
  char v15; // w9
  int v17; // w5
  int v18; // w9
  int v19; // w13
  unsigned int v20; // w11
  unsigned int v21; // w9
  signed int v22; // w10
  unsigned int v23; // w8
  signed int v24; // w12
  const char *v25; // x8
  __int64 v26; // x1
  const char *v27; // x8
  __int64 v28; // x1
  __int64 result; // x0
  const char *v30; // x8
  __int64 v31; // x1
  const char *v32; // x8
  __int64 v33; // x1
  unsigned int v34; // w0
  int v35; // w9
  char v36; // w8
  unsigned __int16 v37; // w8
  const char *v38; // x8
  int v39; // w23
  __int64 v40; // x1
  __int64 v41; // x24
  __int64 v42; // x0
  const char *v43; // x8
  __int64 v44; // x1
  const char *v45; // x9
  __int64 v46; // x1
  const char *v47; // x8
  __int64 v48; // x1
  int v49; // w23
  signed int v50; // w16
  int v52; // w9
  const char *v53; // x8
  __int64 v54; // x1
  const char *v55; // x8
  __int64 v56; // x1
  _BYTE v57[4]; // [xsp+10h] [xbp-20h] BYREF
  _BYTE v58[4]; // [xsp+14h] [xbp-1Ch] BYREF
  _BYTE v59[4]; // [xsp+18h] [xbp-18h] BYREF
  _BYTE v60[4]; // [xsp+1Ch] [xbp-14h] BYREF
  _BYTE v61[4]; // [xsp+20h] [xbp-10h] BYREF
  unsigned __int16 v62; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v63; // [xsp+28h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a4 + 1) & 4) != 0 )
  {
    *(_BYTE *)(a2 + 4) |= 2u;
    v11 = *(_BYTE *)(a4 + 2);
    if ( (v11 & 2) == 0 )
    {
LABEL_3:
      v12 = *(_BYTE *)(a2 + 4);
      if ( (v11 & 4) == 0 )
        goto LABEL_4;
      goto LABEL_10;
    }
  }
  else
  {
    v11 = *(_BYTE *)(a4 + 2);
    if ( (v11 & 2) == 0 )
      goto LABEL_3;
  }
  *(_BYTE *)(a2 + 4) |= 4u;
  v12 = *(_BYTE *)(a2 + 4);
  if ( (*(_BYTE *)(a4 + 2) & 4) == 0 )
  {
LABEL_4:
    if ( (v12 & 4) == 0 )
      goto LABEL_5;
    goto LABEL_11;
  }
LABEL_10:
  v15 = v12 | 1;
  *(_BYTE *)(a2 + 4) = v15;
  if ( (v15 & 4) == 0 )
  {
LABEL_5:
    if ( (*(_BYTE *)(a4 + 2) & 1) == 0 )
    {
      v13 = a1[157];
      if ( v13 )
        v14 = *((_QWORD *)v13 + 1);
      else
        v14 = 0;
      _drm_dev_dbg(0, v14, 2, "%s: Panel supports neither AUX or PWM brightness control? Aborting\n", *a1);
      result = 4294967274LL;
      goto LABEL_59;
    }
    goto LABEL_35;
  }
LABEL_11:
  v59[0] = 0;
  v58[0] = 0;
  v57[0] = 0;
  v17 = drm_dp_dpcd_read(a1, 0x724u, (__int64)v59, 1);
  if ( v17 != 1 )
  {
    v27 = a1[157];
    if ( v27 )
      v28 = *((_QWORD *)v27 + 1);
    else
      v28 = 0;
    _drm_dev_dbg(0, v28, 2, "%s: Failed to read pwmgen bit count cap: %d\n", *a1, v17);
    result = 4294967277LL;
    goto LABEL_59;
  }
  v18 = -1 << v59[0];
  v59[0] &= 0x1Fu;
  *(_WORD *)(a2 + 2) = ~(_WORD)v18;
  if ( a3 )
  {
    if ( (unsigned int)drm_dp_dpcd_read(a1, 0x725u, (__int64)v58, 1) == 1 )
    {
      if ( (unsigned int)drm_dp_dpcd_read(a1, 0x726u, (__int64)v57, 1) == 1 )
      {
        v19 = 1 << v58[0];
        v20 = v58[0] & 0x1F;
        v58[0] &= 0x1Fu;
        v21 = ((a3 >> 1) + 27000000) / (unsigned int)a3;
        v22 = (3 * v21 + 2) >> 2;
        v23 = v57[0] & 0x1F;
        v57[0] &= 0x1Fu;
        if ( v22 >= v19 && (v24 = (5 * v21 + 2) >> 2, 255 << v23 >= v24) )
        {
          if ( v23 >= v20 )
          {
            do
            {
              if ( (unsigned __int8)v23 == 31 )
                v50 = 0;
              else
                v50 = (v21 + ((unsigned int)(1 << v23) >> 1)) >> v23;
              if ( v50 <= 1 )
                v50 = 1;
              if ( v50 >= 255 )
                v49 = 255;
              else
                v49 = v50;
              if ( v22 <= v49 << v23 && v49 << v23 <= v24 )
                break;
              LOBYTE(v23) = v23 - 1;
            }
            while ( v20 <= (unsigned __int8)v23 );
          }
          else
          {
            LOBYTE(v49) = 1;
          }
          v59[0] = v23;
          v60[0] = v23;
          if ( (unsigned int)drm_dp_dpcd_write(a1, 0x724u, (__int64)v60, 1) == 1 )
          {
            v52 = -1 << v59[0];
            *(_BYTE *)a2 = v59[0];
            *(_WORD *)(a2 + 2) = ~(_WORD)v52;
            if ( (*(_BYTE *)(a4 + 2) & 0x20) != 0 )
            {
              *(_BYTE *)(a2 + 1) = v49;
              v53 = a1[157];
              if ( v53 )
                v54 = *((_QWORD *)v53 + 1);
              else
                v54 = 0;
              _drm_dev_dbg(0, v54, 2, "%s: Using backlight frequency from driver (%dHz)\n", *a1);
            }
          }
          else
          {
            v55 = a1[157];
            if ( v55 )
              v56 = *((_QWORD *)v55 + 1);
            else
              v56 = 0;
            _drm_dev_dbg(0, v56, 2, "%s: Failed to write aux pwmgen bit count: %d\n", *a1);
          }
        }
        else
        {
          v25 = a1[157];
          if ( v25 )
            v26 = *((_QWORD *)v25 + 1);
          else
            v26 = 0;
          _drm_dev_dbg(0, v26, 2, "%s: Driver defined backlight frequency (%d) out of range\n", *a1);
        }
      }
      else
      {
        v32 = a1[157];
        if ( v32 )
          v33 = *((_QWORD *)v32 + 1);
        else
          v33 = 0;
        _drm_dev_dbg(0, v33, 2, "%s: Failed to read pwmgen bit count cap max: %d\n", *a1);
      }
    }
    else
    {
      v30 = a1[157];
      if ( v30 )
        v31 = *((_QWORD *)v30 + 1);
      else
        v31 = 0;
      _drm_dev_dbg(0, v31, 2, "%s: Failed to read pwmgen bit count cap min: %d\n", *a1);
    }
  }
LABEL_35:
  v62 = 0;
  v61[0] = 0;
  v34 = drm_dp_dpcd_read(a1, 0x721u, (__int64)v61, 1);
  if ( v34 != 1 )
  {
    v38 = a1[157];
    v39 = v34;
    if ( v38 )
      v40 = *((_QWORD *)v38 + 1);
    else
      v40 = 0;
    _drm_dev_dbg(0, v40, 2, "%s: Failed to read backlight mode: %d\n", *a1, v34);
    goto LABEL_46;
  }
  v35 = v61[0] & 3;
  *a6 = v35;
  v36 = *(_BYTE *)(a2 + 4);
  if ( (v36 & 4) != 0 )
  {
    if ( v35 != 2 )
    {
      v37 = *(_WORD *)(a2 + 2);
      goto LABEL_50;
    }
    v41 = (v36 & 1) + 1LL;
    v42 = drm_dp_dpcd_read(a1, 0x722u, (__int64)&v62, v41);
    if ( v42 == v41 )
    {
      v37 = (unsigned __int8)v62;
      if ( (*(_BYTE *)(a2 + 4) & 1) != 0 )
        v37 = _byteswap_ushort(v62);
      goto LABEL_50;
    }
    v47 = a1[157];
    v39 = v42;
    if ( v47 )
      v48 = *((_QWORD *)v47 + 1);
    else
      v48 = 0;
    _drm_dev_dbg(0, v48, 2, "%s: Failed to read backlight level: %d\n", *a1, (unsigned int)v42);
LABEL_46:
    if ( v39 >= 0 )
      result = 4294967291LL;
    else
      result = (unsigned int)v39;
    goto LABEL_59;
  }
  v37 = 0;
LABEL_50:
  *a5 = v37;
  v43 = a1[157];
  if ( v43 )
    v44 = *((_QWORD *)v43 + 1);
  else
    v44 = 0;
  _drm_dev_dbg(
    0,
    v44,
    2,
    "%s: Found backlight: aux_set=%d aux_enable=%d mode=%d\n",
    *a1,
    (*(unsigned __int8 *)(a2 + 4) >> 2) & 1,
    (*(unsigned __int8 *)(a2 + 4) >> 1) & 1,
    *a6);
  if ( (*(_BYTE *)(a2 + 4) & 4) != 0 )
  {
    v45 = a1[157];
    if ( v45 )
      v46 = *((_QWORD *)v45 + 1);
    else
      v46 = 0;
    _drm_dev_dbg(
      0,
      v46,
      2,
      "%s: Backlight caps: level=%d/%d pwm_freq_pre_divider=%d lsb_reg_used=%d\n",
      *a1,
      *a5,
      *(unsigned __int16 *)(a2 + 2),
      *(unsigned __int8 *)(a2 + 1),
      *(_BYTE *)(a2 + 4) & 1);
  }
  result = 0;
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return result;
}
