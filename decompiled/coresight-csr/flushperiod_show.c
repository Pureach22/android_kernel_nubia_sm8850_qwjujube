__int64 __fastcall flushperiod_show(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x8

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( v3 && v3 <= 0xFFFFFFFFFFFFF000LL && (*(_BYTE *)(v3 + 156) & 1) != 0 )
    return (int)scnprintf(a3, 4096, "%#x\n", *(_DWORD *)(v3 + 68));
  dev_err();
  return -22;
}
