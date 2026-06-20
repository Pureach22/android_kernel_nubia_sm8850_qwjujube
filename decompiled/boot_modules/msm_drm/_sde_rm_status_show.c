__int64 __fastcall sde_rm_status_show(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x22
  __int64 i; // x20
  int v5; // w4
  int v6; // w5
  _QWORD *v7; // x8
  _QWORD *v8; // x9

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 128);
  if ( !v1 )
    return 4294967274LL;
  v3 = v1 + 24;
  for ( i = 2; i != 15; ++i )
  {
    v7 = (_QWORD *)(v3 + 16 * i);
    v8 = (_QWORD *)*v7;
    if ( (_QWORD *)*v7 == v7 )
    {
      v5 = 0;
      v6 = 0;
    }
    else
    {
      v6 = 0;
      v5 = 0;
      do
      {
        if ( v8[2] || v8[3] )
          ++v5;
        else
          ++v6;
        v8 = (_QWORD *)*v8;
      }
      while ( v8 != v7 );
    }
    seq_printf(a1, "type:%d blk:%s allocated:%d unallocated:%d\n", i, &sde_hw_blk_str[16 * i], v5, v6);
  }
  return 0;
}
