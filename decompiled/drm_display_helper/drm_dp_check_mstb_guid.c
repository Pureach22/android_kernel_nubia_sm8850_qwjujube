__int64 __fastcall drm_dp_check_mstb_guid(_QWORD *a1, _QWORD *a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x9
  __int64 v4; // x12
  __int64 *v5; // x8
  bool v6; // zf
  __int64 result; // x0
  __int64 v8; // x9
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned int v13; // w0
  unsigned int v14; // w9
  _QWORD v15[3]; // [xsp+8h] [xbp-18h] BYREF

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = guid_null[1];
  v15[2] = *(_QWORD *)(StatusReg + 1808);
  v4 = a2[1];
  v6 = *a2 == guid_null[0];
  *(_QWORD *)((char *)a1 + 73) = *a2;
  v5 = (_QWORD *)((char *)a1 + 73);
  v6 = v6 && v4 == v3;
  *(_QWORD *)((char *)a1 + 81) = v4;
  if ( v6 )
  {
    v8 = jiffies;
    *(_QWORD *)((char *)a1 + 73) = jiffies;
    *(_QWORD *)((char *)a1 + 81) = v8;
    v10 = a1[7];
    v9 = a1[8];
    v12 = *v5;
    v11 = v5[1];
    v15[0] = v12;
    v15[1] = v11;
    if ( v10 )
      v13 = drm_dp_send_dpcd_write(v9, v10, 48, 0x10u, (__int64)v15);
    else
      v13 = drm_dp_dpcd_write(*(_QWORD **)(v9 + 128), 0x30u, (__int64)v15, 16);
    if ( v13 == 16 )
      v14 = 0;
    else
      v14 = v13;
    if ( v13 - 1 >= 0xF )
      result = v14;
    else
      result = 4294967225LL;
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
