_WORD *__fastcall lim_post_csa_ocv_sa_query_check(_WORD *result, __int64 a2, char a3)
{
  __int64 v4; // x20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x0
  __int64 v15; // x21
  __int16 param; // w22
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  char v34; // w24
  int v35; // w21
  int v36; // w8
  const char *v37; // x2
  const char *v38; // x2
  unsigned int v39; // w1

  if ( a2 && *(_BYTE *)(a2 + 70) && *(_DWORD *)(a2 + 88) == 1 )
  {
    v4 = (__int64)result;
    result = (_WORD *)qdf_mc_timer_get_current_state(a2 + 9800);
    if ( (_DWORD)result == 21 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Post CSA OCV Sa Query timer already started",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "lim_post_csa_ocv_sa_query_check");
      result = (_WORD *)qdf_mc_timer_stop(a2 + 9800);
    }
    if ( (a3 & 1) != 0 )
    {
      if ( *(_BYTE *)(a2 + 70) && *(_DWORD *)(a2 + 88) == 1 )
      {
        v14 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                *(_QWORD *)(*(_QWORD *)(a2 + 8608) + 21624LL),
                *(unsigned __int8 *)(a2 + 10),
                7);
        if ( v14 )
        {
          v15 = v14;
          param = wlan_crypto_get_param(v14, 5u);
          result = (_WORD *)wlan_objmgr_vdev_release_ref(v15, 7u, v17, v18, v19, v20, v21, v22, v23, v24, v25);
          if ( (param & 0x4000) != 0 )
          {
            if ( !*(_WORD *)(a2 + 376) )
              return result;
            v34 = 0;
            v35 = 0;
            do
            {
              while ( 1 )
              {
                result = (_WORD *)dph_get_hash_entry(v4, v35, a2 + 360);
                if ( !result )
                  break;
                v36 = (unsigned __int16)*result;
                *result = v36 & 0xEFFF;
                if ( (~v36 & 0xC00) != 0 )
                  break;
                ++v35;
                v34 = 1;
                *result = v36 | 0x1000;
                if ( *(unsigned __int16 *)(a2 + 376) <= (unsigned int)(unsigned __int16)v35 )
                  goto LABEL_26;
              }
              ++v35;
            }
            while ( *(unsigned __int16 *)(a2 + 376) > (unsigned int)(unsigned __int16)v35 );
            if ( (v34 & 1) == 0 )
              return result;
LABEL_26:
            if ( (unsigned int)qdf_mc_timer_start(a2 + 9800, 0x3A98u) )
            {
              v38 = "%s: cannot start post csa ocv sa query timer";
              v39 = 2;
              return (_WORD *)qdf_trace_msg(
                                0x35u,
                                v39,
                                v38,
                                v26,
                                v27,
                                v28,
                                v29,
                                v30,
                                v31,
                                v32,
                                v33,
                                "lim_post_csa_ocv_sa_query_check");
            }
            v38 = "%s: Post CSA OCV SA Query waiting timer started";
LABEL_21:
            v39 = 8;
            return (_WORD *)qdf_trace_msg(
                              0x35u,
                              v39,
                              v38,
                              v26,
                              v27,
                              v28,
                              v29,
                              v30,
                              v31,
                              v32,
                              v33,
                              "lim_post_csa_ocv_sa_query_check");
          }
LABEL_20:
          v38 = "%s: AP OCV caps not enabled,do not start post CSA timer";
          goto LABEL_21;
        }
        v37 = "%s: Vdev is NULL";
      }
      else
      {
        v37 = "%s: Session is not valid";
      }
      qdf_trace_msg(0x35u, 2u, v37, v6, v7, v8, v9, v10, v11, v12, v13, "lim_get_ap_ocv_cap");
      goto LABEL_20;
    }
  }
  return result;
}
