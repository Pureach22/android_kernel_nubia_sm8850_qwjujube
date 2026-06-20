__int64 __fastcall populate_dot11f_ese_cckm_opaque(__int64 a1, __int64 a2, _BYTE *a3)
{
  unsigned int v3; // w22
  int v6; // w9
  unsigned int v7; // w8
  int v8; // w11
  __int64 v9; // x10
  bool v10; // vf
  size_t v11; // x2
  _WORD s[130]; // [xsp+4h] [xbp-10Ch] BYREF
  __int64 v14; // [xsp+108h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned __int8 *)(a2 + 266);
  if ( v3 - 1 <= 0x88 )
  {
    memset(s, 0, sizeof(s));
    qdf_mem_copy(&s[1], (const void *)(a2 + 128), v3);
    v6 = *(unsigned __int8 *)(a2 + 266);
    v7 = 0;
    v8 = HIBYTE(s[1]) + 2;
    s[0] = *(unsigned __int8 *)(a2 + 266);
    while ( 1 )
    {
      v9 = v7;
      if ( *((unsigned __int8 *)&s[1] + v7) == 156 )
        goto LABEL_8;
      v10 = __OFSUB__(v6, v8);
      v6 -= v8;
      if ( (v6 < 0) ^ v10 | (v6 == 0) )
        break;
      if ( v7 != 256 )
      {
        v9 = *((unsigned __int8 *)&s[1] + v7 + 1);
        v8 = v9 + 2;
        v7 += v9 + 2;
        if ( v7 < 0x101 )
          continue;
      }
      do
      {
        __break(0x5512u);
LABEL_8:
        *a3 = 1;
      }
      while ( v7 >= 0x100 );
      v11 = (unsigned int)*((unsigned __int8 *)&s[1] + v9 + 1) - 4;
      a3[1] = *((_BYTE *)&s[1] + v9 + 1) - 4;
      qdf_mem_copy(a3 + 2, (char *)&s[4] + v9, v11);
      break;
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
