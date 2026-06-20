__int64 __fastcall action_oui_string_to_hex(const char *a1, __int64 a2, int a3, __int64 a4)
{
  unsigned int v8; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  const char *v17; // x2
  __int64 v18; // x8

  v8 = strlen(a1);
  v17 = "%s: Token len is not multiple of 2";
  if ( v8 && (v8 & 1) == 0 )
  {
    if ( a3 )
    {
      v18 = 0;
      v17 = "%s: Token len doesn't match with expected len";
      while ( *(_DWORD *)(a4 + 4 * v18) != v8 )
      {
        if ( a3 == ++v18 )
          goto LABEL_13;
      }
    }
    else
    {
      LODWORD(v18) = 0;
    }
    if ( (_DWORD)v18 == a3 )
    {
      v17 = "%s: Token len doesn't match with expected len";
    }
    else
    {
      if ( !(unsigned int)hex2bin(a2, a1, v8 >> 1) )
        return 1;
      v17 = "%s: Token doesn't contain hex digits";
    }
  }
LABEL_13:
  qdf_trace_msg(0x63u, 2u, v17, v9, v10, v11, v12, v13, v14, v15, v16, "action_oui_string_to_hex");
  return 0;
}
