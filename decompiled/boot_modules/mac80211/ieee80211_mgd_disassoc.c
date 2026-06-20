__int64 __fastcall ieee80211_mgd_disassoc(__int64 a1, __int64 *a2)
{
  int *v2; // x8
  int v3; // w9
  int v4; // w11
  int v5; // w10
  int v6; // w8
  __int64 result; // x0
  unsigned int v9; // w21
  int *v10; // x20
  _QWORD v13[3]; // [xsp+18h] [xbp-28h] BYREF
  __int16 v14; // [xsp+30h] [xbp-10h]
  __int64 v15; // [xsp+38h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 2477) & 8) == 0 )
    goto LABEL_6;
  v2 = (int *)*a2;
  v14 = 0;
  v3 = *(_DWORD *)(a1 + 4802);
  v4 = *(unsigned __int16 *)(a1 + 4806);
  memset(v13, 0, sizeof(v13));
  v5 = *v2;
  v6 = *((unsigned __int16 *)v2 + 2);
  if ( v3 == v5 && v4 == v6 )
  {
    v9 = *((unsigned __int16 *)a2 + 12);
    v10 = (int *)*a2;
    ieee80211_get_reason_code_string(*((_WORD *)a2 + 12));
    printk(&unk_BCFEA, a1 + 1640, v10, v9);
    ieee80211_set_disassoc(a1, 0xA0u, *((unsigned __int16 *)a2 + 12), (*((_BYTE *)a2 + 26) & 1) == 0, (__int64)v13);
    cfg80211_tx_mlme_mgmt(*(_QWORD *)(a1 + 1608), v13, 26, 0);
    drv_event_callback(*(_QWORD *)(a1 + 1616));
    result = 0;
  }
  else
  {
LABEL_6:
    result = 4294967189LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
