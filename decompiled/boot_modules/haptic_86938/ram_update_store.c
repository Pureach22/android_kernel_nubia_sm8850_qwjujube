__int64 __fastcall ram_update_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  v6 = kstrtouint(a3, 0, &v8);
  if ( v6 < 0 )
  {
    a4 = v6;
  }
  else if ( v8 )
  {
    *(_WORD *)(v5 - 163) = 0;
    request_firmware_nowait(&_this_module, 1, aw_ram_name, *(_QWORD *)(v5 + 632), 3264, v5 - 168, ram_load);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
