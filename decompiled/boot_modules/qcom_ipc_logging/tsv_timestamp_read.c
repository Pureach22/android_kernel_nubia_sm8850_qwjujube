__int64 __fastcall tsv_timestamp_read(__int64 a1, __int64 a2, const char *a3)
{
  __int64 result; // x0
  __int64 v7; // x0
  __int64 v8; // x1
  unsigned __int64 v9; // x4
  __int64 v10; // x8
  unsigned __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  __int16 dest; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dest = 0;
  v11 = 0;
  result = tsv_read_header(a1, &dest);
  if ( (unsigned __int8)dest == 1 )
  {
    ((void (__fastcall *)(__int64, unsigned __int64 *, __int64))tsv_read_data)(a1, &v11, 8);
    v7 = *(_QWORD *)(a2 + 8);
    v8 = *(int *)(a2 + 16);
    v9 = v11 % 0x3B9ACA00;
    v11 /= 0x3B9ACA00u;
    result = scnprintf(v7, v8, "[%6u.%09lu%s/", v11, v9, a3);
    v10 = *(_QWORD *)(a2 + 8) + (int)result;
    *(_DWORD *)(a2 + 16) -= result;
    *(_QWORD *)(a2 + 8) = v10;
  }
  else
  {
    __break(0x800u);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
