__int64 __fastcall dot11f_unpack_tlv_ecsa_target_tsf_info_attr(__int64 a1, _BYTE *a2, unsigned __int16 a3, _BYTE *a4)
{
  *a4 = 1;
  if ( a3 && (a4[1] = *a2, a3 > 8u) )
  {
    qdf_mem_copy(a4 + 4, a2 + 1, 4u);
    qdf_mem_copy(a4 + 8, a2 + 5, 4u);
    return 0;
  }
  else
  {
    *a4 = 0;
    return 4;
  }
}
