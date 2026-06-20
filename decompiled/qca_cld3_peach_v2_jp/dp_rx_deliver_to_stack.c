__int64 __fastcall dp_rx_deliver_to_stack(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x22
  _DWORD *v9; // x8
  __int64 v10; // x0
  __int64 (__fastcall *v11)(__int64, __int64, __int64); // x8
  __int64 result; // x0
  __int64 (__fastcall *v13)(__int64, __int64); // x8
  __int64 v14; // x0
  __int64 v15; // x21
  __int64 v16; // x0
  __int64 v17; // x26
  __int64 v18; // x8
  __int64 v19; // x10
  int v20; // w20
  __int64 v21; // x21
  __int64 v22; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF

  v5 = a4;
  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = a5;
  v23[0] = a4;
  if ( !a2 || *(_DWORD *)(a2 + 272) )
  {
    v20 = 0;
    if ( a4 )
    {
      do
      {
        v21 = *(_QWORD *)v5;
        _qdf_nbuf_free(v5);
        ++v20;
        v5 = v21;
      }
      while ( v21 );
    }
    result = 16;
    if ( a1 )
      *(_DWORD *)(a1 + 13692) += v20;
  }
  else
  {
    if ( !*(_QWORD *)(a2 + 160) )
    {
      if ( a3 )
        dp_rx_enqueue_rx(a3, a4);
      else
        ((void (__fastcall *)(_QWORD, __int64))dp_rx_drop_nbuf_list)(*(_QWORD *)(a2 + 24), a4);
      result = 16;
      goto LABEL_28;
    }
    if ( *(_DWORD *)(a2 + 44) <= 1u )
    {
      v9 = *(_DWORD **)(a2 + 200);
      v10 = *(_QWORD *)(a2 + 88);
      if ( *(v9 - 1) != 1488343003 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *, __int64 *))v9)(v10, v23, &v22);
      v5 = v23[0];
    }
    v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a2 + 176);
    if ( v11 )
    {
      if ( *((_DWORD *)v11 - 1) != -451078002 )
        __break(0x8228u);
      result = v11(a1, a2, v5);
      if ( !(_DWORD)result )
        goto LABEL_28;
LABEL_17:
      if ( v5 )
      {
        v15 = *(_QWORD *)(a2 + 24);
        v16 = v5;
        LODWORD(v5) = 0;
        do
        {
          v17 = *(_QWORD *)v16;
          if ( v15 )
          {
            if ( ((*(_QWORD *)(v16 + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(v16 + 87) & 0xFu) >= 0xA )
              __break(0x5512u);
            v18 = v15 + 41856 + 5472 * ((*(_QWORD *)(v16 + 72) >> 18) & 0xFLL) + 608LL * (*(_BYTE *)(v16 + 87) & 0xF);
            v19 = *(_QWORD *)(v18 + 256) - 1LL;
            ++*(_QWORD *)(v18 + 312);
            *(_QWORD *)(v18 + 256) = v19;
          }
          _qdf_nbuf_free(v16);
          LODWORD(v5) = v5 + 1;
          v16 = v17;
        }
        while ( v17 );
      }
      if ( a1 )
        *(_DWORD *)(a1 + 14092) += v5;
      result = 0;
      if ( a3 )
        *(_QWORD *)(a3 + 32) -= (int)v5;
      goto LABEL_28;
    }
    v13 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 160);
    if ( !v13 )
      goto LABEL_17;
    v14 = *(_QWORD *)(a2 + 88);
    if ( *((_DWORD *)v13 - 1) != 424933381 )
      __break(0x8228u);
    result = v13(v14, v5);
    if ( (_DWORD)result )
      goto LABEL_17;
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
