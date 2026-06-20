__int64 __fastcall reg_program_mas_chan_list(
        __int64 a1,
        char *a2,
        const void *a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 psoc_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _DWORD *v25; // x22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  char *v35; // x10
  int v36; // w11
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  const char *v45; // x2
  __int64 result; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  int v55; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v56; // [xsp+8h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  psoc_obj = reg_get_psoc_obj(a1, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( psoc_obj )
  {
    v25 = (_DWORD *)psoc_obj;
    qdf_mem_copy((void *)(psoc_obj + 91099), a3, 2u);
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: set cur_country %.2s",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "reg_program_mas_chan_list",
      (char *)v25 + 91099);
    v34 = 0;
    v35 = a2;
    do
    {
      v35[4] = *(_BYTE *)(channel_map + v34 + 4);
      v36 = *(_DWORD *)(channel_map + v34);
      v34 += 12;
      v35[25] = 0;
      *(_DWORD *)v35 = v36;
      v35 += 36;
    }
    while ( v34 != 1224 );
    qdf_mem_copy(v25 + 2, a2, 0xE58u);
    *v25 = a4;
    qdf_mem_copy(v25 + 7593, a2, 0xE58u);
    v25[7591] = a4;
    qdf_mem_copy(v25 + 15184, a2, 0xE58u);
    v25[15182] = a4;
    v55 = 1;
    if ( !(unsigned int)wlan_objmgr_psoc_try_get_ref(a1, 0x15u, v37, v38, v39, v40, v41, v42, v43, v44) )
    {
      wlan_objmgr_iterate_obj_list(a1, 1, reg_propagate_mas_chan_list_to_pdev, (__int64)&v55, 1, 0x15u);
      result = wlan_objmgr_psoc_release_ref(a1, 0x15u, v47, v48, v49, v50, v51, v52, v53, v54);
      goto LABEL_9;
    }
    v45 = "%s: error taking psoc ref cnt";
  }
  else
  {
    v45 = "%s: reg psoc private obj is NULL";
  }
  result = qdf_trace_msg(0x51u, 2u, v45, v17, v18, v19, v20, v21, v22, v23, v24, "reg_program_mas_chan_list");
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
