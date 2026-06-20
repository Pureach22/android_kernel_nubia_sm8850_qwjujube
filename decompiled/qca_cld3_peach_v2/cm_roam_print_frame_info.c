__int64 __fastcall cm_roam_print_frame_info(__int64 result, __int64 a2, _BYTE *a3, unsigned __int8 *a4, __int64 a5)
{
  char v5; // w24
  __int64 v10; // x23
  __int64 v11; // x26
  unsigned __int64 v12; // x27
  _BYTE *v13; // x9
  int v14; // w8
  int v15; // w10
  int v16; // w11
  _BYTE *v17; // x28
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x25
  __int64 v27; // [xsp+0h] [xbp-50h]
  __int64 v28; // [xsp+8h] [xbp-48h]
  __int64 v29; // [xsp+10h] [xbp-40h]
  __int64 v30; // [xsp+18h] [xbp-38h]
  __int64 v31; // [xsp+20h] [xbp-30h]
  _BYTE v32[4]; // [xsp+2Ch] [xbp-24h] BYREF
  char s[8]; // [xsp+30h] [xbp-20h] BYREF
  __int64 v34; // [xsp+38h] [xbp-18h]
  __int64 v35; // [xsp+40h] [xbp-10h]
  __int64 v36; // [xsp+48h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *a3 )
  {
    v5 = *(_BYTE *)(a2 + 168);
    v10 = result;
    v11 = 0;
    v12 = 0;
    v34 = 0;
    v35 = 0;
    *(_QWORD *)s = 0;
    do
    {
      v32[0] = v5;
      if ( v12 == 55 )
        __break(0x5512u);
      v17 = &a3[v11];
      if ( a3[v11 + 30] == 3 && (wlan_is_sae_auth_log_present_for_bssid(v10, v17 + 9, v32) & 1) != 0 )
      {
        result = wlan_print_cached_sae_auth_logs(v10, v17 + 9, v32[0]);
      }
      else
      {
        qdf_mem_set(s, 0x18u, 0);
        mlme_get_converted_timestamp(*((_DWORD *)v17 + 4), s);
        if ( v17[20] != 3 )
        {
          v26 = jiffies;
          if ( cm_roam_print_frame_info___last_ticks - jiffies + 125 < 0 )
          {
            v13 = &a3[v11];
            v14 = (_DWORD)a3 + v11 + 9;
            if ( &a3[v11] == (_BYTE *)-9LL )
            {
              v15 = 0;
              v16 = 0;
            }
            else
            {
              v14 = (unsigned __int8)v13[10];
              v15 = (unsigned __int8)v13[11];
              v16 = (unsigned __int8)v13[14];
            }
            LODWORD(v31) = *((unsigned __int16 *)v13 + 14);
            LODWORD(v30) = *((unsigned __int16 *)v13 + 16);
            LODWORD(v29) = v16;
            LODWORD(v28) = v15;
            LODWORD(v27) = v14;
            qdf_trace_msg(
              0x68u,
              4u,
              "%s [%s%s] VDEV[%d] bssid: %02x:%02x:%02x:**:**:%02x status:%d seq_num:%d",
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              s,
              v27,
              v28,
              v29,
              v30,
              v31);
            cm_roam_print_frame_info___last_ticks = v26;
          }
        }
        result = cm_roam_mgmt_frame_event(a2, (__int64)(v17 + 8), a4, a5);
      }
      ++v12;
      v11 += 120;
    }
    while ( v12 < (unsigned __int8)*a3 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
