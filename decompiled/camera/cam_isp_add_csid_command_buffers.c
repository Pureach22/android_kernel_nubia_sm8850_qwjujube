__int64 __fastcall cam_isp_add_csid_command_buffers(__int64 *a1, __int64 a2, _DWORD *a3, __int64 a4)
{
  __int64 v6; // x24
  int v7; // w23
  __int64 v8; // x25
  unsigned __int64 v9; // x21
  int *v10; // x27
  int v11; // w24
  unsigned int v12; // w0
  __int64 v13; // x25
  int v14; // w6
  unsigned int v15; // w0
  unsigned int v16; // w0
  int v17; // w8
  _DWORD *v18; // x26
  __int64 v19; // x7
  int v20; // w10
  unsigned int v21; // w0
  int v22; // w26
  int v23; // w8
  __int64 v24; // x7
  int v25; // w10
  int v26; // w8
  __int64 v27; // x7
  int v28; // w10
  unsigned int v29; // w26
  __int64 v30; // x4
  __int64 v31; // x26
  _DWORD *v32; // x21
  __int64 v34; // [xsp+10h] [xbp-40h]
  _DWORD *v35; // [xsp+18h] [xbp-38h]
  __int64 v36; // [xsp+20h] [xbp-30h]
  __int64 *v37; // [xsp+28h] [xbp-28h] BYREF
  __int64 v38; // [xsp+30h] [xbp-20h]
  __int64 v39; // [xsp+38h] [xbp-18h]
  __int64 v40; // [xsp+40h] [xbp-10h]
  __int64 v41; // [xsp+48h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a1;
  v7 = *(_DWORD *)(a4 + 4);
  v8 = *(unsigned int *)(*a1 + 24);
  v36 = a1[4];
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v31 = a2;
    v32 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_add_csid_command_buffers",
      1698,
      "split id = %d, number of command buffers:%d",
      v7,
      *(_DWORD *)(v6 + 28));
    a2 = v31;
    a3 = v32;
    if ( *(_DWORD *)(*a1 + 28) )
      goto LABEL_4;
LABEL_56:
    v29 = 0;
    goto LABEL_57;
  }
  if ( !*(_DWORD *)(v6 + 28) )
    goto LABEL_56;
LABEL_4:
  v9 = 0;
  v34 = a2;
  v35 = a3;
  v10 = (int *)(v6 + v8 + 56);
  while ( 1 )
  {
    v12 = cam_packet_util_validate_cmd_desc(v10);
    if ( v12 )
    {
LABEL_49:
      v29 = v12;
      goto LABEL_57;
    }
    if ( v10[3] )
      break;
LABEL_8:
    ++v9;
    v10 += 6;
    if ( v9 >= *(unsigned int *)(*a1 + 28) )
      goto LABEL_56;
  }
  v13 = *((unsigned int *)a1 + 10);
  v11 = v13 + 1;
  if ( (unsigned int)(v13 + 1) >= *((_DWORD *)a1 + 6) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_add_csid_command_buffers",
      1712,
      "Insufficient  HW entries :%d %d",
      (unsigned int)v13);
LABEL_51:
    v29 = -22;
    goto LABEL_57;
  }
  v12 = cam_packet_util_validate_cmd_desc(v10);
  if ( v12 )
    goto LABEL_49;
  v14 = v10[5];
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    if ( v14 <= 12 )
      goto LABEL_16;
LABEL_36:
    if ( v14 > 17 )
    {
      if ( (unsigned int)(v14 - 21) < 4 )
        goto LABEL_6;
      if ( v14 != 18 )
        goto LABEL_52;
      v17 = v10[3];
      v18 = (_DWORD *)(v36 + 32 * v13);
      v18[2] = v17;
      v19 = (unsigned int)*v10;
      *v18 = v19;
      v20 = v10[1];
      v18[1] = v20;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int, int))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_isp_add_csid_command_buffers",
          1849,
          "Meta_Common num_ent=%d handle=0x%x, len=%u, offset=%u",
          (unsigned int)v13,
          v19,
          v17,
          v20);
    }
    else
    {
      if ( (unsigned int)(v14 - 13) < 3 )
        goto LABEL_6;
      if ( v14 == 16 )
      {
        if ( v7 )
          goto LABEL_6;
        v26 = v10[3];
        v18 = (_DWORD *)(v36 + 32 * v13);
        v18[2] = v26;
        v27 = (unsigned int)*v10;
        *v18 = v27;
        v28 = v10[1];
        v18[1] = v28;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int, int))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_isp_add_csid_command_buffers",
            1820,
            "Meta_Left num_ent=%d handle=0x%x, len=%u, offset=%u",
            (unsigned int)v13,
            v27,
            v26,
            v28);
      }
      else
      {
        if ( v14 != 17 )
        {
LABEL_52:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_add_csid_command_buffers",
            1855,
            "invalid cdm command meta data %d",
            v14);
          goto LABEL_51;
        }
        if ( v7 != 1 )
          goto LABEL_6;
        v23 = v10[3];
        v18 = (_DWORD *)(v36 + 32 * v13);
        v18[2] = v23;
        v24 = (unsigned int)*v10;
        *v18 = v24;
        v25 = v10[1];
        v18[1] = v25;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int, int))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_isp_add_csid_command_buffers",
            1835,
            "Meta_Right num_ent=%d handle=0x%x, len=%u, offset=%u",
            (unsigned int)v13,
            v24,
            v23,
            v25);
      }
    }
    v18[3] = 2;
    goto LABEL_7;
  }
  v22 = v10[5];
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_isp_add_csid_command_buffers",
    1723,
    "meta type: %d, split_id: %d",
    v14,
    v7);
  v14 = v22;
  if ( v22 > 12 )
    goto LABEL_36;
LABEL_16:
  if ( v14 <= 8 )
  {
    v11 = v13;
    if ( (unsigned int)v14 >= 7 )
      goto LABEL_52;
    goto LABEL_7;
  }
  if ( v14 <= 10 )
  {
    if ( v14 != 9 && !v7 )
    {
      *((_DWORD *)a1 + 10) = v13;
      v37 = a1;
      v38 = a4;
      v39 = v34;
      v40 = 0;
      v15 = cam_packet_util_process_generic_cmd_buffer(v10, v35, (__int64)&v37);
      if ( v15 )
      {
        v29 = v15;
        v30 = 1751;
        goto LABEL_54;
      }
      goto LABEL_34;
    }
LABEL_6:
    v11 = v13;
LABEL_7:
    *((_DWORD *)a1 + 10) = v11;
    goto LABEL_8;
  }
  if ( v14 != 11 )
  {
    if ( v14 != 12 )
      goto LABEL_52;
    *((_DWORD *)a1 + 10) = v13;
    v37 = a1;
    v38 = a4;
    v39 = v34;
    v40 = 0;
    v16 = cam_packet_util_process_generic_cmd_buffer(v10, v35, (__int64)&v37);
    if ( v16 )
    {
      v29 = v16;
      v30 = 1795;
      goto LABEL_54;
    }
    goto LABEL_34;
  }
  if ( v7 != 1 )
    goto LABEL_6;
  *((_DWORD *)a1 + 10) = v13;
  v37 = a1;
  v38 = a4;
  v39 = v34;
  v40 = 0;
  v21 = cam_packet_util_process_generic_cmd_buffer(v10, v35, (__int64)&v37);
  if ( !v21 )
  {
LABEL_34:
    *(_DWORD *)(v36 + 32 * v13 + 12) = 2;
    v11 = *((_DWORD *)a1 + 10);
    goto LABEL_7;
  }
  v29 = v21;
  v30 = 1774;
LABEL_54:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_add_csid_command_buffers",
    v30,
    "Failed in processing blobs %d",
    v29);
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return v29;
}
