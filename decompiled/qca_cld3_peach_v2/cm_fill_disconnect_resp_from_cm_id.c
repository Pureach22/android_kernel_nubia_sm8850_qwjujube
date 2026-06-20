__int64 __fastcall cm_fill_disconnect_resp_from_cm_id(__int64 a1, int a2, __int64 a3)
{
  _QWORD *v6; // x1
  __int64 v7; // x8
  unsigned int v8; // w21
  int v9; // w9
  __int64 v10; // x10
  __int64 v11; // x8
  _QWORD *v13; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = nullptr;
  v14[0] = 0;
  if ( (a2 & 0xF000000) == 0xD000000 )
  {
    qdf_mutex_acquire(a1 + 120);
    qdf_list_peek_front((_QWORD *)(a1 + 96), v14);
    v6 = (_QWORD *)v14[0];
    if ( v14[0] )
    {
      while ( 1 )
      {
        qdf_list_peek_next((_QWORD *)(a1 + 96), v6, &v13);
        v7 = v14[0];
        if ( *(_DWORD *)(v14[0] + 16LL) == a2 )
          break;
        v6 = v13;
        v13 = nullptr;
        v14[0] = v6;
        if ( !v6 )
          goto LABEL_5;
      }
      *(_DWORD *)a3 = a2;
      v8 = 0;
      v9 = *(_DWORD *)(v7 + 44);
      v10 = *(_QWORD *)(v7 + 36);
      v11 = *(_QWORD *)(v7 + 28);
      *(_DWORD *)(a3 + 20) = v9;
      *(_QWORD *)(a3 + 12) = v10;
      *(_QWORD *)(a3 + 4) = v11;
    }
    else
    {
LABEL_5:
      v8 = 16;
    }
    qdf_mutex_release(a1 + 120);
  }
  else
  {
    v8 = 4;
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
