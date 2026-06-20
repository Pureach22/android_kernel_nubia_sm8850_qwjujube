__int64 __fastcall cam_cdm_util_dump_cmd_buf(unsigned __int16 *a1, unsigned __int16 *a2)
{
  unsigned __int16 *v3; // x21
  const char *v4; // x20
  const char *v5; // x23
  const char *v6; // x22
  const char *v7; // x25
  const char *v8; // x26
  __int64 result; // x0
  unsigned __int16 *v10; // x27
  int v11; // w7
  unsigned int v12; // w6
  const char *v13; // x24
  const char *v14; // x20
  const char *v15; // x26
  const char *v16; // x23
  const char *v17; // x25
  __int64 v18; // x22
  unsigned int v19; // w27
  unsigned __int16 *v20; // x28
  int v21; // w8
  int v22; // w9
  __int64 v23; // x6
  const char *v24; // x3
  __int64 v25; // x4
  __int64 v26; // x7
  const char *v27; // x5
  const char *v28; // x3
  __int64 v29; // x4
  __int64 v30; // x27
  unsigned __int16 *v31; // x28
  unsigned int v32; // t1

  if ( a1 && a2 )
  {
    v3 = a1;
    v4 = "cam_cdm_util_dump_reg_cont_cmd";
    v5 = "DATA_%d: 0x%X";
    v6 = "Invalid cmd start addr:%pK end addr:%pK";
    v7 = "WAIT_EVENT";
    v8 = "cam_cdm_util_dump_dmi_cmd";
    while ( 1 )
    {
      v11 = *(_DWORD *)v3;
      v12 = HIBYTE(*(_DWORD *)v3);
      if ( v12 > 7 )
        break;
      if ( HIBYTE(*(_DWORD *)v3) <= 4u )
      {
        if ( v12 != 1 )
        {
          if ( v12 == 3 )
          {
            result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       1,
                       3,
                       v4,
                       911,
                       "REG_CONT: COUNT: %u OFFSET: 0x%X",
                       *v3,
                       *((_DWORD *)v3 + 1) & 0xFFFFFF);
            if ( *v3 )
            {
              v30 = 0;
              v31 = v3 + 4;
              while ( v31 <= a2 )
              {
                v32 = *(_DWORD *)v31;
                v31 += 2;
                result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
                           3,
                           1,
                           3,
                           v4,
                           921,
                           v5,
                           (unsigned int)v30++,
                           v32);
                if ( (unsigned int)v30 >= *v3 )
                  goto LABEL_47;
              }
              result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         1,
                         1,
                         v4,
                         917,
                         "Invalid cmd(%d) start addr:%pK end addr:%pK",
                         v30,
                         v31,
                         a2);
LABEL_47:
              v10 = &v3[2 * v30 + 4];
            }
            else
            {
              v10 = v3 + 4;
            }
            goto LABEL_5;
          }
          if ( v12 == 4 )
          {
            v13 = v4;
            v14 = v8;
            v15 = v5;
            v16 = v7;
            v17 = v6;
            result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       1,
                       3,
                       "cam_cdm_util_dump_reg_random_cmd",
                       942,
                       "REG_RAND: COUNT: %u",
                       (unsigned __int16)*(_DWORD *)v3);
            v18 = 1;
            if ( *v3 )
            {
              v19 = 0;
              v20 = v3 + 2;
              v18 = 1;
              while ( v20 <= a2 )
              {
                v21 = *(_DWORD *)v20;
                v22 = *((_DWORD *)v20 + 1);
                v20 += 4;
                result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                           3,
                           1,
                           3,
                           "cam_cdm_util_dump_reg_random_cmd",
                           953,
                           "OFFSET_%d: 0x%X DATA_%d: 0x%X",
                           v19,
                           v21 & 0xFFFFFF,
                           v19,
                           v22);
                ++v19;
                v18 += 2;
                if ( v19 >= *v3 )
                  goto LABEL_49;
              }
              result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         1,
                         1,
                         "cam_cdm_util_dump_reg_random_cmd",
                         948,
                         "Invalid cmd(%d) start addr:%pK end addr:%pK",
                         v19,
                         v20,
                         a2);
            }
LABEL_49:
            v10 = &v3[2 * v18];
            v6 = v17;
            v7 = v16;
            v5 = v15;
            v8 = v14;
            v4 = v13;
            goto LABEL_5;
          }
          goto LABEL_42;
        }
LABEL_18:
        v10 = v3 + 6;
        if ( v3 + 6 > a2 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int16 *, unsigned __int16 *))cam_print_log)(
            3,
            1,
            1,
            v8,
            867,
            v6,
            v3 + 6,
            a2);
          LOWORD(v11) = *v3;
        }
        v23 = (unsigned __int16)v11;
        v24 = v8;
        v25 = 872;
        v26 = *((_DWORD *)v3 + 2) & 0xFFFFFF;
        v27 = "DMI: LEN: %u DMIAddr: 0x%X DMISel: 0x%X LUT_addr: 0x%X";
LABEL_41:
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
                   3,
                   1,
                   3,
                   v24,
                   v25,
                   v27,
                   v23,
                   v26);
        goto LABEL_5;
      }
      if ( v12 == 5 )
      {
        v10 = v3 + 4;
        if ( v3 + 4 > a2 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int16 *, unsigned __int16 *))cam_print_log)(
            3,
            1,
            1,
            "cam_cdm_util_dump_buff_indirect",
            890,
            v6,
            v3 + 4,
            a2);
          LOWORD(v11) = *v3;
        }
        v23 = (unsigned __int16)v11;
        v24 = "cam_cdm_util_dump_buff_indirect";
        v25 = 894;
        v27 = "Buff Indirect: LEN: %u addr: 0x%X";
        v26 = *((unsigned int *)v3 + 1);
        goto LABEL_41;
      }
      if ( v12 != 6 )
      {
        if ( v12 != 7 )
          goto LABEL_42;
        v28 = "cam_cdm_util_dump_wait_event_cmd";
        v29 = 978;
LABEL_30:
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                   3,
                   1,
                   3,
                   v28,
                   v29,
                   v7);
        v10 = v3 + 6;
        goto LABEL_5;
      }
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                 3,
                 1,
                 3,
                 "cam_cdm_util_dump_gen_irq_cmd",
                 967,
                 "GEN_IRQ");
      v10 = v3 + 4;
LABEL_5:
      v3 = v10;
      if ( v10 >= a2 )
        return result;
    }
    if ( HIBYTE(*(_DWORD *)v3) <= 9u )
    {
      if ( v12 == 8 )
      {
        if ( v3 <= a2 )
        {
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     1,
                     3,
                     "cam_cdm_util_dump_change_base_cmd",
                     1003,
                     "CHANGE_BASE: 0x%X, curr cmd addr: %pK",
                     v11 & 0xFFFFFF,
                     v3 + 2);
          v10 = v3 + 2;
        }
        else
        {
          result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int16 *, unsigned __int16 *))cam_print_log)(
                     3,
                     1,
                     1,
                     "cam_cdm_util_dump_change_base_cmd",
                     993,
                     v6,
                     v3,
                     a2);
          v10 = v3;
        }
        goto LABEL_5;
      }
      if ( v12 == 9 )
      {
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                   3,
                   1,
                   3,
                   "cam_cdm_util_dump_perf_ctrl_cmd",
                   1025,
                   "PERF_CTRL");
LABEL_43:
        v10 = v3 + 2;
        goto LABEL_5;
      }
LABEL_42:
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 1,
                 1,
                 "cam_cdm_util_dump_cmd_buf",
                 1166,
                 "Invalid CMD: 0x%x buf 0x%x",
                 v12,
                 v11);
      goto LABEL_43;
    }
    if ( v12 - 10 < 2 )
      goto LABEL_18;
    if ( v12 != 12 )
      goto LABEL_42;
    v28 = "cam_cdm_util_dump_comp_wait_event_cmd";
    v29 = 1014;
    goto LABEL_30;
  }
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
           3,
           1,
           1,
           "cam_cdm_util_dump_cmd_buf",
           1120,
           "Invalid args");
}
