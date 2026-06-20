__int64 __fastcall cam_sfe_process_cmd(__int64 a1, int a2, _QWORD *a3, unsigned int a4)
{
  _QWORD *v5; // x22
  __int64 result; // x0
  __int64 *v7; // x8
  __int64 (__fastcall *v8)(_QWORD); // x9
  __int64 v9; // x0
  __int64 *v10; // x8
  int v11; // w21
  _QWORD *v12; // x19
  unsigned int v13; // w20
  void (__fastcall *v14)(__int64, __int64); // x9
  __int64 v15; // x0
  __int64 *v16; // x8
  unsigned int v17; // w19
  _QWORD *v18; // x20
  unsigned int v19; // w21
  void (__fastcall *v20)(_QWORD); // x9
  __int64 v21; // x0
  __int64 *v22; // x8
  __int64 v23; // x1
  _QWORD *v24; // x2
  __int64 v25; // x3
  _DWORD *v26; // x9
  __int64 v27; // x0
  __int64 *v28; // x8
  _QWORD *v29; // x19
  unsigned int v30; // w20
  void (__fastcall *v31)(__int64, __int64); // x9
  __int64 v32; // x0

  if ( a1 )
  {
    v5 = *(_QWORD **)(a1 + 3680);
    result = 0;
    switch ( a2 )
    {
      case 0:
      case 9:
      case 11:
      case 12:
      case 13:
      case 25:
      case 58:
      case 66:
        v7 = (__int64 *)v5[1];
        goto LABEL_8;
      case 1:
      case 4:
      case 6:
      case 8:
      case 26:
      case 37:
      case 56:
      case 62:
      case 64:
      case 70:
      case 71:
      case 84:
        v7 = (__int64 *)v5[2];
        goto LABEL_8;
      case 2:
      case 5:
      case 7:
      case 23:
      case 57:
      case 63:
      case 65:
        v7 = (__int64 *)v5[3];
LABEL_8:
        v8 = (__int64 (__fastcall *)(_QWORD))v7[11];
        v9 = *v7;
        if ( *((_DWORD *)v8 - 1) != -1055839300 )
          __break(0x8229u);
        return v8(v9);
      case 17:
      case 38:
      case 77:
      case 78:
        goto LABEL_15;
      case 30:
        result = 0;
        *a3 = a1 + 96;
        return result;
      case 35:
        return result;
      case 43:
        v10 = (__int64 *)v5[1];
        v11 = a2;
        v12 = a3;
        v13 = a4;
        v14 = (void (__fastcall *)(__int64, __int64))v10[11];
        v15 = *v10;
        if ( *((_DWORD *)v14 - 1) != -1055839300 )
          __break(0x8229u);
        v14(v15, 43);
        a2 = v11;
        a3 = v12;
        a4 = v13;
LABEL_15:
        v16 = (__int64 *)v5[2];
        v17 = a2;
        v18 = a3;
        v19 = a4;
        v20 = (void (__fastcall *)(_QWORD))v16[11];
        v21 = *v16;
        if ( *((_DWORD *)v20 - 1) != -1055839300 )
          __break(0x8229u);
        v20(v21);
        v22 = (__int64 *)v5[3];
        v23 = v17;
        v24 = v18;
        v25 = v19;
        break;
      case 44:
        v28 = (__int64 *)v5[1];
        v29 = a3;
        v30 = a4;
        v31 = (void (__fastcall *)(__int64, __int64))v28[11];
        v32 = *v28;
        if ( *((_DWORD *)v31 - 1) != -1055839300 )
          __break(0x8229u);
        v31(v32, 44);
        v22 = (__int64 *)v5[2];
        v23 = 44;
        v24 = v29;
        v25 = v30;
        break;
      default:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_process_cmd",
          473,
          "Invalid cmd type: %d",
          a2);
        return 4294967274LL;
    }
    v26 = (_DWORD *)v22[11];
    v27 = *v22;
    if ( *(v26 - 1) != -1055839300 )
      __break(0x8229u);
    ((void (__fastcall *)(__int64, __int64, _QWORD *, __int64))v26)(v27, v23, v24, v25);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_process_cmd",
      387,
      "Invalid arguments");
    return 4294967274LL;
  }
}
