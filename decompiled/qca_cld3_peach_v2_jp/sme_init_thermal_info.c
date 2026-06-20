__int64 __fastcall sme_init_thermal_info(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  unsigned int thermal_temp; // w0
  __int64 result; // x0
  int v6; // w9
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // [xsp+0h] [xbp-80h] BYREF
  __int64 v16; // [xsp+8h] [xbp-78h]
  __int64 v17; // [xsp+10h] [xbp-70h]
  __int64 v18; // [xsp+18h] [xbp-68h]
  __int64 v19; // [xsp+20h] [xbp-60h]
  __int64 v20; // [xsp+28h] [xbp-58h]
  __int64 v21; // [xsp+30h] [xbp-50h] BYREF
  __int64 v22; // [xsp+38h] [xbp-48h]
  __int64 v23; // [xsp+40h] [xbp-40h]
  __int64 v24; // [xsp+48h] [xbp-38h]
  __int64 v25; // [xsp+50h] [xbp-30h]
  __int64 v26; // [xsp+58h] [xbp-28h]
  __int64 v27; // [xsp+60h] [xbp-20h]
  __int64 v28; // [xsp+68h] [xbp-18h]
  __int64 v29; // [xsp+70h] [xbp-10h]
  __int64 v30; // [xsp+78h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v21 = 0;
  v2 = _qdf_mem_malloc(0x2Cu, "sme_init_thermal_info", 9099);
  if ( v2 )
  {
    v3 = v2;
    thermal_temp = ucfg_fwol_get_thermal_temp(*(_QWORD *)(a1 + 21552), &v21);
    if ( thermal_temp )
    {
      result = qdf_status_to_os_return(thermal_temp);
    }
    else
    {
      v6 = HIDWORD(v21);
      *(_BYTE *)(v3 + 25) = v21;
      *(_DWORD *)(v3 + 28) = v6;
      *(_BYTE *)(v3 + 32) = v25;
      *(_BYTE *)(v3 + 33) = BYTE4(v25);
      *(_BYTE *)(v3 + 34) = v26;
      *(_BYTE *)(v3 + 35) = BYTE4(v26);
      *(_BYTE *)(v3 + 36) = v27;
      *(_BYTE *)(v3 + 37) = BYTE4(v27);
      *(_WORD *)v3 = v22;
      *(_WORD *)(v3 + 2) = WORD2(v23);
      *(_WORD *)(v3 + 4) = WORD1(v22);
      *(_WORD *)(v3 + 6) = HIWORD(v23);
      *(_WORD *)(v3 + 8) = WORD2(v22);
      *(_WORD *)(v3 + 10) = v24;
      *(_WORD *)(v3 + 12) = HIWORD(v22);
      *(_WORD *)(v3 + 14) = WORD1(v24);
      *(_WORD *)(v3 + 16) = v23;
      *(_WORD *)(v3 + 18) = WORD2(v24);
      *(_WORD *)(v3 + 20) = WORD1(v23);
      *(_WORD *)(v3 + 22) = HIWORD(v24);
      *(_DWORD *)(v3 + 40) = v29;
      if ( (unsigned int)qdf_mutex_acquire(a1 + 12776) )
      {
        _qdf_mem_free(v3);
      }
      else
      {
        LOWORD(v15) = 4313;
        v16 = v3;
        if ( !(unsigned int)scheduler_post_message_debug(
                              0x34u,
                              0x36u,
                              54,
                              (unsigned __int16 *)&v15,
                              0x23C4u,
                              (__int64)"sme_init_thermal_info") )
        {
          qdf_mutex_release(a1 + 12776);
          result = 0;
          goto LABEL_10;
        }
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Not able to post WMA_SET_THERMAL_INFO_CMD to WMA!",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "sme_init_thermal_info");
        _qdf_mem_free(v3);
        qdf_mutex_release(a1 + 12776);
      }
      result = 16;
    }
  }
  else
  {
    result = 2;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
