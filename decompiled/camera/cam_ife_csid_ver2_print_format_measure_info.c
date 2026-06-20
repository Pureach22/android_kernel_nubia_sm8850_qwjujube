__int64 __fastcall cam_ife_csid_ver2_print_format_measure_info(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x24
  __int64 v6; // x23
  __int64 v7; // x26
  __int64 v8; // x25
  unsigned int v9; // w20
  unsigned int v10; // w22
  int v11; // w0
  _DWORD *v12; // x8
  int v13; // w6
  __int64 result; // x0
  int v15; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+28h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int *)(a2 + 4);
  if ( (unsigned int)v2 >= 0xC )
    __break(0x5512u);
  v3 = *(_QWORD *)(a2 + 24);
  v6 = **(_QWORD **)(a1 + 31136);
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 31128) + 384LL);
  v8 = *(_QWORD *)(v6 + 8 * v2 + 136);
  v9 = cam_io_r_mb(v7 + *(unsigned int *)(*(_QWORD *)(v3 + 264) + 184LL) + *(unsigned int *)(v8 + 316));
  v10 = cam_io_r_mb(v7 + *(unsigned int *)(*(_QWORD *)(v3 + 264) + 176LL) + *(unsigned int *)(v8 + 316));
  v11 = cam_io_r_mb(v7 + *(unsigned int *)(*(_QWORD *)(v3 + 264) + 172LL) + *(unsigned int *)(v8 + 316));
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_ife_csid_ver2_print_format_measure_info",
    3214,
    "CSID[%u] res [id: %d name: %s] format_measure_cfg0: 0x%x",
    *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
    *(_DWORD *)(a2 + 4),
    (const char *)(a2 + 128),
    v11);
  v12 = *(_DWORD **)(v6 + 120);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_ver2_print_format_measure_info",
    3225,
    "CSID[%u] Frame Size Error Expected[h: %u w: %u] Actual[h: %u w: %u]",
    *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
    (v10 >> v12[188]) & v12[187],
    v12[189] & v10,
    (v9 >> v12[188]) & v12[187],
    v12[189] & v9);
  ((void (__fastcall *)(__int64))cam_ife_csid_ver2_print_hbi_vbi)(a1);
  v13 = *(_DWORD *)(a1 + 2068) - *(_DWORD *)(*(_QWORD *)(v6 + 120) + 588LL);
  v15 = v13;
  if ( v13 < 0 )
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               2,
               "cam_ife_csid_ver2_print_format_measure_info",
               3233,
               "Can't notify csiphy, incorrect phy selected=%d",
               v13);
  else
    result = cam_subdev_notify_message(65544, 2u, (__int64)&v15);
  _ReadStatusReg(SP_EL0);
  return result;
}
