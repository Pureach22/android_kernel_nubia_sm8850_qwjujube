__int64 __fastcall rmnet_shs_cpu_ooo(__int64 result, int a2)
{
  if ( (unsigned __int8)result <= 7u )
    rmnet_shs_cpu_ooo_count[(unsigned __int8)result] += a2;
  return result;
}
