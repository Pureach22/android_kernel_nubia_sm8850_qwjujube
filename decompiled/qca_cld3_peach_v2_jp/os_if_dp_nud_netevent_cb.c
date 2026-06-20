__int64 __fastcall os_if_dp_nud_netevent_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 result; // x0
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 != 1 )
    goto LABEL_4;
  v3 = *(_QWORD *)(a3 + 360);
  v5[0] = 0;
  result = _osif_vdev_sync_op_start(v3, v5, "os_if_dp_nud_netevent_cb");
  if ( !(_DWORD)result )
  {
    ucfg_dp_nud_event();
    _osif_vdev_sync_op_stop(v5[0], "os_if_dp_nud_netevent_cb");
LABEL_4:
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
