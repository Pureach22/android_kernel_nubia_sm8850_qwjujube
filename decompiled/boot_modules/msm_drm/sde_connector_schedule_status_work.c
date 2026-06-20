__int64 __fastcall sde_connector_schedule_status_work(__int64 result, char a2)
{
  __int64 v2; // x8
  __int64 v4; // x19
  _DWORD *v5; // x8
  __int64 v6; // x2
  unsigned int v7; // w8
  __int64 v8; // x0
  __int64 v9; // x0
  char v10; // w8
  _QWORD v11[21]; // [xsp+8h] [xbp-A8h] BYREF

  v11[20] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_19;
  v2 = *(_QWORD *)(result + 2512);
  v4 = result;
  memset(v11, 0, 160);
  if ( v2 )
  {
    result = *(_QWORD *)(v2 + 8);
    if ( result )
    {
      result = sde_crtc_get_disp_op(result);
      if ( (_DWORD)result == 1 )
        goto LABEL_19;
    }
  }
  if ( *(_BYTE *)(v4 + 4517) == (a2 & 1) )
    goto LABEL_19;
  if ( !*(_QWORD *)(v4 + 2760) || (v5 = *(_DWORD **)(v4 + 2944)) == nullptr )
  {
    result = printk(&unk_27DE90, "sde_connector_get_info");
    if ( !*(_QWORD *)(v4 + 3064) )
      goto LABEL_19;
    goto LABEL_11;
  }
  v6 = *(_QWORD *)(v4 + 2760);
  if ( *(v5 - 1) != 81886827 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64))v5)(v4, v11, v6);
  if ( *(_QWORD *)(v4 + 3064) )
  {
LABEL_11:
    if ( (v11[0] & 0x1000000000LL) != 0 )
    {
      if ( (a2 & 1) != 0 )
      {
        v7 = *(_DWORD *)(v4 + 4512);
        if ( v7 )
          v8 = v7;
        else
          v8 = 5000;
        v9 = _msecs_to_jiffies(v8);
        result = queue_delayed_work_on(32, system_wq, v4 + 4408, v9);
        v10 = 1;
      }
      else
      {
        result = cancel_delayed_work_sync(v4 + 4408);
        v10 = 0;
      }
      *(_BYTE *)(v4 + 4517) = v10;
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
