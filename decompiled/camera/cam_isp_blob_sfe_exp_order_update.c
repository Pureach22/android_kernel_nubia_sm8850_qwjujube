__int64 __fastcall cam_isp_blob_sfe_exp_order_update(unsigned int a1, _DWORD *a2, __int64 a3)
{
  __int64 v3; // x28
  __int64 v4; // x8
  int v5; // w9
  int v7; // w21
  _DWORD *v8; // x23
  _QWORD **v9; // x22
  unsigned int *v10; // x26
  __int64 v11; // x6
  unsigned int v12; // w7
  unsigned int v13; // w23
  __int64 result; // x0
  _DWORD *v15; // x20
  __int64 v16; // x27
  int *v17; // x8
  unsigned __int64 v18; // x9
  int v19; // w25
  unsigned int v20; // w24
  __int64 v21; // x23
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x20
  __int64 v25; // x8
  __int64 (__fastcall *v26)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v27; // x0
  int v28; // w0
  _QWORD *v29; // x8
  int v30; // w10
  unsigned int v31; // w23
  int v32; // w24
  char v33; // w27
  __int64 (__fastcall *v34)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v35; // x0
  __int64 v36; // x25
  _QWORD *v37; // x20
  __int64 v38; // x9
  const char *v39; // x6
  unsigned int i; // w12
  unsigned int v41; // w11
  unsigned __int64 v44; // x14
  unsigned __int64 v50; // x10
  unsigned int v52; // w10
  __int64 v53; // x7
  const char *v54; // x5
  __int64 v55; // x4
  int v56; // w0
  __int64 v57; // x7
  int v58; // w9
  __int64 v59; // x0
  const char *v60; // x5
  __int64 v61; // x4
  __int64 v62; // x6
  int v63; // w6
  int v64; // w21
  int v65; // w8
  int v66; // [xsp+0h] [xbp-90h]
  int v67; // [xsp+8h] [xbp-88h]
  int v68; // [xsp+10h] [xbp-80h]
  __int64 v69; // [xsp+20h] [xbp-70h]
  int v70; // [xsp+2Ch] [xbp-64h]
  __int64 v71; // [xsp+30h] [xbp-60h]
  int v72; // [xsp+38h] [xbp-58h]
  int v73; // [xsp+3Ch] [xbp-54h]
  _DWORD *v74; // [xsp+40h] [xbp-50h]
  _DWORD *v75; // [xsp+48h] [xbp-48h]
  unsigned int v76; // [xsp+54h] [xbp-3Ch]
  unsigned int v77; // [xsp+54h] [xbp-3Ch]
  int v79; // [xsp+64h] [xbp-2Ch]
  __int64 v80; // [xsp+68h] [xbp-28h] BYREF
  __int64 v81; // [xsp+70h] [xbp-20h]
  __int64 v82; // [xsp+78h] [xbp-18h]
  unsigned __int64 v83[2]; // [xsp+80h] [xbp-10h] BYREF

  v83[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a3 + 16);
  v81 = 0;
  v82 = 0;
  v80 = 0;
  v4 = *(_QWORD *)(v3 + 72);
  *(_DWORD *)(v3 + 9393) = 0;
  *(_WORD *)(v3 + 9397) = 0;
  if ( !*(_DWORD *)(v4 + 81172) )
  {
    result = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_isp_blob_sfe_exp_order_update",
        10338,
        "No caches found during probe, ctx_idx: %u",
        *(_DWORD *)(v3 + 56));
      result = 0;
    }
    goto LABEL_126;
  }
  v5 = *a2;
  if ( !*a2 )
  {
    v53 = *(unsigned int *)(v3 + 56);
    v54 = "Invalid number of ports: %d ctx_idx: %u";
    v55 = 10344;
    v11 = 0;
    goto LABEL_124;
  }
  v71 = v3 + 9393;
  v79 = v5 - 1;
  v7 = 0;
  v8 = a2 + 2;
  v70 = v5 - 3;
  v9 = (_QWORD **)(v3 + 256);
  v72 = v5 - 2;
  v69 = v4 + 81176;
  v74 = a2 + 2;
  v75 = a2;
  while ( 1 )
  {
    v10 = &v8[6 * v7];
    v11 = *v10;
    if ( (unsigned int)(v11 - 24576) >= 3 )
    {
      v53 = *(unsigned int *)(v3 + 56);
      v54 = "Not a SFE fetch RDI: 0x%x ctx_idx: %u";
      v55 = 10361;
      goto LABEL_124;
    }
    v12 = *(_DWORD *)(v3 + 9352);
    if ( (int)v11 - 24576 >= v12 )
    {
      result = 1;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v15 = a2;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_isp_blob_sfe_exp_order_update",
          10370,
          "Skip cache config for resource: 0x%x, active fetches: %u [exp_order: %d %d] in %u ctx",
          v11,
          v12,
          v7,
          v79,
          *(_DWORD *)(v3 + 56));
        a2 = v15;
        result = 1;
      }
      goto LABEL_4;
    }
    v13 = 0;
    LOWORD(v80) = 0;
    HIDWORD(v82) = 0;
    LOBYTE(v82) = 0;
    if ( v7 != v79 )
    {
      if ( v7 == v72 )
      {
        v13 = 1;
      }
      else if ( v7 == v70 )
      {
        v13 = 2;
      }
      else
      {
        v13 = 3;
      }
    }
    if ( a1 >= 3 )
LABEL_128:
      __break(0x5512u);
    v16 = *(_QWORD *)(v3 + 72);
    v17 = (int *)(v16 + 20LL * a1 + 81248);
    v18 = *v17;
    v83[0] = v18;
    if ( !(_DWORD)v18 )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_hw_mgr_get_sfe_sys_cache_id",
          10246,
          "Unsupported SCID for SFE %u exp_type %u ctx_idx: %u",
          a1,
          v13,
          *(_DWORD *)(v3 + 56));
      goto LABEL_23;
    }
    if ( v13 == 3 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, _DWORD))cam_print_log)(
        3,
        8,
        3,
        "cam_ife_hw_mgr_get_sfe_sys_cache_id",
        10252,
        "Invalid Exposure Type for SFE %u exp_type %u ctx_idx: %u",
        a1,
        3,
        *(_DWORD *)(v3 + 56));
LABEL_23:
      if ( (unsigned __int8)v82 == 1 )
        goto LABEL_128;
      v19 = 0;
      v20 = 6;
      goto LABEL_25;
    }
    v20 = __clz(__rbit32(v18));
    _X12 = v83;
    __asm { PRFM            #0x11, [X12] }
    do
      v50 = __ldxr(v83);
    while ( __stxr(v50 & ~(1LL << v20), v83) );
    if ( v13 )
    {
      for ( i = v83[0]; v83[0]; v20 = v41 )
      {
        v20 = __clz(__rbit32(i));
        if ( i )
          v41 = v20;
        else
          v41 = -1;
        _X13 = &v83[v41 >> 6];
        __asm { PRFM            #0x11, [X13] }
        do
          v44 = __ldxr(_X13);
        while ( __stxr(v44 & ~(1LL << v41), _X13) );
        if ( v41 - 6 > 0xFFFFFFFB )
        {
          if ( (*(_BYTE *)(v16 + 20LL * a1 + 81264 + v13) & 1) != 0 )
            break;
          _ZF = *(_DWORD *)(v16 + 20LL * a1 + 81252 + 4LL * v13) == v41;
          v41 = v20;
          if ( !_ZF )
            break;
        }
        i = v83[0];
      }
    }
    _ZF = v20 >= 2 || v13 == 0;
    v52 = _ZF ? v20 : 6;
    if ( v52 < 6 )
    {
      v77 = v52;
      v17[v13 + 1] = v52;
      if ( (*(_BYTE *)(v16 + 20LL * a1 + 81264 + v13) & 1) == 0 && *(_BYTE *)(v3 + 9377) == 1 )
        cam_cpas_activate_llcc(v52);
      *(_BYTE *)(v16 + 20LL * a1 + 81264 + v13) = 1;
      if ( (cam_cpas_is_notif_staling_supported() & 1) != 0
        && *(_BYTE *)(v16 + 12LL * v77 + 81184) == 1
        && (unsigned int)cam_cpas_notif_increment_staling_counter(v77) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_hw_mgr_get_sfe_sys_cache_id",
          10306,
          "llcc cache notif increment staling failed %d",
          v77);
      }
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_hw_mgr_get_sfe_sys_cache_id",
          10310,
          "SFE %u Exp type %u SCID index %d use_large %d ctx_idx: %u",
          a1,
          v13,
          v77,
          v13 != 0,
          *(_DWORD *)(v3 + 56));
    }
    else
    {
      v20 = v52;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_hw_mgr_get_sfe_sys_cache_id",
          10292,
          "Cannot find scid for SFE %u exp_type %u ctx_idx: %u",
          a1,
          v13,
          *(_DWORD *)(v3 + 56));
    }
    if ( v20 >= 6 )
    {
      if ( (v82 & 1) != 0 )
        goto LABEL_128;
      v19 = 0;
    }
    else
    {
      LOBYTE(v82) = 1;
      HIDWORD(v82) = *(_DWORD *)(v69 + 12LL * v20 + 4);
      if ( SHIDWORD(v82) < 1 )
      {
        result = 0;
        goto LABEL_126;
      }
      v19 = 1;
      *(_BYTE *)(v71 + v20) = 1;
    }
LABEL_25:
    v11 = *v10;
    v21 = (unsigned __int8)*v10;
    if ( (unsigned int)v21 >= max_sfe_out_res )
    {
      v56 = __ratelimit(&cam_isp_blob_sfe_exp_order_update__rs, "cam_isp_blob_sfe_exp_order_update");
      v57 = (unsigned int)max_sfe_out_res;
      v58 = *(_DWORD *)(v3 + 56);
      if ( v56 )
        v59 = 3;
      else
        v59 = 2;
      v60 = "res_id_out: %d exceeds max size: %d ctx_idx: %u";
      v61 = 10407;
      v62 = (unsigned int)v21;
      goto LABEL_120;
    }
    v22 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 8504) + v21);
    if ( v22 == 255 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_blob_sfe_exp_order_update",
        10412,
        "Invalid index:%d for out_map",
        v21);
      goto LABEL_125;
    }
    v23 = *(_QWORD *)(v3 + 280) + (v22 << 7);
    v24 = *(_QWORD *)(v23 + 32);
    if ( !v24 || (v25 = *(_QWORD *)(v24 + 16), *(_DWORD *)(v25 + 4) != a1) )
    {
      v24 = *(_QWORD *)(v23 + 40);
      if ( !v24 )
        goto LABEL_122;
      v25 = *(_QWORD *)(v24 + 16);
      if ( *(_DWORD *)(v25 + 4) != a1 )
        break;
    }
    v26 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v25 + 88);
    v27 = *(_QWORD *)(v25 + 112);
    v81 = v24;
    if ( *((_DWORD *)v26 - 1) != -1055839300 )
      __break(0x8229u);
    v28 = v26(v27, 62, &v80, 24);
    if ( v28 )
    {
      v63 = *(_DWORD *)(v24 + 4);
      v64 = v28;
      LODWORD(v24) = 1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_sfe_send_cache_config",
        10227,
        "Failed in sending cache config for: %u",
        v63);
      v11 = *v10;
      v65 = v64;
      goto LABEL_123;
    }
    v29 = *v9;
    if ( *v10 == 24577 )
      v30 = 20482;
    else
      v30 = 20483;
    if ( *v10 == 24576 )
      v31 = 20481;
    else
      v31 = v30;
    if ( v29 == v9 )
    {
      v32 = 0;
      v33 = 0;
LABEL_119:
      v58 = v33 & 1;
      v60 = "Failed to send cache config for RD res: 0x%x base_idx: %u send_config: %d rc: %d ctx_idx: %u";
      v59 = 3;
      v61 = 10472;
      v62 = v31;
      v57 = a1;
      v68 = *(_DWORD *)(v3 + 56);
      v67 = v32;
LABEL_120:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, int, int))cam_print_log)(
        v59,
        8,
        1,
        "cam_isp_blob_sfe_exp_order_update",
        v61,
        v60,
        v62,
        v57,
        v58,
        v67,
        v68);
      goto LABEL_125;
    }
    v76 = v20;
    v32 = 0;
    v33 = 0;
    v73 = v19;
    do
    {
      v36 = v29[4];
      v37 = (_QWORD *)*v29;
      if ( v36 && *(_DWORD *)(v36 + 4) == v31 && (v38 = *(_QWORD *)(v36 + 16), *(_DWORD *)(v38 + 4) == a1)
        || (v36 = v29[5]) != 0
        && *(_DWORD *)(v36 + 4) == v31
        && (v38 = *(_QWORD *)(v36 + 16), *(_DWORD *)(v38 + 4) == a1) )
      {
        v34 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v38 + 88);
        v35 = *(_QWORD *)(v38 + 112);
        v81 = v36;
        if ( *((_DWORD *)v34 - 1) != -1055839300 )
          __break(0x8228u);
        v32 = v34(v35, 63, &v80, 24);
        v33 = 1;
        if ( v32 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "__cam_isp_sfe_send_cache_config",
            10227,
            "Failed in sending cache config for: %u",
            *(_DWORD *)(v36 + 4));
      }
      v29 = v37;
    }
    while ( v37 != v9 );
    if ( ((v32 == 0) & (unsigned __int8)v33) == 0 )
      goto LABEL_119;
    if ( (v80 & 0x100) == 0 && (v80 & 1) == 0 )
    {
      LOBYTE(v82) = 0;
      if ( v73 )
        *(_BYTE *)(v71 + v76) = 0;
    }
    v8 = v74;
    a2 = v75;
    result = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      if ( (_BYTE)v82 )
        v39 = "enabled";
      else
        v39 = "not enabled";
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_isp_blob_sfe_exp_order_update",
        10485,
        "cache %s on exp order: %u [max: %u] for out: 0x%x ctx_idx: %u",
        v39,
        v7,
        v79,
        *v10,
        *(_DWORD *)(v3 + 56));
      a2 = v75;
      result = 0;
    }
LABEL_4:
    if ( (unsigned int)++v7 >= *a2 )
      goto LABEL_126;
  }
  LODWORD(v24) = 0;
LABEL_122:
  v65 = 1;
LABEL_123:
  v54 = "Failed to send cache config for WR res: 0x%x base_idx: %u send_config: %d rc: %d ctx_idx: %u";
  v67 = v65;
  v68 = *(_DWORD *)(v3 + 56);
  v55 = 10435;
  v53 = a1;
  v66 = v24;
LABEL_124:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, int, int))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_blob_sfe_exp_order_update",
    v55,
    v54,
    v11,
    v53,
    v66,
    v67,
    v68);
LABEL_125:
  result = 4294967274LL;
LABEL_126:
  _ReadStatusReg(SP_EL0);
  return result;
}
