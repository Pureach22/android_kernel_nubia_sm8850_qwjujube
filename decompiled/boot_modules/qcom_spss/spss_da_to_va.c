__int64 __fastcall spss_da_to_va(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x9
  __int64 v4; // x8

  v3 = *(_QWORD **)(a1 + 40);
  v4 = a2 - v3[13];
  if ( (v4 & 0x80000000) == 0 && (unsigned __int64)(v4 & 0x7FFFFFFF) + a3 <= v3[15] )
    return v3[14] + (v4 & 0x7FFFFFFF);
  dev_err(a1 + 56, "offset: %x, da: %llx, len: %zx\n", v4, a2, a3);
  return 0;
}
