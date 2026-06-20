__int64 __fastcall drm_dp_queue_down_tx(_QWORD *a1, __int64 a2)
{
  _QWORD *v4; // x0
  _QWORD *v5; // x21
  _QWORD *v6; // x1
  __int64 v7; // x0
  __int64 result; // x0
  _QWORD v9[7]; // [xsp+8h] [xbp-38h] BYREF

  v9[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 + 117);
  v4 = (_QWORD *)(a2 + 320);
  v5 = a1 + 123;
  v6 = (_QWORD *)a1[124];
  if ( (_QWORD *)(a2 + 320) == a1 + 123 || v6 == v4 || (_QWORD *)*v6 != v5 )
  {
    _list_add_valid_or_report(v4);
  }
  else
  {
    a1[124] = v4;
    *(_QWORD *)(a2 + 320) = v5;
    *(_QWORD *)(a2 + 328) = v6;
    *v6 = v4;
  }
  if ( (*(&_drm_debug + 1) & 1) != 0 )
  {
    v7 = a1[13];
    memset(v9, 0, 48);
    drm_dbg_printer(v9, v7);
    drm_dp_mst_dump_sideband_msg_tx(v9, a2);
  }
  if ( (_QWORD *)*v5 != v5 && *v5 == a1[124] )
    process_single_down_tx_qlock(a1);
  result = mutex_unlock(a1 + 117);
  _ReadStatusReg(SP_EL0);
  return result;
}
