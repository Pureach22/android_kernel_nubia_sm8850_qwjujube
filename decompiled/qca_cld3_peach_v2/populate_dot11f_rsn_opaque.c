__int64 __fastcall populate_dot11f_rsn_opaque(__int64 a1, unsigned __int16 *a2, _BYTE *a3)
{
  int v3; // w8
  __int64 v4; // x10
  unsigned __int16 *v5; // x9
  int v6; // w11
  bool v7; // vf
  char *v8; // x9
  unsigned int v9; // w8

  v3 = *a2;
  if ( *a2 )
  {
    LODWORD(v4) = 0;
    v5 = a2 + 1;
    v6 = *((unsigned __int8 *)a2 + 3) + 2;
    while ( 1 )
    {
      v4 = (unsigned int)v4;
      if ( *((_BYTE *)v5 + (unsigned int)v4) == 48 )
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
        *a3 = 1;
      }
      while ( (unsigned int)v4 >= 0x100 );
      v8 = (char *)v5 + v4;
      v9 = (unsigned __int8)v8[1];
      a3[1] = v9;
      qdf_mem_copy(a3 + 2, v8 + 2, v9);
      return 0;
    }
  }
  return 0;
}
