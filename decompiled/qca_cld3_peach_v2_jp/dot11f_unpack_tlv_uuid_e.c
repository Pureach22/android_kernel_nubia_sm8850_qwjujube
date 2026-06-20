__int64 __fastcall dot11f_unpack_tlv_uuid_e(__int64 a1, const void *a2, unsigned __int16 a3, _BYTE *a4)
{
  *a4 = 1;
  if ( a3 <= 0xFu )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy(a4 + 1, a2, 0x10u);
    return 0;
  }
}
