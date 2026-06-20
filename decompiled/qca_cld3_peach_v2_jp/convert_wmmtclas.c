__int64 __fastcall convert_wmmtclas(__int64 a1, __int64 a2, __int64 a3)
{
  char v5; // w9
  int v6; // w8
  __int64 result; // x0
  int v8; // w8
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  if ( (dot11f_get_packed_iewmmtclas(a1, (_BYTE *)a3, &v9) & 0x10000000) != 0 )
    goto LABEL_9;
  v5 = v9;
  *(_BYTE *)a2 = -35;
  *(_BYTE *)(a2 + 1) = v5;
  *(_BYTE *)(a2 + 2) = *(_BYTE *)(a3 + 2);
  *(_BYTE *)(a2 + 3) = *(_BYTE *)(a3 + 3);
  *(_BYTE *)(a2 + 4) = *(_BYTE *)(a3 + 4);
  v6 = *(unsigned __int8 *)(a3 + 3);
  if ( v6 == 2 )
  {
    result = 0;
    *(_WORD *)(a2 + 6) = *(_WORD *)(a3 + 6);
    goto LABEL_10;
  }
  if ( v6 == 1 )
  {
    v8 = *(unsigned __int8 *)(a3 + 6);
    *(_BYTE *)(a2 + 5) = v8;
    if ( v8 == 6 )
    {
      *(_BYTE *)(a2 + 6) = 6;
      qdf_mem_copy((void *)(a2 + 7), (const void *)(a3 + 8), 0x10u);
      qdf_mem_copy((void *)(a2 + 23), (const void *)(a3 + 24), 0x10u);
      *(_WORD *)(a2 + 39) = *(_WORD *)(a3 + 40);
      *(_WORD *)(a2 + 41) = *(_WORD *)(a3 + 42);
      qdf_mem_copy((void *)(a2 + 43), (const void *)(a3 + 44), 3u);
      result = 0;
      goto LABEL_10;
    }
    if ( v8 == 4 )
    {
      *(_BYTE *)(a2 + 6) = 4;
      qdf_mem_copy((void *)(a2 + 7), (const void *)(a3 + 8), 4u);
      qdf_mem_copy((void *)(a2 + 11), (const void *)(a3 + 12), 4u);
      result = 0;
      *(_WORD *)(a2 + 15) = *(_WORD *)(a3 + 16);
      *(_WORD *)(a2 + 17) = *(_WORD *)(a3 + 18);
      *(_BYTE *)(a2 + 19) = *(_BYTE *)(a3 + 20);
      *(_BYTE *)(a2 + 20) = *(_BYTE *)(a3 + 21);
      *(_BYTE *)(a2 + 21) = *(_BYTE *)(a3 + 22);
      goto LABEL_10;
    }
LABEL_9:
    result = 16;
    goto LABEL_10;
  }
  if ( *(_BYTE *)(a3 + 3) )
    goto LABEL_9;
  qdf_mem_copy((void *)(a2 + 6), (const void *)(a3 + 6), 6u);
  qdf_mem_copy((void *)(a2 + 12), (const void *)(a3 + 12), 6u);
  result = 0;
  *(_WORD *)(a2 + 18) = *(_WORD *)(a3 + 18);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
