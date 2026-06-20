__int64 __fastcall cam_vfe_top_ver4_pdaf_lcr_config(__int64 a1, __int64 *a2)
{
  __int64 v2; // x8
  __int64 *v3; // x20
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x21
  unsigned int **v7; // x24
  __int64 v8; // x22
  unsigned int v9; // w8
  __int64 v10; // x6
  const char *v11; // x5
  __int64 v12; // x4
  __int64 (__fastcall *v13)(_QWORD); // x9
  unsigned int v16; // w19
  unsigned int v17; // w0
  __int64 *v18; // x8
  unsigned __int64 v19; // x7
  unsigned __int64 v20; // x23
  __int64 v22; // x9
  int v23; // w10
  unsigned int v24; // w11
  __int64 v25; // x0
  __int64 v26; // x9
  __int64 *v27; // x20
  _DWORD *v28; // x9
  __int64 v29; // [xsp+8h] [xbp-18h] BYREF
  __int64 v30; // [xsp+10h] [xbp-10h]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a2;
  v29 = 0;
  v30 = 0;
  if ( !v2 )
  {
    v10 = *(unsigned int *)(a1 + 1092);
    v11 = "VFE:%u Error, Invalid res";
    v12 = 174;
    goto LABEL_13;
  }
  v3 = *(__int64 **)(a1 + 16);
  v4 = *((unsigned int *)v3 + 52);
  if ( !(_DWORD)v4 || (v5 = v3[25]) == 0 )
  {
    v9 = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_top_ver4_pdaf_lcr_config",
        180,
        "VFE:%u PDAF LCR is not supported",
        *(_DWORD *)(a1 + 1092));
      v9 = 0;
    }
    goto LABEL_25;
  }
  v6 = *(_QWORD *)(v2 + 48);
  if ( !v6 )
  {
    v10 = *(unsigned int *)(a1 + 1092);
    v11 = "VFE:%u Invalid CDM ops";
    v12 = 188;
LABEL_13:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_pdaf_lcr_config",
      v12,
      v11,
      v10);
LABEL_24:
    v9 = -22;
    goto LABEL_25;
  }
  v7 = (unsigned int **)a2[5];
  v8 = 0;
  while ( *((_DWORD *)v7 + 2) != *(_DWORD *)(v5 + v8) )
  {
    --v4;
    v8 += 8;
    if ( !v4 )
      goto LABEL_23;
  }
  if ( !(_DWORD)v4 )
  {
LABEL_23:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, __int64, __int64, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_pdaf_lcr_config",
      199,
      "VFE:%u Res :%d src_res :%u is not supported for mux",
      *(unsigned int *)(a1 + 1092),
      **v7,
      *((_DWORD *)v7 + 2),
      v29,
      v30,
      v31);
    goto LABEL_24;
  }
  v13 = *(__int64 (__fastcall **)(_QWORD))(v6 + 24);
  if ( *((_BYTE *)v7 + 12) )
    v16 = 2;
  else
    v16 = 1;
  if ( *((_DWORD *)v13 - 1) != 2010610996 )
    __break(0x8229u);
  v17 = v13(v16);
  v18 = a2;
  v19 = *((unsigned int *)a2 + 6);
  v20 = 4LL * v17;
  if ( v20 > v19 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, unsigned __int64, unsigned __int64, __int64, __int64, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_pdaf_lcr_config",
      212,
      "VFE:%u buf size:%d is not sufficient, expected: %d",
      *(unsigned int *)(a1 + 1092),
      v19,
      v20,
      v29,
      v30,
      v31);
    goto LABEL_24;
  }
  v22 = *v3;
  v23 = *((_DWORD *)v3 + 64);
  if ( (*((_BYTE *)v7 + 12) & 1) != 0 )
  {
    v29 = (unsigned int)(*(_DWORD *)(v22 + 748) + v23);
    v24 = 2;
  }
  else
  {
    v24 = 0;
  }
  v25 = v18[2];
  *((_DWORD *)&v29 + v24) = *(_DWORD *)(v22 + 744) + v23;
  v26 = v3[25];
  v27 = v18;
  *((_DWORD *)&v29 + (v24 | 1)) = *(_DWORD *)(v26 + v8 + 4);
  v28 = *(_DWORD **)(v6 + 120);
  if ( *(v28 - 1) != -1401492769 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64, _QWORD, __int64 *))v28)(v25, v16, &v29);
  v9 = 0;
  *((_DWORD *)v27 + 7) = v20;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return v9;
}
