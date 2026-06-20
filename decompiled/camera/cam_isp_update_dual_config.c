__int64 __fastcall cam_isp_update_dual_config(
        int *a1,
        int a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        unsigned int a6)
{
  __int64 result; // x0
  unsigned __int64 v13; // x9
  size_t v14; // x6
  unsigned __int64 v15; // x25
  char *v16; // x1
  unsigned int v17; // w20
  unsigned int v18; // w0
  unsigned int *v19; // x27
  __int64 v20; // x7
  unsigned __int64 v21; // x25
  __int64 v22; // x6
  __int64 v23; // x28
  __int64 v24; // x8
  __int64 v25; // x8
  unsigned int v26; // w9
  __int64 v27; // x9
  __int64 (__fastcall *v28)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v29; // x0
  unsigned int v30; // w0
  __int64 v31; // x8
  __int64 v32; // x8
  unsigned int v33; // w9
  __int64 v35; // x9
  __int64 (__fastcall *v36)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v37; // x0
  const char *v38; // x5
  __int64 v39; // x4
  unsigned int *v40; // [xsp+8h] [xbp-38h] BYREF
  char *v41; // [xsp+10h] [xbp-30h] BYREF
  unsigned __int64 v42; // [xsp+18h] [xbp-28h] BYREF
  __int64 v43; // [xsp+20h] [xbp-20h] BYREF
  __int64 v44; // [xsp+28h] [xbp-18h]
  unsigned int *v45; // [xsp+30h] [xbp-10h]
  __int64 v46; // [xsp+38h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  v45 = nullptr;
  v42 = 0;
  v43 = 0;
  v40 = nullptr;
  v41 = nullptr;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_update_dual_config",
      166,
      "cmd des size %d, length: %d",
      a1[2],
      a1[3]);
  result = cam_packet_util_get_cmd_mem_addr(*a1, &v41, &v42);
  if ( !(_DWORD)result )
  {
    if ( v42 < 0x28 || (v13 = (unsigned int)a1[1], v42 - 40 <= v13) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_update_dual_config",
        176,
        "not enough buffer provided");
      goto LABEL_10;
    }
    v14 = (unsigned int)a1[3];
    v15 = v42 - v13;
    v16 = &v41[v13 & 0xFFFFFFFC];
    v41 = v16;
    if ( v42 - v13 < v14 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_update_dual_config",
        194,
        "Invalid packet header size %u",
        v14);
LABEL_10:
      v17 = -22;
LABEL_11:
      cam_mem_put_cpu_buf(*a1);
      result = v17;
      goto LABEL_12;
    }
    v18 = cam_common_mem_kdup(&v40, v16, v14);
    if ( v18 )
    {
      v17 = v18;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_update_dual_config",
        189,
        "Alloc and copy cmd desc fail");
      goto LABEL_11;
    }
    v19 = v40;
    v20 = *v40;
    if ( v15 - 24 >= 16 * v20 )
    {
      if ( !(_DWORD)v20 )
      {
LABEL_44:
        v17 = 0;
LABEL_49:
        cam_common_mem_free((__int64)v40);
        goto LABEL_11;
      }
      v21 = 0;
      v22 = (unsigned __int8)a6;
      v23 = 9;
      while ( v22 != v21 )
      {
        if ( v19[v23] )
        {
          v24 = a3 + ((unsigned __int64)*(unsigned __int8 *)(a4 + (unsigned __int8)v19[v23]) << 7);
          if ( !v24 )
            goto LABEL_45;
          v25 = *(_QWORD *)(v24 + 32);
          if ( v25 )
          {
            if ( *(_DWORD *)(*(_QWORD *)(v25 + 16) + 4LL) == a2 )
            {
              v26 = *(_DWORD *)(v25 + 4);
              if ( v26 >= a5 && v26 < a6 )
              {
                v44 = v25;
                v45 = v19;
                v27 = *(_QWORD *)(v25 + 16);
                LODWORD(v43) = 0;
                v28 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v27 + 88);
                v29 = *(_QWORD *)(v27 + 112);
                if ( *((_DWORD *)v28 - 1) != -1055839300 )
                  __break(0x8228u);
                v30 = v28(v29, 8, &v43, 24);
                if ( v30 )
                {
LABEL_43:
                  v17 = v30;
                  goto LABEL_49;
                }
                v20 = *v19;
                v22 = (unsigned __int8)a6;
              }
            }
          }
        }
        if ( v19[4 * (unsigned int)(3 * (v21 + v20)) + 9] )
        {
          v31 = a3
              + ((unsigned __int64)*(unsigned __int8 *)(a4
                                                      + (unsigned __int8)v19[4 * (unsigned int)(3 * (v21 + v20)) + 9]) << 7);
          if ( !v31 )
          {
LABEL_45:
            v38 = "Invalid isp out resource i %d num_out_res %d";
            v39 = 230;
            v22 = (unsigned int)v21;
            goto LABEL_47;
          }
          v32 = *(_QWORD *)(v31 + 40);
          if ( v32 && *(_DWORD *)(*(_QWORD *)(v32 + 16) + 4LL) == a2 )
          {
            v33 = *(_DWORD *)(v32 + 4);
            if ( v33 >= a5 && v33 < a6 )
            {
              v44 = v32;
              v45 = v19;
              v35 = *(_QWORD *)(v32 + 16);
              v36 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v35 + 88);
              v37 = *(_QWORD *)(v35 + 112);
              LODWORD(v43) = 1;
              if ( *((_DWORD *)v36 - 1) != -1055839300 )
                __break(0x8228u);
              v30 = v36(v37, 8, &v43, 24);
              if ( v30 )
                goto LABEL_43;
              v20 = *v19;
              v22 = (unsigned __int8)a6;
            }
          }
        }
        ++v21;
        v23 += 12;
        if ( v21 >= (unsigned int)v20 )
          goto LABEL_44;
      }
      v38 = "failed update for i:%d > size_isp_out:%d";
      v39 = 213;
      v20 = (unsigned int)v22;
LABEL_47:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_update_dual_config",
        v39,
        v38,
        v22,
        v20);
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_update_dual_config",
        203,
        "not enough buffer for all the dual configs");
    }
    v17 = -22;
    goto LABEL_49;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
