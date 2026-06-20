__int64 __fastcall tsv_byte_array_read(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w8
  __int16 dest; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dest = 0;
  result = tsv_read_header(a1, &dest);
  if ( (unsigned __int8)dest == 4 )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))tsv_read_data)(a1, *(_QWORD *)(a2 + 8), HIBYTE(dest));
    v5 = *(_DWORD *)(a2 + 16) - HIBYTE(dest);
    *(_QWORD *)(a2 + 8) += HIBYTE(dest);
    *(_DWORD *)(a2 + 16) = v5;
  }
  else
  {
    __break(0x800u);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
