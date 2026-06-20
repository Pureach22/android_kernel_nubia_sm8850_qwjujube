__int64 __fastcall dp_tso_segment_stats_update(__int64 result, __int64 a2, unsigned int a3)
{
  __int64 v4; // x20
  _BYTE dest[176]; // [xsp+8h] [xbp-B8h] BYREF
  __int64 v7; // [xsp+B8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v4 = result;
    memcpy(dest, (const void *)(a2 + 8), sizeof(dest));
    result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _BYTE *))dp_tso_segment_update)(v4, a3, 0, dest);
    if ( *(_QWORD *)a2 )
    {
      memcpy(dest, (const void *)(*(_QWORD *)a2 + 8LL), sizeof(dest));
      result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _BYTE *))dp_tso_segment_update)(v4, a3, 1, dest);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
