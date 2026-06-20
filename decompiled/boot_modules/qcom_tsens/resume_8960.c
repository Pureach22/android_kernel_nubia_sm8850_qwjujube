__int64 __fastcall resume_8960(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16);
  result = regmap_update_bits_base(v1, 13856, 2, 2, 0, 0, 0);
  if ( !(_DWORD)result )
  {
    if ( *(_DWORD *)(a1 + 8) < 2u || (result = regmap_update_bits_base(v1, 13888, 15, 155, 0, 0, 0), !(_DWORD)result) )
    {
      result = regmap_write(v1, 13860, *(unsigned int *)(a1 + 2536));
      if ( !(_DWORD)result )
        return regmap_write(v1, 13856, *(unsigned int *)(a1 + 2540));
    }
  }
  return result;
}
