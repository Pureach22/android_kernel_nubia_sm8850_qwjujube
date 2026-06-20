__int64 __fastcall dp_rx_fisa_flush_by_ctx_id(__int64 a1, int a2)
{
  __int64 context; // x0
  __int64 v4; // x1
  __int64 *v5; // x21
  __int64 v6; // x20
  __int64 v7; // x23
  __int64 *v8; // x8
  unsigned __int64 StatusReg; // x9
  __int64 *v10; // x8
  __int64 v11; // x9
  __int16 v13; // w9
  __int64 v14; // x0

  context = dp_get_context();
  v5 = *(__int64 **)(context + 1480);
  v6 = *v5;
  v7 = *((unsigned __int16 *)v5 + 16);
  if ( *((_BYTE *)v5 + 608) == 1 )
  {
    if ( (unsigned __int8)a2 >= 9u )
      goto LABEL_20;
    v8 = &v5[2 * (a2 & 0xF)];
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
      {
        context = raw_spin_lock_bh(v8 + 55);
        v5[2 * (a2 & 0xF) + 56] |= 1uLL;
        if ( !(_DWORD)v7 )
          goto LABEL_8;
        do
        {
LABEL_17:
          if ( *(unsigned __int8 *)(v6 + 144) == a2 && *(_BYTE *)(v6 + 40) )
          {
            v13 = *(_WORD *)(v6 + 194);
            v14 = *(_QWORD *)(v6 + 152);
            *(_WORD *)(v6 + 62) = *(_WORD *)(v6 + 56);
            *(_WORD *)(v6 + 64) = v13;
            context = dp_rx_fisa_flush_flow(v14, v6);
            *(_WORD *)(v6 + 60) = 0;
          }
          --v7;
          v6 += 336;
        }
        while ( v7 );
        goto LABEL_8;
      }
    }
    context = raw_spin_lock(v8 + 55);
  }
  if ( (_DWORD)v7 )
    goto LABEL_17;
LABEL_8:
  if ( *((_BYTE *)v5 + 608) != 1 )
    return 0;
  if ( (unsigned __int8)a2 < 9u )
  {
    v10 = &v5[2 * (a2 & 0xF)];
    v11 = v10[56];
    if ( (v11 & 1) != 0 )
    {
      v10[56] = v11 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v10 + 55);
    }
    else
    {
      raw_spin_unlock(v10 + 55);
    }
    return 0;
  }
LABEL_20:
  __break(0x5512u);
  return dp_rx_fisa_flush_flow(context, v4);
}
