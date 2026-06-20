__int64 __fastcall ieee80211_destroy_assoc_data(__int64 a1, int a2)
{
  __int64 *v3; // x20
  int v5; // w9
  __int64 result; // x0
  _QWORD *v7; // [xsp+0h] [xbp-90h] BYREF
  __int64 v8; // [xsp+8h] [xbp-88h]
  __int64 v9; // [xsp+10h] [xbp-80h]
  __int64 v10; // [xsp+18h] [xbp-78h]
  __int64 v11; // [xsp+20h] [xbp-70h]
  __int64 v12; // [xsp+28h] [xbp-68h]
  __int64 v13; // [xsp+30h] [xbp-60h]
  __int64 v14; // [xsp+38h] [xbp-58h]
  __int64 v15; // [xsp+40h] [xbp-50h]
  __int64 v16; // [xsp+48h] [xbp-48h]
  __int64 v17; // [xsp+50h] [xbp-40h]
  __int64 v18; // [xsp+58h] [xbp-38h]
  __int64 v19; // [xsp+60h] [xbp-30h]
  __int64 v20; // [xsp+68h] [xbp-28h]
  __int64 v21; // [xsp+70h] [xbp-20h]
  __int64 v22; // [xsp+78h] [xbp-18h]
  _BOOL8 v23; // [xsp+80h] [xbp-10h]
  __int64 v24; // [xsp+88h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(__int64 **)(a1 + 2488);
  if ( a2 )
  {
    timer_delete_sync(a1 + 2264);
    sta_info_destroy_addr(a1, v3 + 120);
    *(_DWORD *)(a1 + 4152) = 0;
    *(_WORD *)(a1 + 4156) = 0;
    ieee80211_link_info_change_notify(a1, a1 + 3616, 128);
    *(_DWORD *)(a1 + 2500) = 0;
    *(_BYTE *)(a1 + 5639) = 0;
    if ( a2 != 1 )
    {
      v22 = 0;
      v23 = 0;
      v5 = *(unsigned __int16 *)(a1 + 5800);
      v20 = 0;
      v21 = 0;
      v18 = 0;
      v19 = 0;
      v16 = 0;
      v17 = 0;
      v14 = 0;
      v15 = 0;
      v12 = 0;
      v13 = 0;
      v10 = 0;
      v11 = 0;
      v8 = 0;
      v9 = 0;
      v7 = nullptr;
      v23 = a2 == 2;
      v8 = *v3;
      v9 = v3[8];
      v10 = v3[16];
      v11 = v3[24];
      v12 = v3[32];
      v13 = v3[40];
      v14 = v3[48];
      v15 = v3[56];
      v16 = v3[64];
      v17 = v3[72];
      v18 = v3[80];
      v19 = v3[88];
      v20 = v3[96];
      v21 = v3[104];
      v22 = v3[112];
      if ( v5 )
        v7 = v3 + 120;
      cfg80211_assoc_failure(*(_QWORD *)(a1 + 1608), &v7);
    }
    ieee80211_link_release_channel((__int64 *)(a1 + 3616));
    ieee80211_vif_set_links((unsigned __int16 *)a1, 0, 0);
  }
  result = kfree(v3);
  *(_QWORD *)(a1 + 2488) = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
