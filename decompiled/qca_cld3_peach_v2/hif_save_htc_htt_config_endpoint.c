__int64 __fastcall hif_save_htc_htt_config_endpoint(__int64 result, int a2)
{
  if ( !result )
    return qdf_trace_msg(61, 2, "%s: scn or scn->hif_sc is NULL!", "hif_save_htc_htt_config_endpoint");
  *(_DWORD *)(result + 724) = a2;
  return result;
}
