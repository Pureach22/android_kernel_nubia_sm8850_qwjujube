__int64 __fastcall _qdf_nbuf_is_ipv4_fragment(__int64 a1)
{
  return (*(unsigned __int16 *)(*(_QWORD *)(a1 + 216) + *(unsigned __int16 *)(a1 + 184) + 6LL) >> 5) & 1;
}
