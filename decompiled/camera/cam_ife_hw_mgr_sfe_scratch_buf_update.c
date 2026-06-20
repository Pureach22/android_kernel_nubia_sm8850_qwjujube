__int64 __fastcall cam_ife_hw_mgr_sfe_scratch_buf_update(
        int a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  unsigned int v6; // w19
  __int64 v7; // x22
  unsigned __int64 v8; // x27
  int v9; // w7
  __int64 v10; // x8
  int v11; // w6
  __int64 result; // x0
  int v13; // w6
  unsigned int v14; // w7
  _QWORD *v15; // x11
  __int64 v16; // x24
  int v17; // w20
  __int64 v18; // x8
  __int64 v19; // x26
  unsigned int v20; // w9
  int v21; // w25
  int v22; // w0
  int v23; // w6
  unsigned int v24; // w7
  unsigned __int64 v25; // x21
  __int64 v26; // x27
  __int64 v27; // x28
  __int64 *v28; // x26
  __int64 v29; // t1
  unsigned int v30; // w9
  int v31; // w23
  int v32; // w0
  unsigned int v33; // w7
  __int64 v34; // x25
  __int64 v35; // x27
  __int64 v36; // x21
  int v37; // w28
  _QWORD *v38; // x24
  unsigned int v39; // w9
  int v40; // w23
  int v41; // w0
  int v42; // w6
  unsigned int v43; // w7
  __int64 v44; // x26
  __int64 v45; // x21
  __int64 v46; // x25
  unsigned int v47; // w9
  int v48; // w23
  int v49; // w0
  int v50; // w6
  unsigned int v51; // w7
  __int64 v52; // x26
  __int64 v53; // x21
  __int64 v54; // x25
  int v55; // w27
  int v56; // w27
  __int64 v57; // x7
  __int64 v58; // x4
  __int64 v59; // x20
  __int64 v60; // x21
  __int64 v61; // x20
  unsigned __int64 v62; // [xsp+18h] [xbp-38h]
  int v63; // [xsp+18h] [xbp-38h]
  unsigned __int64 v64; // [xsp+18h] [xbp-38h]
  unsigned __int64 v65; // [xsp+18h] [xbp-38h]
  __int64 v66; // [xsp+20h] [xbp-30h]
  _QWORD *v67; // [xsp+28h] [xbp-28h]
  __int64 v68; // [xsp+30h] [xbp-20h]
  __int64 v69; // [xsp+38h] [xbp-18h]
  int v70; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v71; // [xsp+48h] [xbp-8h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_DWORD *)(a6 + 4);
  LODWORD(v10) = -1 << *(_DWORD *)(a5 + 9352);
  v11 = ~(_DWORD)v10;
  if ( v9 == ~(_DWORD)v10 )
  {
    if ( a1 == 1 )
    {
      result = 0;
      *(_BYTE *)(*(_QWORD *)(a5 + 9360) + 136LL) = 1;
      goto LABEL_83;
    }
LABEL_82:
    result = 0;
    goto LABEL_83;
  }
  if ( a1 == 1 )
  {
    result = 0;
    *(_DWORD *)(*(_QWORD *)(a5 + 9360) + 4LL) = v9;
    goto LABEL_83;
  }
  if ( a1 != 2 )
    goto LABEL_82;
  v68 = a4;
  v69 = a5;
  if ( (debug_mdl & 8) == 0 || (LOBYTE(v10) = debug_priority, debug_priority) )
  {
    if ( a2 < 0xB )
      goto LABEL_9;
LABEL_89:
    __break(0x5512u);
LABEL_90:
    v61 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v10 & 8,
      4,
      "cam_isp_sfe_add_scratch_buffer_cfg",
      14621,
      "ctx_idx: %u num_ports: %u",
      *(_DWORD *)(a5 + 56),
      **(_DWORD **)(a5 + 9360));
    a4 = v68;
    a5 = v69;
    a3 = v61;
    v15 = v67;
    goto LABEL_12;
  }
  v6 = a2;
  v59 = a3;
  v60 = a6;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_ife_hw_mgr_sfe_scratch_buf_update",
    15327,
    "Adding SFE scratch buffer cfg_mask expected: 0x%x actual: 0x%x ctx_idx: %u",
    v11,
    v9,
    *(_DWORD *)(a5 + 56));
  a4 = v68;
  a5 = v69;
  a2 = v6;
  a6 = v60;
  a3 = v59;
  if ( v6 >= 0xB )
    goto LABEL_89;
LABEL_9:
  v13 = *(_DWORD *)(a4 + 40);
  v14 = *(_DWORD *)(a4 + 24);
  v8 = *(unsigned int *)(a6 + 4);
  v7 = *(_QWORD *)(a5 + 280);
  v70 = 0;
  v6 = *(_DWORD *)(a5 + 12LL * a2 + 8584);
  if ( v13 + 1 >= v14 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_sfe_add_scratch_buffer_cfg",
      14615,
      "Insufficient  HW entries :%d %d, ctx_idx: %u",
      v13,
      v14,
      *(_DWORD *)(a5 + 56));
    result = 4294967274LL;
    goto LABEL_83;
  }
  LOBYTE(v10) = debug_mdl;
  v15 = (_QWORD *)(a5 + 256);
  v67 = (_QWORD *)(a5 + 256);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    goto LABEL_90;
LABEL_12:
  v16 = 0;
  v17 = 0;
  do
  {
    v18 = *(unsigned __int8 *)(*(_QWORD *)(a5 + 8504) + v16);
    if ( v18 != 255 )
    {
      v19 = v7 + (v18 << 7);
      v10 = *(_QWORD *)(v19 + 32);
      if ( v10 && *(_DWORD *)(*(_QWORD *)(v10 + 16) + 4LL) == v6 )
      {
        v20 = *(_DWORD *)(a3 + 20);
        v21 = *(_DWORD *)(a3 + 24);
        v22 = v20 - (v21 + v17);
        if ( v20 <= v21 + v17 )
          goto LABEL_84;
        v23 = *(_DWORD *)(v10 + 4);
        v24 = v23 - 24576;
        if ( *(_DWORD *)(a5 + 9352) > (unsigned int)(v23 - 24576)
          && (*(_BYTE *)(a5 + 9387) != 1
           || (*(_BYTE *)(a5 + 9316) & 4) == 0
           || *(_DWORD *)(*(_QWORD *)(a5 + 9360) + 8LL) > v24)
          && ((v8 >> v23) & 1) == 0 )
        {
          if ( v24 > 3 )
            goto LABEL_89;
          v25 = v8;
          v26 = *(_QWORD *)(a5 + 9360) + 40LL * v24;
          if ( (*(_BYTE *)(v26 + 48) & 1) == 0 )
            goto LABEL_87;
          v27 = *(_QWORD *)(a3 + 8);
          v66 = a3;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            v63 = v20 - (v21 + v17);
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_isp_sfe_add_scratch_buffer_cfg",
              14676,
              "WM res_id: 0x%x idx: %u io_addr: %pK, ctx_idx: %u",
              v23,
              v24,
              *(const void **)(v26 + 32),
              *(_DWORD *)(v69 + 56));
            v22 = v63;
            v10 = *(_QWORD *)(v19 + 32);
          }
          result = cam_isp_sfe_send_scratch_buf_upd(
                     v22,
                     1,
                     v10,
                     v26 + 16,
                     v27 + (v17 & 0xFFFFFFFC) + (v21 & 0xFFFFFFFC),
                     &v70);
          if ( (_DWORD)result )
            goto LABEL_83;
          a4 = v68;
          a5 = v69;
          a3 = v66;
          v15 = v67;
          v17 += v70;
          v8 = v25;
        }
      }
      v29 = *(_QWORD *)(v19 + 40);
      v28 = (__int64 *)(v19 + 40);
      v10 = v29;
      if ( v29 && *(_DWORD *)(*(_QWORD *)(v10 + 16) + 4LL) == v6 )
      {
        v30 = *(_DWORD *)(a3 + 20);
        v31 = *(_DWORD *)(a3 + 24);
        v32 = v30 - (v31 + v17);
        if ( v30 <= v31 + v17 )
        {
LABEL_84:
          v57 = *(unsigned int *)(a5 + 56);
          v58 = 14644;
          goto LABEL_86;
        }
        v23 = *(_DWORD *)(v10 + 4);
        v33 = v23 - 24576;
        if ( *(_DWORD *)(a5 + 9352) > (unsigned int)(v23 - 24576)
          && (*(_BYTE *)(a5 + 9387) != 1
           || (*(_BYTE *)(a5 + 9316) & 4) == 0
           || *(_DWORD *)(*(_QWORD *)(a5 + 9360) + 8LL) > v33)
          && ((v8 >> v23) & 1) == 0 )
        {
          if ( v33 > 3 )
            goto LABEL_89;
          v34 = *(_QWORD *)(a5 + 9360) + 40LL * v33;
          if ( *(_BYTE *)(v34 + 48) != 1 )
          {
LABEL_87:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_isp_sfe_add_scratch_buffer_cfg",
              14669,
              "No scratch buffer config found for res: %u on ctx: %u",
              v23,
              *(_DWORD *)(a5 + 56));
            result = 4294967282LL;
            goto LABEL_83;
          }
          v62 = v8;
          v35 = *(_QWORD *)(a3 + 8);
          v36 = a3;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            v37 = v30 - (v31 + v17);
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_isp_sfe_add_scratch_buffer_cfg",
              14676,
              "WM res_id: 0x%x idx: %u io_addr: %pK, ctx_idx: %u",
              v23,
              v33,
              *(const void **)(v34 + 32),
              *(_DWORD *)(v69 + 56));
            v10 = *v28;
            v32 = v37;
          }
          result = cam_isp_sfe_send_scratch_buf_upd(
                     v32,
                     1,
                     v10,
                     v34 + 16,
                     v35 + (v17 & 0xFFFFFFFC) + (v31 & 0xFFFFFFFC),
                     &v70);
          if ( (_DWORD)result )
            goto LABEL_83;
          a4 = v68;
          a5 = v69;
          v8 = v62;
          a3 = v36;
          v15 = v67;
          v17 += v70;
        }
      }
    }
    ++v16;
  }
  while ( v16 != 3 );
  v38 = (_QWORD *)*v15;
  if ( (_QWORD *)*v15 == v15 )
  {
LABEL_80:
    if ( v17 )
      cam_isp_update_hw_entry(3, a4, a3, v17, 0);
    goto LABEL_82;
  }
  v7 = 4294946815LL;
  while ( 1 )
  {
    v10 = v38[4];
    if ( v10 && *(_DWORD *)(*(_QWORD *)(v10 + 16) + 4LL) == v6 )
    {
      v39 = *(_DWORD *)(a3 + 20);
      v40 = *(_DWORD *)(a3 + 24);
      v41 = v39 - (v40 + v17);
      if ( v39 <= v40 + v17 )
        goto LABEL_85;
      v42 = *(_DWORD *)(v10 + 4);
      v43 = v42 - 20481;
      if ( *(_DWORD *)(a5 + 9352) > (unsigned int)(v42 - 20481)
        && (*(_BYTE *)(a5 + 9387) != 1
         || (*(_BYTE *)(a5 + 9316) & 4) == 0
         || *(_DWORD *)(*(_QWORD *)(a5 + 9360) + 8LL) > v43)
        && ((v8 >> v43) & 1) == 0 )
      {
        if ( v43 > 3 )
          goto LABEL_89;
        v44 = *(_QWORD *)(a3 + 8);
        v45 = *(_QWORD *)(a5 + 9360) + 40LL * v43;
        v46 = a3;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v64 = v8;
          v55 = v39 - (v40 + v17);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_isp_sfe_add_scratch_buffer_cfg",
            14732,
            "RM res_id: 0x%x idx: %u io_addr: %pK, ctx_idx: %u",
            v42,
            v43,
            *(const void **)(v45 + 32),
            *(_DWORD *)(v69 + 56));
          v41 = v55;
          v8 = v64;
          v10 = v38[4];
        }
        result = cam_isp_sfe_send_scratch_buf_upd(
                   v41,
                   2,
                   v10,
                   v45 + 16,
                   v44 + (v17 & 0xFFFFFFFC) + (v40 & 0xFFFFFFFC),
                   &v70);
        if ( (_DWORD)result )
          goto LABEL_83;
        a4 = v68;
        a5 = v69;
        v15 = v67;
        a3 = v46;
        v17 += v70;
      }
    }
    v10 = v38[5];
    if ( v10 )
    {
      if ( *(_DWORD *)(*(_QWORD *)(v10 + 16) + 4LL) == v6 )
        break;
    }
LABEL_51:
    v38 = (_QWORD *)*v38;
    if ( v38 == v15 )
      goto LABEL_80;
  }
  v47 = *(_DWORD *)(a3 + 20);
  v48 = *(_DWORD *)(a3 + 24);
  v49 = v47 - (v48 + v17);
  if ( v47 > v48 + v17 )
  {
    v50 = *(_DWORD *)(v10 + 4);
    v51 = v50 - 20481;
    if ( *(_DWORD *)(a5 + 9352) > (unsigned int)(v50 - 20481)
      && (*(_BYTE *)(a5 + 9387) != 1
       || (*(_BYTE *)(a5 + 9316) & 4) == 0
       || *(_DWORD *)(*(_QWORD *)(a5 + 9360) + 8LL) > v51)
      && ((v8 >> v51) & 1) == 0 )
    {
      if ( v51 > 3 )
        goto LABEL_89;
      v52 = *(_QWORD *)(a3 + 8);
      v53 = *(_QWORD *)(a5 + 9360) + 40LL * v51;
      v54 = a3;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v65 = v8;
        v56 = v47 - (v48 + v17);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_isp_sfe_add_scratch_buffer_cfg",
          14732,
          "RM res_id: 0x%x idx: %u io_addr: %pK, ctx_idx: %u",
          v50,
          v51,
          *(const void **)(v53 + 32),
          *(_DWORD *)(v69 + 56));
        v49 = v56;
        v8 = v65;
        v10 = v38[5];
      }
      result = cam_isp_sfe_send_scratch_buf_upd(
                 v49,
                 2,
                 v10,
                 v53 + 16,
                 v52 + (v17 & 0xFFFFFFFC) + (v48 & 0xFFFFFFFC),
                 &v70);
      if ( (_DWORD)result )
        goto LABEL_83;
      a4 = v68;
      a5 = v69;
      v15 = v67;
      a3 = v54;
      v17 += v70;
    }
    goto LABEL_51;
  }
LABEL_85:
  v57 = *(unsigned int *)(a5 + 56);
  v58 = 14707;
LABEL_86:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_sfe_add_scratch_buffer_cfg",
    v58,
    "no free kmd memory for base %d, ctx_idx: %u",
    v6,
    v57);
  result = 4294967284LL;
LABEL_83:
  _ReadStatusReg(SP_EL0);
  return result;
}
