__int64 __fastcall qmi_rmnet_get_queue(__int64 a1, __int64 a2)
{
  __int64 qos_pt; // x0
  __int64 v4; // x21
  int v5; // w8
  __int64 v6; // x8
  unsigned int v7; // w20
  int v8; // w22
  __int64 v9; // x19
  __int64 *v10; // x8
  __int64 v11; // x21
  __int64 *v12; // t1
  __int64 v13; // x9
  int v14; // w10
  __int64 v15; // x10
  __int64 v16; // x11
  unsigned int v17; // w10
  __int64 v18; // x10
  int v19; // w20
  __int64 v20; // x0
  int v21; // w22
  __int64 v22; // x21
  __int64 *v23; // t1

  qos_pt = rmnet_get_qos_pt(a1);
  if ( !qos_pt )
    return 0;
  v4 = qos_pt;
  v5 = *(unsigned __int16 *)(a2 + 180);
  if ( dfc_mode != 4 )
  {
    v9 = qos_pt + 332;
    v19 = *(_DWORD *)(a2 + 168);
    v20 = qos_pt + 332;
    if ( v5 == 56710 )
      v21 = 10;
    else
      v21 = 2;
    raw_spin_lock_bh(v20);
    v23 = *(__int64 **)(v4 + 40);
    v22 = v4 + 40;
    v10 = v23;
    if ( v23 != (__int64 *)v22 )
    {
      while ( *((_DWORD *)v10 + 5) != v19 || *((_DWORD *)v10 + 6) != v21 )
      {
        v10 = (__int64 *)*v10;
        if ( v10 == (__int64 *)v22 )
          goto LABEL_30;
      }
      if ( v10 )
        goto LABEL_25;
    }
    goto LABEL_30;
  }
  if ( v5 != 56710 )
  {
    v8 = 2;
LABEL_9:
    v9 = qos_pt + 332;
    raw_spin_lock_bh(qos_pt + 332);
    v12 = *(__int64 **)(v4 + 40);
    v11 = v4 + 40;
    v10 = v12;
    if ( v12 != (__int64 *)v11 )
    {
      while ( *((_DWORD *)v10 + 5) != *(_DWORD *)(a2 + 168) || *((_DWORD *)v10 + 6) != v8 )
      {
        v10 = (__int64 *)*v10;
        if ( v10 == (__int64 *)v11 )
          goto LABEL_30;
      }
      if ( v10 )
      {
        v13 = v10[4];
        if ( v13 )
        {
          if ( *(_DWORD *)(a2 + 232) == 2 )
          {
LABEL_17:
            v7 = *(_DWORD *)(v13 + 64);
LABEL_31:
            raw_spin_unlock_bh(v9);
            return v7;
          }
          v14 = *(unsigned __int16 *)(a2 + 180);
          if ( v14 == 56710 )
          {
            v18 = *(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 184);
            if ( *(_BYTE *)(v18 + 6) != 6 )
              goto LABEL_25;
            v16 = 40;
            v17 = bswap32(*(unsigned __int16 *)(v18 + 4)) >> 16;
          }
          else
          {
            if ( v14 != 8 )
              goto LABEL_25;
            v15 = *(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 184);
            if ( *(_BYTE *)(v15 + 9) != 6 )
              goto LABEL_25;
            v16 = 4LL * (*(_BYTE *)v15 & 0xF);
            v17 = (bswap32(*(unsigned __int16 *)(v15 + 2)) >> 16) - v16;
          }
          if ( v17 == ((*(unsigned __int16 *)(*(_QWORD *)(a2 + 224) + v16 + 12) >> 2) & 0x3C) )
            goto LABEL_17;
        }
LABEL_25:
        v7 = *((_DWORD *)v10 + 7);
        goto LABEL_31;
      }
    }
LABEL_30:
    v7 = 0;
    goto LABEL_31;
  }
  v6 = *(_QWORD *)(a2 + 216);
  if ( *(_BYTE *)(v6 + *(unsigned __int16 *)(a2 + 184) + 6) != 58
    || (unsigned int)*(unsigned __int8 *)(v6 + *(unsigned __int16 *)(a2 + 182)) - 133 >= 5 )
  {
    v8 = 10;
    goto LABEL_9;
  }
  return 0;
}
