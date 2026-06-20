__int64 __fastcall ucfg_tdls_update_config(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 comp_private_obj; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x19
  const char *v30; // x2
  __int64 result; // x0
  char v32; // w8
  int v33; // w10
  int v34; // w9
  int v35; // w13
  int v36; // w12
  int v37; // w13
  int v38; // w11
  int v39; // w11
  int v40; // w14
  int v41; // w11
  int v42; // w12
  int v43; // w12
  int v44; // w11
  _QWORD v45[3]; // [xsp+8h] [xbp-18h] BYREF

  v45[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0, 8u, "%s: tdls update config ", a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_tdls_update_config");
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: psoc: 0x%pK, req: 0x%pK",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_tdls_update_config",
      a1,
      a2);
LABEL_9:
    result = 16;
    goto LABEL_10;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xAu);
  if ( !comp_private_obj )
  {
    v30 = "%s: Failed to get tdls psoc component";
    goto LABEL_8;
  }
  v29 = comp_private_obj;
  *(_QWORD *)(comp_private_obj + 232) = *(_QWORD *)(a2 + 112);
  *(_QWORD *)(comp_private_obj + 240) = *(_QWORD *)(a2 + 120);
  *(_QWORD *)(comp_private_obj + 248) = *(_QWORD *)(a2 + 128);
  *(_QWORD *)(comp_private_obj + 256) = *(_QWORD *)(a2 + 136);
  *(_QWORD *)(comp_private_obj + 264) = *(_QWORD *)(a2 + 144);
  *(_QWORD *)(comp_private_obj + 272) = *(_QWORD *)(a2 + 152);
  *(_QWORD *)(comp_private_obj + 288) = *(_QWORD *)(a2 + 168);
  *(_QWORD *)(comp_private_obj + 280) = *(_QWORD *)(a2 + 160);
  *(_WORD *)(comp_private_obj + 332) = *(_WORD *)(a2 + 96);
  *(_WORD *)(comp_private_obj + 334) = *(_WORD *)(a2 + 98);
  *(_WORD *)(comp_private_obj + 336) = *(_WORD *)(a2 + 100);
  *(_WORD *)(comp_private_obj + 338) = *(_WORD *)(a2 + 102);
  *(_WORD *)(comp_private_obj + 340) = *(_WORD *)(a2 + 104);
  *(_DWORD *)(comp_private_obj + 344) = *(_DWORD *)(a2 + 108);
  *(_QWORD *)(comp_private_obj + 296) = *(_QWORD *)(a2 + 176);
  *(_QWORD *)(comp_private_obj + 584) = *(_QWORD *)(a2 + 184);
  *(_QWORD *)(comp_private_obj + 592) = *(_QWORD *)(a2 + 192);
  *(_QWORD *)(comp_private_obj + 600) = *(_QWORD *)(a2 + 200);
  *(_QWORD *)(comp_private_obj + 608) = *(_QWORD *)(a2 + 208);
  v45[0] = tdls_notify_increment_session;
  v45[1] = tdls_notify_decrement_session;
  if ( (unsigned int)policy_mgr_register_tdls_cb(a1, v45) )
  {
    v30 = "%s: policy manager callback registration failed ";
LABEL_8:
    qdf_trace_msg(0, 2u, v30, v21, v22, v23, v24, v25, v26, v27, v28, "ucfg_tdls_update_config");
    goto LABEL_9;
  }
  v32 = *(_BYTE *)(v29 + 186);
  v33 = 2;
  v34 = *(unsigned __int8 *)(v29 + 193);
  if ( *(_BYTE *)(v29 + 189) )
    v35 = 2;
  else
    v35 = 0;
  if ( *(_BYTE *)(v29 + 186) )
    v36 = 4;
  else
    v36 = 0;
  v37 = v35 | *(unsigned __int8 *)(v29 + 187);
  if ( *(_BYTE *)(v29 + 193) )
    v38 = 8;
  else
    v38 = 0;
  v39 = v36 | v38;
  if ( *(_BYTE *)(v29 + 192) )
    v40 = 16;
  else
    v40 = 0;
  v41 = v37 | v39 | v40 | (32 * (*(_BYTE *)(v29 + 194) != 0));
  if ( *(_BYTE *)(v29 + 191) )
    v42 = 64;
  else
    v42 = 0;
  v43 = v41 | v42;
  v44 = ((*(_BYTE *)(v29 + 190) & 3) << 7) | v43;
  *(_DWORD *)(v29 + 156) = v44;
  if ( (v43 & 0x40) != 0 )
  {
    if ( (v44 & 0x80) != 0 )
      v33 = 4;
    else
      v33 = 3;
  }
  *(_DWORD *)(v29 + 8) = v33;
  *(_DWORD *)(v29 + 12) = v33;
  if ( (v32 & 1) != 0 || v34 )
  {
    *(_WORD *)(v29 + 200) = 1;
  }
  else if ( !*(_WORD *)(v29 + 200) )
  {
    result = 0;
    goto LABEL_10;
  }
  *(_BYTE *)(v29 + 34) = -1;
  *(_WORD *)(v29 + 32) = 255;
  qdf_mem_set((void *)(v29 + 35), 6u, 0);
  result = 0;
  if ( *(unsigned __int16 *)(v29 + 200) > 1u )
  {
    *(_BYTE *)(v29 + 43) = -1;
    *(_WORD *)(v29 + 41) = 255;
    qdf_mem_set((void *)(v29 + 44), 6u, 0);
    result = 0;
    if ( *(unsigned __int16 *)(v29 + 200) >= 3u )
    {
      *(_BYTE *)(v29 + 52) = -1;
      *(_WORD *)(v29 + 50) = 255;
      qdf_mem_set((void *)(v29 + 53), 6u, 0);
      result = 0;
      if ( *(unsigned __int16 *)(v29 + 200) >= 4u )
      {
        *(_BYTE *)(v29 + 61) = -1;
        *(_WORD *)(v29 + 59) = 255;
        qdf_mem_set((void *)(v29 + 62), 6u, 0);
        result = 0;
        if ( *(unsigned __int16 *)(v29 + 200) >= 5u )
        {
          *(_BYTE *)(v29 + 70) = -1;
          *(_WORD *)(v29 + 68) = 255;
          qdf_mem_set((void *)(v29 + 71), 6u, 0);
          result = 0;
          if ( *(unsigned __int16 *)(v29 + 200) >= 6u )
          {
            *(_BYTE *)(v29 + 79) = -1;
            *(_WORD *)(v29 + 77) = 255;
            qdf_mem_set((void *)(v29 + 80), 6u, 0);
            result = 0;
            if ( *(unsigned __int16 *)(v29 + 200) >= 7u )
            {
              *(_BYTE *)(v29 + 88) = -1;
              *(_WORD *)(v29 + 86) = 255;
              qdf_mem_set((void *)(v29 + 89), 6u, 0);
              result = 0;
              if ( *(unsigned __int16 *)(v29 + 200) >= 8u )
              {
                *(_BYTE *)(v29 + 97) = -1;
                *(_WORD *)(v29 + 95) = 255;
                qdf_mem_set((void *)(v29 + 98), 6u, 0);
                result = 0;
                if ( *(unsigned __int16 *)(v29 + 200) > 8u )
                  __break(0x5512u);
              }
            }
          }
        }
      }
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
