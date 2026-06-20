__int64 __fastcall dot11f_unpack_tlv_request_device_type(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned __int16 a3,
        __int64 a4)
{
  __int64 result; // x0

  *(_BYTE *)a4 = 1;
  if ( a3 <= 1u
    || (*(_WORD *)(a4 + 2) = bswap32(*a2) >> 16, (unsigned int)a3 - 2 <= 3)
    || (qdf_mem_copy((void *)(a4 + 4), a2 + 1, 4u), (a3 & 0xFFFE) == 6) )
  {
    *(_BYTE *)a4 = 0;
    return 4;
  }
  else
  {
    result = 0;
    *(_WORD *)(a4 + 8) = bswap32(a2[3]) >> 16;
  }
  return result;
}
