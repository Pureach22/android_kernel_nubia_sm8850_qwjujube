__int64 __fastcall cam_ife_csid_ver2_init_config_pxl_path(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v5; // x23
  __int64 v6; // x25
  __int64 v7; // x24
  unsigned int v8; // w10
  __int64 v9; // x26
  __int64 v10; // x9
  unsigned int v11; // w21
  __int64 v12; // x28
  __int64 v13; // x27
  int v14; // w9
  unsigned int v15; // w22
  int v16; // w9
  unsigned int v17; // w22
  int v18; // w9
  int v19; // w8
  int v21; // w10
  int v22; // w10
  int v23; // w8
  unsigned int v24; // w22
  unsigned int v25; // w21
  unsigned int v26; // w8
  unsigned int v27; // w0
  __int64 v28; // [xsp+18h] [xbp-8h]

  v2 = *(unsigned int *)(a2 + 4);
  if ( (unsigned int)v2 >= 0xC )
    goto LABEL_78;
  v5 = **(_QWORD **)(a1 + 31136);
  v6 = *(_QWORD *)(v5 + 8 * v2 + 136);
  if ( !v6 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_init_config_pxl_path",
      5170,
      "CSID:%u path res reg not found, type:%d res_id:%d res state %d",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
      *(_DWORD *)a2,
      v2,
      *(_DWORD *)(a2 + 8));
    return 4294967274LL;
  }
  v7 = *(_QWORD *)(a2 + 24);
  v8 = *(_DWORD *)(v7 + 120);
  if ( v8 > 4 )
  {
LABEL_78:
    __break(0x5512u);
    return cam_ife_csid_ver2_discard_sof_top_half();
  }
  v9 = *(_QWORD *)(v5 + 120);
  v10 = a1 + 56LL * v8;
  v11 = (*(_DWORD *)(v10 + 1828) << *(_DWORD *)(v9 + 296))
      | (*(_DWORD *)(v10 + 1824) << *(_DWORD *)(v9 + 288))
      | (*(_DWORD *)(v7 + 48) << *(_DWORD *)(v9 + 248));
  if ( (*(_BYTE *)(v9 + 599) & 1) == 0 )
    v11 |= v8 << *(_DWORD *)(v9 + 284);
  if ( *(_DWORD *)(v9 + 540) )
    v11 |= *(unsigned __int8 *)(v7 + 244) << *(_DWORD *)(v9 + 244);
  if ( *(_DWORD *)(v9 + 544) )
    v11 |= *(unsigned __int8 *)(v7 + 245) << *(_DWORD *)(v9 + 240);
  if ( *(_BYTE *)(v9 + 596) == 1 )
    v11 |= (1 << *(_DWORD *)(*(_QWORD *)(v7 + 264) + 416LL)) | (*(_DWORD *)(v9 + 556) << *(_DWORD *)(v9 + 236));
  v12 = *(_QWORD *)(*(_QWORD *)(a1 + 31128) + 384LL) + *(unsigned int *)(v6 + 316);
  v28 = *(_QWORD *)(*(_QWORD *)(a1 + 31128) + 384LL);
  if ( (*(_BYTE *)(v6 + 584) & 8) != 0
    && ((*(_BYTE *)(v6 + 593) & 1) != 0
     || (*(_BYTE *)(v7 + 250) & 1) != 0
     || (*(_BYTE *)(v7 + 251) & 1) != 0
     || (_DWORD)v2 == 6 && (*(_BYTE *)(a1 + 2159) & 1) != 0) )
  {
    v11 |= 1 << *(_DWORD *)(*(_QWORD *)(v7 + 264) + 580LL);
  }
  v13 = v10 + 1824;
  cam_io_w_mb(v11, v12 + *(unsigned int *)(*(_QWORD *)(v7 + 264) + 16LL));
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_init_config_pxl_path",
      5216,
      "CSID[%u] res:%s cfg0: 0x%x",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
      (const char *)(a2 + 128),
      v11);
  *(_BYTE *)(v7 + 254) = 0;
  if ( *(_BYTE *)(v13 + 20) == 1 )
  {
    v14 = *(_DWORD *)(v13 + 16);
    if ( v14 == 0xFFFF )
      v14 = 0;
    v15 = (v14 << *(_DWORD *)(v9 + 420))
        | (*(_DWORD *)(v13 + 12) << *(_DWORD *)(v9 + 416))
        | (1 << *(_DWORD *)(v9 + 436));
    if ( *(_BYTE *)(v9 + 598) == 1 )
    {
      v16 = *(_DWORD *)(v9 + 432);
      *(_BYTE *)(v7 + 254) = 1;
      v15 |= 1 << v16;
    }
    if ( *(_BYTE *)(v9 + 264) == 1 )
      v15 |= *(_DWORD *)(v7 + 64) << *(_DWORD *)(v9 + 252);
    cam_io_w_mb(v15, v12 + *(unsigned int *)(*(_QWORD *)(v7 + 264) + 28LL));
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_init_config_pxl_path",
        5246,
        "CSID:%u res:%s multi_vcdt_cfg0: 0x%x",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
        (const char *)(a2 + 128),
        v15);
  }
  if ( *(_BYTE *)(v13 + 32) == 1 )
  {
    v17 = (*(_DWORD *)(v7 + 80) << *(_DWORD *)(v9 + 256)) | (*(_DWORD *)(v13 + 28) << *(_DWORD *)(v9 + 424));
    if ( *(_BYTE *)(v13 + 44) == 1 )
      v17 |= (*(_DWORD *)(v13 + 40) << *(_DWORD *)(v9 + 428)) | (*(_DWORD *)(v7 + 96) << *(_DWORD *)(v9 + 260));
    cam_io_w_mb(v17, v12 + *(unsigned int *)(*(_QWORD *)(v7 + 264) + 32LL));
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_init_config_pxl_path",
        5266,
        "CSID:%u res:%s multi_vcdt_cfg1: 0x%x",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
        (const char *)(a2 + 128),
        v17);
  }
  if ( (*(_BYTE *)(*(_QWORD *)(v5 + 120) + 828LL) & 0x20) == 0 )
  {
    if ( *(_BYTE *)(a1 + 2149) != 1 )
    {
      v19 = 0;
LABEL_54:
      v22 = (*(unsigned __int8 *)(v7 + 246) << *(_DWORD *)(v6 + 376))
          | v19
          | (*(unsigned __int8 *)(v7 + 246) << *(_DWORD *)(v6 + 372));
      if ( *(_DWORD *)(v9 + 548) )
        v22 |= (*(unsigned __int8 *)(v7 + 247) << *(_DWORD *)(v6 + 380))
             | (*(unsigned __int8 *)(v7 + 247) << *(_DWORD *)(v6 + 384));
      v23 = *(_DWORD *)(a1 + 2168);
      v24 = (1 << *(_DWORD *)(v6 + 388)) | v22;
      if ( (v23 & 0x100) == 0
        && *(_DWORD *)(v9 + 568)
        && *(_BYTE *)(v7 + 246)
        && (*(_BYTE *)(a1 + 2159) != 1 || *(_DWORD *)(a2 + 4) != 6) )
      {
        v24 |= 1 << *(_DWORD *)(v6 + 392);
      }
      if ( (v23 & 0x80) != 0 )
        v24 |= 1 << *(_DWORD *)(v6 + 412);
      if ( (*(_BYTE *)(v9 + 596) & 1) == 0 )
        v24 |= (1 << *(_DWORD *)(v6 + 416)) | (*(_DWORD *)(v9 + 556) << *(_DWORD *)(v9 + 236));
      cam_io_w_mb(v24, v12 + *(unsigned int *)(*(_QWORD *)(v7 + 264) + 36LL));
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_ver2_init_config_pxl_path",
          5324,
          "CSID[%u] res:%s cfg1: 0x%x",
          *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
          (const char *)(a2 + 128),
          v24);
      goto LABEL_69;
    }
    v18 = *(_DWORD *)(v6 + 496);
    if ( (v18 & 1) != 0 )
    {
      v19 = *(_DWORD *)(v7 + 184) << *(_DWORD *)(v6 + 396);
      if ( (v18 & 4) == 0 )
        goto LABEL_47;
    }
    else
    {
      v19 = 0;
      if ( (v18 & 4) == 0 )
      {
LABEL_47:
        v21 = *(_DWORD *)(v7 + 192);
        if ( (v18 & 2) != 0 )
        {
          v19 |= v21 << *(_DWORD *)(v6 + 408);
          if ( !v21 )
          {
LABEL_51:
            if ( !*(_DWORD *)(v7 + 188) && !*(_DWORD *)(v7 + 184) )
              goto LABEL_54;
          }
        }
        else if ( !v21 )
        {
          goto LABEL_51;
        }
        v19 |= 1 << *(_DWORD *)(v6 + 404);
        goto LABEL_54;
      }
    }
    v19 |= *(_DWORD *)(v7 + 188) << *(_DWORD *)(v6 + 400);
    goto LABEL_47;
  }
LABEL_69:
  v25 = (1 << *(_DWORD *)(v9 + 280)) | v11;
  cam_io_w_mb(v25, v12 + *(unsigned int *)(*(_QWORD *)(v7 + 264) + 16LL));
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_init_config_pxl_path",
      5331,
      "CSID[%u] enabling path: %s cfg0: 0x%x",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
      (const char *)(a2 + 128),
      v25);
    v26 = *(_DWORD *)(v6 + 484);
    if ( !v26 )
      goto LABEL_73;
    goto LABEL_72;
  }
  v26 = *(_DWORD *)(v6 + 484);
  if ( v26 )
LABEL_72:
    cam_io_w_mb(*(_DWORD *)(*(_QWORD *)(v7 + 264) + 480LL) | v26, v12 + *(unsigned int *)(*(_QWORD *)(v7 + 264) + 52LL));
LABEL_73:
  if ( (*(_BYTE *)(a1 + 2168) & 0x80) != 0 )
  {
    v27 = cam_io_r_mb(v28 + *(unsigned int *)(*(_QWORD *)(v7 + 264) + 172LL) + *(unsigned int *)(v6 + 316));
    cam_io_w_mb(
      *(_DWORD *)(*(_QWORD *)(v5 + 120) + 772LL) | v27,
      v12 + *(unsigned int *)(*(_QWORD *)(v7 + 264) + 172LL));
  }
  cam_ife_csid_ver2_res_master_slave_cfg(a1, *(unsigned int *)(a2 + 4));
  *(_DWORD *)(a2 + 8) = 3;
  return 0;
}
