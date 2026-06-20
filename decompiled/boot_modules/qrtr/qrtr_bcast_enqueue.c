__int64 __fastcall qrtr_bcast_enqueue(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5, char a6)
{
  _UNKNOWN **i; // x27
  __int64 v12; // x0
  __int64 v13; // x24
  __int64 v14; // x0

  down_read(&qrtr_epts_lock);
  for ( i = (_UNKNOWN **)qrtr_all_epts; i != &qrtr_all_epts; i = (_UNKNOWN **)*i )
  {
    if ( a3 == 2 || *((_DWORD *)i - 27) != -1 )
    {
      v12 = _pskb_copy_fclone(a2, (unsigned int)(*(_DWORD *)(a2 + 224) - *(_DWORD *)(a2 + 216)), 3264, 0);
      if ( !v12 )
        break;
      v13 = v12;
      skb_set_owner_w(v12, *(_QWORD *)(a2 + 24));
      qrtr_node_enqueue((__int64)(i - 21), v13, a3, a4, a5, a6);
    }
  }
  v14 = up_read(&qrtr_epts_lock);
  qrtr_local_enqueue(v14, a2, a3, a4, a5);
  return 0;
}
