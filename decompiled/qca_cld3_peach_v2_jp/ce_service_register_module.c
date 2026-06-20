__int64 __fastcall ce_service_register_module(__int64 result, __int64 a2)
{
  if ( (unsigned int)result <= 1 )
    ce_attach_register[(unsigned int)result] = a2;
  return result;
}
