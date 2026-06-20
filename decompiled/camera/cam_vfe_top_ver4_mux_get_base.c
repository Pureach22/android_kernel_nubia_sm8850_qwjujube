__int64 __fastcall cam_vfe_top_ver4_mux_get_base(__int64 a1, _DWORD *a2, int a3)
{
  __int64 v3; // x9
  __int64 v4; // x22
  __int64 v5; // x19
  __int64 (*v6)(void); // x8
  unsigned int v9; // w20
  __int64 v10; // x6
  const char *v11; // x5
  __int64 v12; // x4
  const char *v13; // x5
  __int64 v14; // x4
  _DWORD *v16; // x10
  __int64 v17; // x1
  int v18; // w8
  _DWORD *v19; // x9
  int v20; // w12
  void (__fastcall *v21)(__int64, __int64); // x8
  __int64 v22; // x0
  _DWORD *v23; // x19
  unsigned int v24; // [xsp+2Ch] [xbp+1Ch]

  if ( a3 != 56 )
  {
    v13 = "Error, Invalid cmd size";
    v14 = 241;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_mux_get_base",
      v14,
      v13);
    return 4294967274LL;
  }
  if ( !*(_QWORD *)a2 || (v3 = *(_QWORD *)(a1 + 10432)) == 0 )
  {
    v13 = "Error, Invalid args";
    v14 = 247;
    goto LABEL_12;
  }
  v4 = *(_QWORD *)(v3 + 3296);
  if ( !v4 )
  {
    v10 = *(unsigned int *)(a1 + 1092);
    v11 = "VFE:%u soc_private is null";
    v12 = 253;
    goto LABEL_29;
  }
  v5 = *(_QWORD *)(*(_QWORD *)a2 + 48LL);
  if ( !v5 )
  {
    v10 = *(unsigned int *)(a1 + 1092);
    v11 = "VFE:%u Invalid CDM ops";
    v12 = 261;
    goto LABEL_29;
  }
  v6 = *(__int64 (**)(void))(v5 + 56);
  if ( *((_DWORD *)v6 - 1) != -605791253 )
    __break(0x8228u);
  v9 = 4 * v6();
  if ( v9 > a2[6] )
  {
    v10 = *(unsigned int *)(a1 + 1092);
    v11 = "VFE:%u buf size:%d is not sufficient, expected: %d";
    v12 = 269;
LABEL_29:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_mux_get_base",
      v12,
      v11,
      v10);
    return 4294967274LL;
  }
  v16 = *(_DWORD **)(a1 + 10432);
  if ( !v16 || !v16[120] || (v17 = (unsigned int)v16[74], (_DWORD)v17 == -1) )
  {
    v11 = "failed to get mem_base, index: %d num_reg_map: %u";
    v12 = 277;
    v10 = 0;
    goto LABEL_29;
  }
  v18 = a2[3];
  v19 = a2;
  if ( v18 == 10 )
  {
    v20 = *(_DWORD *)(v4 + 8);
    if ( !v20 )
    {
      v10 = *(unsigned int *)(a1 + 1092);
      v11 = "VFE:%u rt_wrapper_base_addr is null";
      v12 = 284;
      goto LABEL_29;
    }
    v17 = (unsigned int)(v17 - v20);
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v24 = v17;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_top_ver4_mux_get_base",
      293,
      "core %u mem_base 0x%x, cdm_id: %u",
      v16[5],
      v17,
      v18);
    v17 = v24;
    v19 = a2;
  }
  v21 = *(void (__fastcall **)(__int64, __int64))(v5 + 152);
  v22 = *((_QWORD *)v19 + 2);
  v23 = v19;
  if ( *((_DWORD *)v21 - 1) != 557450195 )
    __break(0x8228u);
  v21(v22, v17);
  v23[7] = v9;
  return 0;
}
