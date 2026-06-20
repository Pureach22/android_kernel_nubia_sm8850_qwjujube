__int64 __fastcall cam_cpas_apply_smart_qos(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x22
  __int64 v4; // x21
  unsigned __int64 v5; // x8
  __int64 v6; // x6
  unsigned int v7; // w23
  int v8; // w24
  __int64 v9; // x8
  unsigned int v10; // w20
  __int64 v11; // x27
  __int64 v12; // x25
  unsigned __int64 v13; // x10
  _DWORD *v14; // x28
  __int64 v15; // x0
  int *v16; // x8
  __int64 v17; // x0
  int *v18; // x8
  int updated; // w0
  unsigned int v20; // w19
  __int64 result; // x0
  _QWORD v22[22]; // [xsp+0h] [xbp-B0h] BYREF

  v22[20] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 3680);
  v3 = *(_QWORD *)(a1 + 3392);
  v4 = v2 + 155648;
  memset(v22, 0, 160);
  if ( *(_BYTE *)(v2 + 159426) == 1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000000,
      3,
      "cam_cpas_apply_smart_qos",
      1152,
      "Printing SmartQoS values before update");
    cam_cpas_print_smart_qos_priority(a1);
  }
  v5 = *(unsigned __int8 *)(v2 + 159424);
  if ( v5 >= 4 || (v6 = *(unsigned int *)(*(_QWORD *)(*(_QWORD *)v2 + 8 * v5 + 8) + 4LL), (unsigned int)v6 > 9) )
  {
LABEL_47:
    __break(0x5512u);
LABEL_48:
    __break(1u);
  }
  v7 = *(_DWORD *)(v2 + 4 * v6 + 2812);
  switch ( (_DWORD)v6 )
  {
    case 1:
      v8 = 0x40000000;
      break;
    case 6:
      v8 = 0x20000000;
      break;
    case 5:
      v8 = 0x10000000;
      break;
    default:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_apply_smart_qos",
        1172,
        "Reg base %d is not supported in updating smart QoS",
        v6);
      result = 4294967274LL;
      goto LABEL_46;
  }
  v9 = *(_QWORD *)(v3 + 1616);
  if ( *(_BYTE *)(v9 + 9) )
  {
    v10 = 0;
    v11 = 2;
    v12 = a1 + 24LL * v7;
    do
    {
      if ( v11 == 12 )
        goto LABEL_47;
      v14 = *(_DWORD **)(v9 + 8 * v11);
      v15 = (unsigned int)v14[34];
      if ( (_DWORD)v15 != v14[36] )
      {
        if ( (*(_BYTE *)(v3 + 1611) & 1) != 0 )
        {
          if ( v10 > 0x13 )
            goto LABEL_47;
          v16 = (int *)&v22[v10];
          *v16 = v14[31] | v8;
          if ( ((8LL * v10) | 4uLL) > 0xA0 )
            goto LABEL_48;
          ++v10;
          v16[1] = v15;
        }
        else
        {
          if ( v7 > 7 )
            goto LABEL_47;
          cam_io_w_mb(v15, *(_QWORD *)(v12 + 384) + (unsigned int)v14[31]);
          LODWORD(v15) = v14[34];
        }
        v14[36] = v15;
      }
      v17 = (unsigned int)v14[33];
      if ( (_DWORD)v17 != v14[35] )
      {
        if ( (*(_BYTE *)(v3 + 1611) & 1) != 0 )
        {
          if ( v10 > 0x13 )
            goto LABEL_47;
          v18 = (int *)&v22[v10];
          *v18 = v14[30] | v8;
          if ( ((8LL * v10) | 4uLL) > 0xA0 )
            goto LABEL_48;
          ++v10;
          v18[1] = v17;
        }
        else
        {
          if ( v7 > 7 )
            goto LABEL_47;
          cam_io_w_mb(v17, *(_QWORD *)(v12 + 384) + (unsigned int)v14[30]);
          LODWORD(v17) = v14[33];
        }
        v14[35] = v17;
      }
      v9 = *(_QWORD *)(v3 + 1616);
      v13 = v11++ - 1;
    }
    while ( v13 < *(unsigned __int8 *)(v9 + 9) );
    if ( *(_BYTE *)(v3 + 1611) == 1 && v10 )
    {
      if ( (debug_mdl & 0x2000004) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2000004,
          4,
          "cam_cpas_apply_smart_qos",
          1212,
          "Updating secure camera smartQoS count: %d",
          v10);
      updated = cam_update_camnoc_qos_settings();
      if ( updated )
      {
        v20 = updated;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000000,
          1,
          "cam_cpas_apply_smart_qos",
          1216,
          "Secure camera smartQoS update failed: %d",
          updated);
        result = v20;
        goto LABEL_46;
      }
      if ( (debug_mdl & 0x2000004) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x2000004,
          4,
          "cam_cpas_apply_smart_qos",
          1219,
          "Updated secure camera smartQoS");
    }
  }
  if ( *(_BYTE *)(v4 + 3778) == 1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000000,
      3,
      "cam_cpas_apply_smart_qos",
      1223,
      "Printing SmartQoS values after update");
    cam_cpas_print_smart_qos_priority(a1);
  }
  result = 0;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
