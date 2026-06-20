__int64 __fastcall cam_vfe_process_cmd(__int64 a1, unsigned int a2, _QWORD *a3, unsigned int a4)
{
  _QWORD *v4; // x22
  __int64 *v5; // x8
  __int64 result; // x0
  __int64 (__fastcall *v7)(_QWORD); // x9
  __int64 v8; // x0
  __int64 *v9; // x8
  void (__fastcall *v13)(_QWORD); // x9
  __int64 v14; // x0
  __int64 *v15; // x8
  _DWORD *v16; // x9
  __int64 v17; // x0

  if ( a1 )
  {
    v4 = *(_QWORD **)(a1 + 3680);
    switch ( a2 )
    {
      case 0u:
      case 3u:
      case 9u:
      case 0xAu:
      case 0xBu:
      case 0xCu:
      case 0xDu:
      case 0x12u:
      case 0x14u:
      case 0x16u:
      case 0x19u:
      case 0x1Cu:
      case 0x1Du:
      case 0x21u:
      case 0x27u:
      case 0x3Au:
      case 0x3Cu:
      case 0x42u:
      case 0x43u:
      case 0x48u:
      case 0x4Fu:
        v5 = (__int64 *)v4[2];
        goto LABEL_7;
      case 1u:
      case 4u:
      case 6u:
      case 8u:
      case 0xEu:
      case 0x10u:
      case 0x11u:
      case 0x18u:
      case 0x1Au:
      case 0x23u:
      case 0x25u:
      case 0x26u:
      case 0x38u:
      case 0x40u:
      case 0x45u:
      case 0x47u:
      case 0x4Bu:
      case 0x4Du:
      case 0x4Eu:
      case 0x50u:
      case 0x51u:
      case 0x54u:
        v5 = (__int64 *)v4[3];
        goto LABEL_7;
      case 2u:
      case 5u:
      case 0x17u:
        v5 = (__int64 *)v4[4];
        if ( v5 )
        {
LABEL_7:
          v7 = (__int64 (__fastcall *)(_QWORD))v5[11];
          v8 = *v5;
          if ( *((_DWORD *)v7 - 1) != -1055839300 )
            __break(0x8229u);
          result = v7(v8);
        }
        else
        {
          result = 0;
        }
        break;
      case 0x1Eu:
        result = 0;
        *a3 = a1 + 96;
        break;
      case 0x2Cu:
      case 0x3Du:
        v9 = (__int64 *)v4[3];
        v13 = (void (__fastcall *)(_QWORD))v9[11];
        v14 = *v9;
        if ( *((_DWORD *)v13 - 1) != -1055839300 )
          __break(0x8229u);
        v13(v14);
        v15 = (__int64 *)v4[2];
        v16 = (_DWORD *)v15[11];
        v17 = *v15;
        if ( *(v16 - 1) != -1055839300 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD *, _QWORD))v16)(v17, a2, a3, a4);
        result = 0;
        break;
      default:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_process_cmd",
          593,
          "Invalid cmd type:%d",
          a2);
        return 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_process_cmd",
      510,
      "Invalid arguments");
    return 4294967274LL;
  }
  return result;
}
