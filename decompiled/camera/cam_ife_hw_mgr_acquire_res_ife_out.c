__int64 __fastcall cam_ife_hw_mgr_acquire_res_ife_out(__int64 a1, __int64 a2)
{
  __int64 *v3; // x24
  __int64 *v4; // x26
  unsigned int v6; // w28
  unsigned int v7; // w6
  __int64 v8; // x10
  __int64 v9; // x9
  unsigned int v10; // w21
  __int64 v11; // x8
  int v12; // w25
  int *v13; // x23
  __int64 v14; // x22
  unsigned int *v15; // x10
  int v16; // w11
  __int64 v17; // x9
  int v18; // w10
  __int64 v19; // x11
  __int64 v20; // x8
  __int64 (__fastcall *v21)(__int64, __int64 *, __int64); // x9
  __int64 v22; // x0
  unsigned int v23; // w0
  __int64 v24; // x6
  __int64 v25; // x7
  __int64 v26; // x4
  const char *v27; // x5
  __int64 v28; // x21
  _DWORD *v29; // x8
  __int64 v30; // x9
  int v31; // w11
  unsigned __int64 v32; // x8
  int v33; // w10
  unsigned int *v34; // x23
  unsigned int v35; // w6
  int v39; // w8
  int *v40; // x10
  __int64 v41; // x9
  __int64 v42; // x10
  _DWORD *v43; // x12
  int v44; // w8
  __int64 v45; // x26
  _DWORD *v46; // x27
  __int64 v47; // x8
  __int64 v48; // x8
  int v49; // w10
  __int64 v50; // x8
  __int64 v51; // x9
  char v52; // w8
  __int64 v53; // x9
  char v54; // w25
  __int64 v55; // x8
  int v56; // w9
  __int64 v57; // x0
  __int64 (__fastcall *v58)(__int64, __int64 *, __int64); // x9
  unsigned int v59; // w0
  __int64 v60; // x9
  unsigned int v61; // w8
  _DWORD *v62; // x28
  __int64 v63; // x8
  _DWORD *v64; // x10
  __int64 v65; // x9
  int v66; // w9
  unsigned int v67; // w8
  __int64 *v69; // [xsp+10h] [xbp-90h]
  int v70; // [xsp+1Ch] [xbp-84h]
  _DWORD *v71; // [xsp+20h] [xbp-80h]
  __int64 v72; // [xsp+28h] [xbp-78h] BYREF
  __int64 v73; // [xsp+30h] [xbp-70h]
  __int64 v74; // [xsp+38h] [xbp-68h]
  __int64 (__fastcall *v75)(); // [xsp+40h] [xbp-60h]
  __int64 v76; // [xsp+48h] [xbp-58h]
  __int64 v77; // [xsp+50h] [xbp-50h]
  __int64 v78; // [xsp+58h] [xbp-48h]
  unsigned int *v79; // [xsp+60h] [xbp-40h]
  __int128 v80; // [xsp+68h] [xbp-38h]
  __int64 v81; // [xsp+78h] [xbp-28h]
  __int64 v82; // [xsp+80h] [xbp-20h]
  __int64 v83; // [xsp+88h] [xbp-18h]
  __int64 v84; // [xsp+90h] [xbp-10h]
  __int64 v85; // [xsp+98h] [xbp-8h]

  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (__int64 *)(a1 + 224);
  v3 = *(__int64 **)(a1 + 224);
  if ( v3 == (__int64 *)(a1 + 224) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "cam_ife_hw_mgr_acquire_res_ife_out",
      3343,
      "IFE src list empty, ctx_idx: %u",
      *(_DWORD *)(a1 + 56));
LABEL_118:
    v6 = 0;
    goto LABEL_119;
  }
  v6 = -22;
  v69 = (__int64 *)(a1 + 224);
LABEL_5:
  if ( (*(_DWORD *)a2 != 3 || !*((_DWORD *)v3 + 28)) && *((_DWORD *)v3 + 27) )
    goto LABEL_4;
  v7 = *((_DWORD *)v3 + 5);
  if ( v7 > 9 )
  {
LABEL_41:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_res_ife_out",
      3370,
      "Unknown IFE SRC resource: %d, ctx_idx: %u",
      v7,
      *(_DWORD *)(a1 + 56));
    goto LABEL_115;
  }
  if ( ((1 << v7) & 0xF8) == 0 )
  {
    if ( ((1 << v7) & 0x305) == 0 )
      goto LABEL_41;
    if ( !*(_DWORD *)(a2 + 144) )
      goto LABEL_3;
    v28 = 0;
    v83 = 0;
    v84 = 0;
    v81 = 0;
    v82 = 0;
    v80 = 0u;
    v78 = 0;
    v79 = nullptr;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = nullptr;
    v72 = 0;
    v73 = 0;
LABEL_55:
    v34 = (unsigned int *)(*(_QWORD *)(a2 + 224) + 44 * v28);
    v35 = *v34;
    if ( *v34 < 0x3000 || max_ife_out_res + 12288 <= v35 || v35 - 12294 < 4 || v35 == 12327 )
      goto LABEL_54;
    v39 = *((_DWORD *)v3 + 5);
    if ( dword_3A85F0 )
    {
      v40 = &dword_3A85F4;
      if ( dword_3A85F8 == v35 )
        goto LABEL_67;
      if ( dword_3A85F0 != 1 )
      {
        v40 = &dword_3A85FC;
        if ( dword_3A8600 == v35 )
          goto LABEL_67;
        if ( dword_3A85F0 != 2 )
        {
          v40 = &dword_3A8604;
          if ( dword_3A8608 == v35 )
          {
LABEL_67:
            if ( *v40 != v39 )
              goto LABEL_54;
LABEL_68:
            if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_hw_mgr_acquire_res_ife_out_pixel",
                2953,
                "res_type 0x%x, ctx_idx: %u",
                v35,
                *(_DWORD *)(a1 + 56));
              LOBYTE(v35) = *(_BYTE *)v34;
            }
            if ( *(_DWORD *)a2 == 3 )
            {
              v41 = *(_QWORD *)(a1 + 8496);
              if ( !*((_DWORD *)v3 + 5) )
              {
                LOBYTE(v84) = 1;
                v42 = *(unsigned __int8 *)(v41 + (unsigned __int8)v35);
                if ( v42 != 255 )
                {
                  v43 = (_DWORD *)(*(_QWORD *)(a1 + 272) + (v42 << 7));
                  if ( v43[5] == *v34 )
                  {
                    if ( v43[28] )
                    {
                      v70 = 1;
LABEL_84:
                      v44 = *(_DWORD *)(a2 + 80);
                      v45 = 0;
                      LODWORD(v72) = 6;
                      v46 = v43 + 8;
                      v43[6] = v44;
                      v47 = *(_QWORD *)(a1 + 8728);
                      v79 = v34;
                      v71 = v43;
                      v82 = v47;
                      v48 = *(_QWORD *)(a1 + 9336);
                      v49 = *((_DWORD *)v3 + 6);
                      LOBYTE(v83) = byte_3A8576;
                      v75 = cam_ife_hw_mgr_event_handler;
                      v76 = v48;
                      v50 = *(_QWORD *)(a1 + 9344);
                      LODWORD(v80) = *(_DWORD *)(a1 + 56);
                      DWORD1(v80) = v49;
                      v51 = *(_QWORD *)(a1 + 16);
                      v77 = v50;
                      v52 = 1;
                      v73 = v51;
                      v74 = a1;
                      while ( 1 )
                      {
                        v53 = v3[v45 + 4];
                        v54 = v52;
                        if ( v53 )
                          break;
LABEL_85:
                        v52 = 0;
                        v45 = 1;
                        if ( (v54 & 1) == 0 )
                        {
                          v4 = v69;
                          v71[4] = 6;
                          v66 = v71[28];
                          v71[5] = *v34;
                          v67 = v79[9];
                          *((_BYTE *)v71 + 121) = v84;
                          v71[28] = v66 | v67;
                          if ( (v70 & 1) == 0 )
                          {
                            v71[24] = 255;
                            ++*((_DWORD *)v3 + 27);
                            ++*(_DWORD *)(a1 + 8512);
                          }
LABEL_54:
                          if ( ++v28 < (unsigned __int64)*(unsigned int *)(a2 + 144) )
                            goto LABEL_55;
LABEL_3:
                          v6 = 0;
LABEL_4:
                          v3 = (__int64 *)*v3;
                          if ( v3 == v4 )
                            goto LABEL_118;
                          goto LABEL_5;
                        }
                      }
                      v55 = *(_QWORD *)(v53 + 16);
                      if ( (v54 & 1) != 0 )
                      {
                        DWORD2(v80) = 0;
                        v56 = *((_DWORD *)v3 + 6);
                        if ( v56 )
                        {
                          v56 = *(_DWORD *)(a1 + 64);
                          HIDWORD(v80) = 1;
                        }
                        else
                        {
                          HIDWORD(v80) = 0;
                        }
                      }
                      else
                      {
                        v56 = *(_DWORD *)(a1 + 60);
                        *((_QWORD *)&v80 + 1) = 1;
                      }
                      LODWORD(v81) = v56;
                      v57 = *(_QWORD *)(v55 + 112);
                      v58 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v55 + 40);
                      if ( *((_DWORD *)v58 - 1) != 1989616049 )
                        __break(0x8229u);
                      v59 = v58(v57, &v72, 112);
                      if ( v59 )
                      {
                        v6 = v59;
                        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                          3,
                          8,
                          1,
                          "cam_ife_hw_mgr_acquire_res_ife_out_pixel",
                          3026,
                          "Can not acquire out resource 0x%x, ctx_idx: %u",
                          *v34,
                          *(_DWORD *)(a1 + 56));
                        v4 = v69;
                        goto LABEL_115;
                      }
                      v60 = v78;
                      *(_QWORD *)&v46[2 * v45] = v78;
                      if ( (v54 & 1) == 0 )
                      {
LABEL_109:
                        if ( (debug_mdl & 8) != 0 && !debug_priority )
                          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                            3,
                            debug_mdl & 8,
                            4,
                            "cam_ife_hw_mgr_acquire_res_ife_out_pixel",
                            3059,
                            "resource type:0x%x res id:0x%x comp grp id:%d ctx:%u",
                            **(_DWORD **)&v46[2 * v45],
                            *(_DWORD *)(*(_QWORD *)&v46[2 * v45] + 4LL),
                            v71[29],
                            *(_DWORD *)(a1 + 56));
                        goto LABEL_85;
                      }
                      if ( v70 )
                      {
                        v61 = v71[29];
                      }
                      else
                      {
                        v61 = HIDWORD(v83);
                        v71[29] = HIDWORD(v83);
                      }
                      v62 = (_DWORD *)(*(_QWORD *)(a1 + 9472) + 292LL * v61);
                      v63 = (unsigned int)*v62;
                      if ( (unsigned int)v63 > 0x23 )
                        goto LABEL_120;
                      v64 = &v62[v63];
                      v64[1] = *(_DWORD *)(v60 + 4);
                      if ( *(_DWORD *)a2 == 3 && (unsigned __int8)v84 == 1 )
                      {
                        v65 = 1LL << *v34;
                        if ( (v65 & qword_3A85D8) != 0 )
                        {
                          if ( qword_3A85E0 & v65 | qword_3A85E8 & v65 && (qword_3A85E8 & v65) == 0 )
                          {
                            v64[37] = v79[9];
LABEL_108:
                            *v62 = v63 + 1;
                            goto LABEL_109;
                          }
                        }
                        else
                        {
                          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                            3,
                            8,
                            1,
                            "cam_ife_hw_mgr_is_multi_context_port",
                            136,
                            "Invalid res_id: 0x%x trunc_res_id: %d",
                            *v34,
                            *v34 - 12288);
                          v63 = (unsigned int)*v62;
                          if ( (unsigned int)v63 > 0x23 )
                            goto LABEL_120;
                        }
                      }
                      v62[v63 + 37] = 0;
                      goto LABEL_108;
                    }
                  }
                }
              }
            }
            else
            {
              v41 = *(_QWORD *)(a1 + 8496);
            }
            v70 = 0;
            *(_BYTE *)(v41 + (unsigned __int8)v35) = *(_DWORD *)(a1 + 8512);
            v43 = (_DWORD *)(*(_QWORD *)(a1 + 272) + ((unsigned __int64)*(unsigned int *)(a1 + 8512) << 7));
            goto LABEL_84;
          }
          if ( dword_3A85F0 != 3 )
            goto LABEL_120;
        }
      }
    }
    if ( v39 )
      goto LABEL_54;
    goto LABEL_68;
  }
  v83 = 0;
  v84 = 0;
  v8 = *(_QWORD *)(a1 + 16);
  v9 = *(unsigned int *)(a2 + 144);
  v81 = 0;
  v82 = 0;
  v80 = 0u;
  v10 = max_ife_out_res;
  v78 = 0;
  v79 = nullptr;
  v76 = 0;
  v77 = 0;
  v11 = v3[4];
  v74 = 0;
  v75 = nullptr;
  v72 = 0;
  v73 = 0;
  v12 = *(_DWORD *)(v11 + 4);
  v73 = v8;
  LODWORD(v72) = 6;
  if ( !(_DWORD)v9 )
  {
    LODWORD(v14) = 0;
    v13 = nullptr;
    v6 = -22;
    goto LABEL_44;
  }
  v13 = *(int **)(a2 + 224);
  v14 = 0;
  v15 = (unsigned int *)&v13[11 * (unsigned int)(v9 - 1)];
  while ( 1 )
  {
    v16 = *v13;
    if ( *v13 <= 12295 )
    {
      if ( v16 == 12294 )
      {
        if ( v12 == 3 )
          break;
        goto LABEL_13;
      }
      if ( v16 == 12295 )
      {
        if ( v12 == 4 )
          break;
        goto LABEL_13;
      }
    }
    else
    {
      switch ( v16 )
      {
        case 12296:
          if ( v12 == 5 )
            goto LABEL_29;
          goto LABEL_13;
        case 12297:
          if ( v12 == 6 )
            goto LABEL_29;
          goto LABEL_13;
        case 12327:
          if ( v12 == 7 )
            goto LABEL_29;
          goto LABEL_13;
      }
    }
    if ( v12 == 10 )
      break;
LABEL_13:
    ++v14;
    v13 += 11;
    if ( v9 == v14 )
    {
      v6 = -22;
      LODWORD(v14) = v9;
      v13 = (int *)v15;
      goto LABEL_44;
    }
  }
LABEL_29:
  v10 = (unsigned __int8)*v13;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_acquire_res_ife_out_rdi",
      2868,
      "i = %d, ctx: %d out_res_id = %d, out_port: %d",
      v14,
      *(_DWORD *)(a1 + 56),
      v10,
      v16);
    v11 = v3[4];
  }
  v17 = *(_QWORD *)(a1 + 8728);
  v18 = *(_DWORD *)(a1 + 56);
  v19 = *(_QWORD *)(a1 + 9336);
  *(_QWORD *)((char *)&v80 + 4) = 0;
  v82 = v17;
  LODWORD(v80) = v18;
  v79 = (unsigned int *)v13;
  LOBYTE(v83) = byte_3A8576;
  LOBYTE(v17) = *((_BYTE *)v3 + 120);
  v74 = a1;
  v75 = cam_ife_hw_mgr_event_handler;
  v76 = v19;
  v20 = *(_QWORD *)(v11 + 16);
  BYTE1(v83) = v17;
  v21 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v20 + 40);
  v22 = *(_QWORD *)(v20 + 112);
  if ( *((_DWORD *)v21 - 1) != 1989616049 )
    __break(0x8229u);
  v23 = v21(v22, &v72, 112);
  if ( v23 )
  {
    v24 = (unsigned int)*v13;
    v25 = *(unsigned int *)(a1 + 56);
    v6 = v23;
    v26 = 2887;
    v27 = "Can not acquire out resource 0x%x, ctx_idx: %u";
    goto LABEL_51;
  }
  v29 = (_DWORD *)(*(_QWORD *)(a1 + 9472) + 292LL * HIDWORD(v83));
  v30 = (unsigned int)*v29;
  if ( (unsigned int)v30 > 0x23 )
LABEL_120:
    __break(0x5512u);
  v31 = *v13;
  v6 = 0;
  *v29 = v30 + 1;
  v29[v30 + 1] = v31;
LABEL_44:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_acquire_res_ife_out_rdi",
      2899,
      "ctx: %d out_res_id = %d, in_res_id: %d",
      *(_DWORD *)(a1 + 56),
      v10,
      v12);
  v25 = *(unsigned int *)(a2 + 144);
  if ( (_DWORD)v14 == (_DWORD)v25 || v10 >= max_ife_out_res )
  {
    v26 = 2904;
    v27 = "Cannot acquire out resource, i=%d, num_out_res=%d, ctx_idx: %u res_id: %d";
    v24 = (unsigned int)v14;
LABEL_51:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_res_ife_out_rdi",
      v26,
      v27,
      v24,
      v25);
  }
  else
  {
    v6 = 0;
    *(_BYTE *)(*(_QWORD *)(a1 + 8496) + v10) = *(_DWORD *)(a1 + 8512);
    v32 = *(_QWORD *)(a1 + 272) + ((unsigned __int64)*(unsigned int *)(a1 + 8512) << 7);
    *(_QWORD *)(v32 + 32) = v78;
    *(_DWORD *)(v32 + 24) = 0;
    *(_BYTE *)(v32 + 120) = *((_BYTE *)v3 + 120);
    v33 = *v13;
    *(_DWORD *)(v32 + 16) = 6;
    *(_DWORD *)(v32 + 20) = v33;
    *(_DWORD *)(v32 + 96) = 255;
    ++*((_DWORD *)v3 + 27);
    ++*(_DWORD *)(a1 + 8512);
  }
LABEL_115:
  if ( !v6 )
    goto LABEL_4;
LABEL_119:
  _ReadStatusReg(SP_EL0);
  return v6;
}
