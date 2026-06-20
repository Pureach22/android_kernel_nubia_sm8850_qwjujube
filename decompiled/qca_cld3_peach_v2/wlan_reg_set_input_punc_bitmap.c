__int64 __fastcall wlan_reg_set_input_punc_bitmap(__int64 result, __int16 a2)
{
  if ( result )
    *(_WORD *)(result + 22) = a2;
  return result;
}
