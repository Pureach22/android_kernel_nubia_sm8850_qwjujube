__int64 __fastcall cam_context_config_dev_to_hw(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v5; // w0
  unsigned int v6; // w20
  __int64 v7; // x10
  __int64 *v8; // x8
  unsigned int (__fastcall *v9)(__int64, unsigned int **); // x9
  __int64 v10; // x0
  unsigned int *v11; // [xsp+8h] [xbp-38h] BYREF
  __int64 v12; // [xsp+10h] [xbp-30h] BYREF
  unsigned int *v13; // [xsp+18h] [xbp-28h] BYREF
  __int64 v14; // [xsp+20h] [xbp-20h]
  __int64 v15; // [xsp+28h] [xbp-18h]
  _QWORD v16[2]; // [xsp+30h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = nullptr;
  v11 = nullptr;
  if ( a1 && a2 )
  {
    if ( *(_QWORD *)(*(_QWORD *)(a1 + 208) + 64LL) )
    {
      if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) != 0 )
      {
        _warn_printk("Invalid execution context\n");
        __break(0x800u);
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x80000,
          1,
          "cam_context_config_dev_to_hw",
          475,
          "Not executing in the right context");
        result = 4294967274LL;
      }
      else if ( (unsigned int)cam_mem_get_cpu_buf(*(_DWORD *)(a2 + 16), &v12, v16) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x80000,
          1,
          "cam_context_config_dev_to_hw",
          483,
          "[%s][%d] Can not get packet address",
          (const char *)a1,
          *(_DWORD *)(a1 + 32));
        result = 4294967274LL;
      }
      else
      {
        v5 = cam_packet_util_copy_pkt_to_kmd(v12 + *(unsigned int *)(a2 + 8), &v11, v16[0] - *(unsigned int *)(a2 + 8));
        if ( v5 )
        {
          v6 = v5;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x80000,
            1,
            "cam_context_config_dev_to_hw",
            494,
            "Copying packet to KMD failed");
        }
        else
        {
          v7 = *(_QWORD *)(a1 + 264);
          v15 = 0;
          v13 = v11;
          v14 = v7;
          if ( (debug_mdl & 0x80000) != 0 && !debug_priority )
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              debug_mdl & 0x80000,
              4,
              "cam_context_config_dev_to_hw",
              502,
              "Processing config settings");
          v8 = *(__int64 **)(a1 + 208);
          v9 = (unsigned int (__fastcall *)(__int64, unsigned int **))v8[8];
          v10 = *v8;
          if ( *((_DWORD *)v9 - 1) != 1863972096 )
            __break(0x8229u);
          if ( v9(v10, &v13) )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x80000,
              1,
              "cam_context_config_dev_to_hw",
              508,
              "[%s][%d] Config failed stream settings",
              (const char *)a1,
              *(_DWORD *)(a1 + 32));
            v6 = -14;
          }
          else
          {
            v6 = 0;
          }
          cam_common_mem_free((__int64)v11);
          v11 = nullptr;
        }
        cam_mem_put_cpu_buf(*(_DWORD *)(a2 + 16));
        result = v6;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x80000,
        1,
        "cam_context_config_dev_to_hw",
        467,
        "[%s][%d] HW interface is not ready",
        (const char *)a1,
        *(_DWORD *)(a1 + 32));
      result = 4294967282LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_config_dev_to_hw",
      461,
      "Invalid input params %pK %pK",
      (const void *)a1,
      (const void *)a2);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
