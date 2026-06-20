__int64 __fastcall cam_cci_core_cfg(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  unsigned int v3; // w19
  __int64 result; // x0
  __int16 v5; // w8
  int v6; // w8
  __int64 v7; // x10
  unsigned int v8; // w7
  __int64 v9; // x19
  __int64 v10; // x20
  __int64 v11; // x19
  __int64 v12; // x19
  __int64 v13; // x21
  __int64 v14; // x19
  __int64 v15; // x20
  unsigned int v16; // w19
  __int64 v17; // x19
  __int64 v18; // x19
  unsigned int v19; // w20
  __int64 v20; // x0
  __int64 v21; // x22
  unsigned int v22; // w19
  __int64 v23; // x20
  __int64 v24; // x0
  __int64 v25; // x19
  __int64 v26; // x20
  __int64 v27; // x2
  __int64 v28; // x19
  __int64 v29; // x21
  __int64 v30; // x0
  __int64 v31; // x1
  unsigned int v32; // w21
  __int64 v33; // x22
  __int64 v34; // x20
  __int64 v35; // x21
  __int64 v36; // x19
  __int64 v37; // [xsp+28h] [xbp+18h]

  v2 = *(_QWORD *)(a1 + 240);
  if ( !v2 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_core_cfg",
      2482);
    return 4294967274LL;
  }
  if ( !a2 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_core_cfg",
      2487);
    return 4294967274LL;
  }
  v3 = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 16LL);
  if ( v3 >= 2 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_core_cfg",
      2493);
    return 4294967274LL;
  }
  if ( (*(_DWORD *)(v2 + 544LL * v3 + 4040) & 0x80000000) != 0 && *(_DWORD *)(a2 + 16) != 1 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 2,
      "cam_cci_core_cfg",
      2498);
    return 4294967285LL;
  }
  v5 = debug_mdl;
  *(_BYTE *)(v2 + 5896) = 0;
  if ( (v5 & 0x4000) != 0 && !debug_priority )
  {
    v37 = a2;
    v33 = a1;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v5 & 0x4000,
      4,
      "cam_cci_core_cfg",
      2502,
      "CCI%d_I2C_M%d cmd = %d",
      *(_DWORD *)(v2 + 404),
      v3,
      *(_DWORD *)(a2 + 16));
    a2 = v37;
    a1 = v33;
  }
  v6 = *(_DWORD *)(a2 + 16);
  if ( v6 > 4 )
  {
    if ( (unsigned int)v6 <= 0xC )
    {
      if ( ((1 << v6) & 0x1BC0) != 0 )
      {
        v7 = *(_QWORD *)(a1 + 240);
        if ( !v7 )
        {
          v9 = a2;
          ((void (*)(__int64, const char *, ...))cam_print_log)(
            3,
            print_fmt_cam_context_state,
            (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
            "cam_cci_write",
            2414);
          goto LABEL_24;
        }
        v8 = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 16LL);
        if ( v8 >= 2 )
        {
          v9 = a2;
          ((void (*)(__int64, const char *, ...))cam_print_log)(
            3,
            print_fmt_cam_context_state,
            (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
            "cam_cci_write",
            2423);
LABEL_24:
          a2 = v9;
          result = 4294967274LL;
          goto LABEL_59;
        }
        v12 = v7 + 544LL * v8;
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
        {
          v34 = a2;
          v35 = a1;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_write",
            2429,
            "CCI%d_I2C_M%d ctrl_cmd = %d",
            *(unsigned int *)(v7 + 404));
          v6 = *(_DWORD *)(v34 + 16);
          a1 = v35;
          a2 = v34;
        }
        v13 = v12 + 4040;
        if ( v6 <= 8 )
        {
          v14 = a1;
          if ( (unsigned int)(v6 - 7) < 2 )
          {
            v15 = a2;
            mutex_lock(v13 + 160);
            v16 = cam_cci_i2c_write(v14, v15, 0, 0);
            mutex_unlock(v13 + 160);
            result = v16;
            a2 = v15;
            goto LABEL_59;
          }
          result = 4294966781LL;
          if ( v6 != 6 )
            goto LABEL_59;
          v26 = v13 + 160;
          v21 = a2;
          if ( (unsigned int)mutex_trylock(v13 + 160) )
          {
            v27 = 0;
          }
          else
          {
            v29 = v13 + 208;
            if ( !(unsigned int)mutex_trylock(v29) )
            {
              mutex_lock(v26);
              v30 = v14;
              v31 = v21;
              v27 = 0;
              goto LABEL_57;
            }
            v27 = 1;
            v26 = v29;
          }
          v30 = v14;
          v31 = v21;
LABEL_57:
          v32 = cam_cci_i2c_write(v30, v31, v27, 0);
          mutex_unlock(v26);
          result = v32;
          goto LABEL_58;
        }
        if ( v6 == 9 )
        {
          v28 = a2;
        }
        else
        {
          if ( v6 != 11 )
          {
            v23 = a1;
            result = 4294966781LL;
            if ( v6 != 12 )
              goto LABEL_59;
            v24 = v12 + 4248;
            v18 = a2;
            mutex_lock(v24);
            v19 = cam_cci_i2c_write(v23, v18, 1, 1);
            v20 = v13 + 208;
LABEL_46:
            mutex_unlock(v20);
            result = v19;
            a2 = v18;
            goto LABEL_59;
          }
          v28 = a2;
        }
        result = cam_cci_i2c_write_async();
        a2 = v28;
        goto LABEL_59;
      }
      if ( v6 == 5 )
      {
        if ( *(_DWORD *)(v2 + 3960) == 268566537 )
        {
          if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
          {
            v36 = a2;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              debug_mdl & 0x4000,
              4,
              "cam_cci_core_cfg",
              2521,
              "cci-v1.2 no burst read");
            a2 = v36;
          }
          v17 = a2;
          result = cam_cci_read_bytes_v_1_2();
          a2 = v17;
        }
        else
        {
          v25 = a2;
          result = cam_cci_read_bytes();
          a2 = v25;
        }
        goto LABEL_59;
      }
      if ( v6 == 10 )
      {
        result = 0;
        goto LABEL_59;
      }
    }
    goto LABEL_41;
  }
  v10 = a1;
  if ( !v6 )
  {
    v18 = a2;
    mutex_lock(v2 + 5840);
    v19 = cam_cci_init(v10, v18);
    v20 = v2 + 5840;
    goto LABEL_46;
  }
  if ( v6 == 1 )
  {
    v21 = a2;
    mutex_lock(v2 + 5840);
    v22 = cam_cci_release(v10, v3);
    mutex_unlock(v2 + 5840);
    result = v22;
LABEL_58:
    a2 = v21;
    goto LABEL_59;
  }
  if ( v6 != 4 )
  {
LABEL_41:
    result = 4294966781LL;
    goto LABEL_59;
  }
  v11 = a2;
  result = cam_cci_i2c_set_sync_prms(a1);
  a2 = v11;
LABEL_59:
  *(_DWORD *)a2 = result;
  return result;
}
