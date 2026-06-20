__int64 __fastcall tgt_if_regulatory_txpb_send_inference_cmd(__int64 a1)
{
  _QWORD *v1; // x8

  if ( a1 && (v1 = *(_QWORD **)(a1 + 1240)) != nullptr && *v1 )
    return wmi_unified_pdev_pb_send_inference_cmd();
  else
    return 16;
}
