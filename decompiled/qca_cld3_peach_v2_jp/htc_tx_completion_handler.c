__int64 __fastcall htc_tx_completion_handler(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x23
  int v6; // w8
  __int64 v7; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x8
  __int64 v10; // x21
  _QWORD *v11; // x8
  __int64 v12; // x9
  _QWORD *v13; // x10
  _QWORD *v14; // x9
  _QWORD *v15; // x9
  int v16; // w10
  _QWORD *v17; // x9
  int v18; // w12
  _QWORD *v19; // x11
  int v20; // w10
  _QWORD *v21; // x13
  __int64 v22; // x14
  __int64 v23; // x9
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x22
  __int64 v27; // x8
  __int64 v28; // x8
  _QWORD *v29; // x8
  _QWORD *v30; // x8
  int v31; // w8
  __int64 v32; // x8
  __int64 v33; // x8
  __int64 v34; // x22
  __int64 v35; // x1
  __int64 v36; // x23
  unsigned int v44; // w10
  _QWORD *v45; // [xsp+0h] [xbp-20h] BYREF
  _QWORD *v46; // [xsp+8h] [xbp-18h]
  __int64 v47; // [xsp+10h] [xbp-10h]
  __int64 v48; // [xsp+18h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 >= 0xA )
    __break(0x5512u);
  v4 = a1 + 328LL * a3;
  ++*(_DWORD *)(a1 + 3492);
  v6 = *(_DWORD *)(v4 + 220);
  v7 = v4 + 8;
  v45 = &v45;
  v46 = &v45;
  v47 = 0;
  *(_DWORD *)(v4 + 220) = v6 + 1;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v4 + 312);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_8;
  }
  else
  {
    raw_spin_lock_bh(v4 + 312);
    *(_QWORD *)(v4 + 320) |= 1uLL;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_8;
  }
  v9 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v9 + 16) & 0xFF00) == 0 )
  {
    raw_spin_lock_bh(a1 + 2992);
    *(_QWORD *)(a1 + 3000) |= 1uLL;
    goto LABEL_9;
  }
LABEL_8:
  raw_spin_lock(a1 + 2992);
LABEL_9:
  v10 = *(_QWORD *)(v4 + 240);
  v11 = (_QWORD *)(v4 + 232);
  --*(_DWORD *)(v4 + 212);
  if ( v10 == v4 + 232 )
    goto LABEL_30;
  v12 = *(_QWORD *)v10;
  v13 = *(_QWORD **)(v10 + 8);
  if ( v13 )
    *v13 = v12;
  if ( v12 )
    *(_QWORD *)(v12 + 8) = *(_QWORD *)(v10 + 8);
  *(_QWORD *)v10 = v10;
  *(_QWORD *)(v10 + 8) = v10;
  if ( !v10 )
  {
LABEL_30:
    v24 = *(_QWORD *)(a1 + 3000);
    if ( (v24 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 3000) = v24 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2992);
      v25 = *(_QWORD *)(v4 + 320);
      if ( (v25 & 1) == 0 )
        goto LABEL_32;
    }
    else
    {
      raw_spin_unlock(a1 + 2992);
      v25 = *(_QWORD *)(v4 + 320);
      if ( (v25 & 1) == 0 )
      {
LABEL_32:
        raw_spin_unlock(v4 + 312);
        goto LABEL_33;
      }
    }
    *(_QWORD *)(v4 + 320) = v25 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v4 + 312);
    goto LABEL_33;
  }
  --*(_DWORD *)(v4 + 248);
  if ( *(_QWORD *)(v10 + 96) == a2 )
  {
    v27 = *(_QWORD *)(a1 + 3000);
    if ( (v27 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 3000) = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2992);
      v28 = *(_QWORD *)(v4 + 320);
      if ( (v28 & 1) == 0 )
        goto LABEL_41;
    }
    else
    {
      raw_spin_unlock(a1 + 2992);
      v28 = *(_QWORD *)(v4 + 320);
      if ( (v28 & 1) == 0 )
      {
LABEL_41:
        raw_spin_unlock(v4 + 312);
        goto LABEL_49;
      }
    }
    *(_QWORD *)(v4 + 320) = v28 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v4 + 312);
    goto LABEL_49;
  }
  v14 = v45;
  *(_QWORD *)v10 = v45;
  *(_QWORD *)(v10 + 8) = &v45;
  if ( v14 )
    v14[1] = v10;
  v15 = (_QWORD *)*v11;
  v45 = (_QWORD *)v10;
  v16 = v47 + 1;
  LODWORD(v47) = v47 + 1;
  if ( v15 == v11 && *(_QWORD **)(v4 + 240) == v11 )
  {
    v17 = (_QWORD *)v10;
  }
  else
  {
    v15[1] = &v45;
    **(_QWORD **)(v4 + 240) = v10;
    *(_QWORD *)(v10 + 8) = *(_QWORD *)(v4 + 240);
    v17 = *(_QWORD **)(v4 + 232);
    v16 = v47;
    *(_QWORD *)(v4 + 232) = v4 + 232;
    *(_QWORD *)(v4 + 240) = v11;
    v45 = v17;
  }
  v18 = *(_DWORD *)(v4 + 248);
  v19 = v46;
  *(_DWORD *)(v4 + 248) = 0;
  v20 = v18 + v16;
  v21 = v19;
  LODWORD(v47) = v20;
  do
  {
    if ( v21 == &v45 )
    {
      v10 = 0;
      goto LABEL_43;
    }
    v10 = (__int64)v21;
    if ( !v21 )
      goto LABEL_43;
    v22 = v21[12];
    v21 = (_QWORD *)v21[1];
  }
  while ( v22 != a2 );
  v23 = *(_QWORD *)v10;
  if ( v21 )
    *v21 = v23;
  if ( v23 )
    *(_QWORD *)(v23 + 8) = *(_QWORD *)(v10 + 8);
  *(_QWORD *)v10 = v10;
  *(_QWORD *)(v10 + 8) = v10;
  v20 = v47 - 1;
  v17 = v45;
  v19 = v46;
  LODWORD(v47) = v47 - 1;
LABEL_43:
  if ( v17 != &v45 || v19 != &v45 )
  {
    *v19 = v11;
    v29 = v45;
    **(_QWORD **)(v4 + 240) = v45;
    v29[1] = *(_QWORD *)(v4 + 240);
    v30 = v46;
    v20 = v47;
    v45 = &v45;
    v46 = &v45;
    *(_QWORD *)(v4 + 240) = v30;
  }
  v31 = *(_DWORD *)(v4 + 248);
  LODWORD(v47) = 0;
  *(_DWORD *)(v4 + 248) = v31 + v20;
  v32 = *(_QWORD *)(a1 + 3000);
  if ( (v32 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 2992);
    v33 = *(_QWORD *)(v4 + 320);
    if ( (v33 & 1) == 0 )
      goto LABEL_48;
    goto LABEL_63;
  }
  *(_QWORD *)(a1 + 3000) = v32 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 2992);
  v33 = *(_QWORD *)(v4 + 320);
  if ( (v33 & 1) != 0 )
  {
LABEL_63:
    *(_QWORD *)(v4 + 320) = v33 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v4 + 312);
    if ( !v10 )
      goto LABEL_33;
LABEL_49:
    if ( (unsigned int)*(unsigned __int16 *)(v10 + 56) - 12 >= 3 )
    {
      hif_rtpm_put(4, 2u);
      _X8 = (unsigned int *)(a1 + 3568);
      __asm { PRFM            #0x11, [X8] }
      do
        v44 = __ldxr(_X8);
      while ( __stxr(v44 - 1, _X8) );
      if ( *(_WORD *)(v10 + 56) == 11 )
      {
        v34 = *(_QWORD *)(v10 + 88);
        v35 = *(_QWORD *)(v34 + 8);
        if ( v35 != v34 )
        {
          do
          {
            v36 = *(_QWORD *)(v35 + 8);
            *(_DWORD *)(v10 + 52) = 0;
            send_packet_completion(a1);
            v35 = v36;
          }
          while ( v36 != v34 );
        }
        free_htc_bundle_packet(a1, v10);
        if ( (unsigned int)hif_get_bus_type(*(_QWORD *)a1) != 5 || (*(_BYTE *)(v7 + 300) & 1) != 0 )
          goto LABEL_58;
LABEL_38:
        htc_try_send(a1, v7, 0);
        goto LABEL_58;
      }
    }
    *(_DWORD *)(v10 + 52) = 0;
    send_packet_completion(a1);
    if ( (*(_BYTE *)(v4 + 308) & 1) != 0 )
      goto LABEL_58;
LABEL_36:
    if ( *(_DWORD *)(v4 + 284) && (*(_BYTE *)(v4 + 309) & 1) != 0 )
      goto LABEL_58;
    goto LABEL_38;
  }
LABEL_48:
  raw_spin_unlock(v4 + 312);
  if ( v10 )
    goto LABEL_49;
LABEL_33:
  v26 = jiffies;
  if ( htc_tx_completion_handler___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(56, 2, "%s: HTC TX lookup failed!", "htc_tx_completion_handler");
    htc_tx_completion_handler___last_ticks = v26;
  }
  if ( (*(_BYTE *)(v4 + 308) & 1) == 0 )
    goto LABEL_36;
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return 0;
}
