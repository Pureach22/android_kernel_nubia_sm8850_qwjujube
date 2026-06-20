__int64 __fastcall coresight_find_default_sink(__int64 a1)
{
  __int64 sink; // x8
  __int64 v2; // x19
  __int64 v4; // x19
  __int64 (*v5)(void); // x8
  unsigned int v6; // w0
  __int64 v7; // x8

  _ReadStatusReg(SP_EL0);
  sink = *(_QWORD *)(a1 + 992);
  if ( sink )
    goto LABEL_6;
  if ( !a1 || *(_DWORD *)(a1 + 8) != 3 || *(_DWORD *)(a1 + 12) )
  {
LABEL_5:
    v2 = a1;
    sink = coresight_find_sink();
    *(_QWORD *)(v2 + 992) = sink;
LABEL_6:
    _ReadStatusReg(SP_EL0);
    return sink;
  }
  v4 = a1;
  v5 = **(__int64 (***)(void))(*(_QWORD *)(a1 + 24) + 16LL);
  if ( *((_DWORD *)v5 - 1) != 335626315 )
    __break(0x8228u);
  v6 = v5();
  if ( v6 < 0x20 )
  {
    v7 = _per_cpu_offset[v6];
    a1 = v4;
    sink = *(_QWORD *)((char *)&csdev_sink + v7);
    *(_QWORD *)(v4 + 992) = sink;
    if ( sink )
      goto LABEL_6;
    goto LABEL_5;
  }
  __break(0x5512u);
  return coresight_find_sink();
}
