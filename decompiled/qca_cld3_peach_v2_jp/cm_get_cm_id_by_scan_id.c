__int64 __fastcall cm_get_cm_id_by_scan_id(__int64 a1, int a2)
{
  _QWORD *v4; // x1
  __int64 v5; // x21
  __int64 result; // x0
  _QWORD *v7; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v8[2]; // [xsp+10h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = nullptr;
  v8[0] = 0;
  qdf_mutex_acquire(a1 + 120);
  qdf_list_peek_front((_QWORD *)(a1 + 96), v8);
  v4 = (_QWORD *)v8[0];
  if ( v8[0] )
  {
    while ( 1 )
    {
      qdf_list_peek_next((_QWORD *)(a1 + 96), v4, &v7);
      v5 = v8[0];
      if ( *(_DWORD *)(v8[0] + 28LL) == a2 )
        break;
      v4 = v7;
      v7 = nullptr;
      v8[0] = v4;
      if ( !v4 )
        goto LABEL_4;
    }
    qdf_mutex_release(a1 + 120);
    result = *(unsigned int *)(v5 + 16);
  }
  else
  {
LABEL_4:
    qdf_mutex_release(a1 + 120);
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
