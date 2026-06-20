__int64 __fastcall cam_icp_v2_cpas_register(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w8
  __int64 v3; // x9
  __int64 result; // x0
  _QWORD v5[16]; // [xsp+0h] [xbp-B0h] BYREF
  __int64 v6; // [xsp+80h] [xbp-30h]
  __int64 v7; // [xsp+88h] [xbp-28h]
  __int64 v8; // [xsp+90h] [xbp-20h]
  __int64 (__fastcall *v9)(); // [xsp+98h] [xbp-18h]
  __int64 v10; // [xsp+A0h] [xbp-10h]
  __int64 v11; // [xsp+A8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 112);
    v2 = *(_DWORD *)(a1 + 4);
    v9 = nullptr;
    v10 = 0;
    v7 = 0;
    v8 = 0;
    v6 = 0;
    v3 = *(_QWORD *)(v1 + 104);
    LODWORD(v6) = v2;
    v9 = cam_icp_v2_cpas_cb;
    memset(&v5[1], 0, 120);
    v7 = v3;
    v5[0] = 7365481;
    result = cam_cpas_register_client((__int64)v5);
    if ( !(_DWORD)result )
      *(_DWORD *)(*(_QWORD *)(v1 + 3680) + 44LL) = v10;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
