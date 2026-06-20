__int64 __fastcall cam_ife_csid_ver2_parse_path_irq_status(
        __int64 a1,
        __int64 a2,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 *v10; // x8
  _QWORD *v11; // x22
  __int64 v12; // x23
  const char *v13; // x26
  unsigned int v14; // w21
  char **irq_reg_tag_ptr; // x25
  __int64 v16; // x28
  unsigned __int64 v17; // x27
  bool v18; // cc
  __int64 v19; // x8
  __int64 v20; // x7
  __int64 v21; // x8
  __int64 v22; // x6
  __int64 v23; // x6
  int v24; // w9
  __int64 v25; // x6
  __int64 v26; // x7
  __int64 v27; // x6
  __int64 v28; // x7
  void (__fastcall *v29)(__int64, __int64); // x8
  unsigned int v30; // w21
  __int64 v31; // x28
  __int64 v32; // x8
  __int64 v33; // x7
  __int64 v34; // x8
  __int64 v35; // x6
  __int64 v36; // x6
  void (__fastcall *v37)(__int64, __int64); // x8
  unsigned int v38; // w28
  __int64 v39; // x27
  unsigned __int64 v40; // x21
  __int64 v41; // x8
  __int64 v42; // x24
  int v43; // w9
  __int64 v44; // x25
  __int64 v45; // x8
  __int64 v46; // x26
  unsigned __int64 v47; // x21
  __int64 v48; // x27
  unsigned int v49; // w23
  unsigned int v50; // w8
  char v52; // [xsp+0h] [xbp-160h]
  char v53; // [xsp+0h] [xbp-160h]
  char v54; // [xsp+0h] [xbp-160h]
  unsigned int v58; // [xsp+34h] [xbp-12Ch]
  unsigned __int64 v59; // [xsp+38h] [xbp-128h] BYREF
  int v60; // [xsp+44h] [xbp-11Ch] BYREF
  unsigned __int64 v61; // [xsp+48h] [xbp-118h] BYREF
  _QWORD v62[34]; // [xsp+50h] [xbp-110h] BYREF

  v62[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(__int64 **)(a1 + 31136);
  v59 = 0;
  v11 = *(_QWORD **)(a2 + 24);
  v12 = *v10;
  v60 = 0;
  v13 = (const char *)(a1 + 31160);
  v14 = a6 & a4;
  irq_reg_tag_ptr = cam_ife_csid_get_irq_reg_tag_ptr();
  if ( v14 )
  {
    v16 = 0;
    v17 = 0;
    v58 = 0;
    while ( v17 < *(unsigned int *)(v12 + 608) )
    {
      v59 = 0;
      if ( (v14 & 1) != 0 )
      {
        v19 = *(_QWORD *)(v12 + 584);
        if ( *(_DWORD *)(v19 + v16) )
        {
          cam_print_to_buffer(
            (__int64)v13,
            0x400u,
            &v59,
            1u,
            8u,
            "CSID[%u] %s occurred at [%llu: %09llu]",
            *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL),
            *(_QWORD *)(v19 + v16 + 8),
            *v11);
          v21 = *(_QWORD *)(v12 + 584);
          v22 = *(_QWORD *)(v21 + v16 + 16);
          if ( v22 )
          {
            cam_print_to_buffer((__int64)v13, 0x400u, &v59, 1u, 8u, "%s", v22, v20, v52);
            v21 = *(_QWORD *)(v12 + 584);
          }
          v23 = *(_QWORD *)(v21 + v16 + 24);
          if ( v23 )
          {
            cam_print_to_buffer((__int64)v13, 0x400u, &v59, 1u, 8u, "Debug: %s", v23, v20, v52);
            v21 = *(_QWORD *)(v12 + 584);
          }
          v24 = *(_DWORD *)(v21 + v16 + 4);
          if ( v24 )
          {
            if ( v24 == 32 )
            {
              cam_print_to_buffer((__int64)v13, 0x400u, &v59, 1u, 8u, "1. MUP programmed without RUP", v23, v20, v52);
              cam_print_to_buffer(
                (__int64)v13,
                0x400u,
                &v59,
                1u,
                8u,
                "2. Early EOF enabled with vCrop disabled",
                v25,
                v26,
                v53);
              cam_print_to_buffer(
                (__int64)v13,
                0x400u,
                &v59,
                1u,
                8u,
                "3. Mismatch in the decode formats configured for multi vc-dt",
                v27,
                v28,
                v54);
              v21 = *(_QWORD *)(v12 + 584);
              v24 = *(_DWORD *)(v21 + v16 + 4);
            }
            v58 |= v24;
          }
          v29 = *(void (__fastcall **)(__int64, __int64))(v21 + v16 + 32);
          if ( v29 )
          {
            if ( *((_DWORD *)v29 - 1) != -72220 )
              __break(0x8228u);
            v29(a1, a2);
          }
        }
      }
      if ( v59 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver2_parse_path_irq_status",
          2890,
          "CSID[%u] %s status: 0x%x Errors:%s",
          *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
          irq_reg_tag_ptr[a3],
          a6,
          v13);
      v18 = v14 > 1;
      ++v17;
      v16 += 40;
      v14 >>= 1;
      if ( !v18 )
        goto LABEL_24;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_parse_path_irq_status",
      2849,
      "Invalid bit position: %u for path reg",
      v17);
  }
  else
  {
    v17 = 0;
    v58 = 0;
  }
LABEL_24:
  v30 = a6 & a5;
  if ( (a6 & a5) != 0 )
  {
    v31 = 40 * v17;
    while ( v17 < *(unsigned int *)(v12 + 608) )
    {
      v59 = 0;
      if ( (v30 & 1) != 0 )
      {
        v32 = *(_QWORD *)(v12 + 584);
        if ( *(_DWORD *)(v32 + v31) )
        {
          cam_print_to_buffer(
            (__int64)v13,
            0x400u,
            &v59,
            2u,
            8u,
            "CSID[%u] %s occurred at [%llu: %09llu]",
            *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL),
            *(_QWORD *)(v32 + v31 + 8),
            *v11);
          v34 = *(_QWORD *)(v12 + 584);
          v35 = *(_QWORD *)(v34 + v31 + 16);
          if ( v35 )
          {
            cam_print_to_buffer((__int64)v13, 0x400u, &v59, 2u, 8u, "%s", v35, v33, v52);
            v34 = *(_QWORD *)(v12 + 584);
          }
          v36 = *(_QWORD *)(v34 + v31 + 24);
          if ( v36 )
          {
            cam_print_to_buffer((__int64)v13, 0x400u, &v59, 2u, 8u, "Debug: %s", v36, v33, v52);
            v34 = *(_QWORD *)(v12 + 584);
          }
          v37 = *(void (__fastcall **)(__int64, __int64))(v34 + v31 + 32);
          if ( v37 )
          {
            if ( *((_DWORD *)v37 - 1) != -72220 )
              __break(0x8228u);
            v37(a1, a2);
          }
        }
      }
      if ( v59 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_ife_csid_ver2_parse_path_irq_status",
          2924,
          "CSID[%u] %s status: 0x%x Errors:%s",
          *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
          irq_reg_tag_ptr[a3],
          a6,
          v13);
      v18 = v30 > 1;
      ++v17;
      v31 += 40;
      v30 >>= 1;
      if ( !v18 )
        goto LABEL_42;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_parse_path_irq_status",
      2899,
      "Invalid bit position: %u for path reg",
      v17);
  }
LABEL_42:
  v38 = *(_DWORD *)(a1 + 2200) & a6;
  if ( v38 )
  {
    v39 = 0;
    v40 = 0;
    while ( v40 < *(unsigned int *)(v12 + 608) )
    {
      if ( (v38 & 1) != 0 )
      {
        v41 = *(_QWORD *)(v12 + 584);
        if ( *(_DWORD *)(v41 + v39) )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            3,
            "cam_ife_csid_ver2_parse_path_irq_status",
            2943,
            "CSID[%u] IRQ %s %s timestamp: [%lld:%09lld]",
            *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
            irq_reg_tag_ptr[a3],
            *(const char **)(v41 + v39 + 8),
            *(_QWORD *)(a7 + 24),
            *(_QWORD *)(a7 + 32));
      }
      v18 = v38 > 1;
      ++v40;
      v39 += 40;
      v38 >>= 1;
      if ( !v18 )
        goto LABEL_51;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_parse_path_irq_status",
      2934,
      "Invalid bit position: %u for path reg",
      v40);
  }
LABEL_51:
  if ( *(_BYTE *)(a1 + 2216) == 1 && (a6 & 0x200) != 0 && *(_DWORD *)(a1 + 2220) == *(_DWORD *)(a2 + 4) )
  {
    v61 = 0;
    memset(v62, 0, 256);
    if ( a1 )
    {
      v42 = **(_QWORD **)(a1 + 31136);
      v43 = *(_DWORD *)(a1 + 2144) + 1;
      v44 = *(_QWORD *)(*(_QWORD *)(a1 + 31128) + 384LL);
      *(_DWORD *)(a1 + 2144) = v43;
      v45 = *(_QWORD *)(v42 + 120);
      if ( *(_DWORD *)(v45 + 692) )
      {
        v46 = 0;
        v47 = 0;
        v48 = a1 + 2224;
        do
        {
          if ( v46 == 12 )
            __break(0x5512u);
          if ( (unsigned int)cam_io_r_mb(v44 + *(unsigned int *)(v45 + 4 * v46 + 188)) )
          {
            v49 = cam_io_r_mb(v44 + *(unsigned int *)(*(_QWORD *)(v42 + 120) + 4 * v46 + 184));
            cam_io_w_mb(*(unsigned int *)(v48 + v46), v44 + *(unsigned int *)(*(_QWORD *)(v42 + 120) + 4 * v46 + 176));
            cam_io_w_mb(
              *(unsigned int *)(v48 + v46 + 12),
              v44 + *(unsigned int *)(*(_QWORD *)(v42 + 120) + 4 * v46 + 180));
            cam_print_to_buffer(
              (__int64)v62,
              0x100u,
              &v61,
              3u,
              8u,
              "counter idx:%d val: 0x%x",
              (unsigned int)v47,
              v49,
              v52);
          }
          v45 = *(_QWORD *)(v42 + 120);
          ++v47;
          v46 += 4;
        }
        while ( v47 < *(unsigned int *)(v45 + 692) );
        v43 = *(_DWORD *)(a1 + 2144);
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_ife_csid_ver2_read_rst_perf_counters",
        2818,
        "CSID[%u] res: %s Frame:%u perf counters %s ",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
        (const char *)(a2 + 128),
        v43,
        (const char *)v62);
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_read_rst_perf_counters",
        2785,
        "Invalid args csid_hw:%s res:%s",
        "NULL",
        "Non-NULL");
    }
  }
  if ( *(_BYTE *)(a1 + 2150) == 1 )
  {
    v50 = *(_DWORD *)(a1 + 2132);
    if ( (a6 & 0x1000) != 0 )
      *(_DWORD *)(a1 + 2132) = ++v50;
    if ( v50 >= 0xC )
    {
      cam_ife_csid_ver2_sof_irq_debug(a1, &v60);
      *(_DWORD *)(a1 + 2132) = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v58;
}
