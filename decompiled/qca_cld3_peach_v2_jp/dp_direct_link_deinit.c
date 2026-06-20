__int64 __fastcall dp_direct_link_deinit(__int64 result, char a2)
{
  __int64 v2; // x19
  _QWORD *v4; // x20
  __int64 context; // x0
  __int64 v6; // x21
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(result + 1472) )
  {
    v2 = result;
    v7[0] = 0;
    if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(result + 280), v7) )
    {
      do
      {
        v6 = v7[0] - 32LL;
        if ( v7[0] == 32 )
          break;
        if ( *(_DWORD *)(v7[0] - 4LL) == 1 )
          dp_config_direct_link(v7[0] - 32LL, 0, 0);
        v7[0] = 0;
      }
      while ( !(unsigned int)qdf_list_peek_next((_QWORD *)(v2 + 280), (_QWORD *)(v6 + 32), v7) );
    }
    dp_wfds_deinit(*(_QWORD *)(v2 + 1472), a2 & 1);
    v4 = *(_QWORD **)(v2 + 1472);
    context = _cds_get_context(71, "dp_direct_link_refill_ring_deinit");
    if ( context )
    {
      dp_destroy_direct_link_refill_ring(context, *(unsigned __int8 *)(*(_QWORD *)(*v4 + 8LL) + 40LL));
      v4[2] = 0;
    }
    qdf_mutex_destroy(v2 + 1408);
    result = _qdf_mem_free(*(_QWORD *)(v2 + 1472));
    *(_QWORD *)(v2 + 1472) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
