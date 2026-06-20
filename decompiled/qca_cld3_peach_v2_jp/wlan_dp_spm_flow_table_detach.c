__int64 __fastcall wlan_dp_spm_flow_table_detach(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 2952);
  if ( result )
  {
    result = _qdf_mem_free(result);
    *(_QWORD *)(a1 + 2952) = 0;
  }
  return result;
}
