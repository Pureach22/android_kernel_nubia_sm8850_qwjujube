__int64 __fastcall util_is_bssid_non_tx(__int64 a1, __int64 a2, int a3)
{
  __int64 rnr_channel_db; // x0
  __int64 v6; // x21
  __int64 v7; // x23
  char v8; // w22
  __int64 v9; // x25
  _QWORD *v10; // x1
  bool v11; // zf
  _QWORD *v13; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (v13 = nullptr, v14[0] = 0, (rnr_channel_db = scm_get_rnr_channel_db(a1)) != 0) )
  {
    v6 = rnr_channel_db;
    qdf_mutex_acquire(rnr_channel_db + 2888);
    v7 = 0;
    v8 = 0;
    do
    {
      v9 = v6 + 48 * v7;
      if ( *(_DWORD *)v9 == a3 )
      {
        v14[0] = 0;
        qdf_list_peek_front((_QWORD *)(v9 + 24), v14);
        v10 = (_QWORD *)v14[0];
        if ( v14[0] )
        {
          while ( 1 )
          {
            v13 = nullptr;
            qdf_list_peek_next((_QWORD *)(v9 + 24), v10, &v13);
            v11 = *(_DWORD *)((char *)&off_18 + v14[0] + 4) == *(_DWORD *)a2
               && *(unsigned __int16 *)((char *)&qword_20 + v14[0]) == *(unsigned __int16 *)(a2 + 4);
            if ( v11 && (*((_BYTE *)&qword_20 + v14[0] + 2) & 0xC) == 4 )
              break;
            v10 = v13;
            v14[0] = v13;
            if ( !v13 )
              goto LABEL_4;
          }
          v8 = 1;
        }
      }
LABEL_4:
      ++v7;
    }
    while ( v7 != 60 );
    qdf_mutex_release(v6 + 2888);
  }
  else
  {
    v8 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v8 & 1;
}
