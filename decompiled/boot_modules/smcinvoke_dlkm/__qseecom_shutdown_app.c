__int64 __fastcall _qseecom_shutdown_app(_QWORD *a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x20
  __int64 v5; // x0
  _DWORD *v6; // x8
  __int64 v7; // x0
  _DWORD *v8; // x8
  __int64 v9; // x0
  _DWORD *v10; // x8
  __int64 result; // x0

  if ( a1 && (v3 = (_QWORD *)*a1) != nullptr )
  {
    qtee_shmbridge_free_shm(v3 + 3);
    v6 = (_DWORD *)v3[11];
    v5 = v3[12];
    if ( *(v6 - 1) != 816020464 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v6)(v5, 0xFFFF, 0, 0);
    v8 = (_DWORD *)v3[9];
    v7 = v3[10];
    if ( *(v8 - 1) != 816020464 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v8)(v7, 0xFFFF, 0, 0);
    v10 = (_DWORD *)v3[7];
    v9 = v3[8];
    if ( *(v10 - 1) != 816020464 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v10)(v9, 0xFFFF, 0, 0);
    kfree(v3);
    result = 0;
    *a1 = 0;
  }
  else
  {
    printk(&unk_100D2, a2, a3);
    return 4294967274LL;
  }
  return result;
}
