__int64 __fastcall dp_set_vlan_groupkey(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int16 a3,
        unsigned __int16 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w24
  unsigned __int64 StatusReg; // x8
  __int64 v18; // x22
  unsigned int v19; // w8
  unsigned int v26; // w10
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int64 v43; // x8
  void *v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w23
  __int64 v54; // x8
  unsigned int v58; // w9
  __int64 v59; // x8

  v12 = a2;
  if ( a2 <= 5u )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 18928);
    }
    else
    {
      raw_spin_lock_bh(a1 + 18928);
      *(_QWORD *)(a1 + 18936) |= 1uLL;
    }
    v18 = *(_QWORD *)(a1 + 8LL * a2 + 12912);
    if ( v18 )
    {
      v19 = *(_DWORD *)(v18 + 42560);
      do
      {
        if ( !v19 )
          goto LABEL_24;
        _X12 = (unsigned int *)(v18 + 42560);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v26 = __ldxr(_X12);
          if ( v26 != v19 )
            break;
          if ( !__stlxr(v19 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v26 == v19;
        v19 = v26;
      }
      while ( !_ZF );
      _X8 = (unsigned int *)(v18 + 42600);
      __asm { PRFM            #0x11, [X8] }
      do
        v58 = __ldxr(_X8);
      while ( __stxr(v58 + 1, _X8) );
      v59 = *(_QWORD *)(a1 + 18936);
      if ( (v59 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 18936) = v59 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 18928);
      }
      else
      {
        raw_spin_unlock(a1 + 18928);
      }
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Try: vdev_id %d, vdev %pK, multipass_en %d, vlan_id %d, group_key %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "dp_set_vlan_groupkey",
        a2,
        v18,
        *(unsigned __int8 *)(v18 + 80),
        a3,
        a4);
      v43 = *(unsigned __int8 *)(v18 + 80);
      if ( (_DWORD)v43 != 1 )
        goto LABEL_23;
      if ( !*(_QWORD *)(v18 + 42464) )
      {
        v44 = (void *)_qdf_mem_malloc(0x2000u, "dp_set_vlan_groupkey", 16650);
        *(_QWORD *)(v18 + 42464) = v44;
        if ( !v44 )
        {
          v53 = 2;
          qdf_trace_msg(0x45u, 2u, "%s: iv_vlan_map", v45, v46, v47, v48, v49, v50, v51, v52, "dp_set_vlan_groupkey");
          goto LABEL_29;
        }
        qdf_mem_set(v44, 0x2000u, 0);
      }
      v43 = a3;
      if ( a3 <= 0xFFFu )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Successful setting: vdev_id %d, vlan_id %d, group_key %d",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "dp_set_vlan_groupkey",
          a2,
          a3,
          a4);
        v43 = *(_QWORD *)(v18 + 42464);
        v53 = 0;
        *(_WORD *)(v43 + 2LL * a3) = a4;
      }
      else
      {
LABEL_23:
        v53 = 4;
      }
LABEL_29:
      dp_vdev_unref_delete(a1, v18, 9u, (unsigned int *)v43, v35, v36, v37, v38, v39, v40, v41, v42);
      return v53;
    }
LABEL_24:
    v54 = *(_QWORD *)(a1 + 18936);
    if ( (v54 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v54 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
    }
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Try: vdev_id %d, vdev %pK, multipass_en %d, vlan_id %d, group_key %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "dp_set_vlan_groupkey",
    v12,
    0,
    0,
    a3,
    a4);
  return 4;
}
