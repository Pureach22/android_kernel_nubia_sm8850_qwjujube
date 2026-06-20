__int64 __fastcall minbw_data_store(__int64 a1, unsigned __int64 a2)
{
  __int64 result; // x0
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >> 24 )
  {
    result = 4294967274LL;
  }
  else if ( (~*(_DWORD *)(*(_QWORD *)(a1 + 14264) + 32LL) & 0x2000040) != 0 )
  {
    result = 0;
  }
  else
  {
    v3 = a2;
    result = adreno_power_cycle(a1, (void (__fastcall *)(__int64, __int64))set_minbw_data, (__int64)&v3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
