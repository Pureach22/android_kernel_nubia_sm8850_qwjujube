_QWORD *__fastcall lim_update_fils_config(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  _QWORD *result; // x0
  unsigned __int8 *v14; // x22
  __int64 v15; // x21
  __int64 param; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  char v25; // w8
  unsigned int v26; // w8
  char v27; // w8
  unsigned int v28; // w4
  size_t v29; // x0
  void *v30; // x0
  size_t v31; // x2
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  size_t v40; // x0
  void *v41; // x0
  int v42; // w8
  __int64 v43; // x0
  __int64 v44; // [xsp+18h] [xbp-A8h]
  __int64 v45; // [xsp+20h] [xbp-A0h] BYREF
  __int64 v46; // [xsp+28h] [xbp-98h]
  __int64 v47; // [xsp+30h] [xbp-90h]
  __int64 v48; // [xsp+38h] [xbp-88h]
  __int64 v49; // [xsp+40h] [xbp-80h]
  __int64 v50; // [xsp+48h] [xbp-78h]
  __int64 v51; // [xsp+50h] [xbp-70h]
  __int64 v52; // [xsp+58h] [xbp-68h]
  __int64 v53; // [xsp+60h] [xbp-60h]
  __int64 v54; // [xsp+68h] [xbp-58h]
  __int64 v55; // [xsp+70h] [xbp-50h]
  __int64 v56; // [xsp+78h] [xbp-48h]
  __int64 v57; // [xsp+80h] [xbp-40h]
  __int64 v58; // [xsp+88h] [xbp-38h]
  __int64 v59; // [xsp+90h] [xbp-30h]
  __int64 v60; // [xsp+98h] [xbp-28h]
  __int64 v61; // [xsp+A0h] [xbp-20h]
  __int64 v62; // [xsp+A8h] [xbp-18h]
  __int64 v63; // [xsp+B0h] [xbp-10h]
  __int64 v64; // [xsp+B8h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a2 + 16);
  LOWORD(v63) = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  result = (_QWORD *)wlan_vdev_mlme_get_ext_hdl(v12, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v14 = (unsigned __int8 *)result[3010];
    if ( v14 )
    {
      v15 = *(_QWORD *)(a2 + 9976);
      if ( v15 )
      {
        if ( *v14 == 1 )
        {
          *(_BYTE *)v15 = 1;
          *(_BYTE *)(v15 + 16) = *((_DWORD *)v14 + 64);
          *(_BYTE *)(v15 + 48) = *((_DWORD *)v14 + 82);
          param = wlan_crypto_get_param(*(_QWORD *)(a2 + 16), 7u);
          if ( (param & 0x200000) != 0 )
          {
            v25 = 21;
          }
          else if ( (param & 0x100000) != 0 )
          {
            v25 = 20;
          }
          else if ( (param & 0x80000) != 0 )
          {
            v25 = 19;
          }
          else
          {
            v25 = 18;
          }
          *(_BYTE *)(v15 + 17) = v25;
          v26 = v14[661];
          if ( v26 >= 3 )
            v27 = -1;
          else
            v27 = v26 + 4;
          *(_BYTE *)(v15 + 18) = v27;
          *(_WORD *)(v15 + 68) = *((_DWORD *)v14 + 65);
          v28 = *((_DWORD *)v14 + 64);
          if ( v28 < 0xFE )
          {
            if ( !v28 )
              goto LABEL_20;
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Restricting the key_nai_length of %d to max %d",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              "lim_update_fils_config");
            *((_DWORD *)v14 + 64) = 253;
            v28 = 253;
          }
          result = (_QWORD *)_qdf_mem_malloc(v28, "lim_update_fils_config", 1992);
          *(_QWORD *)(v15 + 8) = result;
          if ( result )
          {
            qdf_mem_copy(result, v14 + 1, *((unsigned int *)v14 + 64));
LABEL_20:
            v29 = *((unsigned int *)v14 + 82);
            if ( (_DWORD)v29 )
            {
              v30 = (void *)_qdf_mem_malloc(v29, "lim_update_fils_config", 2003);
              *(_QWORD *)(v15 + 40) = v30;
              if ( !v30 )
              {
                v43 = *(_QWORD *)(v15 + 8);
                goto LABEL_34;
              }
              v31 = *((unsigned int *)v14 + 82);
              if ( (unsigned int)v31 <= 0x40 )
                qdf_mem_copy(v30, v14 + 264, v31);
            }
            qdf_mem_copy((void *)(v15 + 697), v14 + 727, 0x10u);
            *(_BYTE *)(v15 + 351) = **(_BYTE **)(a2 + 112);
            qdf_mem_copy(
              (void *)(v15 + 94),
              (const void *)(*(_QWORD *)(a2 + 112) + 2LL),
              **(unsigned __int16 **)(a2 + 112));
            if ( (unsigned int)dot11f_unpack_ie_rsn(a1, (char *)(v15 + 96), *(_BYTE *)(v15 + 351) - 2, &v45) )
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: FT-FILS: Invalid RSN IE",
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                "lim_update_fils_config");
            else
              *(_BYTE *)(v15 + 352) = BYTE4(v62) != 0;
            v40 = v14[726];
            *(_BYTE *)(v15 + 696) = v40;
            if ( !v40 )
            {
              v42 = 0;
              goto LABEL_31;
            }
            v41 = (void *)_qdf_mem_malloc(v40, "lim_update_fils_config", 2045);
            *(_QWORD *)(v15 + 688) = v41;
            if ( v41 )
            {
              qdf_mem_copy(v41, v14 + 662, v14[726]);
              v42 = v14[726];
LABEL_31:
              result = (_QWORD *)qdf_trace_msg(
                                   0x35u,
                                   8u,
                                   "%s: FILS: fils=%d nai-len=%d rrk_len=%d akm=%d auth=%d pmk_len=%d rsn_len:%d",
                                   v32,
                                   v33,
                                   v34,
                                   v35,
                                   v36,
                                   v37,
                                   v38,
                                   v39,
                                   "lim_update_fils_config",
                                   *v14,
                                   *((unsigned int *)v14 + 64),
                                   *((unsigned int *)v14 + 82),
                                   v14[660],
                                   v14[661],
                                   v42,
                                   *(unsigned __int8 *)(v15 + 351),
                                   v44,
                                   v45,
                                   v46,
                                   v47,
                                   v48,
                                   v49,
                                   v50,
                                   v51,
                                   v52,
                                   v53,
                                   v54,
                                   v55,
                                   v56,
                                   v57,
                                   v58,
                                   v59,
                                   v60,
                                   v61,
                                   v62,
                                   v63,
                                   v64);
              goto LABEL_35;
            }
            _qdf_mem_free(*(_QWORD *)(v15 + 8));
            v43 = *(_QWORD *)(v15 + 40);
LABEL_34:
            result = (_QWORD *)_qdf_mem_free(v43);
          }
        }
      }
    }
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
