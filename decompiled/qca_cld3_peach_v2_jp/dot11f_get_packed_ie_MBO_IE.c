__int64 __fastcall dot11f_get_packed_ie_MBO_IE(__int64 a1, _BYTE *a2, __int64 a3)
{
  if ( *a2 )
    return get_packed_size_tlv_core(a2, a3, &TLVS_MBO_IE);
  else
    return 0;
}
