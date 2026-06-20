__int64 __fastcall cam_ife_hw_mgr_acquire_res_ife_src(__int64 a1, _DWORD *a2, char a3, char a4, _DWORD *a5, __int64 a6)
{
  __int64 *v6; // x9
  __int64 *v7; // x26
  __int64 v10; // x19
  _DWORD *v11; // x11
  _QWORD *v12; // x12
  unsigned int v13; // w22
  char v14; // w13
  int v15; // w14
  unsigned int v16; // w8
  _QWORD *i; // x27
  _QWORD *v18; // x8
  __int64 v19; // x9
  _QWORD *v20; // x1
  char v21; // w9
  char v22; // w9
  char v23; // w8
  char v24; // w9
  __int64 v25; // x8
  __int64 v26; // x9
  __int64 v27; // x6
  int v28; // w8
  int v29; // w8
  __int64 v30; // x19
  _QWORD *v31; // x28
  char v32; // w8
  __int64 v33; // x9
  char v34; // w25
  __int64 v35; // x8
  __int64 v36; // x24
  int v37; // w8
  _DWORD *v38; // x9
  __int64 (__fastcall *v39)(__int64, __int64 *, __int64); // x8
  __int64 v40; // x0
  unsigned int v41; // w0
  int v42; // w9
  __int64 v43; // x6
  int v44; // w8
  int v45; // w8
  int v46; // w8
  int v47; // w8
  int v48; // w9
  const char *v49; // x5
  __int64 v50; // x7
  __int64 v51; // x4
  _QWORD *v53; // [xsp+18h] [xbp-D8h]
  __int64 *v55; // [xsp+28h] [xbp-C8h]
  char v56; // [xsp+30h] [xbp-C0h]
  char v57; // [xsp+34h] [xbp-BCh]
  _QWORD *v58; // [xsp+38h] [xbp-B8h]
  __int64 v59; // [xsp+40h] [xbp-B0h]
  __int64 v60; // [xsp+48h] [xbp-A8h]
  _DWORD *v62; // [xsp+58h] [xbp-98h]
  _DWORD *v63; // [xsp+60h] [xbp-90h]
  __int64 v64; // [xsp+70h] [xbp-80h] BYREF
  __int64 v65; // [xsp+78h] [xbp-78h]
  __int64 v66; // [xsp+80h] [xbp-70h]
  __int64 (__fastcall *v67)(__int64, unsigned int, _DWORD *); // [xsp+88h] [xbp-68h]
  __int64 v68; // [xsp+90h] [xbp-60h]
  __int64 v69; // [xsp+98h] [xbp-58h]
  __int64 v70; // [xsp+A0h] [xbp-50h]
  __int64 v71; // [xsp+A8h] [xbp-48h]
  __int64 v72; // [xsp+B0h] [xbp-40h]
  __int64 v73; // [xsp+B8h] [xbp-38h]
  __int64 v74; // [xsp+C0h] [xbp-30h]
  _DWORD *v75; // [xsp+C8h] [xbp-28h]
  __int64 v76; // [xsp+D0h] [xbp-20h]
  __int64 v77; // [xsp+D8h] [xbp-18h]
  __int64 v78; // [xsp+E0h] [xbp-10h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = (__int64 *)(a1 + 208);
  v7 = *(__int64 **)(a1 + 208);
  if ( v7 == (__int64 *)(a1 + 208) )
  {
LABEL_103:
    v13 = 0;
    goto LABEL_106;
  }
  v10 = a1;
  v59 = a1 + 0x2000;
  v60 = *(_QWORD *)(a1 + 72);
  v11 = a2;
  v58 = (_QWORD *)(a1 + 288);
  v12 = (_QWORD *)(a1 + 224);
  v64 = 0;
  v13 = -1;
  v14 = 1;
  v15 = 4;
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = nullptr;
  v62 = (_DWORD *)(a1 + 60);
  v63 = (_DWORD *)(a1 + 64);
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = nullptr;
  v65 = 0;
  v56 = a3;
  v57 = a4;
  v55 = (__int64 *)(a1 + 208);
  v53 = (_QWORD *)(a1 + 224);
  while ( 1 )
  {
    if ( *((_DWORD *)v7 + 27) && (a3 & 1) == 0 )
      goto LABEL_4;
    v16 = *((_DWORD *)v7 + 5);
    if ( (a3 & 1) == 0 )
      break;
    if ( v16 == 5 )
      goto LABEL_12;
LABEL_4:
    v7 = (__int64 *)*v7;
    if ( v7 == v6 )
      goto LABEL_103;
  }
  if ( v16 == 6 && (a4 & 1) == 0 )
    goto LABEL_4;
LABEL_12:
  if ( *v11 == 3 && v16 <= 0xB && ((1 << v16) & 0xC20) != 0 )
  {
    for ( i = (_QWORD *)*v12; i != v12; i = (_QWORD *)*i )
    {
      if ( i[4] && !*((_DWORD *)i + 5) )
        goto LABEL_33;
    }
  }
  i = (_QWORD *)*v58;
  if ( (_QWORD *)*v58 == v58 )
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
      "cam_ife_hw_mgr_acquire_res_ife_src",
      4208,
      "No more free hw mgr resource, ctx_idx: %u",
      *(_DWORD *)(v10 + 56));
    v13 = -1;
    goto LABEL_106;
  }
  v18 = (_QWORD *)i[1];
  if ( (_QWORD *)*v18 == i && (v19 = *i, *(_QWORD **)(*i + 8LL) == i) )
  {
    *(_QWORD *)(v19 + 8) = v18;
    *v18 = v19;
  }
  else
  {
    _list_del_entry_valid_or_report(*v58);
    a3 = v21;
  }
  *i = i;
  i[1] = i;
  if ( !i )
  {
LABEL_32:
    v13 = 0;
    goto LABEL_33;
  }
  v20 = *(_QWORD **)(v10 + 232);
  if ( i == v12 || v20 == i || (_QWORD *)*v20 != v12 )
  {
    _list_add_valid_or_report(i);
    a3 = v22;
    goto LABEL_32;
  }
  v13 = 0;
  *(_QWORD *)(v10 + 232) = i;
  *i = v12;
  i[1] = v20;
  *v20 = i;
LABEL_33:
  LODWORD(v64) = v15;
  v75 = v11;
  v23 = *(_BYTE *)(v59 + 1186);
  v24 = *(_BYTE *)(v59 + 1188);
  BYTE2(v76) = v14;
  HIDWORD(v72) = 0;
  LOBYTE(v76) = v23;
  v25 = *(_QWORD *)(v10 + 8728);
  BYTE1(v76) = v24;
  v26 = *(_QWORD *)(v10 + 16);
  v73 = v25;
  v65 = v26;
  v66 = v10;
  LODWORD(v25) = *(unsigned __int8 *)(v60 + 81883);
  v67 = cam_ife_hw_mgr_event_handler;
  if ( (_DWORD)v25 == 1 && *(_DWORD *)(v10 + 9312) != 2 )
    BYTE2(v76) = 0;
  v27 = *((unsigned int *)v7 + 5);
  if ( (int)v27 > 4 )
  {
    if ( (unsigned int)(v27 - 10) < 2 )
      goto LABEL_44;
    if ( (_DWORD)v27 == 6 )
    {
      LODWORD(v71) = 8;
      goto LABEL_56;
    }
    if ( (_DWORD)v27 == 5 )
    {
LABEL_44:
      if ( (a3 & 1) != 0 )
      {
        LODWORD(v71) = 9;
      }
      else
      {
        v29 = v11[53];
        LODWORD(v71) = 0;
        HIDWORD(v72) = v29;
      }
      LODWORD(v74) = *((_DWORD *)v7 + 6) != 0;
      LODWORD(v72) = *((_DWORD *)v7 + 6);
      goto LABEL_57;
    }
  }
  else
  {
    if ( (int)v27 > 1 )
    {
      if ( (_DWORD)v27 == 2 )
      {
        v28 = 5;
      }
      else if ( (_DWORD)v27 == 3 )
      {
        v28 = 6;
      }
      else
      {
        v28 = 7;
      }
LABEL_55:
      LODWORD(v71) = v28;
LABEL_56:
      LODWORD(v74) = 0;
LABEL_57:
      *((_DWORD *)i + 4) = v15;
      v30 = 0;
      v31 = i + 4;
      *((_DWORD *)i + 5) = v71;
      *((_DWORD *)i + 6) = *((_DWORD *)v7 + 6);
      *((_BYTE *)i + 120) = *((_BYTE *)v7 + 120);
      v32 = 1;
      while ( 2 )
      {
        v33 = v7[v30 + 4];
        v34 = v32;
        if ( v33 )
        {
          v35 = *(unsigned int *)(*(_QWORD *)(v33 + 16) + 4LL);
          if ( (unsigned int)v35 > 7 )
            __break(0x5512u);
          v36 = **(_QWORD **)(v60 + 160 + 8 * v35);
          v37 = *((_DWORD *)i + 6);
          if ( (v30 & 1) != 0 )
          {
            if ( v37 )
            {
              v38 = v62;
              LODWORD(v74) = 2;
              goto LABEL_65;
            }
          }
          else
          {
            v38 = v63;
            if ( v37 )
LABEL_65:
              HIDWORD(v71) = *v38;
          }
          v39 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v36 + 40);
          v40 = *(_QWORD *)(v36 + 112);
          if ( *((_DWORD *)v39 - 1) != 1989616049 )
            __break(0x8228u);
          v41 = v39(v40, &v64, 112);
          if ( v41 )
          {
            v27 = *((unsigned int *)v7 + 5);
            v13 = v41;
            v49 = "Can not acquire IFE HW res %d, ctx_idx: %u";
            v50 = *(unsigned int *)(a1 + 56);
            v51 = 4310;
            goto LABEL_105;
          }
          v42 = *((_DWORD *)i + 28);
          v31[v30] = v70;
          *((_DWORD *)i + 28) = v42 | HIDWORD(v72);
          v43 = *(unsigned int *)(v36 + 4);
          if ( (unsigned int)v43 >= g_num_ife_available )
          {
            if ( g_num_ife_lite_available + g_num_ife_available <= (unsigned int)v43 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_convert_hw_idx_to_ife_hw_num",
                3449,
                "hw idx %d out-of-bounds",
                v43);
              goto LABEL_76;
            }
            if ( (unsigned int)(v43 - g_num_ife_available) >= 5 )
              goto LABEL_76;
            v44 = dword_4514F0[(unsigned int)(v43 - g_num_ife_available)];
          }
          else
          {
            if ( (unsigned int)v43 < 3 )
            {
              v44 = dword_4514E4[v43];
              goto LABEL_77;
            }
LABEL_76:
            v44 = 0;
          }
LABEL_77:
          *a5 |= v44;
          v45 = *(_DWORD *)(v31[v30] + 4LL);
          if ( v45 > 5 )
          {
            if ( v45 <= 7 )
            {
              if ( v45 == 6 )
                v46 = 64;
              else
                v46 = 128;
              goto LABEL_100;
            }
            if ( v45 == 9 )
            {
              v46 = 4;
            }
            else
            {
              if ( v45 != 8 )
                goto LABEL_99;
              v46 = 2;
            }
          }
          else
          {
            if ( v45 > 3 )
            {
              if ( v45 == 4 )
                v46 = 16;
              else
                v46 = 32;
              goto LABEL_100;
            }
            if ( v45 )
            {
              if ( v45 == 3 )
              {
                v46 = 8;
                goto LABEL_100;
              }
LABEL_99:
              v46 = 0;
            }
            else
            {
              v47 = *((_DWORD *)v7 + 5);
              if ( v47 == 11 )
                v48 = 512;
              else
                v48 = 1;
              if ( v47 == 10 )
                v46 = 256;
              else
                v46 = v48;
            }
          }
LABEL_100:
          v13 = 0;
          *(_DWORD *)(a6 + 4 * v30) |= v46;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_hw_mgr_acquire_res_ife_src",
              4333,
              "acquire success IFE:%d ctx_idx: %u res type :0x%x res: %s res id:0x%x",
              *(_DWORD *)(v36 + 4),
              *(_DWORD *)(a1 + 56),
              *(_DWORD *)v31[v30],
              (const char *)(v31[v30] + 128LL),
              *(_DWORD *)(v31[v30] + 4LL));
            v13 = 0;
          }
        }
        v32 = 0;
        v30 = 1;
        if ( (v34 & 1) == 0 )
        {
          v11 = a2;
          v6 = v55;
          a3 = v56;
          a4 = v57;
          v10 = a1;
          v14 = 1;
          v12 = v53;
          v15 = 4;
          ++*((_DWORD *)v7 + 27);
          goto LABEL_4;
        }
        continue;
      }
    }
    if ( !(_DWORD)v27 )
    {
      v28 = 3;
      goto LABEL_55;
    }
    if ( (_DWORD)v27 == 1 )
    {
      LODWORD(v71) = v15;
      goto LABEL_56;
    }
  }
  v50 = *(unsigned int *)(v10 + 56);
  v49 = "Wrong IFE CSID Path Resource ID : %d, ctx_idx: %u";
  v51 = 4276;
LABEL_105:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_hw_mgr_acquire_res_ife_src",
    v51,
    v49,
    v27,
    v50);
LABEL_106:
  _ReadStatusReg(SP_EL0);
  return v13;
}
