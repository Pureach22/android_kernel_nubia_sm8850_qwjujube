__int64 __fastcall msm_property_atomic_get(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  int v8; // w8
  int v9; // w23
  int v10; // w10

  if ( a1 && a3 )
  {
    mutex_lock(a1 + 80);
    v8 = *(_DWORD *)(a1 + 32);
    if ( v8 )
    {
      v9 = *(_DWORD *)(a1 + 48);
      v10 = v8 - 1;
      while ( *(_QWORD *)(*(_QWORD *)(a1 + 16) + 8LL * v9) != a3 )
      {
        --v8;
        if ( v9 - 1 >= 0 )
          --v9;
        else
          v9 = v10;
        if ( !v8 )
          goto LABEL_10;
      }
      *(_DWORD *)(a1 + 48) = v9;
      mutex_unlock(a1 + 80);
      if ( v9 != -22 && a4 && *(_QWORD *)(a2 + 8) )
      {
        mutex_lock(a1 + 80);
        *a4 = *(_QWORD *)(*(_QWORD *)(a2 + 8) + 32LL * v9);
        mutex_unlock(a1 + 80);
        return 0;
      }
    }
    else
    {
LABEL_10:
      mutex_unlock(a1 + 80);
    }
  }
  else
  {
    _drm_err("invalid argument(s)\n");
  }
  _drm_dev_dbg(0, 0, 0, "Invalid argument(s)\n");
  return 4294967274LL;
}
