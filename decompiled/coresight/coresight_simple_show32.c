__int64 __fastcall coresight_simple_show32(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  _DWORD *v7; // x8
  unsigned int v8; // w0
  __int64 v9; // x8
  __int64 v10; // x20

  _pm_runtime_resume(*(_QWORD *)(a1 + 96), 4);
  v6 = *(unsigned int *)(a2 + 32);
  v7 = *(_DWORD **)(a1 - 16);
  if ( *(_BYTE *)(a1 - 24) == 1 )
  {
    v8 = readl_relaxed_0((char *)v7 + v6);
  }
  else
  {
    if ( *(v7 - 1) != -340433967 )
      __break(0x8228u);
    v8 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v7)(v6, 1, 0);
  }
  v9 = *(_QWORD *)(a1 + 96);
  v10 = v8;
  _pm_runtime_idle(v9, 4);
  return (int)sysfs_emit(a3, "0x%llx\n", v10);
}
