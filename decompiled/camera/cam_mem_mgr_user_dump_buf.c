_QWORD *__fastcall cam_mem_mgr_user_dump_buf(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x8
  int v3; // w12
  __int64 v4; // x10
  __int64 v5; // x11
  __int64 v6; // x13

  *a2 = *(_QWORD *)(a1 + 128);
  a2[1] = *(_QWORD *)(a1 + 136) / 1000LL;
  a2[2] = *(int *)(a1 + 56);
  a2[3] = *(_QWORD *)(a1 + 64);
  a2[4] = *(int *)(a1 + 72);
  a2[5] = *(_QWORD *)(a1 + 80);
  a2[6] = *(int *)(a1 + 76);
  a2[7] = *(unsigned int *)(a1 + 88);
  a2[8] = *(_QWORD *)(a1 + 96);
  a2[9] = *(unsigned __int8 *)(a1 + 122);
  a2[10] = *(unsigned __int8 *)(a1 + 123);
  a2[11] = *(int *)(a1 + 104);
  v2 = a2 + 12;
  v3 = dword_391BA8;
  if ( dword_391BA8 >= 1 )
  {
    v4 = 0;
    v5 = 0;
    do
    {
      v6 = *(_QWORD *)(a1 + 112);
      if ( *(_BYTE *)(v6 + v4 + 32) == 1 )
      {
        *v2 = *(int *)(v6 + v4);
        v2[1] = *(_QWORD *)(*(_QWORD *)(a1 + 112) + v4 + 8);
        v2 += 2;
        v3 = dword_391BA8;
      }
      ++v5;
      v4 += 40;
    }
    while ( v5 < v3 );
  }
  return v2;
}
