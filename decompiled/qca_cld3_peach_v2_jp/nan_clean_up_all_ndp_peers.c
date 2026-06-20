__int64 __fastcall nan_clean_up_all_ndp_peers(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  _DWORD *v21; // x10
  unsigned __int64 v22; // x1
  _DWORD *v23; // x10
  unsigned __int64 v24; // x1
  _DWORD *v25; // x10
  unsigned __int64 v26; // x1
  _DWORD *v27; // x10
  unsigned __int64 v28; // x1
  _DWORD *v29; // x10
  unsigned __int64 v30; // x1
  _DWORD *v31; // x10
  unsigned __int64 v32; // x1
  _DWORD *v33; // x10
  unsigned __int64 v34; // x1
  _DWORD *v35; // x10
  unsigned __int64 v36; // x1
  _DWORD *v37; // x10
  unsigned __int64 v38; // x1

  if ( !a1 )
    goto LABEL_32;
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !result )
    return qdf_trace_msg(
             0x53u,
             2u,
             "%s: NAN PSOC priv obj is null",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "nan_clean_up_all_ndp_peers");
  v20 = result;
  if ( *(_BYTE *)(result + 382) )
  {
    v21 = *(_DWORD **)(result + 128);
    v22 = *(unsigned int *)(result + 334) | ((unsigned __int64)*(unsigned __int16 *)(result + 338) << 32);
    if ( *(v21 - 1) != 1536790594 )
      __break(0x822Au);
    result = ((__int64 (__fastcall *)(_QWORD, unsigned __int64))v21)(a2, v22);
    if ( *(unsigned __int8 *)(v20 + 382) > 1u )
    {
      v23 = *(_DWORD **)(v20 + 128);
      v24 = *(unsigned int *)(v20 + 340) | ((unsigned __int64)*(unsigned __int16 *)(v20 + 344) << 32);
      if ( *(v23 - 1) != 1536790594 )
        __break(0x822Au);
      result = ((__int64 (__fastcall *)(_QWORD, unsigned __int64))v23)(a2, v24);
      if ( *(unsigned __int8 *)(v20 + 382) >= 3u )
      {
        v25 = *(_DWORD **)(v20 + 128);
        v26 = *(unsigned int *)(v20 + 346) | ((unsigned __int64)*(unsigned __int16 *)(v20 + 350) << 32);
        if ( *(v25 - 1) != 1536790594 )
          __break(0x822Au);
        result = ((__int64 (__fastcall *)(_QWORD, unsigned __int64))v25)(a2, v26);
        if ( *(unsigned __int8 *)(v20 + 382) >= 4u )
        {
          v27 = *(_DWORD **)(v20 + 128);
          v28 = *(unsigned int *)(v20 + 352) | ((unsigned __int64)*(unsigned __int16 *)(v20 + 356) << 32);
          if ( *(v27 - 1) != 1536790594 )
            __break(0x822Au);
          result = ((__int64 (__fastcall *)(_QWORD, unsigned __int64))v27)(a2, v28);
          if ( *(unsigned __int8 *)(v20 + 382) >= 5u )
          {
            v29 = *(_DWORD **)(v20 + 128);
            v30 = *(unsigned int *)(v20 + 358) | ((unsigned __int64)*(unsigned __int16 *)(v20 + 362) << 32);
            if ( *(v29 - 1) != 1536790594 )
              __break(0x822Au);
            result = ((__int64 (__fastcall *)(_QWORD, unsigned __int64))v29)(a2, v30);
            if ( *(unsigned __int8 *)(v20 + 382) >= 6u )
            {
              v31 = *(_DWORD **)(v20 + 128);
              v32 = *(unsigned int *)(v20 + 364) | ((unsigned __int64)*(unsigned __int16 *)(v20 + 368) << 32);
              if ( *(v31 - 1) != 1536790594 )
                __break(0x822Au);
              result = ((__int64 (__fastcall *)(_QWORD, unsigned __int64))v31)(a2, v32);
              if ( *(unsigned __int8 *)(v20 + 382) >= 7u )
              {
                v33 = *(_DWORD **)(v20 + 128);
                v34 = *(unsigned int *)(v20 + 370) | ((unsigned __int64)*(unsigned __int16 *)(v20 + 374) << 32);
                if ( *(v33 - 1) != 1536790594 )
                  __break(0x822Au);
                result = ((__int64 (__fastcall *)(_QWORD, unsigned __int64))v33)(a2, v34);
                if ( *(unsigned __int8 *)(v20 + 382) >= 8u )
                {
                  v35 = *(_DWORD **)(v20 + 128);
                  v36 = *(unsigned int *)(v20 + 376) | ((unsigned __int64)*(unsigned __int16 *)(v20 + 380) << 32);
                  if ( *(v35 - 1) != 1536790594 )
                    __break(0x822Au);
                  result = ((__int64 (__fastcall *)(_QWORD, unsigned __int64))v35)(a2, v36);
                  if ( *(unsigned __int8 *)(v20 + 382) >= 9u )
                  {
                    v37 = *(_DWORD **)(v20 + 128);
                    v38 = *(unsigned int *)(v20 + 382) | ((unsigned __int64)*(unsigned __int16 *)(v20 + 386) << 32);
                    if ( *(v37 - 1) != 1536790594 )
                      __break(0x822Au);
                    result = ((__int64 (__fastcall *)(_QWORD, unsigned __int64))v37)(a2, v38);
                    if ( *(unsigned __int8 *)(v20 + 382) > 9u )
                    {
                      __break(0x5512u);
LABEL_32:
                      qdf_trace_msg(
                        0x53u,
                        2u,
                        "%s: psoc is null",
                        a3,
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10,
                        "nan_get_psoc_priv_obj");
                      return qdf_trace_msg(
                               0x53u,
                               2u,
                               "%s: NAN PSOC priv obj is null",
                               v12,
                               v13,
                               v14,
                               v15,
                               v16,
                               v17,
                               v18,
                               v19,
                               "nan_clean_up_all_ndp_peers");
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
