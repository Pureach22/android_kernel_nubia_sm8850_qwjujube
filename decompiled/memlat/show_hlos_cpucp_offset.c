__int64 __fastcall show_hlos_cpucp_offset(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x9
  _DWORD *v5; // x9
  __int64 v6; // x0
  int v7; // w0
  unsigned __int64 v8; // x0
  __int64 result; // x0
  int v10; // w20
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(memlat_data + 312);
  if ( v3 )
  {
    v5 = *(_DWORD **)(v3 + 8);
    v6 = *(_QWORD *)(memlat_data + 320);
    v11[0] = 0;
    if ( *(v5 - 1) != 1134762728 )
      __break(0x8229u);
    v7 = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64, __int64, _QWORD, __int64))v5)(
           v6,
           v11,
           0x4D454D4C4154LL,
           38,
           0,
           8);
    if ( v7 < 0 )
    {
      v10 = v7;
      printk(&unk_C4FF);
      result = v10;
    }
    else
    {
      v8 = sched_clock();
      result = (int)scnprintf(a3, 4096, "%llu\n", v11[0] - v8 / 0x3E8);
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
