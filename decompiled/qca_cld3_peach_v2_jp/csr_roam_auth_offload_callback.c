__int64 __fastcall csr_roam_auth_offload_callback(_QWORD *a1, unsigned int a2, __int64 a3, int a4)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x0
  __int64 v18; // x21
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  _DWORD *v29; // x8
  __int64 v30; // x0
  unsigned int v31; // w20
  int v32; // [xsp+8h] [xbp-48h] BYREF
  __int16 v33; // [xsp+Ch] [xbp-44h]
  __int64 v34; // [xsp+10h] [xbp-40h] BYREF
  _QWORD v35[5]; // [xsp+18h] [xbp-38h] BYREF
  int v36; // [xsp+40h] [xbp-10h]
  __int64 v37; // [xsp+48h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = sme_acquire_global_lock((__int64)(a1 + 1596));
  if ( !(_DWORD)result )
  {
    v32 = a3;
    v33 = WORD2(a3);
    v34 = 0;
    memset(v35, 0, sizeof(v35));
    if ( (unsigned __int8)a2 <= 5u && a1[2153] + 96LL * (unsigned __int8)a2 )
    {
      v17 = _qdf_mem_malloc(0x180u, "csr_process_roam_auth_sae_callback", 7964);
      if ( v17 )
      {
        v18 = v17;
        v19 = a1[2694];
        WORD1(v34) = 52;
        HIDWORD(v34) = (unsigned __int8)a2;
        v36 = a4;
        wlan_cm_get_roam_offload_ssid(v19, a2, (char *)v35 + 7, (_BYTE *)v35 + 6);
        qdf_mem_copy(v35, &v32, 6u);
        *(_QWORD *)(v18 + 328) = &v34;
        if ( a1 && (v28 = a1[2153]) != 0 && (*(_BYTE *)(v28 + 96LL * (unsigned __int8)a2 + 1) & 1) != 0 )
        {
          wlan_get_operation_chan_freq_vdev_id(a1[2695], a2);
          v29 = (_DWORD *)a1[2746];
          if ( v29 )
          {
            v30 = a1[2694];
            if ( *(v29 - 1) != 1469140685 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))v29)(v30, a2, v18, 49, 0);
          }
        }
        else
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: Session ID: %d is not valid",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "csr_roam_call_callback",
            (unsigned __int8)a2);
        }
        _qdf_mem_free(v18);
        v31 = 0;
        goto LABEL_14;
      }
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: WPA3 Preauth event with invalid session id:%d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "csr_process_roam_auth_sae_callback",
        (unsigned __int8)a2);
    }
    v31 = 16;
LABEL_14:
    sme_release_global_lock((__int64)(a1 + 1596));
    result = v31;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
