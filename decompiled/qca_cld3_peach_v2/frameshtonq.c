void *__fastcall frameshtonq(__int64 a1, int *a2)
{
  void *result; // x0
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a2;
  qdf_mem_copy((void *)a1, &v5, 4u);
  v5 = a2[1];
  result = qdf_mem_copy((void *)(a1 + 4), &v5, 4u);
  _ReadStatusReg(SP_EL0);
  return result;
}
