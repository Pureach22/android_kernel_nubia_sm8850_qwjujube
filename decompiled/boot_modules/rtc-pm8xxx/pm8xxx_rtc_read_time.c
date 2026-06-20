__int64 __fastcall pm8xxx_rtc_read_time(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 result; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 152);
  v6[0] = 0;
  v4 = *(_QWORD *)(v3 + 24);
  result = regmap_bulk_read(*(_QWORD *)(v3 + 8), *(unsigned int *)(v4 + 8), (char *)v6 + 4, 4);
  if ( !(_DWORD)result )
  {
    result = regmap_read(*(_QWORD *)(v3 + 8), *(unsigned int *)(v4 + 8), v6);
    if ( (result & 0x80000000) == 0 )
    {
      if ( LODWORD(v6[0]) >= BYTE4(v6[0])
        || (result = regmap_bulk_read(*(_QWORD *)(v3 + 8), *(unsigned int *)(v4 + 8), (char *)v6 + 4, 4), !(_DWORD)result) )
      {
        rtc_time64_to_tm((unsigned int)(*(_DWORD *)(v3 + 48) + HIDWORD(v6[0])), a2);
        result = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
