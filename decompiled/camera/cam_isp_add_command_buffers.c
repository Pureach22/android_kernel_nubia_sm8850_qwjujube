__int64 __fastcall cam_isp_add_command_buffers(
        __int64 *a1,
        __int64 a2,
        unsigned int *a3,
        _DWORD *a4,
        __int64 a5,
        __int64 a6,
        unsigned int a7,
        unsigned int a8)
{
  __int64 v10; // x19
  unsigned int v11; // w10
  int v12; // w27
  __int64 v13; // x20
  unsigned __int64 v14; // x26
  __int64 v15; // x19
  _DWORD *v16; // x21
  __int64 v17; // x26
  __int64 v18; // x28
  unsigned int v19; // w25
  unsigned int v20; // w21
  __int64 v21; // x20
  unsigned int updated; // w0
  unsigned int v23; // w21
  _DWORD *v24; // x21
  __int64 v25; // x1
  __int64 v26; // x6
  __int64 v27; // x11
  _QWORD *v28; // x8
  __int64 v29; // x9
  char v30; // w8
  unsigned int v31; // w0
  unsigned int v32; // w0
  unsigned int v33; // w0
  const char *v34; // x5
  __int64 v35; // x4
  __int64 v37; // x4
  __int64 v38; // [xsp+18h] [xbp-68h]
  unsigned int v39; // [xsp+20h] [xbp-60h]
  unsigned int v40; // [xsp+24h] [xbp-5Ch]
  unsigned int v41; // [xsp+24h] [xbp-5Ch]
  __int64 v42; // [xsp+28h] [xbp-58h]
  __int64 v43; // [xsp+28h] [xbp-58h]
  unsigned int v44; // [xsp+34h] [xbp-4Ch]
  unsigned int v45; // [xsp+34h] [xbp-4Ch]
  __int64 v46; // [xsp+40h] [xbp-40h]
  _DWORD *v47; // [xsp+48h] [xbp-38h]
  __int64 v48; // [xsp+50h] [xbp-30h]
  __int64 *v49; // [xsp+58h] [xbp-28h] BYREF
  unsigned int *v50; // [xsp+60h] [xbp-20h]
  __int64 v51; // [xsp+68h] [xbp-18h]
  __int64 v52; // [xsp+70h] [xbp-10h]
  __int64 v53; // [xsp+78h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v11 = *a3;
  v12 = a3[1];
  v13 = *(unsigned int *)(*a1 + 24);
  v48 = a1[4];
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    if ( *(_DWORD *)(v10 + 28) )
      goto LABEL_4;
LABEL_6:
    v20 = 0;
    goto LABEL_48;
  }
  v45 = a8;
  v16 = a4;
  v43 = a6;
  v17 = a2;
  v18 = a5;
  v19 = a7;
  v41 = *a3;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_isp_add_command_buffers",
    340,
    "split id = %d, number of command buffers:%d",
    v12,
    *(_DWORD *)(v10 + 28));
  a6 = v43;
  v11 = v41;
  a5 = v18;
  a8 = v45;
  a7 = v19;
  a2 = v17;
  a4 = v16;
  if ( !*(_DWORD *)(*a1 + 28) )
    goto LABEL_6;
LABEL_4:
  v14 = 0;
  v40 = v11;
  v15 = v10 + v13 + 56;
  v46 = a2;
  v47 = a4;
  v38 = a5;
  v42 = a6;
  v39 = a7;
  v44 = a8;
  while ( 2 )
  {
    updated = cam_packet_util_validate_cmd_desc((int *)v15);
    if ( updated )
    {
LABEL_46:
      v20 = updated;
      goto LABEL_48;
    }
    if ( !*(_DWORD *)(v15 + 12) )
      goto LABEL_10;
    v21 = *((unsigned int *)a1 + 10);
    if ( (unsigned int)(v21 + 1) >= *((_DWORD *)a1 + 6) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_add_command_buffers",
        354,
        "Insufficient  HW entries :%d %d",
        (unsigned int)v21);
      v20 = -22;
      goto LABEL_48;
    }
    updated = cam_packet_util_validate_cmd_desc((int *)v15);
    if ( updated )
      goto LABEL_46;
    v23 = *(_DWORD *)(v15 + 20);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_isp_add_command_buffers",
        365,
        "meta type: %d, split_id: %d",
        v23,
        v12);
      if ( v23 > 0x18 )
      {
LABEL_45:
        v34 = "invalid cdm command meta data %d";
        v35 = 519;
        v26 = v23;
        goto LABEL_50;
      }
    }
    switch ( v23 )
    {
      case 0u:
      case 1u:
      case 4u:
        if ( v12 )
          goto LABEL_9;
        v24 = (_DWORD *)(v48 + 32 * v21);
        v24[2] = *(_DWORD *)(v15 + 12);
        *v24 = *(_DWORD *)v15;
        v24[1] = *(_DWORD *)(v15 + 4);
        if ( (debug_mdl & 8) == 0 || debug_priority )
          goto LABEL_8;
        v25 = debug_mdl & 8;
        goto LABEL_7;
      case 2u:
      case 5u:
        if ( v12 != 1 )
          goto LABEL_9;
        v24 = (_DWORD *)(v48 + 32 * v21);
        v24[2] = *(_DWORD *)(v15 + 12);
        *v24 = *(_DWORD *)v15;
        v24[1] = *(_DWORD *)(v15 + 4);
        if ( (debug_mdl & 8) == 0 || debug_priority )
          goto LABEL_8;
        v25 = debug_mdl & 8;
LABEL_7:
        ((void (__fastcall *)(__int64, __int64))cam_print_log)(3, v25);
LABEL_8:
        LODWORD(v21) = v21 + 1;
        v24[3] = 2;
        goto LABEL_9;
      case 3u:
      case 6u:
        v24 = (_DWORD *)(v48 + 32 * v21);
        v24[2] = *(_DWORD *)(v15 + 12);
        *v24 = *(_DWORD *)v15;
        v24[1] = *(_DWORD *)(v15 + 4);
        if ( (debug_mdl & 8) == 0 || debug_priority )
          goto LABEL_8;
        v25 = debug_mdl & 8;
        goto LABEL_7;
      case 9u:
        updated = cam_isp_update_dual_config(v15, v40, v38, v42, v39, v44);
        if ( updated )
          goto LABEL_46;
        goto LABEL_9;
      case 0xAu:
        if ( v12 )
          goto LABEL_9;
        v49 = a1;
        v50 = a3;
        v51 = v46;
        v52 = 0;
        v33 = cam_packet_util_process_generic_cmd_buffer((int *)v15, v47, (__int64)&v49);
        if ( !v33 )
          goto LABEL_43;
        v20 = v33;
        v37 = 438;
        goto LABEL_52;
      case 0xBu:
        if ( v12 != 1 )
          goto LABEL_9;
        v49 = a1;
        v50 = a3;
        v51 = v46;
        v52 = 0;
        v31 = cam_packet_util_process_generic_cmd_buffer((int *)v15, v47, (__int64)&v49);
        if ( v31 )
        {
          v20 = v31;
          v37 = 460;
LABEL_52:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_add_command_buffers",
            v37,
            "Failed in processing blobs %d",
            v20);
          goto LABEL_48;
        }
LABEL_43:
        LODWORD(v21) = *((_DWORD *)a1 + 10);
        goto LABEL_9;
      case 0xCu:
        v49 = a1;
        v50 = a3;
        v51 = v46;
        v52 = 0;
        v32 = cam_packet_util_process_generic_cmd_buffer((int *)v15, v47, (__int64)&v49);
        if ( !v32 )
          goto LABEL_43;
        v20 = v32;
        v37 = 480;
        goto LABEL_52;
      case 0xDu:
      case 0xEu:
      case 0xFu:
        if ( v12 )
          goto LABEL_9;
        v26 = *((unsigned int *)a1 + 79);
        if ( (unsigned int)v26 < 0xA )
        {
          v27 = *(_QWORD *)v15;
          v28 = (__int64 *)((char *)&a1[3 * (unsigned int)v26 + 9] + 4);
          v29 = *(_QWORD *)(v15 + 16);
          v28[1] = *(_QWORD *)(v15 + 8);
          v28[2] = v29;
          *v28 = v27;
          v30 = debug_mdl;
          ++*((_DWORD *)a1 + 79);
          if ( (v30 & 8) != 0 && !debug_priority )
            ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              v30 & 8,
              4,
              "cam_isp_add_command_buffers",
              505,
              "Added command buffer: %d desc_count: %d",
              *(unsigned int *)(v15 + 20));
LABEL_9:
          *((_DWORD *)a1 + 10) = v21;
LABEL_10:
          ++v14;
          v15 += 24;
          if ( v14 >= *(unsigned int *)(*a1 + 28) )
            goto LABEL_6;
          continue;
        }
        v34 = "Descriptor count out of bounds: %d";
        v35 = 494;
LABEL_50:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_add_command_buffers",
          v35,
          v34,
          v26);
        v20 = -22;
LABEL_48:
        _ReadStatusReg(SP_EL0);
        return v20;
      case 0x10u:
      case 0x11u:
      case 0x12u:
      case 0x15u:
      case 0x16u:
      case 0x17u:
      case 0x18u:
        goto LABEL_9;
      default:
        goto LABEL_45;
    }
  }
}
