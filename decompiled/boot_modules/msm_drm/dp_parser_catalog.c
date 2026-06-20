__int64 __fastcall dp_parser_catalog(__int64 *a1)
{
  __int64 v2; // x21
  __int64 result; // x0
  int v4; // w8
  char *v5; // x20
  char *s1; // [xsp+8h] [xbp-18h] BYREF
  int v7; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v7 = 0;
  s1 = nullptr;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v2 + 760), "qcom,phy-version", &v7, 1, 0) & 0x80000000) == 0 )
    *((_DWORD *)a1 + 178) = v7;
  if ( (unsigned int)of_property_read_string(*(_QWORD *)(v2 + 760), "qcom,phy-mode", &s1) )
  {
    *((_DWORD *)a1 + 179) = 0;
  }
  else
  {
    v5 = s1;
    if ( *s1 == 100 && s1[1] == 112 && !s1[2] )
    {
      *((_DWORD *)a1 + 179) = 1;
    }
    else if ( !strcmp(s1, "minidp") )
    {
      *((_DWORD *)a1 + 179) = 2;
    }
    else if ( !strcmp(v5, "edp") )
    {
      *((_DWORD *)a1 + 179) = 3;
    }
    else if ( !strcmp(v5, "edp-highswing") )
    {
      *((_DWORD *)a1 + 179) = 4;
    }
    else
    {
      *((_DWORD *)a1 + 179) = 0;
      printk(&unk_21BD20, v5);
    }
  }
  result = of_property_read_string(*(_QWORD *)(v2 + 760), "qcom,phy-revision", &s1);
  if ( !(_DWORD)result )
  {
    if ( *s1 == 118 )
    {
      if ( s1[1] == 49 && !s1[2] )
      {
        v4 = 1;
        goto LABEL_12;
      }
      if ( s1[1] == 50 && !s1[2] )
      {
        v4 = 2;
        goto LABEL_12;
      }
    }
    v4 = 0;
LABEL_12:
    *((_DWORD *)a1 + 180) = v4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
