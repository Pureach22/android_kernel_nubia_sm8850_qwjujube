_QWORD *__fastcall wlan_mlo_get_mlpeer_by_ml_peerid(__int64 a1, unsigned __int16 a2)
{
  __int64 v3; // x21
  __int64 v5; // x22
  int v6; // w0
  _QWORD *v7; // x1
  _QWORD *v9; // x20
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = a1 + 48;
  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_mutex_acquire(a1 + 1584);
  v5 = 0;
  while ( 1 )
  {
    v11[0] = 0;
    v6 = qdf_list_peek_front((_QWORD *)(v3 + 24 * v5), v11);
    v7 = (_QWORD *)v11[0];
    if ( !v6 && v11[0] != 0 )
      break;
LABEL_2:
    if ( ++v5 == 64 )
    {
      v9 = nullptr;
      goto LABEL_12;
    }
  }
  while ( *(_DWORD *)((char *)&qword_60 + (_QWORD)v7 + 4) != a2 )
  {
    v11[0] = 0;
    if ( !(unsigned int)qdf_list_peek_next((_QWORD *)(v3 + 24 * v5), v7, v11) )
    {
      v7 = (_QWORD *)v11[0];
      if ( v11[0] )
        continue;
    }
    goto LABEL_2;
  }
  v9 = v7;
LABEL_12:
  qdf_mutex_release(a1 + 1584);
  _ReadStatusReg(SP_EL0);
  return v9;
}
