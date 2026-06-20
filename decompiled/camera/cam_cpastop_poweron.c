__int64 __fastcall cam_cpastop_poweron(__int64 a1)
{
  __int64 v1; // x23
  __int64 v2; // x20
  _QWORD *v4; // x8
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x9
  __int64 v8; // x8
  int updated; // w0
  __int64 v10; // x20
  __int64 v11; // x26
  char v12; // w28
  unsigned int *v13; // x27
  char v14; // w8
  int v15; // w8
  __int64 v16; // x21
  __int64 v17; // x20
  __int64 v18; // x9
  __int64 v19; // x0
  __int64 v20; // x0
  int v21; // t1
  __int64 v22; // x9
  unsigned int v23; // w20
  unsigned int *v24; // x21
  int v25; // w6
  unsigned int v26; // w21

  v1 = *(_QWORD *)(a1 + 3680);
  v2 = *(_QWORD *)(a1 + 3392);
  v4 = *(_QWORD **)v1;
  v5 = *(_QWORD *)(*(_QWORD *)v1 + 8LL);
  if ( v5 && *(_DWORD *)(v5 + 4) != 7 )
  {
    cam_cpastop_reset_irq(0, a1, 0);
    v4 = *(_QWORD **)v1;
  }
  v6 = v4[2];
  if ( v6 && *(_DWORD *)(v6 + 4) != 7 )
  {
    cam_cpastop_reset_irq(0, a1, 1);
    v4 = *(_QWORD **)v1;
  }
  v7 = v4[3];
  if ( v7 && *(_DWORD *)(v7 + 4) != 7 )
  {
    cam_cpastop_reset_irq(0, a1, 2);
    v4 = *(_QWORD **)v1;
  }
  v8 = v4[4];
  if ( v8 && *(_DWORD *)(v8 + 4) != 7 )
    cam_cpastop_reset_irq(0, a1, 3);
  if ( (*(_BYTE *)(v2 + 1611) & 1) == 0 )
  {
    v11 = 0;
    v12 = 0;
    while ( 1 )
    {
      v13 = *(unsigned int **)(*(_QWORD *)v1 + 8 * v11 + 8);
      if ( v13 )
      {
        v14 = debug_mdl;
        if ( (debug_mdl & 4) != 0 && !debug_priority )
        {
          v22 = *v13;
          if ( (unsigned int)v22 >= 5 )
            goto LABEL_60;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpastop_curr_camnoc_poweron",
            1248,
            "QOS settings for %s :",
            g_camnoc_names[v22]);
        }
        v15 = v13[4];
        if ( v15 >= 1 )
        {
          v16 = 0;
          v17 = 216;
          do
          {
            v18 = *((_QWORD *)v13 + 1);
            if ( *(_BYTE *)(v18 + v17 - 200) == 1 )
            {
              if ( (debug_mdl & 4) != 0 && !debug_priority )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 4,
                  4,
                  "cam_cpastop_curr_camnoc_poweron",
                  1255,
                  "Updating QoS settings port: %d prot name: %s",
                  *(_DWORD *)(v18 + v17 - 216),
                  *(const char **)(v18 + v17 - 208));
                v18 = *((_QWORD *)v13 + 1);
              }
              ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_update)(a1, v13[1], v18 + v17 - 196);
              ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_update)(
                a1,
                v13[1],
                *((_QWORD *)v13 + 1) + v17 - 168);
              ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_update)(
                a1,
                v13[1],
                *((_QWORD *)v13 + 1) + v17 - 140);
              ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_update)(
                a1,
                v13[1],
                *((_QWORD *)v13 + 1) + v17 - 112);
              ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_update)(
                a1,
                v13[1],
                *((_QWORD *)v13 + 1) + v17 - 84);
              ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_update)(
                a1,
                v13[1],
                *((_QWORD *)v13 + 1) + v17 - 56);
              ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_update)(
                a1,
                v13[1],
                *((_QWORD *)v13 + 1) + v17 - 28);
              ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_update)(
                a1,
                v13[1],
                *((_QWORD *)v13 + 1) + v17 + 168);
              ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_update)(
                a1,
                v13[1],
                *((_QWORD *)v13 + 1) + v17);
              ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_update)(
                a1,
                v13[1],
                *((_QWORD *)v13 + 1) + v17 + 28);
              ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_update)(
                a1,
                v13[1],
                *((_QWORD *)v13 + 1) + v17 + 56);
              v15 = v13[4];
            }
            ++v16;
            v17 += 416;
          }
          while ( v16 < v15 );
        }
        if ( (v12 & 1) == 0 )
        {
          v19 = *((_QWORD *)v13 + 7);
          if ( !v19 || (v21 = *(unsigned __int8 *)(v19 + 32), v20 = v19 + 32, v21 != 1) )
          {
            v12 = 0;
            goto LABEL_22;
          }
          cam_cpastop_scm_write(v20);
        }
        v12 = 1;
      }
LABEL_22:
      if ( ++v11 == 4 )
        goto LABEL_42;
    }
  }
  if ( (debug_mdl & 4) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpastop_poweron",
      1332,
      "Updating secure camera static QoS settings");
  updated = cam_update_camnoc_qos_settings();
  if ( updated )
  {
    LODWORD(v10) = updated;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpastop_poweron",
      1335,
      "Secure camera static OoS update failed: %d",
      updated);
    return (unsigned int)v10;
  }
  v14 = debug_mdl;
  if ( (debug_mdl & 4) != 0 && !debug_priority )
    goto LABEL_61;
  while ( 1 )
  {
LABEL_42:
    if ( *(_BYTE *)(v1 + 159434) == 1 )
    {
      v23 = *(_DWORD *)(v1 + 2844);
      if ( v23 == -1 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          2,
          "cam_cpastop_poweron",
          1361,
          "Invalid CPAS secure regbase index: %d",
          -1);
      }
      else
      {
        v14 = debug_mdl;
        v24 = *(unsigned int **)(*(_QWORD *)(*(_QWORD *)v1 + 40LL) + 40LL);
        if ( (debug_mdl & 4) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpastop_poweron",
            1354,
            "Set reg offset: 0x%x value: 0x%x with regbase index: %d for secure",
            *v24,
            v24[1],
            v23);
          if ( v23 > 7 )
            goto LABEL_60;
        }
        else if ( v23 > 7 )
        {
          goto LABEL_60;
        }
        cam_io_w_mb(v24[1], *(_QWORD *)(a1 + 24LL * v23 + 384) + *v24);
      }
    }
    v10 = *(_QWORD *)(*(_QWORD *)v1 + 24LL);
    if ( !v10 )
      return (unsigned int)v10;
    v25 = *(_DWORD *)(v10 + 80);
    if ( !v25 )
      goto LABEL_55;
    v14 = debug_mdl;
    v26 = *(_DWORD *)(v1 + 2836);
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      break;
    if ( v26 <= 7 )
      goto LABEL_54;
LABEL_60:
    __break(0x5512u);
LABEL_61:
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v14 & 4,
      4,
      "cam_cpastop_poweron",
      1338,
      "Updated secure camera static QoS settings");
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 4,
    4,
    "cam_cpastop_poweron",
    1370,
    "Writing DCD Div factor 0x4, offset 0x%x",
    v25);
  if ( v26 > 7 )
    goto LABEL_60;
LABEL_54:
  cam_io_w_mb(4, *(_QWORD *)(a1 + 24LL * v26 + 384) + *(unsigned int *)(v10 + 80));
LABEL_55:
  LODWORD(v10) = 0;
  return (unsigned int)v10;
}
