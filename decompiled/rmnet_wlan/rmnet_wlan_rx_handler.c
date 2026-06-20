__int64 __fastcall rmnet_wlan_rx_handler(__int64 *a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  __int64 v3; // x0
  int v4; // w8
  __int64 v5; // x20
  int v6; // w8
  int v7; // w8
  __int64 *v8; // x9
  __int64 v9; // x3
  int v10; // w8
  int v11; // w11
  unsigned int v12; // w20
  __int64 v13; // x8
  __int64 v14; // x9
  _QWORD *v15; // x21
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x20
  __int64 v19; // x0
  unsigned int v20; // w20
  __int64 v21; // x8
  __int64 *v22; // x9
  __int64 v23; // x0
  __int64 v24; // x21
  _QWORD *v25; // x9
  _DWORD *v26; // x0
  char v27; // w8
  _BYTE v28[4]; // [xsp+Ch] [xbp-44h] BYREF
  __int64 v29; // [xsp+10h] [xbp-40h] BYREF
  __int64 v30; // [xsp+18h] [xbp-38h] BYREF
  __int64 v31; // [xsp+20h] [xbp-30h] BYREF
  __int64 v32; // [xsp+28h] [xbp-28h]
  __int64 v33; // [xsp+30h] [xbp-20h]
  __int64 v34; // [xsp+38h] [xbp-18h]
  int v35; // [xsp+40h] [xbp-10h]
  __int64 v36; // [xsp+48h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *a1;
  v35 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  if ( v1 && (*(_BYTE *)(v1 + 128) & 7) != 5 )
  {
    _rcu_read_lock(a1);
    v3 = rmnet_wlan_stats_update(2);
    v4 = *(unsigned __int16 *)(v1 + 180);
    if ( v4 == 56710 )
    {
      v13 = *(_QWORD *)(v1 + 216);
      v14 = *(unsigned __int16 *)(v1 + 184);
      LOWORD(v30) = 0;
      v15 = (_QWORD *)(v13 + v14);
      v28[0] = 0;
      v28[0] = *(_BYTE *)(v13 + v14 + 6);
      v3 = ipv6_skip_exthdr(v1, 40, v28, &v30);
      if ( (v3 & 0x80000000) == 0 )
      {
        v12 = v3;
        if ( v28[0] != 58 )
          goto LABEL_21;
        v16 = v15[4];
        v31 = v15[3];
        v32 = v16;
        v17 = v15[2];
        v33 = v15[1];
        v34 = v17;
        LOBYTE(v35) = 6;
        v3 = rmnet_wlan_connection_find((__int64)&v31);
        if ( !v3 )
        {
LABEL_21:
          v21 = v15[3];
          v22 = (__int64 *)rmnet_wlan_fwd_hash[(unsigned int)(1640531527 * v21) >> 28];
          if ( !v22 )
            goto LABEL_33;
          while ( *((_BYTE *)v22 + 96) != 6 || v21 != v22[10] )
          {
            v22 = (__int64 *)*v22;
            if ( !v22 )
              goto LABEL_33;
          }
          v10 = v28[0];
          v9 = (__int64)(v22 + 9);
          BYTE4(v29) = 6;
          BYTE5(v29) = v28[0];
          if ( (_WORD)v30 )
          {
            v3 = rmnet_wlan_fragment_v6(v1, v12, (__int64)&v29, v9);
LABEL_28:
            if ( (_DWORD)v3 )
              v20 = 3;
            else
              v20 = 0;
            goto LABEL_34;
          }
LABEL_36:
          if ( v10 != 6 )
          {
            if ( v10 == 50 )
            {
              v24 = v9;
              v30 = 0;
              v26 = (_DWORD *)skb_header_pointer_0(v1, v12, 8, &v30);
              if ( !v26 )
              {
                v23 = 20;
LABEL_32:
                v3 = rmnet_wlan_stats_update(v23);
                goto LABEL_33;
              }
              LODWORD(v29) = *v26;
              goto LABEL_46;
            }
            if ( v10 != 17 )
              goto LABEL_33;
          }
          v24 = v9;
          LOWORD(v29) = *(_WORD *)(*(_QWORD *)(v1 + 224) + v12 + 2LL);
          if ( (rmnet_wlan_udp_encap_check(v1, &v29, v12) & 1) != 0 )
          {
            v25 = &rmnet_wlan_act_encap_drop_hash[(1640531527 * (unsigned int)(unsigned __int16)v29) >> 28];
            while ( 1 )
            {
              v25 = (_QWORD *)*v25;
              if ( !v25 )
                break;
              if ( *((unsigned __int16 *)v25 + 16) == (unsigned __int16)v29 )
              {
                sk_skb_reason_drop(0, v1, 2);
                v19 = 18;
                goto LABEL_20;
              }
            }
            v23 = 10;
            goto LABEL_32;
          }
LABEL_46:
          v27 = rmnet_wlan_tuple_present(&v29);
          v3 = v24;
          if ( (v27 & 1) == 0 )
          {
            if ( *(_DWORD *)(v1 + 168) != 131074 )
              goto LABEL_33;
            v3 = dev_get_by_name_rcu(&init_net, "dummy0");
            if ( v3 )
            {
              *(_QWORD *)(v1 + 16) = v3;
              v20 = 3;
              *(_DWORD *)(v1 + 168) = 0;
              goto LABEL_34;
            }
            v23 = 22;
            goto LABEL_32;
          }
        }
LABEL_18:
        v18 = *(_QWORD *)v3;
        if ( *(_QWORD *)v3 )
        {
          rmnet_wlan_tcp_mss_clamp(v1, 4608);
          *(_QWORD *)(v1 + 16) = v18;
          _dev_queue_xmit(v1, 0);
          v19 = 3;
LABEL_20:
          v3 = rmnet_wlan_stats_update(v19);
          v20 = 0;
          goto LABEL_34;
        }
        v23 = 4;
        goto LABEL_32;
      }
    }
    else if ( v4 == 8 )
    {
      v5 = *(_QWORD *)(v1 + 216) + *(unsigned __int16 *)(v1 + 184);
      if ( *(_BYTE *)(v5 + 9) != 1
        || (LODWORD(v31) = *(_DWORD *)(v5 + 16),
            v6 = *(_DWORD *)(v5 + 12),
            LOBYTE(v35) = 4,
            LODWORD(v33) = v6,
            (v3 = rmnet_wlan_connection_find((__int64)&v31)) == 0) )
      {
        v7 = *(_DWORD *)(v5 + 16);
        v8 = (__int64 *)rmnet_wlan_fwd_hash[(unsigned int)(1640531527 * v7) >> 28];
        if ( !v8 )
          goto LABEL_33;
        while ( *((_BYTE *)v8 + 96) != 4 || *((_DWORD *)v8 + 20) != v7 )
        {
          v8 = (__int64 *)*v8;
          if ( !v8 )
            goto LABEL_33;
        }
        v9 = (__int64)(v8 + 9);
        BYTE4(v29) = 4;
        v10 = *(unsigned __int8 *)(v5 + 9);
        BYTE5(v29) = *(_BYTE *)(v5 + 9);
        v11 = *(unsigned __int16 *)(v5 + 6);
        v12 = 4 * (*(_BYTE *)v5 & 0xF);
        if ( (v11 & 0xFFFFFF3F) != 0 )
        {
          v3 = rmnet_wlan_fragment_v4(v1, v12, (__int64)&v29);
          goto LABEL_28;
        }
        goto LABEL_36;
      }
      goto LABEL_18;
    }
LABEL_33:
    v20 = 3;
LABEL_34:
    _rcu_read_unlock(v3);
    result = v20;
    goto LABEL_35;
  }
  result = 3;
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
