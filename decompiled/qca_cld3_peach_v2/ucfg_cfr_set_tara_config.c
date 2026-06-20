__int64 __fastcall ucfg_cfr_set_tara_config(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 v12; // x21
  __int64 v13; // x22
  __int64 v14; // x10
  __int64 v15; // x0
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // [xsp+8h] [xbp-18h] BYREF
  __int64 v26[2]; // [xsp+10h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v26[0] = 0;
  result = dev_sanity_check(a1, &v25, v26, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    v12 = v26[0];
    v13 = v26[0] + 35 * ((*(_QWORD *)(a2 + 52) >> 14) & 0xFLL);
    qdf_mem_copy((void *)(v13 + 189), (const void *)(a2 + 18), 6u);
    qdf_mem_copy((void *)(v13 + 195), (const void *)(a2 + 24), 6u);
    qdf_mem_copy((void *)(v13 + 201), (const void *)(a2 + 30), 6u);
    qdf_mem_copy((void *)(v13 + 207), (const void *)(a2 + 36), 6u);
    v14 = *(_QWORD *)(v12 + 744);
    v15 = v25;
    *(_DWORD *)(v13 + 179) |= 0xF0000u;
    v16 = (unsigned int *)((1LL << ((*(_QWORD *)(a2 + 52) >> 14) & 0xF)) | v14);
    *(_QWORD *)(v12 + 744) = v16;
    wlan_objmgr_pdev_release_ref(v15, 0x30u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
