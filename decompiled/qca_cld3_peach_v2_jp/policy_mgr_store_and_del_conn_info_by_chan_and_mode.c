__int64 __fastcall policy_mgr_store_and_del_conn_info_by_chan_and_mode(
        __int64 a1,
        int a2,
        int a3,
        unsigned int *a4,
        unsigned __int8 *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int *v16; // x20
  __int64 comp_private_obj; // x0
  __int64 v20; // x22
  __int64 v21; // x0
  __int64 v22; // x1
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned __int8 v31; // w28
  unsigned int v32; // w26
  unsigned int v33; // w27
  __int64 v34; // x8
  unsigned __int64 v35; // x8
  char *v37; // x8
  unsigned int *v38; // x9
  __int64 v39; // x11
  __int64 v40; // x12
  unsigned int v41; // w10
  __int64 v42; // x24
  __int64 v43; // x8
  __int64 result; // x0
  const char *v45; // x2
  __int64 v49; // [xsp+0h] [xbp-10h]

  if ( !a4 || !a5 )
  {
    v45 = "%s: Invalid parameters";
    return qdf_trace_msg(
             0x4Fu,
             2u,
             v45,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             "policy_mgr_store_and_del_conn_info_by_chan_and_mode");
  }
  v16 = a4;
  *a5 = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
  {
    v45 = "%s: Invalid Context";
    return qdf_trace_msg(
             0x4Fu,
             2u,
             v45,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             "policy_mgr_store_and_del_conn_info_by_chan_and_mode");
  }
  v20 = comp_private_obj;
  v21 = qdf_mutex_acquire(comp_private_obj + 56);
  v31 = 0;
  v32 = 0;
  while ( 2 )
  {
    v33 = v32;
    v34 = 9LL * v32++;
    v35 = 4 * v34;
    while ( 1 )
    {
      if ( v35 - 152 < 0xFFFFFFFFFFFFFF4CLL )
        goto LABEL_22;
      if ( *((_BYTE *)&pm_conc_connection_list + v35 + 28) != 1 )
        goto LABEL_14;
      if ( v35 - 176 < 0xFFFFFFFFFFFFFF4CLL )
      {
LABEL_22:
        __break(1u);
        goto LABEL_23;
      }
      if ( *(_DWORD *)((char *)&pm_conc_connection_list + v35 + 4) == a2 )
      {
        if ( v35 > 0xB3 )
          goto LABEL_22;
        if ( *(_DWORD *)((char *)&pm_conc_connection_list + v35) == a3 )
          break;
      }
      _ZF = v32++ == 5;
      ++v33;
      v35 += 36LL;
      if ( _ZF )
        goto LABEL_14;
    }
    v37 = (char *)&pm_conc_connection_list + v35;
    v38 = &v16[9 * v31];
    *(_QWORD *)v38 = *(_QWORD *)v37;
    v40 = *((_QWORD *)v37 + 1);
    v39 = *((_QWORD *)v37 + 2);
    v41 = *((_DWORD *)v37 + 8);
    *((_QWORD *)v38 + 3) = *((_QWORD *)v37 + 3);
    v38[8] = v41;
    *((_QWORD *)v38 + 1) = v40;
    *((_QWORD *)v38 + 2) = v39;
    LODWORD(v49) = a2;
    v21 = qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: Stored %d (%d), deleted STA entry with vdev id %d, index %d ch %d",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "policy_mgr_store_and_del_conn_info_by_chan_and_mode",
            v49);
    ++v31;
    if ( v33 < 4 )
      continue;
    break;
  }
LABEL_14:
  if ( !v31 )
  {
LABEL_18:
    result = qdf_mutex_release(v20 + 56);
    *a5 = v31;
    return result;
  }
  v42 = v31;
  while ( 1 )
  {
    v21 = policy_mgr_decr_connection_count(a1, v16[6]);
    v43 = *v16;
    if ( (unsigned int)v43 > 0x11 )
      break;
    --v42;
    v16 += 9;
    --*(_BYTE *)(v20 + 989 + v43);
    if ( !v42 )
      goto LABEL_18;
  }
LABEL_23:
  __break(0x5512u);
  __asm { STR             P10, [X0,#0xB9,MUL VL] }
  return policy_mgr_restore_deleted_conn_info(v21, v22);
}
