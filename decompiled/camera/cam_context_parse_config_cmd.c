size_t __fastcall cam_context_parse_config_cmd(__int64 a1, __int64 a2, unsigned int **a3)
{
  __int64 v6; // x8
  size_t result; // x0
  size_t v8; // x7
  unsigned __int64 v9; // x0
  size_t v10; // x22
  int v11; // w0
  int v12; // w21
  size_t v13; // [xsp+28h] [xbp-18h] BYREF
  size_t v14[2]; // [xsp+30h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v14[0] = 0;
  if ( a1 && a2 && a3 )
  {
    if ( (unsigned int)cam_mem_get_cpu_buf(*(_DWORD *)(a2 + 16), &v13, v14) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x80000,
        1,
        "cam_context_parse_config_cmd",
        1846,
        "[%s][%d] Can not get packet address for handle:%llx",
        (const char *)a1,
        *(_DWORD *)(a1 + 32),
        *(_QWORD *)(a2 + 16));
LABEL_7:
      v6 = -22;
LABEL_18:
      result = 0;
      *a3 = (unsigned int *)v6;
      goto LABEL_19;
    }
    v8 = *(_QWORD *)(a2 + 8);
    if ( v14[0] < 0x40 || v8 >= v14[0] - 64 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x80000,
        1,
        "cam_context_parse_config_cmd",
        1854,
        "invalid buff length: %zu or offset: %zu",
        v14[0],
        v8);
      v12 = -22;
      goto LABEL_17;
    }
    v9 = v13 + (unsigned int)v8;
    if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL )
    {
      v12 = v13 + v8;
      goto LABEL_17;
    }
    v10 = v14[0] - v8;
    v11 = cam_packet_util_copy_pkt_to_kmd(v9, a3, v14[0] - v8);
    if ( v11 )
    {
      v12 = v11;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x80000,
        1,
        "cam_context_parse_config_cmd",
        1868,
        "Copying packet to KMD failed");
LABEL_17:
      cam_mem_put_cpu_buf(*(_DWORD *)(a2 + 16));
      v6 = v12;
      goto LABEL_18;
    }
    if ( (debug_mdl & 0x80000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x80000,
        4,
        "cam_context_parse_config_cmd",
        1875,
        "handle:%llx, addr:0x%zx, offset:%0xllx, len:%zu, req:%llu, size:%u, opcode:0x%x",
        *(_QWORD *)(a2 + 16),
        v13,
        *(_QWORD *)(a2 + 8),
        v14[0],
        *((_QWORD *)*a3 + 1),
        (*a3)[1],
        **a3);
    cam_mem_put_cpu_buf(*(_DWORD *)(a2 + 16));
    result = v10;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_parse_config_cmd",
      1836,
      "invalid args");
    if ( a3 )
      goto LABEL_7;
    result = 0;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
