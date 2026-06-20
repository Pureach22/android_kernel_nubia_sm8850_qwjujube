void __fastcall pe_free_msg(__int64 a1, __int64 a2)
{
  __int64 v2; // x0

  if ( a2 )
  {
    v2 = *(_QWORD *)(a2 + 8);
    if ( v2 )
    {
      if ( *(_WORD *)a2 == 5044 )
        cds_pkt_return_packet(v2);
      else
        _qdf_mem_free(v2);
    }
    *(_QWORD *)(a2 + 8) = 0;
    *(_DWORD *)(a2 + 4) = 0;
    *(_WORD *)a2 = 0;
  }
}
