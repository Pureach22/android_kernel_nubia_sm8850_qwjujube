__int64 __fastcall cam_cpas_dev_component_bind(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 v5; // x1
  int v6; // w0
  unsigned int v7; // w23
  _DWORD *v8; // x22
  __int64 v9; // x8
  _DWORD *v10; // x9
  __int64 v11; // x0
  int v12; // w0
  _QWORD v13[2]; // [xsp+38h] [xbp-28h] BYREF
  _QWORD v14[3]; // [xsp+48h] [xbp-18h] BYREF

  v14[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  v14[1] = 0;
  v13[0] = 0;
  v13[1] = 0;
  ktime_get_real_ts64(v14);
  if ( g_cpas_intf )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_dev_component_bind",
      2076,
      "cpas component already binded");
    result = 4294967182LL;
    goto LABEL_26;
  }
  if ( mem_trace_en == 1 )
  {
    v3 = cam_mem_trace_alloc(856, 0xCC0u, 0, "cam_cpas_dev_component_bind", 0x820u);
    g_cpas_intf = v3;
    if ( !v3 )
      goto LABEL_25;
  }
  else
  {
    v3 = _kvmalloc_node_noprof(856, 0, 3520, 0xFFFFFFFFLL);
    g_cpas_intf = v3;
    if ( !v3 )
    {
LABEL_25:
      result = 4294967284LL;
      goto LABEL_26;
    }
  }
  v4 = a1 - 16;
  _mutex_init(v3 + 800, "&g_cpas_intf->intf_lock", &cam_cpas_dev_component_bind___key);
  v5 = g_cpas_intf + 480;
  *(_QWORD *)g_cpas_intf = v4;
  v6 = cam_cpas_hw_probe(v4, v5);
  if ( v6 || (v8 = (_DWORD *)g_cpas_intf, (v9 = *(_QWORD *)(g_cpas_intf + 480)) == 0) )
  {
    v7 = v6;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_dev_component_bind",
      2089,
      "Failed in hw probe, rc=%d",
      v6);
LABEL_18:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)g_cpas_intf, 0);
    else
      kvfree(g_cpas_intf);
    g_cpas_intf = 0;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_dev_component_bind",
      2140,
      "CPAS component bind failed");
    result = v7;
    goto LABEL_26;
  }
  *(_DWORD *)(*(_QWORD *)(v9 + 112) + 3400LL) = *(_DWORD *)(*(_QWORD *)(v9 + 112) + 116LL) + 12800;
  v10 = *(_DWORD **)(v9 + 8);
  if ( !v10 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_dev_component_bind",
      2113,
      "Invalid get_hw_caps ops");
    v7 = 0;
    goto LABEL_17;
  }
  v11 = *(_QWORD *)(v9 + 112);
  if ( *(v10 - 1) != 1989616049 )
    __break(0x8229u);
  v12 = ((__int64 (__fastcall *)(__int64, _DWORD *, __int64))v10)(v11, v8 + 122, 308);
  if ( v12 )
  {
    v7 = v12;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_dev_component_bind",
      2109,
      "Failed in get_hw_caps, rc=%d",
      v12);
LABEL_17:
    cam_cpas_hw_remove(*(_QWORD *)(g_cpas_intf + 480));
    goto LABEL_18;
  }
  v7 = cam_cpas_subdev_register(v4);
  if ( v7 )
    goto LABEL_17;
  *(_BYTE *)(g_cpas_intf + 852) = 1;
  ktime_get_real_ts64(v13);
  cam_record_bind_latency();
  result = 0;
  if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_dev_component_bind",
      2130,
      "Component bound successfully %d, %d.%d.%d, %d.%d.%d, 0x%x",
      v8[122],
      v8[123],
      v8[124],
      v8[125],
      v8[127],
      v8[128],
      v8[129],
      (_DWORD)v8 + 524);
    result = 0;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
