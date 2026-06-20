__int64 __fastcall sme_ps_timer_flush_sync(_QWORD *a1, unsigned int a2)
{
  unsigned int v2; // w20
  __int64 result; // x0
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD *v24; // x23
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  _DWORD *v33; // x0
  __int64 v34; // x21
  _QWORD *v35; // x23
  int v36; // w24
  const char *v37; // x2
  const char *v38; // x3
  unsigned int v39; // w20
  char v40[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v41; // [xsp+8h] [xbp-8h]

  v2 = (unsigned __int8)a2;
  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned __int8)a2 <= 5u )
  {
    v6 = sme_acquire_global_lock((__int64)(a1 + 1605));
    if ( v6 )
    {
      v15 = v6;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: can't acquire sme global lock",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "sme_ps_timer_flush_sync");
      result = v15;
      goto LABEL_18;
    }
    if ( (*(_BYTE *)(a1[1] + 5633LL) & 1) != 0 )
    {
      if ( (mlme_get_user_ps(a1[2703], a2) & 1) != 0 )
      {
        if ( cm_is_vdevid_active(a1[2704], a2) )
        {
          v24 = &a1[24 * (unsigned __int8)a2];
          if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)(v24 + 1652)) == 21 )
          {
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: flushing powersave enable for vdev %u",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              "sme_ps_timer_flush_sync",
              v2);
            qdf_mc_timer_stop((__int64)(v24 + 1652));
            v33 = (_DWORD *)_qdf_mem_malloc(0xCu, "sme_ps_timer_flush_sync", 594);
            if ( v33 )
            {
              v34 = (__int64)v33;
              v35 = v24 + 1649;
              if ( *((_BYTE *)v35 + 20) )
              {
                *v33 = 1;
                sme_ps_fill_uapsd_req_params(a1, v33 + 1, v2, v40);
                *(_BYTE *)(v34 + 5) = 1;
                v36 = 2;
              }
              else
              {
                v36 = 1;
                *v33 = 0;
              }
              *(_DWORD *)(v34 + 8) = v2;
              wma_enable_sta_ps_mode(v34);
              _qdf_mem_free(v34);
              v39 = 0;
              *((_DWORD *)v35 + 3) = v36;
            }
            else
            {
              v39 = 2;
            }
            goto LABEL_17;
          }
LABEL_16:
          v39 = 0;
LABEL_17:
          sme_release_global_lock((__int64)(a1 + 1605));
          result = v39;
          goto LABEL_18;
        }
LABEL_15:
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Power save not allowed for vdev id %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "sme_ps_timer_flush_sync",
          v2);
        goto LABEL_16;
      }
      v37 = "%s: vdev:%d Cannot initiate PS. PS is disabled by usr(ioctl)";
      v38 = "sme_ps_enable_user_check";
    }
    else
    {
      v37 = "%s: vdev:%d power save mode is disabled via ini";
      v38 = "sme_enable_sta_ps_check";
    }
    qdf_trace_msg(0x34u, 8u, v37, v7, v8, v9, v10, v11, v12, v13, v14, v38, v2);
    goto LABEL_15;
  }
  result = 4;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
