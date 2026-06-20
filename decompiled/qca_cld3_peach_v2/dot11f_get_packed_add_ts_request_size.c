__int64 __fastcall dot11f_get_packed_add_ts_request_size(__int64 a1, __int64 a2, int *a3)
{
  *a3 = 3;
  return get_packed_size_core(a1, a2, a3, IES_AddTSRequest);
}
