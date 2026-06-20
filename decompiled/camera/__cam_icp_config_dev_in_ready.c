__int64 __fastcall _cam_icp_config_dev_in_ready(__int64 a1, __int64 a2)
{
  int v4; // w0
  __int64 result; // x0
  size_t v6; // x9
  unsigned int v7; // w0
  unsigned int v8; // w21
  unsigned int v9; // w8
  unsigned int *v10; // [xsp+20h] [xbp-20h] BYREF
  __int64 v11; // [xsp+28h] [xbp-18h] BYREF
  size_t v12[2]; // [xsp+30h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 16);
  v11 = 0;
  v12[0] = 0;
  v10 = nullptr;
  if ( !(unsigned int)cam_mem_get_cpu_buf(v4, &v11, v12) )
  {
    v6 = *(_QWORD *)(a2 + 8);
    if ( v12[0] < 0x40 || v6 >= v12[0] - 64 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x80000,
        1,
        "__cam_icp_config_dev_in_ready",
        202,
        "[%s] ctx[%u]: Invalid offset, len: %zu cmd offset: %llu sizeof packet: %zu",
        (const char *)a1,
        *(_DWORD *)(a1 + 32),
        v12[0],
        *(_QWORD *)(a2 + 8),
        0x40u);
      v8 = 0;
      goto LABEL_13;
    }
    v7 = cam_packet_util_copy_pkt_to_kmd(v11 + (unsigned int)v6, &v10, v12[0] - v6);
    if ( v7 )
    {
      v8 = v7;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "__cam_icp_config_dev_in_ready",
        211,
        "copying packet to kmd failed");
LABEL_13:
      cam_mem_put_cpu_buf(*(_DWORD *)(a2 + 16));
      result = v8;
      goto LABEL_14;
    }
    v9 = *(unsigned __int8 *)v10;
    if ( v9 <= 5 && ((1 << v9) & 0x2C) != 0 )
    {
      v8 = cam_context_config_dev_to_hw(a1, a2);
      if ( !v8 )
      {
LABEL_12:
        cam_common_mem_free((__int64)v10);
        goto LABEL_13;
      }
    }
    else
    {
      v8 = cam_context_prepare_dev_to_hw(a1, (const void *)a2);
      if ( !v8 )
        goto LABEL_12;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "__cam_icp_config_dev_in_ready",
      227,
      "[%s] ctx[%u]:Failed to prepare device",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
    goto LABEL_12;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "__cam_icp_config_dev_in_ready",
    191,
    "[%s][%d] Can not get packet address",
    (const char *)a1,
    *(_DWORD *)(a1 + 32));
  result = 4294967274LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
