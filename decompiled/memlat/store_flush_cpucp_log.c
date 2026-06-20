__int64 __fastcall store_flush_cpucp_log(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _DWORD **v4; // x9
  _DWORD *v5; // x9
  __int64 v6; // x0
  int v8; // w0
  int v9; // w20

  v4 = *(_DWORD ***)(memlat_data + 312);
  if ( !v4 )
    return -19;
  v5 = *v4;
  v6 = *(_QWORD *)(memlat_data + 320);
  if ( *(v5 - 1) != 1737159351 )
    __break(0x8229u);
  v8 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))v5)(v6, 0, 0x4D454D4C4154LL, 4, 0);
  if ( v8 < 0 )
  {
    v9 = v8;
    printk(&unk_C5D2);
    return v9;
  }
  return a4;
}
