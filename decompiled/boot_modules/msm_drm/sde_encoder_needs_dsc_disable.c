__int64 __fastcall sde_encoder_needs_dsc_disable(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x19
  __int64 v7; // x8
  unsigned int v8; // w8
  void *v9; // x0
  _QWORD v11[3]; // [xsp+8h] [xbp-18h] BYREF

  v11[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_15;
  if ( !*(_QWORD *)a1 )
  {
    v9 = &unk_26FCAB;
    goto LABEL_14;
  }
  v2 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v2 || (v3 = *(_QWORD *)(v2 + 8)) == 0 )
  {
    v9 = &unk_234896;
LABEL_14:
    printk(v9, "sde_encoder_get_kms");
    goto LABEL_15;
  }
  v4 = *(_QWORD *)(v3 + 136);
  v11[0] = 0;
  v11[1] = 0;
  drm_connector_list_iter_begin(v4, v11);
  do
  {
    v5 = drm_connector_list_iter_next(v11);
    if ( !v5 )
    {
      drm_connector_list_iter_end(v11);
      goto LABEL_15;
    }
  }
  while ( *(_QWORD *)(v5 + 2272) != a1 );
  v6 = v5;
  drm_connector_list_iter_end(v11);
  v7 = *(_QWORD *)(v6 + 2512);
  if ( !v7 )
    goto LABEL_16;
  v8 = *(_DWORD *)(v7 + 3256);
  if ( v8 <= 0xE )
  {
    LODWORD(v7) = 0x72A4u >> v8;
    goto LABEL_16;
  }
LABEL_15:
  LOBYTE(v7) = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v7 & 1;
}
