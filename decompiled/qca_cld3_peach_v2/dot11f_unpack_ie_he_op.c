__int64 __fastcall dot11f_unpack_ie_he_op(__int64 a1, char *a2, unsigned __int8 a3, __int64 a4)
{
  __int64 result; // x0
  int v5; // w22
  unsigned int v9; // w8
  int v10; // w9
  char *v11; // x8
  char v12; // w10
  char v13; // t1
  unsigned __int16 v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a4 )
  {
    v5 = a3;
    *(_BYTE *)a4 = 1;
    if ( a3 <= 1u )
      goto LABEL_24;
    v14 = 0;
    qdf_mem_copy(&v14, a2, 2u);
    v9 = *(_DWORD *)(a4 + 1) & 0xFFF000F0
       | v14 & 7
       | v14 & 8
       | (((v14 >> 15) & 1) << 19)
       | (((v14 >> 4) & 0x3FF) << 8) & 0xFFFBFFFF
       | (((v14 >> 14) & 1) << 18);
    *(_DWORD *)(a4 + 1) = v9;
    if ( v5 == 2 )
      goto LABEL_24;
    *(_DWORD *)(a4 + 1) = v9 & 0xC0CFFFFF
                        | ((a2[2] & 1) << 20) & 0xC0DFFFFF
                        | ((((unsigned __int8)a2[2] >> 1) & 1) << 21) & 0xC0FFFFFF
                        | ((unsigned __int8)a2[2] >> 2 << 24);
    if ( a3 == 3 )
      goto LABEL_24;
    *(_BYTE *)(a4 + 5) = a2[3];
    if ( (a3 & 0xFE) == 4 )
      goto LABEL_24;
    qdf_mem_copy((void *)(a4 + 6), a2 + 4, 2u);
    v10 = *(_DWORD *)(a4 + 1);
    v11 = a2 + 6;
    v12 = a3 - 6;
    if ( (v10 & 0x40000) != 0 )
    {
      if ( a3 == 6 )
        goto LABEL_24;
      *(_BYTE *)(a4 + 8) = *v11;
      if ( a3 == 7 )
        goto LABEL_24;
      *(_BYTE *)(a4 + 9) = a2[7];
      if ( a3 == 8 )
        goto LABEL_24;
      v12 = a3 - 9;
      *(_BYTE *)(a4 + 10) = a2[8];
      v11 = a2 + 9;
    }
    if ( (v10 & 0x80000) != 0 )
    {
      if ( !v12 )
        goto LABEL_24;
      v13 = *v11++;
      --v12;
      *(_BYTE *)(a4 + 11) = v13;
    }
    if ( (v10 & 0x200000) == 0 )
    {
      result = 0;
      goto LABEL_23;
    }
    if ( v12 )
    {
      *(_BYTE *)(a4 + 12) = *v11;
      if ( v12 != 1 )
      {
        *(_BYTE *)(a4 + 13) = v11[1];
        if ( v12 != 2 )
        {
          *(_BYTE *)(a4 + 14) = v11[2];
          if ( v12 != 3 )
          {
            *(_BYTE *)(a4 + 15) = v11[3];
            if ( v12 != 4 )
            {
              result = 0;
              *(_BYTE *)(a4 + 16) = v11[4];
              goto LABEL_23;
            }
          }
        }
      }
    }
LABEL_24:
    *(_BYTE *)a4 = 0;
    result = 4;
    goto LABEL_23;
  }
  result = 32;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
