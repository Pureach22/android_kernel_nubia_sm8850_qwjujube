__int64 __fastcall adreno_regmap_op_preaccess(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 24);
  if ( (*(_BYTE *)(result + 11304) & 1) == 0 && (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) == 0 )
    return kgsl_pre_hwaccess(result, a2);
  return result;
}
