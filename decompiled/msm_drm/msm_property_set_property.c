__int64 __fastcall msm_property_set_property(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  _QWORD *v8; // x8
  __int64 v9; // x20
  _QWORD *v10; // x22
  __int64 result; // x0
  unsigned int v12; // w20

  if ( a1 && *(_DWORD *)(a1 + 32) > a3 && a2 && *(_DWORD *)(a1 + 36) <= a3 && *(_QWORD *)(a2 + 8) )
  {
    mutex_lock(a1 + 80);
    v8 = (_QWORD *)a1;
    *(_QWORD *)(*(_QWORD *)(a2 + 8) + 32LL * a3) = a4;
    v9 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 8LL * a3);
    if ( (*(_BYTE *)(v9 + 48) & 4) != 0 )
      *(_QWORD *)(v8[3] + 16LL * a3) = a4;
    v10 = v8;
    mutex_unlock(v8 + 10);
    result = drm_object_property_set_value(*v10, v9, a4);
    if ( (_DWORD)result )
    {
      v12 = result;
      _drm_err("failed set property value, idx %d rc %d\n", a3, result);
      return v12;
    }
  }
  else
  {
    _drm_err("invalid argument(s)\n");
    return 4294967274LL;
  }
  return result;
}
