__int64 *__fastcall epping_add_adapter(__int64 a1, const void *a2, int a3, char a4)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 *v17; // x19
  __int64 v18; // x20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int16 v27; // w9
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned __int64 StatusReg; // x21
  int v46; // w22
  unsigned __int64 v47; // x23
  __int64 v48; // x24
  unsigned __int64 v55; // x8
  __int64 v56; // x0

  v8 = alloc_netdev_mqs(320, "wifi%d", 0);
  if ( !v8 )
  {
    qdf_trace_msg(
      0x33u,
      1u,
      "%s: Cannot allocate epping_adapter_t\n",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "epping_add_adapter");
    return nullptr;
  }
  v17 = (__int64 *)(v8 + 2688);
  v18 = v8;
  qdf_mem_set((void *)(v8 + 2688), 0x140u, 0);
  *(_QWORD *)(v18 + 2704) = v18;
  *(_QWORD *)(v18 + 2688) = a1;
  *(_DWORD *)(v18 + 2696) = a3;
  dev_addr_mod(v18, 0, a2, 6);
  qdf_mem_copy((void *)(v18 + 2712), a2, 6u);
  *(_DWORD *)(v18 + 2720) = 0;
  *(_QWORD *)(v18 + 2728) = 0;
  *(_QWORD *)(v18 + 2736) = 0;
  *(_QWORD *)(v18 + 2744) = 0;
  *(_QWORD *)(v18 + 2752) = 0;
  *(_DWORD *)(v18 + 2816) = 0;
  epping_get_qdf_ctx(v19, v20, v21, v22, v23, v24, v25, v26);
  *(_QWORD *)(v18 + 2800) = epping_timer_expire;
  *(_QWORD *)(v18 + 2808) = v18;
  init_timer_key(v18 + 2760, _os_timer_shim_11, 0x80000, 0, 0);
  v27 = *(_WORD *)(v18 + 60);
  v28 = *(_QWORD *)(v18 + 2704);
  *(_WORD *)(v18 + 544) = 801;
  *(_DWORD *)(v18 + 1296) = 1250;
  *(_QWORD *)(v18 + 8) = &epping_drv_ops;
  *(_WORD *)(v18 + 60) = v27 + 24;
  *(_DWORD *)(v18 + 1112) = 511;
  if ( (a4 & 1) != 0 )
  {
    if ( (unsigned int)register_netdevice(v28) )
    {
LABEL_4:
      qdf_trace_msg(
        0x33u,
        1u,
        "%s: unable to register device\n",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        *(_QWORD *)(v18 + 2704) + 296LL);
      epping_destroy_adapter(v17, v37, v38, v39, v40, v41, v42, v43, v44);
      return nullptr;
    }
  }
  else if ( (unsigned int)register_netdev(v28) )
  {
    goto LABEL_4;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  *(_BYTE *)(v18 + 2820) = 1;
  qdf_trace_msg(0x33u, 4u, "%s: Disabling queues", v29, v30, v31, v32, v33, v34, v35, v36, "epping_add_adapter");
  *(_DWORD *)(StatusReg + 16) += 512;
  v46 = *(_DWORD *)(StatusReg + 40);
  raw_spin_lock(v18 + 1116);
  if ( *(_DWORD *)(v18 + 1096) )
  {
    v47 = 0;
    v48 = 336;
    do
    {
      _X28 = (unsigned __int64 *)(*(_QWORD *)(v18 + 24) + v48);
      raw_spin_lock(_X28 - 2);
      *((_DWORD *)_X28 - 3) = v46;
      *(_X28 - 1) = jiffies;
      __dmb(0xBu);
      __asm { PRFM            #0x11, [X28] }
      do
        v55 = __ldxr(_X28);
      while ( __stxr(v55 | 1, _X28) );
      *((_DWORD *)_X28 - 3) = -1;
      raw_spin_unlock(_X28 - 2);
      ++v47;
      v48 += 384;
    }
    while ( v47 < *(unsigned int *)(v18 + 1096) );
  }
  v56 = raw_spin_unlock(v18 + 1116);
  local_bh_enable_1(v56);
  netif_carrier_off(v18);
  return v17;
}
