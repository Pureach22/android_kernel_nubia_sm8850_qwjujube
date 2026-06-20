void __fastcall ipi_raise(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x20
  char v4; // w8
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x26
  _BYTE *v7; // x27
  __int64 v8; // x0
  _BYTE *v9; // x8
  __int64 v10; // x9
  int v11; // w9
  int v12; // w9

  if ( (suspend_in_progress & 1) == 0 )
  {
    v3 = ktime_get();
    v4 = 0;
    do
    {
      v5 = (unsigned int)(-1LL << v4) & *a2;
      if ( !(_DWORD)v5 )
        break;
      v6 = __clz(__rbit64(v5));
      v7 = &lpm_cpu_data[_per_cpu_offset[v6]];
      if ( !*((_DWORD *)v7 + 1) )
        break;
      v8 = raw_spin_lock_irqsave(v7 + 320);
      v7[316] = 1;
      v9 = &lpm_cpu_data[_per_cpu_offset[v6]];
      v10 = *((unsigned int *)v9 + 69);
      if ( (unsigned int)v10 > 4 )
      {
        __break(0x5512u);
        ipi_entry(v8);
        return;
      }
      *(_DWORD *)&lpm_cpu_data[4 * v10 + 256 + _per_cpu_offset[v6]] = ((int)v3 - *((_DWORD *)v9 + 70)) / 1000;
      v11 = *((_DWORD *)v9 + 69);
      *((_QWORD *)v9 + 35) = v3;
      if ( (unsigned int)(v11 + 1) <= 4 )
        v12 = v11 + 1;
      else
        v12 = 0;
      *((_DWORD *)v9 + 69) = v12;
      raw_spin_unlock_irqrestore(v7 + 320, v8);
      v4 = v6 + 1;
    }
    while ( v6 < 0x1F );
  }
}
