__int64 __fastcall dp_pdev_set_dp_txrx_handle(__int64 result, char a2, __int64 a3)
{
  __int64 v3; // x8

  if ( !a2 )
  {
    v3 = *(_QWORD *)(result + 72);
    if ( v3 )
      *(_QWORD *)(v3 + 95048) = a3;
  }
  return result;
}
