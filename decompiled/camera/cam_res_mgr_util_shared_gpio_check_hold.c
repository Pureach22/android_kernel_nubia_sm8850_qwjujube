__int64 __fastcall cam_res_mgr_util_shared_gpio_check_hold(unsigned int a1)
{
  __int64 v1; // x21
  char v3; // w20
  __int64 idx_from_shared_pctrl_gpio; // x0
  int v5; // w6
  __int64 result; // x0
  const char *v7; // x5
  __int64 v8; // x1
  __int64 v9; // x4
  __int64 v10; // x23
  unsigned int v11; // w20
  unsigned int idx_from_shared_gpio; // w0
  unsigned int v13; // w8
  __int64 *v14; // x9
  int v15; // w8
  int v16; // w20
  __int64 *v17; // x12
  __int64 *v18; // x8
  __int64 *v19; // x12
  __int64 v20; // x1
  __int64 v21; // x4
  const char *v22; // x5
  __int64 v23; // x4
  __int64 v24; // x8
  unsigned __int64 v25; // x9
  __int64 v26; // x11
  __int64 *v27; // x13
  __int64 *v28; // x15
  __int64 v29; // x8
  unsigned __int64 v30; // x9
  __int64 v31; // x11
  __int64 *v32; // x14
  __int64 *v33; // x16

  v1 = cam_res;
  if ( !cam_res )
  {
    result = 0;
    if ( (debug_mdl & 0x200000) == 0 || debug_priority )
      return result;
    v7 = "res mgr is not initilized";
    v8 = debug_mdl & 0x200000;
    v9 = 241;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v8,
      4,
      "cam_res_mgr_util_shared_gpio_check_hold",
      v9,
      v7);
    return 0;
  }
  if ( (*(_BYTE *)(cam_res + 200) & 1) == 0 )
  {
    result = 0;
    if ( (debug_mdl & 0x200000) == 0 || debug_priority )
      return result;
    v7 = "Res_mgr is not sharing any gpios";
    v8 = debug_mdl & 0x200000;
    v9 = 246;
    goto LABEL_12;
  }
  v3 = ((__int64 (*)(void))cam_res_mgr_gpio_is_in_shared_gpio)();
  idx_from_shared_pctrl_gpio = cam_res_mgr_gpio_is_in_shared_pctrl_gpio(a1);
  if ( (v3 & 1) != 0 && (idx_from_shared_pctrl_gpio & 1) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000,
      1,
      "cam_res_mgr_util_shared_gpio_check_hold",
      259,
      "gpio %u cannot be shared between pinctrl and gpio",
      v5);
    return 4294967274LL;
  }
  v10 = v1 + 8;
  if ( (v3 & 1) == 0 )
  {
    v16 = 0;
LABEL_25:
    if ( (idx_from_shared_pctrl_gpio & 1) == 0 )
      goto LABEL_42;
    goto LABEL_26;
  }
  v11 = idx_from_shared_pctrl_gpio;
  idx_from_shared_gpio = cam_res_mgr_util_get_idx_from_shared_gpio((_QWORD *)a1);
  if ( (idx_from_shared_gpio & 0x80000000) != 0 )
  {
    v22 = "Gpio%u not found in shared gpio list";
    v23 = 267;
    goto LABEL_40;
  }
  v13 = idx_from_shared_gpio;
  idx_from_shared_pctrl_gpio = v11;
  v14 = *(__int64 **)(cam_res + 456);
  if ( v14 == (__int64 *)(cam_res + 456) )
  {
    v16 = 0;
    if ( (idx_from_shared_pctrl_gpio & 1) == 0 )
      goto LABEL_42;
LABEL_26:
    idx_from_shared_pctrl_gpio = cam_res_mgr_util_get_idx_from_shared_pctrl_gpio((_QWORD *)a1);
    if ( (idx_from_shared_pctrl_gpio & 0x80000000) == 0 )
    {
      v18 = *(__int64 **)(cam_res + 456);
      if ( v18 != (__int64 *)(cam_res + 456) )
      {
        if ( (unsigned int)idx_from_shared_pctrl_gpio > 9 )
          goto LABEL_75;
        while ( 1 )
        {
          if ( *((_DWORD *)v18 + 8) == *(_DWORD *)(v1 + 4LL * (unsigned int)idx_from_shared_pctrl_gpio + 72) )
          {
            --v16;
            v19 = v18 + 2;
            do
            {
              v19 = (__int64 *)*v19;
              ++v16;
            }
            while ( v19 != v18 + 2 );
            if ( v16 >= 2 )
              break;
          }
          v18 = (__int64 *)*v18;
          if ( v18 == (__int64 *)(cam_res + 456) )
            goto LABEL_42;
        }
        result = 1;
        if ( (debug_mdl & 0x200000) == 0 || debug_priority )
          return result;
        v20 = debug_mdl & 0x200000;
        v21 = 304;
        goto LABEL_70;
      }
LABEL_42:
      v24 = *(unsigned int *)(v1 + 112);
      if ( (int)v24 < 1 )
      {
LABEL_56:
        v29 = *(unsigned int *)(v1 + 116);
        if ( (int)v29 < 1 )
        {
LABEL_71:
          result = 2;
          if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x200000,
              4,
              "cam_res_mgr_util_shared_gpio_check_hold",
              347,
              "gpio: %u can free the resource",
              a1);
            return 2;
          }
          return result;
        }
        v30 = 0;
        v31 = cam_res + 456;
        while ( *(_QWORD *)(cam_res + 456) == v31 )
        {
LABEL_58:
          if ( ++v30 == v29 )
            goto LABEL_71;
        }
        if ( v30 > 9 )
        {
LABEL_75:
          __break(0x5512u);
          return cam_res_mgr_gpio_is_in_shared_gpio(idx_from_shared_pctrl_gpio);
        }
        v32 = *(__int64 **)(cam_res + 456);
        while ( 1 )
        {
          if ( *((_DWORD *)v32 + 8) == *(_DWORD *)(v1 + 72 + 4 * v30) )
          {
            --v16;
            v33 = v32 + 2;
            do
            {
              v33 = (__int64 *)*v33;
              ++v16;
            }
            while ( v33 != v32 + 2 );
            if ( v16 >= 2 )
              break;
          }
          v32 = (__int64 *)*v32;
          if ( v32 == (__int64 *)v31 )
            goto LABEL_58;
        }
        result = 1;
        if ( (debug_mdl & 0x200000) == 0 || debug_priority )
          return result;
        v20 = debug_mdl & 0x200000;
        v21 = 340;
      }
      else
      {
        v25 = 0;
        v26 = cam_res + 456;
        while ( *(_QWORD *)(cam_res + 456) == v26 )
        {
LABEL_44:
          if ( ++v25 == v24 )
            goto LABEL_56;
        }
        if ( v25 > 0xF )
          goto LABEL_75;
        v27 = *(__int64 **)(cam_res + 456);
        while ( 1 )
        {
          if ( *((_DWORD *)v27 + 8) == *(_DWORD *)(v10 + 4 * v25) )
          {
            --v16;
            v28 = v27 + 2;
            do
            {
              v28 = (__int64 *)*v28;
              ++v16;
            }
            while ( v28 != v27 + 2 );
            if ( v16 >= 2 )
              break;
          }
          v27 = (__int64 *)*v27;
          if ( v27 == (__int64 *)v26 )
            goto LABEL_44;
        }
        result = 1;
        if ( (debug_mdl & 0x200000) == 0 || debug_priority )
          return result;
        v20 = debug_mdl & 0x200000;
        v21 = 322;
      }
LABEL_70:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        v20,
        4,
        "cam_res_mgr_util_shared_gpio_check_hold",
        v21,
        "gpio: %u needs to hold",
        a1);
      return 1;
    }
    v22 = "gpio%u not found in shared pctrl gpio list";
    v23 = 291;
LABEL_40:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x200000,
      1,
      "cam_res_mgr_util_shared_gpio_check_hold",
      v23,
      v22,
      a1);
    return 4294967274LL;
  }
  if ( v13 > 0xF )
    goto LABEL_75;
  v15 = *(_DWORD *)(v10 + 4LL * v13);
  v16 = 0;
  while ( 1 )
  {
    if ( *((_DWORD *)v14 + 8) == v15 )
    {
      --v16;
      v17 = v14 + 2;
      do
      {
        v17 = (__int64 *)*v17;
        ++v16;
      }
      while ( v17 != v14 + 2 );
      if ( v16 > 1 )
        return 1;
    }
    v14 = (__int64 *)*v14;
    if ( v14 == (__int64 *)(cam_res + 456) )
      goto LABEL_25;
  }
}
