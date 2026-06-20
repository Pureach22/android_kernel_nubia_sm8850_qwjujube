__int64 __fastcall msm_property_set_dirty(__int64 a1, _QWORD *a2, unsigned int a3)
{
  __int64 v6; // x9
  __int64 v7; // x0
  _QWORD *v8; // x0
  _QWORD *v9; // t1
  _QWORD *v11; // x2
  _QWORD *v12; // x1

  if ( a1 && a2 && a2[1] )
  {
    mutex_lock(a1 + 80);
    v6 = a2[1];
    if ( v6 && *(_DWORD *)(a1 + 32) > a3 )
    {
      v7 = v6 + 32LL * a3;
      v9 = *(_QWORD **)(v7 + 16);
      v8 = (_QWORD *)(v7 + 16);
      if ( v9 == v8 )
      {
        v11 = a2 + 2;
        v12 = (_QWORD *)a2[3];
        if ( v8 == a2 + 2 || v12 == v8 || (_QWORD *)*v12 != v11 )
        {
          _list_add_valid_or_report(v8, v12);
        }
        else
        {
          a2[3] = v8;
          *v8 = v11;
          v8[1] = v12;
          *v12 = v8;
        }
      }
      else
      {
        _drm_dev_dbg(0, 0, 2, "property %u already dirty\n", a3);
      }
    }
    else
    {
      _drm_err("invalid argument(s), idx %u\n", a3);
    }
    mutex_unlock(a1 + 80);
    return 0;
  }
  else
  {
    _drm_err("invalid argument(s)\n");
    return 4294967274LL;
  }
}
