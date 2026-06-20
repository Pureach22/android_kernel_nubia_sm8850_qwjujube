__int64 __fastcall coresight_remove_path(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x1
  unsigned int v4; // w19
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x19
  __int64 result; // x0
  __int64 (*v9)(void); // x8
  unsigned int v10; // w0
  __int64 v11; // x8
  __int64 v12; // x1

  v1 = *(_DWORD *)(a1 + 12);
  if ( (unsigned int)(v1 - 2) < 3 )
  {
    v2 = *(_QWORD *)(a1 + 168);
    if ( !v2 )
      v2 = *(_QWORD *)(a1 + 56);
    v4 = hashlen_string(0, v2);
    v5 = idr_find(&path_idr, v4);
    if ( v5 )
    {
      v6 = v4;
      v7 = v5;
      idr_remove(&path_idr, v6);
      return v7;
    }
    v12 = *(_QWORD *)(a1 + 168);
    if ( !v12 )
      v12 = *(_QWORD *)(a1 + 56);
    printk(&unk_123AF, v12);
    return 0;
  }
  if ( v1 )
    return 0;
  v9 = **(__int64 (***)(void))(*(_QWORD *)(a1 + 24) + 16LL);
  if ( *((_DWORD *)v9 - 1) != 335626315 )
    __break(0x8228u);
  v10 = v9();
  if ( v10 >= 0x20 )
  {
    __break(0x5512u);
    JUMPOUT(0xAAD8);
  }
  v11 = _per_cpu_offset[v10];
  result = *(_QWORD *)((char *)&tracer_path + v11);
  *(_QWORD *)((char *)&tracer_path + v11) = 0;
  return result;
}
