__int64 __fastcall dot11f_unpack_ie_wmmtspec(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3, __int64 a4)
{
  __int64 result; // x0
  int v6; // w22
  const void *v8; // x1
  int v9; // t1
  int v10; // w8
  int v11; // w21
  int v12; // w22
  _WORD v13[2]; // [xsp+0h] [xbp-10h] BYREF
  __int16 v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a4 )
  {
    result = 32;
  }
  else
  {
    v6 = a3;
    *(_BYTE *)a4 = 1;
    if ( !a3 )
      goto LABEL_25;
    v9 = *a2;
    v8 = a2 + 1;
    *(_BYTE *)(a4 + 1) = v9;
    if ( v9 != 1 )
    {
      *(_BYTE *)a4 = 0;
      result = 64;
      goto LABEL_24;
    }
    if ( a3 <= 2u )
      goto LABEL_25;
    v14 = 0;
    v13[0] = 0;
    qdf_mem_copy(&v14, v8, 2u);
    v10 = v14 & 1
        | (*(unsigned __int16 *)(a4 + 4) << 16)
        | v14 & 0x7E
        | v14 & 0x180
        | v14 & 0x200
        | v14 & 0x400
        | v14 & 0x3800
        | v14 & 0xC000;
    *(_DWORD *)(a4 + 2) = v10;
    if ( v6 == 3 )
      goto LABEL_25;
    v11 = v6 & 0xFE;
    *(_DWORD *)(a4 + 2) = v10 & 0xFF00FFFF | ((a2[3] & 0x7F) << 16) & 0xFF7FFFFF | (((a2[3] >> 7) & 1) << 23);
    if ( v11 == 4 )
      goto LABEL_25;
    qdf_mem_copy(v13, a2 + 4, 2u);
    *(_WORD *)(a4 + 6) = v13[0];
    if ( v11 == 6 )
      goto LABEL_25;
    qdf_mem_copy((void *)(a4 + 8), a2 + 6, 2u);
    v12 = v6 & 0xFC;
    if ( v12 == 8 )
      goto LABEL_25;
    qdf_mem_copy((void *)(a4 + 12), a2 + 8, 4u);
    if ( v12 == 12 )
      goto LABEL_25;
    qdf_mem_copy((void *)(a4 + 16), a2 + 12, 4u);
    if ( v12 == 16 )
      goto LABEL_25;
    qdf_mem_copy((void *)(a4 + 20), a2 + 16, 4u);
    if ( v12 == 20 )
      goto LABEL_25;
    qdf_mem_copy((void *)(a4 + 24), a2 + 20, 4u);
    if ( v12 == 24 )
      goto LABEL_25;
    qdf_mem_copy((void *)(a4 + 28), a2 + 24, 4u);
    if ( v12 == 28
      || (qdf_mem_copy((void *)(a4 + 32), a2 + 28, 4u), v12 == 32)
      || (qdf_mem_copy((void *)(a4 + 36), a2 + 32, 4u), v12 == 36)
      || (qdf_mem_copy((void *)(a4 + 40), a2 + 36, 4u), v12 == 40)
      || (qdf_mem_copy((void *)(a4 + 44), a2 + 40, 4u), v12 == 44)
      || (qdf_mem_copy((void *)(a4 + 48), a2 + 44, 4u), v12 == 48)
      || (qdf_mem_copy((void *)(a4 + 52), a2 + 48, 4u), v11 == 52)
      || (qdf_mem_copy((void *)(a4 + 56), a2 + 52, 2u), v11 == 54) )
    {
LABEL_25:
      *(_BYTE *)a4 = 0;
      result = 4;
      goto LABEL_24;
    }
    qdf_mem_copy((void *)(a4 + 58), a2 + 54, 2u);
    result = 0;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
