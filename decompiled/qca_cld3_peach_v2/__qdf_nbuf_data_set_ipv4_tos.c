__int64 __fastcall _qdf_nbuf_data_set_ipv4_tos(__int64 result, char a2)
{
  *(_BYTE *)(result + 15) = a2;
  return result;
}
