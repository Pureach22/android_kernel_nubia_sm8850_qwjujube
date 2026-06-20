__int64 __fastcall tsv_int32_read(__int64 a1, __int64 a2, const char *a3)
{
  int v6; // w8
  __int64 v7; // x9
  __int64 result; // x0
  unsigned int v9; // [xsp+0h] [xbp-10h] BYREF
  __int16 dest; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dest = 0;
  v9 = 0;
  tsv_read_header(a1, &dest);
  if ( (unsigned __int8)dest == 3 )
  {
    ((void (__fastcall *)(__int64, unsigned int *, __int64))tsv_read_data)(a1, &v9, 4);
    v6 = scnprintf(*(_QWORD *)(a2 + 8), *(int *)(a2 + 16), a3, v9);
    v7 = *(_QWORD *)(a2 + 8) + v6;
    result = v9;
    *(_DWORD *)(a2 + 16) -= v6;
    *(_QWORD *)(a2 + 8) = v7;
  }
  else
  {
    __break(0x800u);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
