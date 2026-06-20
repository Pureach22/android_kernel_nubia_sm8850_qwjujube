__int64 __fastcall cam_cpas_get_hw_features(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x20
  int v4; // w21
  __int64 v5; // x27
  int v6; // w26
  unsigned int v8; // w25
  int v9; // w8
  __int64 v10; // x4
  const char *v11; // x5
  unsigned int v12; // w24
  __int64 v13; // x2
  int v14; // w8
  unsigned int v15; // w19
  __int64 v16; // x2
  __int64 v17; // x0
  __int64 v18; // x28
  int v19; // w0
  unsigned int v20; // w9
  int v21; // w24
  int v22; // w8
  int *v23; // x12
  __int64 v24; // x10
  __int64 v25; // x8
  int v26; // t1
  int v27; // w6
  int *v28; // x8
  int v29; // w6
  _DWORD *v30; // x10
  unsigned int v31; // w8
  const char *v32; // x5
  __int64 v33; // x4
  __int64 v34; // x6
  _DWORD *v35; // [xsp+28h] [xbp-38h]
  int *v36; // [xsp+30h] [xbp-30h]
  _DWORD *v37; // [xsp+38h] [xbp-28h]
  int v38; // [xsp+44h] [xbp-1Ch] BYREF
  __int64 v39; // [xsp+48h] [xbp-18h] BYREF
  _QWORD v40[2]; // [xsp+50h] [xbp-10h] BYREF

  v40[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 760);
  v39 = 0;
  v40[0] = 0;
  v38 = 0;
  v4 = of_property_count_elems_of_size(v3, "cam_hw_fuse", 4);
  if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_get_hw_features",
      883,
      "fuse info elements count %d",
      v4);
    if ( v4 < 1 )
      goto LABEL_7;
  }
  else if ( v4 < 1 )
  {
LABEL_7:
    LODWORD(v5) = 0;
    v6 = 0;
    goto LABEL_8;
  }
  if ( (unsigned int)(-858993459 * v4) > 0x33333333 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      3,
      "cam_cpas_get_hw_features",
      889,
      "fuse entries should be multiple of 5 %d",
      v4);
    goto LABEL_7;
  }
  if ( (unsigned int)v4 < 5 )
    goto LABEL_7;
  v5 = 0;
  v6 = 0;
  v35 = a2;
  v36 = a2 + 267;
  v8 = 0;
  v37 = a2 + 348;
  v9 = 5;
  while ( 1 )
  {
    v12 = v8;
    v13 = v8;
    v8 = v9;
    of_property_read_u32_index(v3, "cam_hw_fuse", v13, (char *)&v39 + 4);
    of_property_read_u32_index(v3, "cam_hw_fuse", v12 + 1, (char *)v40 + 4);
    of_property_read_u32_index(v3, "cam_hw_fuse", v12 + 2, v40);
    of_property_read_u32_index(v3, "cam_hw_fuse", v12 + 3, &v39);
    of_property_read_u32_index(v3, "cam_hw_fuse", v12 + 4, &v38);
    v14 = v40[0];
    if ( LODWORD(v40[0]) )
    {
      v15 = __clz(__rbit32(v40[0]));
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_get_hw_features",
        907,
        "fuse_mask not valid 0x%x",
        0);
      v14 = v40[0];
      v15 = 0;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      3,
      "cam_cpas_get_hw_features",
      915,
      "feature 0x%x addr 0x%x, mask 0x%x, shift 0x%x type 0x%x hw_map 0x%x",
      HIDWORD(v39),
      HIDWORD(v40[0]),
      v14,
      v15,
      v39,
      v38);
    if ( arm64_use_ng_mappings )
      v16 = 0x68000000000F13LL;
    else
      v16 = 0x68000000000713LL;
    v17 = ioremap_prot(HIDWORD(v40[0]), 4, v16);
    v18 = v17;
    if ( v17 )
    {
      v19 = cam_io_r(v17);
      v20 = v6 - 1;
      v21 = v19;
      if ( v6 < 1 )
      {
        LODWORD(v25) = 0;
LABEL_32:
        if ( (_DWORD)v25 != v6 )
        {
LABEL_34:
          if ( v5 == 10 )
            goto LABEL_46;
          goto LABEL_35;
        }
      }
      else
      {
        if ( v20 >= 0x1F )
          v22 = 31;
        else
          v22 = v6 - 1;
        v23 = v36;
        v24 = 0;
        v25 = (unsigned int)(v22 + 1);
        while ( 1 )
        {
          v26 = *v23;
          v23 += 2;
          if ( v26 == HIDWORD(v40[0]) )
            break;
          if ( v25 == ++v24 )
          {
            if ( v20 < 0x1F )
              goto LABEL_32;
            v32 = "fuse_info array overflow! %d";
            v33 = 928;
            v34 = 32;
            goto LABEL_48;
          }
        }
        if ( (_DWORD)v24 != v6 )
          goto LABEL_34;
      }
      v27 = HIDWORD(v40[0]);
      v28 = &v36[2 * v6];
      *v28 = HIDWORD(v40[0]);
      v28[1] = v19;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        3,
        "cam_cpas_get_hw_features",
        938,
        "fuse_addr 0x%x, fuse_val %x",
        v27,
        v19);
      ++v6;
      goto LABEL_34;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_get_hw_features",
      945,
      "fuse register io remap failed fuse_addr:0x%x feature0x%x ",
      HIDWORD(v40[0]),
      HIDWORD(v39));
    if ( (unsigned int)v39 > 1 )
    {
      v21 = 0;
      if ( v5 == 10 )
      {
LABEL_46:
        v32 = "feature_info array overflow %d";
        v33 = 957;
        v34 = 10;
        goto LABEL_48;
      }
    }
    else
    {
      v21 = LODWORD(v40[0]) ^ -(int)v39;
      if ( v5 == 10 )
        goto LABEL_46;
    }
LABEL_35:
    v29 = HIDWORD(v39);
    v30 = &v37[5 * v5];
    v31 = v39;
    v30[4] = v38;
    *v30 = v29;
    v30[1] = v31;
    if ( !v31 )
    {
      if ( (v40[0] & v21) != 0 )
        goto LABEL_41;
LABEL_39:
      *((_BYTE *)v30 + 12) = 1;
LABEL_42:
      v10 = 998;
      v11 = "feature 0x%x enable=%d hw_map=0x%x";
      goto LABEL_11;
    }
    if ( v31 != 2 )
      break;
    v10 = 1005;
    v11 = "feature 0x%x value=0x%x hw_map=0x%x";
    v30[2] = (v40[0] & v21) >> v15;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      3,
      "cam_cpas_get_hw_features",
      v10,
      v11);
    ++v5;
    iounmap(v18);
    v9 = v8 + 5;
    if ( (int)(v8 + 5) > v4 )
      goto LABEL_49;
  }
  if ( v31 == 1 )
  {
    if ( (v40[0] & v21) != 0 )
      goto LABEL_39;
LABEL_41:
    *((_BYTE *)v30 + 12) = 0;
    goto LABEL_42;
  }
  v32 = "Feature type not valid, type: %d";
  v33 = 992;
  v34 = v31;
LABEL_48:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    4,
    1,
    "cam_cpas_get_hw_features",
    v33,
    v32,
    v34);
LABEL_49:
  a2 = v35;
LABEL_8:
  a2[266] = v6;
  _ReadStatusReg(SP_EL0);
  a2[347] = v5;
  return 0;
}
