__int64 __fastcall qdf_dpt_set_value_debugfs(__int64 result, char a2, char a3, __int16 a4)
{
  if ( byte_73EC28 == 1 )
  {
    byte_73EC20 = a2;
    dword_73EC1C = (unsigned __int8)result;
    byte_73EC26 = a3;
    LOWORD(dword_73EC22) = a4;
  }
  return result;
}
