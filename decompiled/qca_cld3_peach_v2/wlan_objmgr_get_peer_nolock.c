_QWORD *__fastcall wlan_objmgr_get_peer_nolock(__int64 a1, unsigned __int8 a2, _BYTE *a3, unsigned int a4)
{
  unsigned int v7; // w8
  __int64 v8; // x23
  int v9; // w0
  _QWORD *v10; // x21
  _QWORD *result; // x0
  bool v12; // zf
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_WORD *)(a1 + 58) )
  {
    v7 = a3[5] & 0x3F;
    v22[0] = 0;
    v8 = a1 + 24LL * v7;
    v9 = qdf_list_peek_front((_QWORD *)(v8 + 128), v22);
    v10 = (_QWORD *)v22[0];
    v12 = v9 == 0;
    result = nullptr;
    v12 = !v12 || v22[0] == 0;
    if ( !v12 )
    {
      while ( (unsigned int)qdf_mem_cmp(v10 + 6, a3, 6u)
           || *((unsigned __int8 *)&qword_30 + (_QWORD)v10 + 6) != a2
           || (unsigned int)wlan_objmgr_peer_try_get_ref((__int64)v10, a4, v13, v14, v15, v16, v17, v18, v19, v20) )
      {
        v22[0] = 0;
        v21 = qdf_list_peek_next((_QWORD *)(v8 + 128), v10, v22);
        result = nullptr;
        if ( !v21 )
        {
          v10 = (_QWORD *)v22[0];
          if ( v22[0] )
            continue;
        }
        goto LABEL_13;
      }
      result = v10;
    }
  }
  else
  {
    result = nullptr;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
