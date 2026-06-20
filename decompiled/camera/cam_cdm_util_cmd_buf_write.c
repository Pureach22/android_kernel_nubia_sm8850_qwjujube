__int64 __fastcall cam_cdm_util_cmd_buf_write(__int64 *a1, _DWORD *a2, unsigned int a3, __int64 a4, unsigned int a5)
{
  unsigned int v7; // w22
  __int64 *v9; // x26
  __int64 v10; // x23
  unsigned int v11; // w25
  __int64 v12; // x27
  _QWORD *v13; // x0
  __int64 v14; // x27
  __int64 v15; // x9
  unsigned int v16; // w0
  int v17; // w23
  unsigned int *v18; // x24
  unsigned int v19; // w8
  unsigned int v20; // w25
  __int64 v21; // x26
  unsigned int v22; // t1
  __int64 v23; // x6
  int v24; // w9
  __int64 v25; // x8
  __int64 v26; // x24
  int v27; // w25
  __int64 v28; // x25
  unsigned __int64 v29; // x23
  __int64 v30; // x0
  unsigned int v31; // w24
  unsigned int v32; // w27
  unsigned int v33; // w25
  __int64 v34; // x26
  unsigned int v35; // w25
  __int64 v36; // x26
  unsigned int v37; // t1
  __int64 v38; // x8
  _QWORD *v39; // x25
  unsigned int v40; // w23
  unsigned int *v41; // x26
  unsigned int v42; // w8
  const char *v43; // x5
  __int64 v44; // x4
  const char *v46; // x3
  __int64 v47; // x4
  __int64 v49; // [xsp+20h] [xbp-20h] BYREF
  __int64 v50; // [xsp+28h] [xbp-18h] BYREF
  int v51; // [xsp+30h] [xbp-10h]
  __int64 v52; // [xsp+38h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 )
  {
    v31 = 0;
    goto LABEL_72;
  }
  v7 = a3;
  v9 = a1;
  LODWORD(v10) = 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (debug_mdl & 1) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_cdm_util_cmd_buf_write",
        767,
        "cmd data=%x",
        *a2);
    v11 = HIBYTE(*a2);
    if ( v11 > 7 )
    {
      if ( v11 - 115 >= 2 )
      {
        if ( v11 == 8 )
        {
          v23 = *a2 & 0xFFFFFF;
          if ( a5 )
          {
            v24 = 0;
            while ( 1 )
            {
              v25 = *(_QWORD *)(a4 + 8LL * v24);
              v26 = v24;
              if ( v25 )
              {
                if ( (debug_mdl & 1) == 0
                  || debug_priority
                  || (v27 = v23,
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        1,
                        4,
                        "cam_cdm_get_ioremap_from_base",
                        482,
                        "In loop %d ioremap for %x addr=%x",
                        v24,
                        *(_DWORD *)(v25 + 8),
                        v23),
                      v25 = *(_QWORD *)(a4 + 8 * v26),
                      LODWORD(v23) = v27,
                      v25) )
                {
                  if ( *(_DWORD *)(v25 + 8) == (_DWORD)v23 )
                    break;
                }
              }
              v24 = v26 + 1;
              if ( a5 == (_DWORD)v26 + 1 )
              {
                v23 = *a2 & 0xFFFFFF;
                goto LABEL_70;
              }
            }
            *v9 = *(_QWORD *)v25;
            if ( (debug_mdl & 1) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                1,
                4,
                "cam_cdm_util_cmd_buf_write",
                833,
                "Got ioremap for %x addr=%pK",
                *a2 & 0xFFFFFF,
                v9);
            v31 = 0;
            v7 -= 4;
            ++a2;
            goto LABEL_42;
          }
LABEL_70:
          v43 = "Get ioremap change base failed %x";
          v44 = 828;
        }
        else
        {
LABEL_75:
          v43 = "unsupported cdm_cmd_type type 0%x";
          v44 = 841;
LABEL_76:
          v23 = v11;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_util_cmd_buf_write",
          v44,
          v43,
          v23);
        v31 = -22;
        goto LABEL_72;
      }
LABEL_13:
      v14 = *v9;
      if ( !*v9 )
      {
        v43 = "Got SWI DMI cmd =%d for invalid hw";
        v44 = 802;
        goto LABEL_76;
      }
      v49 = 0;
      v15 = *(_QWORD *)a2;
      v51 = a2[2];
      v50 = v15;
      v16 = cam_cdm_util_cmd_buf_validation(v14, a5, a4, v7, &v50, &v49, v11);
      if ( v16 )
      {
        v31 = v16;
        v46 = "cam_cdm_util_swd_dmi_write";
        v47 = 724;
        goto LABEL_78;
      }
      v17 = (unsigned __int16)v50;
      v18 = a2 + 3;
      v19 = (unsigned __int16)v50 + 1;
      if ( v11 == 116 )
      {
        if ( (unsigned __int16)v50 >= 7u )
        {
          v33 = v19 >> 3;
          v34 = v14 + (v51 & 0xFFFFFFLL);
          do
          {
            cam_io_w_mb(*v18, v34 + 12);
            cam_io_w_mb(v18[1], v34 + 8);
            --v33;
            v18 += 2;
          }
          while ( v33 );
        }
      }
      else if ( v11 == 1 )
      {
        if ( (unsigned __int16)v50 >= 3u )
        {
          v20 = v19 >> 2;
          v21 = v14 + (v51 & 0xFFFFFFLL);
          do
          {
            v22 = *v18++;
            cam_io_w_mb(v22, v21 + 8);
            --v20;
          }
          while ( v20 );
        }
      }
      else if ( (unsigned __int16)v50 >= 3u )
      {
        v35 = v19 >> 2;
        v36 = v14 + (v51 & 0xFFFFFFLL);
        do
        {
          v37 = *v18++;
          cam_io_w_mb(v37, v36 + 12);
          --v35;
        }
        while ( v35 );
      }
      LODWORD(v10) = v17 + 13;
      v9 = a1;
      v31 = 0;
      v38 = v10 & 0x1FFFC;
      goto LABEL_41;
    }
    if ( v11 == 1 )
      goto LABEL_13;
    if ( v11 == 3 )
      break;
    if ( v11 != 4 )
      goto LABEL_75;
    v12 = *v9;
    v50 = 0;
    if ( mem_trace_en == 1 )
      v13 = (_QWORD *)cam_mem_trace_alloc(v7, 0xCC0u, 0, "cam_cdm_util_reg_random_write", 0x2A6u);
    else
      v13 = (_QWORD *)_kvmalloc_node_noprof(v7, 0, 3520, 0xFFFFFFFFLL);
    v39 = v13;
    if ( !v13 )
    {
      v31 = -12;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_util_reg_random_write",
        680,
        "Mem alloc failed! rc=%d",
        -12);
      goto LABEL_72;
    }
    memcpy(v13, a2, v7);
    v31 = cam_cdm_util_cmd_buf_validation(v12, a5, a4, v7, v39, &v50, 4);
    if ( v31 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_util_reg_random_write",
        688,
        "Validation failed! rc=%d",
        v31);
    }
    else if ( *(_WORD *)v39 )
    {
      v40 = 0;
      v41 = (unsigned int *)(v39 + 1);
      do
      {
        if ( (debug_mdl & 1) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            4,
            "cam_cdm_util_reg_random_write",
            698,
            "reg random: offset %pK, value 0x%x",
            (const void *)(v12 + *(v41 - 1)),
            *v41);
        cam_io_w(*v41, v12 + *(v41 - 1));
        v42 = *(unsigned __int16 *)v39;
        ++v40;
        v41 += 2;
      }
      while ( v40 < v42 );
      v9 = a1;
      LODWORD(v10) = (8 * v42) | 4;
    }
    else
    {
      LODWORD(v10) = 4;
    }
    if ( mem_trace_en != 1 )
    {
      kvfree(v39);
      if ( v31 )
        goto LABEL_42;
LABEL_65:
      if ( !(_DWORD)v10 )
        goto LABEL_42;
      v38 = (unsigned int)v10 & 0xFFFFFFFC;
      v31 = 0;
LABEL_41:
      v7 -= v10;
      a2 = (_DWORD *)((char *)a2 + v38);
      goto LABEL_42;
    }
    cam_mem_trace_free(v39, 0);
    if ( !v31 )
      goto LABEL_65;
LABEL_42:
    if ( (v31 & 0x80000000) != 0 || !v7 )
      goto LABEL_72;
  }
  v49 = 0;
  v28 = *v9;
  v29 = *(_QWORD *)a2;
  v30 = *v9;
  v50 = *(_QWORD *)a2;
  v31 = cam_cdm_util_cmd_buf_validation(v30, a5, a4, v7, &v50, &v49, 3);
  if ( !v31 )
  {
    v32 = 4 * (unsigned __int16)v29;
    cam_io_memcpy(v28 + (HIDWORD(v29) & 0xFFFFFF), a2 + 2, v32);
    v10 = v32 + 8;
    v7 -= v10;
    a2 = (_DWORD *)((char *)a2 + v10);
    goto LABEL_42;
  }
  v46 = "cam_cdm_util_reg_cont_write";
  v47 = 654;
LABEL_78:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    1,
    1,
    v46,
    v47,
    "Validation failed! rc=%d",
    v31);
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return v31;
}
