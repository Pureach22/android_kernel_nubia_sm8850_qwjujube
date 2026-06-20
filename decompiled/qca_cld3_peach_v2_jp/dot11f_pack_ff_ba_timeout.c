void *__fastcall dot11f_pack_ff_ba_timeout(int a1, __int16 *a2, void *a3)
{
  void *result; // x0
  __int16 v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a2;
  result = qdf_mem_copy(a3, &v4, 2u);
  _ReadStatusReg(SP_EL0);
  return result;
}
