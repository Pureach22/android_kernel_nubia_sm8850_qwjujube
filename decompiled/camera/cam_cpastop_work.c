_QWORD *__fastcall cam_cpastop_work(__int64 a1)
{
  _QWORD *v1; // x23
  __int64 v3; // x21
  __int64 v4; // x22
  __int64 v5; // x19
  unsigned int v6; // w8
  unsigned int v13; // w12
  int v14; // w8
  __int64 v15; // x24
  __int64 v16; // x23
  __int64 v17; // x26
  int v18; // w9
  _QWORD *result; // x0
  __int64 v20; // x10
  int v21; // w27
  __int64 v22; // x0
  __int64 v23; // x27
  __int64 v24; // x8
  unsigned int v25; // w8
  unsigned int v26; // w0
  __int64 v27; // x27
  __int64 v28; // x8
  unsigned int v29; // w8
  int v30; // w0
  __int64 v31; // x0
  unsigned int v34; // w10
  int v35; // [xsp+10h] [xbp-70h]
  int v36; // [xsp+18h] [xbp-68h]
  int v37; // [xsp+20h] [xbp-60h]
  int v38; // [xsp+28h] [xbp-58h]
  _QWORD *v39; // [xsp+30h] [xbp-50h]
  __int64 v40; // [xsp+38h] [xbp-48h]
  __int64 v41; // [xsp+40h] [xbp-40h]
  _DWORD v42[12]; // [xsp+48h] [xbp-38h] BYREF
  __int64 v43; // [xsp+78h] [xbp-8h]

  v1 = (_QWORD *)(a1 - 32);
  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v42, 0, 44);
  if ( a1 == 32 )
  {
    result = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                         3,
                         4,
                         1,
                         "cam_cpastop_work",
                         923,
                         "NULL payload");
    goto LABEL_58;
  }
  v3 = *(unsigned int *)(a1 - 32);
  cam_common_util_thread_switch_delay_detect("cam_cpas_workq", "schedule", cam_cpastop_work, *(_QWORD *)(a1 - 8), 5u);
  if ( (unsigned int)v3 >= 4 )
LABEL_62:
    __break(0x5512u);
  v4 = *(_QWORD *)(*(_QWORD *)(a1 - 24) + 3680LL);
  v40 = *(_QWORD *)(a1 - 24);
  v5 = *(_QWORD *)(*(_QWORD *)v4 + 8 * v3 + 8);
  v6 = *(_DWORD *)(v4 + 8104);
  do
  {
    if ( !v6 )
    {
      result = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                           3,
                           4,
                           1,
                           "cam_cpastop_work",
                           939,
                           "CPAS off");
      goto LABEL_58;
    }
    _X14 = (unsigned int *)(v4 + 8104);
    __asm { PRFM            #0x11, [X14] }
    while ( 1 )
    {
      v13 = __ldxr(_X14);
      if ( v13 != v6 )
        break;
      if ( !__stlxr(v6 + 1, _X14) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v13 == v6;
    v6 = v13;
  }
  while ( !_ZF );
  v14 = *(_DWORD *)(v5 + 40);
  v39 = v1;
  if ( v14 >= 1 )
  {
    v15 = 0;
    v16 = 0;
    v41 = v4 + 2812;
    v17 = v40 + 384;
    v18 = *(_DWORD *)(a1 - 16);
    while ( 2 )
    {
      v20 = *(_QWORD *)(v5 + 32);
      if ( (*(_DWORD *)(v20 + v15 + 8) & v18) == 0 || *(_BYTE *)(v20 + v15 + 4) != 1 )
        goto LABEL_17;
      v21 = *(_DWORD *)(v20 + v15);
      if ( (unsigned int)__ratelimit(&cam_cpastop_work__rs, "cam_cpastop_work") )
        v22 = 3;
      else
        v22 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v22,
        4,
        1,
        "cam_cpastop_work",
        948,
        "Error occurred, irq type=%d",
        v21);
      memset(&v42[1], 0, 40);
      v42[0] = v21;
      if ( v21 > 13 )
      {
        if ( v21 > 16 )
        {
          switch ( v21 )
          {
            case 17:
              goto LABEL_40;
            case 19:
              if ( (unsigned int)__ratelimit(
                                   &cam_cpastop_handle_ahb_timeout_err__rs,
                                   "cam_cpastop_handle_ahb_timeout_err") )
                v31 = 3;
              else
                v31 = 2;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                v31,
                4,
                1,
                "cam_cpastop_handle_ahb_timeout_err",
                708,
                "[%s] ahb timeout error",
                g_camnoc_names[v3]);
              break;
            case 22:
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                4,
                3,
                "cam_cpastop_work",
                982,
                "TEST IRQ for %s",
                g_camnoc_names[v3]);
              break;
            default:
              goto LABEL_49;
          }
          goto LABEL_16;
        }
        if ( (unsigned int)(v21 - 14) < 2 )
          goto LABEL_40;
      }
      else if ( v21 <= 9 )
      {
        if ( (unsigned int)(v21 - 4) >= 2 )
        {
          if ( !v21 )
          {
            cam_cpastop_handle_errlogger(v3, (_QWORD *)v4, v40 + 96, &v42[1]);
            goto LABEL_16;
          }
          if ( v21 != 2 )
          {
LABEL_49:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4,
              1,
              "cam_cpastop_work",
              985,
              "Invalid IRQ type: %u",
              v21);
            goto LABEL_16;
          }
        }
LABEL_40:
        v27 = *(_QWORD *)(*(_QWORD *)v4 + 8 * v3 + 8);
        v28 = *(unsigned int *)(v27 + 4);
        if ( (unsigned int)v28 > 9 )
          goto LABEL_62;
        v29 = *(_DWORD *)(v41 + 4 * v28);
        if ( v29 > 7 )
          goto LABEL_62;
        v30 = cam_io_r_mb(*(_QWORD *)(v17 + 24LL * v29) + *(unsigned int *)(*(_QWORD *)(v27 + 32) + v15 + 52));
        v42[1] = v30;
        if ( (debug_mdl & 4) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, char *, _QWORD, _DWORD, int, int, int, int, int))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpastop_handle_ubwc_enc_err",
            677,
            "[%s] ubwc enc err [%d]: offset[0x%x] value[0x%x]",
            g_camnoc_names[v3],
            (unsigned int)v16,
            *(_DWORD *)(*(_QWORD *)(v27 + 32) + v15 + 52),
            v30,
            v35,
            v36,
            v37,
            v38);
LABEL_16:
        cam_cpastop_notify_clients(v4, v42, 0);
        v18 = *(_DWORD *)(a1 - 16) & ~*(_DWORD *)(*(_QWORD *)(v5 + 32) + v15 + 8);
        *(_DWORD *)(a1 - 16) = v18;
        v14 = *(_DWORD *)(v5 + 40);
LABEL_17:
        ++v16;
        v15 += 96;
        if ( v16 >= v14 )
          goto LABEL_50;
        continue;
      }
      break;
    }
    v23 = *(_QWORD *)(*(_QWORD *)v4 + 8 * v3 + 8);
    v24 = *(unsigned int *)(v23 + 4);
    if ( (unsigned int)v24 > 9 )
      goto LABEL_62;
    v25 = *(_DWORD *)(v41 + 4 * v24);
    if ( v25 > 7 )
      goto LABEL_62;
    v26 = cam_io_r_mb(*(_QWORD *)(v17 + 24LL * v25) + *(unsigned int *)(*(_QWORD *)(v23 + 32) + v15 + 52));
    v42[1] = v26;
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, char *, _QWORD, _DWORD, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_handle_ubwc_dec_err",
        699,
        "[%s] ubwc dec err status [%d]: offset[0x%x] value[0x%x] thr_err=%d, fcl_err=%d, len_md_err=%d, format_err=%d",
        g_camnoc_names[v3],
        (unsigned int)v16,
        *(_DWORD *)(*(_QWORD *)(v23 + 32) + v15 + 52),
        v26,
        v26 & 1,
        (v26 >> 1) & 1,
        (v26 >> 2) & 1,
        (v26 >> 3) & 1);
    goto LABEL_16;
  }
LABEL_50:
  _X8 = (unsigned int *)(v4 + 8104);
  __asm { PRFM            #0x11, [X8] }
  do
    v34 = __ldxr(_X8);
  while ( __stxr(v34 - 1, _X8) );
  _wake_up(v4 + 8112, 3, 1, 0);
  if ( (debug_mdl & 4) == 0 || debug_priority )
  {
    if ( !*(_DWORD *)(a1 - 16) )
      goto LABEL_55;
    goto LABEL_54;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 4,
    4,
    "cam_cpastop_work",
    997,
    "soc_access_count=%d\n",
    *(_DWORD *)(v4 + 8104));
  if ( *(_DWORD *)(a1 - 16) )
LABEL_54:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpastop_work",
      1001,
      "%s IRQ not handled irq_status=0x%x",
      g_camnoc_names[v3]);
LABEL_55:
  if ( mem_trace_en == 1 )
    result = cam_mem_trace_free(v39, 0);
  else
    result = (_QWORD *)kvfree(v39);
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return result;
}
