__int64 __fastcall cm_get_first_roam_command(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  __int64 v10; // x19
  _QWORD *v11; // x1
  __int64 v12; // x21
  _QWORD *v13; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = nullptr;
  v14[0] = 0;
  result = cm_get_cm_ctx_fl(a1, (__int64)"cm_get_first_roam_command", 0x104u, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v10 = result;
    cm_req_lock_acquire(result);
    qdf_list_peek_front((_QWORD *)(v10 + 96), v14);
    v11 = (_QWORD *)v14[0];
    if ( v14[0] )
    {
      while ( 1 )
      {
        qdf_list_peek_next((_QWORD *)(v10 + 96), v11, &v13);
        v12 = v14[0];
        if ( (~*(_DWORD *)(v14[0] + 16LL) & 0xF000000) == 0 )
          break;
        v11 = v13;
        v13 = nullptr;
        v14[0] = v11;
        if ( !v11 )
          goto LABEL_5;
      }
      cm_req_lock_release(v10);
      result = v12 + 24;
    }
    else
    {
LABEL_5:
      cm_req_lock_release(v10);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
