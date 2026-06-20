__int64 __fastcall set_req_update(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x0
  __int64 (__fastcall *v4)(__int64, _QWORD *, __int64, __int64, __int64); // x8
  __int64 result; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = a2;
  if ( a2 )
  {
    v3 = ph_telemetry;
    v4 = *(__int64 (__fastcall **)(__int64, _QWORD *, __int64, __int64, __int64))vendor_ops;
    if ( *(_DWORD *)(*(_QWORD *)vendor_ops - 4LL) != 1737159351 )
      __break(0x8228u);
    result = v4(v3, v6, 0x454C454D45545259LL, 1, 8);
  }
  else
  {
    printk(&unk_7000, "set_req_update", a3);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
