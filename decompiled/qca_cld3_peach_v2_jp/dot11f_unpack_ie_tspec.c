__int64 __fastcall dot11f_unpack_ie_tspec(__int64 a1, _BYTE *a2, unsigned __int8 a3, __int64 a4)
{
  __int64 result; // x0
  int v5; // w21
  unsigned int v8; // w8
  _WORD v9[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int16 v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a4 )
  {
    result = 32;
  }
  else
  {
    v5 = a3;
    *(_BYTE *)a4 = 1;
    if ( a3 <= 1u )
      goto LABEL_22;
    v10 = 0;
    v9[0] = 0;
    qdf_mem_copy(&v10, a2, 2u);
    v8 = (*(_DWORD *)(a4 + 1) & 0xFFFE0080
        | v10 & 1
        | v10 & 0x7E
        | (((v10 >> 7) & 3) << 8) & 0xFFFFF3FF
        | (((v10 >> 9) & 1) << 10) & 0xFFFFF7FF
        | (((v10 >> 10) & 1) << 11)
        | (2 * v10) & 0x7000)
       + ((2 * v10) & 0x18000);
    *(_DWORD *)(a4 + 1) = v8;
    if ( v5 == 2 )
      goto LABEL_22;
    *(_DWORD *)(a4 + 1) = v8 & 0x80FDFFFF | ((a2[2] & 1) << 17) & 0x80FFFFFF | (a2[2] >> 1 << 24);
    if ( (unsigned int)(v5 - 3) <= 1 )
      goto LABEL_22;
    qdf_mem_copy(v9, a2 + 3, 2u);
    *(_WORD *)(a4 + 6) = v9[0];
    if ( (unsigned int)(v5 - 5) <= 1 )
      goto LABEL_22;
    qdf_mem_copy((void *)(a4 + 8), a2 + 5, 2u);
    if ( (unsigned int)(v5 - 7) <= 3 )
      goto LABEL_22;
    qdf_mem_copy((void *)(a4 + 12), a2 + 7, 4u);
    if ( (unsigned int)(v5 - 11) <= 3 )
      goto LABEL_22;
    qdf_mem_copy((void *)(a4 + 16), a2 + 11, 4u);
    if ( (unsigned int)(v5 - 15) <= 3 )
      goto LABEL_22;
    qdf_mem_copy((void *)(a4 + 20), a2 + 15, 4u);
    if ( (unsigned int)(v5 - 19) <= 3 )
      goto LABEL_22;
    qdf_mem_copy((void *)(a4 + 24), a2 + 19, 4u);
    if ( (unsigned int)(v5 - 23) <= 3 )
      goto LABEL_22;
    qdf_mem_copy((void *)(a4 + 28), a2 + 23, 4u);
    if ( (unsigned int)(v5 - 27) <= 3
      || (qdf_mem_copy((void *)(a4 + 32), a2 + 27, 4u), (unsigned int)(v5 - 31) <= 3)
      || (qdf_mem_copy((void *)(a4 + 36), a2 + 31, 4u), (unsigned int)(v5 - 35) <= 3)
      || (qdf_mem_copy((void *)(a4 + 40), a2 + 35, 4u), (unsigned int)(v5 - 39) <= 3)
      || (qdf_mem_copy((void *)(a4 + 44), a2 + 39, 4u), (unsigned int)(v5 - 43) <= 3)
      || (qdf_mem_copy((void *)(a4 + 48), a2 + 43, 4u), (unsigned int)(v5 - 47) <= 3)
      || (qdf_mem_copy((void *)(a4 + 52), a2 + 47, 4u), (unsigned int)(v5 - 51) <= 1)
      || (qdf_mem_copy((void *)(a4 + 56), a2 + 51, 2u), (unsigned int)(v5 - 53) <= 1) )
    {
LABEL_22:
      *(_BYTE *)a4 = 0;
      result = 4;
    }
    else
    {
      qdf_mem_copy((void *)(a4 + 58), a2 + 53, 2u);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
