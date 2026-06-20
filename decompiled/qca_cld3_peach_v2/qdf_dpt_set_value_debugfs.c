__int64 __fastcall qdf_dpt_set_value_debugfs(__int64 result, char a2, char a3, __int16 a4)
{
  if ( byte_7F7658 == 1 )
  {
    byte_7F7650 = a2;
    dword_7F764C = (unsigned __int8)result;
    byte_7F7656 = a3;
    LOWORD(dword_7F7652) = a4;
  }
  return result;
}
