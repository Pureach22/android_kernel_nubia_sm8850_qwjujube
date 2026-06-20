__int64 __fastcall hif_send_head(__int64 a1, unsigned __int8 a2, unsigned int a3, unsigned int a4, __int64 a5, int a6)
{
  char v6; // w9
  int v9; // w23
  __int64 v11; // x26
  unsigned int v12; // w8
  int *v13; // x28
  int v14; // w9
  unsigned int v15; // w25
  int v16; // w24
  unsigned int v17; // w8
  int v18; // w9
  __int64 v19; // x10
  int v20; // w21
  __int64 v21; // x2
  unsigned int v22; // w0
  unsigned __int64 StatusReg; // x8
  int v24; // w8
  bool v25; // vf
  int v26; // w8
  __int64 v27; // x8
  unsigned int v28; // w19
  __int64 v29; // x9
  __int64 v30; // x20
  int v32; // [xsp+0h] [xbp-120h]
  __int64 v34; // [xsp+8h] [xbp-118h]
  _QWORD v35[33]; // [xsp+18h] [xbp-108h] BYREF

  v35[31] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 0xDu )
    __break(0x5512u);
  v6 = *(_BYTE *)(a5 + 68);
  v9 = a4;
  v11 = a1 + 136LL * a2 + 27416;
  v34 = *(_QWORD *)v11;
  memset(v35, 0, 248);
  if ( (v6 & 4) != 0 )
  {
    v13 = (int *)(a5 + 112);
    v12 = *(_DWORD *)(a5 + 112);
    v14 = *(unsigned __int16 *)(a5 + 66);
    if ( v12 + v14 < a4 )
      goto LABEL_6;
  }
  else
  {
    v13 = (int *)(a5 + 112);
    v12 = *(_DWORD *)(a5 + 112);
    if ( v12 < a4 )
    {
      v14 = 0;
LABEL_6:
      qdf_trace_msg(61, 2, "%s: nbytes: %d nbuf_len: %d", "hif_send_head", a4, v14 + v12);
    }
  }
  v32 = *(_DWORD *)(*(_QWORD *)(a1 + 632) + 232LL);
  v15 = *(_DWORD *)(*(_QWORD *)(a1 + 632) + 236LL) & a6;
  ce_sendlist_init(v35);
  v16 = 0;
  do
  {
    v17 = *(unsigned __int8 *)(a5 + 68);
    v18 = (v17 >> 2) & 1;
    if ( v16 >= (unsigned int)v18 )
      v19 = 40;
    else
      v19 = 80;
    if ( v16 < v18 )
      v20 = *(unsigned __int16 *)(a5 + 66);
    else
      v20 = *v13;
    if ( v16 > 0 )
      v15 &= 0xF000FFFF;
    if ( v20 >= v9 )
      v21 = (unsigned int)v9;
    else
      v21 = (unsigned int)v20;
    v22 = ce_sendlist_buf_add(v35, *(_QWORD *)(a5 + v19), v21, ((v17 >> (v16 >= v18)) & 1) == 0, v15);
    if ( v22 )
    {
      v28 = v22;
      qdf_trace_msg(61, 2, "%s: frag_num: %d larger than limit (status=%d)", "hif_send_head", v16, v22);
      goto LABEL_34;
    }
    v9 -= v20;
    ++v16;
  }
  while ( v9 > 0 );
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v11 + 56);
  }
  else
  {
    raw_spin_lock_bh(v11 + 56);
    *(_QWORD *)(v11 + 64) |= 1uLL;
  }
  v24 = *(_DWORD *)(v11 + 72);
  v25 = __OFSUB__(v24, v16);
  v26 = v24 - v16;
  if ( v26 < 0 == v25 )
  {
    v29 = *(_QWORD *)(v11 + 64);
    *(_DWORD *)(v11 + 72) = v26;
    if ( (v29 & 1) != 0 )
    {
      *(_QWORD *)(v11 + 64) = v29 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v11 + 56);
      v30 = v34;
      if ( v34 )
        goto LABEL_33;
    }
    else
    {
      raw_spin_unlock(v11 + 56);
      v30 = v34;
      if ( v34 )
      {
LABEL_33:
        ((void (__fastcall *)(__int64, __int64))qdf_nbuf_set_state)(a5, 7);
        qdf_dp_trace(a5, 40, 255, a5 + 224, 8, 0);
        v28 = ce_sendlist_send(v30, a5, v35, v32 & a3);
        goto LABEL_34;
      }
    }
    qdf_trace_msg(61, 2, "%s: CE handle is null", "hif_send_head");
    v28 = 4;
    goto LABEL_34;
  }
  v27 = *(_QWORD *)(v11 + 64);
  if ( (v27 & 1) != 0 )
  {
    *(_QWORD *)(v11 + 64) = v27 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v11 + 56);
  }
  else
  {
    raw_spin_unlock(v11 + 56);
  }
  v28 = 1;
  ++*(_DWORD *)(a1 + 592);
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return v28;
}
