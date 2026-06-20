__int64 __fastcall dp_mst_atomic_best_encoder(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  _QWORD *v4; // x21
  __int64 v6; // x20
  unsigned __int64 private_obj_state; // x0
  _QWORD *v9; // x23
  __int64 v10; // x20
  unsigned __int64 v11; // x0
  __int64 v12; // x20
  __int64 v13; // x0
  __int64 v14; // x20
  int v15; // w20
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v18; // x0
  unsigned __int64 v19; // x20

  v3 = *(_QWORD *)(a3 + 16);
  if ( v3 )
    return v3;
  v4 = *(_QWORD **)(a2 + 40);
  v6 = *(_QWORD *)(a3 + 32);
  if ( (mutex_is_locked(v4[180] + 480LL) & 1) == 0 )
    __break(0x800u);
  private_obj_state = drm_atomic_get_private_obj_state(v6, v4 + 204);
  if ( private_obj_state > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_26;
  v9 = v4 + 167;
  if ( *(_QWORD *)(private_obj_state + 16) == a1 )
  {
    v15 = 0;
  }
  else
  {
    v10 = *(_QWORD *)(a3 + 32);
    if ( (mutex_is_locked(v4[354] + 480LL) & 1) == 0 )
      __break(0x800u);
    v11 = drm_atomic_get_private_obj_state(v10, v4 + 378);
    if ( v11 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_26;
    if ( *(_QWORD *)(v11 + 16) == a1 )
    {
      v15 = 1;
      v9 = v4 + 341;
    }
    else
    {
      if ( v4[340] )
        goto LABEL_32;
      v12 = *(_QWORD *)(a3 + 32);
      if ( (mutex_is_locked(v4[180] + 480LL) & 1) == 0 )
        __break(0x800u);
      v13 = drm_atomic_get_private_obj_state(v12, v4 + 204);
      if ( *(_QWORD *)(v13 + 16) )
      {
LABEL_32:
        if ( v4[514] )
          goto LABEL_26;
        v14 = *(_QWORD *)(a3 + 32);
        if ( (mutex_is_locked(v4[354] + 480LL) & 1) == 0 )
          __break(0x800u);
        v13 = drm_atomic_get_private_obj_state(v14, v4 + 378);
        if ( *(_QWORD *)(v13 + 16) )
          goto LABEL_26;
        v15 = 1;
        v9 = v4 + 341;
      }
      else
      {
        v15 = 0;
      }
      *(_QWORD *)(v13 + 16) = a1;
      *(_QWORD *)(v13 + 24) = *(_QWORD *)(a1 + 2768);
    }
  }
  v3 = v9[52];
  if ( v3 )
  {
    ipc_log_context = get_ipc_log_context();
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      ipc_log_context,
      "[d][%-4d]mst connector:%d atomic best encoder:%d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(a1 + 64),
      v15);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]mst connector:%d atomic best encoder:%d\n",
        *(_DWORD *)(StatusReg + 1800),
        *(_DWORD *)(a1 + 64),
        v15);
    return v3;
  }
LABEL_26:
  v18 = get_ipc_log_context();
  v19 = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v18,
    "[d][%-4d]mst connector:%d atomic best encoder failed\n",
    *(_DWORD *)(v19 + 1800),
    *(_DWORD *)(a1 + 64));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]mst connector:%d atomic best encoder failed\n",
      *(_DWORD *)(v19 + 1800),
      *(_DWORD *)(a1 + 64));
  return 0;
}
