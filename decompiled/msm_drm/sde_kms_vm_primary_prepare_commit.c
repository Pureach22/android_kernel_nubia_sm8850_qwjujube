__int64 __fastcall sde_kms_vm_primary_prepare_commit(__int64 a1, __int64 a2)
{
  __int64 v2; // x23
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x21
  _QWORD *v6; // x9
  int v7; // w4
  __int64 *v8; // x19
  __int64 v9; // x10
  __int64 result; // x0
  __int64 v11; // x20
  __int64 v12; // x22
  __int64 v13; // x8
  unsigned int v14; // w22
  __int64 v15; // x8
  __int64 v16; // x1
  __int64 v17; // x0
  __int64 v18; // x8
  void (__fastcall *v19)(__int64, __int64); // x9
  __int64 v20; // x8
  __int64 *i; // x24
  __int64 v22; // x0
  __int64 (__fastcall *v23)(_QWORD); // x8
  __int64 v24; // x22
  _QWORD v25[2]; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 6384);
  if ( !v2 )
  {
    result = 4294967274LL;
    goto LABEL_41;
  }
  v3 = *(unsigned int *)(*(_QWORD *)(a2 + 8) + 860LL);
  if ( (int)v3 < 1 )
    goto LABEL_40;
  v4 = *(_QWORD *)(a2 + 32);
  v5 = *(_QWORD *)(a1 + 136);
  v25[0] = 0;
  v25[1] = 0;
  v6 = (_QWORD *)(v4 + 16);
  while ( 1 )
  {
    v8 = (__int64 *)*(v6 - 2);
    if ( !v8 )
      goto LABEL_6;
    v9 = v6[1];
    if ( (*(_BYTE *)(v9 + 9) & 1) == 0 )
      break;
    if ( v9 )
      goto LABEL_5;
LABEL_6:
    --v3;
    v6 += 7;
    if ( !v3 )
      goto LABEL_40;
  }
  if ( !v9 || (*(_BYTE *)(*v6 + 9LL) & 1) == 0 )
    goto LABEL_6;
LABEL_5:
  v7 = *(_DWORD *)(v9 + 1568);
  if ( !v7 )
    goto LABEL_6;
  v11 = a1;
  if ( (_drm_debug & 4) != 0 )
  {
    v12 = a2;
    _drm_dev_dbg(0, 0, 0, "valid vm request:%d found on crtc-%d\n", v7, *((_DWORD *)v8 + 28));
    a2 = v12;
    a1 = v11;
  }
  if ( a1 && (v13 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 56LL)) != 0 )
  {
    v14 = *(_DWORD *)(v13 + 5912);
  }
  else
  {
    v24 = a2;
    printk(&unk_25E374, "sde_kms_get_disp_op");
    a2 = v24;
    v14 = 0;
  }
  v15 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 56LL * *((unsigned int *)v8 + 40) + 24);
  if ( !v15 || *(_DWORD *)(v15 + 1568) != 2 )
    goto LABEL_40;
  sde_irq_update(v11, 1);
  v17 = *(_QWORD *)(v11 + 1896);
  v18 = v11;
  if ( !v17 )
    goto LABEL_26;
  if ( v14 > 2 )
  {
    __break(0x5512u);
    return ((__int64 (*)(void))sde_kms_remove_pm_qos_irq_request)();
  }
  v19 = *(void (__fastcall **)(__int64, __int64))(v17 + 8LL * v14 + 104);
  if ( v19 )
  {
    if ( *((_DWORD *)v19 - 1) != 1946677504 )
      __break(0x8229u);
    v19(v17, v16);
    v18 = v11;
  }
LABEL_26:
  v26[0] = 0xFFFFFFFFLL;
  sde_kms_remove_pm_qos_irq_request(v18, v26);
  v20 = *v8;
  for ( i = *(__int64 **)(*v8 + 816); i != (__int64 *)(v20 + 816); i = (__int64 *)*i )
  {
    if ( ((*(_DWORD *)(v8[251] + 20) >> *((_DWORD *)i + 15)) & 1) != 0
      && (((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(i - 1) & 1) == 0 )
    {
      sde_encoder_irq_control((_DWORD *)i - 2, 1);
    }
    v20 = *v8;
  }
  drm_connector_list_iter_begin(v5, v25);
  while ( 1 )
  {
    v22 = drm_connector_list_iter_next(v25);
    if ( !v22 )
      break;
    if ( ((*(_DWORD *)(v8[251] + 16) >> *(_DWORD *)(v22 + 152)) & 1) != 0 )
      sde_connector_schedule_status_work(v22, 1);
  }
  drm_connector_list_iter_end(v25);
  drm_crtc_vblank_on(v8);
  sde_dbg_set_hw_ownership_status(1);
  v23 = *(__int64 (__fastcall **)(_QWORD))(v2 + 136);
  if ( !v23 )
  {
LABEL_40:
    result = 0;
    goto LABEL_41;
  }
  if ( *((_DWORD *)v23 - 1) != 925264262 )
    __break(0x8228u);
  result = v23(v11);
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
