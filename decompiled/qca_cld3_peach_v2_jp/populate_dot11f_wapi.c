__int64 __fastcall populate_dot11f_wapi(__int64 a1, unsigned __int16 *a2, _WORD *a3)
{
  int v3; // w8
  __int64 v4; // x11
  unsigned __int16 *v5; // x9
  int v6; // w10
  bool v7; // vf
  unsigned int v8; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7

  v3 = *a2;
  if ( *a2 )
  {
    LODWORD(v4) = 0;
    v5 = a2 + 1;
    v6 = *((unsigned __int8 *)a2 + 3) + 2;
    while ( 1 )
    {
      v4 = (unsigned int)v4;
      if ( *((_BYTE *)v5 + (unsigned int)v4) == 68 )
        goto LABEL_8;
      v7 = __OFSUB__(v3, v6);
      v3 -= v6;
      if ( (v3 < 0) ^ v7 | (v3 == 0) )
        break;
      if ( (_DWORD)v4 != 256 )
      {
        v6 = *((unsigned __int8 *)v5 + (unsigned int)v4 + 1) + 2;
        v4 = (unsigned int)(v6 + v4);
        if ( (unsigned int)v4 < 0x101 )
          continue;
      }
      do
      {
        __break(0x5512u);
LABEL_8:
        ;
      }
      while ( (unsigned int)v4 >= 0x100 );
      v8 = dot11f_unpack_ie_wapi(a1, (char *)v5 + v4 + 2, *((_BYTE *)v5 + v4 + 1), a3);
      if ( (v8 & 0x10000000) == 0 )
      {
        qdf_trace_msg(0x35u, 8u, "%s: status 0x%08x", v9, v10, v11, v12, v13, v14, v15, v16, "populate_dot11f_wapi", v8);
        return 0;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Parse failure (0x%08x)",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "populate_dot11f_wapi",
        v8);
      return 16;
    }
  }
  return 0;
}
