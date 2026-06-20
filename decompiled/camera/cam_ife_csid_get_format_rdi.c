__int64 __fastcall cam_ife_csid_get_format_rdi(int a1, int a2, __int64 a3, char a4, char a5)
{
  int v7; // w9
  int v8; // w8
  int v9; // w11
  int v10; // w10
  __int64 result; // x0

  if ( a1 > 5 )
  {
    if ( a1 > 33 )
    {
      if ( a1 == 34 )
      {
        if ( a2 != 34 )
        {
LABEL_31:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_csid_validate_rdi_format",
            199,
            "Unsupported format pair in %d out %d",
            a1,
            a2);
LABEL_32:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_csid_get_format_rdi",
            313,
            "Unsupported format pair in %d out %d",
            a1,
            a2);
          return 4294967274LL;
        }
      }
      else if ( a1 != 50 || a2 != 50 )
      {
        goto LABEL_31;
      }
    }
    else if ( a1 == 6 )
    {
      if ( a2 != 6 && a2 != 17 )
        goto LABEL_31;
    }
    else if ( a1 != 7 || a2 != 7 && a2 != 18 )
    {
      goto LABEL_31;
    }
  }
  else if ( (unsigned int)(a1 - 3) >= 3 )
  {
    if ( a1 == 1 )
    {
      if ( a2 != 1 && a2 != 12 )
        goto LABEL_31;
    }
    else if ( a1 != 2 || (unsigned int)a2 > 0x14 || ((1 << a2) & 0x101004) == 0 )
    {
      goto LABEL_31;
    }
  }
  else if ( (unsigned int)a2 > 0x31 || ((1LL << a2) & 0x200000013C038LL) == 0 )
  {
    goto LABEL_31;
  }
  *(_QWORD *)a3 = 0;
  *(_QWORD *)(a3 + 8) = 0;
  if ( a1 == a2 && (a4 & 1) == 0 )
  {
    v7 = 15;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    *(_DWORD *)a3 = 15;
    goto LABEL_74;
  }
  v8 = 8;
  v7 = 1;
  if ( a1 <= 4 )
  {
    if ( a1 > 2 )
    {
      if ( a1 == 3 )
      {
LABEL_45:
        v8 = 10;
        v7 = 2;
        goto LABEL_49;
      }
      v8 = 12;
      v7 = 3;
    }
    else if ( a1 == 1 )
    {
      v7 = 0;
      v8 = 6;
      goto LABEL_50;
    }
  }
  else
  {
    if ( a1 <= 6 )
    {
      if ( a1 == 5 )
      {
        v8 = 14;
        v7 = 4;
      }
      else
      {
        v8 = 16;
        v7 = 5;
      }
      goto LABEL_49;
    }
    if ( a1 == 7 )
    {
      v8 = 20;
      v7 = 6;
      goto LABEL_49;
    }
    if ( a1 != 34 )
      goto LABEL_45;
  }
LABEL_49:
  *(_DWORD *)a3 = v7;
LABEL_50:
  *(_DWORD *)(a3 + 12) = v8;
  if ( a2 > 13 )
  {
    if ( a2 <= 19 )
    {
      if ( (unsigned int)(a2 - 14) >= 4 )
      {
        if ( a2 != 18 )
          goto LABEL_32;
        goto LABEL_72;
      }
LABEL_69:
      v10 = 1;
LABEL_70:
      v9 = 0;
      *(_DWORD *)(a3 + 8) = v10;
      goto LABEL_74;
    }
    if ( a2 <= 48 )
    {
      if ( a2 != 20 && a2 != 34 )
        goto LABEL_32;
      goto LABEL_62;
    }
    if ( a2 == 49 )
      goto LABEL_69;
LABEL_68:
    if ( (a5 & 1) != 0 )
      goto LABEL_69;
    goto LABEL_73;
  }
  if ( a2 <= 6 )
  {
    if ( (unsigned int)(a2 - 3) >= 4 )
    {
      if ( (unsigned int)(a2 - 1) >= 2 )
        goto LABEL_32;
LABEL_62:
      if ( (a5 & 1) == 0 )
        goto LABEL_73;
LABEL_66:
      v9 = 0;
      v10 = 0;
      *(_DWORD *)(a3 + 8) = 0;
      goto LABEL_74;
    }
    goto LABEL_68;
  }
  if ( a2 != 7 )
  {
    if ( a2 != 12 )
      goto LABEL_32;
    goto LABEL_66;
  }
  if ( (a5 & 1) != 0 )
  {
LABEL_72:
    v10 = 2;
    goto LABEL_70;
  }
LABEL_73:
  v10 = 0;
  v9 = 1;
  *(_DWORD *)(a3 + 4) = 1;
LABEL_74:
  result = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_get_format_rdi",
      308,
      "in %u out %u plain_fmt %u packing %u decode %u bpp %u unpack %u pack supported %u",
      a1,
      a2,
      v10,
      v9,
      v7,
      v8,
      a5 & 1,
      a4 & 1);
    return 0;
  }
  return result;
}
