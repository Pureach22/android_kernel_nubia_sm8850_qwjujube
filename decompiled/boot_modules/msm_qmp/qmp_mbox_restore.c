__int64 __fastcall qmp_mbox_restore(__int64 a1)
{
  __int64 v1; // x22
  __int64 v2; // x0
  __int64 i; // x19
  __int64 v4; // x0
  _QWORD v6[11]; // [xsp+8h] [xbp-58h] BYREF

  v6[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(_QWORD *)(a1 + 744);
  memset(v6, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v2, "qcom,qmp", 0, 0, 0, v6) || !v6[0] )
  {
    for ( i = *(_QWORD *)(v1 + 16); i != v1 + 16; i = *(_QWORD *)i )
    {
      *(_DWORD *)(i + 264) = 0;
      *(_DWORD *)(i + 328) = 0;
      _init_swait_queue_head(i + 336, "&x->wait", &init_completion___key);
      *(_DWORD *)(i + 360) = 0;
      _init_swait_queue_head(i + 368, "&x->wait", &init_completion___key);
      v4 = *(_QWORD *)(i + 200);
      *(_BYTE *)(i + 177) = 0;
      *(_BYTE *)(i + 504) = 1;
      kfree(v4);
      *(_QWORD *)(i + 200) = 0;
      if ( *(_BYTE *)(v1 + 152) == 1 )
        _qmp_rx_worker(i);
    }
  }
  if ( *(_BYTE *)(v1 + 153) == 1 )
    *(_BYTE *)(v1 + 153) = 0;
  if ( *(_BYTE *)(v1 + 154) == 1 )
    *(_BYTE *)(v1 + 154) = 0;
  _ReadStatusReg(SP_EL0);
  return 0;
}
