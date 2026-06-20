__int64 __fastcall dfc_do_burst_flow_control(__int64 *a1, _BYTE *a2, char a3)
{
  __int64 lock; // x0
  __int64 v6; // x23
  __int64 v7; // x24
  __int64 v8; // x10
  int v9; // w25
  __int64 v10; // x27
  __int64 v11; // x26
  __int64 v12; // x1
  __int64 bearer_map; // x0
  __int64 bearer_noref; // x28
  __int64 v15; // x8
  unsigned int v16; // w8
  unsigned int v17; // w9
  bool v18; // cf
  unsigned int v19; // w8
  unsigned int v20; // w19
  unsigned int v21; // w9
  unsigned int v22; // w22
  int v23; // w8
  int v24; // w19
  _BOOL4 v25; // w9
  __int16 v26; // w8
  __int16 v27; // w8
  int v28; // w19
  int v30; // [xsp+30h] [xbp-10h]

  if ( a2[644] )
    v30 = (unsigned __int8)a2[645];
  else
    v30 = 0;
  lock = _rcu_read_lock();
  if ( !a2[1] )
    return _rcu_read_unlock(lock);
  v6 = 0;
  _ReadStatusReg(SP_EL0);
  while ( v6 != 17 )
  {
    v7 = (__int64)&a2[40 * v6 + 4];
    if ( a2[646] && a2[647] )
    {
      v8 = 0;
      while ( v8 != 136 )
      {
        if ( a2[v8 + 649] == *(_BYTE *)(v7 + 1) && a2[v8 + 650] == *(_BYTE *)(v7 + 2) )
        {
          v9 = *(_DWORD *)&a2[v8 + 652];
          goto LABEL_19;
        }
        v8 += 8;
        if ( 8LL * (unsigned __int8)a2[647] == v8 )
          goto LABEL_18;
      }
      break;
    }
LABEL_18:
    LOBYTE(v9) = 0;
LABEL_19:
    lock = rmnet_get_rmnet_dev(*a1, *(_BYTE *)(v7 + 1));
    if ( !lock )
      return _rcu_read_unlock(lock);
    v10 = lock;
    lock = rmnet_get_qos_pt(lock);
    if ( lock )
    {
      v11 = lock;
      raw_spin_lock_bh(lock + 332);
      if ( (qmi_rmnet_ignore_grant(*a1) & 1) == 0 )
        goto LABEL_24;
      if ( !*(_DWORD *)(v7 + 4) )
        goto LABEL_7;
      *(_WORD *)(v7 + 8) = 0;
      *(_DWORD *)(v7 + 4) = 1;
      *(_BYTE *)(v7 + 28) = 1;
      *(_DWORD *)(v7 + 32) = -1;
LABEL_24:
      v12 = *(unsigned __int8 *)(v7 + 2);
      if ( (_DWORD)v12 == 255 )
      {
        dfc_all_bearer_flow_ctl(v10);
        goto LABEL_7;
      }
      bearer_map = qmi_rmnet_get_bearer_map(v11, v12);
      bearer_noref = bearer_map;
      if ( bearer_map || (a3 & 1) != 0 )
      {
        if ( bearer_map )
          goto LABEL_28;
LABEL_7:
        lock = raw_spin_unlock_bh(v11 + 332);
        goto LABEL_8;
      }
      if ( !*(_DWORD *)(v7 + 4) )
        goto LABEL_7;
      bearer_noref = qmi_rmnet_get_bearer_noref(v11, *(unsigned __int8 *)(v7 + 2));
      if ( !bearer_noref )
        goto LABEL_7;
LABEL_28:
      if ( (v9 & 2) != 0 )
      {
        *(_BYTE *)(bearer_noref + 53) = *(_DWORD *)(v7 + 4) == 0;
      }
      else if ( (*(_BYTE *)(bearer_noref + 53) & 1) != 0 )
      {
        goto LABEL_7;
      }
      if ( *(_BYTE *)(bearer_noref + 54) == 1 && *(_DWORD *)(v7 + 4) )
        goto LABEL_7;
      if ( *(_BYTE *)(v7 + 36) )
      {
        if ( *(_BYTE *)(bearer_noref + 128) != 1 )
        {
          v15 = *(unsigned int *)(bearer_noref + 60);
          *(_BYTE *)(bearer_noref + 128) = 1;
          *(_BYTE *)(bearer_noref + 132) = 1;
          if ( (unsigned int)v15 <= 0xF )
            *(_BYTE *)(v11 + 16 * v15 + 80) = 1;
        }
      }
      if ( !dfc_qmap || (a3 & 1) == 0 )
      {
        v22 = *(_DWORD *)(v7 + 4);
        *(_DWORD *)(bearer_noref + 44) = 0;
        goto LABEL_48;
      }
      if ( *(_BYTE *)(v7 + 28) )
      {
        v16 = *(_DWORD *)(bearer_noref + 44);
        v17 = *(_DWORD *)(v7 + 32);
        v18 = v16 >= v17;
        v19 = v16 - v17;
        if ( v18 )
          v20 = v19;
        else
          v20 = 0;
        *(_DWORD *)(bearer_noref + 44) = v20;
        v21 = *(_DWORD *)(v7 + 4);
        if ( v21 >= v20 )
          v22 = v21 - v20;
        else
          v22 = 0;
LABEL_48:
        v23 = *(_DWORD *)(bearer_noref + 24);
        if ( !v23 )
        {
LABEL_49:
          if ( !v22 )
            goto LABEL_50;
LABEL_54:
          v24 = 1;
          goto LABEL_55;
        }
      }
      else
      {
        v22 = *(_DWORD *)(v7 + 4);
        v23 = *(_DWORD *)(bearer_noref + 24);
        if ( !v23 )
          goto LABEL_49;
      }
LABEL_50:
      if ( v23 && !v22 || (v9 & 1) != *(_BYTE *)(bearer_noref + 52) )
        goto LABEL_54;
      v24 = 0;
LABEL_55:
      if ( dfc_qmap )
      {
        v25 = 1;
        if ( v23 && !v30 && *(_BYTE *)(bearer_noref + 34) )
        {
          dfc_qmap_send_ack(v11, *(unsigned __int8 *)(bearer_noref + 16), *(unsigned __int16 *)(bearer_noref + 32), 1);
          v25 = dfc_qmap != 0;
        }
        *(_DWORD *)(bearer_noref + 24) = v22;
        if ( v25 && (a3 & 1) != 0 && v22 < *(_DWORD *)(v7 + 4) / 5u )
        {
          *(_DWORD *)(bearer_noref + 28) = v22;
          qmi_rmnet_watchdog_add(bearer_noref);
          goto LABEL_66;
        }
      }
      else
      {
        *(_DWORD *)(bearer_noref + 24) = v22;
      }
      *(_DWORD *)(bearer_noref + 28) = qmi_rmnet_grant_per(v22);
      qmi_rmnet_watchdog_remove(bearer_noref);
LABEL_66:
      v26 = *(_WORD *)(v7 + 8);
      *(_BYTE *)(bearer_noref + 34) = v30;
      *(_BYTE *)(bearer_noref + 52) = v9 & 1;
      *(_WORD *)(bearer_noref + 32) = v26;
      *(_DWORD *)(bearer_noref + 36) = *(_DWORD *)(v7 + 4);
      v27 = *(_WORD *)(v7 + 8);
      *(_DWORD *)(bearer_noref + 48) = v22;
      *(_WORD *)(bearer_noref + 40) = v27;
      if ( v24 )
      {
        v28 = *(_DWORD *)(bearer_noref + 24);
        if ( *(_DWORD *)(bearer_noref + 64) != 255 )
          qmi_rmnet_flow_control(v10);
        qmi_rmnet_flow_control(v10);
        if ( !v28 )
        {
          if ( *(_BYTE *)(bearer_noref + 34) )
            dfc_send_ack(
              v10,
              *(unsigned __int8 *)(bearer_noref + 16),
              *(unsigned __int16 *)(bearer_noref + 32),
              *(_BYTE *)(v11 + 16),
              1);
        }
      }
      goto LABEL_7;
    }
LABEL_8:
    if ( ++v6 >= (unsigned __int64)(unsigned __int8)a2[1] )
      return _rcu_read_unlock(lock);
  }
  __break(0x5512u);
  return dfc_all_bearer_flow_ctl(lock);
}
