__int64 __fastcall tsens_threshold_violated(__int64 result, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x22
  __int64 v4; // x21
  int v5; // w20

  if ( (unsigned int)(a2 + 105) >= 0x137 )
    goto LABEL_13;
  v3 = result + 48;
  v4 = result;
  v5 = a2;
  result = regmap_field_read(*(_QWORD *)(result + 48 + 8LL * (unsigned int)(a2 + 105)), a3);
  if ( (_DWORD)result )
    return result;
  if ( (unsigned int)(v5 + 25) > 0x136 )
    goto LABEL_13;
  result = regmap_field_read(*(_QWORD *)(v3 + 8LL * (unsigned int)(v5 + 25)), a3 + 4);
  if ( (_DWORD)result )
    return result;
  if ( (*(_BYTE *)(*(_QWORD *)(v4 + 2544) + 4LL) & 1) != 0 )
  {
    if ( (unsigned int)(v5 + 185) <= 0x136 )
    {
      result = regmap_field_read(*(_QWORD *)(v3 + 8LL * (unsigned int)(v5 + 185)), a3 + 8);
      if ( (_DWORD)result )
        return result;
      return *a3 || a3[4] || a3[8] != 0;
    }
LABEL_13:
    __break(0x5512u);
    return tsens_dump_persist_data(result, a2);
  }
  return *a3 || a3[4] || a3[8] != 0;
}
