__int64 __fastcall set_hfi_buffer_reset(_QWORD *a1)
{
  _QWORD *v1; // x19
  __int64 *v2; // x0
  __int64 *v3; // x20
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 *v6; // x8
  __int64 **v7; // x1
  __int64 v9; // [xsp+0h] [xbp-20h] BYREF
  __int64 v10; // [xsp+8h] [xbp-18h]
  __int64 v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v1 = a1;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v11 = 0;
  v9 = 0;
  while ( !(unsigned int)get_hfi_buffer_queue(a1, &v9, 24) )
  {
    set_hfi_buffer_pool(v1, &v9, 24);
    a1 = v1;
  }
  v2 = (__int64 *)virtqueue_detach_unused_buf(v1[135]);
  if ( v2 )
  {
    v3 = v1 + 125;
    do
    {
      v5 = v2[1];
      v4 = v2[2];
      v9 = *v2;
      v10 = v5;
      v11 = v4;
      v6 = v2 + 3;
      v2[1] = 0;
      v2[2] = 0;
      *v2 = 0;
      v7 = (__int64 **)v1[126];
      if ( v2 + 3 == v3 || v7 == (__int64 **)v6 || *v7 != v3 )
      {
        _list_add_valid_or_report(v2 + 3, v7, v1 + 125);
      }
      else
      {
        v1[126] = v6;
        v2[3] = (__int64)v3;
        v2[4] = (__int64)v7;
        *v7 = v6;
      }
      set_hfi_buffer_pool(v1, &v9, 24);
      v2 = (__int64 *)virtqueue_detach_unused_buf(v1[135]);
    }
    while ( v2 );
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
