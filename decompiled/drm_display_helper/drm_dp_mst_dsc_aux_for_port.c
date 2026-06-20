const char **__fastcall drm_dp_mst_dsc_aux_for_port(const char **result)
{
  const char *v1; // x8
  const char **v2; // x19
  __int64 v3; // x21
  __int64 v4; // x20
  __int64 v5; // x8
  _QWORD *v6; // x8
  _QWORD *i; // x9
  _QWORD *v8; // t1
  const char **v9; // x21
  __int64 v10; // x8
  _QWORD *v11; // x8
  _QWORD *j; // x9
  _QWORD *v13; // t1
  const char *v14; // x8
  _QWORD *v15; // x8
  _QWORD *k; // x9
  _QWORD *v17; // t1
  const char **v18; // x0
  const char **v19; // x20
  const char **v20; // x19
  _BYTE v21[4]; // [xsp+0h] [xbp-30h] BYREF
  _BYTE v22[4]; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-28h] BYREF
  __int64 v24; // [xsp+10h] [xbp-20h]
  _QWORD v25[3]; // [xsp+18h] [xbp-18h] BYREF

  v25[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  if ( !result )
    goto LABEL_64;
  v1 = result[202];
  v2 = result;
  v22[0] = 0;
  v21[0] = 0;
  v3 = *((_QWORD *)v1 + 7);
  if ( !v3 )
    goto LABEL_43;
  v4 = *((_QWORD *)v1 + 7);
  do
  {
    if ( *(unsigned __int8 *)(v4 + 14) >= 0x14u )
    {
      if ( *(unsigned __int8 *)(v4 + 8) > 7u
        || *(_BYTE *)(v4 + 12) == 4 && (*(_BYTE *)(v4 + 10) & 1) == 0 && (*(_BYTE *)(v4 + 13) & 1) != 0 )
      {
        goto LABEL_6;
      }
      mutex_lock(*(_QWORD *)(v4 + 1632) + 800LL);
      if ( *(_BYTE *)(v4 + 12) == 2 )
      {
        v5 = *(_QWORD *)(v4 + 40);
        if ( v5 )
        {
          if ( *(_DWORD *)(v5 + 36) == 2 )
          {
            v8 = *(_QWORD **)(v5 + 40);
            v6 = (_QWORD *)(v5 + 40);
            for ( i = v8; i != v6; i = (_QWORD *)*i )
            {
              if ( *((_BYTE *)i - 12) == 3 && *((_BYTE *)i - 15) != 1 )
              {
                mutex_unlock(*(_QWORD *)(v4 + 1632) + 800LL);
                goto LABEL_6;
              }
            }
          }
        }
      }
      mutex_unlock(*(_QWORD *)(v4 + 1632) + 800LL);
    }
    if ( *(_BYTE *)(v4 + 1648) != 1 )
      goto LABEL_63;
LABEL_6:
    v4 = *(_QWORD *)(*(_QWORD *)(v4 + 1616) + 56LL);
  }
  while ( v4 );
  if ( *(unsigned __int8 *)(v3 + 14) < 0x14u )
    goto LABEL_43;
  if ( *(unsigned __int8 *)(v3 + 8) > 7u
    || *(_BYTE *)(v3 + 12) == 4 && (*(_BYTE *)(v3 + 10) & 1) == 0 && (*(_BYTE *)(v3 + 13) & 1) != 0 )
  {
LABEL_23:
    LOBYTE(v25[0]) = 0;
    if ( drm_dp_dpcd_read(v2 + 6, 0x60u, (__int64)v21, 1) == 1 && drm_dp_dpcd_read(v2 + 6, 0x90u, (__int64)v22, 1) == 1 )
    {
      v9 = (const char **)(v3 + 48);
      if ( drm_dp_dpcd_read(v9, 0x60u, (__int64)v25, 1) == 1 )
      {
        if ( (v21[0] & 1) != 0 && (v22[0] & 1) != 0 && (v25[0] & 2) != 0 )
        {
          v2[201] = (const char *)v9;
          result = v2 + 6;
        }
        else
        {
          result = v9;
        }
        goto LABEL_64;
      }
    }
    goto LABEL_63;
  }
  mutex_lock(*(_QWORD *)(v3 + 1632) + 800LL);
  if ( *(_BYTE *)(v3 + 12) == 2 )
  {
    v10 = *(_QWORD *)(v3 + 40);
    if ( v10 )
    {
      if ( *(_DWORD *)(v10 + 36) == 2 )
      {
        v13 = *(_QWORD **)(v10 + 40);
        v11 = (_QWORD *)(v10 + 40);
        for ( j = v13; j != v11; j = (_QWORD *)*j )
        {
          if ( *((_BYTE *)j - 12) == 3 && *((_BYTE *)j - 15) != 1 )
          {
            mutex_unlock(*(_QWORD *)(v3 + 1632) + 800LL);
            goto LABEL_23;
          }
        }
      }
    }
  }
  mutex_unlock(*(_QWORD *)(v3 + 1632) + 800LL);
LABEL_43:
  if ( *((unsigned __int8 *)v2 + 14) < 0x14u )
  {
LABEL_59:
    if ( v3 )
      v18 = (const char **)(v3 + 48);
    else
      v18 = *((const char ***)v2[204] + 16);
    v19 = v18;
    if ( (unsigned int)drm_dp_read_desc(v18, (unsigned __int16 *)&v23, 1) )
      goto LABEL_63;
    if ( (v24 & 0x800000000LL) != 0 )
    {
      memset(v25, 0, 15);
      if ( (drm_dp_read_dpcd_caps(v19, v25) & 0x80000000) != 0 )
        goto LABEL_63;
      if ( LOBYTE(v25[0]) >= 0x14u && (v25[0] & 0x10000000000LL) != 0 )
      {
        result = v19;
        if ( (BYTE5(v25[0]) & 6) != 2 )
          goto LABEL_64;
      }
    }
    v20 = v2 + 6;
    if ( drm_dp_dpcd_read(v20, 0x60u, (__int64)v21, 1) == 1
      && drm_dp_dpcd_read(v20, 0x90u, (__int64)v22, 1) == 1
      && (v21[0] & 1) != 0 )
    {
      result = v20;
      if ( (v22[0] & 1) != 0 )
        goto LABEL_64;
    }
LABEL_63:
    result = nullptr;
    goto LABEL_64;
  }
  if ( *((unsigned __int8 *)v2 + 8) <= 7u
    && (*((_BYTE *)v2 + 12) != 4 || (*((_BYTE *)v2 + 10) & 1) != 0 || (*((_BYTE *)v2 + 13) & 1) == 0) )
  {
    mutex_lock(v2[204] + 800);
    if ( *((_BYTE *)v2 + 12) == 2 )
    {
      v14 = v2[5];
      if ( v14 )
      {
        if ( *((_DWORD *)v14 + 9) == 2 )
        {
          v17 = *((_QWORD **)v14 + 5);
          v15 = v14 + 40;
          for ( k = v17; k != v15; k = (_QWORD *)*k )
          {
            if ( *((_BYTE *)k - 12) == 3 && *((_BYTE *)k - 15) != 1 )
            {
              mutex_unlock(v2[204] + 800);
              goto LABEL_45;
            }
          }
        }
      }
    }
    mutex_unlock(v2[204] + 800);
    goto LABEL_59;
  }
LABEL_45:
  result = v2 + 6;
LABEL_64:
  _ReadStatusReg(SP_EL0);
  return result;
}
