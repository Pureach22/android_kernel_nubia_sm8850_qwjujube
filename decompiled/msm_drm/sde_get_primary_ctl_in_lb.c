__int64 __fastcall sde_get_primary_ctl_in_lb(__int64 **a1)
{
  __int64 *v1; // x8
  __int64 v3; // x0
  __int64 v4; // x9
  __int64 *v5; // x8
  __int64 *v6; // x9
  unsigned int v7; // w10
  unsigned int *v8; // x19
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x20
  void *v12; // x0
  _QWORD v13[3]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v14[3]; // [xsp+18h] [xbp-18h] BYREF

  v14[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_17;
  v1 = *a1;
  if ( !*a1 )
    goto LABEL_17;
  memset(v13, 0, sizeof(v13));
  v14[0] = 0;
  v14[1] = 0;
  drm_connector_list_iter_begin(*v1, v14);
  v3 = drm_connector_list_iter_next(v14);
  if ( !v3 )
  {
LABEL_16:
    drm_connector_list_iter_end(v14);
LABEL_17:
    result = 0;
    goto LABEL_18;
  }
  while ( ((*((_DWORD *)a1 + 4) >> *(_DWORD *)(v3 + 152)) & 1) == 0 || (*(_BYTE *)(v3 + 5129) & 1) == 0 )
  {
    v3 = drm_connector_list_iter_next(v14);
    if ( !v3 )
      goto LABEL_16;
  }
  drm_connector_list_iter_end(v14);
  v4 = **a1;
  v5 = *(__int64 **)(v4 + 816);
  v6 = (__int64 *)(v4 + 816);
  if ( v5 == v6 )
    goto LABEL_17;
  v7 = *((_DWORD *)a1 + 5);
  v8 = nullptr;
  do
  {
    if ( ((v7 >> *((_DWORD *)v5 + 15)) & 1) != 0 )
    {
      if ( v5 == (__int64 *)&unk_8 )
      {
        v8 = nullptr;
      }
      else if ( (*((_DWORD *)v5 + 159) & 0x80) == 0 )
      {
        v8 = (unsigned int *)(v5 - 1);
      }
    }
    v5 = (__int64 *)*v5;
  }
  while ( v5 != v6 );
  if ( !v8 )
    goto LABEL_17;
  if ( *(_QWORD *)v8 )
  {
    v10 = *(_QWORD *)(*(_QWORD *)v8 + 56LL);
    if ( v10 )
    {
      v11 = *(_QWORD *)(v10 + 8);
      if ( v11 )
        goto LABEL_23;
    }
    v12 = &unk_234896;
  }
  else
  {
    v12 = &unk_26FCAB;
  }
  printk(v12, "sde_encoder_get_kms");
  v11 = 0;
LABEL_23:
  sde_rm_init_hw_iter(v13, v8[6], 5);
  if ( (sde_rm_get_hw(v11 + 2144, v13) & 1) != 0 )
    result = v13[0];
  else
    result = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
