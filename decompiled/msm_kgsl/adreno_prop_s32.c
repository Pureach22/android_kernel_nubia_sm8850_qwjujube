__int64 __fastcall adreno_prop_s32(__int64 a1, int *a2)
{
  int v2; // w9
  unsigned int v3; // w9
  __int64 result; // x0
  unsigned int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a2;
  v5 = 0;
  if ( v2 == 7 )
  {
    v3 = 1;
    goto LABEL_5;
  }
  if ( v2 == 6 )
  {
    v3 = ((unsigned int)*(_QWORD *)(a1 + 104) >> 1) & 1;
LABEL_5:
    v5 = v3;
  }
  result = copy_prop(a2, &v5, 4);
  _ReadStatusReg(SP_EL0);
  return result;
}
