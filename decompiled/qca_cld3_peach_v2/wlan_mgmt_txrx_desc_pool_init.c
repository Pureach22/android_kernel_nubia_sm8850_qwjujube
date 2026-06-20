__int64 __fastcall wlan_mgmt_txrx_desc_pool_init(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x5
  __int64 v10; // x8
  unsigned int v11; // w20
  unsigned int v12; // w21
  __int64 v14; // x0
  __int64 v15; // x23
  __int64 v16; // x24
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v26; // x2

  v9 = *a1;
  if ( !*a1 )
  {
    v26 = "%s: pdev context passed is NULL";
LABEL_9:
    qdf_trace_msg(0x4Bu, 2u, v26, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mgmt_txrx_desc_pool_init");
    return 4;
  }
  v10 = *(_QWORD *)(v9 + 80);
  if ( !v10 )
  {
    v26 = "%s: psoc context in pdev is NULL";
    goto LABEL_9;
  }
  v11 = *(unsigned __int8 *)(v9 + 40);
  v12 = *(unsigned __int8 *)(v10 + 48);
  qdf_trace_msg(
    0x4Bu,
    8u,
    "%s: mgmt_txrx ctx: %pK pdev: %pK pdev_id: %d psoc_id: %d mgmt desc pool size %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_mgmt_txrx_desc_pool_init",
    a1,
    v9,
    *(unsigned __int8 *)(v9 + 40),
    *(unsigned __int8 *)(v10 + 48),
    64);
  v14 = _qdf_mem_malloc(0x1200u, "wlan_mgmt_txrx_desc_pool_init", 64);
  a1[4] = v14;
  if ( !v14 )
    return 2;
  v15 = 0;
  v16 = 0;
  a1[1] = (__int64)(a1 + 1);
  a1[2] = (__int64)(a1 + 1);
  a1[3] = 0x4000000000LL;
  do
  {
    *(_DWORD *)(a1[4] + v15 + 40) = v16;
    *(_BYTE *)(a1[4] + v15 + 65) = 0;
    qdf_list_insert_front(a1 + 1, (_QWORD *)(a1[4] + v15));
    ++v16;
    v15 += 72;
  }
  while ( v16 != 64 );
  *((_DWORD *)a1 + 10) = 0;
  a1[6] = 0;
  qdf_trace_msg(
    0x4Bu,
    8u,
    "%s: exit pdev_id:%d psoc_id:%d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "wlan_mgmt_txrx_desc_pool_init",
    v11,
    v12);
  return 0;
}
