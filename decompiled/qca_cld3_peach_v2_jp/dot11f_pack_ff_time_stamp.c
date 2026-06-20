void *__fastcall dot11f_pack_ff_time_stamp(int a1, int *a2, __int64 a3)
{
  void *result; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a2;
  qdf_mem_copy((void *)a3, &v6, 4u);
  v6 = a2[1];
  result = qdf_mem_copy((void *)(a3 + 4), &v6, 4u);
  _ReadStatusReg(SP_EL0);
  return result;
}
