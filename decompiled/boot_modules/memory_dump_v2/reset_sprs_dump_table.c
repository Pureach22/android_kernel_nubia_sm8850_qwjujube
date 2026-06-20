__int64 __fastcall reset_sprs_dump_table(__int64 result)
{
  void ***v1; // x19
  void **v2; // x8
  __int64 v3; // x8
  void **v4; // x8
  __int64 v5; // x8
  void **v6; // x8
  __int64 v7; // x8
  void **v8; // x8
  __int64 v9; // x8
  void **v10; // x8
  __int64 v11; // x8
  void **v12; // x8
  __int64 v13; // x8
  void **v14; // x8
  __int64 v15; // x8
  void **v16; // x8
  __int64 v17; // x8

  v1 = *(void ****)(result + 152);
  if ( v1 )
  {
    mutex_lock(*(_QWORD *)(result + 152));
    v2 = v1[8];
    if ( v2 )
    {
      *((_DWORD *)v2 + 3) = 0;
      *((_DWORD *)v1[8] + 4) = 24;
      memset(*v1[8], 222, *((unsigned int *)v1[8] + 2));
      v3 = (__int64)*v1[8];
      *(_DWORD *)v3 = 12648430;
      *(_QWORD *)(v3 + 4) = 0x500000001LL;
      *(_DWORD *)(v3 + 12) = 24;
      *((_QWORD *)*v1[8] + 2) = 0;
    }
    v4 = v1[9];
    if ( v4 )
    {
      *((_DWORD *)v4 + 3) = 0;
      *((_DWORD *)v1[9] + 4) = 24;
      memset(*v1[9], 222, *((unsigned int *)v1[9] + 2));
      v5 = (__int64)*v1[9];
      *(_DWORD *)v5 = 12648430;
      *(_QWORD *)(v5 + 4) = 0x500000001LL;
      *(_DWORD *)(v5 + 12) = 24;
      *((_QWORD *)*v1[9] + 2) = 0;
    }
    v6 = v1[10];
    if ( v6 )
    {
      *((_DWORD *)v6 + 3) = 0;
      *((_DWORD *)v1[10] + 4) = 24;
      memset(*v1[10], 222, *((unsigned int *)v1[10] + 2));
      v7 = (__int64)*v1[10];
      *(_DWORD *)v7 = 12648430;
      *(_QWORD *)(v7 + 4) = 0x500000001LL;
      *(_DWORD *)(v7 + 12) = 24;
      *((_QWORD *)*v1[10] + 2) = 0;
    }
    v8 = v1[11];
    if ( v8 )
    {
      *((_DWORD *)v8 + 3) = 0;
      *((_DWORD *)v1[11] + 4) = 24;
      memset(*v1[11], 222, *((unsigned int *)v1[11] + 2));
      v9 = (__int64)*v1[11];
      *(_DWORD *)v9 = 12648430;
      *(_QWORD *)(v9 + 4) = 0x500000001LL;
      *(_DWORD *)(v9 + 12) = 24;
      *((_QWORD *)*v1[11] + 2) = 0;
    }
    v10 = v1[12];
    if ( v10 )
    {
      *((_DWORD *)v10 + 3) = 0;
      *((_DWORD *)v1[12] + 4) = 24;
      memset(*v1[12], 222, *((unsigned int *)v1[12] + 2));
      v11 = (__int64)*v1[12];
      *(_DWORD *)v11 = 12648430;
      *(_QWORD *)(v11 + 4) = 0x500000001LL;
      *(_DWORD *)(v11 + 12) = 24;
      *((_QWORD *)*v1[12] + 2) = 0;
    }
    v12 = v1[13];
    if ( v12 )
    {
      *((_DWORD *)v12 + 3) = 0;
      *((_DWORD *)v1[13] + 4) = 24;
      memset(*v1[13], 222, *((unsigned int *)v1[13] + 2));
      v13 = (__int64)*v1[13];
      *(_DWORD *)v13 = 12648430;
      *(_QWORD *)(v13 + 4) = 0x500000001LL;
      *(_DWORD *)(v13 + 12) = 24;
      *((_QWORD *)*v1[13] + 2) = 0;
    }
    v14 = v1[14];
    if ( v14 )
    {
      *((_DWORD *)v14 + 3) = 0;
      *((_DWORD *)v1[14] + 4) = 24;
      memset(*v1[14], 222, *((unsigned int *)v1[14] + 2));
      v15 = (__int64)*v1[14];
      *(_DWORD *)v15 = 12648430;
      *(_QWORD *)(v15 + 4) = 0x500000001LL;
      *(_DWORD *)(v15 + 12) = 24;
      *((_QWORD *)*v1[14] + 2) = 0;
    }
    v16 = v1[15];
    if ( v16 )
    {
      *((_DWORD *)v16 + 3) = 0;
      *((_DWORD *)v1[15] + 4) = 24;
      memset(*v1[15], 222, *((unsigned int *)v1[15] + 2));
      v17 = (__int64)*v1[15];
      *(_DWORD *)v17 = 12648430;
      *(_QWORD *)(v17 + 4) = 0x500000001LL;
      *(_DWORD *)(v17 + 12) = 24;
      *((_QWORD *)*v1[15] + 2) = 0;
    }
    return mutex_unlock(v1);
  }
  return result;
}
