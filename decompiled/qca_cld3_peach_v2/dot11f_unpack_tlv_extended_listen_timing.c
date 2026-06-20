__int64 __fastcall dot11f_unpack_tlv_extended_listen_timing(__int64 a1, __int64 a2, unsigned __int16 a3, _BYTE *a4)
{
  *a4 = 1;
  if ( a3 <= 1u || (qdf_mem_copy(a4 + 2, (const void *)a2, 2u), (a3 & 0xFFFE) == 2) )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy(a4 + 4, (const void *)(a2 + 2), 2u);
    return 0;
  }
}
