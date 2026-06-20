__int64 __fastcall dot11f_unpack_tlv_p2_p_device_info(__int64 a1, __int64 a2, unsigned __int16 a3, _BYTE *a4)
{
  *a4 = 1;
  if ( a3 <= 5u
    || (qdf_mem_copy(a4 + 1, (const void *)a2, 6u), (a3 & 0xFFFE) == 6)
    || (qdf_mem_copy(a4 + 8, (const void *)(a2 + 6), 2u), (a3 & 0xFFF8) == 8) )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy(a4 + 10, (const void *)(a2 + 8), 8u);
    return unpack_tlv_core(a2 + 16, (unsigned __int16)(a3 - 16), &TLVS_P2PDeviceInfo, a4);
  }
}
