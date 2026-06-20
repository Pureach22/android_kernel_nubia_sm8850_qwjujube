__int64 __fastcall hfi_enc_set_panic_events(_QWORD *a1, char a2)
{
  _QWORD *v3; // x23
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x21
  _QWORD *v7; // x20
  __int64 connector; // x0
  unsigned int v9; // w22
  __int64 cmd_buf; // x0
  unsigned int property; // w0
  __int64 result; // x0
  void *v13; // x0
  void *v14; // x0
  unsigned int v15; // w19
  _DWORD v16[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (_QWORD *)a1[622];
  if ( !a1 || !*a1 )
  {
    v13 = &unk_26FCAB;
    goto LABEL_14;
  }
  v4 = *(_QWORD *)(*a1 + 56LL);
  if ( !v4 || (v5 = *(_QWORD *)(v4 + 8)) == 0 )
  {
    v13 = &unk_234896;
LABEL_14:
    printk(v13, "sde_encoder_get_kms");
    v5 = 0;
    if ( !v3 )
      goto LABEL_15;
    goto LABEL_6;
  }
  if ( !v3 )
  {
LABEL_15:
    v14 = &unk_22A7AB;
LABEL_18:
    printk(v14, "hfi_enc_set_panic_events");
    result = 4294967274LL;
    goto LABEL_11;
  }
LABEL_6:
  v6 = *(_QWORD *)(v5 + 6440);
  if ( !v6 )
    goto LABEL_15;
  v7 = (_QWORD *)*v3;
  connector = sde_encoder_get_connector(*(_QWORD *)*v3, *v3);
  if ( !connector )
  {
    v14 = &unk_24F8F8;
    goto LABEL_18;
  }
  v9 = *(_DWORD *)(connector + 2740);
  cmd_buf = hfi_kms_get_cmd_buf(v6, v9, 1);
  if ( !cmd_buf )
  {
    v14 = &unk_237EB0;
    goto LABEL_18;
  }
  v16[0] = v9;
  v16[1] = 7;
  v16[2] = a2 & 1;
  property = hfi_adapter_add_get_property(cmd_buf, -16777205, 0, 2u, (__int64)v16, 0xCu, (__int64)(v3 + 14), 0);
  if ( property )
  {
    v15 = property;
    printk(&unk_226F0B, "hfi_enc_set_panic_events");
    result = v15;
  }
  else
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "hfi_enc_set_panic_events", 366, -1, *((_DWORD *)v7 + 6), 0, -16777205, 0, 239);
    result = 0;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
