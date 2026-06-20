__int64 __fastcall pmo_unpause_all_vdev(__int64 a1, _QWORD *a2)
{
  unsigned int v4; // w21
  unsigned __int64 StatusReg; // x26
  unsigned int v6; // w8
  __int64 v7; // x8
  __int64 (__fastcall *v8)(_QWORD); // x24
  __int64 result; // x0
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x24
  __int64 v20; // x8
  __int64 v21; // x25
  __int64 v22; // x8
  _DWORD *v23; // x8
  _DWORD *v24; // x8

  v4 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  do
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a2 + 130);
      v7 = a2[131];
      v8 = (__int64 (__fastcall *)(_QWORD))a2[125];
      if ( (v7 & 1) == 0 )
        goto LABEL_7;
    }
    else
    {
      raw_spin_lock_bh(a2 + 130);
      v7 = a2[131] | 1LL;
      a2[131] = v7;
      v8 = (__int64 (__fastcall *)(_QWORD))a2[125];
      if ( (v7 & 1) == 0 )
      {
LABEL_7:
        result = raw_spin_unlock(a2 + 130);
        if ( !v8 )
          goto LABEL_2;
        goto LABEL_8;
      }
    }
    a2[131] = v7 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a2 + 130);
    if ( !v8 )
      goto LABEL_2;
LABEL_8:
    if ( *((_DWORD *)v8 - 1) != -911938828 )
      __break(0x8238u);
    result = v8(v4);
    if ( (_WORD)result )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
      if ( !comp_private_obj )
        goto LABEL_28;
      v19 = comp_private_obj;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(comp_private_obj + 1040);
        v20 = *(_QWORD *)(v19 + 1048);
        v21 = *(_QWORD *)(v19 + 960);
        if ( (v20 & 1) == 0 )
          goto LABEL_16;
LABEL_27:
        *(_QWORD *)(v19 + 1048) = v20 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(v19 + 1040);
        if ( !v21 )
          goto LABEL_28;
LABEL_17:
        if ( !*(_QWORD *)v21 )
          goto LABEL_28;
        v22 = *(_QWORD *)(*(_QWORD *)v21 + 120LL);
        if ( v22 )
        {
          v23 = *(_DWORD **)(v22 + 56);
          if ( v23 )
          {
            if ( *(v23 - 1) != 875705606 )
              __break(0x8228u);
            result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD))v23)(v21, v4, 0xFFFFFFFFLL, 0);
          }
        }
      }
      else
      {
        raw_spin_lock_bh(comp_private_obj + 1040);
        v20 = *(_QWORD *)(v19 + 1048) | 1LL;
        *(_QWORD *)(v19 + 1048) = v20;
        v21 = *(_QWORD *)(v19 + 960);
        if ( (v20 & 1) != 0 )
          goto LABEL_27;
LABEL_16:
        result = raw_spin_unlock(v19 + 1040);
        if ( v21 )
          goto LABEL_17;
LABEL_28:
        result = qdf_trace_msg(
                   0x89u,
                   8u,
                   "%s: invalid instance",
                   v11,
                   v12,
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   "cdp_fc_vdev_unpause");
      }
      v24 = (_DWORD *)a2[124];
      if ( v24 )
      {
        if ( *(v24 - 1) != -2049405488 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(_QWORD, _QWORD))v24)(v4, 0);
      }
    }
LABEL_2:
    v6 = (unsigned __int8)v4++;
  }
  while ( v6 < 5 );
  return result;
}
