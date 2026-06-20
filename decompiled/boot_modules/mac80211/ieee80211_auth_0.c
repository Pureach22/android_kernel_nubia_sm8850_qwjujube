__int64 __fastcall ieee80211_auth_0(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  __int64 v5; // x20
  int v7; // w8
  bool v8; // nf
  __int64 result; // x0
  __int64 v10; // x2
  __int64 v11; // x1
  __int64 v12; // x3
  __int64 v13; // x20
  int v14; // w8
  __int64 v15; // x1
  __int64 v16; // [xsp+28h] [xbp-18h] BYREF
  int v17; // [xsp+30h] [xbp-10h]
  __int64 v18; // [xsp+38h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[310];
  v5 = a1[202];
  v16 = 11534336;
  if ( v4 )
  {
    v7 = *(_DWORD *)(v4 + 16) + 1;
    v8 = *(_DWORD *)(v4 + 16) - 3 < 0;
    *(_DWORD *)(v4 + 16) = v7;
    if ( v8 != __OFSUB__(v7, 4) )
    {
      if ( *(_WORD *)(v4 + 20) == 3 )
        LOWORD(v16) = jiffies_to_msecs(500);
      v17 = *(_DWORD *)(v4 + 44);
      drv_mgd_prepare_tx(v5, a1, &v16);
      printk(&unk_BD099, a1 + 205, v4 + 48, *(unsigned int *)(v4 + 16));
      v10 = *(unsigned __int16 *)(v4 + 20);
      *(_WORD *)(v4 + 22) = 2;
      if ( (_DWORD)v10 == 3 )
      {
        v11 = *(unsigned __int16 *)(v4 + 54);
        v12 = *(unsigned __int16 *)(v4 + 56);
        *(_WORD *)(v4 + 22) = v11;
      }
      else
      {
        v12 = 0;
        v11 = 1;
      }
      v13 = *(_QWORD *)(v5 + 96);
      if ( (v13 & 0x10000) != 0 )
        v14 = 1048577;
      else
        v14 = 0;
      ieee80211_send_auth(a1, v11, v10, v12, v4 + 72, *(_QWORD *)(v4 + 64), v4 + 48, v4 + 48, 0, 0, 0, v14);
      if ( (v13 & 0x10000) != 0 )
      {
        v15 = round_jiffies_up(jiffies + 125LL);
      }
      else if ( *(_WORD *)(v4 + 20) == 3 )
      {
        v15 = jiffies + 500LL;
      }
      else
      {
        v15 = jiffies + 50LL;
      }
      *(_QWORD *)(v4 + 8) = v15;
      *(_BYTE *)(v4 + 42) = 1;
      if ( !a1[284] || v15 - a1[285] < 0 )
        mod_timer(a1 + 283, v15);
      result = 0;
    }
    else
    {
      printk(&unk_BA108, a1 + 205, v4 + 48, a4);
      cfg80211_unlink_bss(*(_QWORD *)(v5 + 72), *(_QWORD *)v4);
      result = 4294967186LL;
    }
  }
  else
  {
    __break(0x800u);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
