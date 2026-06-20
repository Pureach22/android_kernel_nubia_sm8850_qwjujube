__int64 __fastcall icnss_call_driver_uevent(_QWORD *a1, int a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v6; // x2
  __int64 v8; // x8
  __int64 v9; // x9
  _DWORD *v10; // x8
  __int64 result; // x0
  _QWORD v12[3]; // [xsp+8h] [xbp-18h] BYREF

  v12[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[2];
  if ( v3 && *(_QWORD *)(v3 + 288) )
  {
    v6 = a1[229];
    v12[0] = 0;
    ipc_log_string(icnss_ipc_log_context, "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n", v6, a2);
    v9 = a1[1];
    v8 = a1[2];
    LODWORD(v12[0]) = a2;
    v12[1] = a3;
    v10 = *(_DWORD **)(v8 + 288);
    if ( *(v10 - 1) != -712363570 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD *))v10)(v9 + 16, v12);
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
