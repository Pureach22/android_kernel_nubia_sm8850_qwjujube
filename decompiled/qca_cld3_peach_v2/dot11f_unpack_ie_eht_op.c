__int64 __fastcall dot11f_unpack_ie_eht_op(__int64 a1, _BYTE *a2, unsigned __int8 a3, _BYTE *a4)
{
  __int64 result; // x0
  int v5; // w20
  unsigned int v9; // w11
  int v10; // w9
  unsigned int v11; // w12
  unsigned __int64 v12; // t2
  size_t v13; // x2
  unsigned int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *a4 )
  {
    result = 32;
  }
  else
  {
    *a4 = 1;
    if ( a3
      && (v5 = a3,
          *(_DWORD *)(a4 + 1) = *(_DWORD *)(a4 + 1) & 0xFFFFFF00
                              | *a2 & 1
                              | *a2 & 2
                              | *a2 & 4
                              | *a2 & 8
                              | *a2 & 0x30
                              | *a2 & 0x40
                              | *a2 & 0x80,
          a3 > 4u) )
    {
      v14 = 0;
      qdf_mem_copy(&v14, a2 + 1, 4u);
      v9 = v14;
      v10 = (unsigned __int8)a4[1];
      v11 = HIBYTE(v14);
      *(_DWORD *)(a4 + 1) = v10 | (v14 << 8);
      a4[5] = v11;
      if ( v5 == 5
        || (HIDWORD(v12) = (unsigned __int8)a2[5], LODWORD(v12) = v9, *(_WORD *)(a4 + 5) = v12 >> 24, a3 == 6)
        || (a4[7] = a2[6], a3 == 7)
        || (v13 = v10 & 2, a4[8] = a2[7], (unsigned int)v13 > (unsigned __int8)(a3 - 8)) )
      {
        *a4 = 0;
        result = 4;
      }
      else
      {
        qdf_mem_copy(a4 + 9, a2 + 8, v13);
        result = 0;
      }
    }
    else
    {
      *a4 = 0;
      result = 4;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
