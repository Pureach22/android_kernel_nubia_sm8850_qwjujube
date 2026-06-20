__int64 __fastcall ml_nlink_validate_request(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, __int64 a5, void *a6)
{
  int v11; // w23
  int v12; // w8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x5
  unsigned int v22; // w6
  const char *v23; // x2
  __int64 v24; // x4
  unsigned int v25; // w26
  const char *v26; // x2
  __int64 v27; // x4
  __int64 result; // x0
  _BYTE *v29; // x25
  char v30; // w10
  const char *v31; // x2
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  unsigned int v35; // w0
  int v36; // w8
  int v37; // w9
  __int64 v38; // x0
  unsigned int v39; // w0
  void *v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int16 v49; // w10
  __int16 v50; // w9
  __int16 v51; // w9
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // [xsp+0h] [xbp-B0h]
  __int64 v61; // [xsp+8h] [xbp-A8h]
  __int64 v62; // [xsp+18h] [xbp-98h]
  __int64 v63; // [xsp+20h] [xbp-90h] BYREF
  __int64 v64; // [xsp+28h] [xbp-88h]
  __int64 v65; // [xsp+30h] [xbp-80h]
  __int64 v66; // [xsp+38h] [xbp-78h] BYREF
  __int64 v67; // [xsp+40h] [xbp-70h]
  int v68; // [xsp+48h] [xbp-68h]
  unsigned int v69; // [xsp+50h] [xbp-60h] BYREF
  char v70; // [xsp+57h] [xbp-59h] BYREF
  int v71; // [xsp+58h] [xbp-58h] BYREF
  char v72; // [xsp+5Ch] [xbp-54h]
  int v73; // [xsp+60h] [xbp-50h] BYREF
  char v74; // [xsp+64h] [xbp-4Ch]
  _QWORD v75[5]; // [xsp+68h] [xbp-48h] BYREF
  _QWORD v76[2]; // [xsp+90h] [xbp-20h] BYREF
  int v77; // [xsp+A0h] [xbp-10h]
  __int64 v78; // [xsp+A8h] [xbp-8h]

  v11 = a1;
  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(unsigned __int16 *)(a5 + 8);
  v68 = 0;
  v66 = 0;
  v67 = 0;
  LOWORD(v65) = 0;
  v63 = 0;
  v64 = 0;
  if ( !v12
    && !*(_WORD *)(a5 + 10)
    && !*(_BYTE *)(a5 + 12)
    && !*(_WORD *)(a5 + 14)
    && !*(_BYTE *)(a5 + 16)
    && !*(_WORD *)(a5 + 18) )
  {
    qdf_mem_copy(a6, (const void *)a3, 0x14u);
    goto LABEL_31;
  }
  v69 = 0;
  v74 = 0;
  v73 = 0;
  v77 = 0;
  v76[0] = 0;
  v76[1] = 0;
  v72 = 0;
  v71 = 0;
  memset(v75, 0, sizeof(v75));
  ml_nlink_get_link_info(a1, a2, 1u, 5u, v75, (unsigned int *)v76, (unsigned __int8 *)&v73, &v71, &v70, &v69);
  v21 = *(unsigned __int16 *)(a5 + 8);
  v22 = *(unsigned __int16 *)(a5 + 10);
  if ( (v22 & (unsigned int)v21) == 0 )
  {
    v25 = v69;
    if ( *(_WORD *)(a5 + 8)
      && (*(_BYTE *)(a5 + 12) || *(_WORD *)(a5 + 14) || *(_BYTE *)(a5 + 16) || *(_WORD *)(a5 + 18)) )
    {
      v26 = "%s: req source %d not supported: force_active_bitmap 0x%x conflict with force num";
LABEL_16:
      v27 = a4;
LABEL_24:
      qdf_trace_msg(0x8Fu, 8u, v26, v13, v14, v15, v16, v17, v18, v19, v20, "ml_nlink_validate_request", v27, v21);
      goto LABEL_25;
    }
    if ( *(_WORD *)(a5 + 10) )
    {
      if ( *(_BYTE *)(a5 + 12) || *(_WORD *)(a5 + 14) || *(_BYTE *)(a5 + 16) || *(_WORD *)(a5 + 18) )
      {
        v26 = "%s: req source %d not supported: force_inactive_bitmap 0x%x conflict with force num";
LABEL_23:
        v27 = a4;
        v21 = v22;
        goto LABEL_24;
      }
      v29 = (_BYTE *)(a5 + 12);
    }
    else
    {
      v29 = (_BYTE *)(a5 + 12);
      if ( *(_BYTE *)(a5 + 12) )
      {
        if ( !*(_WORD *)(a5 + 14) )
        {
LABEL_34:
          v31 = "%s: req source %d not supported: force act num bitmap 0";
LABEL_42:
          qdf_trace_msg(0x8Fu, 8u, v31, v13, v14, v15, v16, v17, v18, v19, v20, "ml_nlink_validate_request", a4);
          goto LABEL_25;
        }
        v30 = 0;
LABEL_36:
        if ( *(_BYTE *)(a5 + 16) )
        {
          if ( *(_WORD *)(a5 + 18) )
          {
            if ( (v30 & 1) == 0 )
            {
              v23 = "%s: req source %d not supported: force inact num %d mix with act num %d in req";
              v24 = a4;
              goto LABEL_9;
            }
LABEL_43:
            if ( *(_WORD *)(a5 + 8) )
            {
              if ( (*(_WORD *)(a3 + 10) & (unsigned __int16)v21) != 0 )
              {
                v23 = "%s: req source %d not supported: act bitmap 0x%x conflict with high priority inact bitmap 0x%x";
                v24 = a4;
                goto LABEL_9;
              }
              if ( *(_WORD *)(a3 + 18) )
              {
                v32 = *(unsigned __int16 *)(a3 + 18) & (unsigned int)~(_DWORD)v21;
                if ( !(_DWORD)v32 )
                {
                  v26 = "%s: req source %d not supported: act bitmap 0x%x conflict with high priority forc inact num";
                  goto LABEL_16;
                }
                if ( (unsigned int)convert_link_bitmap_to_link_ids(v32, 0, 0, v13, v14, v15, v16, v17, v18, v19, v20) < *(unsigned __int8 *)(a3 + 16) )
                {
                  v21 = *(unsigned __int16 *)(a5 + 8);
                  v26 = "%s: req source %d not supported: act bitmap 0x%x, can't force inact num for high priority";
                  goto LABEL_16;
                }
                v22 = *(unsigned __int16 *)(a5 + 10);
              }
            }
            if ( v22 )
            {
              if ( (*(_WORD *)(a3 + 8) & (unsigned __int16)v22) != 0 )
              {
                v23 = "%s: req source %d not supported: inact bitmap 0x%x conflict with high priority act bitmap 0x%x";
                v24 = a4;
                goto LABEL_9;
              }
              if ( (v25 & ~(*(unsigned __int16 *)(a3 + 10) | v22)) == 0 )
              {
                v26 = "%s: req source %d not supported: no available link after force inact bitmap 0x%x";
                goto LABEL_23;
              }
              v21 = *(unsigned __int16 *)(a3 + 14);
              if ( *(_WORD *)(a3 + 14) )
              {
                v33 = (unsigned int)v21 & ~v22;
                if ( !(_DWORD)v33 )
                {
                  v26 = "%s: req source %d not supported: can't force act number bitmap 0x%x for high priority";
                  goto LABEL_16;
                }
                if ( (unsigned int)convert_link_bitmap_to_link_ids(v33, 0, 0, v13, v14, v15, v16, v17, v18, v19, v20) < *(unsigned __int8 *)(a3 + 12) )
                {
                  v31 = "%s: req source %d not supported: no available link to force act num";
                  goto LABEL_42;
                }
              }
            }
            if ( *(_WORD *)(a5 + 14) )
            {
              v21 = (unsigned __int8)*v29;
              if ( !*v29 )
              {
                v31 = "%s: req source %d not supported: req force act num 0";
                goto LABEL_42;
              }
              if ( *(_WORD *)(a3 + 10) )
              {
                v34 = *(unsigned __int16 *)(a5 + 14) & ~*(unsigned __int16 *)(a3 + 10);
                if ( !(_DWORD)v34 )
                {
                  v26 = "%s: req source %d not supported: no available link to force act num bitmap 0x%x";
                  v27 = a4;
                  v21 = *(unsigned __int16 *)(a5 + 14);
                  goto LABEL_24;
                }
                v35 = convert_link_bitmap_to_link_ids(v34, 0, 0, v13, v14, v15, v16, v17, v18, v19, v20);
                v21 = (unsigned __int8)*v29;
                if ( v35 < (unsigned int)v21 )
                {
                  v26 = "%s: req source %d not supported: no available link to force act num %d";
                  goto LABEL_16;
                }
              }
              if ( (unsigned int)v21 >= 3 )
              {
                v26 = "%s: req source %d not supported: force_active_num %d > 2";
                goto LABEL_16;
              }
              if ( (_DWORD)v21 == 2 && *(_BYTE *)(a3 + 16) )
              {
                v36 = *(unsigned __int16 *)(a5 + 14);
                v37 = *(unsigned __int16 *)(a3 + 18);
                if ( (v37 & ~v36) == 0 )
                {
                  v23 = "%s: req source %d not supported: force act num %d conflict with inact num %d";
                  v24 = a4;
                  goto LABEL_9;
                }
                if ( (unsigned int)convert_link_bitmap_to_link_ids(
                                     v37 & (unsigned int)~v36,
                                     0,
                                     0,
                                     v13,
                                     v14,
                                     v15,
                                     v16,
                                     v17,
                                     v18,
                                     v19,
                                     v20) < *(unsigned __int8 *)(a3 + 16) )
                {
                  v31 = "%s: req source %d not supported: no available link to force inact";
                  goto LABEL_42;
                }
              }
            }
            if ( *(_WORD *)(a5 + 18) )
            {
              v21 = *(unsigned __int8 *)(a5 + 16);
              if ( !*(_BYTE *)(a5 + 16) )
              {
                v31 = "%s: req source %d not supported: req force inact num 0";
                goto LABEL_42;
              }
              if ( *(_WORD *)(a3 + 8) )
              {
                v38 = *(unsigned __int16 *)(a5 + 18) & ~*(unsigned __int16 *)(a3 + 8);
                if ( !(_DWORD)v38 )
                {
                  v31 = "%s: req source %d not supported: no available link to force inact num";
                  goto LABEL_42;
                }
                v39 = convert_link_bitmap_to_link_ids(v38, 0, 0, v13, v14, v15, v16, v17, v18, v19, v20);
                v21 = *(unsigned __int8 *)(a5 + 16);
                if ( v39 < (unsigned int)v21 )
                {
                  v21 = *(unsigned __int16 *)(a5 + 18);
                  v26 = "%s: req source %d not supported: no available link to force inact num bitmap 0x%x";
                  goto LABEL_16;
                }
              }
              if ( (unsigned int)v21 >= 3 )
              {
                v26 = "%s: req source %d not supported: force_inactive_num %d";
                goto LABEL_16;
              }
            }
            if ( *(_BYTE *)(a3 + 12) && *v29 )
            {
              v31 = "%s: req source %d not supported: high priority force active num present";
              goto LABEL_42;
            }
            if ( *(_BYTE *)(a3 + 16) && *(_BYTE *)(a5 + 16) )
            {
              v31 = "%s: req source %d not supported: high priority force inactive num present";
              goto LABEL_42;
            }
            v40 = qdf_mem_copy(&v66, (const void *)a3, 0x14u);
            v49 = *(_WORD *)(a5 + 10);
            LOWORD(v67) = v67 | *(_WORD *)(a5 + 8);
            WORD1(v67) |= v49;
            if ( !BYTE4(v67) )
            {
              v50 = *(_WORD *)(a5 + 14);
              BYTE4(v67) = *(_BYTE *)(a5 + 12);
              HIWORD(v67) = v50;
            }
            if ( !(_BYTE)v68 )
            {
              v51 = *(_WORD *)(a5 + 18);
              LOBYTE(v68) = *(_BYTE *)(a5 + 16);
              HIWORD(v68) = v51;
            }
            ml_nlink_get_curr_force_state(v41, v42, v43, v44, v45, v46, v47, v48, (__int64)v40, a2, &v63);
            if ( (ml_nlink_check_allow_link_req(v11, a2) & 1) == 0 )
            {
              v31 = "%s: req source %d not supported by conc check";
              goto LABEL_42;
            }
            qdf_mem_copy(a6, &v66, 0x14u);
            LODWORD(v61) = *(unsigned __int8 *)(a5 + 16);
            LODWORD(v60) = *(unsigned __int16 *)(a5 + 14);
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: source %d act 0x%x inact 0x%x %d 0x%x %d 0x%x",
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              "ml_nlink_validate_request",
              a4,
              *(unsigned __int16 *)(a5 + 8),
              *(unsigned __int16 *)(a5 + 10),
              *(unsigned __int8 *)(a5 + 12),
              v60,
              v61,
              *(unsigned __int16 *)(a5 + 18),
              v62,
              v63,
              v64,
              v65,
              v66,
              v67);
LABEL_31:
            result = 1;
            goto LABEL_26;
          }
        }
        else if ( !*(_WORD *)(a5 + 18) )
        {
          goto LABEL_43;
        }
        v31 = "%s: req source %d not supported: force inact num bitmap 0";
        goto LABEL_42;
      }
    }
    if ( *(_WORD *)(a5 + 14) )
      goto LABEL_34;
    v30 = 1;
    goto LABEL_36;
  }
  v23 = "%s: req source %d not supported: force_active_bitmap 0x%x inact 0x%x conflict";
  v24 = a4;
LABEL_9:
  qdf_trace_msg(0x8Fu, 8u, v23, v13, v14, v15, v16, v17, v18, v19, v20, "ml_nlink_validate_request", v24);
LABEL_25:
  result = 0;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
