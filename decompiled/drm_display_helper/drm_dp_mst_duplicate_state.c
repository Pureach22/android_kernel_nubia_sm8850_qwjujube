__int64 __fastcall drm_dp_mst_duplicate_state(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x19
  __int64 v4; // x21
  _QWORD *v5; // x20
  _QWORD *v6; // x24
  _QWORD *v7; // t1
  _QWORD *v8; // x0
  _QWORD *v9; // x23
  __int64 v10; // x4
  __int64 v12; // x8
  __int64 v13; // x1
  _QWORD *v14; // x2
  _QWORD *v15; // x0
  __int64 v16; // x28
  __int64 v17; // x1
  unsigned int v23; // w8
  _QWORD *v24; // x20
  _QWORD *v25; // x22

  v1 = *(_QWORD *)(a1 + 88);
  v3 = kmemdup_noprof(v1, 80, 3264);
  if ( !v3 )
    return v3;
  _drm_atomic_helper_private_obj_duplicate_state(a1, v3);
  v4 = v3 + 56;
  *(_QWORD *)(v3 + 56) = v3 + 56;
  *(_QWORD *)(v3 + 64) = v3 + 56;
  *(_DWORD *)(v3 + 24) = 0;
  *(_QWORD *)(v3 + 32) = 0;
  *(_QWORD *)(v3 + 40) = 0;
  v7 = *(_QWORD **)(v1 + 56);
  v5 = (_QWORD *)(v1 + 56);
  v6 = v7;
  if ( v7 == v5 )
    return v3;
  _ReadStatusReg(SP_EL0);
  while ( (*((_BYTE *)v6 - 12) & 1) != 0 )
  {
LABEL_5:
    v6 = (_QWORD *)*v6;
    if ( v6 == v5 )
      return v3;
  }
  v8 = (_QWORD *)kmemdup_noprof(v6 - 4, 48, 3264);
  v9 = v8;
  if ( v8 )
  {
    v10 = *v8;
    _X0 = (unsigned int *)(*v8 + 4LL);
    __asm { PRFM            #0x11, [X0] }
    do
      v23 = __ldxr(_X0);
    while ( __stxr(v23 + 1, _X0) );
    if ( v23 )
    {
      if ( (((v23 + 1) | v23) & 0x80000000) == 0 )
      {
LABEL_10:
        v12 = *(_QWORD *)(*(_QWORD *)(v10 + 1632) + 104LL);
        if ( v12 )
          v13 = *(_QWORD *)(v12 + 8);
        else
          v13 = 0;
        _drm_dev_dbg(0, v13, 1, "port %p (%d)\n", (const void *)v10, *(_DWORD *)(v10 + 4));
        v14 = *(_QWORD **)v4;
        v15 = v9 + 4;
        if ( *(_QWORD *)(*(_QWORD *)v4 + 8LL) != v4 || v15 == (_QWORD *)v4 || v14 == v15 )
        {
          _list_add_valid_or_report(v15);
        }
        else
        {
          v14[1] = v15;
          v9[4] = v14;
          v9[5] = v4;
          *(_QWORD *)v4 = v15;
        }
        goto LABEL_5;
      }
      v16 = v10;
      v17 = 1;
    }
    else
    {
      v16 = v10;
      v17 = 2;
    }
    refcount_warn_saturate(_X0, v17);
    v10 = v16;
    goto LABEL_10;
  }
  v24 = *(_QWORD **)v4;
  if ( *(_QWORD *)v4 != v4 )
  {
    do
    {
      v25 = (_QWORD *)*v24;
      drm_dp_mst_put_port_malloc(*(v24 - 4));
      kfree(v24 - 4);
      v24 = v25;
    }
    while ( v25 != (_QWORD *)v4 );
  }
  kfree(v3);
  return 0;
}
