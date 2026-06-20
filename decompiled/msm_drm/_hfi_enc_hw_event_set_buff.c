__int64 __fastcall hfi_enc_hw_event_set_buff(int *a1, int a2, char a3)
{
  __int64 v5; // x24
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x22
  __int64 connector; // x0
  int v10; // w21
  _QWORD *cmd_buf; // x0
  int v12; // w22
  __int64 v13; // x23
  unsigned int property; // w0
  int v15; // w0
  int v16; // w4
  unsigned int v17; // w19
  __int64 result; // x0
  void *v19; // x0
  int v20; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *((_QWORD *)a1 + 622);
  v20 = a2;
  if ( !a1 || !*(_QWORD *)a1 )
  {
    v19 = &unk_26FCAB;
    goto LABEL_20;
  }
  v6 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v6 || (v7 = *(_QWORD *)(v6 + 8)) == 0 )
  {
    v19 = &unk_234896;
LABEL_20:
    printk(v19, "sde_encoder_get_kms");
    v7 = 0;
    if ( v5 )
      goto LABEL_6;
LABEL_21:
    printk(&unk_242658, "_hfi_enc_hw_event_set_buff");
    result = 4294967274LL;
    goto LABEL_17;
  }
  if ( !v5 )
    goto LABEL_21;
LABEL_6:
  v8 = *(_QWORD *)(v7 + 6440);
  if ( !v8 )
    goto LABEL_21;
  connector = sde_encoder_get_connector(*(_QWORD *)a1, a1);
  if ( !connector )
    goto LABEL_21;
  v10 = *(_DWORD *)(connector + 2740);
  cmd_buf = hfi_adapter_get_cmd_buf(v8 + 8);
  if ( !cmd_buf )
  {
    printk(&unk_26FCD5, "_hfi_enc_hw_event_set_buff");
    result = 4294967274LL;
    goto LABEL_17;
  }
  if ( (a3 & 1) != 0 )
    v12 = 33554436;
  else
    v12 = 33554437;
  v13 = (__int64)cmd_buf;
  property = hfi_adapter_add_get_property((__int64)cmd_buf, v12, v10, 1u, (__int64)&v20, 4u, v5 + 112, 4);
  if ( property )
  {
    v17 = property;
    printk(&unk_279CA2, "_hfi_enc_hw_event_set_buff");
LABEL_25:
    result = v17;
    goto LABEL_17;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "sending events enable:%d for display:%d\n", a3 & 1, v10);
  v15 = hfi_adapter_set_cmd_buf(v13);
  v16 = a1[6];
  v17 = v15;
  sde_evtlog_log(sde_dbg_base_evtlog, "_hfi_enc_hw_event_set_buff", 282, -1, v16, v10, v12, v15, 51);
  if ( v17 )
  {
    printk(&unk_2653D7, "_hfi_enc_hw_event_set_buff");
    goto LABEL_25;
  }
  result = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
