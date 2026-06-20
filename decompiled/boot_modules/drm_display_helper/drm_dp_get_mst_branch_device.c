_DWORD *__fastcall drm_dp_get_mst_branch_device(__int64 a1, unsigned __int8 a2, unsigned __int8 *a3)
{
  unsigned int v7; // w9
  _QWORD *v9; // x13
  __int64 v10; // x8
  __int64 v11; // x0
  unsigned int v12; // w8
  unsigned int v13; // w21
  unsigned int v18; // w9
  __int64 v19; // x8
  __int64 v20; // x1

  mutex_lock(a1 + 800);
  _X20 = *(_DWORD **)(a1 + 904);
  if ( !_X20 )
    goto LABEL_29;
  if ( a2 >= 2u )
  {
    v7 = 0;
LABEL_5:
    v9 = _X20 + 10;
    do
    {
      v9 = (_QWORD *)*v9;
      if ( v9 == (_QWORD *)(_X20 + 10) )
      {
LABEL_4:
        if ( v7++ == a2 - 2 )
          goto LABEL_11;
        goto LABEL_5;
      }
    }
    while ( ((a3[(unsigned __int64)v7 >> 1] >> (~(4 * v7) & 4)) & 0xF) != *((_BYTE *)v9 - 16) );
    _X20 = (_DWORD *)v9[2];
    if ( _X20 )
      goto LABEL_4;
    v10 = *(_QWORD *)(a1 + 104);
    if ( v10 )
      v11 = *(_QWORD *)(v10 + 8);
    else
      v11 = 0;
    dev_err(v11, "[drm] *ERROR* failed to lookup MSTB with lct %d, rad %02x\n", a2, *a3);
    goto LABEL_28;
  }
LABEL_11:
  v12 = *_X20;
  if ( *_X20 )
  {
    do
    {
      __asm { PRFM            #0x11, [X20] }
      do
        v18 = __ldxr(_X20);
      while ( v18 == v12 && __stxr(v12 + 1, _X20) );
      v13 = v12;
      if ( v18 == v12 )
        break;
      v13 = 0;
      v12 = v18;
    }
    while ( v18 );
  }
  else
  {
    v13 = 0;
  }
  if ( (((v13 + 1) | v13) & 0x80000000) != 0 )
  {
    refcount_warn_saturate(_X20, 0);
    if ( v13 )
      goto LABEL_22;
LABEL_28:
    _X20 = nullptr;
    goto LABEL_29;
  }
  if ( !v13 )
    goto LABEL_28;
LABEL_22:
  v19 = *(_QWORD *)(*((_QWORD *)_X20 + 8) + 104LL);
  if ( v19 )
    v20 = *(_QWORD *)(v19 + 8);
  else
    v20 = 0;
  _drm_dev_dbg(0, v20, 1, "mstb %p (%d)\n", _X20, *_X20);
LABEL_29:
  mutex_unlock(a1 + 800);
  return _X20;
}
