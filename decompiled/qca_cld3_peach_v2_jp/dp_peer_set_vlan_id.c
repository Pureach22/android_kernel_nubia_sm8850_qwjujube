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
  unsigned int v12; // w24
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
  __int64 *v44; // x9
  __int64 **v45; // x22
  unsigned int *v46; // x8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x21
  unsigned __int64 v56; // x9
  __int64 v57; // x10
  _QWORD *v58; // x9
  __int64 *v59; // x8
  __int64 v60; // x8
  __int64 v61; // x11
  unsigned int v64; // w9
  __int64 v65; // x8
  __int64 v66; // [xsp+0h] [xbp-20h]

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
      while ( v19 )
      {
        _X13 = (unsigned int *)(v18 + 42560);
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
          _X8 = (unsigned int *)(v18 + 42600);
          __asm { PRFM            #0x11, [X8] }
          do
            v64 = __ldxr(_X8);
          while ( __stxr(v64 + 1, _X8) );
          v65 = *(_QWORD *)(a1 + 18936);
          if ( (v65 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18936) = v65 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18928);
          }
          else
          {
            raw_spin_unlock(a1 + 18928);
          }
          v27 = *(unsigned __int8 *)(v18 + 80);
          v28 = 0;
          if ( !a3 )
            goto LABEL_23;
          goto LABEL_19;
        }
      }
    }
    v33 = *(_QWORD *)(a1 + 18936);
    if ( (v33 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v33 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
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
      v44 = *(__int64 **)v35;
      v45 = (__int64 **)v35;
      if ( *(_QWORD *)v35 )
      {
        if ( !*((_WORD *)v44 + 84) )
        {
          *((_WORD *)v44 + 84) = a4;
          v55 = **(_QWORD **)v35;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (v56 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v56 + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(v56 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v55 + 42488);
          }
          else
          {
            raw_spin_lock_bh(v55 + 42488);
            *(_QWORD *)(v55 + 42496) |= 1uLL;
          }
          v57 = *(_QWORD *)(**v45 + 42472);
          (*v45)[19] = v57;
          if ( v57 )
            v58 = (_QWORD *)(*(_QWORD *)(**v45 + 42472) + 160LL);
          else
            v58 = (_QWORD *)(**v45 + 42480);
          *v58 = *v45 + 19;
          v59 = *v45;
          *(_QWORD *)(**v45 + 42472) = *v45;
          v59[20] = *v59 + 42472;
          v60 = **v45;
          v61 = *(_QWORD *)(v60 + 42496);
          if ( (v61 & 1) != 0 )
          {
            *(_QWORD *)(v60 + 42496) = v61 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v60 + 42488);
          }
          else
          {
            raw_spin_unlock(v60 + 42488);
          }
          return dp_vdev_unref_delete(a1, v18, 9u, v46, v47, v48, v49, v50, v51, v52, v53, v54);
        }
        LODWORD(v66) = *((unsigned __int16 *)v44 + 84);
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
          *(unsigned __int8 *)(v35 + 44),
          *(unsigned __int8 *)(v35 + 45),
          *(unsigned __int8 *)(v35 + 46),
          *(unsigned __int8 *)(v35 + 49),
          v66);
      }
      dp_peer_unref_delete((__int64)v45, 9u, v36, v37, v38, v39, v40, v41, v42, v43);
    }
    else
    {
      qdf_trace_msg(0x38u, 2u, "%s: NULL peer", v36, v37, v38, v39, v40, v41, v42, v43, "dp_peer_multipass_list_add");
    }
    return dp_vdev_unref_delete(a1, v18, 9u, v46, v47, v48, v49, v50, v51, v52, v53, v54);
  }
  return result;
}
