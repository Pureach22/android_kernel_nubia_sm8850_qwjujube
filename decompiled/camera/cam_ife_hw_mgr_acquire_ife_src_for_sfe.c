__int64 __fastcall cam_ife_hw_mgr_acquire_ife_src_for_sfe(__int64 a1, __int64 a2, _DWORD *a3, _DWORD *a4)
{
  __int64 v4; // x25
  __int64 v5; // x26
  unsigned int v7; // w6
  unsigned int v8; // w7
  __int64 result; // x0
  __int64 v10; // x9
  _QWORD *v11; // x20
  __int64 v12; // x21
  _QWORD *v13; // x8
  __int64 v16; // x10
  char v17; // w10
  char v18; // w8
  __int64 v19; // x11
  __int64 v20; // x8
  int v21; // w10
  int v22; // w8
  int v23; // w10
  __int64 v24; // x8
  unsigned int (__fastcall *v25)(__int64, __int64 *, __int64); // x8
  __int64 v26; // x0
  _DWORD *v27; // x8
  __int64 v28; // x2
  _QWORD *v29; // x1
  __int64 v30; // x6
  _DWORD *v31; // x9
  int v32; // w10
  _QWORD *v33; // x1
  __int64 v34; // x8
  int v35; // w8
  __int64 v36; // x8
  int v37; // w9
  __int64 v38; // x24
  unsigned int (__fastcall *v39)(__int64, __int64 *, __int64); // x8
  __int64 v40; // x0
  int v41; // w8
  __int64 v42; // x10
  __int64 v43; // [xsp+18h] [xbp-78h] BYREF
  __int64 v44; // [xsp+20h] [xbp-70h]
  __int64 v45; // [xsp+28h] [xbp-68h]
  __int64 (__fastcall *v46)(__int64, unsigned int, _DWORD *); // [xsp+30h] [xbp-60h]
  __int64 v47; // [xsp+38h] [xbp-58h]
  __int64 v48; // [xsp+40h] [xbp-50h]
  __int64 v49; // [xsp+48h] [xbp-48h]
  __int64 v50; // [xsp+50h] [xbp-40h]
  __int64 v51; // [xsp+58h] [xbp-38h]
  __int64 v52; // [xsp+60h] [xbp-30h]
  __int64 v53; // [xsp+68h] [xbp-28h]
  __int64 v54; // [xsp+70h] [xbp-20h]
  __int64 v55; // [xsp+78h] [xbp-18h]
  __int64 v56; // [xsp+80h] [xbp-10h]
  __int64 v57; // [xsp+88h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_DWORD *)(a1 + 60);
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = nullptr;
  v43 = 0;
  v44 = 0;
  if ( v7 >= 3 )
  {
    v8 = *(_DWORD *)(a1 + 64);
LABEL_3:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_ife_src_for_sfe",
      4039,
      "the hw index:[%d - %d] is wrong",
      v7,
      v8);
LABEL_4:
    result = 0xFFFFFFFFLL;
    goto LABEL_5;
  }
  if ( *(_BYTE *)(a1 + 9379) == 1 )
  {
    v8 = *(_DWORD *)(a1 + 64);
    if ( v8 >= 3 )
      goto LABEL_3;
  }
  v10 = *(_QWORD *)(a1 + 72);
  v11 = *(_QWORD **)(a1 + 288);
  v12 = a1 + 288;
  if ( v11 == (_QWORD *)(a1 + 288) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_get_res",
      2078,
      "No more free ife hw mgr ctx");
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_ife_src_for_sfe",
      4048,
      "No more free hw mgr resource, ctx_idx: %u",
      *(_DWORD *)(a1 + 56));
    goto LABEL_4;
  }
  v13 = (_QWORD *)v11[1];
  if ( (_QWORD *)*v13 == v11 && (v16 = *v11, *(_QWORD **)(*v11 + 8LL) == v11) )
  {
    *(_QWORD *)(v16 + 8) = v13;
    *v13 = v16;
  }
  else
  {
    _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 288));
    a2 = v42;
  }
  *v11 = v11;
  v11[1] = v11;
  v17 = *(_BYTE *)(a1 + 9380);
  LODWORD(v43) = 4;
  v18 = *(_BYTE *)(a1 + 9378);
  v19 = *(_QWORD *)(a1 + 16);
  v54 = a2;
  BYTE1(v55) = v17;
  LOBYTE(v55) = v18;
  v20 = *(_QWORD *)(a1 + 8728);
  v21 = *(unsigned __int8 *)(v10 + 81883);
  v44 = v19;
  v45 = a1;
  v52 = v20;
  v46 = cam_ife_hw_mgr_event_handler;
  BYTE2(v55) = 1;
  if ( v21 == 1 )
    BYTE2(v55) = *(_DWORD *)(a1 + 9312) == 2;
  v22 = *(unsigned __int8 *)(a1 + 9379);
  v23 = 0;
  LODWORD(v50) = 0;
  if ( v22 == 1 )
  {
    HIDWORD(v50) = *(_DWORD *)(a1 + 64);
    v23 = 1;
  }
  LODWORD(v53) = v23;
  LODWORD(v51) = v22;
  *((_DWORD *)v11 + 4) = 4;
  *((_DWORD *)v11 + 5) = v50;
  *((_DWORD *)v11 + 6) = *(unsigned __int8 *)(a1 + 9379);
  v24 = *(unsigned int *)(a1 + 60);
  if ( (unsigned int)v24 >= 8 )
    goto LABEL_58;
  v4 = v10 + 160;
  v5 = **(_QWORD **)(v10 + 160 + 8 * v24);
  v25 = *(unsigned int (__fastcall **)(__int64, __int64 *, __int64))(v5 + 40);
  v26 = *(_QWORD *)(v5 + 112);
  if ( *((_DWORD *)v25 - 1) != 1989616049 )
    __break(0x8228u);
  if ( v25(v26, &v43, 112) || !v49 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_ife_src_for_sfe",
      4095,
      "Unable to acquire LEFT IFE res: %d ctx_idx: %u",
      v50,
      *(_DWORD *)(a1 + 56));
    if ( !v11 )
    {
LABEL_56:
      result = 4294967274LL;
      goto LABEL_5;
    }
LABEL_31:
    v33 = *(_QWORD **)(a1 + 296);
    if ( v33 == v11 || *v33 != v12 )
    {
      _list_add_valid_or_report(v11);
      result = 4294967274LL;
    }
    else
    {
      result = 4294967274LL;
      *(_QWORD *)(a1 + 296) = v11;
      *v11 = v12;
      v11[1] = v33;
      *v33 = v11;
    }
    goto LABEL_5;
  }
  v11[4] = v49;
  v27 = a3;
  if ( v11 )
  {
    v28 = a1 + 224;
    v29 = *(_QWORD **)(a1 + 232);
    if ( v11 == (_QWORD *)(a1 + 224) || v29 == v11 || *v29 != v28 )
      goto LABEL_59;
    *(_QWORD *)(a1 + 232) = v11;
    *v11 = v28;
    v11[1] = v29;
    *v29 = v11;
  }
  while ( 1 )
  {
    v30 = *(unsigned int *)(v5 + 4);
    v31 = a4;
    if ( (unsigned int)v30 >= g_num_ife_available )
    {
      if ( g_num_ife_lite_available + g_num_ife_available <= (unsigned int)v30 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_convert_hw_idx_to_ife_hw_num",
          3449,
          "hw idx %d out-of-bounds",
          v30);
        v27 = a3;
        v31 = a4;
      }
      else if ( (unsigned int)(v30 - g_num_ife_available) < 5 )
      {
        v32 = dword_4514F0[(unsigned int)(v30 - g_num_ife_available)];
        goto LABEL_39;
      }
    }
    else if ( (unsigned int)v30 < 3 )
    {
      v32 = dword_4514E4[v30];
      goto LABEL_39;
    }
    v32 = 0;
LABEL_39:
    *v27 |= v32;
    v34 = *(unsigned int *)(v11[4] + 4LL);
    if ( (unsigned int)v34 > 9 )
      v35 = 0;
    else
      v35 = dword_4514BC[v34];
    *v31 |= v35;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_acquire_ife_src_for_sfe",
        4113,
        "acquire success LEFT IFE: %d res type: 0x%x res: %s res id: 0x%x ctx_idx: %u",
        *(_DWORD *)(v5 + 4),
        *(_DWORD *)v11[4],
        (const char *)(v11[4] + 128LL),
        *(_DWORD *)(v11[4] + 4LL),
        *(_DWORD *)(a1 + 56));
    if ( *(_BYTE *)(a1 + 9379) != 1 )
      goto LABEL_54;
    v37 = *(_DWORD *)(a1 + 60);
    v36 = *(unsigned int *)(a1 + 64);
    v49 = 0;
    LODWORD(v53) = 2;
    HIDWORD(v50) = v37;
    if ( (unsigned int)v36 <= 7 )
      break;
LABEL_58:
    __break(0x5512u);
LABEL_59:
    _list_add_valid_or_report(v11);
    v27 = a3;
  }
  v38 = **(_QWORD **)(v4 + 8 * v36);
  v39 = *(unsigned int (__fastcall **)(__int64, __int64 *, __int64))(v38 + 40);
  v40 = *(_QWORD *)(v38 + 112);
  if ( *((_DWORD *)v39 - 1) != 1989616049 )
    __break(0x8228u);
  if ( v39(v40, &v43, 112) || !v49 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_ife_src_for_sfe",
      4129,
      "Unable to acquire right IFE res: %u, ctx_idx: %u",
      v50,
      *(_DWORD *)(a1 + 56));
    if ( !v11 )
      goto LABEL_56;
    goto LABEL_31;
  }
  v11[5] = v49;
  *a3 |= cam_convert_hw_idx_to_ife_hw_num(*(_DWORD *)(v38 + 4));
  v41 = a4[1] | cam_convert_res_id_to_hw_path(*(_DWORD *)(v11[5] + 4LL), -1);
  result = 0;
  a4[1] = v41;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_acquire_ife_src_for_sfe",
      4144,
      "acquire success RIGHT IFE: %u res type: 0x%x res: %s res id: 0x%x ctx_idx: %u",
      *(_DWORD *)(v38 + 4),
      *(_DWORD *)v11[5],
      (const char *)(v11[5] + 128LL),
      *(_DWORD *)(v11[5] + 4LL),
      *(_DWORD *)(a1 + 56));
LABEL_54:
    result = 0;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
