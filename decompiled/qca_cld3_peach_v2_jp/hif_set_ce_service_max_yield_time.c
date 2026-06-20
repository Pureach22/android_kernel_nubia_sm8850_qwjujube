__int64 __fastcall hif_set_ce_service_max_yield_time(__int64 result, int a2)
{
  *(_QWORD *)(result + 2448) = (unsigned int)(1000 * a2);
  return result;
}
