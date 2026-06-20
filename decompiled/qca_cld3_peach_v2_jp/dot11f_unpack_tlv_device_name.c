__int64 __fastcall dot11f_unpack_tlv_device_name(__int64 a1, const void *a2, unsigned __int16 a3, _BYTE *a4)
{
  *a4 = 1;
  a4[1] = a3;
  if ( a3 < 0x21u )
  {
    qdf_mem_copy(a4 + 2, a2, a3);
    return 0;
  }
  else
  {
    *a4 = 0;
    return 8;
  }
}
