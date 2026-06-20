__int64 __fastcall lim_reorder_vendor_ies(__int64 a1, __int64 a2, unsigned __int16 a3)
{
  int v5; // w21
  int v6; // w23
  bool v7; // zf
  __int64 result; // x0
  unsigned __int16 v9; // [xsp+14h] [xbp-10Ch] BYREF
  _BYTE s[257]; // [xsp+17h] [xbp-109h] BYREF
  __int64 v11; // [xsp+118h] [xbp-8h]

  v5 = a3;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a3;
  memset(s, 0, sizeof(s));
  v6 = v5;
  do
  {
    result = lim_strip_ie(a1, a2, &v9, 221, 1, 0, 0, s, 255);
    if ( v5 != v9 )
    {
      result = (__int64)qdf_mem_copy((void *)(a2 + v9), s, v5 - (unsigned int)v9);
      v6 = v9;
    }
    v7 = v5 == v6;
    v5 = v6;
  }
  while ( !v7 );
  _ReadStatusReg(SP_EL0);
  return result;
}
