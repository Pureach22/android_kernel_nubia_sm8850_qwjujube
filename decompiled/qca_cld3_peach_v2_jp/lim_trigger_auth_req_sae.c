__int64 __fastcall lim_trigger_auth_req_sae(__int64 a1, __int64 a2, int *a3)
{
  __int64 v6; // x0
  __int64 v7; // x20
  int v8; // w9
  int param; // w0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v18; // w8
  __int64 result; // x0
  size_t v20; // x2
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 (__fastcall *v29)(__int64, __int64 *); // x9
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w19
  int v39; // [xsp+0h] [xbp-60h]
  int v40; // [xsp+8h] [xbp-58h]
  int v41; // [xsp+10h] [xbp-50h]
  int v42; // [xsp+18h] [xbp-48h]
  __int64 v43; // [xsp+28h] [xbp-38h] BYREF
  __int64 v44; // [xsp+30h] [xbp-30h]
  __int64 v45; // [xsp+38h] [xbp-28h]
  __int64 v46; // [xsp+40h] [xbp-20h]
  __int64 v47; // [xsp+48h] [xbp-18h]
  __int64 v48; // [xsp+50h] [xbp-10h]
  __int64 v49; // [xsp+58h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v6 = _qdf_mem_malloc(0x34u, "lim_trigger_auth_req_sae", 681);
  if ( v6 )
  {
    v7 = v6;
    *(_DWORD *)v6 = 3413134;
    *(_DWORD *)(v6 + 4) = *(unsigned __int8 *)(a2 + 10);
    v8 = *a3;
    *(_WORD *)(v6 + 12) = *((_WORD *)a3 + 2);
    *(_DWORD *)(v6 + 8) = v8;
    param = wlan_crypto_get_param(*(_QWORD *)(a2 + 16), 7u);
    if ( (param & 0x10000000) != 0 )
    {
      v18 = 25;
    }
    else if ( (param & 0x8000000) != 0 )
    {
      v18 = 24;
    }
    else if ( (param & 0x800) != 0 )
    {
      v18 = 9;
    }
    else
    {
      if ( (param & 0x400) == 0 )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Invalid SAE Keymgmt suite %d",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "lim_get_sae_keymgmt_suite");
      v18 = 8;
    }
    *(_DWORD *)(v7 + 48) = v18;
    v20 = *(unsigned __int8 *)(a2 + 36);
    *(_BYTE *)(v7 + 14) = v20;
    qdf_mem_copy((void *)(v7 + 15), (const void *)(a2 + 37), v20);
    v41 = *(unsigned __int8 *)(v7 + 13);
    v42 = *(_DWORD *)(v7 + 48);
    v40 = *(unsigned __int8 *)(v7 + 10);
    v39 = *(unsigned __int8 *)(v7 + 9);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: vdev_id %d ssid %.*s %02x:%02x:%02x:**:**:%02xakm %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "lim_trigger_auth_req_sae",
      *(unsigned int *)(v7 + 4),
      *(unsigned __int8 *)(v7 + 14),
      v7 + 15,
      *(unsigned __int8 *)(v7 + 8),
      v39,
      v40,
      v41,
      v42);
    v29 = *(__int64 (__fastcall **)(__int64, __int64 *))(a1 + 12416);
    v44 = v7;
    LOWORD(v43) = 5262;
    HIDWORD(v43) = 0;
    if ( *((_DWORD *)v29 - 1) != -1829016265 )
      __break(0x8229u);
    result = v29(a1, &v43);
    if ( (_DWORD)result )
    {
      v38 = result;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: SAE failed for AUTH frame",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "lim_trigger_auth_req_sae");
      _qdf_mem_free(v7);
      result = v38;
    }
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
