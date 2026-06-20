__int64 __fastcall fastrpc_channel_default_user_delete(__int64 a1)
{
  __int64 v1; // x20

  v1 = *(_QWORD *)(a1 + 64248);
  if ( !v1 )
    return 4294967274LL;
  fastrpc_free_user(*(_QWORD **)(a1 + 64248));
  kfree(v1);
  *(_QWORD *)(a1 + 64248) = 0;
  return 0;
}
