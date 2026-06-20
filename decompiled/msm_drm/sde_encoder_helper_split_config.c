__int64 __fastcall sde_encoder_helper_split_config(__int64 **a1, int a2)
{
  __int64 v3; // x8
  __int64 v5; // x8
  __int64 result; // x0
  __int64 *v7; // x24
  __int64 *v8; // x23
  __int64 *v9; // x20
  __int64 *v10; // x8
  __int64 *v11; // x21
  __int64 (__fastcall *v12)(__int64 *, __int64 *); // x8
  __int64 (__fastcall *v13)(__int64 *, __int64 *); // x8
  __int64 *v14; // x8
  unsigned int v15; // w22
  char v16; // w8
  __int64 *v17; // x8
  __int64 v18; // x8
  int v19; // w8
  unsigned int v20; // w21
  int v21; // w4
  __int64 v22; // x8
  char v23; // w9
  int v24; // w5
  unsigned int v25; // w21
  int v26; // w4
  void *v27; // x0

  if ( !a1 || !a1[51] || !*a1 )
    return printk(&unk_26FF61, "sde_encoder_helper_split_config");
  v3 = **a1;
  if ( v3 )
  {
    v5 = *(_QWORD *)(v3 + 56);
    if ( v5 && *(_QWORD *)(v5 + 8) )
    {
      result = sde_kms_get_disp_op();
      goto LABEL_8;
    }
    v27 = &unk_234896;
  }
  else
  {
    v27 = &unk_26FCAB;
  }
  printk(v27, "sde_encoder_get_kms");
  result = 0;
LABEL_8:
  v7 = a1[53];
  v8 = *a1;
  v9 = a1[51];
  v7[8] = 0;
  v7[9] = 0;
  v7[7] = 0;
  if ( *((_DWORD *)v8 + 160) != 16 )
    return result;
  if ( (*((_BYTE *)v8 + 644) & 0x40) != 0 )
    *((_BYTE *)v7 + 77) = 1;
  if ( *((_DWORD *)a1 + 166) )
  {
    v10 = *a1;
    if ( !*a1 || *((_DWORD *)v10 + 49) != 1 || *((_BYTE *)v10 + 4936) != 1 )
    {
      *((_BYTE *)v7 + 56) = 1;
      *((_DWORD *)v7 + 15) = *((_DWORD *)a1 + 167);
      *((_DWORD *)v7 + 16) = a2;
      v14 = a1[24];
      if ( v14 )
      {
        v15 = result;
        if ( *((_DWORD *)v14 - 1) != -1375811177 )
          __break(0x8228u);
        v16 = ((__int64 (__fastcall *)(__int64 **))v14)(a1);
        result = v15;
        if ( (v16 & 1) != 0 )
          *((_BYTE *)v7 + 76) = 1;
      }
      v17 = a1[1];
      if ( v17 && (v18 = v17[314]) != 0 && *(_DWORD *)(v18 + 1376) == 10 )
        v19 = *((_DWORD *)v7 + 16);
      else
        v19 = 10;
      *((_DWORD *)v7 + 17) = v19;
      if ( (unsigned int)(*((_DWORD *)a1 + 166) - 1) > 1 )
      {
        v22 = v8[42];
        if ( !v22 )
          return result;
        v23 = _drm_debug;
        v24 = *(_DWORD *)(v22 + 32) - 1;
        *((_DWORD *)v7 + 18) = v24;
        if ( (v23 & 4) != 0 )
        {
          v25 = result;
          if ( v8 )
            v26 = *((_DWORD *)v8 + 6);
          else
            v26 = -1;
          _drm_dev_dbg(0, 0, 0, "enc%d master using pp%d\n", v26, v24);
          result = v25;
        }
        if ( (unsigned int)result <= 2 )
        {
          v13 = (__int64 (__fastcall *)(__int64 *, __int64 *))v9[(unsigned int)result + 10];
          if ( !v13 )
            return result;
          goto LABEL_48;
        }
      }
      else
      {
        if ( (_drm_debug & 4) != 0 )
        {
          v20 = result;
          if ( v8 )
            v21 = *((_DWORD *)v8 + 6);
          else
            v21 = -1;
          _drm_dev_dbg(0, 0, 0, "enc%d enable %d\n", v21, *((unsigned __int8 *)v7 + 56));
          result = v20;
        }
        if ( (unsigned int)result <= 2 )
        {
          v13 = (__int64 (__fastcall *)(__int64 *, __int64 *))v9[(unsigned int)result + 7];
          if ( !v13 )
            return result;
          goto LABEL_48;
        }
      }
LABEL_57:
      __break(0x5512u);
      return sde_encoder_is_self_refresh_completed();
    }
  }
  if ( (unsigned int)result >= 3 )
    goto LABEL_57;
  v11 = &v9[(unsigned int)result];
  v12 = (__int64 (__fastcall *)(__int64 *, __int64 *))v11[7];
  if ( v12 )
  {
    if ( *((_DWORD *)v12 - 1) != 139546062 )
      __break(0x8228u);
    result = v12(v9, v7 + 7);
  }
  v13 = (__int64 (__fastcall *)(__int64 *, __int64 *))v11[10];
  if ( v13 )
  {
LABEL_48:
    if ( *((_DWORD *)v13 - 1) != 139546062 )
      __break(0x8228u);
    return v13(v9, v7 + 7);
  }
  return result;
}
