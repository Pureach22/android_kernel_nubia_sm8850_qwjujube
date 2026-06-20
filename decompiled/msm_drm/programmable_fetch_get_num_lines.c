__int64 __fastcall programmable_fetch_get_num_lines(_QWORD *a1, _DWORD *a2)
{
  int v2; // w21
  int v3; // w22
  __int64 v4; // x8
  int v5; // w27
  unsigned int v8; // w19
  __int64 v9; // x25
  unsigned int v10; // w26
  unsigned int v11; // w8
  unsigned int v12; // w24
  unsigned int v13; // w8
  unsigned int v14; // w21
  unsigned int v15; // w25
  int v16; // w4
  __int64 v17; // x8
  int v18; // w4
  __int64 v19; // x8
  int v20; // w4
  __int64 v21; // x8
  int v22; // w5
  int v23; // w4
  __int64 v24; // x8
  int v25; // w5
  int v26; // w4
  __int64 v27; // x8
  int v28; // w5
  int v30; // w5
  int v31; // w5

  v2 = a2[6];
  v3 = a2[7];
  v4 = *a1;
  v5 = a2[9];
  v8 = *(_DWORD *)(*(_QWORD *)(a1[53] + 40LL) + 56LL);
  v9 = *(_QWORD *)(a1[64] + 152LL);
  if ( *(_BYTE *)(a1[1] + 4713LL) )
    v10 = v3 - 2;
  else
    v10 = a2[7];
  if ( v4 )
  {
    v11 = *(_DWORD *)(v4 + 3976);
  }
  else
  {
    printk(&unk_26FCAB, "sde_encoder_get_dfps_maxfps");
    v11 = 0;
  }
  if ( v11 <= a2[21] )
    v12 = a2[21];
  else
    v12 = v11;
  v13 = v5 + v2;
  if ( v12 >= 0x3D )
    v8 = v12 * v8 / 0x3C;
  v14 = v8 - v13;
  if ( v8 <= v13 )
  {
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_36;
    if ( a1 )
    {
      if ( *a1 )
      {
        v18 = *(_DWORD *)(*a1 + 24LL);
        v19 = a1[53];
        if ( !v19 )
          goto LABEL_31;
LABEL_34:
        v22 = *(_DWORD *)(v19 + 32) - 1;
        goto LABEL_35;
      }
      v18 = -1;
      v19 = a1[53];
      if ( v19 )
        goto LABEL_34;
    }
    else
    {
      v18 = -1;
    }
LABEL_31:
    v22 = -1;
LABEL_35:
    _drm_dev_dbg(0, 0, 0, "enc%d intf%d prog fetch always enabled case\n", v18, v22);
LABEL_36:
    if ( (*(_QWORD *)(v9 + 22008) & 0x4000000LL) != 0 )
      v15 = 2;
    else
      v15 = 1;
    goto LABEL_39;
  }
  if ( v10 >= v14 )
  {
    v15 = v8 - v13;
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_39;
    if ( a1 )
    {
      if ( *a1 )
      {
        v20 = *(_DWORD *)(*a1 + 24LL);
        v21 = a1[53];
        if ( !v21 )
          goto LABEL_62;
LABEL_67:
        v31 = *(_DWORD *)(v21 + 32) - 1;
        goto LABEL_68;
      }
      v20 = -1;
      v21 = a1[53];
      if ( v21 )
        goto LABEL_67;
    }
    else
    {
      v20 = -1;
    }
LABEL_62:
    v31 = -1;
LABEL_68:
    _drm_dev_dbg(0, 0, 0, "enc%d intf%d room in vfp for needed prefetch\n", v20, v31);
    v15 = v14;
    goto LABEL_39;
  }
  if ( (programmable_fetch_get_num_lines___already_done & 1) == 0 )
  {
    programmable_fetch_get_num_lines___already_done = 1;
    printk(&unk_246114, "programmable_fetch_get_num_lines");
  }
  v15 = v10;
  if ( (_drm_debug & 4) != 0 )
  {
    if ( a1 )
    {
      if ( *a1 )
      {
        v16 = *(_DWORD *)(*a1 + 24LL);
        v17 = a1[53];
        if ( !v17 )
          goto LABEL_60;
LABEL_64:
        v30 = *(_DWORD *)(v17 + 32) - 1;
        goto LABEL_65;
      }
      v16 = -1;
      v17 = a1[53];
      if ( v17 )
        goto LABEL_64;
    }
    else
    {
      v16 = -1;
    }
LABEL_60:
    v30 = -1;
LABEL_65:
    _drm_dev_dbg(0, 0, 0, "enc%d intf%d less vfp than fetch req, using entire vfp\n", v16, v30);
    v15 = v10;
  }
LABEL_39:
  if ( (_drm_debug & 4) == 0 )
    return v15;
  if ( !a1 )
  {
    v23 = -1;
    goto LABEL_45;
  }
  if ( !*a1 )
  {
    v23 = -1;
    v24 = a1[53];
    if ( v24 )
      goto LABEL_47;
LABEL_45:
    v25 = -1;
    goto LABEL_48;
  }
  v23 = *(_DWORD *)(*a1 + 24LL);
  v24 = a1[53];
  if ( !v24 )
    goto LABEL_45;
LABEL_47:
  v25 = *(_DWORD *)(v24 + 32) - 1;
LABEL_48:
  _drm_dev_dbg(
    0,
    0,
    0,
    "enc%d intf%d vrefresh:%u v_front_porch:%u v_back_porch:%u vsync_pulse_width:%u\n",
    v23,
    v25,
    v12,
    v3,
    a2[6],
    a2[9]);
  if ( (_drm_debug & 4) != 0 )
  {
    if ( a1 )
    {
      if ( *a1 )
      {
        v26 = *(_DWORD *)(*a1 + 24LL);
        v27 = a1[53];
        if ( !v27 )
          goto LABEL_54;
LABEL_56:
        v28 = *(_DWORD *)(v27 + 32) - 1;
        goto LABEL_57;
      }
      v26 = -1;
      v27 = a1[53];
      if ( v27 )
        goto LABEL_56;
    }
    else
    {
      v26 = -1;
    }
LABEL_54:
    v28 = -1;
LABEL_57:
    _drm_dev_dbg(
      0,
      0,
      0,
      "enc%d intf%d prefill_lines:%u needed_vfp_lines:%u actual_vfp_lines:%u allowed_vfp:%u\n",
      v26,
      v28,
      v8,
      v14,
      v15,
      v10);
  }
  return v15;
}
