__int64 __fastcall kgsl_open(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x20
  unsigned int v4; // w0
  __int64 (*v5)(void); // x8
  _QWORD *v6; // x0
  _QWORD *v7; // x21
  int v8; // w8
  unsigned __int64 v9; // x0
  unsigned int v10; // w24
  unsigned int v12; // w22
  int v13; // w8
  void (__fastcall *v14)(_QWORD); // x8
  __int64 (__fastcall *v15)(_QWORD); // x8

  if ( (*(_DWORD *)(a1 + 76) & 0xFFFFF) != 0 || (mutex_lock(&unk_3A878), v3 = off_3A7F8, mutex_unlock(&unk_3A878), !v3) )
  {
    printk(&unk_145C7F);
    return (unsigned int)-19;
  }
  v4 = _pm_runtime_resume(v3[1396] + 16LL, 4);
  if ( (v4 & 0x80000000) != 0 )
  {
    v12 = v4;
    dev_err(*v3, "Runtime PM: Unable to wake up the device, rc = %d\n", v4);
    return v12;
  }
  v5 = *(__int64 (**)(void))(v3[1094] + 104LL);
  if ( *((_DWORD *)v5 - 1) != -1045440965 )
    __break(0x8228u);
  v6 = (_QWORD *)v5();
  v7 = v6;
  if ( !v6 )
  {
    v12 = -12;
    goto LABEL_27;
  }
  *v6 = v3;
  *(_QWORD *)(a2 + 32) = v6;
  mutex_lock(v3 + 1773);
  v8 = *((_DWORD *)v3 + 2768);
  if ( !v8 )
  {
    rt_mutex_lock(v3 + 1386);
    v15 = *(__int64 (__fastcall **)(_QWORD))(v3[1094] + 8LL);
    if ( *((_DWORD *)v15 - 1) != -1357770785 )
      __break(0x8228u);
    v12 = v15(v3);
    rt_mutex_unlock(v3 + 1386);
    if ( !v12 )
    {
      v8 = *((_DWORD *)v3 + 2768);
      goto LABEL_8;
    }
    mutex_unlock(v3 + 1773);
LABEL_27:
    *(_QWORD *)(a2 + 32) = 0;
    kfree(v7);
    _pm_runtime_idle(v3[1396] + 16LL, 5);
    return v12;
  }
LABEL_8:
  *((_DWORD *)v3 + 2768) = v8 + 1;
  mutex_unlock(v3 + 1773);
  v9 = process_private_open(v3);
  if ( v9 >= 0xFFFFFFFFFFFFF001LL && (unsigned int)v9 == 4294967279LL )
  {
    v10 = 0;
    do
    {
      usleep_range_state(10, 100, 2);
      v9 = process_private_open(v3);
      if ( v9 < 0xFFFFFFFFFFFFF001LL )
        break;
      if ( (unsigned int)v9 != 4294967279LL )
        break;
    }
    while ( v10++ < 0x31 );
  }
  v7[1] = v9;
  if ( v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    v12 = v9;
    mutex_lock(v3 + 1773);
    v13 = *((_DWORD *)v3 + 2768);
    if ( v13 == 1 )
    {
      rt_mutex_lock(v3 + 1386);
      v14 = *(void (__fastcall **)(_QWORD))(v3[1094] + 16LL);
      if ( *((_DWORD *)v14 - 1) != -1357770785 )
        __break(0x8228u);
      v14(v3);
      rt_mutex_unlock(v3 + 1386);
      v13 = *((_DWORD *)v3 + 2768);
    }
    *((_DWORD *)v3 + 2768) = v13 - 1;
    mutex_unlock(v3 + 1773);
    goto LABEL_27;
  }
  return 0;
}
