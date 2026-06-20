__int64 __fastcall wlan_mlo_iterate_ml_peerlist(__int64 a1, _DWORD *a2, __int64 a3)
{
  __int64 v4; // x24
  __int64 v7; // x25
  int v8; // w0
  _QWORD *v9; // x23
  unsigned int v11; // w20
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v4 = a1 + 48;
  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_mutex_acquire(a1 + 1584);
  v7 = 0;
  while ( 1 )
  {
    v13[0] = 0;
    v8 = qdf_list_peek_front((_QWORD *)(v4 + 24 * v7), v13);
    v9 = (_QWORD *)v13[0];
    if ( !v8 && v13[0] != 0 )
      break;
LABEL_2:
    if ( ++v7 == 64 )
    {
      v11 = 17;
      goto LABEL_14;
    }
  }
  while ( 1 )
  {
    if ( *(a2 - 1) != 1361561092 )
      __break(0x8235u);
    if ( !((unsigned int (__fastcall *)(__int64, _QWORD *, __int64))a2)(a1, v9, a3) )
      break;
    v13[0] = 0;
    if ( !(unsigned int)qdf_list_peek_next((_QWORD *)(v4 + 24 * v7), v9, v13) )
    {
      v9 = (_QWORD *)v13[0];
      if ( v13[0] )
        continue;
    }
    goto LABEL_2;
  }
  v11 = 0;
LABEL_14:
  qdf_mutex_release(a1 + 1584);
  _ReadStatusReg(SP_EL0);
  return v11;
}
