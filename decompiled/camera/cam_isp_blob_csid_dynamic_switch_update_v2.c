__int64 __fastcall cam_isp_blob_csid_dynamic_switch_update_v2(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x23
  __int64 v5; // x25
  __int64 v6; // x7
  const char *v7; // x5
  __int64 v8; // x6
  __int64 v9; // x4
  __int64 v12; // x22
  int v13; // w9
  int v14; // w8
  int v15; // w9
  int v16; // w6
  int v17; // w10
  __int64 v18; // x9
  unsigned int v19; // w8
  int v20; // w9
  __int64 result; // x0
  int v22; // w10
  __int64 v23; // x11
  int v24; // w9
  __int64 v25; // x27
  __int64 v26; // x26
  unsigned int *v27; // x8
  __int64 v28; // x8
  __int64 v29; // x9
  _DWORD *v30; // x8
  __int64 v31; // x0
  unsigned int v32; // w0
  unsigned int v33; // w22
  char v34; // w4
  _QWORD v35[2]; // [xsp+18h] [xbp-38h] BYREF
  __int64 v36; // [xsp+28h] [xbp-28h]
  __int64 v37; // [xsp+30h] [xbp-20h]
  unsigned __int64 v38; // [xsp+38h] [xbp-18h]
  __int64 v39; // [xsp+40h] [xbp-10h]
  __int64 v40; // [xsp+48h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a3 + 320);
  v38 = 0;
  v39 = 0;
  v5 = *(_QWORD *)(a3 + 16);
  v36 = 0;
  v37 = 0;
  v35[0] = 0;
  v35[1] = 0;
  if ( *(_BYTE *)(v4 + 4288) == 1 )
  {
    v6 = *(unsigned int *)(v5 + 56);
    v7 = "MUP is already updated for Req: %lld on ctx: %u";
    v8 = *(_QWORD *)(*(_QWORD *)a3 + 8LL);
    v9 = 10933;
LABEL_27:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_csid_dynamic_switch_update_v2",
      v9,
      v7,
      v8,
      v6);
LABEL_28:
    result = 4294967274LL;
    goto LABEL_29;
  }
  v12 = *(_QWORD *)(v5 + 72);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_isp_blob_csid_dynamic_switch_update_v2",
    10940,
    "csid mup value=%u, ctx_idx: %u req id %lld num_dt_path: %u",
    *(_DWORD *)(a2 + 4),
    *(_DWORD *)(v5 + 56),
    *(_QWORD *)(*(_QWORD *)a3 + 8LL),
    *(_DWORD *)(a2 + 12));
  *(_BYTE *)(v4 + 4288) = 1;
  v13 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(v4 + 4280) = v13;
  if ( *(_DWORD *)(v12 + 80972) >= 2u )
  {
    *(_DWORD *)(v4 + 4280) = (v13 & 1) == 0;
    v13 = *(_DWORD *)(a2 + 4);
  }
  if ( *(_DWORD *)(v4 + 8) == 1 )
  {
    LODWORD(v35[0]) = v13;
    BYTE4(v35[0]) = 1;
  }
  v14 = *(_DWORD *)(a2 + 12);
  LODWORD(v39) = v13;
  BYTE4(v39) = 1;
  if ( !v14 )
    goto LABEL_44;
  if ( ((*(_BYTE *)(v5 + 9385) & 1) != 0 || *(_BYTE *)(v5 + 9399) == 1)
    && (v15 = *(_DWORD *)(v5 + 9532), v15 < (unsigned int)dword_3A85A4) )
  {
    if ( v15 <= 12295 )
    {
      if ( v15 == 12294 )
      {
        v16 = 8;
      }
      else
      {
        if ( v15 != 12295 )
          goto LABEL_26;
        v16 = 16;
      }
    }
    else
    {
      switch ( v15 )
      {
        case 12296:
          v16 = 32;
          break;
        case 12297:
          v16 = 64;
          break;
        case 12327:
          v16 = 128;
          break;
        default:
LABEL_26:
          v6 = *(unsigned int *)(v5 + 9312);
          v7 = "Failed to process dt info for req: %lld ctx: %u";
          v8 = *(_QWORD *)(*(_QWORD *)a3 + 8LL);
          v9 = 10965;
          goto LABEL_27;
      }
    }
  }
  else
  {
    v16 = 1;
  }
  v17 = 0;
  v18 = a2 + 40;
  while ( *(_DWORD *)(v18 + 32LL * v17) != v16 )
  {
    if ( v14 == ++v17 )
      goto LABEL_25;
  }
  v19 = *(_DWORD *)(v18 + 32LL * v17 + 4);
  if ( !v19 )
  {
LABEL_25:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_csid_dynamic_switch_process_dt_info",
      10890,
      "No DT info provided for path: %u");
    goto LABEL_26;
  }
  if ( v16 > 31 )
  {
    if ( v16 == 32 )
    {
      v20 = 2;
    }
    else if ( v16 == 64 )
    {
      v20 = 3;
    }
    else
    {
      v20 = 4;
    }
  }
  else if ( v16 == 1 )
  {
    v20 = 5;
  }
  else
  {
    v20 = v16 != 8;
  }
  if ( *(_DWORD *)(v5 + 9988) != v19 )
  {
    v22 = *(_DWORD *)(v4 + 4272);
    v23 = *(_QWORD *)(v4 + 4256);
    v38 = __PAIR64__(v20, v19);
    v24 = *(_DWORD *)(v4 + 4268);
    BYTE4(v39) = 0;
    v36 = v23 + (v22 & 0xFFFFFFFC);
    v37 = (unsigned int)(v24 - v22);
  }
LABEL_44:
  if ( !*(_DWORD *)(v5 + 8716) )
    goto LABEL_28;
  v25 = 0;
  result = 4294967274LL;
  v26 = *(_QWORD *)(v5 + 72) + 96LL;
  do
  {
    while ( 1 )
    {
      v27 = (unsigned int *)(v5 + 8584 + 12 * v25);
      if ( v27[2] || v27[1] )
        break;
      v28 = *v27;
      if ( (unsigned int)v28 > 7 )
        goto LABEL_60;
      v29 = *(_QWORD *)(v26 + 8 * v28);
      if ( !v29 )
        break;
      v30 = *(_DWORD **)(v29 + 88);
      if ( !v30 )
        break;
      v31 = *(_QWORD *)(v29 + 112);
      if ( *(v30 - 1) != -1055839300 )
        __break(0x8228u);
      v32 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v30)(v31, 54, v35, 48);
      if ( v32 )
      {
        v33 = v32;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_update_csid_mode_update_util",
          10786,
          "Dynamic switch update failed, ctx_idx: %u",
          *(_DWORD *)(v5 + 56));
        result = v33;
        break;
      }
      if ( ++v25 >= (unsigned __int64)*(unsigned int *)(v5 + 8716) )
        goto LABEL_62;
      result = 0;
      if ( v25 == 11 )
        goto LABEL_60;
    }
    if ( ++v25 >= (unsigned __int64)*(unsigned int *)(v5 + 8716) )
      goto LABEL_61;
  }
  while ( v25 != 11 );
LABEL_60:
  __break(0x5512u);
LABEL_61:
  if ( (_DWORD)result )
    goto LABEL_29;
LABEL_62:
  if ( HIDWORD(v37) )
  {
    v34 = *(_BYTE *)(a1 + 24) == 1
       && *(_DWORD *)(*(_QWORD *)(a3 + 32) + 32LL * (unsigned int)(*(_DWORD *)(a3 + 40) - 1) + 12) == 5;
    cam_isp_update_hw_entry(5, a3, v4 + 4248, SHIDWORD(v37), v34);
    result = 0;
    *(_BYTE *)(a1 + 24) = 1;
    *(_BYTE *)(v4 + 4289) = 1;
    *(_DWORD *)(v4 + 4292) = v38;
  }
  else
  {
    result = 0;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
