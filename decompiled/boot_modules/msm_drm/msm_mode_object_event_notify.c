__int64 __fastcall msm_mode_object_event_notify(_DWORD *a1, _QWORD *a2, _DWORD *a3, const void *a4)
{
  int v4; // s11
  int v8; // w3
  __int64 v9; // x23
  __int64 v11; // x0
  __int64 *v12; // x28
  int v13; // w2
  int v14; // w1
  int v15; // w3
  unsigned __int64 v16; // x26
  __int64 v17; // x0
  size_t v18; // x1
  size_t v19; // x2
  __int64 v20; // x25
  unsigned __int64 v21; // x1
  __int64 v22; // x8
  __int64 v23; // x10
  __int64 v24; // x11
  __int64 v26; // x0
  int v27; // s4
  __int64 v28; // [xsp+18h] [xbp-8h]

  if ( !a1 || !a3 )
  {
    if ( a3 )
      v8 = a3[1];
    else
      v8 = -1;
    return _drm_err("err param obj %pK event %pK len %d payload %pK\n", a1, a3, v8, a4);
  }
  v8 = a3[1];
  if ( !a4 || !v8 )
    return _drm_err("err param obj %pK event %pK len %d payload %pK\n", a1, a3, v8, a4);
  if ( !a2 )
    return _drm_err("invalid dev %pK priv %pK\n", a2, nullptr);
  v9 = a2[7];
  if ( !v9 )
    return _drm_err("invalid dev %pK priv %pK\n", a2, nullptr);
  v11 = raw_spin_lock_irqsave(a2 + 53);
  v12 = *(__int64 **)(v9 + 5664);
  v28 = v11;
  if ( v12 == (__int64 *)(v9 + 5664) )
    return raw_spin_unlock_irqrestore(a2 + 53, v28);
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v13 = *((_DWORD *)v12 + 8);
    if ( v13 != *a3 || *a1 != *((_DWORD *)v12 + 10) )
      goto LABEL_12;
    v14 = *(_DWORD *)(*(v12 - 1) + 296);
    v15 = a3[1] + 112;
    if ( v14 < v15 )
    {
      _drm_err("Insufficient space %d for event %x len %d\n", v14, v13, v15);
      goto LABEL_12;
    }
    v16 = v15;
    v17 = _kmalloc_noprof(v15, 2336);
    v20 = v17;
    if ( !v17 )
      goto LABEL_12;
    if ( v16 < 0x20 )
      break;
    if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) == 0x20 )
      break;
    *(_QWORD *)(v17 + 32) = *(v12 - 1);
    if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) == 0x10 )
      break;
    *(_QWORD *)(v17 + 16) = v17 + 72;
    if ( v16 < 0x48 )
      break;
    if ( (v16 & 0xFFFFFFFFFFFFFFFCLL) == 0x48 )
      break;
    *(_DWORD *)(v17 + 72) = *((_DWORD *)v12 + 8);
    if ( v16 < 0x4C || (v16 & 0xFFFFFFFFFFFFFFFCLL) == 0x4C )
      break;
    if ( v16 >= 0x50 )
      v21 = v16 - 80;
    else
      v21 = 0;
    *(_DWORD *)(v17 + 76) = a3[1] + 40;
    if ( v21 <= 0x1F )
      goto LABEL_43;
    v22 = v12[8];
    v23 = v12[5];
    v24 = v12[6];
    if ( v16 >= 0x70 )
      v18 = v16 - 112;
    else
      v18 = 0;
    v19 = (unsigned int)a3[1];
    *(_QWORD *)(v17 + 96) = v12[7];
    *(_QWORD *)(v17 + 104) = v22;
    *(_QWORD *)(v17 + 80) = v23;
    *(_QWORD *)(v17 + 88) = v24;
    if ( v18 < v19 )
      goto LABEL_42;
    memcpy((void *)(v17 + 112), a4, v19);
    if ( (unsigned int)drm_event_reserve_init_locked(a2, *(v12 - 1), v20, v20 + 72) )
      kfree(v20);
    else
      drm_send_event_locked(a2, v20);
LABEL_12:
    v12 = (__int64 *)*v12;
    if ( v12 == (__int64 *)(v9 + 5664) )
      return raw_spin_unlock_irqrestore(a2 + 53, v28);
  }
  __break(1u);
LABEL_42:
  _fortify_panic(17, v18, v19);
LABEL_43:
  v26 = _fortify_panic(17, v21, 32);
  *(_DWORD *)v12 = v27;
  *((_DWORD *)v12 + 1) = v4;
  return msm_drm_register_component(v26);
}
