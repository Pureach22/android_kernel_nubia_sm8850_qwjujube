__int64 __fastcall cam_icp_mgr_flush_req(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  char v3; // w12
  __int64 v4; // x10
  __int64 v5; // x9
  unsigned __int64 v10; // x14
  __int64 v11; // x13
  __int64 v12; // x14
  int v14; // w13

  v2 = 0;
  v3 = 0;
  v4 = 4664;
  v5 = ***(_QWORD ***)(a2 + 16);
  do
  {
    v11 = result + 8 * v2;
    v12 = *(_QWORD *)(v11 + 1784);
    if ( v12 )
      _ZF = v12 == v5;
    else
      _ZF = 0;
    if ( _ZF )
    {
      *(_QWORD *)(v11 + 1784) = 0;
      v14 = *(_DWORD *)(result + v4 - 160);
      if ( v14 )
      {
        *(_DWORD *)(result + v4) = v14;
        *(_DWORD *)(result + v4 - 160) = 0;
      }
      _X12 = *(unsigned __int64 **)(result + 1720);
      __asm { PRFM            #0x11, [X12] }
      do
        v10 = __ldxr(_X12);
      while ( __stxr(v10 & ~(1LL << v2), _X12) );
      v3 = 1;
    }
    ++v2;
    v4 += 4;
  }
  while ( v2 != 40 );
  if ( (v3 & 1) != 0 )
    return cam_icp_mgr_delete_sync_obj(result);
  return result;
}
