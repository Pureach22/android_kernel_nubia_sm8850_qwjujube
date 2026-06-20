__int64 __fastcall cam_vfe_top_ver3_mux_get_base(__int64 a1, _DWORD *a2, int a3)
{
  __int64 v3; // x19
  __int64 (*v4)(void); // x8
  unsigned int v7; // w20
  const char *v8; // x5
  __int64 v9; // x4
  _DWORD *v11; // x9
  int v12; // w1
  _DWORD *v13; // x8
  void (__fastcall *v14)(_QWORD); // x9
  __int64 v15; // x0
  _DWORD *v16; // x19

  if ( a3 != 56 )
  {
    v8 = "Error, Invalid cmd size";
    v9 = 59;
    goto LABEL_11;
  }
  if ( !*(_QWORD *)a2 || !*(_QWORD *)(a1 + 10432) )
  {
    v8 = "Error, Invalid args";
    v9 = 65;
    goto LABEL_11;
  }
  v3 = *(_QWORD *)(*(_QWORD *)a2 + 48LL);
  if ( !v3 )
  {
    v8 = "Invalid CDM ops";
    v9 = 73;
    goto LABEL_11;
  }
  v4 = *(__int64 (**)(void))(v3 + 56);
  if ( *((_DWORD *)v4 - 1) != -605791253 )
    __break(0x8228u);
  v7 = 4 * v4();
  if ( v7 > a2[6] )
  {
    v8 = "buf size:%d is not sufficient, expected: %d";
    v9 = 81;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver3_mux_get_base",
      v9,
      v8);
    return 4294967274LL;
  }
  v11 = *(_DWORD **)(a1 + 10432);
  if ( !v11 || !v11[120] || (v12 = v11[74], v12 == -1) )
  {
    v8 = "failed to get mem_base, index: %d num_reg_map: %u";
    v9 = 89;
    goto LABEL_11;
  }
  v13 = a2;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_top_ver3_mux_get_base",
      93,
      "core %d mem_base 0x%x",
      v11[5],
      v12);
    v13 = a2;
  }
  v14 = *(void (__fastcall **)(_QWORD))(v3 + 152);
  v15 = *((_QWORD *)v13 + 2);
  v16 = v13;
  if ( *((_DWORD *)v14 - 1) != 557450195 )
    __break(0x8229u);
  v14(v15);
  v16[7] = v7;
  return 0;
}
