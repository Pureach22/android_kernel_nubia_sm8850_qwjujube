__int64 __fastcall dp_peer_set_vlan_id(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int16 *a3,
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
  unsigned int v12; // w22
  unsigned __int64 StatusReg; // x8
  __int64 v18; // x20
  unsigned int v19; // w9
  unsigned int v26; // w11
  __int64 v27; // x6
  char v28; // w25
  __int64 v29; // x7
  int v30; // w8
  int v31; // w9
  int v32; // w10
  __int64 v33; // x8
  __int64 result; // x0
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned __int8 *v44; // x24
  __int64 v45; // x8
  unsigned int v46; // w9
  unsigned int v49; // w11
  __int64 v50; // x4
  __int64 v51; // x5
  __int64 v52; // x6
  __int64 v53; // x7
  unsigned __int8 *v55; // x22
  __int64 *v56; // x9
  __int64 v57; // x4
  __int64 v58; // x5
  __int64 v59; // x6
  __int64 v60; // x7
  __int64 v61; // x21
  unsigned __int64 v62; // x9
  __int64 v63; // x10
  _QWORD *v64; // x9
  unsigned int *v65; // x8
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 *v74; // x8
  __int64 v75; // x8
  __int64 v76; // x11
  unsigned int v79; // w9
  __int64 v80; // x8
  unsigned int v82; // w9
  __int64 v83; // [xsp+0h] [xbp-20h]

  v12 = a2;
  if ( a2 <= 5u )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 18984);
    }
    else
    {
      raw_spin_lock_bh(a1 + 18984);
      *(_QWORD *)(a1 + 18992) |= 1uLL;
    }
    v18 = *(_QWORD *)(a1 + 8LL * a2 + 12960);
    if ( v18 )
    {
      v19 = *(_DWORD *)(v18 + 43384);
      while ( v19 )
      {
        _X13 = (unsigned int *)(v18 + 43384);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v26 = __ldxr(_X13);
          if ( v26 != v19 )
            break;
          if ( !__stlxr(v19 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v26 == v19;
        v19 = v26;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v18 + 43424);
          __asm { PRFM            #0x11, [X8] }
          do
            v79 = __ldxr(_X8);
          while ( __stxr(v79 + 1, _X8) );
          v80 = *(_QWORD *)(a1 + 18992);
          if ( (v80 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18992) = v80 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18984);
          }
          else
          {
            raw_spin_unlock(a1 + 18984);
          }
          v27 = *(unsigned __int8 *)(v18 + 80);
          v28 = 0;
          if ( !a3 )
            goto LABEL_23;
          goto LABEL_19;
        }
      }
    }
    v33 = *(_QWORD *)(a1 + 18992);
    if ( (v33 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18992) = v33 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18984);
    }
    else
    {
      raw_spin_unlock(a1 + 18984);
    }
  }
  v18 = 0;
  v27 = 0;
  v28 = 1;
  if ( a3 )
  {
LABEL_19:
    v29 = *(unsigned __int8 *)a3;
    v30 = *((unsigned __int8 *)a3 + 1);
    v31 = *((unsigned __int8 *)a3 + 2);
    v32 = *((unsigned __int8 *)a3 + 5);
  }
  else
  {
LABEL_23:
    v31 = 0;
    v29 = 0;
    v30 = 0;
    v32 = 0;
  }
  result = qdf_trace_msg(
             0x45u,
             5u,
             "%s: vdev_id %d, vdev %pK, multipass_en %d, peer_mac %02x:%02x:%02x:**:**:%02x vlan %d",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "dp_peer_set_vlan_id",
             v12,
             v18,
             v27,
             v29,
             v30,
             v31,
             v32,
             a4);
  if ( (v28 & 1) == 0 && *(_BYTE *)(v18 + 80) == 1 )
  {
    v35 = dp_peer_find_hash_find(a1, a3, 0, a2, 9u);
    if ( v35 )
    {
      v44 = (unsigned __int8 *)v35;
      if ( *(_DWORD *)(v35 + 408) != 1 )
        goto LABEL_42;
      v45 = *(_QWORD *)(v35 + 416);
      if ( !v45 )
        goto LABEL_42;
      v46 = *(_DWORD *)(v45 + 40);
      do
      {
        if ( !v46 )
        {
          dp_peer_unref_delete(v35, 9u, v36, v37, v38, v39, v40, v41, v42, v43);
          goto LABEL_57;
        }
        _X13 = (unsigned int *)(v45 + 40);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v49 = __ldxr(_X13);
          if ( v49 != v46 )
            break;
          if ( !__stlxr(v46 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v49 == v46;
        v46 = v49;
      }
      while ( !_ZF );
      _X8 = (unsigned int *)(v45 + 300);
      __asm { PRFM            #0x11, [X8] }
      do
        v82 = __ldxr(_X8);
      while ( __stxr(v82 + 1, _X8) );
      v55 = *(unsigned __int8 **)(v35 + 416);
      dp_peer_unref_delete(v35, 9u, v36, v37, v38, v39, v40, v41, v42, v43);
      v44 = v55;
      if ( v55 )
      {
LABEL_42:
        v56 = *(__int64 **)v44;
        if ( *(_QWORD *)v44 )
        {
          if ( !*((_WORD *)v56 + 84) )
          {
            *((_WORD *)v56 + 84) = a4;
            v61 = **(_QWORD **)v44;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (v62 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v62 + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(v62 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v61 + 43312);
            }
            else
            {
              raw_spin_lock_bh(v61 + 43312);
              *(_QWORD *)(v61 + 43320) |= 1uLL;
            }
            v63 = *(_QWORD *)(**(_QWORD **)v44 + 43296LL);
            *(_QWORD *)(*(_QWORD *)v44 + 152LL) = v63;
            if ( v63 )
              v64 = (_QWORD *)(*(_QWORD *)(**(_QWORD **)v44 + 43296LL) + 160LL);
            else
              v64 = (_QWORD *)(**(_QWORD **)v44 + 43304LL);
            *v64 = *(_QWORD *)v44 + 152LL;
            v74 = *(__int64 **)v44;
            *(_QWORD *)(**(_QWORD **)v44 + 43296LL) = *(_QWORD *)v44;
            v74[20] = *v74 + 43296;
            v75 = **(_QWORD **)v44;
            v76 = *(_QWORD *)(v75 + 43320);
            if ( (v76 & 1) != 0 )
            {
              *(_QWORD *)(v75 + 43320) = v76 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v75 + 43312);
            }
            else
            {
              raw_spin_unlock(v75 + 43312);
            }
            return dp_vdev_unref_delete(a1, v18, 9u, v65, v66, v67, v68, v69, v70, v71, v72, v73);
          }
          if ( v44 == (unsigned __int8 *)-44LL )
          {
            v59 = 0;
            v57 = 0;
            v58 = 0;
            v60 = 0;
          }
          else
          {
            v57 = v44[44];
            v58 = v44[45];
            v59 = v44[46];
            v60 = v44[49];
          }
          LODWORD(v83) = *((unsigned __int16 *)v56 + 84);
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: peer already added to vdev multipass listMAC: %02x:%02x:%02x:**:**:%02x vlan: %d ",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "dp_peer_multipass_list_add",
            v57,
            v58,
            v59,
            v60,
            v83);
        }
        dp_peer_unref_delete((__int64)v44, 9u, v36, v37, v38, v39, v40, v41, v42, v43);
        return dp_vdev_unref_delete(a1, v18, 9u, v65, v66, v67, v68, v69, v70, v71, v72, v73);
      }
    }
    else
    {
      if ( a3 )
      {
        v50 = *(unsigned __int8 *)a3;
        v51 = *((unsigned __int8 *)a3 + 1);
        v52 = *((unsigned __int8 *)a3 + 2);
        v53 = *((unsigned __int8 *)a3 + 5);
      }
      else
      {
        v52 = 0;
        v50 = 0;
        v51 = 0;
        v53 = 0;
      }
      LODWORD(v83) = v12;
      qdf_trace_msg(
        0x81u,
        5u,
        "%s: fail to find peer:%02x:%02x:%02x:**:**:%02x vdev_id: %u",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "dp_peer_get_tgt_peer_hash_find",
        v50,
        v51,
        v52,
        v53,
        v83);
    }
LABEL_57:
    qdf_trace_msg(0x38u, 2u, "%s: NULL peer", v36, v37, v38, v39, v40, v41, v42, v43, "dp_peer_multipass_list_add");
    return dp_vdev_unref_delete(a1, v18, 9u, v65, v66, v67, v68, v69, v70, v71, v72, v73);
  }
  return result;
}
