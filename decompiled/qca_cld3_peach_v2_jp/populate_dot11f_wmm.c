__int64 __fastcall populate_dot11f_wmm(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  char v7; // w9

  if ( (*(_BYTE *)(a5 + 7024) & 2) != 0 )
  {
    result = populate_dot11f_wmm_params(result, a3, a5);
    if ( (*(_BYTE *)(a5 + 7024) & 4) != 0 )
    {
      v7 = *(_BYTE *)(a4 + 2) & 0xF | 0x20;
      *(_WORD *)a4 = 257;
      *(_BYTE *)(a4 + 2) = v7;
    }
  }
  return result;
}
