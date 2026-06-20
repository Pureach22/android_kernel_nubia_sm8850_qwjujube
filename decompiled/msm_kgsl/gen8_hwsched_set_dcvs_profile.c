__int64 __fastcall gen8_hwsched_set_dcvs_profile(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  unsigned __int64 v5; // x9
  int v6; // w8
  __int64 result; // x0
  __int64 v8; // [xsp+0h] [xbp-20h] BYREF
  int v9; // [xsp+8h] [xbp-18h]
  int v10; // [xsp+Ch] [xbp-14h]
  int v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = to_gen8_gmu(a1);
  v5 = *(_QWORD *)(a2 + 736);
  v6 = *(_DWORD *)(a2 + 880);
  if ( (*(_QWORD *)(v4 + 1040) & 2) != 0 )
  {
    v8 = 201;
    v9 = 2;
    v10 = v6 + (v5 >> 1);
    v11 = v6;
    result = gen8_hfi_send_cmd_async(a1, (int *)&v8, 0x14u);
    if ( !(_DWORD)result )
      *(_WORD *)(a2 + 688) = 257;
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
