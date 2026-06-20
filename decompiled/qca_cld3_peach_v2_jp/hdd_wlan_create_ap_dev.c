void *__fastcall hdd_wlan_create_ap_dev(
        __int64 *a1,
        const void *a2,
        unsigned int a3,
        const char *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x0
  __int64 v17; // x21
  void *v18; // x20
  unsigned int concurrency_mode; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  size_t v28; // x0
  unsigned __int64 v29; // x2
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x9
  unsigned __int64 v41; // x9

  qdf_trace_msg(0x33u, 8u, "%s: iface_name = %s", a5, a6, a7, a8, a9, a10, a11, a12, "hdd_wlan_create_ap_dev", a4);
  v16 = alloc_netdev_mqs(57456, a4, a3, &ether_setup, 17, 5);
  if ( !v16 )
    return nullptr;
  v17 = v16;
  v18 = (void *)(v16 + 2688);
  ether_setup();
  qdf_mem_set(v18, 0xE070u, 0);
  *(_QWORD *)(v17 + 2720) = v17;
  *(_QWORD *)(v17 + 55512) = v17 + 55520;
  *(_QWORD *)(v17 + 2712) = a1;
  *(_DWORD *)(v17 + 2688) = 1885692259;
  while ( 1 )
  {
    _X8 = (unsigned __int64 *)(v17 + 4328);
    __asm { PRFM            #0x11, [X8] }
    do
      v41 = __ldxr(_X8);
    while ( __stxr(v41 | 1, _X8) );
    concurrency_mode = policy_mgr_get_concurrency_mode(*a1);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: dev = %pK, adapter = %pK, concurrency_mode=0x%x",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "hdd_wlan_create_ap_dev",
      v17,
      v18,
      concurrency_mode);
    v28 = strnlen(a4, 0x10u);
    if ( v28 == -1 )
    {
      _fortify_panic(2, -1, 0);
      goto LABEL_12;
    }
    v29 = v28 == 16 ? 16LL : v28 + 1;
    if ( v29 < 0x11 )
      break;
LABEL_12:
    _fortify_panic(7, 16, v29);
  }
  sized_strscpy(v17 + 296, a4, v29);
  *(_QWORD *)(v17 + 8) = &net_ops_struct;
  *(_DWORD *)(v17 + 1296) = 1250;
  *(_DWORD *)(v17 + 56) = 1500;
  *(_DWORD *)(v17 + 1112) = 3000;
  dev_addr_mod(v17, 0, a2, 6);
  qdf_mem_copy((void *)(v17 + 4305), a2, 6u);
  hdd_update_dynamic_tsf_sync(v18);
  *(_BYTE *)(v17 + 1348) = 1;
  *(_QWORD *)(v17 + 992) = v17 + 2800;
  v30 = a1[3];
  *(_QWORD *)(v17 + 2832) = v17;
  *(_QWORD *)(v17 + 2800) = v30;
  v31 = a1[12];
  *(_DWORD *)(v17 + 44788) = 0;
  *(_QWORD *)(v17 + 1472) = v31;
  v32 = jiffies;
  v33 = *(_QWORD *)(v17 + 55512);
  *(_QWORD *)(v17 + 44800) = jiffies;
  *(_QWORD *)(v17 + 44792) = v32;
  *(_DWORD *)(v33 + 2348) = 0;
  return v18;
}
