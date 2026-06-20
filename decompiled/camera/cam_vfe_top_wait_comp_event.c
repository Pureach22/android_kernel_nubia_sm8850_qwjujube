__int64 __fastcall cam_vfe_top_wait_comp_event(__int64 a1, _DWORD *a2, int a3)
{
  __int64 v3; // x19
  __int64 (*v4)(void); // x8
  int v6; // w0
  _DWORD *v7; // x8
  unsigned int v8; // w6
  int v9; // w20
  const char *v10; // x5
  __int64 v11; // x4
  _DWORD *v13; // x9
  __int64 v14; // x0
  _DWORD *v15; // x19

  if ( a3 != 56 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_wait_comp_event",
      199,
      "Error, Invalid arg size = %d expected = %d",
      a3,
      56);
    return 4294967274LL;
  }
  if ( !*(_QWORD *)a2 || !*(_QWORD *)(a1 + 10432) )
  {
    v10 = "Error, Invalid args";
    v11 = 205;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_wait_comp_event",
      v11,
      v10);
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(*(_QWORD *)a2 + 48LL);
  if ( !v3 )
  {
    v10 = "Invalid CDM ops";
    v11 = 213;
    goto LABEL_11;
  }
  v4 = *(__int64 (**)(void))(v3 + 64);
  if ( *((_DWORD *)v4 - 1) != -605791253 )
    __break(0x8228u);
  v6 = v4();
  v7 = a2;
  v8 = a2[6];
  v9 = 4 * v6;
  if ( 4 * v6 > v8 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_wait_comp_event",
      221,
      "buf size:%d is not sufficient, expected: %d",
      v8,
      v6);
    return 4294967274LL;
  }
  v13 = *(_DWORD **)(v3 + 160);
  v14 = *((_QWORD *)v7 + 2);
  v15 = v7;
  if ( *(v13 - 1) != -779882607 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64, _QWORD, __int64))v13)(v14, 0, 2);
  v15[7] = v9;
  return 0;
}
