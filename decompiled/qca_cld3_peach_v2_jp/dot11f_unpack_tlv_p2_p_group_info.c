__int64 __fastcall dot11f_unpack_tlv_p2_p_group_info(__int64 a1, const void *a2, unsigned __int16 a3, _BYTE *a4)
{
  a4[1] = a3;
  *a4 = 1;
  qdf_mem_copy(a4 + 2, a2, a3);
  return 0;
}
