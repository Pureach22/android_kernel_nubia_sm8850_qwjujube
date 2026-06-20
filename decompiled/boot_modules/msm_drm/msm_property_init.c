void *__fastcall msm_property_init(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        void *a5,
        unsigned int a6,
        unsigned int a7,
        int a8)
{
  __int64 v10; // x21
  __int64 v11; // x22
  __int64 v12; // x23
  __int64 v13; // x24
  int v14; // w25

  if ( !a2 || !a3 || !a4 || !a5 )
    return (void *)_drm_err("invalid arguments, forcing zero properties\n");
  if ( a7 > a6 )
  {
    v10 = a1;
    v11 = a2;
    v12 = a3;
    v13 = a4;
    v14 = a8;
    _drm_dev_dbg(0, 0, 1, "Capping number of blob properties to %d\n", a6);
    a3 = v12;
    a4 = v13;
    a2 = v11;
    a1 = v10;
    a8 = v14;
    a7 = a6;
  }
  if ( !a1 )
    return (void *)_drm_err("info pointer is NULL\n");
  *(_QWORD *)a1 = a2;
  *(_QWORD *)(a1 + 8) = a3;
  *(_QWORD *)(a1 + 16) = a4;
  *(_QWORD *)(a1 + 24) = a5;
  *(_DWORD *)(a1 + 32) = a6;
  *(_DWORD *)(a1 + 36) = a7;
  *(_QWORD *)(a1 + 40) = 0;
  *(_QWORD *)(a1 + 45) = 0;
  *(_DWORD *)(a1 + 72) = a8;
  *(_DWORD *)(a1 + 76) = 0;
  _mutex_init(a1 + 80, "&info->property_lock", &msm_property_init___key);
  return memset(a5, 0, 16LL * a6);
}
