__int64 __fastcall sde_kms_vm_primary_post_commit(__int64 a1, __int64 a2)
{
  __int64 v2; // x23
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  int v7; // w4
  __int64 v8; // x19
  __int64 v9; // x11
  __int64 v11; // x20
  __int64 v12; // x21
  __int64 v13; // x8
  int v14; // w24
  __int64 v15; // x8
  __int64 v16; // x21
  _QWORD *v17; // x25
  _QWORD *v18; // x26
  __int64 v19; // x2
  __int64 v20; // x3
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  int v24; // w7
  __int64 v25; // x22
  __int64 v26; // x0
  __int64 (__fastcall *v27)(_QWORD); // x8
  unsigned int v28; // w0
  __int64 (__fastcall *v29)(_QWORD); // x8
  __int64 v30; // x9
  unsigned int v31; // w0
  unsigned int v32; // w21
  __int64 v33; // x0
  unsigned int v34; // w19
  __int64 v35; // x0

  if ( !a1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(a1 + 6384);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(unsigned int *)(*(_QWORD *)(a2 + 8) + 860LL);
  if ( (int)v3 < 1 )
    return 0;
  v4 = *(_QWORD *)(a2 + 32);
  v5 = 56 * v3;
  v6 = 0;
  while ( 1 )
  {
    v8 = *(_QWORD *)(v4 + v6);
    if ( !v8 )
      goto LABEL_7;
    v9 = *(_QWORD *)(v4 + v6 + 24);
    if ( (*(_BYTE *)(v9 + 9) & 1) == 0 )
      break;
    if ( v9 )
      goto LABEL_6;
LABEL_7:
    v6 += 56;
    if ( v5 == v6 )
      return 0;
  }
  if ( !v9 || (*(_BYTE *)(*(_QWORD *)(v4 + v6 + 16) + 9LL) & 1) == 0 )
    goto LABEL_7;
LABEL_6:
  v7 = *(_DWORD *)(v9 + 1568);
  if ( !v7 )
    goto LABEL_7;
  v11 = a1;
  if ( (_drm_debug & 4) != 0 )
  {
    v12 = a2;
    _drm_dev_dbg(0, 0, 0, "valid vm request:%d found on crtc-%d\n", v7, *(_DWORD *)(v8 + 112));
    v4 = *(_QWORD *)(v12 + 32);
    a2 = v12;
    a1 = v11;
  }
  v13 = *(_QWORD *)(v4 + 56LL * *(unsigned int *)(v8 + 160) + 24);
  if ( !v13 )
    return 0;
  v14 = *(_DWORD *)(v13 + 1568);
  if ( !v14 )
    return 0;
  v15 = *(_QWORD *)(a1 + 136);
  v16 = a2;
  v17 = *(_QWORD **)(v15 + 816);
  v18 = (_QWORD *)(v15 + 816);
  while ( v17 != v18 )
  {
    if ( sde_encoder_is_dsi_display((_BOOL8)(v17 - 1)) )
      sde_encoder_control_idle_pc((__int64)(v17 - 1), v14 != 1, v19, v20, v21, v22, v23, v24);
    v17 = (_QWORD *)*v17;
  }
  if ( v14 != 1 )
    return 0;
  v25 = v11;
  ((void (__fastcall *)(__int64, __int64, __int64))sde_kms_vm_pre_release)(v11, v16, 1);
  sde_cp_crtc_vm_primary_handoff(v8);
  v26 = *(_QWORD *)(v11 + 6384);
  if ( v26 )
  {
    mutex_lock(v26);
    v25 = v11;
  }
  v27 = *(__int64 (__fastcall **)(_QWORD))(v2 + 128);
  if ( !v27 )
    goto LABEL_31;
  if ( *((_DWORD *)v27 - 1) != 925264262 )
    __break(0x8228u);
  v28 = v27(v11);
  v25 = v11;
  if ( v28 )
  {
    v34 = v28;
    printk(&unk_25EB65, "sde_kms_vm_primary_post_commit");
    v35 = *(_QWORD *)(v11 + 6384);
    if ( v35 )
      mutex_unlock(v35);
    return v34;
  }
  else
  {
LABEL_31:
    sde_irq_update(v25, 0);
    v29 = *(__int64 (__fastcall **)(_QWORD))(v2 + 80);
    if ( !v29 )
      goto LABEL_37;
    v30 = *(_QWORD *)(v11 + 6384);
    if ( v30 )
    {
      *(_QWORD *)(v30 + 264) = v8;
      v29 = *(__int64 (__fastcall **)(_QWORD))(v2 + 80);
    }
    if ( *((_DWORD *)v29 - 1) != 925264262 )
      __break(0x8228u);
    v31 = v29(v11);
    if ( v31 )
    {
      v32 = v31;
      printk(&unk_23BDB4, "sde_kms_vm_primary_post_commit");
      v33 = *(_QWORD *)(v11 + 6384);
      if ( v33 )
LABEL_38:
        mutex_unlock(v33);
    }
    else
    {
LABEL_37:
      v32 = 0;
      v33 = *(_QWORD *)(v11 + 6384);
      if ( v33 )
        goto LABEL_38;
    }
    sde_crtc_vm_release_notify((__int64 *)v8);
    return v32;
  }
}
