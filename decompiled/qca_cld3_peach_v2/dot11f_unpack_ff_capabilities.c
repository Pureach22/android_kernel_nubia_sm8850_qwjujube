void *__fastcall dot11f_unpack_ff_capabilities(__int64 a1, const void *a2, _WORD *a3)
{
  void *result; // x0
  __int16 v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  result = qdf_mem_copy(&v5, a2, 2u);
  *a3 = v5;
  _ReadStatusReg(SP_EL0);
  return result;
}
