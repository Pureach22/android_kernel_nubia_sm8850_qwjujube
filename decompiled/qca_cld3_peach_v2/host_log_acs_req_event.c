__int64 __fastcall host_log_acs_req_event(
        const char *a1,
        const char *a2,
        __int16 a3,
        char a4,
        char a5,
        __int16 a6,
        __int16 a7)
{
  size_t v14; // x0
  unsigned __int64 v15; // x2
  unsigned __int64 v16; // x2
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  _QWORD v26[2]; // [xsp+0h] [xbp-30h] BYREF
  __int64 v27; // [xsp+10h] [xbp-20h] BYREF
  __int64 v28; // [xsp+18h] [xbp-18h]
  int v29; // [xsp+20h] [xbp-10h]
  __int64 v30; // [xsp+28h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v27 = 0;
  v28 = 0;
  v26[0] = 0;
  v26[1] = 0;
  v14 = strnlen(a1, 0x10u);
  if ( v14 == -1 )
    goto LABEL_12;
  if ( v14 == 16 )
    v15 = 16;
  else
    v15 = v14 + 1;
  if ( v15 >= 0x25 )
    goto LABEL_13;
  sized_strscpy(v26, a1, v15);
  v14 = strnlen(a2, 0xCu);
  if ( v14 == -1 )
  {
LABEL_12:
    _fortify_panic(2, -1, v14 + 1);
LABEL_13:
    _fortify_panic(7, 36, v15);
    goto LABEL_14;
  }
  if ( v14 == 12 )
    v16 = 12;
  else
    v16 = v14 + 1;
  if ( v16 >= 0x15 )
LABEL_14:
    _fortify_panic(7, 20, v16);
  sized_strscpy(&v27, a2, v16);
  WORD2(v28) = a3;
  BYTE6(v28) = a4;
  HIBYTE(v28) = a5;
  LOWORD(v29) = a6;
  HIWORD(v29) = a7;
  result = host_diag_event_report_payload(3146, 36, v26, v17, v18, v19, v20, v21, v22, v23, v24);
  _ReadStatusReg(SP_EL0);
  return result;
}
