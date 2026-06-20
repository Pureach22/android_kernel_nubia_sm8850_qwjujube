__int64 __fastcall dot11f_get_packed_ie_wsc_reassoc_res(__int64 a1, _BYTE *a2, int *a3)
{
  if ( *a2 )
    return get_packed_size_tlv_core((__int64)a2, a3, (unsigned int *)&TLVS_WscReassocRes);
  else
    return 0;
}
