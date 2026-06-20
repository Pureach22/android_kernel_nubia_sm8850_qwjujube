__int64 __fastcall sde_wb_connector_set_info_blob(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x9
  unsigned int *v8; // x22
  __int64 v9; // x21
  unsigned int v10; // w8
  unsigned int v11; // w1
  _DWORD *v12; // x22
  unsigned int v13; // t1
  unsigned int *v14; // x22
  unsigned int v15; // w8
  unsigned int v16; // w1
  _DWORD *v17; // x22
  unsigned int v18; // t1
  __int64 v19; // x8
  __int64 v20; // x2
  __int64 v21; // x2
  __int64 v22; // x2
  unsigned int v23; // w22
  void *v25; // x0
  const char *v26; // x1
  __int64 vars0; // [xsp+0h] [xbp+0h]
  int _8; // [xsp+8h] [xbp+8h]
  __int64 vars10; // [xsp+10h] [xbp+10h]
  int _18; // [xsp+18h] [xbp+18h]
  __int64 vars20; // [xsp+20h] [xbp+20h]

  if ( !a1 || !a2 || !a3 || (v5 = *(_QWORD *)(a3 + 16)) == 0 )
  {
    v25 = &unk_223EAA;
    v26 = "sde_wb_connector_set_info_blob";
LABEL_33:
    printk(v25, v26);
    return 4294967274LL;
  }
  if ( !*(_QWORD *)a1 || (v6 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) == 0 )
  {
    v25 = &unk_242658;
    v26 = "sde_connector_get_kms";
    goto LABEL_33;
  }
  v7 = *(_QWORD *)(v6 + 8);
  if ( !v7 )
  {
    v25 = &unk_234896;
    v26 = "sde_connector_get_kms";
    goto LABEL_33;
  }
  v8 = *(unsigned int **)(v5 + 56);
  v9 = *(_QWORD *)(v7 + 152);
  if ( v8 )
  {
    ((void (__fastcall *)(__int64, const char *))sde_kms_info_start)(a2, "pixel_formats");
    v11 = *v8;
    if ( *v8 )
    {
      v12 = v8 + 4;
      do
      {
        sde_kms_info_append_format(a2, v11, *((_QWORD *)v12 - 1), v10, vars0, _8, vars10, _18, vars20);
        v13 = *v12;
        v12 += 4;
        v11 = v13;
      }
      while ( v13 );
    }
    ((void (__fastcall *)(__int64))sde_kms_info_stop)(a2);
    v5 = *(_QWORD *)(a3 + 16);
  }
  v14 = *(unsigned int **)(v5 + 64);
  if ( v14 )
  {
    ((void (__fastcall *)(__int64, const char *))sde_kms_info_start)(a2, "rot_output_formats");
    v16 = *v14;
    if ( *v14 )
    {
      v17 = v14 + 4;
      do
      {
        sde_kms_info_append_format(a2, v16, *((_QWORD *)v17 - 1), v15, vars0, _8, vars10, _18, vars20);
        v18 = *v17;
        v17 += 4;
        v16 = v18;
      }
      while ( v18 );
    }
    ((void (__fastcall *)(__int64))sde_kms_info_stop)(a2);
  }
  sde_kms_info_add_keyint(a2, (__int64)"wb_intf_index", (unsigned int)(*(_DWORD *)(a3 + 12) - 1));
  sde_kms_info_add_keyint(a2, (__int64)"maxlinewidth", **(unsigned int **)(*(_QWORD *)(a3 + 16) + 48LL));
  sde_kms_info_add_keyint(
    a2,
    (__int64)"maxlinewidth_linear",
    *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a3 + 16) + 48LL) + 4LL));
  ((void (__fastcall *)(__int64, const char *))sde_kms_info_start)(a2, "features");
  v19 = *(_QWORD *)(a3 + 16);
  if ( v19 && (*(_BYTE *)(v19 + 32) & 0x80) != 0 )
    ((void (__fastcall *)(__int64, const char *))sde_kms_info_append)(a2, "wb_ubwc");
  ((void (__fastcall *)(__int64))sde_kms_info_stop)(a2);
  sde_kms_info_add_keyint(a2, (__int64)"has_cwb_dither", (*(_QWORD *)(v9 + 22008) >> 5) & 1LL);
  v20 = *(unsigned int *)(v9 + 11848);
  if ( (_DWORD)v20 )
    sde_kms_info_add_keyint(a2, (__int64)"cdm_count", v20);
  v21 = *(unsigned int *)(v9 + 12624);
  if ( (_DWORD)v21 && *(_QWORD *)(v9 + 22088) )
  {
    sde_kms_info_add_keyint(a2, (__int64)"dnsc_blur_count", v21);
    ((void (__fastcall *)(__int64, const char *))sde_kms_info_start)(a2, "dnsc_blur_info");
    if ( *(_DWORD *)(v9 + 22096) )
    {
      v23 = 0;
      do
        sde_kms_info_append_dnsc_blur_filter_info(
          a2,
          (unsigned __int8 *)(*(_QWORD *)(v9 + 22088) + ((__int64)(int)v23++ << 6)),
          v22);
      while ( v23 < *(_DWORD *)(v9 + 22096) );
    }
    ((void (__fastcall *)(__int64))sde_kms_info_stop)(a2);
  }
  return 0;
}
