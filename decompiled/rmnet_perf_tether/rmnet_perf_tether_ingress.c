__int64 __fastcall rmnet_perf_tether_ingress(__int64 result, __int64 a2)
{
  __int64 v3; // x19
  int v4; // w21
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x0
  int v9; // w8
  __int64 v10; // x11
  __int64 v11; // x12
  unsigned __int16 *v12; // x11
  __int64 v13; // x11
  __int64 v14; // x11
  __int64 v15; // x13
  __int64 v17; // x11
  __int64 v18; // x11
  __int64 v19; // x12
  __int64 v21; // x11
  unsigned __int16 *v22; // x11
  __int64 v23; // x11
  _QWORD *v24; // x8
  __int64 v25; // x10
  _QWORD *v26; // x1
  unsigned int v27; // w9
  unsigned int v28; // w8
  unsigned int v29; // w9
  unsigned __int8 *v30; // x10
  int v31; // w11
  unsigned int v32; // w12
  bool v33; // cf
  _BYTE *v34; // x10
  int v35; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  if ( !(configure_knob1 | configure_knob2) )
    goto LABEL_32;
  v3 = result;
  result = rmnet_perf_tether_get_hash_from_skb(a2, &v35, 1, 0);
  if ( !v35 )
    goto LABEL_32;
  v4 = result;
  v5 = raw_spin_lock_irqsave(&rmnet_perf_tether_lock);
  v6 = rmnet_perf_tether_flow_table[(unsigned int)(1640531527 * v4) >> 27];
  v7 = v5;
  if ( !v6 || (v8 = v6 - 16, v6 == 16) )
  {
LABEL_31:
    result = raw_spin_unlock_irqrestore(&rmnet_perf_tether_lock, v7);
    goto LABEL_32;
  }
  v9 = *(unsigned __int16 *)(a2 + 180);
  while ( v9 != 56710 )
  {
    if ( v9 == 8 )
    {
      v10 = *(_QWORD *)(a2 + 216);
      v11 = v10 + *(unsigned __int16 *)(a2 + 184);
      if ( *(_DWORD *)(v8 + 36) == *(_DWORD *)(v11 + 12)
        && *(_DWORD *)(v8 + 40) == *(_DWORD *)(v11 + 16)
        && *(_DWORD *)(v8 + 44) == *(unsigned __int8 *)(v11 + 9) )
      {
        v12 = (unsigned __int16 *)(v10 + *(unsigned __int16 *)(a2 + 182));
        if ( *(_DWORD *)(v8 + 48) == *v12 && *(_DWORD *)(v8 + 52) == v12[1] && *(_DWORD *)(v8 + 80) == 5 )
          goto LABEL_33;
      }
    }
LABEL_29:
    v23 = *(_QWORD *)(v8 + 16);
    if ( v23 )
    {
      v8 = v23 - 16;
      if ( v23 != 16 )
        continue;
    }
    goto LABEL_31;
  }
  v13 = *(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 184);
  v15 = *(_QWORD *)(v13 + 8);
  v14 = *(_QWORD *)(v13 + 16);
  if ( *(_QWORD *)(v8 + 36) != v15 || *(_QWORD *)(v8 + 44) != v14 )
    goto LABEL_29;
  v17 = *(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 184);
  v19 = *(_QWORD *)(v17 + 24);
  v18 = *(_QWORD *)(v17 + 32);
  if ( *(_QWORD *)(v8 + 56) != v19 || *(_QWORD *)(v8 + 64) != v18 )
    goto LABEL_29;
  v21 = *(_QWORD *)(a2 + 216);
  if ( *(_DWORD *)(v8 + 68) != *(unsigned __int8 *)(v21 + *(unsigned __int16 *)(a2 + 184) + 6) )
    goto LABEL_29;
  v22 = (unsigned __int16 *)(v21 + *(unsigned __int16 *)(a2 + 182));
  if ( *(_DWORD *)(v8 + 72) != *v22 || *(_DWORD *)(v8 + 76) != v22[1] || *(_DWORD *)(v8 + 80) != 11 )
    goto LABEL_29;
LABEL_33:
  v24 = *(_QWORD **)(v8 + 24);
  if ( v24 )
  {
    v25 = *(_QWORD *)(v8 + 16);
    *v24 = v25;
    if ( v25 )
      *(_QWORD *)(v25 + 8) = v24;
    *(_QWORD *)(v8 + 16) = 0;
    *(_QWORD *)(v8 + 24) = 0;
  }
  v26 = off_40;
  if ( (_UNKNOWN **)v8 == &rmnet_perf_tether_free_list
    || off_40 == (_UNKNOWN *)v8
    || *(_UNKNOWN ***)off_40 != &rmnet_perf_tether_free_list )
  {
    _list_add_valid_or_report();
  }
  else
  {
    off_40 = (_UNKNOWN *)v8;
    *(_QWORD *)v8 = &rmnet_perf_tether_free_list;
    *(_QWORD *)(v8 + 8) = v26;
    *v26 = v8;
  }
  result = raw_spin_unlock_irqrestore(&rmnet_perf_tether_lock, v7);
  v27 = *(unsigned __int16 *)(v3 + 12);
  if ( (~v27 & 0x1200) == 0 )
  {
    if ( configure_knob1 )
    {
      v28 = knob1;
      if ( (unsigned int)knob1 >= 0x10000 )
      {
        v28 = 0xFFFF;
        knob1 = 0xFFFF;
      }
      *(_WORD *)(v3 + 14) = bswap32(v28) >> 16;
    }
    if ( configure_knob2 )
    {
      if ( (unsigned int)knob2 >= 0xF )
        knob2 = 14;
      v29 = ((v27 >> 2) & 0x3C) - 20;
      if ( v29 )
      {
        v30 = (unsigned __int8 *)(v3 + 20);
        do
        {
          while ( 1 )
          {
            v31 = *v30;
            if ( v31 != 1 )
              break;
            --v29;
            ++v30;
            if ( !v29 )
              goto LABEL_32;
          }
          if ( !*v30 )
            break;
          if ( v29 == 1 )
            break;
          v32 = v30[1];
          if ( v32 < 2 )
            break;
          v33 = v29 >= v32;
          v29 -= v32;
          if ( !v33 )
            break;
          v34 = v30 + 2;
          if ( v31 == 3 )
            *v34 = knob2;
          v30 = &v34[v32 - 2];
        }
        while ( v29 );
      }
    }
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
