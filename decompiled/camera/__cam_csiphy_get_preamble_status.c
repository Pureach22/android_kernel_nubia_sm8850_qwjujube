__int64 __fastcall _cam_csiphy_get_preamble_status(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x8
  __int64 v4; // x19
  __int64 v5; // x20
  int v6; // w21
  int v7; // w0
  __int64 v8; // x22
  int v9; // w0
  __int64 v10; // x20
  int v11; // w0
  _QWORD *v12; // x8
  int *v13; // x27
  __int64 v14; // x26
  __int64 v15; // x21
  __int64 v16; // x19
  __int64 v17; // x20
  int v18; // w22
  __int64 v19; // x23
  int v20; // w24
  __int64 v21; // x21
  int *v22; // x8
  _QWORD *v23; // x8
  __int64 v24; // x22
  __int64 v25; // x20
  __int64 v26; // x19
  int v27; // w21
  __int64 v28; // x20
  int *v29; // x8
  _QWORD *v30; // x8
  int v31; // w19
  int v32; // w22
  char v33; // w24
  unsigned int v34; // w21
  __int64 v35; // x9
  __int16 v36; // w23
  int v37; // w8
  __int64 v38; // x28
  int *v39; // x25
  int v40; // w20
  __int64 v41; // x27
  __int64 v42; // x26
  int v43; // w27
  __int16 v44; // w23
  int v45; // w0
  __int16 v46; // w23
  int v47; // w20
  int v48; // w0
  int v49; // w0
  int v50; // w0
  int v51; // w0
  __int64 v52; // x25
  __int64 v53; // x19
  const char *v54; // x5
  __int64 v55; // x4
  int v56; // w20
  int v57; // w19
  char v58; // w23
  unsigned int v59; // w21
  __int64 v60; // x9
  __int16 v61; // w27
  int v62; // w8
  int v63; // w28
  __int64 v64; // x26
  __int64 v65; // x25
  int v66; // w26
  __int16 v67; // w22
  int v68; // w27
  __int16 v69; // w22
  int v70; // w0
  __int16 v71; // w22
  int v72; // w22
  int v73; // w0
  int v74; // w0
  int v75; // w0
  int v76; // w0
  int v77; // w0
  __int64 v78; // x19
  const char *v79; // x5
  __int64 v80; // x4
  _QWORD *v81; // x8
  __int64 v82; // x19
  __int64 v83; // x20
  int v84; // w21
  int v85; // w0
  __int64 v86; // x22
  int v87; // w0
  unsigned int v88; // w8
  _QWORD *v89; // x8
  __int64 v90; // x20
  int v91; // w21
  int v92; // w0
  __int64 v93; // x22
  int v94; // w0
  __int64 v95; // x20
  int v96; // w0
  __int64 v97; // x19
  int v98; // w0
  int v100; // [xsp+Ch] [xbp-A4h]
  int v101; // [xsp+Ch] [xbp-A4h]
  _DWORD *v102; // [xsp+10h] [xbp-A0h]
  __int64 v103; // [xsp+10h] [xbp-A0h]
  int v104; // [xsp+1Ch] [xbp-94h]
  __int64 v106; // [xsp+28h] [xbp-88h]
  int v107; // [xsp+30h] [xbp-80h]
  __int64 v108; // [xsp+30h] [xbp-80h]
  __int64 v109; // [xsp+38h] [xbp-78h]
  __int64 v110; // [xsp+38h] [xbp-78h]
  __int64 v111; // [xsp+40h] [xbp-70h]
  __int64 v112; // [xsp+40h] [xbp-70h]
  __int64 v113; // [xsp+48h] [xbp-68h]
  __int64 v114; // [xsp+48h] [xbp-68h]

  if ( (unsigned int)a2 >= 3 )
  {
    __break(0x5512u);
    return cam_csiphy_cpas_ops(a1, a2);
  }
  else
  {
    if ( *(_DWORD *)(a1 + 104LL * (unsigned int)a2 + 624) )
    {
      v3 = *(_QWORD **)(a1 + 112);
      v4 = *(_QWORD *)(a1 + 1200);
      v5 = *(unsigned int *)(v3[6] + 8LL);
      v6 = *(_DWORD *)(*v3 + 24LL);
      v7 = cam_io_r(v4 + v5);
      cam_io_w_mb(v7 | 0x10u, v4 + v5);
      v8 = (unsigned int)(v6 + v5);
      v9 = cam_io_r(v4 + v8);
      cam_io_w_mb(v9 | 0x10u, v4 + v8);
      v10 = (unsigned int)(v5 + 2 * v6);
      v11 = cam_io_r(v4 + v10);
      cam_io_w_mb(v11 | 0x10u, v4 + v10);
      v12 = *(_QWORD **)(a1 + 112);
      v13 = (int *)&unk_393000;
      v14 = v12[6];
      v15 = *(_QWORD *)(v14 + 40);
      if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          (unsigned __int16)debug_mdl & 0x8000,
          4,
          "__cam_csiphy_get_3phase_pattern_status",
          2564,
          "ENTER");
        v12 = *(_QWORD **)(a1 + 112);
        v14 = v12[6];
      }
      v16 = *(_QWORD *)(a1 + 1200);
      v17 = *(unsigned int *)(v14 + 24);
      v18 = *(_DWORD *)(*v12 + 24LL);
      if ( (int)v15 < 1 )
      {
        v20 = 0;
      }
      else
      {
        v19 = 0;
        v20 = 0;
        v21 = v15 & 0x7FFFFFFF;
        do
        {
          v22 = (int *)(*(_QWORD *)(v14 + 80) + v19);
          if ( v22[3] == 32 )
            v20 |= cam_io_r(v16 + *v22);
          --v21;
          v19 += 16;
        }
        while ( v21 );
      }
      v102 = (_DWORD *)v14;
      v107 = v20;
      cam_io_r(v16 + v17);
      cam_io_r(v16 + (unsigned int)(v18 + v17));
      cam_io_r(v16 + (unsigned int)(v17 + 2 * v18));
      v30 = *(_QWORD **)(a1 + 112);
      v31 = *(_DWORD *)(v30[6] + 36LL);
      v114 = v30[6];
      if ( v31 <= 0 )
      {
        v34 = 0;
      }
      else
      {
        v32 = 0;
        v33 = 0;
        v34 = 0;
        v35 = *(unsigned int *)(*v30 + 24LL);
        v36 = debug_mdl;
        v37 = debug_priority;
        v38 = (unsigned int)(2 * v35);
        v109 = *(_QWORD *)(a1 + 1200);
        v111 = v35;
        do
        {
          v39 = v13;
          v40 = *(_DWORD *)(v114 + 28);
          v41 = (unsigned int)(v32 + v40);
          v42 = v109 + v41;
          if ( v36 < 0 && !v37 )
          {
            v49 = cam_io_r(v109 + v41);
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v36 & 0x8000,
              4,
              "__cam_csiphy_read_3phase_bist_counter_status",
              2538,
              "value to be read from addr: 0x%x is 0x%x",
              v41,
              v49);
          }
          v43 = cam_io_r(v42);
          v44 = debug_mdl;
          if ( (debug_mdl & 0x8000) != 0 && !v39[919] )
          {
            v50 = cam_io_r(v42 + v111);
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v44 & 0x8000,
              4,
              "__cam_csiphy_read_3phase_bist_counter_status",
              2538,
              "value to be read from addr: 0x%x is 0x%x",
              v111 + v32 + v40,
              v50);
          }
          v45 = cam_io_r(v42 + v111);
          v46 = debug_mdl;
          if ( (debug_mdl & 0x8000) != 0 && !v39[919] )
          {
            v100 = v45;
            v51 = cam_io_r(v42 + v38);
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v46 & 0x8000,
              4,
              "__cam_csiphy_read_3phase_bist_counter_status",
              2538,
              "value to be read from addr: 0x%x is 0x%x",
              v38 + v32 + v40,
              v51);
            v45 = v100;
          }
          v47 = v45 | v43;
          v48 = cam_io_r(v42 + v38);
          v13 = v39;
          v36 = debug_mdl;
          v37 = v39[919];
          v34 |= (v47 | v48) << v33;
          if ( (debug_mdl & 0x8000) != 0 && !v37 )
          {
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              (unsigned __int16)debug_mdl & 0x8000,
              4,
              "__cam_csiphy_read_3phase_bist_counter_status",
              2543,
              "COUNTER VALUE is 0x%x",
              v34);
            v36 = debug_mdl;
            v37 = v39[919];
          }
          --v31;
          v33 += 8;
          v32 += 4;
        }
        while ( v31 );
      }
      if ( (v107 & 1) != 0 )
      {
        v53 = a1;
        if ( (*v102 & v107) != 0 )
        {
          if ( v34 > 2 )
          {
            v54 = "PN9 Pattern is corrupted:: counter value: 0x%x Status1: 0x%x Status0: 0x%x";
            v55 = 2611;
          }
          else
          {
            v54 = "PN9 Pattern rxced succesfully after sensor streamoff:: counter value: 0x%x Status1: 0x%x Status0: 0x%x";
            v55 = 2607;
          }
        }
        else
        {
          v54 = "PN9 Pattern rxced succesfully before sensor streamoff:: counter value: 0x%x Status1: 0x%x Status0: 0x%x";
          v55 = 2622;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          0x8000,
          3,
          "__cam_csiphy_get_3phase_pattern_status",
          v55,
          v54,
          v34);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          0x8000,
          3,
          "__cam_csiphy_get_3phase_pattern_status",
          2626,
          "PN9 Pattern is corrupted:: counter value: 0x%x Status1: 0x%x Status0: 0x%x",
          v34);
        v53 = a1;
      }
      v81 = *(_QWORD **)(v53 + 112);
      v82 = *(_QWORD *)(v53 + 1200);
      v83 = *(unsigned int *)(v81[6] + 8LL);
      v84 = *(_DWORD *)(*v81 + 24LL);
      v85 = cam_io_r(v82 + v83);
      cam_io_w_mb(v85 & 0xFFFFFFEF, v82 + v83);
      v86 = (unsigned int)(v84 + v83);
      v87 = cam_io_r(v82 + v86);
      cam_io_w_mb(v87 & 0xFFFFFFEF, v82 + v86);
      v88 = v83 + 2 * v84;
    }
    else
    {
      _cam_csiphy_2ph_status_checker_ops(a1, 1);
      v23 = *(_QWORD **)(a1 + 112);
      v24 = v23[6];
      v25 = *(_QWORD *)(v24 + 40);
      if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          (unsigned __int16)debug_mdl & 0x8000,
          4,
          "__cam_csiphy_get_2phase_pattern_status",
          2430,
          "ENTER");
        v23 = *(_QWORD **)(a1 + 112);
        v24 = v23[6];
      }
      v113 = *(_QWORD *)(a1 + 1200);
      if ( (int)v25 < 1 )
      {
        v27 = 0;
        v52 = v24;
      }
      else
      {
        v26 = 0;
        v27 = 0;
        v28 = v25 & 0x7FFFFFFF;
        do
        {
          v29 = (int *)(*(_QWORD *)(v24 + 80) + v26);
          if ( v29[3] == 16 )
            v27 |= cam_io_r(v113 + *v29);
          --v28;
          v26 += 16;
        }
        while ( v28 );
        v23 = *(_QWORD **)(a1 + 112);
        v52 = v23[6];
        v113 = *(_QWORD *)(a1 + 1200);
      }
      v56 = *(_DWORD *)(v52 + 36);
      v103 = v24;
      v104 = v27;
      if ( v56 < 1 )
      {
        v59 = 0;
      }
      else
      {
        v57 = 0;
        v58 = 0;
        v59 = 0;
        v106 = v52;
        v60 = *(unsigned int *)(*v23 + 24LL);
        v61 = debug_mdl;
        v62 = debug_priority;
        v110 = (unsigned int)(2 * v60);
        v112 = v60;
        v108 = (unsigned int)(3 * v60);
        do
        {
          v63 = *(_DWORD *)(v52 + 32);
          v64 = (unsigned int)(v57 + v63);
          v65 = v113 + v64;
          if ( v61 < 0 && !v62 )
          {
            v74 = cam_io_r(v113 + v64);
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v61 & 0x8000,
              4,
              "__cam_csiphy_read_2phase_bist_counter_status",
              2409,
              "value to be read from addr: 0x%x is 0x%x",
              v64,
              v74);
          }
          v66 = cam_io_r(v65);
          v67 = debug_mdl;
          if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
          {
            v75 = cam_io_r(v65 + v112);
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v67 & 0x8000,
              4,
              "__cam_csiphy_read_2phase_bist_counter_status",
              2409,
              "value to be read from addr: 0x%x is 0x%x",
              v112 + v57 + v63,
              v75);
          }
          v68 = cam_io_r(v65 + v112);
          v69 = debug_mdl;
          if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
          {
            v76 = cam_io_r(v65 + v110);
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v69 & 0x8000,
              4,
              "__cam_csiphy_read_2phase_bist_counter_status",
              2409,
              "value to be read from addr: 0x%x is 0x%x",
              v110 + v57 + v63,
              v76);
          }
          v70 = cam_io_r(v65 + v110);
          v71 = debug_mdl;
          if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
          {
            v101 = v70;
            v77 = cam_io_r(v65 + v108);
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v71 & 0x8000,
              4,
              "__cam_csiphy_read_2phase_bist_counter_status",
              2409,
              "value to be read from addr: 0x%x is 0x%x",
              v108 + v57 + v63,
              v77);
            v70 = v101;
          }
          v72 = v68 | v66 | v70;
          v73 = cam_io_r(v65 + v108);
          v61 = debug_mdl;
          v62 = debug_priority;
          v59 |= (v72 | v73) << v58;
          if ( (debug_mdl & 0x8000) != 0 )
          {
            v52 = v106;
            if ( !debug_priority )
            {
              ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                (unsigned __int16)debug_mdl & 0x8000,
                4,
                "__cam_csiphy_read_2phase_bist_counter_status",
                2413,
                "COUNTER VALUE is 0x%x",
                v59);
              v61 = debug_mdl;
              v62 = debug_priority;
            }
          }
          else
          {
            v52 = v106;
          }
          --v56;
          v58 += 8;
          v57 += 4;
        }
        while ( v56 );
      }
      if ( (v104 & 1) != 0 )
      {
        v78 = a1;
        if ( (*(_DWORD *)(v103 + 4) & v104) != 0 )
        {
          if ( v59 > 2 )
          {
            v79 = "PN9 Pattern is corrupted:: counter value: 0x%x, Status0: 0x%x";
            v80 = 2467;
          }
          else
          {
            v79 = "PN9 Pattern rxced succesfully:: counter value: 0x%x, Status0: 0x%x";
            v80 = 2463;
          }
        }
        else
        {
          v79 = "PN9 Pattern rxced succesfully:: counter value: 0x%x, Status0: 0x%x";
          v80 = 2478;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          0x8000,
          3,
          "__cam_csiphy_get_2phase_pattern_status",
          v80,
          v79,
          v59);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          0x8000,
          3,
          "__cam_csiphy_get_2phase_pattern_status",
          2482,
          "PN9 Pattern is corrupted:: counter value: 0x%x Status0: 0x%x",
          v59);
        v78 = a1;
      }
      v89 = *(_QWORD **)(v78 + 112);
      v82 = *(_QWORD *)(v78 + 1200);
      v90 = *(unsigned int *)(v89[6] + 12LL);
      v91 = *(_DWORD *)(*v89 + 24LL);
      v92 = cam_io_r(v82 + v90);
      cam_io_w_mb(v92 & 0xFFFFFFEF, v82 + v90);
      v93 = (unsigned int)(v91 + v90);
      v94 = cam_io_r(v82 + v93);
      cam_io_w_mb(v94 & 0xFFFFFFEF, v82 + v93);
      v95 = (unsigned int)(v90 + 2 * v91);
      v96 = cam_io_r(v82 + v95);
      cam_io_w_mb(v96 & 0xFFFFFFEF, v82 + v95);
      v88 = v95 + v91;
    }
    v97 = v82 + v88;
    v98 = cam_io_r(v97);
    return cam_io_w_mb(v98 & 0xFFFFFFEF, v97);
  }
}
