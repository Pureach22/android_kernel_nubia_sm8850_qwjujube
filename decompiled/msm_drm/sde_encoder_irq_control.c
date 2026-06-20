_DWORD *__fastcall sde_encoder_irq_control(_DWORD *result, char a2)
{
  _DWORD *v2; // x20
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 v6; // x22
  _DWORD *v7; // x8
  __int64 v8; // x0
  _DWORD *v9; // x8
  __int64 v10; // x22
  _DWORD *v11; // x8
  __int64 v12; // x0
  _DWORD *v13; // x8
  __int64 v14; // x22
  _DWORD *v15; // x8
  __int64 v16; // x0
  _DWORD *v17; // x8
  __int64 v18; // x22
  _DWORD *v19; // x8
  __int64 v20; // x0
  _DWORD *v21; // x8
  void *v22; // x0
  void *v23; // x0

  if ( !result )
  {
    v23 = &unk_26FCAB;
    return (_DWORD *)printk(v23, "sde_encoder_irq_control");
  }
  v2 = result;
  if ( !*(_QWORD *)result )
  {
    v22 = &unk_26FCAB;
    goto LABEL_53;
  }
  v3 = *(_QWORD *)(*(_QWORD *)result + 56LL);
  if ( !v3 || (v4 = *(_QWORD *)(v3 + 8)) == 0 )
  {
    v22 = &unk_234896;
LABEL_53:
    printk(v22, "sde_encoder_get_kms");
    v23 = &unk_234896;
    return (_DWORD *)printk(v23, "sde_encoder_irq_control");
  }
  if ( (_drm_debug & 4) != 0 )
    result = (_DWORD *)_drm_dev_dbg(0, 0, 0, "enc%d enable:%d\n", result[6], a2 & 1);
  if ( !v2[49] )
    goto LABEL_59;
  v6 = *((_QWORD *)v2 + 25);
  if ( v6 )
  {
    v7 = *(_DWORD **)(v6 + 224);
    if ( v7 )
    {
      v8 = *((_QWORD *)v2 + 25);
      if ( *(v7 - 1) != 1595431362 )
        __break(0x8228u);
      result = (_DWORD *)((__int64 (__fastcall *)(__int64, _QWORD))v7)(v8, a2 & 1);
    }
    v9 = *(_DWORD **)(v6 + 232);
    if ( v9 )
    {
      if ( *(v9 - 1) != 1595431362 )
        __break(0x8228u);
      result = (_DWORD *)((__int64 (__fastcall *)(__int64, _QWORD))v9)(v6, a2 & 1);
    }
  }
  if ( v2[49] < 2u )
    goto LABEL_59;
  v10 = *((_QWORD *)v2 + 26);
  if ( v10 )
  {
    v11 = *(_DWORD **)(v10 + 224);
    if ( v11 )
    {
      v12 = *((_QWORD *)v2 + 26);
      if ( *(v11 - 1) != 1595431362 )
        __break(0x8228u);
      result = (_DWORD *)((__int64 (__fastcall *)(__int64, _QWORD))v11)(v12, a2 & 1);
    }
    v13 = *(_DWORD **)(v10 + 232);
    if ( v13 )
    {
      if ( *(v13 - 1) != 1595431362 )
        __break(0x8228u);
      result = (_DWORD *)((__int64 (__fastcall *)(__int64, _QWORD))v13)(v10, a2 & 1);
    }
  }
  if ( v2[49] < 3u )
    goto LABEL_59;
  v14 = *((_QWORD *)v2 + 27);
  if ( v14 )
  {
    v15 = *(_DWORD **)(v14 + 224);
    if ( v15 )
    {
      v16 = *((_QWORD *)v2 + 27);
      if ( *(v15 - 1) != 1595431362 )
        __break(0x8228u);
      result = (_DWORD *)((__int64 (__fastcall *)(__int64, _QWORD))v15)(v16, a2 & 1);
    }
    v17 = *(_DWORD **)(v14 + 232);
    if ( v17 )
    {
      if ( *(v17 - 1) != 1595431362 )
        __break(0x8228u);
      result = (_DWORD *)((__int64 (__fastcall *)(__int64, _QWORD))v17)(v14, a2 & 1);
    }
  }
  if ( v2[49] < 4u )
    goto LABEL_59;
  v18 = *((_QWORD *)v2 + 28);
  if ( v18 )
  {
    v19 = *(_DWORD **)(v18 + 224);
    if ( v19 )
    {
      v20 = *((_QWORD *)v2 + 28);
      if ( *(v19 - 1) != 1595431362 )
        __break(0x8228u);
      result = (_DWORD *)((__int64 (__fastcall *)(__int64, _QWORD))v19)(v20, a2 & 1);
    }
    v21 = *(_DWORD **)(v18 + 232);
    if ( v21 )
    {
      if ( *(v21 - 1) != 1595431362 )
        __break(0x8228u);
      result = (_DWORD *)((__int64 (__fastcall *)(__int64, _QWORD))v21)(v18, a2 & 1);
    }
  }
  if ( v2[49] > 4u )
  {
    __break(0x5512u);
    return (_DWORD *)sde_encoder_get_rsc_client(result);
  }
  else
  {
LABEL_59:
    if ( !*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 136) + 56LL) + 5912LL) )
      return (_DWORD *)sde_kms_cpu_vote_for_irq(v4, a2 & 1);
  }
  return result;
}
