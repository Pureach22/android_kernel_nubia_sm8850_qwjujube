__int64 __fastcall hfi_enc_kickoff(_QWORD *a1)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 connector; // x0
  unsigned int v7; // w19
  __int64 cmd_buf; // x0
  unsigned int v9; // w0
  int v10; // w6
  int v11; // w7
  __int64 result; // x0
  void *v13; // x0
  void *v14; // x0
  unsigned int v15; // w19
  unsigned int v22; // w8
  unsigned int v23; // w8
  char v24; // [xsp+0h] [xbp-20h]
  __int64 v25; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v26; // [xsp+14h] [xbp-Ch]
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_18;
  if ( !*a1 )
  {
    v13 = &unk_26FCAB;
    goto LABEL_13;
  }
  v2 = *(_QWORD *)(*a1 + 56LL);
  if ( !v2 || (v3 = *(_QWORD *)(v2 + 8)) == 0 )
  {
    v13 = &unk_234896;
LABEL_13:
    printk(v13, "sde_encoder_get_kms");
    v4 = 0x2AE7FC00171F28LL;
    goto LABEL_6;
  }
  v4 = *(_QWORD *)(v3 + 6440);
  if ( !v4 )
  {
    v14 = &unk_279C72;
LABEL_16:
    printk(v14, "hfi_enc_kickoff");
LABEL_18:
    result = 4294967274LL;
    goto LABEL_19;
  }
LABEL_6:
  v5 = a1[622];
  connector = sde_encoder_get_connector(*a1, a1);
  if ( !connector )
  {
    v14 = &unk_242658;
    goto LABEL_16;
  }
  v7 = *(_DWORD *)(connector + 2740);
  cmd_buf = hfi_kms_get_cmd_buf(v4, v7, 1);
  if ( !cmd_buf )
  {
    printk(&unk_237E69, "hfi_enc_kickoff");
    goto LABEL_18;
  }
  v25 = 0x2001A00000001LL;
  _X9 = (unsigned int *)(v5 + 44);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v22 = __ldxr(_X9);
    v23 = v22 + 1;
  }
  while ( __stlxr(v23, _X9) );
  __dmb(0xBu);
  v26 = v23;
  v9 = hfi_adapter_add_set_property(cmd_buf, 33554433, v7, 2u, (__int64)&v25, 0xCu, 4);
  if ( v9 )
  {
    v15 = v9;
    printk(&unk_25A59C, "hfi_enc_kickoff");
    result = v15;
  }
  else
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "hfi_enc_kickoff", 520, -1, *(_DWORD *)(v5 + 44), -1059143953, v10, v11, v24);
    result = 0;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
