__int64 __fastcall lim_stop_reassoc_retry_timer(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x19

  v1 = *(_QWORD *)(a1 + 12376);
  *(_BYTE *)(a1 + 12384) = 0;
  if ( v1 )
  {
    v2 = *(_QWORD *)(v1 + 136);
    if ( v2 )
    {
      v3 = a1;
      _qdf_mem_free(v2);
      a1 = v3;
      *(_QWORD *)(*(_QWORD *)(v3 + 12376) + 136LL) = 0;
    }
  }
  return lim_deactivate_and_change_timer(a1, 6);
}
