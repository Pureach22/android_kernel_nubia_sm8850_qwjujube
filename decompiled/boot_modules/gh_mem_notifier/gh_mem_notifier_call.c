__int64 __fastcall gh_mem_notifier_call(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x19
  char *v7; // x8
  __int64 v8; // x22
  _DWORD *v9; // x23

  if ( (unsigned __int64)(a2 - 1360003092) < 0xFFFFFFFFFFFFFFFDLL )
    return 0;
  v3 = 8;
  if ( a2 == 1360003089 )
    v3 = 16;
  v4 = *(unsigned int *)(a3 + v3);
  if ( (unsigned int)v4 > 8 )
    return 0;
  mutex_lock(&mem_notifier_entries_lock);
  if ( ((16LL * (unsigned int)v4) | 8uLL) > 0x90 )
  {
    __break(1u);
    JUMPOUT(0x61E0);
  }
  v7 = (char *)&mem_notifier_entries + 16 * v4;
  v9 = *(_DWORD **)v7;
  v8 = *((_QWORD *)v7 + 1);
  mutex_unlock(&mem_notifier_entries_lock);
  if ( v9 )
  {
    if ( *(v9 - 1) != 2093521252 )
      __break(0x8237u);
    ((void (__fastcall *)(_QWORD, __int64, __int64, __int64))v9)((unsigned int)v4, a2, v8, a3);
  }
  return 1;
}
