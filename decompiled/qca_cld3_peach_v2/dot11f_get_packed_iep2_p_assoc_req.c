__int64 __fastcall dot11f_get_packed_iep2_p_assoc_req(__int64 a1, _BYTE *a2, int *a3)
{
  if ( *a2 )
    return get_packed_size_tlv_core((__int64)a2, a3, (unsigned int *)&TLVS_P2PAssocReq);
  else
    return 0;
}
