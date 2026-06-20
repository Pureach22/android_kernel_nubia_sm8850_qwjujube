__int64 __fastcall rmnet_shs_is_filter_match(__int64 a1)
{
  int v2; // w8
  unsigned int v3; // w20
  __int64 v4; // x0
  char *v5; // x21
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x22
  __int64 v9; // x0
  __int64 v10; // x21
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x22
  _QWORD v15[2]; // [xsp+8h] [xbp-48h] BYREF
  int v16; // [xsp+18h] [xbp-38h]
  _QWORD v17[6]; // [xsp+20h] [xbp-30h] BYREF

  v17[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v15[0] = 0;
  v15[1] = 0;
  memset(v17, 0, 40);
  raw_spin_lock_bh(&rmnet_shs_ll_ht_splock);
  v2 = *(unsigned __int16 *)(a1 + 180);
  if ( v2 != 56710 )
  {
    v3 = 0;
    if ( v2 != 8 )
      goto LABEL_21;
    v4 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD *))rmnet_shs_header_ptr)(a1, 0, 20, v15);
    if ( v4 )
    {
      v5 = (char *)v4;
      v3 = 0;
      v6 = rmnet_shs_ll_filter_ht[(unsigned int)(1640531527 * *(_DWORD *)(v4 + 12)) >> 23];
      if ( v6 )
      {
        v7 = v6 - 16;
        if ( v7 )
        {
          v3 = 0;
          while ( 1 )
          {
            v8 = *(_QWORD *)(v7 + 16);
            if ( (unsigned int)ipv4_packet_match(a1, v5, v7 + 32) )
              break;
            if ( v8 )
            {
              v7 = v8 - 16;
              if ( v8 != 16 )
                continue;
            }
            goto LABEL_21;
          }
LABEL_20:
          v3 = 1;
          goto LABEL_21;
        }
      }
      goto LABEL_21;
    }
LABEL_19:
    v3 = 0;
    goto LABEL_21;
  }
  v9 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD *))rmnet_shs_header_ptr)(a1, 0, 40, v17);
  if ( !v9 )
    goto LABEL_19;
  v10 = v9;
  v3 = 0;
  v11 = rmnet_shs_ll_filter_ht[(unsigned int)(1640531527 * *(_DWORD *)(v9 + 8)) >> 23];
  if ( v11 )
  {
    v12 = v11 - 16;
    if ( v12 )
    {
      v3 = 0;
      while ( 1 )
      {
        v13 = *(_QWORD *)(v12 + 16);
        if ( (unsigned int)ipv6_packet_match(a1, v10, v12 + 32) )
          goto LABEL_20;
        if ( v13 )
        {
          v12 = v13 - 16;
          if ( v13 != 16 )
            continue;
        }
        break;
      }
    }
  }
LABEL_21:
  raw_spin_unlock_bh(&rmnet_shs_ll_ht_splock);
  _ReadStatusReg(SP_EL0);
  return v3;
}
