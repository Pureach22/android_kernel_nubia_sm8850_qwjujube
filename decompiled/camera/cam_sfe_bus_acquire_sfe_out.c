__int64 __fastcall cam_sfe_bus_acquire_sfe_out(__int64 a1, __int64 a2)
{
  int v4; // w24
  unsigned int v5; // w20
  const char *v6; // x5
  __int64 v7; // x4
  __int64 result; // x0
  __int64 v9; // x28
  __int64 v10; // x8
  __int64 v11; // x23
  __int64 v12; // x8
  unsigned int v13; // w25
  unsigned int v14; // w22
  __int64 v15; // x8
  __int64 v16; // x8
  int v17; // w9
  int v18; // w22
  __int64 v19; // x8
  __int64 v20; // x28
  __int64 v21; // x27
  int *v22; // x25
  unsigned int v23; // w26
  int v24; // w9
  unsigned int v25; // w0
  int v26; // w8
  int v27; // w26
  const char *v28; // x8
  int v29; // w8
  int v30; // w9
  __int64 v31; // x8
  __int64 v32; // x8
  int v33; // w6
  int v34; // w8
  int v35; // w24
  unsigned int v36; // w21
  __int64 v37; // x8
  int v38; // w9
  _DWORD *v39; // x21
  int v40; // w9
  __int64 v41; // x12
  int v42; // w10
  __int64 v43; // x9
  int v44; // w8
  __int64 v45; // x0
  __int64 v46; // x8
  __int64 v47; // x24
  __int64 v48; // x22
  bool v49; // cc
  __int64 v50; // x9
  __int64 v51; // x8
  __int64 v52; // [xsp+40h] [xbp-50h]
  __int128 v53; // [xsp+50h] [xbp-40h] BYREF
  __int64 v54; // [xsp+60h] [xbp-30h]
  __int64 v55; // [xsp+68h] [xbp-28h]
  __int64 v56; // [xsp+70h] [xbp-20h]
  __int64 v57; // [xsp+78h] [xbp-18h]
  __int16 v58; // [xsp+80h] [xbp-10h]
  __int64 v59; // [xsp+88h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40000000,
        4,
        "cam_sfe_bus_acquire_sfe_out",
        1254,
        "SFE:%d Acquire out_type:0x%X",
        *(_DWORD *)a1,
        **(_DWORD **)(a2 + 48));
    v4 = 0;
    v5 = 5;
    switch ( **(_DWORD **)(a2 + 48) )
    {
      case 0x6000:
        v5 = 0;
        v4 = 1;
        goto LABEL_27;
      case 0x6001:
        v4 = 1;
        v5 = 1;
        goto LABEL_27;
      case 0x6002:
        v5 = 2;
        v4 = 1;
        goto LABEL_27;
      case 0x6003:
        v5 = 3;
        v4 = 1;
        goto LABEL_27;
      case 0x6004:
        v5 = 4;
        v4 = 1;
        goto LABEL_27;
      case 0x6005:
        v4 = 0;
        v5 = 7;
        goto LABEL_27;
      case 0x6006:
        v4 = 0;
        v5 = 8;
        goto LABEL_27;
      case 0x6007:
        v4 = 0;
        v5 = 9;
        goto LABEL_27;
      case 0x6008:
        v4 = 0;
        v5 = 10;
        goto LABEL_27;
      case 0x6009:
        v4 = 0;
        v5 = 11;
        goto LABEL_27;
      case 0x600A:
        v4 = 0;
        v5 = 12;
        goto LABEL_27;
      case 0x600B:
        v4 = 0;
        v5 = 6;
        goto LABEL_27;
      case 0x600C:
        goto LABEL_27;
      case 0x600D:
        v4 = 0;
        v5 = 16;
        goto LABEL_27;
      case 0x600E:
        v4 = 0;
        v5 = 13;
        goto LABEL_27;
      case 0x600F:
        v4 = 0;
        v5 = 14;
        goto LABEL_27;
      case 0x6010:
        v4 = 0;
        v5 = 15;
        goto LABEL_27;
      case 0x6011:
        v4 = 0;
        v5 = 17;
LABEL_27:
        v9 = *(_QWORD *)(a1 + 27576) + 152LL * v5;
        if ( *(_DWORD *)(v9 + 8) != 1 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000000,
            1,
            "cam_sfe_bus_acquire_sfe_out",
            1266,
            "SFE:%d out_type:0x%X resource not available state:%d",
            *(_DWORD *)a1,
            v5,
            *(_DWORD *)(v9 + 8));
          result = 4294967280LL;
          break;
        }
        v10 = *(_QWORD *)(a2 + 32);
        if ( !v10 )
        {
          v6 = "Invalid buf done controller";
          v7 = 1271;
          goto LABEL_9;
        }
        v11 = *(_QWORD *)(v9 + 24);
        *(_QWORD *)(*(_QWORD *)(v11 + 8) + 32LL) = v10;
        *(_QWORD *)(*(_QWORD *)(v11 + 8) + 27456LL) = *(_QWORD *)(a2 + 24);
        v12 = *(_QWORD *)(a2 + 16);
        *(_QWORD *)(v11 + 16) = a1;
        v13 = *(_DWORD *)v11;
        *(_QWORD *)(v11 + 104) = v12;
        v14 = *(_DWORD *)(*(_QWORD *)(a2 + 48) + 24LL);
        mutex_lock(*(_QWORD *)(v11 + 8) + 27376LL);
        if ( v13 > 0x10 || ((0x1003Fu >> v13) & 1) == 0 )
          goto LABEL_39;
        v15 = *(_QWORD *)(v11 + 8);
        if ( *(_DWORD *)(v15 + 27428) )
        {
          if ( v14 != *(_DWORD *)(v15 + 27424) )
          {
            if ( (unsigned int)__ratelimit(&cam_sfe_bus_acquire_sfe_out__rs, "cam_sfe_bus_acquire_sfe_out") )
              v45 = 3;
            else
              v45 = 2;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
              v45,
              0x40000000,
              1,
              "cam_sfe_bus_acquire_sfe_out",
              1299,
              "Mismatch: Acquire mode[%d], drvr mode[%d]",
              *(unsigned int *)(*(_QWORD *)(v11 + 8) + 27424LL),
              v14);
            mutex_unlock(*(_QWORD *)(v11 + 8) + 27376LL);
            result = 4294967274LL;
            break;
          }
          *(_DWORD *)(v11 + 96) = v14;
        }
        else
        {
          *(_DWORD *)(v11 + 96) = v14;
          *(_DWORD *)(v15 + 27424) = v14;
          v15 = *(_QWORD *)(v11 + 8);
        }
        ++*(_DWORD *)(v15 + 27428);
LABEL_39:
        mutex_unlock(*(_QWORD *)(v11 + 8) + 27376LL);
        *(_QWORD *)(a1 + 27592) = *(_QWORD *)(a2 + 8);
        *(_BYTE *)(v9 + 144) = 0;
        *(_DWORD *)(v9 + 4) = **(_DWORD **)(a2 + 48);
        *(_QWORD *)(v9 + 56) = *(_QWORD *)(a2 + 8);
        v16 = *(_QWORD *)(a2 + 72);
        *(_QWORD *)(v9 + 48) = v16;
        *(_QWORD *)(v11 + 88) = v16;
        v17 = *(_DWORD *)(v11 + 24);
        *(_DWORD *)(v11 + 72) = *(_DWORD *)(*(_QWORD *)(a2 + 48) + 4LL);
        if ( v17 )
        {
          v18 = 0;
          v52 = v9;
          while ( 1 )
          {
            v19 = *(_QWORD *)(v11 + 32);
            v58 = 0;
            v20 = v19 + 152LL * v18;
            v56 = 0;
            v57 = 0;
            v21 = *(_QWORD *)(a2 + 8);
            v54 = 0;
            v55 = 0;
            v53 = 0u;
            if ( *(_DWORD *)(v20 + 8) != 1 )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                0x40000000,
                1,
                "cam_sfe_bus_acquire_wm",
                683,
                "WM:%d not available state:%d",
                0);
              v36 = -114;
              goto LABEL_91;
            }
            v22 = *(int **)(v20 + 24);
            v23 = *v22;
            v22[16] = *(_DWORD *)(*(_QWORD *)(a2 + 48) + 4LL);
            *((_BYTE *)v22 + 123) = *(_BYTE *)(a2 + 80);
            v22[17] = cam_sfe_bus_get_packer_fmt(a1);
            v22[13] = *(_DWORD *)(*(_QWORD *)(a2 + 48) + 8LL);
            v22[14] = *(_DWORD *)(*(_QWORD *)(a2 + 48) + 12LL);
            v22[26] = *(_DWORD *)(*(_QWORD *)(a2 + 48) + 8LL);
            v22[27] = *(_DWORD *)(*(_QWORD *)(a2 + 48) + 12LL);
            v24 = *(_DWORD *)(a2 + 60);
            *((_BYTE *)v22 + 120) = 0;
            v22[25] = v24;
            if ( v4 )
              v22[18] = 0;
            v22[12] = 0;
            if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                debug_mdl & 0x40000000,
                4,
                "cam_sfe_bus_acquire_wm",
                713,
                "WM:%d width %d height %d",
                v23);
              if ( !v4 )
              {
LABEL_55:
                if ( v5 == 16 || v5 == 5 )
                {
LABEL_57:
                  v29 = v22[16];
                  v30 = v22[13];
                  v22[24] = 1;
                  v22[15] = v30;
                  if ( (unsigned int)(v29 - 14) < 4 )
                    goto LABEL_58;
                  goto LABEL_59;
                }
                if ( v5 - 7 > 8 )
                {
                  if ( v5 == 17 )
                    goto LABEL_57;
                  if ( v5 != 6 )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      0x40000000,
                      1,
                      "cam_sfe_bus_acquire_wm",
                      790,
                      "Invalid out_type:%d requested",
                      v5);
                    goto LABEL_100;
                  }
                  v33 = v22[16];
                  if ( (unsigned int)(v33 - 14) > 3 )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      0x40000000,
                      1,
                      "cam_sfe_bus_acquire_wm",
                      770,
                      "Invalid format %d out_type:%d",
                      v33,
                      6);
LABEL_100:
                    v36 = -22;
LABEL_91:
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      0x40000000,
                      1,
                      "cam_sfe_bus_acquire_sfe_out",
                      1331,
                      "Failed to acquire WM SFE:%d out_type:%d rc:%d",
                      **(_DWORD **)(v11 + 8),
                      v5,
                      v36);
                    goto LABEL_92;
                  }
                  v34 = v22[13];
                  v22[24] = 1;
                  v22[15] = (2 * v34 + 7) & 0xFFFFFFF8;
LABEL_58:
                  v22[17] |= 1 << *(_DWORD *)(a1 + 27440);
LABEL_59:
                  v27 = *(_DWORD *)(*((_QWORD *)v22 + 2) + 108LL);
LABEL_60:
                  v31 = *(_QWORD *)"line-based";
                  *(_DWORD *)((char *)&v53 + 7) = 6579571;
                }
                else
                {
                  v32 = *((_QWORD *)v22 + 2);
                  *(_QWORD *)(v22 + 13) = 0;
                  v22[15] = 1;
                  v22[24] = 65537;
                  v27 = *(_DWORD *)(v32 + 108);
LABEL_63:
                  v28 = "frame-based";
LABEL_64:
                  v31 = *(_QWORD *)v28;
                  DWORD2(v53) = 6579571;
                }
                *(_QWORD *)&v53 = v31;
                goto LABEL_66;
              }
            }
            else if ( !v4 )
            {
              goto LABEL_55;
            }
            v25 = cam_sfe_bus_config_rdi_wm(v22);
            if ( v25 )
            {
              v36 = v25;
              goto LABEL_91;
            }
            v26 = v22[24];
            v27 = *(_DWORD *)(*((_QWORD *)v22 + 2) + 108LL);
            switch ( v26 )
            {
              case 131073:
                v28 = "index-based";
                goto LABEL_64;
              case 65537:
                goto LABEL_63;
              case 1:
                goto LABEL_60;
            }
LABEL_66:
            *(_QWORD *)(v20 + 56) = v21;
            *(_DWORD *)(v20 + 8) = 2;
            if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x40000000,
                4,
                "cam_sfe_bus_acquire_wm",
                816,
                "SFE:%d WM:%d %s processed width:%d height:%d format:0x%X pack_fmt 0x%x %s",
                **((_DWORD **)v22 + 1),
                *v22,
                (const char *)(v20 + 128),
                v22[13],
                v22[14],
                v22[16],
                v22[17],
                (const char *)&v53);
            if ( (unsigned int)++v18 >= *(_DWORD *)(v11 + 24) )
            {
              v9 = v52;
              v35 = 1 << v5;
              goto LABEL_76;
            }
          }
        }
        v35 = 0;
        v18 = 0;
        v27 = 11;
LABEL_76:
        v37 = *(_QWORD *)(v11 + 40);
        v38 = *(_DWORD *)(v37 + 8);
        v39 = *(_DWORD **)(v37 + 24);
        if ( v38 != 4 )
        {
          if ( v38 == 1 )
          {
            v40 = *(_DWORD *)(a2 + 68);
            v41 = *(_QWORD *)(a2 + 8);
            v42 = *(_DWORD *)(a2 + 60);
            v39[7] = 1;
            *(_DWORD *)(v37 + 8) = 2;
            *(_QWORD *)(v37 + 56) = v41;
            v39[4] = v40;
            v39[5] = v42;
            v39[8] = v40 == 0;
          }
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x40000000,
              4,
              "cam_sfe_bus_acquire_comp_grp",
              1073,
              "Acquire SFE:%d comp_grp:%u",
              **((_DWORD **)v39 + 1),
              *v39);
          result = 0;
          ++v39[10];
          v43 = *(_QWORD *)(v11 + 40);
          *(_DWORD *)(v11 + 68) = *(_DWORD *)(a2 + 60);
          *(_DWORD *)(v11 + 64) = *(_DWORD *)(a2 + 68);
          *(_DWORD *)(*(_QWORD *)(v43 + 24) + 36LL) |= v35;
          *(_DWORD *)(v9 + 8) = 2;
          v44 = debug_mdl;
          *(_QWORD *)(a2 + 40) = v9;
          *(_DWORD *)(a2 + 84) = v27;
          if ( (v44 & 0x40000000) != 0 && !debug_priority )
          {
            ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              v44 & 0x40000000,
              4,
              "cam_sfe_bus_acquire_sfe_out",
              1362,
              "Acquire successful");
            result = 0;
          }
          break;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_acquire_comp_grp",
          1067,
          "Invalid State %d comp_grp:%u",
          4,
          *v39);
        v36 = -16;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_acquire_sfe_out",
          1348,
          "Failed to acquire comp_grp SFE:%d out_type:%d rc:%d",
          **(_DWORD **)(v11 + 8),
          v5,
          -16);
LABEL_92:
        v46 = (unsigned int)(v18 - 1);
        result = v36;
        if ( v18 - 1 >= 0 )
        {
          v47 = v46 + 1;
          v48 = 152LL * (unsigned int)v46;
          do
          {
            v50 = *(_QWORD *)(v11 + 32) + v48;
            v51 = *(_QWORD *)(v50 + 24);
            *(_BYTE *)(v51 + 122) = 0;
            *(_WORD *)(v51 + 120) = 0;
            *(_QWORD *)(v51 + 48) = 0;
            *(_QWORD *)(v51 + 56) = 0;
            *(_QWORD *)(v51 + 64) = 0;
            *(_QWORD *)(v51 + 76) = 0;
            *(_QWORD *)(v51 + 84) = 0;
            *(_QWORD *)(v51 + 92) = 0;
            *(_DWORD *)(v51 + 100) = 0;
            *(_QWORD *)(v50 + 56) = 0;
            *(_DWORD *)(v50 + 8) = 1;
            if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x40000000,
                4,
                "cam_sfe_bus_release_wm",
                848,
                "SFE:%d Release WM:%d",
                **(_DWORD **)(v51 + 8),
                *(_DWORD *)v51);
              result = v36;
            }
            v49 = v47-- <= 1;
            v48 -= 152;
          }
          while ( !v49 );
        }
        break;
      default:
        result = 4294967277LL;
        break;
    }
  }
  else
  {
    v6 = "Invalid Param";
    v7 = 1245;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_acquire_sfe_out",
      v7,
      v6);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
