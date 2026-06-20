__int64 __fastcall sme_handle_sae_msg(__int64 a1, unsigned __int8 a2, unsigned __int8 a3, __int64 a4, const void *a5)
{
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v18; // w23
  __int64 v19; // x0
  __int64 v20; // x22
  __int16 v21; // w9
  unsigned int v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w20
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x23
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w0
  __int64 v44; // [xsp+10h] [xbp-40h] BYREF
  __int64 v45; // [xsp+18h] [xbp-38h]
  __int64 v46; // [xsp+20h] [xbp-30h]
  __int64 v47; // [xsp+28h] [xbp-28h]
  __int64 v48; // [xsp+30h] [xbp-20h]
  __int64 v49; // [xsp+38h] [xbp-18h]
  int v50; // [xsp+40h] [xbp-10h] BYREF
  __int16 v51; // [xsp+44h] [xbp-Ch]
  __int64 v52; // [xsp+48h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50 = a4;
  v51 = WORD2(a4);
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    if ( a2 > 5u || !(*(_QWORD *)(a1 + 17296) + 96LL * a2) )
    {
      qdf_trace_msg(0x34u, 2u, "%s: session %d not found", v10, v11, v12, v13, v14, v15, v16, v17, "sme_handle_sae_msg");
      v31 = 16;
LABEL_12:
      qdf_mutex_release(a1 + 12848);
      result = v31;
      goto LABEL_13;
    }
    v18 = a2;
    if ( (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), a2) & 0xFFFFFFFD) == 1
      || *(_DWORD *)(a1 + 4LL * a2 + 17244) != 3 )
    {
      v33 = _qdf_mem_malloc(0x24u, "sme_handle_sae_msg", 15349);
      if ( v33 )
      {
        v34 = v33;
        *(_WORD *)(v33 + 4) = a2;
        *(_DWORD *)v33 = 2364560;
        *(_BYTE *)(v33 + 22) = a3;
        *(_DWORD *)(v33 + 32) = 513;
        qdf_mem_copy((void *)(v33 + 23), &v50, 6u);
        qdf_mem_set((void *)(v34 + 6), 0x10u, 0);
        if ( a5 )
          qdf_mem_copy((void *)(v34 + 6), a5, 0x10u);
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: SAE: sae_status %d vdev_id %d Peer: %02x:%02x:%02x:**:**:%02x",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "sme_handle_sae_msg",
          *(unsigned __int8 *)(v34 + 22),
          *(unsigned __int16 *)(v34 + 4),
          *(unsigned __int8 *)(v34 + 23),
          *(unsigned __int8 *)(v34 + 24),
          *(unsigned __int8 *)(v34 + 25),
          *(unsigned __int8 *)(v34 + 28),
          v44,
          v45,
          v46,
          v47,
          v48,
          v49);
        LOWORD(v44) = 5264;
        v45 = v34;
        v43 = scheduler_post_message_debug(
                0x34u,
                0x35u,
                53,
                (unsigned __int16 *)&v44,
                0x3C11u,
                (__int64)"sme_handle_sae_msg");
        if ( v43 )
        {
          v31 = v43;
          v32 = v34;
          goto LABEL_19;
        }
LABEL_21:
        v31 = 0;
        goto LABEL_12;
      }
    }
    else
    {
      v19 = _qdf_mem_malloc(0x20u, "sme_handle_sae_msg", 15395);
      if ( v19 )
      {
        v20 = v19;
        *(_DWORD *)v19 = v18;
        *(_DWORD *)(v19 + 4) = a3;
        v21 = v51;
        *(_DWORD *)(v19 + 8) = v50;
        *(_WORD *)(v19 + 12) = v21;
        qdf_mem_set((void *)(v19 + 14), 0x10u, 0);
        if ( a5 )
          qdf_mem_copy((void *)(v20 + 14), a5, 0x10u);
        LOWORD(v44) = 4267;
        v45 = v20;
        v22 = scheduler_post_message_debug(
                0x34u,
                0x36u,
                54,
                (unsigned __int16 *)&v44,
                0x3C37u,
                (__int64)"sme_handle_sae_msg");
        if ( v22 )
        {
          v31 = v22;
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: WMA_ROAM_PRE_AUTH_STATUS cmd posting failed",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "sme_handle_sae_msg");
          v32 = v20;
LABEL_19:
          _qdf_mem_free(v32);
          goto LABEL_12;
        }
        goto LABEL_21;
      }
    }
    v31 = 2;
    goto LABEL_12;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
