__int64 __fastcall dp_mst_fixed_atomic_best_encoder(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v4; // x8
  __int64 v6; // x22
  int v7; // w20
  __int64 v8; // x21
  unsigned __int64 private_obj_state; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v12; // x0
  unsigned __int64 v13; // x20

  v3 = *(_QWORD *)(a3 + 16);
  if ( v3 )
    return v3;
  v4 = *(_QWORD *)(a2 + 40);
  if ( *(_QWORD *)(v4 + 2720) == a1 )
  {
    v7 = 0;
    v6 = v4 + 1336;
  }
  else
  {
    if ( *(_QWORD *)(v4 + 4112) != a1 )
      goto LABEL_12;
    v6 = v4 + 2728;
    v7 = 1;
  }
  v8 = *(_QWORD *)(a3 + 32);
  if ( (mutex_is_locked(*(_QWORD *)(v6 + 104) + 480LL) & 1) == 0 )
    __break(0x800u);
  private_obj_state = drm_atomic_get_private_obj_state(v8, v6 + 296);
  if ( private_obj_state <= 0xFFFFFFFFFFFFF000LL )
  {
    *(_QWORD *)(private_obj_state + 16) = a1;
    *(_QWORD *)(private_obj_state + 24) = *(_QWORD *)(a1 + 2768);
    v3 = *(_QWORD *)(v6 + 416);
    if ( v3 )
    {
      ipc_log_context = get_ipc_log_context();
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(
        ipc_log_context,
        "[d][%-4d]mst connector:%d atomic best encoder:%d\n",
        *(_DWORD *)(StatusReg + 1800),
        *(_DWORD *)(a1 + 64),
        v7);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]mst connector:%d atomic best encoder:%d\n",
          *(_DWORD *)(StatusReg + 1800),
          *(_DWORD *)(a1 + 64),
          v7);
      return v3;
    }
  }
LABEL_12:
  v12 = get_ipc_log_context();
  v13 = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v12,
    "[d][%-4d]mst connector:%d atomic best encoder failed\n",
    *(_DWORD *)(v13 + 1800),
    *(_DWORD *)(a1 + 64));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]mst connector:%d atomic best encoder failed\n",
      *(_DWORD *)(v13 + 1800),
      *(_DWORD *)(a1 + 64));
  return 0;
}
