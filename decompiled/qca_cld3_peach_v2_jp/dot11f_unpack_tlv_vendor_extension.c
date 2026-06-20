__int64 __fastcall dot11f_unpack_tlv_vendor_extension(__int64 a1, unsigned __int8 *a2, unsigned __int16 a3, _BYTE *a4)
{
  *a4 = 1;
  if ( a3 <= 2u )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy(a4 + 1, a2, 3u);
    return unpack_tlv_core(a2 + 3, (unsigned __int16)(a3 - 3), (unsigned int *)&TLVS_VendorExtension, (__int64)a4);
  }
}
