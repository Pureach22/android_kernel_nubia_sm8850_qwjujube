__int64 __fastcall mlo_sta_set_all_vdevs_connect_req_bmap(__int64 result)
{
  _QWORD *v1; // x8
  _QWORD *v2; // x9

  v1 = *(_QWORD **)(result + 1360);
  if ( v1 )
  {
    v2 = (_QWORD *)v1[278];
    if ( v2 )
    {
      if ( v1[3] )
        *v2 |= 1uLL;
      if ( v1[4] )
        *(_QWORD *)v1[278] |= 2uLL;
    }
  }
  return result;
}
