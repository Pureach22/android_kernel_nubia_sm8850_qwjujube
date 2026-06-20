__int64 __fastcall cam_ife_csid_get_format_ipp_ppp(int a1, int *a2)
{
  __int64 result; // x0
  int v3; // w8
  int v4; // w8
  int v5; // w9
  char v6; // w8
  int *v7; // x19
  int v8; // w19
  int *v9; // x22
  unsigned int v10; // w19

  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v8 = a1;
    v9 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_get_format_ipp_ppp",
      324,
      "input format:%d",
      a1);
    a1 = v8;
    a2 = v9;
  }
  switch ( a1 )
  {
    case 1:
      result = 0;
      *a2 = 0;
      goto LABEL_17;
    case 2:
    case 34:
      result = 0;
      v3 = 1;
      goto LABEL_16;
    case 3:
      result = 0;
      v4 = 2;
      goto LABEL_23;
    case 4:
      result = 0;
      v4 = 3;
      goto LABEL_23;
    case 5:
      result = 0;
      v4 = 4;
      goto LABEL_23;
    case 6:
      result = 0;
      v4 = 5;
      goto LABEL_23;
    case 7:
      result = 0;
      v4 = 6;
      v5 = 2;
      goto LABEL_24;
    case 25:
      result = 0;
      v4 = 7;
      goto LABEL_23;
    case 26:
      result = 0;
      v4 = 8;
      goto LABEL_23;
    case 27:
      result = 0;
      v4 = 9;
      goto LABEL_23;
    case 28:
      result = 0;
      v4 = 10;
      goto LABEL_23;
    case 29:
      result = 0;
      v4 = 11;
      goto LABEL_23;
    case 30:
      result = 0;
      v4 = 12;
      goto LABEL_23;
    case 46:
      result = 0;
      v4 = 13;
LABEL_23:
      v5 = 1;
LABEL_24:
      *a2 = v4;
      a2[2] = v5;
      v6 = debug_mdl;
      if ( (debug_mdl & 8) != 0 )
        goto LABEL_25;
      return result;
    case 50:
      result = 0;
      v3 = 2;
LABEL_16:
      *a2 = v3;
LABEL_17:
      a2[2] = 0;
      v6 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        return result;
      goto LABEL_25;
    default:
      v7 = a2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_get_format_ipp_ppp",
        393,
        "Unsupported format %d",
        a1);
      a2 = v7;
      result = 4294967274LL;
      v6 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        return result;
LABEL_25:
      if ( !debug_priority )
      {
        v10 = result;
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v6 & 8,
          4,
          "cam_ife_csid_get_format_ipp_ppp",
          399,
          "decode_fmt:%d plain_fmt:%d",
          *a2,
          a2[2]);
        return v10;
      }
      return result;
  }
}
