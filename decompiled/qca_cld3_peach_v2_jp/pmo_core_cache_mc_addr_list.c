__int64 __fastcall pmo_core_cache_mc_addr_list(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x20
  unsigned int v13; // w0
  __int64 v14; // x8
  __int64 comp_private_obj; // x0
  __int64 v16; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v18; // x8
  __int64 v19; // x27
  unsigned int v20; // w22
  unsigned __int8 *v21; // x23
  unsigned __int64 v22; // x25
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x7
  int v26; // w8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned __int8 *v35; // x28
  __int64 v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x4
  __int64 v46; // x5
  __int64 v47; // x6
  __int64 v48; // x7
  __int64 v49; // x8
  const char *v50; // x2
  __int64 result; // x0
  unsigned int v52; // w19
  __int64 v53; // [xsp+0h] [xbp-20h]
  _BYTE v54[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v55; // [xsp+18h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  if ( !v10 )
  {
LABEL_41:
    v50 = "%s: psoc is NULL";
LABEL_43:
    qdf_trace_msg(0x4Du, 2u, v50, a2, a3, a4, a5, a6, a7, a8, a9, "pmo_core_cache_mc_addr_list");
    result = 29;
    goto LABEL_46;
  }
  v11 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          v10,
          *((unsigned __int8 *)a1 + 8),
          10);
  if ( !v11 )
  {
    v50 = "%s: vdev is NULL";
    goto LABEL_43;
  }
  v12 = v11;
  v13 = pmo_core_mc_addr_flitering_sanity();
  if ( !v13 )
  {
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: Cache mc addr list for vdev id: %d psoc: %pK",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "pmo_core_cache_mc_addr_list",
      *((unsigned __int8 *)a1 + 8),
      *a1);
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v12, 4u);
    v16 = comp_private_obj;
    v54[0] = *(_BYTE *)(comp_private_obj + 866);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1056);
      v18 = *(_QWORD *)(v16 + 1064);
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      v18 = *(_QWORD *)(v16 + 1064) | 1LL;
      *(_QWORD *)(v16 + 1064) = v18;
    }
    *(_BYTE *)(v16 + 673) = *((_DWORD *)a1 + 3);
    if ( (v18 & 1) != 0 )
    {
      *(_QWORD *)(v16 + 1064) = v18 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v16 + 1056);
    }
    else
    {
      raw_spin_unlock(v16 + 1056);
    }
    v14 = *((unsigned int *)a1 + 3);
    if ( (int)v14 >= 1 )
    {
      v19 = 0;
      v20 = 0;
      v21 = (unsigned __int8 *)(a1 + 2);
      v22 = _ReadStatusReg(SP_EL0);
      do
      {
        if ( v19 == 32 )
        {
LABEL_40:
          __break(0x5512u);
          goto LABEL_41;
        }
        if ( !(unsigned int)qdf_mem_cmp(v21, &pmo_core_fill_mc_list_ipv6_rs, 6u)
          || v54[0] && !(unsigned int)qdf_mem_cmp(v21, v54, 1u) )
        {
          if ( v21 )
          {
            v45 = *v21;
            v46 = v21[1];
            v47 = v21[2];
            v48 = v21[5];
          }
          else
          {
            v47 = 0;
            v45 = 0;
            v46 = 0;
            v48 = 0;
          }
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: MC/BC filtering Skip addr %02x:%02x:%02x:**:**:%02x",
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            "pmo_core_fill_mc_list",
            v45,
            v46,
            v47,
            v48);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v22 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v16 + 1056);
            v49 = *(_QWORD *)(v16 + 1064);
          }
          else
          {
            raw_spin_lock_bh(v16 + 1056);
            v49 = *(_QWORD *)(v16 + 1064) | 1LL;
            *(_QWORD *)(v16 + 1064) = v49;
          }
          --*(_BYTE *)(v16 + 673);
          if ( (v49 & 1) != 0 )
          {
            *(_QWORD *)(v16 + 1064) = v49 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v16 + 1056);
          }
          else
          {
            raw_spin_unlock(v16 + 1056);
          }
          goto LABEL_14;
        }
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v22 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v22 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v16 + 1056);
          if ( v20 > 0x1F )
            goto LABEL_40;
        }
        else
        {
          raw_spin_lock_bh(v16 + 1056);
          *(_QWORD *)(v16 + 1064) |= 1uLL;
          if ( v20 > 0x1F )
            goto LABEL_40;
        }
        v35 = (unsigned __int8 *)(v16 + 674 + 6LL * v20);
        qdf_mem_set(v35, 6u, 0);
        qdf_mem_copy(v35, v21, 6u);
        v36 = *(_QWORD *)(v16 + 1064);
        if ( (v36 & 1) != 0 )
        {
          *(_QWORD *)(v16 + 1064) = v36 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v16 + 1056);
          if ( !v35 )
          {
LABEL_25:
            v25 = 0;
            v23 = 0;
            v24 = 0;
            v26 = 0;
            goto LABEL_13;
          }
        }
        else
        {
          raw_spin_unlock(v16 + 1056);
          if ( !v35 )
            goto LABEL_25;
        }
        v23 = *v35;
        v24 = v35[1];
        v25 = v35[2];
        v26 = v35[5];
LABEL_13:
        LODWORD(v53) = v26;
        qdf_trace_msg(
          0x4Du,
          8u,
          "%s: Index = %d, mac[%02x:%02x:%02x:**:**:%02x]",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "pmo_core_fill_mc_list",
          v20++,
          v23,
          v24,
          v25,
          v53);
LABEL_14:
        v14 = *((int *)a1 + 3);
        ++v19;
        v21 += 6;
      }
      while ( v19 < v14 );
    }
    v13 = 0;
  }
  v52 = v13;
  wlan_objmgr_vdev_release_ref(v12, 0xAu, (unsigned int *)v14, a2, a3, a4, a5, a6, a7, a8, a9);
  result = v52;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
