__int64 __fastcall cam_jpeg_dma_dump_camnoc_misr_val(unsigned int *a1, __int64 a2, _DWORD *a3)
{
  __int64 v4; // x23
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 v8; // x26
  unsigned int *v9; // x27
  unsigned int v10; // w8
  int v11; // w22
  unsigned int v12; // w25
  unsigned int v13; // w8
  _BOOL4 v15; // w28
  unsigned int v16; // w9
  unsigned int v17; // w9
  int v18; // w7
  __int64 result; // x0
  __int64 v20; // x8
  unsigned int v21; // w8
  __int64 v22; // x9
  unsigned int *v23; // x10
  __int64 v24; // x9
  _QWORD v25[5]; // [xsp+58h] [xbp-28h] BYREF

  v25[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v25, 0, 32);
  if ( !a3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dma_dump_camnoc_misr_val",
      450,
      "Invalid command argument");
    result = 4294967274LL;
LABEL_48:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v4 = *(_QWORD *)(a2 + 312);
  v6 = cam_io_r_mb(*(_QWORD *)(a2 + 288) + a1[7]);
  v7 = ((int)v6 >> a1[30]) & a1[29];
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
  {
    v6 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           debug_mdl & 0x200,
           4,
           "cam_jpeg_dma_dump_camnoc_misr_val",
           456,
           "index %d",
           v7);
    if ( !a1[45] )
      goto LABEL_36;
  }
  else if ( !a1[45] )
  {
    goto LABEL_36;
  }
  v6 = cam_io_r_mb(v4 + a1[35]);
  if ( (unsigned int)v7 > 1 )
    goto LABEL_59;
  v8 = 16 * v7;
  v9 = a1 + 65;
  v10 = a1[45];
  v11 = v6;
  v12 = a1[4 * v7 + 65];
  LODWORD(v25[2 * v7]) = v6;
  if ( v10 < 2 )
  {
    v18 = 1;
    if ( v12 != (_DWORD)v6 )
      goto LABEL_31;
LABEL_36:
    if ( (debug_mdl & 0x200) != 0 && !debug_priority )
    {
      if ( (unsigned int)v7 > 1 )
        goto LABEL_59;
      if ( ((16LL * (unsigned int)v7) | 0xCuLL) > 0x20 )
        goto LABEL_57;
      v24 = 16LL * (unsigned int)v7;
      if ( (v24 | 8uLL) > 0x20 || (v24 | 4uLL) > 0x20 )
        goto LABEL_57;
      v6 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             debug_mdl & 0x200,
             4,
             "cam_jpeg_dma_dump_camnoc_misr_val",
             484,
             "CAMNOC DMA_MISR req:%d SigData:0x %x %x %x %x",
             *a3,
             HIDWORD(v25[2 * (unsigned int)v7 + 1]),
             LODWORD(v25[2 * (unsigned int)v7 + 1]),
             HIDWORD(v25[2 * (unsigned int)v7]),
             LODWORD(v25[2 * (unsigned int)v7]));
      v21 = a1[45];
      if ( !v21 )
        goto LABEL_47;
    }
    else
    {
      v21 = a1[45];
      if ( !v21 )
        goto LABEL_47;
    }
    if ( (unsigned int)v7 <= 1 )
    {
      v22 = 16 * v7;
      v23 = a1 + 65;
      a1[4 * v7 + 65] = v25[2 * v7];
      if ( v21 == 1 )
        goto LABEL_47;
      if ( ((16 * v7) | 4uLL) <= 0x20 )
      {
        v23[(unsigned __int64)v22 / 4 + 1] = HIDWORD(v25[(unsigned __int64)v22 / 8]);
        if ( v21 == 2 )
          goto LABEL_47;
        if ( ((16 * v7) | 8uLL) <= 0x20 )
        {
          v23[(unsigned __int64)v22 / 4 + 2] = v25[(unsigned __int64)v22 / 8 + 1];
          if ( v21 != 3 )
          {
            if ( ((16 * v7) | 0xCuLL) <= 0x20 )
            {
              v23[(unsigned __int64)v22 / 4 + 3] = HIDWORD(v25[(unsigned __int64)v22 / 8 + 1]);
              if ( v21 == 4 )
                goto LABEL_47;
              goto LABEL_59;
            }
            goto LABEL_57;
          }
LABEL_47:
          cam_io_w_mb(a1[41], v4 + a1[34]);
          result = 0;
          goto LABEL_48;
        }
      }
LABEL_57:
      __break(1u);
LABEL_58:
      v6 = cam_io_r_mb(v4 + a1[35] + 32);
    }
LABEL_59:
    __break(0x5512u);
    goto LABEL_60;
  }
  v6 = cam_io_r_mb(v4 + a1[35] + 8);
  if ( ((16 * v7) | 4uLL) > 0x20 )
    goto LABEL_57;
  v13 = v9[(unsigned __int64)v8 / 4 + 1];
  HIDWORD(v25[(unsigned __int64)v8 / 8]) = v6;
  v15 = v13 != (_DWORD)v6 || v12 != v11;
  if ( a1[45] < 3 )
  {
    v18 = 2;
    if ( v15 )
      goto LABEL_31;
    goto LABEL_36;
  }
  v6 = cam_io_r_mb(v4 + a1[35] + 16);
  if ( ((16 * v7) | 8uLL) > 0x20 )
    goto LABEL_57;
  v16 = a1[45];
  if ( v9[(unsigned __int64)v8 / 4 + 2] != (_DWORD)v6 )
    v15 = 1;
  LODWORD(v25[(unsigned __int64)v8 / 8 + 1]) = v6;
  if ( v16 < 4 )
  {
    v18 = 3;
    if ( v15 )
      goto LABEL_31;
    goto LABEL_36;
  }
  v6 = cam_io_r_mb(v4 + a1[35] + 24);
  if ( ((16 * v7) | 0xCuLL) > 0x20 )
    goto LABEL_57;
  v17 = a1[45];
  if ( v9[(unsigned __int64)v8 / 4 + 3] != (_DWORD)v6 )
    v15 = 1;
  HIDWORD(v25[(unsigned __int64)v8 / 8 + 1]) = v6;
  if ( v17 >= 5 )
    goto LABEL_58;
  v18 = 4;
  if ( !v15 )
    goto LABEL_36;
LABEL_31:
  if ( *a3 == 1 )
    goto LABEL_36;
  if ( ((16LL * (unsigned int)v7) | 0xCuLL) > 0x20 )
    goto LABEL_57;
  v20 = 2LL * (unsigned int)v7;
  if ( ((v20 * 8) | 8uLL) > 0x20 || ((v20 * 8) | 4uLL) > 0x20 )
    goto LABEL_57;
  v6 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
         3,
         512,
         1,
         "cam_jpeg_dma_dump_camnoc_misr_val",
         476,
         "CAMNOC DMA_MISR MISMATCH [req:%d][i:%d][index:%d]\ncurr:0x%x %x %x %x prev:0x%x %x %x %x isbug:%d",
         *a3,
         v18,
         v7,
         HIDWORD(v25[v20 + 1]),
         LODWORD(v25[v20 + 1]),
         HIDWORD(v25[v20]),
         LODWORD(v25[v20]),
         a1[4 * v7 + 68],
         a1[4 * v7 + 67],
         a1[4 * v7 + 66],
         a1[4 * v7 + 65],
         *((unsigned __int8 *)a3 + 4));
  if ( *((_BYTE *)a3 + 4) != 1 )
    goto LABEL_36;
LABEL_60:
  __break(0x800u);
  return cam_jpeg_dma_dump_hw_misr_val(v6);
}
