__int64 __fastcall cam_vfe_top_add_wait_trigger(__int64 a1, _DWORD *a2, int a3)
{
  __int64 v3; // x20
  __int64 (__fastcall *v4)(_QWORD); // x8
  int v7; // w0
  _DWORD *v8; // x8
  unsigned int v9; // w6
  int v10; // w19
  const char *v11; // x5
  __int64 v12; // x4
  __int64 result; // x0
  int v14; // w10
  _DWORD *v15; // x11
  __int64 v16; // x0
  _DWORD *v17; // x20
  _DWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 != 56 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_add_wait_trigger",
      244,
      "Error, Invalid arg size = %d expected = %d",
      a3,
      56);
    goto LABEL_12;
  }
  if ( !*(_QWORD *)a2 || !*(_QWORD *)(a1 + 10432) )
  {
    v11 = "Error, Invalid args";
    v12 = 250;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_add_wait_trigger",
      v12,
      v11);
    goto LABEL_12;
  }
  v3 = *(_QWORD *)(*(_QWORD *)a2 + 48LL);
  if ( !v3 )
  {
    v11 = "Invalid CDM ops";
    v12 = 258;
    goto LABEL_11;
  }
  v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 24);
  if ( *((_DWORD *)v4 - 1) != 2010610996 )
    __break(0x8228u);
  v7 = v4(1);
  v8 = a2;
  v9 = a2[6];
  v10 = 4 * v7;
  if ( 4 * v7 > v9 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_add_wait_trigger",
      266,
      "buf size:%d is not sufficient, expected: %d",
      v9,
      v7);
LABEL_12:
    result = 4294967274LL;
    goto LABEL_13;
  }
  v14 = *((unsigned __int8 *)v8 + 48);
  v15 = *(_DWORD **)(v3 + 120);
  v16 = *((_QWORD *)v8 + 2);
  v17 = v8;
  v18[0] = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 64LL);
  v18[1] = v14;
  if ( *(v15 - 1) != -1401492769 )
    __break(0x822Bu);
  ((void (__fastcall *)(__int64, __int64, _DWORD *))v15)(v16, 1, v18);
  result = 0;
  v17[7] = v10;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
