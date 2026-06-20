__int64 __fastcall cds_get_global_context(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0

  result = gp_cds_context;
  if ( !gp_cds_context )
  {
    printk(&unk_A3062F, "cds_get_global_context", a3, a4);
    return gp_cds_context;
  }
  return result;
}
