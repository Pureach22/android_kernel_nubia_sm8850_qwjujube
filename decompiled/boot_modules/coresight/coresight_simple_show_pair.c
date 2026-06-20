__int64 __fastcall coresight_simple_show_pair(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v6; // x8
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 v9; // x22
  __int64 v10; // x0
  __int64 v11; // x21
  __int64 v13; // x0
  _DWORD *v14; // x8

  _pm_runtime_resume(*(_QWORD *)(a1 + 96), 4);
  v6 = *(_DWORD **)(a1 - 16);
  v7 = *(unsigned int *)(a2 + 32);
  v8 = *(unsigned int *)(a2 + 36);
  if ( *(_BYTE *)(a1 - 24) == 1 )
  {
    v9 = (unsigned int)readl_relaxed_0((char *)v6 + v7);
    v10 = (unsigned int)readl_relaxed_0(*(_QWORD *)(a1 - 16) + v8);
  }
  else
  {
    if ( *(v6 - 1) != -340433967 )
      __break(0x8228u);
    v13 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v6)(v7, 1, 0);
    v14 = *(_DWORD **)(a1 - 16);
    v9 = v13;
    if ( *(v14 - 1) != -340433967 )
      __break(0x8228u);
    v10 = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD))v14)((unsigned int)v8, 1, 0);
  }
  v11 = v9 | (v10 << 32);
  _pm_runtime_idle(*(_QWORD *)(a1 + 96), 4);
  return (int)sysfs_emit(a3, "0x%llx\n", v11);
}
