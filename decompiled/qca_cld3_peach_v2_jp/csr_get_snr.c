__int64 __fastcall csr_get_snr(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x0
  __int64 v9; // x19
  __int64 v10; // x0
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // [xsp+0h] [xbp-40h] BYREF
  __int64 v21; // [xsp+8h] [xbp-38h]
  __int64 v22; // [xsp+10h] [xbp-30h]
  __int64 v23; // [xsp+18h] [xbp-28h]
  __int64 v24; // [xsp+20h] [xbp-20h]
  __int64 v25; // [xsp+28h] [xbp-18h]
  int v26; // [xsp+30h] [xbp-10h] BYREF
  __int16 v27; // [xsp+34h] [xbp-Ch]
  unsigned __int8 v28; // [xsp+36h] [xbp-Ah]
  __int64 v29; // [xsp+38h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v8 = _qdf_mem_malloc(0x20u, "csr_get_snr", 6663);
  if ( v8 )
  {
    v9 = v8;
    v10 = *(_QWORD *)(a1 + 21560);
    v26 = a3;
    v27 = WORD2(a3);
    v28 = 6;
    wlan_objmgr_pdev_iterate_obj_list(
      v10,
      2,
      (void (__fastcall *)(__int64, __int64, __int64))csr_get_vdev_id_from_bssid,
      (__int64)&v26,
      0,
      0xBu);
    if ( v28 >= 6u )
    {
      _qdf_mem_free(v9);
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Couldn't find session_id for given BSSID",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "csr_get_snr",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25);
      goto LABEL_7;
    }
    *(_BYTE *)(v9 + 4) = v28;
    *(_DWORD *)v9 = 2102313;
    *(_QWORD *)(v9 + 8) = a2;
    *(_QWORD *)(v9 + 16) = a4;
    LODWORD(v20) = 5161;
    v21 = v9;
    result = scheduler_post_message_debug(0x34u, 0x34u, 52, (unsigned __int16 *)&v20, 0x1A1Eu, (__int64)"csr_get_snr");
    if ( (_DWORD)result )
    {
      _qdf_mem_free(v9);
LABEL_7:
      result = 16;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
