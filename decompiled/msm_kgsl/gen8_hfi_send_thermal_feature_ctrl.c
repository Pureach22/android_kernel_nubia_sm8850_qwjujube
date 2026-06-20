__int64 __fastcall gen8_hfi_send_thermal_feature_ctrl(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x8
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x11
  __int64 v7; // x12
  __int64 v8; // x10
  __int64 v9; // x12
  __int64 v10; // x11

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 248LL);
  v3 = *(_QWORD *)(a1 + 1528);
  result = 0;
  if ( (v3 & 0x80) != 0 )
  {
    if ( v2 )
    {
      result = gen8_hfi_send_feature_ctrl(a1, 28, 1, 0);
      if ( !(_DWORD)result )
      {
        if ( !dword_17C240 )
        {
          gen8_hfi_send_thermal_feature_ctrl_cmd = 0x100000009LL;
          v5 = *(_QWORD *)(v2 + 24);
          v6 = *(_QWORD *)v2;
          v7 = *(_QWORD *)(v2 + 8);
          qword_17C254 = *(_QWORD *)(v2 + 16);
          qword_17C25C = v5;
          qword_17C244 = v6;
          qword_17C24C = v7;
          v9 = *(_QWORD *)(v2 + 40);
          v8 = *(_QWORD *)(v2 + 48);
          v10 = *(_QWORD *)(v2 + 32);
          dword_17C27C = *(_DWORD *)(v2 + 56);
          qword_17C26C = v9;
          qword_17C274 = v8;
          qword_17C264 = v10;
        }
        return gen8_hfi_send_generic_req(a1, (__int64)&gen8_hfi_send_thermal_feature_ctrl_cmd, 68);
      }
    }
  }
  return result;
}
