__int64 __fastcall cam_cpas_hw_set_addr_trans(__int64 a1, unsigned int *a2)
{
  _DWORD *v2; // x25
  __int64 v3; // x19
  __int64 v4; // x21
  __int64 v5; // x26
  unsigned int v6; // w22
  __int64 v7; // x8
  unsigned __int8 *v8; // x24
  _DWORD *v10; // x20
  __int64 v11; // x7
  const char *v12; // x5
  __int64 v13; // x4
  __int64 result; // x0
  unsigned int v15; // w21
  unsigned __int64 v16; // x27
  __int64 v17; // x25
  __int64 v18; // x26
  __int64 v19; // x19
  size_t v20; // x0
  size_t v21; // x2
  __int64 v22; // x8
  unsigned int *v23; // x23
  __int64 v24; // x22
  __int64 v25; // x8
  const char *v26; // x5
  __int64 v27; // x1
  __int64 v28; // x4
  __int64 v29; // x0
  __int64 v30; // x1
  __int64 v31; // x2
  __int64 v32; // x3
  __int64 v33; // x4
  __int64 v34; // x5
  char s[8]; // [xsp+10h] [xbp-90h] BYREF
  __int64 v36; // [xsp+18h] [xbp-88h]
  __int64 v37; // [xsp+20h] [xbp-80h]
  __int64 v38; // [xsp+28h] [xbp-78h]
  __int64 v39; // [xsp+30h] [xbp-70h]
  __int64 v40; // [xsp+38h] [xbp-68h]
  __int64 v41; // [xsp+40h] [xbp-60h]
  __int64 v42; // [xsp+48h] [xbp-58h]
  __int64 v43; // [xsp+50h] [xbp-50h]
  __int64 v44; // [xsp+58h] [xbp-48h]
  __int64 v45; // [xsp+60h] [xbp-40h]
  __int64 v46; // [xsp+68h] [xbp-38h]
  __int64 v47; // [xsp+70h] [xbp-30h]
  __int64 v48; // [xsp+78h] [xbp-28h]
  __int64 v49; // [xsp+80h] [xbp-20h]
  _BYTE v50[11]; // [xsp+88h] [xbp-18h] BYREF
  __int64 v51; // [xsp+98h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD **)(a1 + 3680);
  v3 = *a2;
  v4 = *((_QWORD *)a2 + 1);
  v5 = *(_QWORD *)(a1 + 3392);
  v6 = v2[709];
  v49 = 0;
  memset(v50, 0, sizeof(v50));
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  *(_QWORD *)s = 0;
  v36 = 0;
  v7 = *(_QWORD *)(*(_QWORD *)v2 + 24LL);
  if ( !v7 )
  {
    v12 = "Invalid cam noc info for %s";
    v13 = 677;
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_set_addr_trans",
      v13,
      v12,
      "CAMNOC_NRT");
    goto LABEL_11;
  }
  v8 = *(unsigned __int8 **)(v7 + 72);
  if ( !v8 )
  {
    v12 = "Invalid address translator information, camnoc name: %s";
    v13 = 684;
    goto LABEL_10;
  }
  if ( (unsigned int)v3 > 0x2A )
  {
LABEL_11:
    result = 4294967274LL;
    goto LABEL_12;
  }
  v10 = &v2[12 * (unsigned int)v3];
  mutex_lock(v10 + 166);
  v11 = *(_QWORD *)&v2[2 * v3 + 80];
  if ( *(_BYTE *)(v11 + 168) == 1 && (*(_BYTE *)(v11 + 169) & 1) != 0 )
  {
    if ( *(_BYTE *)(v5 + 8) == 1 )
      snprintf(s, 0x83u, "%s%d", *(const char **)&v2[2 * v3 + 80], *(_DWORD *)(v11 + 128));
    else
      snprintf(s, 0x83u, "%s", *(const char **)&v2[2 * v3 + 80]);
    if ( *v8 )
    {
      v16 = 0;
      v17 = 36;
      while ( 1 )
      {
        v18 = *((_QWORD *)v8 + 1);
        v19 = *(_QWORD *)(v18 + v17 - 36);
        v20 = strnlen(s, 0x83u);
        v21 = v20;
        if ( v20 >= 0x84 )
          goto LABEL_37;
        if ( v20 == 131 )
        {
          _fortify_panic(4, 131, 132);
LABEL_37:
          v29 = _fortify_panic(2, 131, v21 + 1);
          return cam_cpas_hw_reg_write(v29, v30, v31, v32, v33, v34);
        }
        if ( strnstr(s, v19, v20) )
          break;
        ++v16;
        v17 += 40;
        if ( v16 >= *v8 )
          goto LABEL_22;
      }
      v22 = a1;
      if ( (debug_mdl & 4) == 0 || debug_priority )
      {
        if ( v6 <= 7 )
          goto LABEL_26;
LABEL_35:
        __break(0x5512u);
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpas_hw_set_addr_trans",
        716,
        "Found corresponding client %s that supports address translate",
        s);
      v22 = a1;
      if ( v6 > 7 )
        goto LABEL_35;
LABEL_26:
      v23 = (unsigned int *)(v18 + v17);
      v24 = *(_QWORD *)(v22 + 24LL * v6 + 384);
      v25 = *(unsigned int *)(v18 + v17 - 28);
      if ( *(_BYTE *)v4 == 1 )
      {
        cam_io_w_mb(1, v24 + v25);
        cam_io_w_mb(*(unsigned int *)(v4 + 4), v24 + *(v23 - 6));
        cam_io_w_mb(*(unsigned int *)(v4 + 8), v24 + *(v23 - 5));
        cam_io_w_mb(*(unsigned int *)(v4 + 12), v24 + *(v23 - 4));
        cam_io_w_mb(*(unsigned int *)(v4 + 16), v24 + *(v23 - 3));
        cam_io_w_mb(*(unsigned int *)(v4 + 20), v24 + *(v23 - 2));
        cam_io_w_mb(*(unsigned int *)(v4 + 24), v24 + *(v23 - 1));
        cam_io_w_mb(*(unsigned int *)(v4 + 28), v24 + *v23);
        v15 = 0;
        if ( (debug_mdl & 4) != 0 && !debug_priority )
        {
          v26 = "Enabled address translator for %s";
          v27 = debug_mdl & 4;
          v28 = 740;
LABEL_33:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, char *))cam_print_log)(
            3,
            v27,
            4,
            "cam_cpas_hw_set_addr_trans",
            v28,
            v26,
            s);
          v15 = 0;
        }
      }
      else
      {
        cam_io_w_mb(0, v24 + v25);
        v15 = 0;
        if ( (debug_mdl & 4) != 0 && !debug_priority )
        {
          v26 = "Disabled address translator for %s";
          v27 = debug_mdl & 4;
          v28 = 744;
          goto LABEL_33;
        }
      }
    }
    else
    {
LABEL_22:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_hw_set_addr_trans",
        752,
        "No address translator support for this client: %s",
        s);
      v15 = -22;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_set_addr_trans",
      697,
      "client=[%d][%s][%d] has not started",
      v3,
      (const char *)v11,
      *(_DWORD *)(v11 + 128));
    v15 = -1;
  }
  mutex_unlock(v10 + 166);
  result = v15;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
