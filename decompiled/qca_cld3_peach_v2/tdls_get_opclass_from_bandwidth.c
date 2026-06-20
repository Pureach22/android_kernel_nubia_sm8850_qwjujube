__int64 __fastcall tdls_get_opclass_from_bandwidth(__int64 a1, __int64 a2, char a3, char *a4)
{
  __int64 result; // x0
  char v6; // w8
  unsigned int v8; // w21

  if ( (a3 & 8) != 0 )
  {
LABEL_5:
    result = tdls_find_opclass_frm_freq(a1, a2, 160, 0);
    v6 = 5;
LABEL_7:
    *a4 = v6;
    return result;
  }
  if ( (a3 & 4) != 0 )
  {
    result = tdls_find_opclass_frm_freq(a1, a2, 80, 0);
    v6 = 4;
    goto LABEL_7;
  }
  if ( (a3 & 2) == 0 )
  {
    if ( (a3 & 1) != 0 )
    {
      result = tdls_find_opclass_frm_freq(a1, a2, 20, 0);
      v6 = 0;
      goto LABEL_7;
    }
    goto LABEL_5;
  }
  v8 = a2;
  result = tdls_find_opclass_frm_freq(a1, a2, 40, 1);
  *a4 = 1;
  if ( !(_BYTE)result )
  {
    result = tdls_find_opclass_frm_freq(a1, v8, 40, 2);
    v6 = 3;
    goto LABEL_7;
  }
  return result;
}
