__int64 __fastcall cm_fill_bss_info_in_connect_rsp_by_cm_id(__int64 a1, int a2, __int64 a3)
{
  _QWORD *v6; // x1
  unsigned int v7; // w20
  _QWORD *v9; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v10[2]; // [xsp+10h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = nullptr;
  v10[0] = 0;
  if ( (a2 & 0xF000000) == 0xC000000 )
  {
    qdf_mutex_acquire(a1 + 120);
    qdf_list_peek_front((_QWORD *)(a1 + 96), v10);
    v6 = (_QWORD *)v10[0];
    if ( v10[0] )
    {
      while ( 1 )
      {
        qdf_list_peek_next((_QWORD *)(a1 + 96), v6, &v9);
        if ( *(_DWORD *)(v10[0] + 16LL) == a2 )
          break;
        v6 = v9;
        v9 = nullptr;
        v10[0] = v6;
        if ( !v6 )
          goto LABEL_5;
      }
      cm_fill_connect_resp_from_req(a3);
      v7 = 0;
    }
    else
    {
LABEL_5:
      v7 = 16;
    }
    qdf_mutex_release(a1 + 120);
  }
  else
  {
    v7 = 4;
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
