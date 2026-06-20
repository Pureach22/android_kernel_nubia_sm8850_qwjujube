__int64 __fastcall msm_property_atomic_set(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4)
{
  int v8; // w8
  unsigned int v9; // w21
  unsigned int v10; // w10
  __int64 v11; // x2
  _QWORD *v12; // x8
  __int64 v14; // x0
  unsigned int *v15; // x0
  unsigned int *v16; // x24
  _QWORD *v17; // x9
  __int64 v18; // x9
  __int64 v19; // x22
  __int64 v20; // x0
  _QWORD *v21; // x0
  _QWORD *v22; // t1
  _QWORD *v23; // x2
  _QWORD *v24; // x1

  if ( !a1 || !a2 )
    goto LABEL_17;
  if ( !a3 )
  {
    _drm_err("invalid argument(s)\n");
    goto LABEL_17;
  }
  mutex_lock(a1 + 80);
  v8 = *(_DWORD *)(a1 + 32);
  if ( !v8 )
  {
LABEL_11:
    mutex_unlock(a1 + 80);
LABEL_17:
    _drm_err("invalid argument(s)\n");
    return 4294967274LL;
  }
  v9 = *(_DWORD *)(a1 + 48);
  v10 = v8 - 1;
  while ( *(_QWORD *)(*(_QWORD *)(a1 + 16) + 8LL * (int)v9) != a3 )
  {
    --v8;
    if ( (int)(v9 - 1) >= 0 )
      --v9;
    else
      v9 = v10;
    if ( !v8 )
      goto LABEL_11;
  }
  *(_DWORD *)(a1 + 48) = v9;
  mutex_unlock(a1 + 80);
  if ( v9 == -22 || !a2[1] )
    goto LABEL_17;
  mutex_lock(a1 + 80);
  if ( (*(_BYTE *)(a3 + 48) & 0x10) != 0 )
  {
    v11 = a4;
    v12 = a2;
    if ( v9 < *(_DWORD *)(a1 + 36) )
    {
      v14 = *(_QWORD *)(a2[1] + 32LL * (int)v9 + 8);
      if ( v14 )
      {
        drm_property_blob_put(v14);
        LODWORD(v11) = a4;
      }
      v15 = (unsigned int *)drm_property_lookup_blob(*(_QWORD *)(a1 + 8), (unsigned int)v11);
      v11 = a4;
      if ( !a4 || v15 )
      {
        if ( v15 )
        {
          v16 = v15;
          _drm_dev_dbg(0, 0, 1, "Blob %u saved\n", *v15);
          v11 = *v16;
          v15 = v16;
        }
        v12 = a2;
        *(_QWORD *)(a2[1] + 32LL * (int)v9 + 8) = v15;
      }
      else
      {
        _drm_err("prop %d blob id 0x%llx not found\n", v9, a4);
        v11 = 0;
        v12 = a2;
      }
    }
  }
  else
  {
    v11 = a4;
    v12 = a2;
  }
  v17 = (_QWORD *)(v12[1] + 32LL * (int)v9);
  if ( *v17 != v11 || *(_BYTE *)(*(_QWORD *)(a1 + 24) + 16LL * (int)v9 + 8) == 1 )
  {
    *v17 = v11;
    v18 = v12[1];
    if ( v18 && *(_DWORD *)(a1 + 32) > v9 )
    {
      v19 = v11;
      v20 = v18 + 32LL * v9;
      v22 = *(_QWORD **)(v20 + 16);
      v21 = (_QWORD *)(v20 + 16);
      if ( v22 == v21 )
      {
        v23 = v12 + 2;
        v24 = (_QWORD *)v12[3];
        if ( v21 == v12 + 2 || v24 == v21 || (_QWORD *)*v24 != v23 )
        {
          _list_add_valid_or_report(v21, v24);
        }
        else
        {
          v12[3] = v21;
          *v21 = v23;
          v21[1] = v24;
          *v24 = v21;
        }
      }
      else
      {
        _drm_dev_dbg(0, 0, 2, "property %u already dirty\n", v9);
      }
    }
    else
    {
      v19 = v11;
      _drm_err("invalid argument(s), idx %u\n", v9);
    }
    _drm_dev_dbg(0, 0, 1, "%s - %lld\n", (const char *)(a3 + 52), v19);
  }
  mutex_unlock(a1 + 80);
  return 0;
}
