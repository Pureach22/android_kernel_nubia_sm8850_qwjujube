__int64 __fastcall dot11f_unpack_ie_wmm_schedule(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3, __int64 a4)
{
  __int64 result; // x0
  int v6; // w21
  const void *v8; // x1
  int v9; // t1
  __int16 v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a4 )
  {
    result = 32;
  }
  else
  {
    v6 = a3;
    *(_BYTE *)a4 = 1;
    if ( !a3 )
      goto LABEL_13;
    v9 = *a2;
    v8 = a2 + 1;
    *(_BYTE *)(a4 + 1) = v9;
    if ( v9 != 1 )
    {
      *(_BYTE *)a4 = 0;
      result = 64;
      goto LABEL_12;
    }
    if ( a3 <= 2u
      || (v10 = 0, qdf_mem_copy(&v10, v8, 2u), *(_WORD *)(a4 + 2) = v10, (unsigned int)(v6 - 3) <= 3)
      || (qdf_mem_copy((void *)(a4 + 4), a2 + 3, 4u), (unsigned int)(v6 - 7) <= 3)
      || (qdf_mem_copy((void *)(a4 + 8), a2 + 7, 4u), (unsigned int)(v6 - 11) <= 1)
      || (qdf_mem_copy((void *)(a4 + 12), a2 + 11, 2u), (unsigned int)(v6 - 13) <= 1) )
    {
LABEL_13:
      *(_BYTE *)a4 = 0;
      result = 4;
      goto LABEL_12;
    }
    qdf_mem_copy((void *)(a4 + 14), a2 + 13, 2u);
    result = 0;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
