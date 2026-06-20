__int64 __fastcall adreno_prop_gpu_model(__int64 a1, __int64 a2)
{
  size_t v3; // x0
  unsigned __int64 v4; // x2
  __int64 result; // x0
  _QWORD v6[5]; // [xsp+8h] [xbp-28h] BYREF

  v6[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v6, 0, 32);
  adreno_get_gpu_model(a1);
  v3 = strnlen(adreno_get_gpu_model_gpu_model, 0x20u);
  if ( v3 >= 0x21 )
  {
    _fortify_panic(2, 32, v3 + 1);
    goto LABEL_8;
  }
  if ( v3 == 32 )
    v4 = 32;
  else
    v4 = v3 + 1;
  if ( v4 >= 0x21 )
LABEL_8:
    _fortify_panic(7, 32, v4);
  sized_strscpy(v6, adreno_get_gpu_model_gpu_model);
  result = copy_prop(a2, v6, 32);
  _ReadStatusReg(SP_EL0);
  return result;
}
