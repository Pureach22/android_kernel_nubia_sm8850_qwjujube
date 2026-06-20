__int64 __fastcall sde_encoder_helper_get_kickoff_timeout_ms(__int64 *src_encoder_of_clone)
{
  __int64 v1; // x8
  __int64 v2; // x19
  int v3; // w8
  __int64 v4; // x9
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x8
  unsigned int v10; // w8
  void *v12; // x0
  const char *v13; // x1

  if ( !src_encoder_of_clone )
  {
    v12 = &unk_26FCAB;
    v13 = "sde_encoder_helper_get_kickoff_timeout_ms";
    goto LABEL_32;
  }
  if ( !*src_encoder_of_clone )
  {
    v12 = &unk_26FCAB;
    v13 = "sde_encoder_get_kms";
    goto LABEL_32;
  }
  v1 = *(_QWORD *)(*src_encoder_of_clone + 56);
  if ( !v1 || (v2 = *(_QWORD *)(v1 + 8)) == 0 )
  {
    v12 = &unk_234896;
    v13 = "sde_encoder_get_kms";
LABEL_32:
    printk(v12, v13);
    return 84;
  }
  v3 = *((_DWORD *)src_encoder_of_clone + 49);
  if ( !v3 )
    goto LABEL_18;
  v4 = src_encoder_of_clone[25];
  if ( !v4 || (*(_BYTE *)(v4 + 2290) & 1) == 0 )
  {
    if ( v3 == 1 )
      goto LABEL_18;
    v5 = src_encoder_of_clone[26];
    if ( !v5 || (*(_BYTE *)(v5 + 2290) & 1) == 0 )
    {
      if ( v3 == 2 )
        goto LABEL_18;
      v6 = src_encoder_of_clone[27];
      if ( !v6 || (*(_BYTE *)(v6 + 2290) & 1) == 0 )
      {
        if ( v3 == 3 )
          goto LABEL_18;
        v7 = src_encoder_of_clone[28];
        if ( !v7 || (*(_BYTE *)(v7 + 2290) & 1) == 0 )
        {
          if ( v3 != 4 )
          {
            __break(0x5512u);
            return sde_encoder_get_avr_status(src_encoder_of_clone);
          }
LABEL_18:
          if ( (*(_QWORD *)(*(_QWORD *)(v2 + 152) + 22008LL) & 0x100000000000LL) != 0 )
            return 100000;
          if ( (*((_BYTE *)src_encoder_of_clone + 749) & 1) != 0 )
          {
            v8 = src_encoder_of_clone[41];
            if ( !v8 || (v9 = *(_QWORD *)(v8 + 2408)) == 0 )
            {
              LOWORD(v10) = 1;
              return 2 * (0x3E8u / (unsigned __int16)v10);
            }
            v10 = *(_DWORD *)(*(_QWORD *)v9 + 4LL * (unsigned int)(*(_DWORD *)(v9 + 8) - 1)) / 0x3E8u;
          }
          else
          {
            v10 = *((_DWORD *)src_encoder_of_clone + 986);
          }
          if ( v10 - 24 < 0xFFFFFFE9 )
            return 84;
          return 2 * (0x3E8u / (unsigned __int16)v10);
        }
      }
    }
  }
  src_encoder_of_clone = sde_crtc_get_src_encoder_of_clone((__int64 *)src_encoder_of_clone[10]);
  if ( src_encoder_of_clone )
    goto LABEL_18;
  return 84;
}
