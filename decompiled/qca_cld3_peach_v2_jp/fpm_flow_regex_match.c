bool __fastcall fpm_flow_regex_match(_DWORD *a1, _DWORD *a2)
{
  int v2; // w8
  _DWORD *v3; // x19
  _DWORD *v4; // x20
  _DWORD *v5; // x19
  _DWORD *v6; // x20

  v2 = a1[10];
  if ( (v2 & 1) != 0 )
  {
    if ( (v2 & 4) != 0 && *a1 != *a2 || (v2 & 8) != 0 && a1[4] != a2[4] )
      return 0;
  }
  else if ( (v2 & 2) != 0 )
  {
    if ( (v2 & 4) != 0 )
    {
      v3 = a1;
      v4 = a2;
      if ( (unsigned int)qdf_mem_cmp(a1, a2, 0x10u) )
        return 0;
      v2 = v3[10];
      a1 = v3;
      a2 = v4;
    }
    if ( (v2 & 8) != 0 )
    {
      v5 = a1;
      v6 = a2;
      if ( (unsigned int)qdf_mem_cmp(a1 + 4, a2 + 4, 0x10u) )
        return 0;
      v2 = v5[10];
      a1 = v5;
      a2 = v6;
    }
  }
  return ((v2 & 0x10) == 0 || *((unsigned __int16 *)a1 + 16) == *((unsigned __int16 *)a2 + 16))
      && ((v2 & 0x20) == 0 || *((unsigned __int16 *)a1 + 17) == *((unsigned __int16 *)a2 + 17))
      && ((v2 & 0x40) == 0 || *((unsigned __int8 *)a1 + 36) == *((unsigned __int8 *)a2 + 36));
}
