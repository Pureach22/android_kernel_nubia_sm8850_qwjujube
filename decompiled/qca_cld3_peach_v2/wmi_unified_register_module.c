__int64 __fastcall wmi_unified_register_module(__int64 result, __int64 a2)
{
  if ( (unsigned int)result <= 1 )
    wmi_attach_register[(unsigned int)result] = a2;
  return result;
}
