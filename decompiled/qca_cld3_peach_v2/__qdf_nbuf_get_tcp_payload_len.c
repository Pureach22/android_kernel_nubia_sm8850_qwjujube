unsigned __int64 __fastcall _qdf_nbuf_get_tcp_payload_len(__int64 a1)
{
  return *(unsigned int *)(a1 + 112)
       + (unsigned __int64)*(unsigned __int16 *)(a1 + 186)
       - *(unsigned __int16 *)(a1 + 182)
       - (((unsigned __int64)*(unsigned __int16 *)(*(_QWORD *)(a1 + 216) + *(unsigned __int16 *)(a1 + 182) + 12LL) >> 2)
        & 0x3C);
}
