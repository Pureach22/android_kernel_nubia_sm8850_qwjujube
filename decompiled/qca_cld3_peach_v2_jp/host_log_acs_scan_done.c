__int64 __fastcall host_log_acs_scan_done(const char *a1, char a2, int a3)
{
  size_t v6; // x0
  unsigned __int64 v7; // x2
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  _QWORD v17[3]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v18; // [xsp+20h] [xbp-10h]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  memset(v17, 0, sizeof(v17));
  v6 = strnlen(a1, 0x18u);
  if ( v6 == -1 )
  {
    _fortify_panic(2, -1, 0);
    goto LABEL_8;
  }
  if ( v6 == 24 )
    v7 = 24;
  else
    v7 = v6 + 1;
  if ( v7 >= 0x21 )
LABEL_8:
    _fortify_panic(7, 32, v7);
  sized_strscpy(v17, a1, v7);
  BYTE4(v18) = a2;
  LODWORD(v18) = a3;
  result = host_diag_event_report_payload(3148, 32, v17, v8, v9, v10, v11, v12, v13, v14, v15);
  _ReadStatusReg(SP_EL0);
  return result;
}
