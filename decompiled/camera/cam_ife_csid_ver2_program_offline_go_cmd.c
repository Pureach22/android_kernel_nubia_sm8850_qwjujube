__int64 __fastcall cam_ife_csid_ver2_program_offline_go_cmd(__int64 a1, __int64 *a2, int a3)
{
  __int64 v4; // x21
  __int64 (__fastcall *v5)(_QWORD); // x8
  unsigned int v7; // w20
  const char *v8; // x5
  __int64 v9; // x6
  __int64 v10; // x4
  __int64 result; // x0
  int v12; // w8
  _DWORD *v13; // x8
  __int64 v14; // x0
  _DWORD v15[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 != 24 )
  {
    v8 = "CSID[%u] Invalid arg size: %d expected:%ld";
    v9 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
    v10 = 8034;
    goto LABEL_8;
  }
  v4 = *(_QWORD *)(a2[2] + 48);
  if ( !v4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_program_offline_go_cmd",
      8041,
      "CSID[%u] Invalid CDM ops",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL));
    result = 4294967274LL;
    goto LABEL_16;
  }
  v5 = *(__int64 (__fastcall **)(_QWORD))(v4 + 24);
  if ( *((_DWORD *)v5 - 1) != 2010610996 )
    __break(0x8228u);
  v7 = 4 * v5(1);
  if ( v7 > *((_DWORD *)a2 + 2) )
  {
    v8 = "CSID[%u] buf size:%d is not sufficient, expected: %d";
    v9 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
    v10 = 8049;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_program_offline_go_cmd",
      v10,
      v8,
      v9);
    result = 4294967274LL;
    goto LABEL_16;
  }
  v12 = *(_DWORD *)(*(_QWORD *)(**(_QWORD **)(a1 + 31136) + 120LL) + 36LL);
  v15[0] = v12;
  v15[1] = 1;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_program_offline_go_cmd",
      8061,
      "CSID:%u offline_cmd 0x%x offset 0x%X",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
      1,
      v12);
  v13 = *(_DWORD **)(v4 + 120);
  v14 = *a2;
  if ( *(v13 - 1) != -1401492769 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _DWORD *))v13)(v14, 1, v15);
  result = 0;
  *((_DWORD *)a2 + 3) = v7;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
