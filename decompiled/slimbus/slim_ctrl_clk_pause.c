__int64 __fastcall slim_ctrl_clk_pause(__int64 a1, char a2, unsigned __int8 a3)
{
  __int64 result; // x0
  int v6; // w8
  __int64 (__fastcall *v7)(_QWORD); // x8
  unsigned int v8; // w0
  unsigned int v9; // w20
  __int64 v10; // x20
  __int64 i; // x21
  unsigned int v12; // w0
  __int64 v13; // x1
  _QWORD v14[3]; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v15[2]; // [xsp+20h] [xbp-30h] BYREF
  char *v16; // [xsp+30h] [xbp-20h]
  __int64 v17; // [xsp+38h] [xbp-18h]
  unsigned __int8 v18; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+48h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = a3;
  v16 = nullptr;
  v17 = 0;
  v15[0] = 0;
  v15[1] = 0;
  v14[0] = 0xFF00000003400003LL;
  v14[1] = v15;
  v14[2] = 0;
  if ( a3 < 3u || (a2 & 1) != 0 )
  {
    mutex_lock(a1 + 216);
    v6 = *(_DWORD *)(a1 + 176);
    if ( (a2 & 1) != 0 )
    {
      if ( v6 )
      {
        if ( !(unsigned int)wait_for_completion_timeout(a1 + 184, 25) )
        {
          mutex_unlock(a1 + 216);
          printk(&unk_8791, v13);
          result = 4294967186LL;
          goto LABEL_25;
        }
        if ( *(_DWORD *)(a1 + 176) != 2 )
          goto LABEL_12;
        v7 = *(__int64 (__fastcall **)(_QWORD))(a1 + 304);
        if ( !v7 )
          goto LABEL_12;
        if ( *((_DWORD *)v7 - 1) != 1028036439 )
          __break(0x8228u);
        v8 = v7(a1);
        if ( !v8 )
        {
LABEL_12:
          v8 = 0;
          *(_DWORD *)(a1 + 176) = 0;
        }
        v9 = v8;
        goto LABEL_23;
      }
    }
    else if ( v6 != 2 )
    {
      v10 = raw_spin_lock_irqsave(a1 + 168);
      for ( i = 0; i != 256; ++i )
      {
        if ( idr_find(a1 + 144, i) )
        {
          raw_spin_unlock_irqrestore(a1 + 168, v10);
          mutex_unlock(a1 + 216);
          result = 4294967280LL;
          goto LABEL_25;
        }
      }
      raw_spin_unlock_irqrestore(a1 + 168, v10);
      *(_DWORD *)(a1 + 176) = 1;
      v12 = slim_do_transfer((_QWORD *)a1, (unsigned __int8 *)v14);
      if ( v12 )
        goto LABEL_22;
      BYTE2(v14[0]) = 74;
      LOBYTE(v14[0]) = 4;
      BYTE2(v15[0]) = 1;
      v16 = (char *)&v18;
      v12 = slim_do_transfer((_QWORD *)a1, (unsigned __int8 *)v14);
      if ( v12
        || (BYTE2(v14[0]) = 95,
            LOBYTE(v14[0]) = 3,
            BYTE2(v15[0]) = 1,
            v16 = nullptr,
            (v12 = slim_do_transfer((_QWORD *)a1, (unsigned __int8 *)v14)) != 0) )
      {
LABEL_22:
        v9 = v12;
        *(_DWORD *)(a1 + 176) = 0;
      }
      else
      {
        *(_DWORD *)(a1 + 176) = 2;
        complete(a1 + 184);
        v9 = 0;
      }
LABEL_23:
      mutex_unlock(a1 + 216);
      result = v9;
      goto LABEL_25;
    }
    mutex_unlock(a1 + 216);
    result = 0;
    goto LABEL_25;
  }
  result = 4294967274LL;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
