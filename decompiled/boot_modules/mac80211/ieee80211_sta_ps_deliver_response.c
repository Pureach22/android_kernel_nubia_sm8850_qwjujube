_QWORD *__fastcall ieee80211_sta_ps_deliver_response(
        _QWORD *result,
        unsigned int a2,
        unsigned __int8 a3,
        unsigned int a4)
{
  int v4; // w28
  _QWORD *v5; // x25
  __int64 v6; // x8
  __int64 v8; // x23
  __int64 v9; // x21
  __int64 v10; // x8
  unsigned __int64 v11; // x22
  _QWORD *v12; // x24
  _QWORD *v13; // x25
  _QWORD *v14; // x8
  _QWORD *v15; // x24
  _QWORD *v16; // x11
  _QWORD *v17; // x20
  __int64 v18; // x3
  __int64 v19; // x5
  __int64 v20; // x26
  unsigned int v21; // w8
  _QWORD *v22; // x14
  __int64 v23; // x1
  __int64 v24; // x3
  _QWORD *v25; // x8
  __int64 v26; // x13
  _QWORD *v27; // x14
  _QWORD *v28; // x15
  _WORD *v29; // x13
  int v30; // w14
  int v31; // w15
  __int16 v32; // w14
  __int64 *v33; // x14
  char v34; // w16
  __int64 v35; // x10
  _BYTE *v36; // x10
  _BYTE *v37; // x9
  int v38; // w20
  _DWORD *v39; // x8
  __int64 v40; // x8
  __int64 v41; // x9
  _DWORD *v42; // x8
  __int64 v43; // x1
  unsigned __int64 v50; // x9
  __int64 v51; // [xsp+0h] [xbp-60h]
  _QWORD *v54; // [xsp+10h] [xbp-50h]
  _QWORD *v55; // [xsp+18h] [xbp-48h]
  _QWORD *v56; // [xsp+20h] [xbp-40h]
  __int64 v57; // [xsp+28h] [xbp-38h] BYREF
  __int64 *v58; // [xsp+30h] [xbp-30h]
  __int64 v59; // [xsp+38h] [xbp-28h]
  _QWORD *v60; // [xsp+40h] [xbp-20h] BYREF
  _QWORD **v61; // [xsp+48h] [xbp-18h]
  __int64 v62; // [xsp+50h] [xbp-10h]
  __int64 v63; // [xsp+58h] [xbp-8h]

  v4 = a2;
  v5 = result;
  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = result[10];
  v61 = nullptr;
  v62 = 0;
  v60 = nullptr;
  v51 = *(_QWORD *)(v6 + 1616);
  _X8 = result + 27;
  __asm { PRFM            #0x11, [X8] }
  do
    v50 = __ldxr(_X8);
  while ( __stxr(v50 | 0x40000, _X8) );
  v11 = 0;
  v9 = 0;
  v8 = *(_QWORD *)(result[10] + 1616LL);
  v15 = result + 29;
  v16 = result + 41;
  v60 = &v60;
  v61 = &v60;
  LODWORD(v62) = 0;
  v55 = result + 29;
  v56 = result;
  v54 = result + 41;
  while ( ((unsigned __int8)ieee80211_ac_to_qos_mask[v9] & a3) != 0 )
  {
LABEL_2:
    if ( ++v9 == 4 )
      goto LABEL_21;
  }
  if ( (v9 & 0xFFFFFFFC) != 0 )
  {
    v10 = 0;
    __break(0x800u);
  }
  else
  {
    v10 = (__int64)*(&off_C15B0 + (v9 & 3));
  }
  if ( v60 == &v60 )
  {
    v11 |= (v5[54] | v5[53]) & v10;
    if ( v11 )
      goto LABEL_19;
  }
  else if ( v11 )
  {
    goto LABEL_19;
  }
  if ( v4 >= 1 )
  {
    v12 = &v15[3 * v9];
    v13 = &v16[3 * v9];
    do
    {
      result = (_QWORD *)skb_dequeue(v13);
      if ( !result )
      {
        result = (_QWORD *)skb_dequeue(v12);
        if ( !result )
          goto LABEL_18;
        --*(_DWORD *)(v8 + 5000);
      }
      v14 = v61;
      *result = &v60;
      _VF = __OFSUB__(v4--, 1);
      result[1] = v14;
      v61 = (_QWORD **)result;
      *v14 = result;
      LODWORD(v62) = v62 + 1;
    }
    while ( !((v4 < 0) ^ _VF | (v4 == 0)) );
    v4 = 0;
LABEL_18:
    v15 = v55;
    v5 = v56;
    v16 = v54;
  }
LABEL_19:
  if ( (_QWORD *)v16[3 * v9] == &v16[3 * v9] && (_QWORD *)v15[3 * v9] == &v15[3 * v9] )
    goto LABEL_2;
LABEL_21:
  if ( !a4 )
  {
    v17 = v16;
    result = (_QWORD *)_sw_hweight16((unsigned int)v11);
    v16 = v17;
    if ( (unsigned int)result > 1 )
    {
      v18 = a2;
      v19 = 1;
      goto LABEL_42;
    }
  }
  v18 = a2;
  if ( ((ieee80211_ac_to_qos_mask[0] & a3) != 0 || (_QWORD *)*v16 == v16 && (_QWORD *)*v15 == v15)
    && ((a3 & 2) != 0 || (_QWORD *)v5[44] == v5 + 44 && (_QWORD *)v5[32] == v5 + 32)
    && ((a3 & 8) != 0 || (_QWORD *)v5[47] == v5 + 47 && (_QWORD *)v5[35] == v5 + 35)
    && ((a3 & 4) != 0 || (_QWORD *)v5[50] == v5 + 50 && (_QWORD *)v5[38] == v5 + 38) )
  {
    v19 = 0;
    if ( !a4 )
      goto LABEL_42;
  }
  else
  {
    v19 = 1;
    if ( !a4 )
    {
LABEL_42:
      if ( v11 )
      {
        if ( (v11 & 0xF8) != 0 )
        {
          v20 = v51;
          v21 = __clz(v11) ^ 0x1F;
        }
        else
        {
          v20 = v51;
          if ( (v11 & 1) != 0 )
            LOBYTE(v21) = 0;
          else
            v21 = __clz(v11) ^ 0x1F;
        }
        v11 = 1LL << v21;
        goto LABEL_77;
      }
    }
  }
  v22 = v60;
  if ( v60 != &v60 || v11 )
  {
    v20 = v51;
    if ( v11 )
    {
LABEL_77:
      v39 = *(_DWORD **)(*(_QWORD *)(v20 + 464) + 536LL);
      if ( v39 )
      {
        if ( *(v39 - 1) != 1853379195 )
          __break(0x8228u);
        result = (_QWORD *)((__int64 (__fastcall *)(__int64, _QWORD *, _QWORD, __int64, _QWORD, __int64))v39)(
                             v20,
                             v5 + 336,
                             (unsigned int)v11,
                             v18,
                             a4,
                             v19);
      }
      v40 = 0;
      while ( 1 )
      {
        v41 = v5[v40 + 342];
        if ( v41 )
        {
          if ( ((v11 >> v40) & 1) != 0 && *(_QWORD *)(v41 - 32) == v41 - 32 && !*(_DWORD *)(v41 - 124) )
            goto LABEL_103;
        }
        if ( ++v40 == 17 )
          goto LABEL_104;
      }
    }
    v24 = 0;
    v57 = (__int64)&v57;
    v58 = &v57;
    v59 = 0;
    do
    {
      if ( v22 == &v60 || (v25 = v22) == nullptr )
      {
        v38 = 0;
        goto LABEL_94;
      }
      v24 = (unsigned int)(v24 + 1);
      LODWORD(v62) = v62 - 1;
      v26 = *v22;
      v27 = (_QWORD *)v22[1];
      *v25 = 0;
      v25[1] = 0;
      *(_QWORD *)(v26 + 8) = v27;
      *v27 = v26;
      v28 = v60;
      v29 = (_WORD *)v25[28];
      LODWORD(v27) = *((_DWORD *)v25 + 20) | 2;
      *((_DWORD *)v25 + 10) |= 0x20000u;
      *((_DWORD *)v25 + 20) = (_DWORD)v27;
      if ( v28 == &v60 )
        v30 = v19;
      else
        v30 = 1;
      v31 = (unsigned __int16)*v29;
      if ( v30 )
        v32 = 0x2000;
      else
        v32 = 0;
      *v29 = v31 & 0xDFFF | v32;
      v33 = v58;
      v34 = *((_DWORD *)v25 + 36);
      *v25 = &v57;
      v25[1] = v33;
      v58 = v25;
      *v33 = (__int64)v25;
      LODWORD(v11) = v11 | (1LL << v34);
      LODWORD(v59) = v59 + 1;
      v22 = v60;
    }
    while ( v60 != &v60 );
    v35 = 12;
    if ( (~v31 & 0x300) == 0 )
      v35 = 15;
    v36 = &v29[v35];
    if ( (v31 & 0x8C) == 0x88 )
      v37 = v36;
    else
      v37 = nullptr;
    if ( a4 == 1 )
    {
      if ( !v37 )
      {
        v24 = (unsigned int)(v24 + 1);
        v38 = 1;
        *v29 |= 0x2000u;
        goto LABEL_94;
      }
      v38 = 0;
      *v37 |= 0x10u;
    }
    else
    {
      v38 = 0;
    }
    *((_DWORD *)v25 + 10) |= 0x10000001u;
LABEL_94:
    v42 = *(_DWORD **)(*(_QWORD *)(v51 + 464) + 528LL);
    if ( v42 )
    {
      if ( *(v42 - 1) != 1853379195 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *, _QWORD, __int64, _QWORD))v42)(v51, v5 + 336, (unsigned int)v11, v24, a4);
    }
    ieee80211_add_pending_skbs(v51, &v57);
    if ( v38 )
    {
      if ( (v11 & 0xF8) == 0 && (v11 & 1) != 0 )
        v43 = 0;
      else
        v43 = 31 - __clz((unsigned __int16)v11);
      ieee80211_send_null_response(v5, v43, a4, 0, 0);
    }
LABEL_103:
    result = (_QWORD *)_sta_info_recalc_tim((__int64)v5, 0);
    goto LABEL_104;
  }
  if ( (ieee80211_ac_to_qos_mask[0] & a3) != 0 )
  {
    if ( (a3 & 2) != 0 )
    {
      if ( (a3 & 8) != 0 )
      {
        if ( (a3 & 4) != 0 )
          v23 = 0xFFFFFFFFLL;
        else
          v23 = 1;
      }
      else
      {
        v23 = 3;
      }
    }
    else
    {
      v23 = 5;
    }
  }
  else
  {
    v23 = 7;
  }
  result = (_QWORD *)ieee80211_send_null_response(v5, v23, a4, 1, 0);
LABEL_104:
  _ReadStatusReg(SP_EL0);
  return result;
}
