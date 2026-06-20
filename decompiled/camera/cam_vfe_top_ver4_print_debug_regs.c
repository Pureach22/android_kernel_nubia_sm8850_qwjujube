__int64 __fastcall cam_vfe_top_ver4_print_debug_regs(_QWORD *a1)
{
  char v1; // w8
  bool v2; // zf
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x19
  __int64 v6; // x11
  __int64 v7; // x10
  __int64 v8; // x9
  const char *v9; // x22
  __int64 v10; // x9
  __int64 v11; // x26
  __int64 v12; // x27
  __int64 v13; // x21
  __int64 v14; // x20
  unsigned int v15; // w0
  __int64 v16; // x6
  char v17; // w24
  __int64 v18; // x20
  unsigned int v19; // w22
  __int64 v20; // x27
  unsigned __int64 v21; // x28
  __int64 v22; // x20
  char v23; // w8
  __int64 v24; // x9
  unsigned __int64 v25; // x23
  char v26; // w27
  __int64 v27; // x25
  __int64 v28; // x8
  int v29; // w0
  unsigned int v30; // w8
  char v31; // w9
  bool v32; // w10
  const char *v33; // x8
  size_t v34; // x21
  size_t v35; // x0
  size_t v36; // x2
  __int64 v37; // x19
  __int64 v38; // x0
  __int64 result; // x0
  const char *v40; // [xsp+10h] [xbp-5F0h]
  char v41; // [xsp+1Ch] [xbp-5E4h]
  __int64 v42; // [xsp+20h] [xbp-5E0h]
  __int64 v43; // [xsp+28h] [xbp-5D8h]
  __int64 v44; // [xsp+30h] [xbp-5D0h]
  __int64 v45; // [xsp+38h] [xbp-5C8h]
  bool v46; // [xsp+44h] [xbp-5BCh]
  unsigned __int64 v48; // [xsp+50h] [xbp-5B0h] BYREF
  _QWORD v49[19]; // [xsp+58h] [xbp-5A8h] BYREF
  char s[1024]; // [xsp+F0h] [xbp-510h] BYREF
  char string[8]; // [xsp+4F0h] [xbp-110h] BYREF
  __int64 v52; // [xsp+4F8h] [xbp-108h]
  __int64 v53; // [xsp+500h] [xbp-100h]
  __int64 v54; // [xsp+508h] [xbp-F8h]
  __int64 v55; // [xsp+510h] [xbp-F0h]
  __int64 v56; // [xsp+518h] [xbp-E8h]
  __int64 v57; // [xsp+520h] [xbp-E0h]
  __int64 v58; // [xsp+528h] [xbp-D8h]
  __int64 v59; // [xsp+530h] [xbp-D0h]
  __int64 v60; // [xsp+538h] [xbp-C8h]
  __int64 v61; // [xsp+540h] [xbp-C0h]
  __int64 v62; // [xsp+548h] [xbp-B8h]
  __int64 v63; // [xsp+550h] [xbp-B0h]
  __int64 v64; // [xsp+558h] [xbp-A8h]
  __int64 v65; // [xsp+560h] [xbp-A0h]
  __int64 v66; // [xsp+568h] [xbp-98h]
  __int64 v67; // [xsp+570h] [xbp-90h]
  __int64 v68; // [xsp+578h] [xbp-88h]
  __int64 v69; // [xsp+580h] [xbp-80h]
  __int64 v70; // [xsp+588h] [xbp-78h]
  __int64 v71; // [xsp+590h] [xbp-70h]
  __int64 v72; // [xsp+598h] [xbp-68h]
  __int64 v73; // [xsp+5A0h] [xbp-60h]
  __int64 v74; // [xsp+5A8h] [xbp-58h]
  __int64 v75; // [xsp+5B0h] [xbp-50h]
  __int64 v76; // [xsp+5B8h] [xbp-48h]
  __int64 v77; // [xsp+5C0h] [xbp-40h]
  __int64 v78; // [xsp+5C8h] [xbp-38h]
  __int64 v79; // [xsp+5D0h] [xbp-30h]
  __int64 v80; // [xsp+5D8h] [xbp-28h]
  __int64 v81; // [xsp+5E0h] [xbp-20h]
  __int64 v82; // [xsp+5E8h] [xbp-18h]
  __int64 v83; // [xsp+5F0h] [xbp-10h]

  v1 = 1;
  v40 = (char *)a1 + 10516;
  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  do
  {
    v41 = v1;
    v2 = (v1 & 1) == 0;
    v3 = 768;
    v4 = a1[1];
    v48 = 0;
    if ( !v2 )
      v3 = 760;
    v5 = *(_QWORD *)(v4 + v3);
    memset(&v49[15], 0, 32);
    if ( v2 )
      v6 = 96;
    else
      v6 = 88;
    v7 = 752;
    if ( v2 )
      v7 = 756;
    v8 = 264;
    v49[13] = 0;
    v49[14] = 0;
    if ( !v2 )
      v8 = 256;
    v45 = v8;
    if ( v2 )
      v9 = "BAYER";
    else
      v9 = "TOP";
    memset(v49, 0, 104);
    if ( v5 )
    {
      v10 = a1[2];
      v11 = *(_QWORD *)(v10 + v6);
      if ( v11 )
      {
        v12 = *(unsigned int *)(v4 + v7);
        v44 = a1[1304];
        if ( (_DWORD)v12 )
        {
          v13 = 0;
          v14 = *(_QWORD *)(v44 + 288) + *(_QWORD *)(v10 + v45);
          do
          {
            v15 = cam_io_r(v14 + *(unsigned int *)(v5 + 4 * v13));
            if ( v13 == 19 )
              goto LABEL_67;
            v16 = *(unsigned int *)(v44 + 20);
            v49[v13] = v15;
            cam_print_to_buffer(
              (__int64)v40,
              0x100u,
              &v48,
              3u,
              8u,
              "VFE[%u] status %2d : 0x%08x",
              v16,
              (unsigned int)v13++,
              v15);
          }
          while ( v12 != v13 );
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          3,
          "cam_vfe_top_ver4_print_debug_reg_status",
          666,
          "VFE[%u]: %s Debug Status: %s",
          *(_DWORD *)(v44 + 20),
          v9,
          v40);
        v82 = 0;
        v81 = 0;
        v80 = 0;
        v79 = 0;
        v78 = 0;
        v77 = 0;
        v76 = 0;
        v75 = 0;
        v74 = 0;
        v73 = 0;
        v72 = 0;
        v71 = 0;
        v70 = 0;
        v69 = 0;
        v68 = 0;
        v67 = 0;
        v66 = 0;
        v65 = 0;
        v64 = 0;
        v63 = 0;
        v62 = 0;
        v61 = 0;
        v60 = 0;
        v59 = 0;
        v58 = 0;
        v57 = 0;
        v56 = 0;
        v55 = 0;
        v54 = 0;
        v53 = 0;
        v52 = 0;
        *(_QWORD *)string = 0;
        memset(s, 0, sizeof(s));
        if ( (_DWORD)v12 )
        {
          v17 = 0;
          v18 = 0;
          v19 = 0;
          v46 = 0;
          v43 = v12;
          do
          {
            if ( v18 == 19 || (v18 & 0x1FFFFFFFFFFFFFFFLL) == 0x13 )
              goto LABEL_66;
            v21 = v49[v18];
            if ( v21 == 1431655765 )
            {
              v20 = v43;
            }
            else
            {
              v42 = v18;
              v22 = 0;
              v23 = 0;
              do
              {
                v24 = v11 + v22;
                v25 = v21 >> *(_DWORD *)(v11 + v22);
                if ( (v25 & 0xF) != 5 )
                {
                  v26 = *(_BYTE *)(v24 + 24);
                  if ( a1 )
                  {
                    if ( v24 )
                    {
                      v27 = v11 + v22;
                      v28 = *(unsigned int *)(v11 + v22 + 16);
                      if ( (_DWORD)v28 )
                      {
                        if ( *(_DWORD *)(v27 + 20) )
                        {
                          v29 = cam_io_r_mb(*(_QWORD *)(a1[1304] + 288LL) + *(_QWORD *)(a1[2] + v45) + v28);
                          v30 = *(_DWORD *)(v27 + 20);
                          v31 = __clz(__rbit32(v30));
                          if ( v30 )
                          {
                            v32 = (v30 & (v30 - 1)) != 0;
                          }
                          else
                          {
                            v31 = -1;
                            v32 = 1;
                          }
                          v46 = v32;
                          v19 = (v30 & v29) >> v31;
                        }
                      }
                    }
                  }
                  v33 = "N";
                  if ( v46 )
                    v33 = "Y";
                  snprintf(
                    string,
                    0x100u,
                    "\n\t%s [I:%llu V:%llu R:%llu] idle: 0x%x, is_mc: %s",
                    *(const char **)(v11 + v22 + 8),
                    (v25 >> 2) & 1,
                    (v25 >> 1) & 1,
                    v25 & 1,
                    v19,
                    v33);
                  v34 = strnlen(s, 0x400u);
                  if ( v34 >= 0x401 )
                    goto LABEL_64;
                  v35 = strnlen(string, 0x100u);
                  if ( v35 >= 0x101 )
                    goto LABEL_65;
                  if ( v35 == 256 )
                  {
                    _fortify_panic(4, 256, 257);
LABEL_64:
                    v35 = _fortify_panic(2, 1024, v34 + 1);
LABEL_65:
                    _fortify_panic(2, 256, v35 + 1);
LABEL_66:
                    __break(1u);
LABEL_67:
                    __break(0x5512u);
                  }
                  v17 |= ((v25 & 1) == 0) & v26;
                  if ( v34 != 1024 )
                  {
                    if ( v35 + v34 >= 0x400 )
                      v36 = 1023 - v34;
                    else
                      v36 = v35;
                    if ( v35 + v34 >= 0x400 )
                      v37 = 1023;
                    else
                      v37 = v35 + v34;
                    memcpy(&s[v34], string, v36);
                    s[v37] = 0;
                  }
                  v23 = 1;
                }
                v22 += 32;
              }
              while ( v22 != 256 );
              v18 = v42;
              v20 = v43;
              if ( (v23 & 1) != 0 )
              {
                if ( (unsigned int)__ratelimit(
                                     &cam_vfe_top_ver4_check_module_status__rs,
                                     "cam_vfe_top_ver4_check_module_status") )
                  v38 = 3;
                else
                  v38 = 2;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  v38,
                  8,
                  3,
                  "cam_vfe_top_ver4_check_module_status",
                  550,
                  "Check config for Debug%u - %s",
                  v42,
                  s);
              }
              memset(s, 0, sizeof(s));
            }
            ++v18;
            v11 += 256;
          }
          while ( v18 != v20 );
          if ( (v17 & 1) != 0 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              2,
              "cam_vfe_top_ver4_print_debug_reg_status",
              673,
              "VFE[%u] Module status points to possible Bus Overflow",
              *(_DWORD *)(v44 + 20));
        }
      }
    }
    v1 = 0;
  }
  while ( (v41 & 1) != 0 );
  result = cam_vfe_top_dump_perf_counters("ERROR", &unk_3E455A, a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
