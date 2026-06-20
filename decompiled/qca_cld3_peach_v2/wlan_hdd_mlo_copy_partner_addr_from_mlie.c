__int64 __fastcall wlan_hdd_mlo_copy_partner_addr_from_mlie(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x19
  unsigned int v6; // w8
  __int64 v7; // x9
  unsigned int mlie; // w19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w9
  _QWORD *v27; // x8
  int v28; // w9
  __int16 v29; // w8
  __int64 v30; // [xsp+8h] [xbp-C8h] BYREF
  __int64 v31; // [xsp+10h] [xbp-C0h] BYREF
  __int64 v32; // [xsp+18h] [xbp-B8h] BYREF
  _QWORD v33[6]; // [xsp+20h] [xbp-B0h] BYREF
  _QWORD v34[6]; // [xsp+50h] [xbp-80h] BYREF
  _QWORD v35[6]; // [xsp+80h] [xbp-50h] BYREF
  _QWORD v36[4]; // [xsp+B0h] [xbp-20h] BYREF

  v36[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v31 = 0;
  memset(v36, 0, 24);
  memset(v35, 0, sizeof(v35));
  memset(v34, 0, sizeof(v34));
  v32 = 0;
  memset(v33, 0, sizeof(v33));
  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 1360);
    if ( v2 )
    {
      v3 = *(_QWORD *)(v2 + 2224);
      if ( v3 )
      {
        qdf_mutex_acquire(v2 + 1656);
        v6 = *(_DWORD *)(v3 + 104);
        if ( v6 > 6 )
        {
          v7 = *(_QWORD *)(v3 + 112);
          if ( v7 )
          {
            mlie = util_find_mlie(v7 + 6, v6 - 6, &v30, &v31);
            if ( mlie || !v30 )
            {
              qdf_mutex_release(v2 + 1656);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: ML IE not found %d",
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                "wlan_hdd_mlo_copy_partner_addr_from_mlie",
                mlie);
              goto LABEL_15;
            }
            mlie = util_get_bvmlie_persta_partner_info(v30, v31, &v32, 255);
            qdf_mutex_release(v2 + 1656);
            if ( mlie )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Unable to find per-sta profile in ML IE",
                v9,
                v10,
                v11,
                v12,
                v13,
                v14,
                v15,
                v16,
                "wlan_hdd_mlo_copy_partner_addr_from_mlie");
LABEL_15:
              result = mlie;
              goto LABEL_13;
            }
            if ( (_BYTE)v32 )
            {
              v26 = *(unsigned __int8 *)(a1 + 93);
              if ( BYTE6(v33[0]) == v26 )
              {
                v27 = v33;
LABEL_19:
                v28 = *(_DWORD *)v27;
                v29 = *((_WORD *)v27 + 2);
                result = 0;
                *(_DWORD *)a2 = v28;
                *(_WORD *)(a2 + 4) = v29;
                goto LABEL_13;
              }
              if ( (unsigned __int8)v32 != 1 )
              {
                if ( BYTE6(v34[0]) == v26 )
                {
                  v27 = v34;
                  goto LABEL_19;
                }
                if ( (unsigned __int8)v32 != 2 )
                {
                  if ( BYTE6(v35[0]) == v26 )
                  {
                    v27 = v35;
                    goto LABEL_19;
                  }
                  if ( (unsigned __int8)v32 != 3 )
                  {
                    if ( BYTE6(v36[0]) == v26 )
                    {
                      v27 = v36;
                      goto LABEL_19;
                    }
                    if ( (unsigned __int8)v32 != 4 )
                      __break(0x5512u);
                  }
                }
              }
            }
            result = 17;
            goto LABEL_13;
          }
        }
        qdf_mutex_release(v2 + 1656);
      }
    }
    result = 4;
  }
  else
  {
    result = 29;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
