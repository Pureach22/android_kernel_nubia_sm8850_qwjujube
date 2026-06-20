__int64 __fastcall tsv_pointer_read(__int64 a1, __int64 a2, const char *a3)
{
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  __int16 dest; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dest = 0;
  v8 = 0;
  result = tsv_read_header(a1, &dest);
  if ( (unsigned __int8)dest == 2 )
  {
    ((void (__fastcall *)(__int64, __int64 *, __int64))tsv_read_data)(a1, &v8, 8);
    result = scnprintf(*(_QWORD *)(a2 + 8), *(int *)(a2 + 16), a3, v8);
    v7 = *(_QWORD *)(a2 + 8) + (int)result;
    *(_DWORD *)(a2 + 16) -= result;
    *(_QWORD *)(a2 + 8) = v7;
  }
  else
  {
    __break(0x800u);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
