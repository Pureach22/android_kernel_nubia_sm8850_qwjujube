__int64 __fastcall aw882xx_hal_monitor_work_get(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x20
  __int64 v7; // x21
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = aw_componet_codec_ops[0];
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v4 = v3();
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64))v5)(v4);
  v7 = *(_QWORD *)(v6 + 96);
  v9 = 0;
  mutex_lock(v6 + 528);
  aw882xx_dev_monitor_hal_work(v7, &v9);
  *(_QWORD *)(a2 + 72) = v9;
  mutex_unlock(v6 + 528);
  _ReadStatusReg(SP_EL0);
  return 0;
}
