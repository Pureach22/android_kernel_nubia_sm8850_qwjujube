__int64 __fastcall sde_vm_post_acquire(__int64 a1)
{
  __int64 v1; // x9
  _QWORD *v2; // x20
  _QWORD *v3; // x19
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x0
  unsigned int v6; // w0
  unsigned int v7; // w21
  _QWORD *v8; // x20
  __int64 result; // x0
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0
  unsigned int v12; // w19

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 56LL);
  v2 = *(_QWORD **)(v1 + 5752);
  v3 = (_QWORD *)(v1 + 5752);
  while ( 1 )
  {
    if ( v2 == v3 )
      return 0;
    v4 = (__int64 (__fastcall *)(_QWORD))*(v2 - 5);
    if ( v4 )
    {
      v5 = *(v2 - 1);
      if ( *((_DWORD *)v4 - 1) != -1066802076 )
        __break(0x8228u);
      v6 = v4(v5);
      if ( v6 )
        break;
    }
    v2 = (_QWORD *)*v2;
  }
  v7 = v6;
  printk(&unk_21BB36, "sde_vm_post_acquire");
  v8 = (_QWORD *)v2[1];
  result = v7;
  while ( v8 != v3 )
  {
    v10 = (__int64 (__fastcall *)(_QWORD))*(v8 - 6);
    if ( v10 )
    {
      v11 = *(v8 - 1);
      if ( *((_DWORD *)v10 - 1) != -1066802076 )
        __break(0x8228u);
      result = v10(v11);
      if ( (_DWORD)result )
      {
        v12 = result;
        printk(&unk_214902, "sde_vm_post_acquire");
        return v12;
      }
    }
    v8 = (_QWORD *)v8[1];
  }
  return result;
}
