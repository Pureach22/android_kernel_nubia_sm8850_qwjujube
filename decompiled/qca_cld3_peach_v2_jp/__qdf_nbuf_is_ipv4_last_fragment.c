bool __fastcall _qdf_nbuf_is_ipv4_last_fragment(__int64 a1)
{
  return (*(_WORD *)(*(_QWORD *)(a1 + 216) + *(unsigned __int16 *)(a1 + 184) + 6LL) & 0x20) == 0;
}
