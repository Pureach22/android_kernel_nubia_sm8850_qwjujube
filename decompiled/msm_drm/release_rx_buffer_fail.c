__int64 __fastcall release_rx_buffer_fail(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x0
  _QWORD v5[11]; // [xsp+8h] [xbp-58h] BYREF

  v5[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result && a2 )
  {
    v2 = result;
    v3 = result + 64;
    v4 = *(_QWORD *)(a2 + 32);
    v5[0] = v3;
    memset(&v5[1], 0, 72);
    result = hfi_core_release_rx_buffer(v4, v5, 1);
    if ( (_DWORD)result )
      result = printk(&unk_24F7AD, "release_rx_buffer_fail");
    *(_DWORD *)(*(_QWORD *)(v2 + 144) + 64LL) = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
