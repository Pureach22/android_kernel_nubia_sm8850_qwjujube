__int64 __fastcall cam_sfe_bus_start_rm(__int64 a1)
{
  __int64 v2; // x21
  _DWORD *v3; // x22
  int v4; // w19
  __int64 v5; // x0
  int v6; // w8
  unsigned int v8; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+48h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 24);
  v8 = 0;
  v3 = *(_DWORD **)v2;
  cam_sfe_bus_rd_pxls_to_bytes(*(unsigned int *)(v2 + 40), *(unsigned int *)(v2 + 60), &v8);
  v4 = v8;
  cam_io_w_mb(v8, *((_QWORD *)v3 + 1) + *(unsigned int *)(*(_QWORD *)(v2 + 8) + 8LL));
  cam_io_w_mb(*(unsigned int *)(v2 + 44), *((_QWORD *)v3 + 1) + *(unsigned int *)(*(_QWORD *)(v2 + 8) + 12LL));
  cam_io_w_mb(*(unsigned int *)(v2 + 48), *((_QWORD *)v3 + 1) + *(unsigned int *)(*(_QWORD *)(v2 + 8) + 16LL));
  cam_io_w_mb(*(unsigned int *)(v2 + 60), *((_QWORD *)v3 + 1) + *(unsigned int *)(*(_QWORD *)(v2 + 8) + 20LL));
  cam_io_w_mb(*(unsigned int *)(v2 + 56), *((_QWORD *)v3 + 1) + *(unsigned int *)(*(_QWORD *)(v2 + 8) + 24LL));
  if ( (*(_BYTE *)(v2 + 89) & 1) == 0 )
  {
    if ( *((_BYTE *)v3 + 1860) )
      v5 = 5;
    else
      v5 = 1;
    cam_io_w_mb(v5, *((_QWORD *)v3 + 1) + **(unsigned int **)(v2 + 8));
  }
  cam_io_w_mb((unsigned int)v3[464], *((_QWORD *)v3 + 1) + *(unsigned int *)(*(_QWORD *)(v2 + 8) + 36LL));
  v6 = debug_mdl;
  *(_DWORD *)(a1 + 8) = 4;
  if ( (v6 & 0x40000000) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v6 & 0x40000000,
      4,
      "cam_sfe_bus_start_rm",
      593,
      "Start SFE:%d RM:%d offset:0x%X width:%d [in bytes: %u] height:%d unpack_fmt:%d stride:%d latency_buf_alloc:%u",
      **(_DWORD **)v2,
      *(_DWORD *)(v2 + 24),
      *(_DWORD *)(v2 + 84),
      *(_DWORD *)(v2 + 40),
      v4,
      *(_DWORD *)(v2 + 44),
      *(_DWORD *)(v2 + 60),
      *(_DWORD *)(v2 + 48),
      *(_DWORD *)(v2 + 56));
  _ReadStatusReg(SP_EL0);
  return 0;
}
