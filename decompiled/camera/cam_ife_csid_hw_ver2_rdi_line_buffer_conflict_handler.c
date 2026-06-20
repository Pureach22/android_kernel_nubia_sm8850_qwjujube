__int64 __fastcall cam_ife_csid_hw_ver2_rdi_line_buffer_conflict_handler(__int64 a1)
{
  _QWORD *v2; // x22
  __int64 v3; // x21
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x23
  __int64 v7; // x7
  __int64 v8; // x8
  __int64 v9; // x23
  __int64 v10; // x7
  __int64 v11; // x8
  __int64 v12; // x23
  __int64 v13; // x7
  __int64 v14; // x8
  __int64 v15; // x22
  __int64 v16; // x7
  unsigned __int64 v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = **(_QWORD ***)(a1 + 31136);
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 31128) + 384LL);
  v17[0] = 0;
  result = (__int64)memset((void *)(a1 + 31160), 0, 0x400u);
  v5 = *(_QWORD *)(a1 + 24);
  if ( v5 )
  {
    v6 = v2[17];
    if ( (*(_BYTE *)(v6 + 584) & 4) != 0 )
    {
      result = cam_io_r_mb(v3 + *(unsigned int *)(*(_QWORD *)(v5 + 264) + 36LL) + *(unsigned int *)(v6 + 316));
      if ( (*(_DWORD *)(v6 + 388) & (unsigned int)result) != 0 )
        result = cam_print_to_buffer(a1 + 31160, 0x400u, v17, 1u, 8u, "LINE BUFFER ENABLED for RDI%d", 0, v7, v17[0]);
    }
  }
  v8 = *(_QWORD *)(a1 + 176);
  if ( v8 )
  {
    v9 = v2[18];
    if ( (*(_BYTE *)(v9 + 584) & 4) != 0 )
    {
      result = cam_io_r_mb(v3 + *(unsigned int *)(*(_QWORD *)(v8 + 264) + 36LL) + *(unsigned int *)(v9 + 316));
      if ( (*(_DWORD *)(v9 + 388) & (unsigned int)result) != 0 )
        result = cam_print_to_buffer(a1 + 31160, 0x400u, v17, 1u, 8u, "LINE BUFFER ENABLED for RDI%d", 1, v10, v17[0]);
    }
  }
  v11 = *(_QWORD *)(a1 + 328);
  if ( v11 )
  {
    v12 = v2[19];
    if ( (*(_BYTE *)(v12 + 584) & 4) != 0 )
    {
      result = cam_io_r_mb(v3 + *(unsigned int *)(*(_QWORD *)(v11 + 264) + 36LL) + *(unsigned int *)(v12 + 316));
      if ( (*(_DWORD *)(v12 + 388) & (unsigned int)result) != 0 )
        result = cam_print_to_buffer(a1 + 31160, 0x400u, v17, 1u, 8u, "LINE BUFFER ENABLED for RDI%d", 2, v13, v17[0]);
    }
  }
  v14 = *(_QWORD *)(a1 + 480);
  if ( v14 )
  {
    v15 = v2[20];
    if ( (*(_BYTE *)(v15 + 584) & 4) != 0 )
    {
      result = cam_io_r_mb(v3 + *(unsigned int *)(*(_QWORD *)(v14 + 264) + 36LL) + *(unsigned int *)(v15 + 316));
      if ( (*(_DWORD *)(v15 + 388) & (unsigned int)result) != 0 )
        result = cam_print_to_buffer(a1 + 31160, 0x400u, v17, 1u, 8u, "LINE BUFFER ENABLED for RDI%d", 3, v16, v17[0]);
    }
  }
  if ( v17[0] )
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               1,
               "cam_ife_csid_hw_ver2_rdi_line_buffer_conflict_handler",
               2545,
               "CSID[%u] %s",
               *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
               (const char *)(a1 + 31160));
  _ReadStatusReg(SP_EL0);
  return result;
}
