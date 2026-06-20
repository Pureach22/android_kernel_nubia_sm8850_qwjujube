__int64 __fastcall wlan_objmgr_get_peer_nolock(__int64 a1, char a2, _BYTE *a3, unsigned int a4)
{
  unsigned int v7; // w8
  __int64 v8; // x23
  int v9; // w0
  __int64 v10; // x21
  __int64 result; // x0
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
    v10 = v22[0];
    v12 = v9 == 0;
    result = 0;
    v12 = !v12 || v22[0] == 0;
    if ( !v12 )
    {
      while ( (unsigned int)qdf_mem_cmp((const void *)(v10 + 48), a3, 6u)
           || byte_36[v10] != a2
           || (unsigned int)wlan_objmgr_peer_try_get_ref(v10, a4, v13, v14, v15, v16, v17, v18, v19, v20) )
      {
        v22[0] = 0;
        v21 = qdf_list_peek_next((_QWORD *)(v8 + 128), (_QWORD *)v10, v22);
        result = 0;
        if ( !v21 )
        {
          v10 = v22[0];
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
    result = 0;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
