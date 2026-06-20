__int64 __fastcall hfi_dbg_device_setup(__int64 a1)
{
  _QWORD *cmd_buf; // x0
  __int64 v2; // x8
  __int64 v3; // x19
  int *v4; // x0
  int *v5; // x0
  int *v6; // x0
  int *v7; // x0
  _DWORD *payload_addr; // x20
  unsigned int size; // w0
  unsigned int v10; // w19
  __int64 result; // x0
  void *v12; // x0
  _QWORD src[2]; // [xsp+10h] [xbp-10h] BYREF

  src[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  src[0] = 0;
  if ( !a1 || !hfi_dbg )
  {
    v12 = &unk_22A7AB;
LABEL_21:
    printk(v12, "hfi_dbg_device_setup");
    result = 4294967274LL;
    goto LABEL_18;
  }
  cmd_buf = hfi_adapter_get_cmd_buf(a1 + 8);
  if ( !cmd_buf )
  {
    v12 = &unk_237EB0;
    goto LABEL_21;
  }
  v2 = hfi_dbg;
  v3 = (__int64)cmd_buf;
  if ( *(_DWORD *)(hfi_dbg + 56) && *(_QWORD *)(hfi_dbg + 40) )
  {
    v4 = *(int **)(hfi_dbg + 264);
    src[0] = *(_QWORD *)(hfi_dbg + 40);
    hfi_util_u32_prop_helper_add_prop(v4, 327685, 2, src, 8u);
    v2 = hfi_dbg;
  }
  if ( *(_DWORD *)(v2 + 112) && *(_QWORD *)(v2 + 96) )
  {
    v5 = *(int **)(v2 + 264);
    src[0] = *(_QWORD *)(v2 + 96);
    hfi_util_u32_prop_helper_add_prop(v5, 327687, 2, src, 8u);
    v2 = hfi_dbg;
  }
  if ( *(_DWORD *)(v2 + 168) && *(_QWORD *)(v2 + 152) )
  {
    v6 = *(int **)(v2 + 264);
    src[0] = *(_QWORD *)(v2 + 152);
    hfi_util_u32_prop_helper_add_prop(v6, 327686, 2, src, 8u);
    v2 = hfi_dbg;
  }
  if ( *(_DWORD *)(v2 + 224) && *(_QWORD *)(v2 + 208) )
  {
    v7 = *(int **)(v2 + 264);
    src[0] = *(_QWORD *)(v2 + 208);
    hfi_util_u32_prop_helper_add_prop(v7, 327688, 2, src, 8u);
    v2 = hfi_dbg;
  }
  payload_addr = hfi_util_u32_prop_helper_get_payload_addr(*(_DWORD **)(v2 + 264));
  size = hfi_util_u32_prop_helper_get_size(*(_QWORD *)(hfi_dbg + 264));
  hfi_adapter_add_set_property(v3, -16777206, 0, 2u, (__int64)payload_addr, size, 0);
  v10 = hfi_adapter_set_cmd_buf(v3);
  sde_evtlog_log(sde_dbg_base_evtlog, "hfi_dbg_device_setup", 401, -1, 0, -16777206, v10, 13107, 239);
  result = 0;
  if ( v10 )
  {
    printk(&unk_23B5A2, "hfi_dbg_device_setup");
    result = v10;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
