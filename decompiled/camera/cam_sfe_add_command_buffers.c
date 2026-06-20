__int64 __fastcall cam_sfe_add_command_buffers(
        __int64 *a1,
        __int64 a2,
        int *a3,
        _DWORD *a4,
        __int64 a5,
        __int64 a6,
        unsigned int a7,
        unsigned int a8)
{
  __int64 v10; // x19
  int v11; // w27
  __int64 v12; // x28
  __int64 v13; // x20
  unsigned __int64 v14; // x26
  int *v15; // x28
  int v16; // w24
  unsigned int updated; // w0
  __int64 v18; // x19
  int v19; // w6
  bool v20; // cf
  unsigned int v21; // w0
  int v22; // w8
  _DWORD *v23; // x20
  __int64 v24; // x7
  int v25; // w10
  unsigned int v26; // w0
  int v27; // w8
  __int64 v28; // x7
  int v29; // w10
  int v30; // w8
  __int64 v31; // x7
  int v32; // w10
  unsigned int v33; // w0
  int v34; // w20
  unsigned int v35; // w20
  __int64 v36; // x4
  __int64 v37; // x24
  unsigned int v38; // w26
  unsigned int v40; // [xsp+14h] [xbp-5Ch]
  __int64 v41; // [xsp+18h] [xbp-58h]
  __int64 v42; // [xsp+18h] [xbp-58h]
  __int64 v43; // [xsp+20h] [xbp-50h]
  __int64 v44; // [xsp+20h] [xbp-50h]
  unsigned int v45; // [xsp+2Ch] [xbp-44h]
  unsigned int v46; // [xsp+2Ch] [xbp-44h]
  __int64 v47; // [xsp+30h] [xbp-40h]
  __int64 v48; // [xsp+38h] [xbp-38h]
  _DWORD *v49; // [xsp+40h] [xbp-30h]
  _DWORD *v50; // [xsp+40h] [xbp-30h]
  __int64 *v51; // [xsp+48h] [xbp-28h] BYREF
  int *v52; // [xsp+50h] [xbp-20h]
  __int64 v53; // [xsp+58h] [xbp-18h]
  __int64 v54; // [xsp+60h] [xbp-10h]
  __int64 v55; // [xsp+68h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v11 = a3[1];
  v12 = a1[4];
  v13 = *(unsigned int *)(*a1 + 24);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v46 = a8;
    v37 = a2;
    v50 = a4;
    v42 = a5;
    v44 = a6;
    v38 = a7;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_sfe_add_command_buffers",
      556,
      "split id = %d, number of command buffers:%d",
      v11,
      *(_DWORD *)(v10 + 28));
    a5 = v42;
    a6 = v44;
    a7 = v38;
    a4 = v50;
    a8 = v46;
    a2 = v37;
    if ( *(_DWORD *)(*a1 + 28) )
      goto LABEL_4;
LABEL_56:
    v35 = 0;
    goto LABEL_57;
  }
  if ( !*(_DWORD *)(v10 + 28) )
    goto LABEL_56;
LABEL_4:
  v47 = v12;
  v48 = a2;
  v14 = 0;
  v15 = (int *)(v10 + v13 + 56);
  v49 = a4;
  v41 = a5;
  v43 = a6;
  v40 = a7;
  v45 = a8;
  while ( 1 )
  {
    updated = cam_packet_util_validate_cmd_desc(v15);
    if ( updated )
    {
LABEL_49:
      v35 = updated;
      goto LABEL_57;
    }
    if ( v15[3] )
      break;
LABEL_8:
    ++v14;
    v15 += 6;
    if ( v14 >= *(unsigned int *)(*a1 + 28) )
      goto LABEL_56;
  }
  v18 = *((unsigned int *)a1 + 10);
  v16 = v18 + 1;
  if ( (unsigned int)(v18 + 1) >= *((_DWORD *)a1 + 6) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_sfe_add_command_buffers",
      570,
      "Insufficient  HW entries :%d %d",
      (unsigned int)v18);
    goto LABEL_51;
  }
  updated = cam_packet_util_validate_cmd_desc(v15);
  if ( updated )
    goto LABEL_49;
  v19 = v15[5];
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    v20 = (unsigned int)v19 >= 0xA;
    if ( v19 > 10 )
      goto LABEL_16;
    goto LABEL_5;
  }
  v34 = v15[5];
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_sfe_add_command_buffers",
    581,
    "meta type: %d, split_id: %d",
    v19,
    v11);
  v19 = v34;
  v20 = (unsigned int)v34 >= 0xA;
  if ( v34 <= 10 )
  {
LABEL_5:
    if ( !v20 )
      goto LABEL_6;
    if ( v19 == 10 )
    {
      v16 = v18;
      if ( !v11 )
      {
        v51 = a1;
        v52 = a3;
        v53 = v48;
        v54 = 0;
        v26 = cam_packet_util_process_generic_cmd_buffer(v15, v49, (__int64)&v51);
        if ( v26 )
        {
          v35 = v26;
          v36 = 650;
          goto LABEL_54;
        }
        goto LABEL_46;
      }
      goto LABEL_7;
    }
LABEL_52:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_sfe_add_command_buffers",
      717,
      "invalid cdm command meta data %d",
      v19);
LABEL_51:
    v35 = -22;
    goto LABEL_57;
  }
LABEL_16:
  if ( v19 > 20 )
  {
    if ( v19 > 22 )
    {
      if ( v19 != 23 )
      {
        if ( v19 != 24 )
          goto LABEL_52;
        updated = cam_isp_update_dual_config(v15, *a3, v41, v43, v40, v45);
        v16 = v18;
        if ( updated )
          goto LABEL_49;
        goto LABEL_7;
      }
      v30 = v15[3];
      v23 = (_DWORD *)(v47 + 32 * v18);
      v23[2] = v30;
      v31 = (unsigned int)*v15;
      *v23 = v31;
      v32 = v15[1];
      v23[1] = v32;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int, int))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_sfe_add_command_buffers",
          623,
          "Meta_Common num_ent=%d handle=0x%x, len=%u, offset=%u",
          (unsigned int)v18,
          v31,
          v30,
          v32);
    }
    else if ( v19 == 21 )
    {
      if ( v11 )
        goto LABEL_6;
      v27 = v15[3];
      v23 = (_DWORD *)(v47 + 32 * v18);
      v23[2] = v27;
      v28 = (unsigned int)*v15;
      *v23 = v28;
      v29 = v15[1];
      v23[1] = v29;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int, int))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_sfe_add_command_buffers",
          594,
          "Meta_Left num_ent=%d handle=0x%x, len=%u, offset=%u",
          (unsigned int)v18,
          v28,
          v27,
          v29);
    }
    else
    {
      if ( v11 != 1 )
        goto LABEL_6;
      v22 = v15[3];
      v23 = (_DWORD *)(v47 + 32 * v18);
      v23[2] = v22;
      v24 = (unsigned int)*v15;
      *v23 = v24;
      v25 = v15[1];
      v23[1] = v25;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int, int))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_sfe_add_command_buffers",
          609,
          "Meta_Right num_ent=%d handle=0x%x, len=%u, offset=%u",
          (unsigned int)v18,
          v24,
          v22,
          v25);
    }
    v23[3] = 2;
    goto LABEL_7;
  }
  if ( (unsigned int)(v19 - 13) < 6 )
  {
LABEL_6:
    v16 = v18;
    goto LABEL_7;
  }
  if ( v19 != 11 )
  {
    if ( v19 != 12 )
      goto LABEL_52;
    v51 = a1;
    v52 = a3;
    v53 = v48;
    v54 = 0;
    v21 = cam_packet_util_process_generic_cmd_buffer(v15, v49, (__int64)&v51);
    if ( v21 )
    {
      v35 = v21;
      v36 = 692;
      goto LABEL_54;
    }
    goto LABEL_46;
  }
  v16 = v18;
  if ( v11 != 1 )
  {
LABEL_7:
    *((_DWORD *)a1 + 10) = v16;
    goto LABEL_8;
  }
  v51 = a1;
  v52 = a3;
  v53 = v48;
  v54 = 0;
  v33 = cam_packet_util_process_generic_cmd_buffer(v15, v49, (__int64)&v51);
  if ( !v33 )
  {
LABEL_46:
    v16 = *((_DWORD *)a1 + 10);
    goto LABEL_7;
  }
  v35 = v33;
  v36 = 672;
LABEL_54:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    8,
    1,
    "cam_sfe_add_command_buffers",
    v36,
    "Failed in processing blobs %d",
    v35);
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return v35;
}
