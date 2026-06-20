__int64 __fastcall pmo_core_del_wow_user_pattern(
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
  unsigned int ref; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 comp_private_obj; // x0
  __int64 v22; // x22
  __int64 v23; // x20
  bool v24; // zf
  char StatusReg; // w8
  unsigned __int64 v26; // x8
  __int64 v27; // x8
  int v28; // w22
  __int64 v29; // x0
  unsigned __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x22
  char v34; // w8
  unsigned __int64 v35; // x8
  __int64 v36; // x8
  unsigned int v37; // w22
  __int64 v38; // x0
  __int64 v39; // x21
  char v40; // w8
  unsigned __int64 v41; // x8
  __int64 v42; // x8
  unsigned int v43; // w21
  __int64 v44; // x0
  unsigned __int64 v45; // x8
  __int64 v46; // x8
  __int64 v47; // x9
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x21
  char v57; // w8
  unsigned __int64 v58; // x8
  __int64 v59; // x8
  int v60; // w21
  __int64 v61; // x0
  unsigned __int64 v62; // x8
  __int64 v63; // x8
  __int64 v64; // x9
  unsigned int *v65; // x8
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned __int64 v74; // x8
  __int64 v75; // x8
  __int64 v76; // x9
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7

  ref = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !ref )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
    v22 = *(_QWORD *)comp_private_obj;
    v23 = comp_private_obj;
    v24 = *(_BYTE *)(*(_QWORD *)comp_private_obj + 955LL) == 1;
    StatusReg = _ReadStatusReg(DAIF);
    if ( !v24 )
    {
      if ( StatusReg < 0
        || (v30 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v30 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v30 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v22 + 1040);
      }
      else
      {
        raw_spin_lock_bh(v22 + 1040);
        *(_QWORD *)(v22 + 1048) |= 1uLL;
      }
      v31 = *(_QWORD *)v23;
      v32 = *(_QWORD *)(*(_QWORD *)v23 + 1048LL);
      v28 = *(unsigned __int8 *)(*(_QWORD *)v23 + 945LL);
      if ( (v32 & 1) == 0 )
      {
        v29 = v31 + 1040;
        goto LABEL_15;
      }
      *(_QWORD *)(v31 + 1048) = v32 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v31 + 1040);
LABEL_16:
      if ( v28 )
      {
        v33 = *(_QWORD *)v23;
        v24 = *(_BYTE *)(*(_QWORD *)v23 + 955LL) == 1;
        v34 = _ReadStatusReg(DAIF);
        if ( !v24 )
        {
          if ( v34 < 0
            || (v45 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v45 + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(v45 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v33 + 1040);
          }
          else
          {
            raw_spin_lock_bh(v33 + 1040);
            *(_QWORD *)(v33 + 1048) |= 1uLL;
          }
          v46 = *(_QWORD *)v23;
          v47 = *(_QWORD *)(*(_QWORD *)v23 + 1048LL);
          v37 = *(unsigned __int8 *)(*(_QWORD *)v23 + 945LL);
          if ( (v47 & 1) == 0 )
          {
            v38 = v46 + 1040;
            goto LABEL_37;
          }
          *(_QWORD *)(v46 + 1048) = v47 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v46 + 1040);
LABEL_38:
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: Delete user passed wow pattern id %d total user pattern %d",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "pmo_core_del_wow_user_pattern",
            (unsigned __int8)a2,
            v37);
          pmo_tgt_del_wow_pattern(a1, a2, 1);
          v56 = *(_QWORD *)v23;
          v24 = *(_BYTE *)(*(_QWORD *)v23 + 955LL) == 1;
          v57 = _ReadStatusReg(DAIF);
          if ( !v24 )
          {
            if ( v57 < 0
              || (v62 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v62 + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(v62 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v56 + 1040);
            }
            else
            {
              raw_spin_lock_bh(v56 + 1040);
              *(_QWORD *)(v56 + 1048) |= 1uLL;
            }
            v63 = *(_QWORD *)v23;
            v64 = *(_QWORD *)(*(_QWORD *)v23 + 1048LL);
            v60 = *(unsigned __int8 *)(*(_QWORD *)v23 + 945LL);
            if ( (v64 & 1) != 0 )
            {
              *(_QWORD *)(v63 + 1048) = v64 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v63 + 1040);
              goto LABEL_52;
            }
            v61 = v63 + 1040;
LABEL_51:
            raw_spin_unlock(v61);
LABEL_52:
            if ( !v60 )
              pmo_register_wow_default_patterns(a1);
            ref = 0;
            goto LABEL_63;
          }
          if ( v57 < 0
            || (v58 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v58 + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(v58 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v23 + 1056);
            v59 = *(_QWORD *)(v23 + 1064);
            v60 = *(unsigned __int8 *)(v23 + 1031);
            if ( (v59 & 1) == 0 )
            {
LABEL_44:
              v61 = v23 + 1056;
              goto LABEL_51;
            }
          }
          else
          {
            raw_spin_lock_bh(v23 + 1056);
            v59 = *(_QWORD *)(v23 + 1064) | 1LL;
            *(_QWORD *)(v23 + 1064) = v59;
            v60 = *(unsigned __int8 *)(v23 + 1031);
            if ( (v59 & 1) == 0 )
              goto LABEL_44;
          }
          *(_QWORD *)(v23 + 1064) = v59 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v23 + 1056);
          goto LABEL_52;
        }
        if ( v34 < 0
          || (v35 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v35 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v35 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v23 + 1056);
          v36 = *(_QWORD *)(v23 + 1064);
          v37 = *(unsigned __int8 *)(v23 + 1031);
          if ( (v36 & 1) == 0 )
          {
LABEL_23:
            v38 = v23 + 1056;
LABEL_37:
            raw_spin_unlock(v38);
            goto LABEL_38;
          }
        }
        else
        {
          raw_spin_lock_bh(v23 + 1056);
          v36 = *(_QWORD *)(v23 + 1064) | 1LL;
          *(_QWORD *)(v23 + 1064) = v36;
          v37 = *(unsigned __int8 *)(v23 + 1031);
          if ( (v36 & 1) == 0 )
            goto LABEL_23;
        }
        *(_QWORD *)(v23 + 1064) = v36 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v23 + 1056);
        goto LABEL_38;
      }
      v39 = *(_QWORD *)v23;
      v24 = *(_BYTE *)(*(_QWORD *)v23 + 955LL) == 1;
      v40 = _ReadStatusReg(DAIF);
      if ( !v24 )
      {
        if ( v40 < 0
          || (v74 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v74 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v74 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v39 + 1040);
        }
        else
        {
          raw_spin_lock_bh(v39 + 1040);
          *(_QWORD *)(v39 + 1048) |= 1uLL;
        }
        v75 = *(_QWORD *)v23;
        v76 = *(_QWORD *)(*(_QWORD *)v23 + 1048LL);
        v43 = *(unsigned __int8 *)(*(_QWORD *)v23 + 945LL);
        if ( (v76 & 1) != 0 )
        {
          *(_QWORD *)(v75 + 1048) = v76 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v75 + 1040);
          goto LABEL_62;
        }
        v44 = v75 + 1040;
LABEL_61:
        raw_spin_unlock(v44);
LABEL_62:
        qdf_trace_msg(
          0x4Du,
          2u,
          "%s: No valid user pattern. Num user pattern %u",
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          "pmo_core_del_wow_user_pattern",
          v43);
        ref = 4;
LABEL_63:
        wlan_objmgr_vdev_release_ref(a1, 0xAu, v65, v66, v67, v68, v69, v70, v71, v72, v73);
        goto LABEL_64;
      }
      if ( v40 < 0
        || (v41 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v41 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v41 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v23 + 1056);
        v42 = *(_QWORD *)(v23 + 1064);
        v43 = *(unsigned __int8 *)(v23 + 1031);
        if ( (v42 & 1) == 0 )
        {
LABEL_30:
          v44 = v23 + 1056;
          goto LABEL_61;
        }
      }
      else
      {
        raw_spin_lock_bh(v23 + 1056);
        v42 = *(_QWORD *)(v23 + 1064) | 1LL;
        *(_QWORD *)(v23 + 1064) = v42;
        v43 = *(unsigned __int8 *)(v23 + 1031);
        if ( (v42 & 1) == 0 )
          goto LABEL_30;
      }
      *(_QWORD *)(v23 + 1064) = v42 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v23 + 1056);
      goto LABEL_62;
    }
    if ( StatusReg < 0
      || (v26 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v26 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v26 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1056);
      v27 = *(_QWORD *)(v23 + 1064);
      v28 = *(unsigned __int8 *)(v23 + 1031);
      if ( (v27 & 1) == 0 )
      {
LABEL_8:
        v29 = v23 + 1056;
LABEL_15:
        raw_spin_unlock(v29);
        goto LABEL_16;
      }
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      v27 = *(_QWORD *)(v23 + 1064) | 1LL;
      *(_QWORD *)(v23 + 1064) = v27;
      v28 = *(unsigned __int8 *)(v23 + 1031);
      if ( (v27 & 1) == 0 )
        goto LABEL_8;
    }
    *(_QWORD *)(v23 + 1064) = v27 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v23 + 1056);
    goto LABEL_16;
  }
LABEL_64:
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v13, v14, v15, v16, v17, v18, v19, v20, "pmo_core_del_wow_user_pattern");
  return ref;
}
