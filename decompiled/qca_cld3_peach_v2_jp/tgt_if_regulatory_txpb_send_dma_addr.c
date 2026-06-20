__int64 __fastcall tgt_if_regulatory_txpb_send_dma_addr(__int64 a1, __int64 a2)
{
  __int64 *v2; // x8
  __int64 v3; // x8

  if ( a1 && (v2 = *(__int64 **)(a1 + 1232)) != nullptr && (v3 = *v2) != 0 )
    return wmi_unified_pdev_pb_mem_ind_send(v3, a2, *(unsigned __int8 *)(a1 + 40));
  else
    return 16;
}
