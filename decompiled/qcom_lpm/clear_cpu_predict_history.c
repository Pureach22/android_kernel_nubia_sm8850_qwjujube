void clear_cpu_predict_history()
{
  char v0; // w12
  int v1; // w8
  unsigned __int64 v2; // x12
  unsigned __int64 v3; // x12
  __int64 v4; // x13
  bool v5; // cf
  _BYTE *v6; // x13

  if ( (prediction_disabled & 1) == 0 )
  {
    v0 = 0;
    v1 = _cpu_possible_mask;
    do
    {
      v2 = (unsigned int)(-1LL << v0) & v1;
      if ( !(_DWORD)v2 )
        break;
      v3 = __clz(__rbit64(v2));
      v4 = _per_cpu_offset[v3];
      v5 = v3 >= 0x1F;
      v0 = v3 + 1;
      v6 = &lpm_cpu_data[v4];
      *((_DWORD *)v6 + 56) = -1;
      *((_QWORD *)v6 + 26) = -1;
      *((_QWORD *)v6 + 27) = -1;
      *(_QWORD *)(v6 + 228) = 0;
      *(_QWORD *)(v6 + 236) = 0;
      *(_QWORD *)(v6 + 244) = 0;
      *((_DWORD *)v6 + 63) = 0;
      *((_QWORD *)v6 + 38) = 0;
      *((_DWORD *)v6 + 78) = 0;
    }
    while ( !v5 );
  }
}
