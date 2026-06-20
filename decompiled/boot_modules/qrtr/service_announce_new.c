__int64 __fastcall service_announce_new(__int64 a1, _DWORD *a2)
{
  int v4; // w10
  __int64 v5; // x9
  int v6; // w8
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+18h] [xbp-98h] BYREF
  __int64 v9; // [xsp+28h] [xbp-88h] BYREF
  __int64 v10; // [xsp+30h] [xbp-80h]
  __int64 v11; // [xsp+38h] [xbp-78h]
  __int64 v12; // [xsp+40h] [xbp-70h]
  __int64 v13; // [xsp+48h] [xbp-68h]
  __int64 v14; // [xsp+50h] [xbp-60h]
  __int64 v15; // [xsp+58h] [xbp-58h]
  __int64 v16; // [xsp+60h] [xbp-50h]
  __int64 v17; // [xsp+68h] [xbp-48h]
  __int64 v18; // [xsp+70h] [xbp-40h]
  __int64 v19; // [xsp+78h] [xbp-38h]
  __int64 v20; // [xsp+80h] [xbp-30h]
  __int64 v21; // [xsp+88h] [xbp-28h]
  _DWORD v22[2]; // [xsp+94h] [xbp-1Ch] BYREF
  __int64 v23; // [xsp+9Ch] [xbp-14h]
  int v24; // [xsp+A4h] [xbp-Ch]
  __int64 v25; // [xsp+A8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  ipc_log_string(ns_ilc, "%s: [0x%x:0x%x]@[0x%x:0x%x]\n", "service_announce_new", *a2, a2[1], a2[2], a2[3]);
  v4 = *a2;
  v8[0] = v22;
  v8[1] = 20;
  v5 = *(_QWORD *)(a2 + 1);
  v22[0] = 4;
  v22[1] = v4;
  v6 = a2[3];
  v23 = v5;
  v24 = v6;
  v9 = a1;
  LODWORD(v10) = 12;
  result = kernel_sendmsg(qrtr_ns, &v9, v8, 1, 20);
  _ReadStatusReg(SP_EL0);
  return result;
}
