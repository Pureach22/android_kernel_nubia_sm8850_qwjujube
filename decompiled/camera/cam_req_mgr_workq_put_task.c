__int64 __fastcall cam_req_mgr_workq_put_task(__int64 a1)
{
  _QWORD *v1; // x8
  _QWORD *v2; // x20
  __int64 v3; // x21
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x2
  _QWORD *v8; // x1
  unsigned int v16; // w10

  v1 = *(_QWORD **)(a1 + 40);
  v2 = (_QWORD *)(a1 + 32);
  v3 = *(_QWORD *)(a1 + 24);
  if ( *v1 == a1 + 32 && (v5 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
  {
    *(_QWORD *)(v5 + 8) = v1;
    *v1 = v5;
  }
  else
  {
    _list_del_entry_valid_or_report(a1 + 32);
  }
  *(_QWORD *)(a1 + 32) = a1 + 32;
  *(_QWORD *)(a1 + 40) = v2;
  *(_BYTE *)(a1 + 48) = 0;
  *(_QWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 56) = 0;
  if ( *(_DWORD *)(v3 + 44) )
  {
    v6 = raw_spin_lock_irqsave(v3 + 40);
  }
  else
  {
    raw_spin_lock_bh(v3 + 40);
    v6 = 0;
  }
  v7 = v3 + 280;
  v8 = *(_QWORD **)(v3 + 288);
  if ( v2 == (_QWORD *)(v3 + 280) || v8 == v2 || *v8 != v7 )
  {
    _list_add_valid_or_report(v2);
  }
  else
  {
    *(_QWORD *)(v3 + 288) = v2;
    *(_QWORD *)(a1 + 32) = v7;
    *(_QWORD *)(a1 + 40) = v8;
    *v8 = v2;
  }
  _X8 = (unsigned int *)(v3 + 244);
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 + 1, _X8) );
  if ( *(_DWORD *)(v3 + 44) )
    return raw_spin_unlock_irqrestore(v3 + 40, v6);
  else
    return raw_spin_unlock_bh(v3 + 40);
}
