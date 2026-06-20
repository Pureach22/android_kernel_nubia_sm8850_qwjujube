__int64 __fastcall wlan_hdd_update_bw_from_mlme(__int64 *a1, __int64 a2)
{
  unsigned int v2; // w19
  unsigned int v4; // w21
  char is_dbs_enable; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v15; // w20
  __int64 v16; // [xsp+8h] [xbp-38h] BYREF
  __int64 v17; // [xsp+10h] [xbp-30h]
  __int64 v18; // [xsp+18h] [xbp-28h]
  __int64 v19; // [xsp+20h] [xbp-20h]
  __int64 v20; // [xsp+28h] [xbp-18h]
  __int64 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int16 *)(a2 + 1178);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  if ( v2 <= 4 )
  {
    v4 = *(_DWORD *)(a2 + 1148);
    if ( v4 > (unsigned int)wlan_reg_ch_to_freq(0xDu) )
    {
      is_dbs_enable = policy_mgr_is_dbs_enable(*a1);
      if ( !(unsigned int)wma_get_caps_for_phyidx_hwmode(&v16, is_dbs_enable & 1, 2) )
      {
        if ( v2 == 3 )
        {
          if ( (v17 & 0xC00000000LL) != 0 )
          {
            v2 = 3;
            goto LABEL_4;
          }
          v15 = 2;
        }
        else
        {
          if ( v2 != 4 )
            goto LABEL_4;
          if ( (v17 & 0x800000000LL) != 0 )
          {
            v2 = 4;
            goto LABEL_4;
          }
          if ( (v17 & 0x400000000LL) != 0 )
            v15 = 3;
          else
            v15 = 2;
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: ch_width updated from %d to %d vht_5g: %x",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "wlan_hdd_update_bw_from_mlme",
          v2,
          (unsigned __int16)v15);
        v2 = v15;
      }
    }
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return v2;
}
