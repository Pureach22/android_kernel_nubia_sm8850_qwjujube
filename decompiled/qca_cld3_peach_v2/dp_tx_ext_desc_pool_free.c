_QWORD *__fastcall dp_tx_ext_desc_pool_free(
        _QWORD *result,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x21
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x21
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x21
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x21
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 v97; // x21
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  __int64 v114; // x21
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7

  if ( a2 )
  {
    v11 = result[526];
    v12 = (__int64)result;
    dp_desc_multi_pages_mem_free((__int64)result, 4u, (_BYTE *)result + 4144, 0, 1, a3, a4, a5, a6, a7, a8, a9, a10);
    result = dp_desc_multi_pages_mem_free(
               v12,
               3u,
               (_BYTE *)(v12 + 4096),
               v11,
               0,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20);
    if ( a2 != 1 )
    {
      v29 = *(_QWORD *)(v12 + 4344);
      dp_desc_multi_pages_mem_free(v12, 4u, (_BYTE *)(v12 + 4280), 0, 1, v21, v22, v23, v24, v25, v26, v27, v28);
      result = dp_desc_multi_pages_mem_free(
                 v12,
                 3u,
                 (_BYTE *)(v12 + 4232),
                 v29,
                 0,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 v37);
      if ( a2 != 2 )
      {
        v46 = *(_QWORD *)(v12 + 4480);
        dp_desc_multi_pages_mem_free(v12, 4u, (_BYTE *)(v12 + 4416), 0, 1, v38, v39, v40, v41, v42, v43, v44, v45);
        result = dp_desc_multi_pages_mem_free(
                   v12,
                   3u,
                   (_BYTE *)(v12 + 4368),
                   v46,
                   0,
                   v47,
                   v48,
                   v49,
                   v50,
                   v51,
                   v52,
                   v53,
                   v54);
        if ( a2 != 3 )
        {
          v63 = *(_QWORD *)(v12 + 4616);
          dp_desc_multi_pages_mem_free(v12, 4u, (_BYTE *)(v12 + 4552), 0, 1, v55, v56, v57, v58, v59, v60, v61, v62);
          result = dp_desc_multi_pages_mem_free(
                     v12,
                     3u,
                     (_BYTE *)(v12 + 4504),
                     v63,
                     0,
                     v64,
                     v65,
                     v66,
                     v67,
                     v68,
                     v69,
                     v70,
                     v71);
          if ( a2 != 4 )
          {
            v80 = *(_QWORD *)(v12 + 4752);
            dp_desc_multi_pages_mem_free(v12, 4u, (_BYTE *)(v12 + 4688), 0, 1, v72, v73, v74, v75, v76, v77, v78, v79);
            result = dp_desc_multi_pages_mem_free(
                       v12,
                       3u,
                       (_BYTE *)(v12 + 4640),
                       v80,
                       0,
                       v81,
                       v82,
                       v83,
                       v84,
                       v85,
                       v86,
                       v87,
                       v88);
            if ( a2 != 5 )
            {
              v97 = *(_QWORD *)(v12 + 4888);
              dp_desc_multi_pages_mem_free(v12, 4u, (_BYTE *)(v12 + 4824), 0, 1, v89, v90, v91, v92, v93, v94, v95, v96);
              result = dp_desc_multi_pages_mem_free(
                         v12,
                         3u,
                         (_BYTE *)(v12 + 4776),
                         v97,
                         0,
                         v98,
                         v99,
                         v100,
                         v101,
                         v102,
                         v103,
                         v104,
                         v105);
              if ( a2 != 6 )
              {
                v114 = *(_QWORD *)(v12 + 5024);
                dp_desc_multi_pages_mem_free(
                  v12,
                  4u,
                  (_BYTE *)(v12 + 4960),
                  0,
                  1,
                  v106,
                  v107,
                  v108,
                  v109,
                  v110,
                  v111,
                  v112,
                  v113);
                result = dp_desc_multi_pages_mem_free(
                           v12,
                           3u,
                           (_BYTE *)(v12 + 4912),
                           v114,
                           0,
                           v115,
                           v116,
                           v117,
                           v118,
                           v119,
                           v120,
                           v121,
                           v122);
                if ( a2 != 7 )
                {
                  __break(0x5512u);
                  JUMPOUT(0x5A43C48);
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
