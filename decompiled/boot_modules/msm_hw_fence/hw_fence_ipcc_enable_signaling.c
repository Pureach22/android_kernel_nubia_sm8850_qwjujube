__int64 __fastcall hw_fence_ipcc_enable_signaling(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  int v8; // w0
  int v9; // w5
  int v10; // w8
  bool v11; // zf
  int v12; // w8
  int v13; // w10
  int inited; // w0
  __int64 v15; // x3
  __int64 v16; // x4
  int v17; // w23
  void *v18; // x0
  __int64 v19; // x2
  int v20; // w8
  bool v21; // zf
  int v22; // w8
  int v23; // w10
  int v24; // w8
  int v25; // w8
  int v26; // w8
  bool v27; // zf
  int v28; // w8
  int v29; // w10
  __int64 v30; // x8
  unsigned __int64 v31; // x11
  int v32; // w8
  int v33; // w8
  __int64 v34; // x5
  int v35; // w6
  unsigned int v36; // w0
  __int64 v37; // x20
  __int64 v38; // x3
  __int64 v39; // x4
  __int64 result; // x0
  unsigned int v41; // w19
  __int64 v42; // x3
  int v43; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-8h]

  v6 = v5;
  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43 = 0;
  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
    printk(&unk_270B9, "hw_fence_ipcc_enable_signaling", 801, a4, a5);
  v8 = of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)a1 + 744LL), "qcom,hw-fence-ipc-ver", &v43, 1, 0);
  v9 = v43;
  if ( v8 < 0 || !v43 )
  {
    printk(&unk_28519, "hw_fence_ipcc_enable_signaling", 805, v6, v8 & (unsigned int)(v8 >> 31));
    result = 4294967274LL;
LABEL_60:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  *(_DWORD *)(a1 + 620) = 0x40000;
  if ( v9 <= 133891 )
  {
    switch ( v9 )
    {
      case 67328:
        *(_QWORD *)(a1 + 632) = 0x800000008LL;
        *(_DWORD *)(a1 + 640) = 8;
        *(_QWORD *)(a1 + 624) = 0x800000002LL;
        inited = hw_fence_ipcc_init_map_with_configurable_clients(a1, &hw_fence_clients_ipc_map);
        if ( (~msm_hw_fence_debug_level & 0x10008) != 0 )
          goto LABEL_50;
        v17 = inited;
        v18 = &unk_2100B;
        v19 = 682;
        break;
      case 131075:
        *(_QWORD *)(a1 + 632) = 0x800000003LL;
        *(_DWORD *)(a1 + 640) = 3;
        *(_QWORD *)(a1 + 624) = 0x800000004LL;
        inited = hw_fence_ipcc_init_map_with_configurable_clients(a1, &hw_fence_clients_ipc_map_v2);
        if ( (~msm_hw_fence_debug_level & 0x10008) != 0 )
          goto LABEL_50;
        v17 = inited;
        v18 = &unk_265DE;
        v19 = 692;
        break;
      case 133634:
        v20 = *(unsigned __int8 *)(a1 + 33520);
        *(_DWORD *)(a1 + 632) = 3;
        v21 = v20 == 0;
        if ( v20 )
          v22 = 22;
        else
          v22 = 3;
        if ( v21 )
          v23 = 8;
        else
          v23 = 46;
        *(_DWORD *)(a1 + 636) = v23;
        *(_DWORD *)(a1 + 640) = v22;
        *(_QWORD *)(a1 + 624) = 0x800000004LL;
        inited = hw_fence_ipcc_init_map_with_configurable_clients(a1, &hw_fence_clients_ipc_map_sun);
        if ( (~msm_hw_fence_debug_level & 0x10008) != 0 )
          goto LABEL_50;
        v17 = inited;
        v18 = &unk_270F7;
        v19 = 704;
        break;
      default:
        goto LABEL_63;
    }
    goto LABEL_65;
  }
  if ( v9 <= 196608 )
  {
    if ( v9 != 133892 )
    {
      if ( v9 == 135169 )
      {
        v10 = *(unsigned __int8 *)(a1 + 33520);
        *(_DWORD *)(a1 + 632) = 2;
        v11 = v10 == 0;
        if ( v10 )
          v12 = 12;
        else
          v12 = 2;
        if ( v11 )
          v13 = 8;
        else
          v13 = 46;
        *(_DWORD *)(a1 + 636) = v13;
        *(_DWORD *)(a1 + 640) = v12;
        *(_QWORD *)(a1 + 624) = 0x800000004LL;
        inited = hw_fence_ipcc_init_map_with_configurable_clients(a1, &hw_fence_clients_ipc_map_seraph);
        if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
        {
          v17 = inited;
          v18 = &unk_248C7;
          v19 = 764;
          goto LABEL_65;
        }
LABEL_50:
        if ( inited )
        {
LABEL_66:
          v42 = v6;
          goto LABEL_67;
        }
LABEL_51:
        hw_fence_ipcc_enable_protocol(a1, 0);
        if ( a1 && (v34 = *(_QWORD *)(a1 + 608), v35 = *(_DWORD *)(a1 + 624), v34) && v35 )
        {
          v36 = *(_DWORD *)(a1 + 636) << 16;
          v37 = v34 + (unsigned int)(*(_DWORD *)(a1 + 632) << 12) + (unsigned int)(*(_DWORD *)(a1 + 620) * v35);
          if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
          {
            v41 = *(_DWORD *)(a1 + 636) << 16;
            printk(&unk_242F0, "_enable_client_signal_pair", 790, v36, v37 + 20);
            v36 = v41;
          }
          writel_relaxed(v36, (unsigned int *)(v37 + 20));
        }
        else
        {
          printk(&unk_24325, "_enable_client_signal_pair", 783, v6, a1);
        }
        if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
          printk(&unk_2ACED, "hw_fence_ipcc_enable_signaling", 821, v38, v39);
        result = 0;
        goto LABEL_60;
      }
LABEL_63:
      printk(&unk_2103A, "_hw_fence_ipcc_hwrev_init", 767, v6, (unsigned int)v9);
      v42 = v6;
LABEL_67:
      printk(&unk_28B42, "hw_fence_ipcc_enable_signaling", 810, v42, v16);
      result = 4294967274LL;
      goto LABEL_60;
    }
    v26 = *(unsigned __int8 *)(a1 + 33520);
    *(_DWORD *)(a1 + 632) = 2;
    v27 = v26 == 0;
    if ( v26 )
      v28 = 13;
    else
      v28 = 2;
    if ( v27 )
      v29 = 8;
    else
      v29 = 46;
    *(_DWORD *)(a1 + 636) = v29;
    *(_DWORD *)(a1 + 640) = v28;
    *(_QWORD *)(a1 + 624) = 0x800000004LL;
    inited = hw_fence_ipcc_init_map_with_configurable_clients(a1, &hw_fence_clients_ipc_map_niobe);
    if ( (~msm_hw_fence_debug_level & 0x10008) != 0 )
      goto LABEL_50;
    v17 = inited;
    v18 = &unk_225A9;
    v19 = 717;
LABEL_65:
    printk(v18, "_hw_fence_ipcc_hwrev_init", v19, v15, v16);
    if ( v17 )
      goto LABEL_66;
    goto LABEL_51;
  }
  if ( v9 != 196609 )
  {
    if ( v9 != 196866 )
      goto LABEL_63;
    v24 = *(unsigned __int8 *)(a1 + 33520);
    *(_QWORD *)(a1 + 628) = 0x300000003LL;
    if ( v24 )
      v25 = 24;
    else
      v25 = 3;
    *(_DWORD *)(a1 + 636) = v25;
    *(_DWORD *)(a1 + 640) = v25;
    *(_QWORD *)(a1 + 620) = 0x4000C0000LL;
    inited = hw_fence_ipcc_init_map_with_configurable_clients(a1, &hw_fence_clients_ipc_map_canoe);
    if ( (~msm_hw_fence_debug_level & 0x10008) != 0 )
      goto LABEL_50;
    v17 = inited;
    v18 = &unk_25F00;
    v19 = 751;
    goto LABEL_65;
  }
  v30 = *(unsigned int *)(a1 + 12);
  if ( (unsigned int)v30 >= 5 )
  {
    __break(0x5512u);
  }
  else
  {
    v31 = (16LL * *(unsigned int *)(a1 + 12)) | 4;
    *(_DWORD *)(a1 + 628) = hw_fence_clients_ipc_map_sa8797_apps[4 * v30];
    if ( v31 <= 0x50 )
    {
      v32 = hw_fence_clients_ipc_map_sa8797_apps[4 * v30 + 1];
      *(_QWORD *)(a1 + 636) = 0x2100000021LL;
      *(_DWORD *)(a1 + 632) = v32;
      *(_QWORD *)(a1 + 620) = 0x4000C0000LL;
      inited = hw_fence_ipcc_init_map_with_configurable_clients(a1, &hw_fence_clients_ipc_map_sa8797);
      **(_DWORD **)(a1 + 648) = *(_DWORD *)(a1 + 628);
      v33 = msm_hw_fence_debug_level;
      *(_DWORD *)(*(_QWORD *)(a1 + 648) + 4LL) = *(_DWORD *)(a1 + 632);
      if ( (~v33 & 0x10008) != 0 )
        goto LABEL_50;
      v17 = inited;
      v18 = &unk_22C7D;
      v19 = 736;
      goto LABEL_65;
    }
  }
  __break(1u);
  return ((__int64 (*)(void))hw_fence_ipcc_enable_protocol)();
}
