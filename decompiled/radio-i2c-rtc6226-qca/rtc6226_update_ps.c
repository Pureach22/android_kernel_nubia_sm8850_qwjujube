__int64 __fastcall rtc6226_update_ps(__int64 result, unsigned __int8 a2, unsigned __int8 a3)
{
  _QWORD *v3; // x20
  int v4; // w11
  _BYTE *v5; // x10
  unsigned int v6; // w11
  char v7; // w9
  __int64 v8; // x12
  unsigned int v9; // w13
  char v10; // w14
  int v11; // w8
  bool v12; // cf
  int v13; // w8
  unsigned int v14; // w8
  unsigned int v15; // w8
  unsigned int v16; // w8
  unsigned int v17; // w8
  unsigned int v18; // w8
  unsigned int v19; // w8
  unsigned int v20; // w8
  __int64 v21; // x22
  __int64 v22; // x0
  __int64 v23; // x19
  char v24; // w10
  __int16 v25; // w11
  __int64 v26; // x10
  __int64 v27; // x20
  __int64 v28; // x20
  int v29; // w21
  char v30[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v3 = (_QWORD *)(result + 2828);
  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)(result + 2828 + a2);
  if ( v4 == a3 )
  {
    v5 = (_BYTE *)(result + 2844);
    v6 = *(unsigned __int8 *)(result + 2844 + a2);
    if ( v6 <= 1 )
    {
      v7 = v6 + 1;
LABEL_30:
      v5[a2] = v7;
      goto LABEL_31;
    }
    v5[a2] = 2;
    *(_BYTE *)(result + a2 + 2836) = a3;
  }
  else
  {
    v8 = result + 2836;
    v5 = (_BYTE *)(result + 2844);
    v9 = *(unsigned __int8 *)(result + 2844 + a2);
    if ( *(unsigned __int8 *)(result + 2836 + a2) == a3 )
    {
      *(_BYTE *)(v8 + a2) = v4;
      if ( v9 <= 1 )
        v10 = 2;
      else
        v10 = 3;
      v5[a2] = v10;
      *((_BYTE *)v3 + a2) = a3;
      if ( v9 >= 2 )
      {
        v11 = (unsigned __int8)*v5;
        v12 = v11 != 0;
        v13 = v11 - 1;
        if ( v13 != 0 && v12 )
          *v5 = v13;
        v14 = *(unsigned __int8 *)(result + 2845);
        if ( v14 >= 2 )
          *(_BYTE *)(result + 2845) = v14 - 1;
        v15 = *(unsigned __int8 *)(result + 2846);
        if ( v15 >= 2 )
          *(_BYTE *)(result + 2846) = v15 - 1;
        v16 = *(unsigned __int8 *)(result + 2847);
        if ( v16 >= 2 )
          *(_BYTE *)(result + 2847) = v16 - 1;
        v17 = *(unsigned __int8 *)(result + 2848);
        if ( v17 >= 2 )
          *(_BYTE *)(result + 2848) = v17 - 1;
        v18 = *(unsigned __int8 *)(result + 2849);
        if ( v18 >= 2 )
          *(_BYTE *)(result + 2849) = v18 - 1;
        v19 = *(unsigned __int8 *)(result + 2850);
        if ( v19 >= 2 )
          *(_BYTE *)(result + 2850) = v19 - 1;
        v20 = *(unsigned __int8 *)(result + 2851);
        if ( v20 >= 2 )
          *(_BYTE *)(result + 2851) = v20 - 1;
      }
    }
    else
    {
      if ( !*(_BYTE *)(result + 2844 + a2) )
      {
        *((_BYTE *)v3 + a2) = a3;
        v7 = 1;
        goto LABEL_30;
      }
      *(_BYTE *)(v8 + a2) = a3;
    }
  }
LABEL_31:
  if ( *(unsigned __int8 *)(result + 2844) >= 2u
    && *(unsigned __int8 *)(result + 2845) >= 2u
    && *(unsigned __int8 *)(result + 2846) >= 2u
    && *(unsigned __int8 *)(result + 2847) >= 2u
    && *(unsigned __int8 *)(result + 2848) >= 2u
    && *(unsigned __int8 *)(result + 2849) >= 2u
    && *(unsigned __int8 *)(result + 2850) >= 2u
    && *(unsigned __int8 *)(result + 2851) >= 2u
    && (*(unsigned __int8 *)(result + 2820) != *(unsigned __int8 *)(result + 2828)
     || *(unsigned __int8 *)(result + 2821) != *(unsigned __int8 *)(result + 2829)
     || *(unsigned __int8 *)(result + 2822) != *(unsigned __int8 *)(result + 2830)
     || *(unsigned __int8 *)(result + 2823) != *(unsigned __int8 *)(result + 2831)
     || *(unsigned __int8 *)(result + 2824) != *(unsigned __int8 *)(result + 2832)
     || *(unsigned __int8 *)(result + 2825) != *(unsigned __int8 *)(result + 2833)
     || *(unsigned __int8 *)(result + 2826) != *(unsigned __int8 *)(result + 2834)
     || *(unsigned __int8 *)(result + 2827) != *(unsigned __int8 *)(result + 2835)) )
  {
    v21 = result;
    *(_QWORD *)(result + 2820) = *(_QWORD *)(result + 2828);
    v22 = _kmalloc_cache_noprof(init_wait_entry, 2080, 13);
    v23 = v22;
    if ( v22 )
    {
      v24 = *(_BYTE *)(v21 + 2552);
      v25 = *(_WORD *)(v21 + 2550);
      *(_BYTE *)v22 = 1;
      *(_BYTE *)(v22 + 1) = v24;
      v26 = *v3;
      *(_WORD *)(v22 + 3) = (unsigned __int8)v25;
      *(_BYTE *)(v22 + 2) = HIBYTE(v25);
      *(_QWORD *)(v22 + 5) = v26;
      v27 = raw_spin_lock_irqsave(v21 + 1984);
      _kfifo_in(v21 + 3208, v23, 13);
      raw_spin_unlock_irqrestore(v21 + 1984, v27);
      v30[0] = 6;
      v28 = raw_spin_lock_irqsave(v21 + 1976);
      v29 = _kfifo_in(v21 + 3160, v30, 1);
      raw_spin_unlock_irqrestore(v21 + 1976, v28);
      if ( v29 )
        _wake_up(v21 + 2520, 1, 1, 0);
      result = kfree(v23);
    }
    else
    {
      result = printk(&unk_DBBA, "rtc6226_update_ps");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
