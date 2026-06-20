__int64 __fastcall cam_isp_mgr_drv_config(__int64 a1, unsigned __int64 a2, char a3, __int64 a4)
{
  __int64 result; // x0
  char v7; // w21
  __int64 v8; // x24
  __int64 v9; // x26
  __int64 v10; // x8
  unsigned int v11; // w9
  unsigned __int64 *v12; // x23
  unsigned __int64 *v13; // x28
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x24
  char v17; // w27
  unsigned __int64 v18; // x8
  const char *v19; // x6
  const char *v20; // x10
  const char *v21; // x12
  const char *v22; // x7
  int v23; // w8
  __int64 v24; // x1
  int v25; // w8
  char v26; // w8
  unsigned __int64 v27; // x25
  int v28; // w22
  _BOOL4 v29; // w26
  char v30; // w8
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x21
  unsigned __int64 v33; // x15
  __int64 v34; // x7
  const char *v35; // x5
  __int64 v36; // x1
  __int64 v37; // x4
  __int64 v38; // x9
  __int64 v39; // x10
  unsigned __int64 *v40; // x24
  char v41; // w28
  unsigned __int64 v42; // x27
  _BOOL4 v43; // w8
  unsigned __int64 v44; // x8
  unsigned __int64 v45; // x21
  unsigned int *v46; // x22
  __int64 v47; // x9
  __int64 v48; // x10
  __int64 (__fastcall *v49)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v50; // x0
  int v51; // w0
  int v52; // w9
  unsigned int v53; // w20
  unsigned __int64 v54; // x10
  const char *v55; // x7
  __int64 v56; // x25
  const char *v57; // x9
  const char *v58; // x6
  char v59; // w22
  __int64 v60; // x25
  char v61; // w24
  char v62; // [xsp+3Ch] [xbp-34h]
  __int64 v63; // [xsp+48h] [xbp-28h]
  _DWORD *v64; // [xsp+50h] [xbp-20h]
  __int64 v65; // [xsp+58h] [xbp-18h] BYREF
  int v66; // [xsp+60h] [xbp-10h]
  __int64 v67; // [xsp+68h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v66 = 0;
  v65 = 0;
  if ( byte_3A88D4 == 1 && byte_3A857A != 1 )
  {
    if ( a4 )
      v7 = *(_BYTE *)(a4 + 1992);
    else
      v7 = 0;
    v8 = *(_QWORD *)(a1 + 72);
    v9 = a1 + 0x2000;
    v10 = a1 + 9536;
    if ( *(_QWORD *)(a1 + 9536) == a2 )
    {
      v11 = 0;
    }
    else if ( *(_QWORD *)(a1 + 9592) == a2 )
    {
      v11 = 1;
    }
    else if ( *(_QWORD *)(a1 + 9648) == a2 )
    {
      v11 = 2;
    }
    else if ( *(_QWORD *)(a1 + 9704) == a2 )
    {
      v11 = 3;
    }
    else if ( *(_QWORD *)(a1 + 9760) == a2 )
    {
      v11 = 4;
    }
    else if ( *(_QWORD *)(a1 + 9816) == a2 )
    {
      v11 = 5;
    }
    else if ( *(_QWORD *)(a1 + 9872) == a2 )
    {
      v11 = 6;
    }
    else
    {
      if ( *(_QWORD *)(a1 + 9928) != a2 )
      {
        if ( (v7 & 1) == 0 || *(_DWORD *)(a4 + 8) != 1 )
        {
          LOBYTE(v43) = 0;
          LODWORD(v27) = 0;
          v28 = 0;
          goto LABEL_107;
        }
        v54 = *(unsigned __int8 *)(a1 + 9984);
        *(_BYTE *)(a1 + 9984) = v54 + 1;
        if ( v54 > 7 )
LABEL_140:
          __break(0x5512u);
        v12 = (unsigned __int64 *)(v10 + 56LL * (unsigned int)v54);
        v13 = (unsigned __int64 *)(v10 + 56LL * (((_BYTE)v54 + 1) & 7));
        *v12 = a2;
        v12[3] = 0;
        *((_BYTE *)v12 + 46) = 1;
        goto LABEL_26;
      }
      v11 = 7;
    }
    v12 = (unsigned __int64 *)(v10 + 56LL * v11);
    v13 = (unsigned __int64 *)(v10 + 56LL * (((_BYTE)v11 + 1) & 7));
    *((_BYTE *)v12 + 46) = v7 & 1;
    if ( (v7 & 1) == 0 )
    {
      if ( !a2 )
      {
        v63 = v8;
        v64 = nullptr;
        goto LABEL_35;
      }
      v14 = v10 + 56LL * (((_BYTE)v11 - 1) & 7);
      if ( *(_QWORD *)v14 >= a2 )
      {
        result = 0;
        if ( (debug_mdl & 8) == 0 || debug_priority )
          goto LABEL_138;
        v34 = *(unsigned int *)(a1 + 56);
        v35 = "no valid drv info,  req:%llu, ctx:%d";
        v36 = debug_mdl & 8;
        v37 = 671;
        goto LABEL_104;
      }
      v64 = nullptr;
      *((_DWORD *)v12 + 2) = *(_DWORD *)(v14 + 8);
      v15 = *(_QWORD *)(v14 + 32);
LABEL_34:
      v63 = v8;
      v12[4] = v15;
LABEL_35:
      if ( debug_drv )
      {
        v16 = a4;
        v17 = a3;
        v18 = a2;
        if ( (v7 & 1) != 0 )
        {
          if ( *(_BYTE *)(a4 + 1992) )
            v19 = "Y";
          else
            v19 = "N";
          if ( byte_3A857A )
            v20 = "Y";
          else
            v20 = "N";
          if ( *v64 )
            v21 = "Y";
          else
            v21 = "N";
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, _QWORD, unsigned __int64, const char *, _DWORD, const char *, _DWORD, _DWORD, _DWORD))cam_print_log)(
            3,
            0x2000000,
            3,
            "cam_isp_mgr_drv_config",
            686,
            "DRV config blob valid:%s opcode:%u req_id:%llu disable_drv_override:%s ctx_idx:%u drv_en:%s path_idle_en:0x%"
            "x timeout_val:%u, ctx:%d",
            v19,
            *(unsigned int *)(a4 + 8),
            a2,
            v20,
            *(_DWORD *)(a1 + 56),
            v21,
            v64[2],
            v64[1],
            *(_DWORD *)(a1 + 56));
          v18 = *v12;
        }
        if ( v18 == a2 )
          v22 = "Y";
        else
          v22 = "N";
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000000,
          3,
          "cam_isp_mgr_drv_config",
          692,
          "DRV per frame info: req:%llu is_valid:%s frame duration:%llu ns, vertical blanking duration:%llu ns, ctx:%d",
          a2,
          v22,
          v12[2],
          v12[3],
          *(_DWORD *)(a1 + 56));
        a3 = v17;
        a4 = v16;
      }
      v23 = debug_priority;
      if ( (v7 & 1) != 0 && (debug_mdl & 0x2000008) != 0 && !debug_priority )
      {
        v57 = "N";
        if ( *(_BYTE *)(a4 + 1992) )
          v58 = "Y";
        else
          v58 = "N";
        if ( byte_3A857A )
          v57 = "Y";
        v59 = a3;
        v60 = a4;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2000008,
          4,
          "cam_isp_mgr_drv_config",
          702,
          "DRV config blob valid:%s opcode:%u req_id:%llu disable_drv_override:%s ctx_idx:%u drv_en:%u path_idle_en:0x%x "
          "timeout_val:%u, ctx:%d",
          v58,
          *(_DWORD *)(a4 + 8),
          a2,
          v57,
          *(_DWORD *)(a1 + 56),
          *v64,
          v64[2],
          v64[1],
          *(_DWORD *)(a1 + 56));
        v23 = debug_priority;
        a4 = v60;
        a3 = v59;
        v24 = debug_mdl & 0x2000008;
        if ( (debug_mdl & 0x2000008) == 0 )
        {
LABEL_56:
          if ( (v7 & 1) != 0 && (v25 = *(_DWORD *)(a4 + 8), v25 == 1) )
          {
            LOBYTE(v65) = 1;
            *(_BYTE *)(v9 + 1793) = 1;
            if ( (*(_BYTE *)(v9 + 1793) & 1) == 0 )
            {
LABEL_59:
              if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x2000008,
                  4,
                  "cam_isp_mgr_drv_config",
                  717,
                  "Init DRV cfg hasn't received, ctx:%d",
                  *(_DWORD *)(a1 + 56));
                if ( !debug_drv )
                  goto LABEL_137;
              }
              else if ( !debug_drv )
              {
                goto LABEL_137;
              }
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x2000000,
                3,
                "cam_isp_mgr_drv_config",
                721,
                "Init DRV cfg hasn't received, ctx:%d",
                *(_DWORD *)(a1 + 56));
              goto LABEL_137;
            }
          }
          else
          {
            LOBYTE(v25) = 0;
            if ( (*(_BYTE *)(v9 + 1793) & 1) == 0 )
              goto LABEL_59;
          }
          v26 = v25 ^ 1;
          if ( *v12 != a2 )
            v26 = 0;
          if ( (v26 & 1) != 0 )
          {
            if ( a2 )
            {
              v31 = v12[3];
              if ( *v13 <= a2 )
              {
                v28 = *((_DWORD *)v12 + 2);
                v33 = 0;
                v32 = 0;
                v29 = 0;
                LODWORD(v27) = 0;
              }
              else
              {
                v29 = 0;
                v28 = *((_DWORD *)v12 + 2);
                if ( v12[2] >= v13[2] )
                  v32 = v13[2];
                else
                  v32 = v12[2];
                if ( v31 >= v13[3] )
                  v33 = v13[3];
                else
                  v33 = v12[3];
                if ( v32 <= 0xF4240 || v33 <= v12[4] )
                {
                  LODWORD(v27) = 0;
                }
                else
                {
                  v29 = 1;
                  v27 = (19200 * v32 - 19200000000LL) / 0xF4240;
                }
              }
              if ( debug_drv )
              {
                v38 = v13[2];
                v39 = v13[3];
                v40 = v13;
                v41 = a3;
                v42 = v33;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  3,
                  "cam_isp_mgr_drv_config",
                  782,
                  "[min:curr:next] frame duration:[%llu:%llu:%llu] blanking:[%llu:%llu:%llu] drv_en:%d timeout:0x%x, ctx:%d",
                  v32,
                  v12[2],
                  v38,
                  v33,
                  v31,
                  v39,
                  v29,
                  v27,
                  *(_DWORD *)(a1 + 56));
                v33 = v42;
                a3 = v41;
                v13 = v40;
              }
              v30 = 1;
              if ( (debug_mdl & 8) == 0 || debug_priority )
                goto LABEL_91;
              v61 = a3;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_isp_mgr_drv_config",
                789,
                "[min:curr:next] frame duration:[%llu:%llu:%llu] blanking:[%llu:%llu:%llu] drv_en:%d timeout:0x%x, ctx:%d",
                v32,
                v12[2],
                v13[2],
                v33,
                v12[3],
                v13[3],
                v29,
                v27,
                *(_DWORD *)(a1 + 56));
              a3 = v61;
              goto LABEL_69;
            }
          }
          else if ( (v7 & 1) != 0 )
          {
            LODWORD(v27) = v64[1];
            v28 = v64[2];
            v29 = *v64 != 0;
LABEL_69:
            v30 = 1;
LABEL_91:
            *((_BYTE *)v12 + 44) = v30;
            *((_BYTE *)v12 + 45) = v29;
            *((_DWORD *)v12 + 10) = v27;
            if ( (a3 & 1) != 0 )
            {
              LOBYTE(v43) = 0;
              if ( (debug_mdl & 8) != 0 )
              {
                v8 = v63;
                if ( !debug_priority )
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 8,
                    4,
                    "cam_isp_mgr_drv_config",
                    800,
                    "req_id:%llu force to disable drv, ctx:%d",
                    a2,
                    *(_DWORD *)(a1 + 56));
                  LOBYTE(v43) = 0;
                }
LABEL_107:
                BYTE1(v65) = v43;
                v44 = *(unsigned int *)(a1 + 8716);
                HIDWORD(v65) = v27;
                v66 = v28;
                if ( (_DWORD)v44 )
                {
                  v45 = 0;
                  v46 = (unsigned int *)(a1 + 8584);
                  do
                  {
                    if ( v45 == 11 )
                      goto LABEL_140;
                    if ( !v46[2] )
                    {
                      v47 = *v46;
                      if ( (unsigned int)v47 > 7 )
                        goto LABEL_140;
                      v48 = *(_QWORD *)(v8 + 96 + 8 * v47);
                      if ( v48 )
                      {
                        v49 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v48 + 88);
                        if ( v49 )
                        {
                          v50 = *(_QWORD *)(v48 + 112);
                          if ( *((_DWORD *)v49 - 1) != -1055839300 )
                            __break(0x8229u);
                          v51 = v49(v50, 73, &v65, 12);
                          if ( v51 )
                          {
                            v52 = *(_DWORD *)(a1 + 56);
                            v53 = v51;
                            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                              3,
                              0x2000000,
                              1,
                              "cam_isp_mgr_drv_config",
                              834,
                              "DRV config failed req_id:%d i:%d hw_idx=%d rc:%d ctx_idx: %u",
                              a2,
                              v45,
                              *v46,
                              v51,
                              v52);
                            result = v53;
                            goto LABEL_138;
                          }
                          v44 = *(unsigned int *)(a1 + 8716);
                        }
                      }
                    }
                    ++v45;
                    v46 += 3;
                  }
                  while ( v45 < v44 );
                }
LABEL_137:
                result = 0;
                goto LABEL_138;
              }
LABEL_106:
              v8 = v63;
              goto LABEL_107;
            }
            if ( (v30 & 1) != 0 )
            {
              if ( v28 )
                v43 = v29;
              else
                v43 = 0;
              if ( v43 )
                *(_DWORD *)(a1 + 9464) = v28;
              else
                LOBYTE(v43) = 0;
              goto LABEL_106;
            }
            result = 0;
            if ( (debug_mdl & 8) == 0 || debug_priority )
              goto LABEL_138;
            v34 = *(unsigned int *)(a1 + 56);
            v35 = "req_id:%llu no need to update drv, ctx:%d";
            v36 = debug_mdl & 8;
            v37 = 805;
LABEL_104:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64, __int64))cam_print_log)(
              3,
              v36,
              4,
              "cam_isp_mgr_drv_config",
              v37,
              v35,
              a2,
              v34);
            goto LABEL_137;
          }
          v29 = 0;
          v30 = 0;
          LODWORD(v27) = 0;
          v28 = 0;
          goto LABEL_91;
        }
      }
      else
      {
        v24 = debug_mdl & 0x2000008;
        if ( (debug_mdl & 0x2000008) == 0 )
          goto LABEL_56;
      }
      if ( !v23 )
      {
        if ( *v12 == a2 )
          v55 = "Y";
        else
          v55 = "N";
        v62 = a3;
        v56 = a4;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v24,
          4,
          "cam_isp_mgr_drv_config",
          707,
          "DRV per frame info: req:%llu is_valid:%s frame duration:%llu ns, vertical blanking duration:%llu ns, ctx:%d",
          a2,
          v55,
          v12[2],
          v12[3],
          *(_DWORD *)(a1 + 56));
        a3 = v62;
        a4 = v56;
      }
      goto LABEL_56;
    }
LABEL_26:
    v64 = (_DWORD *)(a4 + 1952);
    *((_BYTE *)v12 + 48) = *(_BYTE *)(a4 + 4288);
    *((_DWORD *)v12 + 2) = *(_DWORD *)(a4 + 1960);
    if ( !*(_DWORD *)(a4 + 1964) || (*(_BYTE *)(a4 + 1968) & 1) == 0 )
    {
      v63 = v8;
      goto LABEL_35;
    }
    v15 = 1000000LL * *(unsigned int *)(a4 + 1972);
    goto LABEL_34;
  }
  result = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_mgr_drv_config",
      587,
      "Skipping DRV config. drv_support: %d, drv_disable %d",
      (unsigned __int8)byte_3A88D4,
      (unsigned __int8)byte_3A857A);
    goto LABEL_137;
  }
LABEL_138:
  _ReadStatusReg(SP_EL0);
  return result;
}
