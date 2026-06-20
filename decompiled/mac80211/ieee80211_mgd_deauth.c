__int64 __fastcall ieee80211_mgd_deauth(__int64 a1, _QWORD *a2)
{
  char v2; // w9
  __int64 v3; // x8
  char v4; // w22
  _DWORD *v5; // x20
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 v8; // x20
  __int64 result; // x0
  unsigned int v10; // w21
  _QWORD *v11; // x19
  _QWORD *v12; // x23
  __int64 v13; // x0
  unsigned int v14; // w21
  __int64 v16; // x0
  __int16 v17; // w9
  unsigned int v18; // w21
  __int64 v19; // x0
  __int64 v20; // [xsp+0h] [xbp-50h] BYREF
  int v21; // [xsp+8h] [xbp-48h]
  __int64 v22; // [xsp+10h] [xbp-40h]
  __int64 v23; // [xsp+18h] [xbp-38h]
  __int16 v24; // [xsp+20h] [xbp-30h]
  __int16 v25; // [xsp+22h] [xbp-2Eh]
  int v26; // [xsp+24h] [xbp-2Ch]
  _QWORD v27[3]; // [xsp+28h] [xbp-28h] BYREF
  __int16 v28; // [xsp+40h] [xbp-10h]
  __int64 v29; // [xsp+48h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_BYTE *)a2 + 26);
  v3 = *(_QWORD *)(a1 + 2480);
  v28 = 0;
  v4 = v2 ^ 1;
  memset(v27, 0, sizeof(v27));
  v21 = 0;
  v20 = 12582912;
  if ( v3 )
  {
    v5 = (_DWORD *)*a2;
    if ( !(*(_DWORD *)*a2 ^ *(_DWORD *)(v3 + 48) | *(unsigned __int16 *)(*a2 + 4LL) ^ *(unsigned __int16 *)(v3 + 52)) )
    {
      v10 = *((unsigned __int16 *)a2 + 12);
      v11 = (_QWORD *)a1;
      v12 = a2;
      ieee80211_get_reason_code_string(*((_WORD *)a2 + 12));
      printk(&unk_BABBB, v11 + 205, v5, v10);
      v13 = v11[202];
      v21 = *(_DWORD *)(v11[310] + 44LL);
      drv_mgd_prepare_tx(v13, v11, &v20);
      ieee80211_send_deauth_disassoc(v11, *v12, *v12, 192, *((unsigned __int16 *)v12 + 12), v4 & 1, v27);
      ieee80211_destroy_auth_data((__int64)v11, 0);
LABEL_12:
      v17 = *((_WORD *)v12 + 12);
      v22 = 1;
      v23 = 3;
      goto LABEL_13;
    }
  }
  v6 = *(_QWORD *)(a1 + 2488);
  if ( v6 )
  {
    v7 = *a2;
    if ( !(*(_DWORD *)*a2 ^ *(_DWORD *)(v6 + 960) | *(unsigned __int16 *)(*a2 + 4LL) ^ *(unsigned __int16 *)(v6 + 964)) )
    {
      v14 = *((unsigned __int16 *)a2 + 12);
      v11 = (_QWORD *)a1;
      ieee80211_get_reason_code_string(*((_WORD *)a2 + 12));
      printk(&unk_B90BF, v11 + 205, v7, v14);
      v16 = v11[202];
      v21 = *(_DWORD *)(v11[311] + 1044LL);
      drv_mgd_prepare_tx(v16, v11, &v20);
      ieee80211_send_deauth_disassoc(v11, *a2, *a2, 192, *((unsigned __int16 *)a2 + 12), v4 & 1, v27);
      ieee80211_destroy_assoc_data((__int64)v11, 3);
      v17 = *((_WORD *)a2 + 12);
      v22 = 1;
      v23 = 3;
LABEL_13:
      v19 = v11[201];
      v24 = v17;
      v25 = 0;
      v26 = 0;
      cfg80211_tx_mlme_mgmt(v19, v27, 26, 0);
      drv_event_callback(v11[202]);
      drv_mgd_complete_tx(v11[202], v11, &v20);
      result = 0;
      goto LABEL_8;
    }
  }
  if ( (*(_BYTE *)(a1 + 2477) & 8) != 0 )
  {
    v8 = *a2;
    if ( !(*(_DWORD *)*a2 ^ *(_DWORD *)(a1 + 4802) | *(unsigned __int16 *)(*a2 + 4LL) ^ *(unsigned __int16 *)(a1 + 4806)) )
    {
      v18 = *((unsigned __int16 *)a2 + 12);
      v11 = (_QWORD *)a1;
      v12 = a2;
      ieee80211_get_reason_code_string(*((_WORD *)a2 + 12));
      printk(&unk_BA590, v11 + 205, v8, v18);
      ieee80211_set_disassoc((__int64)v11, 0xC0u, *((unsigned __int16 *)v12 + 12), v4 & 1, (__int64)v27);
      goto LABEL_12;
    }
  }
  result = 4294967189LL;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
