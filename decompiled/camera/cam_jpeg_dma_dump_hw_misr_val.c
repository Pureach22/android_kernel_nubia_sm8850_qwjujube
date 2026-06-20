__int64 __fastcall cam_jpeg_dma_dump_hw_misr_val(_DWORD *a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x27
  __int64 v5; // x0
  __int64 v6; // x19
  __int64 v7; // x22
  __int64 v8; // x23
  __int64 v9; // x26
  _DWORD *v10; // x25
  unsigned int v11; // w8
  int v12; // w24
  int v13; // w21
  _BOOL4 v14; // w28
  bool v15; // cf
  int v16; // w8
  int v17; // w8
  bool v18; // zf
  unsigned int v19; // w9
  unsigned int v20; // w9
  __int64 v21; // x9
  int v22; // w8
  __int64 v23; // x9
  _DWORD *v24; // x10
  __int64 v25; // x27
  _DWORD *v26; // x26
  unsigned int v27; // w8
  int v28; // w24
  int v29; // w28
  _BOOL4 v30; // w25
  int v31; // w8
  int v32; // w8
  bool v33; // zf
  unsigned int v34; // w9
  unsigned int v35; // w9
  __int64 v36; // x9
  int v37; // w8
  __int64 v38; // x9
  _DWORD *v39; // x10
  __int64 result; // x0
  __int64 v41; // x9
  __int64 v42; // x9
  __int64 v43; // x0
  __int64 v44; // [xsp+50h] [xbp-60h]
  _QWORD v46[4]; // [xsp+60h] [xbp-50h] BYREF
  _QWORD v47[6]; // [xsp+80h] [xbp-30h] BYREF

  v47[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v47, 0, 32);
  memset(v46, 0, sizeof(v46));
  if ( !a3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dma_dump_hw_misr_val",
      512,
      "Invalid command argument");
    result = 4294967274LL;
    goto LABEL_81;
  }
  v3 = *(_QWORD *)(a2 + 288);
  v5 = cam_io_r_mb(v3 + (unsigned int)a1[7]);
  v6 = (unsigned int)((int)v5 >> a1[30]) & a1[29];
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
    v5 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           debug_mdl & 0x200,
           4,
           "cam_jpeg_dma_dump_hw_misr_val",
           518,
           "index %d",
           v6);
  v44 = (int)a1[9];
  if ( a1[43] )
  {
    v7 = v3 + v44;
    v8 = v3 + v44 + 4;
    cam_io_w_mb(0, v3 + v44);
    v5 = cam_io_r_mb(v8);
    if ( (unsigned int)v6 > 1 )
      goto LABEL_98;
    v9 = 16 * v6;
    v10 = a1 + 57;
    v11 = a1[43];
    v12 = v5;
    v13 = a1[4 * v6 + 57];
    LODWORD(v46[2 * v6]) = v5;
    v14 = v13 != v5;
    v15 = v11 >= 2;
    v16 = 1;
    if ( v15 )
    {
      cam_io_w_mb((unsigned int)(1 << a1[47]), v7);
      v5 = cam_io_r_mb(v8);
      if ( ((16 * v6) | 4uLL) > 0x20 )
        goto LABEL_94;
      v17 = v10[(unsigned __int64)v9 / 4 + 1];
      HIDWORD(v46[(unsigned __int64)v9 / 8]) = v5;
      v18 = v17 == (_DWORD)v5 && v13 == v12;
      v14 = !v18;
      v16 = 2;
      if ( a1[43] >= 3u )
      {
        cam_io_w_mb((unsigned int)(2 << a1[47]), v7);
        v5 = cam_io_r_mb(v8);
        if ( ((16 * v6) | 8uLL) > 0x20 )
          goto LABEL_94;
        v19 = a1[43];
        if ( v10[(unsigned __int64)v9 / 4 + 2] != (_DWORD)v5 )
          v14 = 1;
        LODWORD(v46[(unsigned __int64)v9 / 8 + 1]) = v5;
        v16 = 3;
        if ( v19 >= 4 )
        {
          cam_io_w_mb((unsigned int)(3 << a1[47]), v7);
          v5 = cam_io_r_mb(v8);
          if ( ((16 * v6) | 0xCuLL) > 0x20 )
            goto LABEL_94;
          v20 = a1[43];
          if ( v10[(unsigned __int64)v9 / 4 + 3] != (_DWORD)v5 )
            v14 = 1;
          HIDWORD(v46[(unsigned __int64)v9 / 8 + 1]) = v5;
          v16 = 4;
          if ( v20 >= 5 )
          {
            v43 = (unsigned int)(4 << a1[47]);
LABEL_97:
            cam_io_w_mb(v43, v7);
            v5 = cam_io_r_mb(v8);
            goto LABEL_98;
          }
        }
      }
    }
    if ( v14 && *a3 != 1 )
    {
      if ( ((16LL * (unsigned int)v6) | 0xCuLL) > 0x20 )
        goto LABEL_94;
      v21 = 2LL * (unsigned int)v6;
      if ( ((v21 * 8) | 8uLL) > 0x20 || ((v21 * 8) | 4uLL) > 0x20 )
        goto LABEL_94;
      v5 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             512,
             1,
             "cam_jpeg_dma_dump_hw_misr_val",
             543,
             "CAMNOC DMA_RD_MISR MISMATCH [req:%d][index:%d][i:%d]\ncurr:0x%x %x %x %x prev:0x%x %x %x %x isbug:%d",
             *a3,
             v6,
             v16,
             HIDWORD(v46[v21 + 1]),
             LODWORD(v46[v21 + 1]),
             HIDWORD(v46[v21]),
             LODWORD(v46[v21]),
             a1[4 * v6 + 60],
             a1[4 * v6 + 59],
             a1[4 * v6 + 58],
             a1[4 * v6 + 57],
             *((unsigned __int8 *)a3 + 4));
      if ( *((_BYTE *)a3 + 4) == 1 )
      {
LABEL_99:
        __break(0x800u);
        goto LABEL_100;
      }
    }
  }
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
  {
    if ( (unsigned int)v6 > 1 )
      goto LABEL_98;
    if ( ((16LL * (unsigned int)v6) | 0xCuLL) > 0x20 )
      goto LABEL_94;
    v41 = 16LL * (unsigned int)v6;
    if ( (v41 | 8uLL) > 0x20 || (v41 | 4uLL) > 0x20 )
      goto LABEL_94;
    v5 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           debug_mdl & 0x200,
           4,
           "cam_jpeg_dma_dump_hw_misr_val",
           551,
           "CORE JPEG DMA RD MISR: 0x%x %x %x %x",
           HIDWORD(v46[2 * (unsigned int)v6 + 1]),
           LODWORD(v46[2 * (unsigned int)v6 + 1]),
           HIDWORD(v46[2 * (unsigned int)v6]),
           LODWORD(v46[2 * (unsigned int)v6]));
    v22 = a1[43];
    if ( !v22 )
      goto LABEL_42;
  }
  else
  {
    v22 = a1[43];
    if ( !v22 )
      goto LABEL_42;
  }
  if ( (unsigned int)v6 > 1 )
    goto LABEL_98;
  v23 = 16 * v6;
  v24 = a1 + 57;
  a1[4 * v6 + 57] = v46[2 * v6];
  if ( v22 != 1 )
  {
    if ( ((16 * v6) | 4uLL) > 0x20 )
      goto LABEL_94;
    v24[(unsigned __int64)v23 / 4 + 1] = HIDWORD(v46[(unsigned __int64)v23 / 8]);
    if ( v22 != 2 )
    {
      if ( ((16 * v6) | 8uLL) > 0x20 )
        goto LABEL_94;
      v24[(unsigned __int64)v23 / 4 + 2] = v46[(unsigned __int64)v23 / 8 + 1];
      if ( v22 != 3 )
      {
        if ( ((16 * v6) | 0xCuLL) > 0x20 )
          goto LABEL_94;
        v24[(unsigned __int64)v23 / 4 + 3] = HIDWORD(v46[(unsigned __int64)v23 / 8 + 1]);
        if ( v22 != 4 )
          goto LABEL_98;
      }
    }
  }
LABEL_42:
  if ( !a1[44] )
  {
LABEL_68:
    if ( (debug_mdl & 0x200) != 0 && !debug_priority )
    {
      if ( (unsigned int)v6 > 1 )
        goto LABEL_98;
      if ( ((16LL * (unsigned int)v6) | 0xCuLL) > 0x20 )
        goto LABEL_94;
      v42 = 16LL * (unsigned int)v6;
      if ( (v42 | 8uLL) > 0x20 || (v42 | 4uLL) > 0x20 )
        goto LABEL_94;
      v5 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             debug_mdl & 0x200,
             4,
             "cam_jpeg_dma_dump_hw_misr_val",
             587,
             "CORE JPEG DMA WR MISR: 0x%x %x %x %x",
             HIDWORD(v47[2 * (unsigned int)v6 + 1]),
             LODWORD(v47[2 * (unsigned int)v6 + 1]),
             HIDWORD(v47[2 * (unsigned int)v6]),
             LODWORD(v47[2 * (unsigned int)v6]));
      v37 = a1[44];
      if ( !v37 )
        goto LABEL_79;
    }
    else
    {
      v37 = a1[44];
      if ( !v37 )
        goto LABEL_79;
    }
    if ( (unsigned int)v6 <= 1 )
    {
      v38 = 16 * v6;
      v39 = a1 + 49;
      a1[4 * v6 + 49] = v47[2 * v6];
      if ( v37 != 1 )
      {
        if ( ((16 * v6) | 4uLL) > 0x20 )
          goto LABEL_94;
        v39[(unsigned __int64)v38 / 4 + 1] = HIDWORD(v47[(unsigned __int64)v38 / 8]);
        if ( v37 != 2 )
        {
          if ( ((16 * v6) | 8uLL) > 0x20 )
            goto LABEL_94;
          v39[(unsigned __int64)v38 / 4 + 2] = v47[(unsigned __int64)v38 / 8 + 1];
          if ( v37 != 3 )
          {
            if ( ((16 * v6) | 0xCuLL) <= 0x20 )
            {
              v39[(unsigned __int64)v38 / 4 + 3] = HIDWORD(v47[(unsigned __int64)v38 / 8 + 1]);
              if ( v37 == 4 )
                goto LABEL_79;
              goto LABEL_98;
            }
LABEL_94:
            __break(1u);
          }
        }
      }
LABEL_79:
      result = 0;
LABEL_81:
      _ReadStatusReg(SP_EL0);
      return result;
    }
LABEL_98:
    __break(0x5512u);
    goto LABEL_99;
  }
  v7 = v3 + v44;
  v8 = v3 + v44 + 4;
  cam_io_w_mb((unsigned int)a1[46], v3 + v44);
  v5 = cam_io_r_mb(v8);
  if ( (unsigned int)v6 >= 2 )
    goto LABEL_98;
  v25 = 16 * v6;
  v26 = a1 + 49;
  v27 = a1[44];
  v28 = v5;
  v29 = a1[4 * v6 + 49];
  LODWORD(v47[2 * v6]) = v5;
  v30 = v29 != v5;
  v15 = v27 >= 2;
  v31 = 1;
  if ( v15 )
  {
    cam_io_w_mb((unsigned int)(1 << a1[47]) | a1[46], v7);
    v5 = cam_io_r_mb(v8);
    if ( ((16 * v6) | 4uLL) > 0x20 )
      goto LABEL_94;
    v32 = v26[(unsigned __int64)v25 / 4 + 1];
    HIDWORD(v47[(unsigned __int64)v25 / 8]) = v5;
    v33 = v32 == (_DWORD)v5 && v29 == v28;
    v30 = !v33;
    v31 = 2;
    if ( a1[44] >= 3u )
    {
      cam_io_w_mb((unsigned int)(2 << a1[47]) | a1[46], v7);
      v5 = cam_io_r_mb(v8);
      if ( ((16 * v6) | 8uLL) > 0x20 )
        goto LABEL_94;
      v34 = a1[44];
      if ( v26[(unsigned __int64)v25 / 4 + 2] != (_DWORD)v5 )
        v30 = 1;
      LODWORD(v47[(unsigned __int64)v25 / 8 + 1]) = v5;
      v31 = 3;
      if ( v34 >= 4 )
      {
        cam_io_w_mb((unsigned int)(3 << a1[47]) | a1[46], v7);
        v5 = cam_io_r_mb(v8);
        if ( ((16 * v6) | 0xCuLL) > 0x20 )
          goto LABEL_94;
        v35 = a1[44];
        if ( v26[(unsigned __int64)v25 / 4 + 3] != (_DWORD)v5 )
          v30 = 1;
        HIDWORD(v47[(unsigned __int64)v25 / 8 + 1]) = v5;
        v31 = 4;
        if ( v35 >= 5 )
        {
          v43 = (unsigned int)(4 << a1[47]) | a1[46];
          goto LABEL_97;
        }
      }
    }
  }
  if ( !v30 || *a3 == 1 )
    goto LABEL_68;
  if ( ((16LL * (unsigned int)v6) | 0xCuLL) > 0x20 )
    goto LABEL_94;
  v36 = 2LL * (unsigned int)v6;
  if ( ((v36 * 8) | 8uLL) > 0x20 || ((v36 * 8) | 4uLL) > 0x20 )
    goto LABEL_94;
  v5 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
         3,
         512,
         1,
         "cam_jpeg_dma_dump_hw_misr_val",
         580,
         "CAMNOC DMA_WR_MISR MISMATCH [req:%d][index:%d][i:%d]\ncurr:0x%x %x %x %x prev:0x%x %x %x %x isbug:%d",
         *a3,
         v6,
         v31,
         HIDWORD(v47[v36 + 1]),
         LODWORD(v47[v36 + 1]),
         HIDWORD(v47[v36]),
         LODWORD(v47[v36]),
         a1[4 * v6 + 52],
         a1[4 * v6 + 51],
         a1[4 * v6 + 50],
         a1[4 * v6 + 49],
         *((unsigned __int8 *)a3 + 4));
  if ( *((_BYTE *)a3 + 4) != 1 )
    goto LABEL_68;
LABEL_100:
  __break(0x800u);
  return cam_jpeg_dma_config_cmanoc_hw_misr(v5);
}
